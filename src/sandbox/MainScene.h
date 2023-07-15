#ifndef DWARFENGINE_MAINSCENE_H
#define DWARFENGINE_MAINSCENE_H

#include "../DwarfEngine.h"
#include "Box.h"

class MainScene : public Scene {
public:
    void OnStart() override;
    void OnUpdate(float deltaTime) override;
    void OnRender() override;

private:
    Camera camera;
    float cameraSensitivity{0.1f};

    Box box;
};


#endif //DWARFENGINE_MAINSCENE_H
