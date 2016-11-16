// ============================================================ 
//                                                              
// Example: LCDML_003_glcd_u8glib                         
//                                                            
// ============================================================ 
// todo
// ============================================================ 

  // include libs
  #include <LCDMenuLib.h>
  #include <U8glib.h>

  
  #define CLK 5       // DISPLAY NOKIA5115
  #define DIN 6       // DISPLAY NOKIA5115
  #define CE 8        // DISPLAY NOKIA5115
  #define DC 7        // DISPLAY NOKIA5115
  #define RST 9       // DISPLAY NOKIA5115
  #define backlight 3 // DISPLAY NOKIA5115

  #include <EEPROM.h> //EEPROM
  #include <DS3231.h>
  DS3231  rtc(SDA, SCL); // SDA=A4  - SCL=A5
  Time  t;
  char  buffer[20];
  
  // lib config
  #define _LCDML_DISP_cfg_button_press_time          300    // button press time in ms

// *********************************************************************
// U8GLIB
// *********************************************************************
  // setup u8g object, please remove comment from one of the following constructor calls
  // IMPORTANT NOTE: The following list is incomplete. The complete list of supported 
  // devices with all constructor calls is here: https://github.com/olikraus/u8glib/wiki/device
U8GLIB_PCD8544 u8g(CLK, DIN, CE, DC, RST); 
  
  // settings for u8g lib and lcd
  #define _LCDML_u8g_lcd_w       84            // lcd width
  #define _LCDML_u8g_lcd_h       48             // lcd height
  #define _LCDML_u8g_font        u8g_font_helvB08r  // u8glib font (more fonts under u8g.h line 1520 ...)
  #define _LCDML_u8g_font_w      6             // u8glib font width
  #define _LCDML_u8g_font_h      9             // u8glib font heigt

  // nothing change here
  #define _LCDML_u8g_cols_max    (_LCDML_u8g_lcd_w/_LCDML_u8g_font_w)  
  #define _LCDML_u8g_rows_max    (_LCDML_u8g_lcd_h/_LCDML_u8g_font_h) 

  // rows and cols 
  // when you use more rows or cols as allowed change in LCDMenuLib.h the define "_LCDML_DISP_cfg_max_rows" and "_LCDML_DISP_cfg_max_string_length"
  // the program needs more ram with this changes
  #define _LCDML_u8g_rows        _LCDML_u8g_rows_max  // max rows 
  #define _LCDML_u8g_cols        12                   // max cols

  // scrollbar width
  #define _LCDML_u8g_scrollbar_w 6  // scrollbar width  


  // old defines with new content
  #define _LCDML_DISP_cols      _LCDML_u8g_cols
  #define _LCDML_DISP_rows      _LCDML_u8g_rows  


// *********************************************************************
// MYKIDPET VARIABLES
// *********************************************************************
byte qpets = 5;
byte thisPet = 1;

// *********************************************************************
// MYKIDPET AJUSTES
// *********************************************************************
byte brilho = 80;
byte contraste = 80;
int sleep = 10000;
unsigned long sleep_timer_counter = millis();


