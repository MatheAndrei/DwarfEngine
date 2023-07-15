#include "MainScene.h"

void MainScene::OnStart() {
    static bool firstTimeCursorEntered = false;

    Input::RegisterCursorEnterCallback([](bool entered) {
        if (entered) {
            firstTimeCursorEntered = true;
            Application::Get().GetWindow().DisableCursor();
        }
    });

    Input::RegisterCursorPositionCallback([this](glm::vec2 position) {
        static glm::vec2 lastPosition{(float) Application::Get().GetWindow().GetWidth() / 2.0f,
                                      (float) Application::Get().GetWindow().GetHeight() / 2.0f};

        if (firstTimeCursorEntered) {
            lastPosition = position;
            firstTimeCursorEntered = false;
        }

        glm::vec2 offset = position - lastPosition;
        lastPosition = position;

        offset.y = -offset.y;
        offset *= cameraSensitivity;
        camera.transform.Rotate(offset.y, offset.x, 0.0f);

        if (camera.transform.rotation.x > 89.0f)
            camera.transform.rotation.x = 89.0f;
        if (camera.transform.rotation.x < -89.f)
            camera.transform.rotation.x = -89.0f;
    });

    camera.transform.Translate({0.0f, 0.0f, 3.0f});
}

void MainScene::OnUpdate(float deltaTime) {
    if (Input::GetKeyPressed(Key::W))
        camera.transform.position += camera.transform.front * deltaTime;
    if (Input::GetKeyPressed(Key::S))
        camera.transform.position -= camera.transform.front * deltaTime;
    if (Input::GetKeyPressed(Key::A))
        camera.transform.position -= glm::normalize(glm::cross(camera.transform.front, {0.0f, 1.0f, 0.0f})) * deltaTime;
    if (Input::GetKeyPressed(Key::D))
        camera.transform.position += glm::normalize(glm::cross(camera.transform.front, {0.0f, 1.0f, 0.0f})) * deltaTime;
}

void MainScene::OnRender() {
    box.Draw(camera);
}