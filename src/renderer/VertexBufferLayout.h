#ifndef DWARFENGINE_VERTEXBUFFERLAYOUT_H
#define DWARFENGINE_VERTEXBUFFERLAYOUT_H

#include <vector>
#include <cstdint>
#include <cassert>

namespace DwarfEngine {

    enum class VertexAttribType {
        BYTE = 0x1400,
        UNSIGNED_BYTE = 0x1401,
        SHORT = 0x1402,
        UNSIGNED_SHORT = 0x1403,
        INT = 0x1404,
        UNSIGNED_INT = 0x1405,
        FLOAT = 0x1406
    };

    uint32_t GetVertexAttribTypeSize(VertexAttribType type);

    struct VertexAttrib {
        uint32_t count;
        VertexAttribType type;
        bool normalized;
    };

    class VertexBufferLayout {
    public:
        VertexBufferLayout();

        [[nodiscard]] uint32_t GetStride() const;
        [[nodiscard]] const std::vector<VertexAttrib>& GetAttributes() const;

        template<typename T>
        void Push(uint32_t count) {
            assert(false);
        }

    private:
        std::vector<VertexAttrib> m_attributes;
        uint32_t m_stride;
    };

    template<>
    inline void VertexBufferLayout::Push<int8_t>(uint32_t count) {
        m_attributes.push_back({count, VertexAttribType::BYTE, false});
        m_stride += count * GetVertexAttribTypeSize(VertexAttribType::BYTE);
    }

    template<>
    inline void VertexBufferLayout::Push<uint8_t>(uint32_t count) {
        m_attributes.push_back({count, VertexAttribType::UNSIGNED_BYTE, false});
        m_stride += count * GetVertexAttribTypeSize(VertexAttribType::UNSIGNED_BYTE);
    }

    template<>
    inline void VertexBufferLayout::Push<int16_t>(uint32_t count) {
        m_attributes.push_back({count, VertexAttribType::SHORT, false});
        m_stride += count * GetVertexAttribTypeSize(VertexAttribType::SHORT);
    }

    template<>
    inline void VertexBufferLayout::Push<uint16_t>(uint32_t count) {
        m_attributes.push_back({count, VertexAttribType::UNSIGNED_SHORT, false});
        m_stride += count * GetVertexAttribTypeSize(VertexAttribType::UNSIGNED_SHORT);
    }

    template<>
    inline void VertexBufferLayout::Push<int32_t>(uint32_t count) {
        m_attributes.push_back({count, VertexAttribType::INT, false});
        m_stride += count * GetVertexAttribTypeSize(VertexAttribType::INT);
    }

    template<>
    inline void VertexBufferLayout::Push<uint32_t>(uint32_t count) {
        m_attributes.push_back({count, VertexAttribType::UNSIGNED_INT, false});
        m_stride += count * GetVertexAttribTypeSize(VertexAttribType::UNSIGNED_INT);
    }

    template<>
    inline void VertexBufferLayout::Push<float>(uint32_t count) {
        m_attributes.push_back({count, VertexAttribType::FLOAT, false});
        m_stride += count * GetVertexAttribTypeSize(VertexAttribType::FLOAT);
    }

} // DwarfEngine

#endif //DWARFENGINE_VERTEXBUFFERLAYOUT_H
