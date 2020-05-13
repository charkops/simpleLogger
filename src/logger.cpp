#include "logger.hpp"
#include "colorCodes.hpp"

namespace slog {
  using std::cout;
  constexpr char endl = '\n';

  std::ostream& operator <<(std::ostream &os, Level level) {
    std::string levelString;
    switch (level)
    {
      case Level::Info:
        levelString = "Info";
        break;
      
      case Level::Warning:
        levelString = "Warning";
        break;
      case Level::Error:
        levelString = "Error";
        break;
      default:
        break;
    }
    return os << levelString;
  };

  void Logger::setLogLevel(Level level) {
    loggingLevel_ = level;
  };

  Logger::Logger()
  : loggingLevel_ (Level::Info)
  {
    // cout << "[Logger constructor]: Initialized logger with level == " << loggingLevel_ << endl;
  };

  std::string Logger::getCurrentPrefix() {
    std::string prefix;
    switch(loggingLevel_)
    {
      case Level::Info:
        prefix = InfoPrefix_;
        break;
      case Level::Warning:
        prefix = WarningPrefix_;
        break;
      case Level::Error:
        prefix = ErrorPrefix_;
        break;
      default:
        prefix = InfoPrefix_;
    };

    return prefix;
  };

  // Adds a [pre + post] fix to the ${text} to color it
  void Logger::colorText(std::string &text, Color color) {
    const char *colorCode;
    const char *stopCode = COLOR_STOP;

    switch (color)
    {
    case Color::Green:
      colorCode = GREEN_START;
      break;
    case Color::LightGreen:
      colorCode = LIGHTGREEN_START;
      break;
    case Color::Red:
      colorCode = RED_START;
      break;
    case Color::Yellow:
      colorCode = YELLOW_START;
      break;
    case Color::White:
    default:
      colorCode = WHITE_START;
    }
    text = colorCode + text + stopCode;
  };

  void Logger::log(const char *message, bool newLine) {    
    auto prefix = getCurrentPrefix();
    std::string greenIndent = std::string(GREEN_START) + ">" + std::string(COLOR_STOP) + " ";
    std::string content = "[" + prefix + "]: " + std::string(message);

    // Color text depending on current loggingLevel_
    switch (loggingLevel_)
    {
      case Level::Warning:
        Logger::colorText(content, Color::Yellow);
        break;

      case Level::Error:
        Logger::colorText(content, Color::Red);
        break;

      default: 
        Logger::colorText(content, Color::White);
        break;
    }

    std::string finalMessage = greenIndent + content;
    if (newLine)
      cout << finalMessage << endl;
    else 
      cout << finalMessage;
  };

  void Logger::log(const std::string &message, bool newLine) {
    log(message.c_str(), newLine);
  };

  
};