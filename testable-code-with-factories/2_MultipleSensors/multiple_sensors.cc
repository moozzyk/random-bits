#include <iostream>
#include <string>

enum class TemperatureSensorModel {
  SensorA,
  SensorB,
  SensorC,
};

class TemperatureSensor {
 public:
  virtual float getTemperature() = 0;
  virtual ~TemperatureSensor() = default;
};

class TemperatureSensorA : public TemperatureSensor {
 public:
  float getTemperature() override { return 22.0; }
};

class TemperatureSensorB : public TemperatureSensor {
 public:
  float getTemperature() override { return 22.37; }
};

class TemperatureSensorC : public TemperatureSensor {
 public:
  float getTemperature() override { return 22.3734; }
};

struct WeatherReport {
  const float temperature;
};

class WeatherStation {
 public:
  WeatherStation(TemperatureSensorModel tempSensorModel)
      : tempSensor_{createSensor(tempSensorModel)} {}

  WeatherReport getWeatherReport() {
    return WeatherReport{.temperature = tempSensor_->getTemperature()};
  }

 private:
  static std::unique_ptr<TemperatureSensor> createSensor(
      TemperatureSensorModel tempSensorModel) {
    switch (tempSensorModel) {
      case TemperatureSensorModel::SensorA:
        return std::make_unique<TemperatureSensorA>();
      case TemperatureSensorModel::SensorB:
        return std::make_unique<TemperatureSensorB>();
      case TemperatureSensorModel::SensorC:
        return std::make_unique<TemperatureSensorC>();
    }
  }

  std::unique_ptr<TemperatureSensor> tempSensor_;
};

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