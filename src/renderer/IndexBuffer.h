#ifndef DWARFENGINE_INDEXBUFFER_H
#define DWARFENGINE_INDEXBUFFER_H

#include <cstdint>

namespace DwarfEngine {

    class IndexBuffer {
    public:
        explicit IndexBuffer(uint32_t count);
        IndexBuffer(uint32_t* indices, uint32_t count);
        ~IndexBuffer();

        void SetData(uint32_t* indices, uint32_t count) const;
        [[nodiscard]] uint32_t GetCount() const;

        void Bind() const;
        void Unbind() const;

    private:
        uint32_t m_id;
        uint32_t m_count;
    };

} // DwarfEngine

#endif //DWARFENGINE_INDEXBUFFER_H
