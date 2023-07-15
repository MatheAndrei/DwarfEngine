#include "Transform.h"
#include <glm/gtx/euler_angles.hpp>

namespace DwarfEngine {

    Transform::Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
    : position(position), rotation(rotation), scale(scale) {}

    void Transform::Translate(glm::vec3 translation) {
        position += translation;
    }

    void Transform::Translate(float x, float y, float z) {
        position.x += x;
        position.y += y;
        position.z += z;
    }

    void Transform::Rotate(glm::vec3 eulers) {
        rotation += eulers;
    }

    void Transform::Rotate(float x, float y, float z) {
        rotation.x += x;
        rotation.y += y;
        rotation.z += z;

        front.x = glm::cos(glm::radians(rotation.y - 90.0f)) * glm::cos(glm::radians(rotation.x));
        front.y = glm::sin(glm::radians(rotation.x));
        front.z = glm::sin(glm::radians(rotation.y - 90.0f)) * glm::cos(glm::radians(rotation.x));
        front = glm::normalize(front);
    }

    void Transform::Scale(glm::vec3 scale) {
        this->scale += scale;
    }

    void Transform::Scale(float x, float y, float z) {
        scale.x += x;
        scale.y += y;
        scale.z += z;
    }

    glm::mat4 Transform::GetMatrix() const {
        return glm::translate(glm::mat4(1.0f), position) *
               glm::eulerAngleXYZ(glm::radians(rotation.x), glm::radians(rotation.y), glm::radians(rotation.z)) *
               glm::scale(glm::mat4(1.0f), scale);
    }

} // DwarfEngine