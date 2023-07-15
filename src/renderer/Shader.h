#ifndef DWARFENGINE_SHADER_H
#define DWARFENGINE_SHADER_H

#include <glm/glm.hpp>
#include <string>
#include <unordered_map>

namespace DwarfEngine {

    class Shader {
    public:
        Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
        ~Shader();

        void Bind() const;
        void Unbind() const;

        // TODO: Complete set uniform methods
        void SetUniformInt(const std::string& name, int32_t value);
        void SetUniformFloat(const std::string& name, float value);
        void SetUniformVec2(const std::string& name, glm::vec2 vec2);
        void SetUniformMat4(const std::string& name, glm::mat4 mat4);

    private:
        int32_t GetUniformLocation(const std::string& name);

    private:
        uint32_t m_id;
        std::string m_vertexShaderPath;
        std::string m_fragmentShaderPath;
        std::unordered_map<std::string, int32_t> m_uniformCache;
    };

} // DwarfEngine

#endif //DWARFENGINE_SHADER_H
