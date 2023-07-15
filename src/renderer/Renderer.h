#ifndef DWARFENGINE_RENDERER_H
#define DWARFENGINE_RENDERER_H

#include <memory>
#include "VertexArray.h"
#include "Shader.h"

namespace DwarfEngine {

    class Renderer {
    public:
        static void ClearScreen();
        static void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);

        static void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& shader);
        static void DrawArrays(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& shader);
    };

} // DwarfEngine

#endif //DWARFENGINE_RENDERER_H
