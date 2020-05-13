# SimpleLogger is a (very) simple c++ logging library

* Stdout outputting 
* Color output depending on logLevel
* Levels of output: Info, Warning, Error

* TODO: 
  * Implement logInfo / logWarning / logError  

Usage:
``` c++
  #include "slog/logger.hpp"

  using namespace slog;

  Logger logger; // Default loggingLevel == Level::info
  logger.log("This is an info message");

  logger.setLogLevel(Level::Warning);
  logger.log("This is a warning message");

  logger.setLogLevel(Level::Error);
  logger.log("This is a warning message");

```
