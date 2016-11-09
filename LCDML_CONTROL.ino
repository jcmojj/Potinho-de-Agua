// =====================================================================
//
// CONTROL
//
// =====================================================================
// *********************************************************************
// *********************************************************************


// *********************************************************************
// CONTROL TASK, DO NOT CHANGE
// *********************************************************************
void LCDML_BACK_setup(LCDML_BACKEND_control)      
// *********************************************************************
{
  // call setup   
  LCDML_CONTROL_setup();      
}
// backend loop
boolean LCDML_BACK_loop(LCDML_BACKEND_control)
{    
  // call loop
  LCDML_CONTROL_loop();

  // go to next backend function and do not block it
  return true;  
}
// backend stop stable
void LCDML_BACK_stable(LCDML_BACKEND_control)
{
}






// *********************************************************************
// *************** (1) CONTROL OVER ONE ANALOG PIN *********************
// *********************************************************************

// settings
// Embutido modo serial
  # define _LCDML_CONTROL_serial_enter           'e'
  # define _LCDML_CONTROL_serial_up              'w'
  # define _LCDML_CONTROL_serial_down            's'
  # define _LCDML_CONTROL_serial_left            'a'
  # define _LCDML_CONTROL_serial_right           'd'
  # define _LCDML_CONTROL_serial_quit            'q'

// Modo Joystick
  #define _LCDML_CONTROL_analog_pin_VRX           A2
  #define _LCDML_CONTROL_analog_pin_VRY           A3
  #define _LCDML_CONTROL_digital_pin_SW           A7
  // when you did not use a button set the value to zero
  #define _LCDML_CONTROL_analog_enter_min        false     // Button Enter
  #define _LCDML_CONTROL_analog_enter_max        true  
  #define _LCDML_CONTROL_analog_up_min           0     // Button Up
  #define _LCDML_CONTROL_analog_up_max           200   
  #define _LCDML_CONTROL_analog_down_min         900     // Button Down
  #define _LCDML_CONTROL_analog_down_max         1030   
  #define _LCDML_CONTROL_analog_back_min         0     // Button Back
  #define _LCDML_CONTROL_analog_back_max         0   
  #define _LCDML_CONTROL_analog_left_min         0     // Button Left
  #define _LCDML_CONTROL_analog_left_max         200   
  #define _LCDML_CONTROL_analog_right_min        900     // Button Right
  #define _LCDML_CONTROL_analog_right_max        1030
  #define _LCDML_CONTROL_analog_counter_max      5      // vezes antes de entrar ou sair
  byte _LCDML_CONTROL_analog_counter_enter = 0;         // contador
  byte _LCDML_CONTROL_analog_counter_quit = 0;          // contador
  
// *********************************************************************
// setup
void LCDML_CONTROL_setup()
{
  pinMode(_LCDML_CONTROL_analog_pin_VRX,INPUT);
  pinMode(_LCDML_CONTROL_analog_pin_VRY,INPUT);
  pinMode(_LCDML_CONTROL_digital_pin_SW,INPUT);
}
// *********************************************************************
// loop
void LCDML_CONTROL_loop()
{
  //Modo Serial
  if (Serial.available()) {
    // read one char from input buffer   
    switch (Serial.read())
    {
      case _LCDML_CONTROL_serial_enter:  LCDML_BUTTON_enter(); break;
      case _LCDML_CONTROL_serial_up:     LCDML_BUTTON_up();    break;
      case _LCDML_CONTROL_serial_down:   LCDML_BUTTON_down();  break;
      case _LCDML_CONTROL_serial_left:   LCDML_BUTTON_left();  break;
      case _LCDML_CONTROL_serial_right:  LCDML_BUTTON_right(); break;
      case _LCDML_CONTROL_serial_quit:   LCDML_BUTTON_quit();  break;
      default: break;
    } 
  }
  // Modo Joystick
  // check debounce timer  
  if((millis() - g_LCDML_DISP_press_time) >= _LCDML_DISP_cfg_button_press_time) {
    g_LCDML_DISP_press_time = millis(); // reset debounce timer
    
    uint16_t valueX = analogRead(_LCDML_CONTROL_analog_pin_VRX);  // analogpin for keypad
    uint16_t valueY = analogRead(_LCDML_CONTROL_analog_pin_VRY);  // analogpin for keypad
    boolean valueZ = analogRead(_LCDML_CONTROL_digital_pin_SW);  // digitalpin for keypad

    if(_LCDML_CONTROL_analog_counter_enter == _LCDML_CONTROL_analog_counter_max){LCDML_BUTTON_enter(); _LCDML_CONTROL_analog_counter_enter = 0;}
    if(_LCDML_CONTROL_analog_counter_quit == _LCDML_CONTROL_analog_counter_max){LCDML_BUTTON_quit(); _LCDML_CONTROL_analog_counter_quit = 0;}
        
    if (valueZ != _LCDML_CONTROL_analog_enter_max) { LCDML_BUTTON_enter(); _LCDML_CONTROL_analog_counter_enter=0; _LCDML_CONTROL_analog_counter_quit=0; sleep_timer_counter=millis();u8g.sleepOn(); analogWrite(backlight, brilho);}// Serial.print("Value Z:"); Serial.println(valueZ);}
    if (valueY >= _LCDML_CONTROL_analog_up_min    && valueY <= _LCDML_CONTROL_analog_up_max)    { LCDML_BUTTON_up(); _LCDML_CONTROL_analog_counter_enter=0; _LCDML_CONTROL_analog_counter_quit=0; sleep_timer_counter=millis();u8g.sleepOn();}// analogWrite(backlight, brilho);   Serial.print("Value Y:"); Serial.println(valueY);}
    if (valueY >= _LCDML_CONTROL_analog_down_min  && valueY <= _LCDML_CONTROL_analog_down_max)  { LCDML_BUTTON_down(); _LCDML_CONTROL_analog_counter_enter=0; _LCDML_CONTROL_analog_counter_quit=0; sleep_timer_counter=millis();u8g.sleepOn();}// analogWrite(backlight, brilho); Serial.print("Value Y:"); Serial.println(valueY);}
    if (valueX >= _LCDML_CONTROL_analog_left_min  && valueX <= _LCDML_CONTROL_analog_left_max)  { LCDML_BUTTON_left();  _LCDML_CONTROL_analog_counter_enter=0; _LCDML_CONTROL_analog_counter_quit++; sleep_timer_counter=millis();u8g.sleepOn();}// analogWrite(backlight, brilho); Serial.print("Value X:"); Serial.println(valueX);}
    if (valueX >= _LCDML_CONTROL_analog_right_min && valueX <= _LCDML_CONTROL_analog_right_max) { LCDML_BUTTON_right();  _LCDML_CONTROL_analog_counter_enter++; _LCDML_CONTROL_analog_counter_quit=0; sleep_timer_counter=millis();u8g.sleepOn();}// analogWrite(backlight, brilho); Serial.print("Value X:"); Serial.println(valueX);}
  }
}
// *********************************************************************
// ******************************* END *********************************
// *********************************************************************







