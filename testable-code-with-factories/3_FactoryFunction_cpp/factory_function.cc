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

class WeatherStation {
 public:
  WeatherStation(
      TemperatureSensorModel tempSensorModel,
      std::function<std::unique_ptr<TemperatureSensor>(TemperatureSensorModel)>
          sensorFactory = createSensor)
      : tempSensor_{sensorFactory(tempSensorModel)} {}

  void printWeather() {
    std::cout << "Temperature: " << tempSensor_->getTemperature() << "°C"
              << std::endl;
  }

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

int main() {
  WeatherStation{TemperatureSensorModel::SensorA}.printWeather();
  WeatherStation{TemperatureSensorModel::SensorB}.printWeather();
  WeatherStation{TemperatureSensorModel::SensorC}.printWeather();
  return 0;
}
