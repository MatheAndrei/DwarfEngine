#ifndef DWARFENGINE_CAMERA_H
#define DWARFENGINE_CAMERA_H

#include "Transform.h"

namespace DwarfEngine {

    class Camera {
    public:
        [[nodiscard]] glm::mat4 GetView() const;
        [[nodiscard]] glm::mat4 GetProjection() const;

    public:
        Transform transform;
        float fov{45.0f};
        float aspectRatio{16.0f / 9.0f};
        float nearClipPlane{0.1f};
        float farClipPlane{100.0f};
    };

} // DwarfEngine

#endif //DWARFENGINE_CAMERA_H
