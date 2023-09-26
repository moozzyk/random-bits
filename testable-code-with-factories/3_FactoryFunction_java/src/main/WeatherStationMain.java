public class WeatherStationMain {
    private static void printWeather(WeatherReport weatherReport) {
        System.out.println("Temperature: " + weatherReport.temperature + "°C");
    }

    public static void main(String[] args) {
        printWeather(new WeatherStation(TemperatureSensorModel.SENSOR_A).getWeatherReport());
        printWeather(new WeatherStation(TemperatureSensorModel.SENSOR_B).getWeatherReport());
        printWeather(new WeatherStation(TemperatureSensorModel.SENSOR_C).getWeatherReport());
    }
}