#include "Application.h"
#include <glfw/glfw3.h>
#include "Logger.h"
#include "../renderer/OpenGLContext.h"
#include "../renderer/Renderer.h"
#include "../input/Input.h"

namespace DwarfEngine {

    Application* Application::s_instance = nullptr;

    Application::Application(const std::string& title, uint32_t width, uint32_t height) {
        if (s_instance) {
            Logger::error("Application already exists");
            exit(-1);
        }
        s_instance = this;

        m_running = false;
        m_window = std::make_shared<Window>(title, width, height, [this](Event event) { this->OnEvent(event); });

        OpenGLContext::Init();
        Input::Init();
    }

    Application& Application::Get() {
        return *s_instance;
    }

    void Application::Start() {
        m_running = true;
        Run();
    }

    void Application::Close() {
        m_running = false;
    }

    void Application::Run() {
        float deltaTime = 0.0f;
        float lastTime = 0.0f;

        m_activeScene->OnStart();
        while (m_running) {
            Renderer::ClearScreen();

            m_activeScene->OnUpdate(deltaTime);
            m_activeScene->OnRender();

            m_window->OnUpdate();

            auto currentTime = (float)GetTime();
            deltaTime = currentTime - lastTime;
            lastTime = currentTime;
        }
    }

    void Application::OnEvent(DwarfEngine::Event event) {
        if (event == Event::WindowCloseEvent) {
            m_running = false;
        }
    }

    const Window& Application::GetWindow() const {
        return *m_window;
    }

    double Application::GetTime() {
        return glfwGetTime();
    }

    void Application::SetScene(const std::shared_ptr<Scene>& scene) {
        m_activeScene = scene;
    }

}  // DwarfEngine
