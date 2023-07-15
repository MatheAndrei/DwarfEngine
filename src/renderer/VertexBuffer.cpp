#include "VertexBuffer.h"
#include <glad/glad.h>

namespace DwarfEngine {

    VertexBuffer::VertexBuffer(uint32_t size) : m_id(0), m_count(size / sizeof(float)) {
        glGenBuffers(1, &m_id);
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
        glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    VertexBuffer::VertexBuffer(float* vertices, uint32_t size) : m_id(0), m_count(size / sizeof(float)) {
        glGenBuffers(1, &m_id);
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    VertexBuffer::~VertexBuffer() {
        glDeleteBuffers(1, &m_id);
    }

    void VertexBuffer::SetData(float* vertices, uint32_t size) const {
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
        glBufferSubData(GL_ARRAY_BUFFER, 0, size, vertices);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void VertexBuffer::SetLayout(const VertexBufferLayout& layout) {
        m_layout = layout;
    }

    const VertexBufferLayout& VertexBuffer::GetLayout() const {
        return m_layout;
    }

    uint32_t VertexBuffer::GetCount() const {
        return m_count;
    }

    void VertexBuffer::Bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
    }

    void VertexBuffer::Unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

} // DwarfEngine