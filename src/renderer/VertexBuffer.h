#ifndef DWARFENGINE_VERTEXBUFFER_H
#define DWARFENGINE_VERTEXBUFFER_H

#include "VertexBufferLayout.h"

namespace DwarfEngine {

    class VertexBuffer {
    public:
        explicit VertexBuffer(uint32_t size);
        VertexBuffer(float* vertices, uint32_t size);
        ~VertexBuffer();

        void SetData(float* vertices, uint32_t size) const;
        void SetLayout(const VertexBufferLayout& layout);
        const VertexBufferLayout& GetLayout() const;
        uint32_t GetCount() const;

        void Bind() const;
        void Unbind() const;

    private:
        uint32_t m_id;
        uint32_t m_count;
        VertexBufferLayout m_layout;
    };

} // DwarfEngine

#endif //DWARFENGINE_VERTEXBUFFER_H
