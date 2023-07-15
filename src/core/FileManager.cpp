#include "FileManager.h"
#include <fstream>
#include <sstream>
#include "Logger.h"

namespace DwarfEngine {

    std::string FileManager::ReadFile(const std::string& filepath) {
        std::ifstream file{filepath};
        if (!file) {
            Logger::error("Could not open file " + filepath);
            return "";
        }
        std::ostringstream data;
        data << file.rdbuf();
        return data.str();
    }

    std::filesystem::path FileManager::GetWorkingDirectory() {
        return std::filesystem::current_path();
    }

} // DwarfEngine