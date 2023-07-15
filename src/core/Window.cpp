#include "Window.h"
#include <glfw/glfw3.h>
#include <utility>
#include "Logger.h"
#include "../renderer/Renderer.h"

namespace DwarfEngine {

    static uint8_t s_windowCount = 0;

    Window::Window(std::string  title, uint32_t width, uint32_t height, EventCallbackFn  eventCallback)
    : m_title(std::move(title)), m_width(width), m_height(height), m_eventCallback(std::move(eventCallback))
    {
        if (s_windowCount == 0) {
            if (!glfwInit()) {
                Logger::critical("Failed to initialize GLFW");
                exit(1);
            }
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_window = glfwCreateWindow((int32_t)m_width, (int32_t)m_height, m_title.c_str(), nullptr, nullptr);
        if (!m_window) {
            Logger::error("Failed to create window");
            if (s_windowCount == 0) {
                glfwTerminate();
            }
            exit(-1);
        }
        s_windowCount++;

        glfwMakeContextCurrent(m_window);
        glfwSetWindowUserPointer(m_window, this);

        glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* window, int32_t width, int32_t height) {
            Window& w = *(Window*)glfwGetWindowUserPointer(window);
            w.m_width = width;
            w.m_height = height;
            Renderer::SetViewport(0, 0, width, height);
        });

        glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
            Window& w = *(Window*) glfwGetWindowUserPointer(window);
            w.m_eventCallback(Event::WindowCloseEvent);
        });
    }

    Window::~Window() {
        glfwDestroyWindow(m_window);
        s_windowCount--;
        if (s_windowCount == 0) {
            glfwTerminate();
        }
    }

    void Window::OnUpdate() {
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

    uint32_t Window::GetWidth() const {
        return m_width;
    }

    uint32_t Window::GetHeight() const {
        return m_height;
    }

    glm::vec2 Window::GetSize() const {
        return { m_width, m_height };
    }

    void Window::EnableCursor() const {
        glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }

    void Window::DisableCursor() const {
        glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    }

} // DwarfEngine