#include "VertexArray.h"
#include <glad/glad.h>

namespace DwarfEngine {

    VertexArray::VertexArray() : m_id(0) {
        glGenVertexArrays(1, &m_id);
    }

    VertexArray::~VertexArray() {
        glDeleteVertexArrays(1, &m_id);
    }

    void VertexArray::SetVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) {
        m_vertexBuffer = vertexBuffer;

        glBindVertexArray(m_id);
        m_vertexBuffer->Bind();

        uint64_t offset = 0;
        uint32_t stride = m_vertexBuffer->GetLayout().GetStride();
        auto& attributes = m_vertexBuffer->GetLayout().GetAttributes();
        for (int i = 0; i < attributes.size(); ++i) {
            glEnableVertexAttribArray(i);
            glVertexAttribPointer(i, (int32_t)attributes[i].count, static_cast<GLenum>(attributes[i].type), attributes[i].normalized, (int32_t)stride, reinterpret_cast<const void*>(offset));
            offset += attributes[i].count * GetVertexAttribTypeSize(attributes[i].type);
        }

        glBindVertexArray(0);
    }

    void VertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) {
        m_indexBuffer = indexBuffer;

        glBindVertexArray(m_id);
        m_indexBuffer->Bind();

        glBindVertexArray(0);
    }

    const std::shared_ptr<VertexBuffer>& VertexArray::GetVertexBuffer() const {
        return m_vertexBuffer;
    }

    const std::shared_ptr<IndexBuffer>& VertexArray::GetIndexBuffer() const {
        return m_indexBuffer;
    }

    void VertexArray::Bind() const {
        glBindVertexArray(m_id);
    }

    void VertexArray::Unbind() const {
        glBindVertexArray(0);
    }

} // DwarfEngine