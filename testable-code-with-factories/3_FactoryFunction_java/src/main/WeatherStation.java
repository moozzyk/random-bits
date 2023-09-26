import java.util.function.Function;

import javax.management.RuntimeErrorException;

public class WeatherStation {
    private ITemperatureSensor temperatureSensor;

    public WeatherStation(TemperatureSensorModel temperatureSensorModel) {
        this(temperatureSensorModel, WeatherStation::createSensor);
    }

    public WeatherStation(TemperatureSensorModel temperatureSensorModel,
            Function<TemperatureSensorModel, ITemperatureSensor> factory) {
        this(factory.apply(temperatureSensorModel));
    }

    public WeatherStation(ITemperatureSensor temperatureSensor) {
        this.temperatureSensor = temperatureSensor;
    }

    public WeatherReport getWeatherReport() {
        return new WeatherReport(temperatureSensor.getTemperature());
    }

    public static ITemperatureSensor createSensor(TemperatureSensorModel temperatureSensorModel) {
        switch (temperatureSensorModel) {
            case SENSOR_A:
                return new TemperatureSensorA();
            case SENSOR_B:
                return new TemperatureSensorB();
            case SENSOR_C:
                return new TemperatureSensorC();
            default:
                throw new RuntimeException("Unsupported temperature sensor model");
        }
    }
}