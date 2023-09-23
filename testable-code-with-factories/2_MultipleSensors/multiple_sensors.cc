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
  WeatherStation(TemperatureSensorModel tempSensorModel) {
    switch (tempSensorModel) {
      case TemperatureSensorModel::SensorA:
        tempSensor_ = std::make_unique<TemperatureSensorA>();
        break;
      case TemperatureSensorModel::SensorB:
        tempSensor_ = std::make_unique<TemperatureSensorB>();
        break;
      case TemperatureSensorModel::SensorC:
        tempSensor_ = std::make_unique<TemperatureSensorC>();
        break;
    }
  }

  WeatherReport getWeatherReport() {
    return WeatherReport{.temperature = tempSensor_->getTemperature()};
  }

 private:
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