#include "Renderer.h"
#include <glad/glad.h>

namespace DwarfEngine {

    void Renderer::ClearScreen() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Renderer::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
        glViewport((int32_t)x, (int32_t)y, (int32_t)width, (int32_t)height);
    }

    void Renderer::DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& shader) {
        vertexArray->Bind();
        shader->Bind();
        glDrawElements(GL_TRIANGLES, (int32_t)vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
    }

    void Renderer::DrawArrays(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& shader) {
        vertexArray->Bind();
        shader->Bind();
        glDrawArrays(GL_TRIANGLES, 0, (int32_t)vertexArray->GetVertexBuffer()->GetCount());
    }

} // DwarfEngine