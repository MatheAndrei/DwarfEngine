#ifndef DWARFENGINE_APPLICATION_H
#define DWARFENGINE_APPLICATION_H

#include <string>
#include <memory>
#include "Window.h"
#include "Event.h"
#include "../scene/Scene.h"

namespace DwarfEngine {

    class Application {
    public:
        Application(const std::string& title, uint32_t width, uint32_t height);
        ~Application() = default;

        static Application& Get();

        void Start();
        void Close();

        [[nodiscard]] const Window& GetWindow() const;
        [[nodiscard]] static double GetTime() ;

        void SetScene(const std::shared_ptr<Scene>& scene);

    private:
        void Run();
        void OnEvent(Event event);

    private:
        bool m_running;
        std::shared_ptr<Window> m_window;
        std::shared_ptr<Scene> m_activeScene;

    private:
        static Application* s_instance;
    };

} // DwarfEngine

#endif //DWARFENGINE_APPLICATION_H
