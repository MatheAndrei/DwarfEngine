#include "OpenGLContext.h"
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <sstream>
#include "../core/Logger.h"
#include "OpenGLThings.h"

namespace DwarfEngine {

    void OpenGLContext::Init() {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            Logger::critical("Failed to initialize GLAD");
            exit(-1);
        }

        auto vendor = reinterpret_cast<const char*>(glGetString(GL_VENDOR));
        auto openGLVersion = reinterpret_cast<const char*>(glGetString(GL_VERSION));
        auto glslVersion = reinterpret_cast<const char*>(glGetString(GL_SHADING_LANGUAGE_VERSION));
        Logger::info(fmt::format("Vendor {}", vendor));
        Logger::info(fmt::format("OpenGL version {}", openGLVersion));
        Logger::info(fmt::format("GLSL version {}", glslVersion));

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(HandleDebugMessage, nullptr);
    }

    static std::string GetSourceString(uint32_t source) {
        switch (source) {
            case GL_DEBUG_SOURCE_API: return "API";
            case GL_DEBUG_SOURCE_SHADER_COMPILER: return "Shader Compiler";
            case GL_DEBUG_SOURCE_WINDOW_SYSTEM: return "Window System";
            case GL_DEBUG_SOURCE_THIRD_PARTY: return "Third Party";
            case GL_DEBUG_SOURCE_APPLICATION: return "Application";
            case GL_DEBUG_SOURCE_OTHER: return "Other";
            default: return "Unknown";
        }
    }

    static std::string GetTypeString(uint32_t type) {
        switch (type) {
            case GL_DEBUG_TYPE_ERROR: return "Error";
            case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: return "Deprecated behavior";
            case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR: return "Undefined behavior";
            case GL_DEBUG_TYPE_PORTABILITY: return "Portability";
            case GL_DEBUG_TYPE_PERFORMANCE: return "Performance";
            case GL_DEBUG_TYPE_MARKER: return "Marker";
            case GL_DEBUG_TYPE_PUSH_GROUP: return "Push group";
            case GL_DEBUG_TYPE_POP_GROUP: return "Pop group";
            case GL_DEBUG_TYPE_OTHER: return "Other";
            default: return "Unknown";
        }
    }

    static std::string GetSeverityString(uint32_t severity) {
        switch (severity) {
            case GL_DEBUG_SEVERITY_LOW: return "Low";
            case GL_DEBUG_SEVERITY_MEDIUM: return "Medium";
            case GL_DEBUG_SEVERITY_HIGH: return "High";
            case GL_DEBUG_SEVERITY_NOTIFICATION: return "Notification";
            default: return "Unknown";
        }
    }

    void OpenGLContext::HandleDebugMessage(uint32_t source, uint32_t type, uint32_t id, uint32_t severity, int32_t length, const char* message, const void* userParam) {
        std::string sourceString = GetSourceString(source);
        std::string typeString = GetTypeString(type);
        std::string idString = OpenGLValueToEnum.at(id);
        std::string severityString = GetSeverityString(severity);

        std::ostringstream logMessage;
        logMessage << "OpenGL Debug Message\n";
        logMessage << "- source: " << sourceString << "\n";
        logMessage << "- type: " << typeString << "\n";
        logMessage << "- severity: " << severityString << "\n";
        logMessage << "- id: " << idString << "\n";
        logMessage << "- message: " << message;

        Logger::error(logMessage.str());
    }

} // DwarfEngine