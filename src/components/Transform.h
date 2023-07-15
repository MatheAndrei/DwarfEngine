#ifndef DWARFENGINE_TRANSFORM_H
#define DWARFENGINE_TRANSFORM_H

#include <glm/glm.hpp>

namespace DwarfEngine {

    class Transform {
    public:
        explicit Transform(glm::vec3 position = {0.0f, 0.0f, 0.0f},
                  glm::vec3 rotation = {0.0f, 0.0f, 0.0f},
                  glm::vec3 scale = {1.0f, 1.0f, 1.0f});

        void Translate(glm::vec3 translation);
        void Translate(float x, float y, float z);
        void Rotate(glm::vec3 eulers);
        void Rotate(float x, float y, float z);
        void Scale(glm::vec3 scale);
        void Scale(float x, float y, float z);

        [[nodiscard]] glm::mat4 GetMatrix() const;

    public:
        glm::vec3 position{0.0f, 0.0f, 0.0f};
        glm::vec3 rotation{0.0f, 0.0f, 0.0f};
        glm::vec3 scale{1.0f, 1.0f, 1.0f};
        glm::vec3 front{0.0f, 0.0f, -1.0f};
    };

} // DwarfEngine

#endif //DWARFENGINE_TRANSFORM_H
