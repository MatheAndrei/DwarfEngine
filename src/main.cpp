#include "DwarfEngine.h"
#include "sandbox/MainScene.h"

int main() {
    DwarfEngine::Application application{"App", 1028, 720};
    auto mainScene = std::make_shared<MainScene>();
    application.SetScene(mainScene);
    application.Start();

    return 0;
}