#ifndef DWARFENGINE_SCENE_H
#define DWARFENGINE_SCENE_H

#include <memory>
#include "../core/Window.h"

namespace DwarfEngine {

    class Scene {
    public:
        Scene() = default;
        virtual ~Scene() = default;

        virtual void OnStart() {};
        virtual void OnUpdate(float deltaTime) {};
        virtual void OnRender() {};
    };

} // DwarfEngine

#endif //DWARFENGINE_SCENE_H
