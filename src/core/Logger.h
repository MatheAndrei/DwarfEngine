#ifndef DWARFENGINE_LOGGER_H
#define DWARFENGINE_LOGGER_H

#include <fmt/core.h>
#include <fmt/chrono.h>
#include <fmt/color.h>

namespace DwarfEngine {

    class Logger {
    public:
        enum class Level {
            DEBUG, INFO, WARNING, ERROR, CRITICAL
        };

        static void log(Level level, const std::string& message);
        static void debug(const std::string& message);
        static void info(const std::string& message);
        static void warn(const std::string& message);
        static void error(const std::string& message);
        static void critical(const std::string& message);

        template<typename... T>
        static void log(Level level, fmt::format_string<T...> fmt, T&&... args) {
            log(level, fmt::format(fmt, std::forward<T>(args)...));
        }

        template<typename... T>
        static void debug(fmt::format_string<T...> fmt, T&&... args) {
            debug(fmt::format(fmt, std::forward<T>(args)...));
        }

        template<typename... T>
        static void info(fmt::format_string<T...> fmt, T&&... args) {
            info(fmt::format(fmt, std::forward<T>(args)...));
        }

        template<typename... T>
        static void warn(fmt::format_string<T...> fmt, T&&... args) {
            warn(fmt::format(fmt, std::forward<T>(args)...));
        }

        template<typename... T>
        static void error(fmt::format_string<T...> fmt, T&&... args) {
            error(fmt::format(fmt, std::forward<T>(args)...));
        }

        template<typename... T>
        static void critical(fmt::format_string<T...> fmt, T&&... args) {
            critical(fmt::format(fmt, std::forward<T>(args)...));
        }
    };

} // DwarfEngine

#endif //DWARFENGINE_LOGGER_H
