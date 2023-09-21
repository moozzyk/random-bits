#include "factory_function.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace ::testing;

class MockTemperatureSensor : public TemperatureSensor {
 public:
  MOCK_METHOD(float, getTemperature, ());
};

TEST(FactoryFunctionTest, CustomFactory) {
  auto tempSensor = std::make_unique<MockTemperatureSensor>();
  EXPECT_CALL(*tempSensor, getTemperature())
      .Times(Exactly(1))
      .WillOnce(Return(15));

  auto ws = WeatherStation{TemperatureSensorModel::SensorA,
                           [&](auto) { return std::move(tempSensor); }};
  ws.printWeather();
}

TEST(FactoryFunctionTest, FactoryTest) {
  auto ws = WeatherStation{TemperatureSensorModel::SensorA};
  ASSERT_TRUE(dynamic_cast<TemperatureSensorA*>(
      WeatherStation::createSensor(TemperatureSensorModel::SensorA).get()));
}
