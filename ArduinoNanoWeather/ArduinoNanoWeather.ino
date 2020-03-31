//www.elegoo.com
//2018.10.25


#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

static const int DHT_SENSOR_PIN = 8;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );



/*
 * Initialize the serial port.
 */
void setup( )
{
  lcd.begin(16, 2);
}



/*
 * Poll for a measurement, keeping the state machine alive.  Returns
 * true if a measurement is available.
 */
static bool measure_environment( float *temperature, float *humidity )
{
  static unsigned long measurement_timestamp = millis( );

  /* Measure once every four seconds. */
  if( millis( ) - measurement_timestamp > 3000ul )
  {
    if( dht_sensor.measure( temperature, humidity ) == true )
    {
      measurement_timestamp = millis( );
      return( true );
    }
  }

  return( false );
}



/*
 * Main program loop.
 */
void loop( )
{
  float temperature;
  float humidity;

  /* Measure temperature and humidity.  If the functions returns
     true, then a measurement is available. */
  if( measure_environment( &temperature, &humidity ) == true )
  {
//    Serial.print( "T = " );
//    Serial.print( temperature, 1 );
//    Serial.print( " deg. C, H = " );
//    Serial.print( humidity, 1 );
//    Serial.println( "%" );
      int fahrenheit = (temperature * 1.8) + 32; 
      
      lcd.setCursor(0, 0);
      lcd.print(fahrenheit, 1);
      lcd.setCursor(0, 1);
      lcd.print(humidity, 1);
  }
}
