#include "Camera.h"
#include "glm/gtc/matrix_transform.hpp"

namespace DwarfEngine {

    glm::mat4 Camera::GetView() const {
        return glm::lookAt(transform.position, transform.position + transform.front, {0.0f, 1.0f, 0.0f});
    }

    glm::mat4 Camera::GetProjection() const {
        return glm::perspective(glm::radians(fov), aspectRatio, nearClipPlane, farClipPlane);
    }

} // DwarfEngine