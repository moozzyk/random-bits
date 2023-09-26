#include <iostream>
#include <optional>
#include <string>

bool isMorning() { return false; }

int main() {
  if (isMorning()) {
    std::cout << "Good Morning!" << std::endl;
  } else {
    std::cout << "Good Afternoon" << std::endl;
  }
  return 0;
}
