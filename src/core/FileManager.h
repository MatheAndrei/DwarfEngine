#ifndef DWARFENGINE_FILEMANAGER_H
#define DWARFENGINE_FILEMANAGER_H

#include <string>
#include <filesystem>

namespace DwarfEngine {

    class FileManager {
    public:
        static std::string ReadFile(const std::string& filepath);
        static std::filesystem::path GetWorkingDirectory();
    };

} // DwarfEngine

#endif //DWARFENGINE_FILEMANAGER_H
