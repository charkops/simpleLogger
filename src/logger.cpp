#include "logger.hpp"

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
    cout << "[Logger constructor]: Initialized logger with level == " << loggingLevel_ << endl;
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

  void Logger::log(const char *message, bool newLine) {    
    auto prefix = getCurrentPrefix();
    std::string finalMessage = "[" + prefix + "]: " + std::string(message);
    if (newLine)
      cout << finalMessage << endl;
    else 
      cout << finalMessage;
  };

  void Logger::log(const std::string &message, bool newLine) {
    log(message.c_str(), newLine);
  };
};