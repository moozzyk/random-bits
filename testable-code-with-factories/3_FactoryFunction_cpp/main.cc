#include <iostream>
#include <string>

#include "factory_function.h"

int main() {
  WeatherStation{TemperatureSensorModel::SensorA}.printWeather();
  WeatherStation{TemperatureSensorModel::SensorB}.printWeather();
  WeatherStation{TemperatureSensorModel::SensorC}.printWeather();
  return 0;
}
