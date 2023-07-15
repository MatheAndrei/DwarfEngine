#include "VertexBufferLayout.h"

namespace DwarfEngine {

    // ########## VERTEX ATTRIB ########## //
    uint32_t GetVertexAttribTypeSize(VertexAttribType type) {
        switch (type) {
            case VertexAttribType::BYTE:
            case VertexAttribType::UNSIGNED_BYTE:
                return 1;

            case VertexAttribType::SHORT:
            case VertexAttribType::UNSIGNED_SHORT:
                return 2;

            case VertexAttribType::INT:
            case VertexAttribType::UNSIGNED_INT:
            case VertexAttribType::FLOAT:
                return 4;
            default:
                return 0;
        }
    }

    // ########## VERTEX LAYOUT ########## //
    VertexBufferLayout::VertexBufferLayout() : m_stride(0) {}

    uint32_t VertexBufferLayout::GetStride() const {
        return m_stride;
    }

    const std::vector<VertexAttrib>& VertexBufferLayout::GetAttributes() const {
        return m_attributes;
    }

} // DwarfEngine