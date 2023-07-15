#include "Logger.h"

namespace DwarfEngine {

    void Logger::log(Logger::Level level, const std::string& message) {
        std::time_t dateTime = std::time(nullptr);

        std::string levelString;
        fmt::text_style levelStyle;
        switch (level) {
            case Level::DEBUG:
                levelString = "debug";
                levelStyle = fmt::fg(fmt::color::light_gray);
                break;

            case Level::INFO:
                levelString = "info";
                levelStyle = fmt::fg(fmt::color::dodger_blue);
                break;

            case Level::WARNING:
                levelString = "warning";
                levelStyle = fmt::fg(fmt::color::orange);
                break;

            case Level::ERROR:
                levelString = "error";
                levelStyle = fmt::fg(fmt::color::red);
                break;

            case Level::CRITICAL:
                levelString = "critical";
                levelStyle = fmt::fg(fmt::color::black) | fmt::bg(fmt::color::fire_brick);
                break;
        }

        fmt::println("[{:%Y-%m-%d %H:%M:%S}] [{}] {}", fmt::localtime(dateTime), fmt::styled(levelString, levelStyle), message);
    }

    void Logger::debug(const std::string& message) {
        log(Level::DEBUG, message);
    }

    void Logger::info(const std::string& message) {
        log(Level::INFO, message);
    }

    void Logger::warn(const std::string& message) {
        log(Level::WARNING, message);
    }

    void Logger::error(const std::string& message) {
        log(Level::ERROR, message);
    }

    void Logger::critical(const std::string& message) {
        log(Level::CRITICAL, message);
    }

} // DwarfEngine