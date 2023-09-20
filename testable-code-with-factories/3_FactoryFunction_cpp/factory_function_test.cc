#include "factory_function.h"

#include <gtest/gtest.h>

TEST(FactoryFunctionTest, CustomFactory) {
  auto ws = WeatherStation{TemperatureSensorModel::SensorA};
  ASSERT_TRUE(dynamic_cast<TemperatureSensorA*>(
      WeatherStation::createSensor(TemperatureSensorModel::SensorA).get()));
}