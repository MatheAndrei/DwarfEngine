#ifndef DWARFENGINE_OPENGLCONTEXT_H
#define DWARFENGINE_OPENGLCONTEXT_H

#include <cstdint>

namespace DwarfEngine {

    class OpenGLContext {
    public:
        static void Init();

    public:
        static void HandleDebugMessage(uint32_t source,
                                       uint32_t type,
                                       uint32_t id,
                                       uint32_t severity,
                                       int32_t length,
                                       const char* message,
                                       const void* userParam);
    };

} // DwarfEngine

#endif //DWARFENGINE_OPENGLCONTEXT_H
