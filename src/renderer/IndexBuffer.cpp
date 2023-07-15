#include "IndexBuffer.h"
#include <glad/glad.h>

namespace DwarfEngine {

    IndexBuffer::IndexBuffer(uint32_t count) : m_id(0), m_count(count) {
        glGenBuffers(1, &m_id);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * (uint32_t)sizeof(uint32_t), nullptr, GL_DYNAMIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    IndexBuffer::IndexBuffer(uint32_t* indices, uint32_t count) : m_id(0), m_count(count) {
        glGenBuffers(1, &m_id);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * (uint32_t)sizeof(uint32_t), indices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    IndexBuffer::~IndexBuffer() {
        glDeleteBuffers(1, &m_id);
    }

    void IndexBuffer::SetData(uint32_t* indices, uint32_t count) const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
        glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, count * (uint32_t)sizeof(uint32_t), indices);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    uint32_t IndexBuffer::GetCount() const {
        return m_count;
    }

    void IndexBuffer::Bind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
    }

    void IndexBuffer::Unbind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

} // DwarfEngine