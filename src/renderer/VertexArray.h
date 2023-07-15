#ifndef DWARFENGINE_VERTEXARRAY_H
#define DWARFENGINE_VERTEXARRAY_H

#include <memory>
#include "VertexBuffer.h"
#include "IndexBuffer.h"

namespace DwarfEngine {

    class VertexArray {
    public:
        VertexArray();
        ~VertexArray();

        void SetVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer);
        void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer);

        [[nodiscard]] const std::shared_ptr<VertexBuffer>& GetVertexBuffer() const;
        [[nodiscard]] const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const;

        void Bind() const;
        void Unbind() const;

    private:
        uint32_t m_id;
        std::shared_ptr<VertexBuffer> m_vertexBuffer;
        std::shared_ptr<IndexBuffer> m_indexBuffer;
    };

} // DwarfEngine

#endif //DWARFENGINE_VERTEXARRAY_H
