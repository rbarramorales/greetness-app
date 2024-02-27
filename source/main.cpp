#include <iostream>
#include <string>

#include "greetness2/greetness2.hpp"
#include "lib.hpp"

auto main() -> int
{
  auto const lib = library {};
  auto const message = "Hello from " + lib.name + "!";
  std::cout << message << '\n';

  const exported_class greeter {};
  auto const message2 = "Hello from " + std::string(greeter.name()) + "!";
  std::cout << message2 << '\n';

  return 0;
}
