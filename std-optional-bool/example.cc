#include <iostream>
#include <optional>
#include <string>

int main() {
  {
    // no std::optional<bool> - business as usual
    bool isMorning = false;
    if (isMorning) {
      std::cout << "Good Morning!" << std::endl;
    } else {
      std::cout << "Good Afternoon!" << std::endl;
    }
  }

  {
    // Unintentional behavior:
    // `if (isMorning)` is actually `if (isMorning.has_value())`
    std::optional<bool> isMorning = false;
    if (isMorning) {
      std::cout << "Good Morning!" << std::endl;
    } else {
      std::cout << "Good Afternoon!" << std::endl;
    }
  }

  {
    // Same behavior for non-bool types.
    std::optional<int> n = 0;
    if (n) {
      std::cout << "Condition evaluated to true" << std::endl;
    } else {
      std::cout << "Condition evaluated to false" << std::endl;
    }
  }

  {
    // Unwrap `std::optional<bool>` - throws `std::bad_optional_access` if the
    // value is not initialized
    std::optional<bool> isMorning = false;
    if (isMorning.value()) {
      std::cout << "Good Morning!" << std::endl;
    } else {
      std::cout << "Good Afternoon!" << std::endl;
    }
  }

  {
    // Dereference `std::optional` - only works if the variable is guaranteed to
    // be initialized otherwise UB (undefined behavior)
    std::optional<bool> isMorning = false;
    if (*isMorning) {
      std::cout << "Good Morning!" << std::endl;
    } else {
      std::cout << "Good Afternoon!" << std::endl;
    }
  }

  {
    // Compare with a value. Keep in mind that std::nullopt compared to
    // non-optional value returns false. Caveat: it is tempting to optimize the
    // condition and remove the `== false` part which introduces a bug.
    std::optional<bool> isMorning = std::nullopt;
    if (isMorning == false) {
      std::cout << "It's not morning anymore..." << std::endl;
    } else {
      std::cout << "Good Morning!" << std::endl;
    }
  }

  {
    // Use `.value_or()` if you can provide a sensible default value if the
    // variable is not initialized.
    std::optional<bool> isMorning = std::nullopt;
    if (!isMorning.value_or(false)) {
      std::cout << "It's not morning anymore..." << std::endl;
    } else {
      std::cout << "Good Morning!" << std::endl;
    }
  }

  {
    // Handle std::nullopt explicitly.
    std::optional<bool> isMorning = std::nullopt;
    if (isMorning.has_value()) {
      if (isMorning.value()) {
        std::cout << "Good Morning!" << std::endl;
      } else {
        std::cout << "Good Afternoon!" << std::endl;
      }
    } else {
      std::cout << "I am lost in time..." << std::endl;
    }
  }

  return 0;
}
