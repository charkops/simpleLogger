#pragma once

// ANSI Color codes
namespace slog {

  enum class Color {
    Red,
    Yellow,
    Green,
    LightGreen,
    White
  };

  constexpr char RED_START[] = "\033[31;1m";
  constexpr char YELLOW_START[] = "\033[33;1m";
  constexpr char GREEN_START[] = "\033[32;1m";
  constexpr char WHITE_START[] = "\033[37;0m";
  constexpr char LIGHTGREEN_START[] = "\033[92;1m";
  constexpr char COLOR_STOP[] = "\033[0m";
};