// *********************************************************************
// LCDML MENU/DISP
// *********************************************************************
  // create menu
  // menu element count - last element id
  // this value must be the same as the last menu element
  #define _LCDML_DISP_cnt    38
  
  // LCDML_root        => layer 0 
  // LCDML_root_X      => layer 1 
  // LCDML_root_X_X    => layer 2 
  // LCDML_root_X_X_X  => layer 3 
  // LCDML_root_... 	 => layer ... 
  
  // LCDMenuLib_add(id, group, prev_layer_element, new_element_num, lang_char_array, callback_function)
  LCDML_DISP_initParam(_LCDML_DISP_cnt); // enable parameters (needs one byte per menu element)

  LCDML_DISP_add      (0  , _LCDML_G1  , LCDML_root        , 1  , "MyKidPet"        , LCDML_FUNC);
 

  LCDML_DISP_add      (1  , _LCDML_G1  , LCDML_root_1      , 1  , "Adiciona"        , LCDML_FUNC_adiciona);
  LCDML_DISP_add      (2  , _LCDML_G1  , LCDML_root_1      , 2  , "Apaga"           , LCDML_FUNC_apagainverte);
  LCDML_DISP_add      (3  , _LCDML_G1  , LCDML_root_1      , 3  , "Inverte"         , LCDML_FUNC_apagainverte);
  
  LCDML_DISP_add      (4  , _LCDML_G1  , LCDML_root        , 2  , "Pets"            , LCDML_FUNC);
  LCDML_DISP_add      (5  , _LCDML_G1  , LCDML_root_2      , 1  , "Info"            , LCDML_FUNC);
  LCDML_DISP_add      (6  , _LCDML_G1  , LCDML_root_2_1    , 1  , "Ultima vez"      , LCDML_FUNC_ultvez);
  LCDML_DISP_add      (7  , _LCDML_G1  , LCDML_root_2_1    , 2  , "Ultima hora"     , LCDML_FUNC_ulthor);  
  LCDML_DISP_add      (8  , _LCDML_G1  , LCDML_root_2_1    , 3  , "Ultima sem."     , LCDML_FUNC_ultsem);  
  LCDML_DISP_add      (9  , _LCDML_G1  , LCDML_root_2_1    , 4  , "Ultimo mes"      , LCDML_FUNC_ultmes);
   
  LCDML_DISP_addParam (10 , _LCDML_G1  , LCDML_root_2      , 2  ,       ""          , LCDML_FUNC_jump,  1); 
  LCDML_DISP_addParam (11 , _LCDML_G2  , LCDML_root_2      , 3  ,       ""          , LCDML_FUNC_jump,  2);
  LCDML_DISP_addParam (12 , _LCDML_G3  , LCDML_root_2      , 4  ,       ""          , LCDML_FUNC_jump,  3);  
  LCDML_DISP_addParam (13 , _LCDML_G4  , LCDML_root_2      , 5  ,       ""          , LCDML_FUNC_jump,  4);
  LCDML_DISP_addParam (14 , _LCDML_G5  , LCDML_root_2      , 6  ,       ""          , LCDML_FUNC_jump,  5);  

  LCDML_DISP_add      (15 , _LCDML_G1  , LCDML_root        , 3  , "Dono"            , LCDML_FUNC);
  LCDML_DISP_addParam (16 , _LCDML_G1  , LCDML_root_3      , 1  , "Celular"         , LCDML_FUNC_nome,  2);
  LCDML_DISP_addParam (17 , _LCDML_G1  , LCDML_root_3      , 2  , "Email"           , LCDML_FUNC_nome,  3);
  
  LCDML_DISP_add      (18 , _LCDML_G1  , LCDML_root        , 4  , "Opcoes"          , LCDML_FUNC);
  LCDML_DISP_add      (19 , _LCDML_G1  , LCDML_root_4      , 1  , "Modo"            , LCDML_FUNC);
  LCDML_DISP_addParam (20 , _LCDML_G1  , LCDML_root_4_1    , 1  , "Por Volume"      , LCDML_FUNC_jump,7);
  LCDML_DISP_addParam (21 , _LCDML_G1  , LCDML_root_4_1    , 2  , "Por Horario"     , LCDML_FUNC_jump,8);  
  LCDML_DISP_add      (22 , _LCDML_G1  , LCDML_root_4      , 2  , "Rede"            , LCDML_FUNC);
  LCDML_DISP_add      (23 , _LCDML_G1  , LCDML_root_4_2    , 1  , "Escolha rede"    , LCDML_FUNC_redes);
  LCDML_DISP_addParam (24 , _LCDML_G1  , LCDML_root_4_2    , 2  , "Defina senha"    , LCDML_FUNC_nome, 4); 
  LCDML_DISP_add      (25 , _LCDML_G1  , LCDML_root_4      , 3  , "Data"            , LCDML_FUNC_hora  );
  LCDML_DISP_add      (26 , _LCDML_G1  , LCDML_root_4      , 4  , "Hora"            , LCDML_FUNC_hora  );
      
  LCDML_DISP_add      (27 , _LCDML_G1  , LCDML_root        , 5  , "Ajustes"         , LCDML_FUNC);
  LCDML_DISP_addParam (28 , _LCDML_G1  , LCDML_root_5      , 1  , "Brilho"          , LCDML_FUNC_ajustes,1);
  LCDML_DISP_addParam (29 , _LCDML_G1  , LCDML_root_5      , 2  , "Constraste"      , LCDML_FUNC_ajustes,2);
  LCDML_DISP_addParam (30 , _LCDML_G1  , LCDML_root_5      , 3  , "Tela acesa"      , LCDML_FUNC_ajustes,3);

  LCDML_DISP_addParam (31 , _LCDML_G1  , LCDML_root_2_2     , 1  , "Muda Nome"      , LCDML_FUNC_nome,1);
  LCDML_DISP_add      (32 , _LCDML_G1  , LCDML_root_2_2     , 2  , "Tag"            , LCDML_FUNC);
  LCDML_DISP_addParam (33 , _LCDML_G1  , LCDML_root_2_2     , 3  , "Info"           , LCDML_FUNC_jump,  6);
  
  LCDML_DISP_addParam (34 , _LCDML_G1  , LCDML_root_2_2_2   , 1  , "Vermelho"       , LCDML_FUNC_tag,1);  
  LCDML_DISP_addParam (35 , _LCDML_G1  , LCDML_root_2_2_2   , 2  , "Azul"           , LCDML_FUNC_tag,2);  
  LCDML_DISP_addParam (36 , _LCDML_G1  , LCDML_root_2_2_2   , 3  , "Verde"          , LCDML_FUNC_tag,3);  
  LCDML_DISP_addParam (37 , _LCDML_G1  , LCDML_root_2_2_2   , 4  , "Branco"         , LCDML_FUNC_tag,4);  
  LCDML_DISP_addParam (38 , _LCDML_G1  , LCDML_root_2_2_2   , 5  , "Preto"          , LCDML_FUNC_tag,5);
 
  LCDML_DISP_createMenu(_LCDML_DISP_cnt);



