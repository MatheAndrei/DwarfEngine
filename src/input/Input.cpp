#include "Input.h"
#include <glfw/glfw3.h>

namespace DwarfEngine {

    GLFWwindow* Input::s_window = nullptr;
    std::vector<KeyCallbackFn> Input::s_keyCallbackFns = std::vector<KeyCallbackFn>();
    std::vector<MouseCallbackFn> Input::s_mouseCallbackFns = std::vector<MouseCallbackFn>();
    std::vector<CursorPositionCallbackFn> Input::s_cursorCallbackFns = std::vector<CursorPositionCallbackFn>();
    std::vector<CursorEnterCallbackFn> Input::s_cursorEnterCallbackFns = std::vector<CursorEnterCallbackFn>();
    std::vector<ScrollCallbackFn> Input::s_scrollCallbackFns = std::vector<ScrollCallbackFn>();

    void Input::Init() {
        s_window = glfwGetCurrentContext();

        glfwSetKeyCallback(s_window, DispatchKeyEvent);
        glfwSetMouseButtonCallback(s_window, DispatchMouseEvent);
        glfwSetCursorPosCallback(s_window, DispatchCursorEvent);
        glfwSetCursorEnterCallback(s_window, DispatchCursorEnterEvent);
        glfwSetScrollCallback(s_window, DispatchScrollEvent);
    }

    void Input::DispatchKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods) {
        for (auto& fn : s_keyCallbackFns) {
            fn((Key)key, (Action)action);
        }
    }

    void Input::DispatchMouseEvent(GLFWwindow* window, int button, int action, int mods) {
        for (auto& fn : s_mouseCallbackFns) {
            fn((Mouse)button, (Action)action);
        }
    }

    void Input::DispatchCursorEvent(GLFWwindow* window, double xpos, double ypos) {
        for (auto& fn : s_cursorCallbackFns) {
            fn({ xpos, ypos });
        }
    }

    void Input::DispatchCursorEnterEvent(GLFWwindow *window, int entered) {
        for (auto& fn : s_cursorEnterCallbackFns) {
            fn(entered);
        }
    }

    void Input::DispatchScrollEvent(GLFWwindow* window, double xoffset, double yoffset) {
        for (auto& fn : s_scrollCallbackFns) {
            fn({ xoffset, yoffset });
        }
    }

    bool Input::GetKeyPressed(Key key) {
        return glfwGetKey(s_window, (int)key) == GLFW_PRESS;
    }

    bool Input::GetKeyReleased(Key key) {
        return glfwGetKey(s_window, (int)key) == GLFW_RELEASE;
    }

    bool Input::GetMouseButtonPressed(Mouse button) {
        return glfwGetMouseButton(s_window, (int)button) == GLFW_PRESS;
    }

    bool Input::GetMouseButtonReleased(Mouse button) {
        return glfwGetMouseButton(s_window, (int)button) == GLFW_RELEASE;
    }

    void Input::SetCursorPosition(const glm::vec2& position) {
        glfwSetCursorPos(s_window, position.x, position.y);
    }

    glm::vec2 Input::GetCursorPosition() {
        double x, y;
        glfwGetCursorPos(s_window, &x, &y);
        return { x, y };
    }

    void Input::RegisterKeyCallback(const KeyCallbackFn& keyCallbackFn) {
        s_keyCallbackFns.push_back(keyCallbackFn);
    }

    void Input::RegisterMouseButtonCallback(const MouseCallbackFn& mouseCallbackFn) {
        s_mouseCallbackFns.push_back(mouseCallbackFn);
    }

    void Input::RegisterCursorPositionCallback(const CursorPositionCallbackFn& cursorCallbackFn) {
        s_cursorCallbackFns.push_back(cursorCallbackFn);
    }

    void Input::RegisterScrollCallback(const ScrollCallbackFn& scrollCallbackFn) {
        s_scrollCallbackFns.push_back(scrollCallbackFn);
    }

    void Input::RegisterCursorEnterCallback(const CursorEnterCallbackFn &cursorEnterCallbackFn) {
        s_cursorEnterCallbackFns.push_back(cursorEnterCallbackFn);
    }

} // DwarfEngine