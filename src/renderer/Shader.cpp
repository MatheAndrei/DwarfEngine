#include "Shader.h"
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include "../core/FileManager.h"
#include "../core/Logger.h"

namespace DwarfEngine {

    Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) : m_id(0) {
        m_id = glCreateProgram();
        m_vertexShaderPath = vertexShaderPath;
        m_fragmentShaderPath = fragmentShaderPath;

        std::string vertexShaderSource = FileManager::ReadFile(vertexShaderPath);
        std::string fragmentShaderSource = FileManager::ReadFile(fragmentShaderPath);

        const char* vertexShaderSourceC = vertexShaderSource.c_str();
        const char* fragmentShaderSourceC = fragmentShaderSource.c_str();

        uint32_t vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSourceC, nullptr);
        glCompileShader(vertexShader);

        uint32_t fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSourceC, nullptr);
        glCompileShader(fragmentShader);

        glAttachShader(m_id, vertexShader);
        glAttachShader(m_id, fragmentShader);
        glLinkProgram(m_id);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    Shader::~Shader() {
        glDeleteProgram(m_id);
    }

    void Shader::Bind() const {
        glUseProgram(m_id);
    }

    void Shader::Unbind() const {
        glUseProgram(0);
    }

    int32_t Shader::GetUniformLocation(const std::string& name) {
        if (m_uniformCache.find(name) != m_uniformCache.end()) {
            return m_uniformCache[name];
        }

        int32_t location = glGetUniformLocation(m_id, name.c_str());
        if (location == -1) {
            Logger::warn("Uniform " + name + " location not found");
        } else {
            m_uniformCache[name] = location;
        }

        return location;
    }

    void Shader::SetUniformInt(const std::string& name, int32_t value) {
        int32_t location = GetUniformLocation(name);
        Bind();
        glUniform1i(location, value);
        Unbind();
    }

    void Shader::SetUniformFloat(const std::string& name, float value) {
        int32_t location = GetUniformLocation(name);
        Bind();
        glUniform1f(location, value);
        Unbind();
    }

    void Shader::SetUniformVec2(const std::string& name, glm::vec2 vec2) {
        int32_t location = GetUniformLocation(name);
        Bind();
        glUniform2fv(location, 1, glm::value_ptr(vec2));
        Unbind();
    }

    void Shader::SetUniformMat4(const std::string& name, glm::mat4 mat4) {
        int32_t location = GetUniformLocation(name);
        Bind();
        glUniformMatrix4fv(location, 1, false, glm::value_ptr(mat4));
        Unbind();
    }

} // DwarfEngine