// ********************************************************************* 
// LCDML BACKEND (core of the menu, do not change here anything yet)
// ********************************************************************* 
  // define backend function  
  #define _LCDML_BACK_cnt    1  // last backend function id
  
  LCDML_BACK_init(_LCDML_BACK_cnt);
  LCDML_BACK_new_timebased_dynamic (0  , ( 20UL )         , _LCDML_start  , LCDML_BACKEND_control);
  LCDML_BACK_new_timebased_dynamic (1  , ( 10000000UL )   , _LCDML_stop   , LCDML_BACKEND_menu);
  LCDML_BACK_create();



// *********************************************************************
// SETUP
// *********************************************************************
  void setup()
  {  
    pinMode(backlight,OUTPUT);
    analogWrite(backlight, 80);
    rtc.begin();
    // serial init; only be needed if serial control is used 
    while(!Serial);                    // wait until serial ready
    Serial.begin(9600);                // start serial    
    Serial.println(F(_LCDML_VERSION)); // only for examples
      
    // Enable all items with _LCDML_G1
                LCDML_DISP_groupEnable(_LCDML_G1); // enable group 1    
                LCDML_DISP_groupEnable(_LCDML_G2); // enable group 2 
                LCDML_DISP_groupEnable(_LCDML_G3); // enable group 3
                LCDML_DISP_groupEnable(_LCDML_G4); // enable group 4
                LCDML_DISP_groupEnable(_LCDML_G5); // enable group 5
                LCDML_DISP_groupDisable(_LCDML_G6); // unable group 6
       
    // LCDMenu Setup
    LCDML_setup(_LCDML_BACK_cnt);  
  }

// *********************************************************************
// LOOP
// *********************************************************************
  void loop()
  { 
    // this function must called here, do not delete it
    LCDML_run(_LCDML_priority);

    if(millis()-sleep_timer_counter>sleep){
      u8g.sleepOff();
      analogWrite(backlight, 0);
    }  
  }




// *********************************************************************
// check some errors - do not change here anything
// *********************************************************************
# if(_LCDML_DISP_rows > _LCDML_DISP_cfg_max_rows)
# error change value of _LCDML_DISP_cfg_max_rows in LCDMenuLib.h
# endif
# if(_LCDML_DISP_cols > _LCDML_DISP_cfg_max_string_length)
# error change value of _LCDML_DISP_cfg_max_string_length in LCDMenuLib.h
# endif
