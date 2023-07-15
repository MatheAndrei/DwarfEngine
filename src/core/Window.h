#ifndef DWARFENGINE_WINDOW_H
#define DWARFENGINE_WINDOW_H

#include <glm/glm.hpp>
#include <string>
#include <functional>
#include "Event.h"

struct GLFWwindow;

namespace DwarfEngine {

    class Window {
        using EventCallbackFn = std::function<void(Event)>;

    public:
        Window(std::string title, uint32_t width, uint32_t height, EventCallbackFn eventCallback);
        ~Window();

        void OnUpdate();

        [[nodiscard]] uint32_t GetWidth() const;
        [[nodiscard]] uint32_t GetHeight() const;
        [[nodiscard]] glm::vec2 GetSize() const;

        void EnableCursor() const;
        void DisableCursor() const;

    private:
        std::string m_title;
        uint32_t m_width;
        uint32_t m_height;
        GLFWwindow* m_window;
        EventCallbackFn m_eventCallback;
    };

} // DwarfEngine

#endif //DWARFENGINE_WINDOW_H
