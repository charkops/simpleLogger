#pragma once

#include <iostream>

namespace slog {
  // Logging level
  // Info < Warning < Error
  enum class Level {
    Info,
    Warning,
    Error
  };  

  std::ostream& operator <<(std::ostream &os, Level level);

  class Logger {
  private:
    Level loggingLevel_;
    const std::string WarningPrefix_ = "Warning";
    const std::string InfoPrefix_ = "Info";
    const std::string ErrorPrefix_ = "Error";

    // Private functions
    std::string getCurrentPrefix();

  public:
    Logger();
    ~Logger() = default;

    void setLogLevel(Level level);
    void log(const char *message, bool newLine = true);
    void log(const std::string &message, bool newLine = true);
  };
};