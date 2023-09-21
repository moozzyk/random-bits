#include <iostream>
#include <string>

class TemperatureSensor {
 public:
  float getTemperature() { return 22.0; }
};

struct WeatherReport {
  const float temperature;
};

class WeatherStation {
 public:
  WeatherReport getWeatherReport() {
    return WeatherReport{.temperature = TemperatureSensor{}.getTemperature()};
  }
};

int main() {
  std::cout << "Temperature: "
            << WeatherStation{}.getWeatherReport().temperature << "°C"
            << std::endl;
  return 0;
}
