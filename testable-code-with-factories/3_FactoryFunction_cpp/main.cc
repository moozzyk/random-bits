#include <iostream>
#include <string>

#include "factory_function.h"
void printWeather(WeatherReport report) {
  std::cout << "Temperature: " << report.temperature << "°C" << std::endl;
}

int main() {
  printWeather(
      WeatherStation{TemperatureSensorModel::SensorA}.getWeatherReport());
  printWeather(
      WeatherStation{TemperatureSensorModel::SensorB}.getWeatherReport());
  printWeather(
      WeatherStation{TemperatureSensorModel::SensorC}.getWeatherReport());
  return 0;
}
