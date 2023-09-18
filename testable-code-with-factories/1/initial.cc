#include <iostream>
#include <string>

class TemperatureSensor {
 public:
  float getTemperature() { return 22.0; }
};

class WeatherStation {
 public:
  void printWeather() {
    std::cout << "Temperature: " << TemperatureSensor{}.getTemperature() << "°C"
              << std::endl;
  }
};

int main() {
  WeatherStation{}.printWeather();
  return 0;
}
