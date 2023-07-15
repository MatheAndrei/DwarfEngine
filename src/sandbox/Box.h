#ifndef DWARFENGINE_BOX_H
#define DWARFENGINE_BOX_H

#include "../DwarfEngine.h"

class Box {
public:
    Box();

    void Draw(const Camera& camera);

public:
    Transform transform;

private:
    std::shared_ptr<VertexArray> m_vertexArray;
    std::shared_ptr<Shader> m_shader;
};


#endif //DWARFENGINE_BOX_H
