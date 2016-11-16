/* ===================================================================== *
 *                                                                       *
 * DISPLAY SYSTEM                                                        *
 *                                                                       *
 * ===================================================================== *
 * every "disp menu function" needs three functions 
 * - void LCDML_DISP_setup(func_name)    
 * - void LCDML_DISP_loop(func_name)     
 * - void LCDML_DISP_loop_end(func_name)
 *
 * EXAMPLE CODE:
    void LCDML_DISP_setup(..menu_func_name..) 
    {
      // setup
      // is called only if it is started

      // starts a trigger event for the loop function every 100 millisecounds
      LCDML_DISP_triggerMenu(100);  
    }
    
    void LCDML_DISP_loop(..menu_func_name..)
    { 
      // loop
      // is called when it is triggert
      // - with LCDML_DISP_triggerMenu( millisecounds ) 
      // - with every button status change

      // check if any button is presed (enter, up, down, left, right)
      if(LCDML_BUTTON_checkAny()) {         
        LCDML_DISP_funcend();
      } 
    }
    
    void LCDML_DISP_loop_end(..menu_func_name..)
    {
      // loop end
      // this functions is ever called when a DISP function is quit
      // you can here reset some global vars or do nothing  
    } 
 * ===================================================================== * 
 */

// this needs some bytes in ram
#define MAX_FILES_IN_LIST 20

// scroll row position
uint8_t scroll_row;
// cursor real position on lcd lines (0 - _LCDML_DISP_rows - 1)
uint8_t cursor_real_pos;
// max filelist count
uint8_t current_max_list_count;
// cursor position to file list entry
uint8_t cursor_position_cur;
// parameters from main menu
uint8_t param;
// time for counting
//unsigned long t;















// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_jump)
// *********************************************************************
{
  uint8_t param = LCDML_DISP_getParameter();
Serial.print("Parameter: "); Serial.println(param);
Serial.print("a");
if(param==31){LCDML.jumpToElement(6);}else{LCDML.jumpToElement(29);}


}

void LCDML_DISP_loop(LCDML_FUNC_jump)
{Serial.print("t");
  
}

void LCDML_DISP_loop_end(LCDML_FUNC_jump)
{
}



// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_nome)
// *********************************************************************
{

}

void LCDML_DISP_loop(LCDML_FUNC_nome)
{ 
  
      
      
      // check if any button is presed (enter, up, down, left, right)
  if(LCDML_BUTTON_checkAny()) {         
    LCDML_DISP_funcend();
  } 
}

void LCDML_DISP_loop_end(LCDML_FUNC_nome)
{

}



// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_raca)
// *********************************************************************
{

}

void LCDML_DISP_loop(LCDML_FUNC_raca)
{ 
      // check if any button is presed (enter, up, down, left, right)
  if(LCDML_BUTTON_checkAny()) {         
    LCDML_DISP_funcend();
  } 
}

void LCDML_DISP_loop_end(LCDML_FUNC_raca)
{

}



// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_niver)
// *********************************************************************
{

}

void LCDML_DISP_loop(LCDML_FUNC_niver)
{ 
      // check if any button is presed (enter, up, down, left, right)
  if(LCDML_BUTTON_checkAny()) {         
    LCDML_DISP_funcend();
  } 
}

void LCDML_DISP_loop_end(LCDML_FUNC_niver)
{

}








// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_tag)
// *********************************************************************
{
   // cursor_position_cur = 1;
}




void LCDML_DISP_loop(LCDML_FUNC_tag)
{ /*
// control
// =====================================
  
if(LCDML_BUTTON_checkUp()){
  LCDML_BUTTON_resetAll();
  if(cursor_position_cur<6){cursor_position_cur--;}
  LCDML_BACK_start(LCDML_BACKEND_menu); 
}

if(LCDML_BUTTON_checkDown()){
  LCDML_BUTTON_resetAll();
  if(cursor_position_cur>0){cursor_position_cur++;}
  LCDML_BACK_start(LCDML_BACKEND_menu); 
}

if(LCDML_BUTTON_checkEnter()||LCDML_BUTTON_checkLeft()) {
  LCDML_BUTTON_resetAll();   
  LCDML_DISP_funcend();
}

     
// display content
// ==================   
   u8g.firstPage();
   do{  
      u8g.setFont( u8g_font_helvB08);
      for ( int pos = 1; pos<6;pos++){ 
      u8g.drawStr( 0 ,  cursor_position_cur*8, F("X"));
      char buffer[9];
      switch(pos){
        case 1:  strncpy(buffer, "Vermelho", 8); break;
        case 2:  strncpy(buffer, "Azul", 8); break;
        case 3:  strncpy(buffer, "Verde", 8); break;
        case 4:  strncpy(buffer, "Branco", 8); break;
        case 5:  strncpy(buffer, "Preto", 8); break;
       // case 2: buffer = "Azul"; break;
       // case 3: buffer = "Verde"; break;
       // case 4: buffer = "Branco"; break;
       // case 5: buffer = "Preto"; break;
              
        }
      u8g.drawStr( 8 ,  9*pos, buffer);
      }
     
   }while ( u8g.nextPage() ); 
*/  //uint8_t param = LCDML_DISP_getParameter();  LCDML_DISP_funcend();
}

void LCDML_DISP_loop_end(LCDML_FUNC_tag)
{

}









// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_ultvez)
// *********************************************************************
{

}

void LCDML_DISP_loop(LCDML_FUNC_ultvez)
{ 
      // check if any button is presed (enter, up, down, left, right)
  if(LCDML_BUTTON_checkAny()) {         
    LCDML_DISP_funcend();
  } 
}

void LCDML_DISP_loop_end(LCDML_FUNC_ultvez)
{

}



// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_ulthor)
// *********************************************************************
{
  
}

void LCDML_DISP_loop(LCDML_FUNC_ulthor)
{ 
      // check if any button is presed (enter, up, down, left, right)
  if(LCDML_BUTTON_checkAny()) {         
    LCDML_DISP_funcend();
  } 
}

void LCDML_DISP_loop_end(LCDML_FUNC_ulthor)
{

}



// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_ultsem)
// *********************************************************************
{
 
}

void LCDML_DISP_loop(LCDML_FUNC_ultsem)
{ 
      // check if any button is presed (enter, up, down, left, right)
  if(LCDML_BUTTON_checkAny()) {         
    LCDML_DISP_funcend();
  } 
}

void LCDML_DISP_loop_end(LCDML_FUNC_ultsem)
{

}



// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_ultmes)
// *********************************************************************
{

}

void LCDML_DISP_loop(LCDML_FUNC_ultmes)
{ 
      // check if any button is presed (enter, up, down, left, right)
  if(LCDML_BUTTON_checkAny()) {         
    LCDML_DISP_funcend();
  } 
}

void LCDML_DISP_loop_end(LCDML_FUNC_ultmes)
{

}



// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_adiciona)
// *********************************************************************
{

}

void LCDML_DISP_loop(LCDML_FUNC_adiciona)
{ 
      // check if any button is presed (enter, up, down, left, right)
  if(LCDML_BUTTON_checkAny()) {         
    LCDML_DISP_funcend();
  } 
}

void LCDML_DISP_loop_end(LCDML_FUNC_adiciona)
{
}



// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_apagainverte)
// *********************************************************************
{

}

void LCDML_DISP_loop(LCDML_FUNC_apagainverte)
{ 
   // LCDML.jumpToElement(18);        
    LCDML_DISP_funcend();

}

void LCDML_DISP_loop_end(LCDML_FUNC_apagainverte)
{
}




// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_pets)
// *********************************************************************
{

}

void LCDML_DISP_loop(LCDML_FUNC_pets)
{ 
 //   LCDML.jumpToElement(18);        
    LCDML_DISP_funcend();

}

void LCDML_DISP_loop_end(LCDML_FUNC_pets)
{
}



// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_volume)
// *********************************************************************
{

}

void LCDML_DISP_loop(LCDML_FUNC_volume)
{ 
      // check if any button is presed (enter, up, down, left, right)
  if(LCDML_BUTTON_checkAny()) {         
    LCDML_DISP_funcend();
  } 
}

void LCDML_DISP_loop_end(LCDML_FUNC_volume)
{
}






// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_redes)
// *********************************************************************
{
  uint8_t param = LCDML_DISP_getParameter(); 
}

void LCDML_DISP_loop(LCDML_FUNC_redes)
{ 
      // check if any button is presed (enter, up, down, left, right)
  if(LCDML_BUTTON_checkAny()) {         
    LCDML_DISP_funcend();
  } 
}

void LCDML_DISP_loop_end(LCDML_FUNC_redes)
{
}




// *********************************************************************



// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_back_tela)
// *********************************************************************
{
  uint8_t param = LCDML_DISP_getParameter(); 
}

void LCDML_DISP_loop(LCDML_FUNC_back_tela)
{ 
      // check if any button is presed (enter, up, down, left, right)
  if(LCDML_BUTTON_checkAny()) {         
    LCDML_DISP_funcend();
  } 
}

void LCDML_DISP_loop_end(LCDML_FUNC_back_tela)
{
}



// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_hora)
// *********************************************************************
{
  cursor_position_cur = 0;
}
void LCDML_DISP_loop(LCDML_FUNC_hora)
{ 
  // Data:25 --> hora=1
  // Hora:26 --> hora=0

// control
// =====================================
boolean ehData = LCDML.getFunction()%2;
t=rtc.getTime();
byte data[3]={t.hour*(1-ehData)+t.mon*ehData,t.min*(1-ehData)+t.date*ehData,t.sec*(1-ehData)+t.year*ehData};

if(LCDML_BUTTON_checkUp()){LCDML_BUTTON_resetAll();data[cursor_position_cur]++;}
if(LCDML_BUTTON_checkDown()){LCDML_BUTTON_resetAll();data[cursor_position_cur]--;}
if(LCDML_BUTTON_checkRight()){LCDML_BUTTON_resetAll();if(cursor_position_cur<2){cursor_position_cur++;}else{LCDML_DISP_funcend();}}
if(LCDML_BUTTON_checkLeft()){LCDML_BUTTON_resetAll();if(cursor_position_cur>0){cursor_position_cur--;}else{LCDML_DISP_funcend();}}
  
/*if(ehData){rtc.setDate(data[0],data[1],data[2]);}else{rtc.setTime(data[0],data[1],data[2]);}
t=rtc.getTime();
data[0]=t.hour*(1-ehData)+t.mon*ehData;
data[1]=t.min*(1-ehData)+t.date*ehData;
data[2]=t.sec*(1-ehData)+t.year*ehData;*/



  //buffer[0]=(data[0]>>8)&&0xff;
 // buffer[1]=data[0]&&0xff;
//  buffer[2]=(ehData?"/":":");
 // strcpy(buffer, (byte)data[0]);
 // strcat(buffer,ehData?"/":":");
 // strcat(buffer,data[1]);
  //strcat(buffer,ehData?"/":":");
  //strcat(buffer,data[2]);
  //strcat(buffer,'\n');

//Serial.print("buffer");
//for(int i=0;i<12;i++){Serial.print(buffer[i]);}Serial.println(")");
  
Serial.print(cursor_position_cur);Serial.print(")");
for(int i=0;i<3;i++){Serial.print(data[i]);Serial.print("-");}
Serial.println("");

  // display content
  // ==================   
   u8g.firstPage();
   do{  
      u8g.setFont( u8g_font_helvB08);
      for(byte i=0;i<3;i++){
        u8g.setPrintPos(i*3*6,9+i*9);
        u8g.print(data[i]);
        u8g.setPrintPos((i*3-1)*6,9+i*9);
        u8g.print(F(":"));  
      }            
   }while ( u8g.nextPage() ); 

// ========================================================================================================================================================================================================================================================================================
}
void LCDML_DISP_loop_end(LCDML_FUNC_hora)
{
  
}





// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_ajustes)
// *********************************************************************
{
  param = LCDML_DISP_getParameter();
 // Serial.print("Parameter: "); Serial.println(param);
 // t = 0;
  cursor_position_cur = 0;
}

void LCDML_DISP_loop(LCDML_FUNC_ajustes)
{

// control
// =====================================
  


if(LCDML_BUTTON_checkUp()){
  LCDML_BUTTON_resetAll();
  cursor_position_cur = 1;
  switch(param){
     case 1: brilho=brilho+5; break;
     case 2: contraste=contraste+5; break;
     case 3: sleep=sleep+500; break;            
  }
  LCDML_BACK_start(LCDML_BACKEND_menu); 
}

if(LCDML_BUTTON_checkDown()){
  LCDML_BUTTON_resetAll();
  cursor_position_cur = 2;
  switch(param){
     case 1: brilho=brilho-5; break;
     case 2: contraste=contraste-5; break;
     case 3: sleep=sleep-500; break;         
  }
  LCDML_BACK_start(LCDML_BACKEND_menu); 
}

if(LCDML_BUTTON_checkEnter()||LCDML_BUTTON_checkLeft()) {
  LCDML_BUTTON_resetAll();   
  LCDML_DISP_funcend();
}

  // atualização de valores
  // =====================================

analogWrite(backlight, brilho);
u8g.setContrast(contraste);


  // display value---------------------------------------------------------------------------------------->usar um buffer
  // ==================
     String temp;
     switch(param){
     case 1: temp = (float)brilho*100/255; temp+="%"; break;
     case 2: temp = contraste; break;
     case 3: temp = (float)sleep/1000; temp+="s"; break; 
     }
     
  // display content
  // ==================   
   u8g.firstPage();
   do{  
      u8g.setFont( u8g_font_helvB08);
      
      u8g.drawStr( 28,10, F("MAIS"));
      u8g.drawStr( 23,46, F("MENOS"));
     // u8g.drawFrame(20,0,44,_LCDML_u8g_lcd_h); //vertical
      u8g.drawFrame(20,0,44,12); //superior
      u8g.drawFrame(20,_LCDML_u8g_lcd_h-12,44,12); //inferior
      u8g.drawBox(38,12,8,24); // linha vertical

     u8g.setPrintPos(0,29);
     u8g.print(temp);          
     
   }while ( u8g.nextPage() ); 
}

void LCDML_DISP_loop_end(LCDML_FUNC_ajustes)
{
}



/*

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_information)
// *********************************************************************
{
  // setup function
  u8g.setFont(u8g_font_6x13);
  u8g.firstPage();  
  do {
    u8g.drawStr( 0, 13, F("To close this"));
    u8g.drawStr( 0, 26, F("function press"));
    u8g.drawStr( 0, 39, F("any button or use"));
    u8g.drawStr( 0, 52, F("back button"));
  } while( u8g.nextPage() );
}

void LCDML_DISP_loop(LCDML_FUNC_information) 
{
  // loop function, can be run in a loop when LCDML_DISP_triggerMenu(xx) is set
  // the quit button works in every DISP function without any checks; it starts the loop_end function   
  if(LCDML_BUTTON_checkAny()) { // check if any button is presed (enter, up, down, left, right)
    // LCDML_DISP_funcend calls the loop_end function
    LCDML_DISP_funcend();
  } 
}

void LCDML_DISP_loop_end(LCDML_FUNC_information)
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing    
}  


// *********************************************************************
uint8_t g_func_timer_info = 0;  // time counter (global variable)
unsigned long g_timer_1 = 0;    // timer variable (globale variable)
void LCDML_DISP_setup(LCDML_FUNC_timer_info)
// *********************************************************************
{
  // setup function
  char buf[20];
  sprintf (buf, "wait %d secounds", 10);
  
  u8g.setFont(u8g_font_6x13);
  u8g.firstPage();  
  do {
    u8g.drawStr( 0, 13, buf);
    u8g.drawStr( 0, 26, F("or press back button"));
  } while( u8g.nextPage() );

     
  g_func_timer_info = 10;       // reset and set timer    
  LCDML_DISP_triggerMenu(100);  // starts a trigger event for the loop function every 100 millisecounds
}

void LCDML_DISP_loop(LCDML_FUNC_timer_info)
{ 
  // loop function, can be run in a loop when LCDML_DISP_triggerMenu(xx) is set
  // the quit button works in every DISP function without any checks; it starts the loop_end function 
  
  // this function is called every 100 millisecounds
  
  // this timer checks every 1000 millisecounds if it is called
  if((millis() - g_timer_1) >= 1000) {
    g_timer_1 = millis();   
    g_func_timer_info--;                // increment the value every secound
    char buf[20];
    sprintf (buf, "wait %d secounds", g_func_timer_info);
    
    u8g.setFont(u8g_font_6x13);
    u8g.firstPage();  
    do {
      u8g.drawStr( 0, 13, buf);
      u8g.drawStr( 0, 26, F("or press back button"));
    } while( u8g.nextPage() );   
  }
  
  // reset the initscreen timer
  LCDML_DISP_resetIsTimer();
  
  // this function can only be ended when quit button is pressed or the time is over
  // check if the function ends normaly
  if (g_func_timer_info <= 0)
  {
    // end function for callback
    LCDML_DISP_funcend();  
  }   
}

void LCDML_DISP_loop_end(LCDML_FUNC_timer_info) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing
}

// *********************************************************************
uint8_t g_button_value = 0; // button value counter (global variable)
void LCDML_DISP_setup(LCDML_FUNC_p2)
// *********************************************************************
{ 
  // setup function
  // print lcd content
  char buf[17];
  sprintf (buf, "count: %d of 3", 0);
  
  u8g.setFont(u8g_font_6x13);
  u8g.firstPage();  
  do {
    u8g.drawStr( 0, 13, F("press a or w button"));
    u8g.drawStr( 0, 26, buf);
  } while( u8g.nextPage() );  

  // Reset Button Value
  g_button_value = 0; 
}

void LCDML_DISP_loop(LCDML_FUNC_p2)
{
  // loop function, can be run in a loop when LCDML_DISP_triggerMenu(xx) is set
  // the quit button works in every DISP function without any checks; it starts the loop_end function 
  
  if (LCDML_BUTTON_checkAny()) // check if any button is pressed (enter, up, down, left, right)
  {
    if (LCDML_BUTTON_checkLeft() || LCDML_BUTTON_checkUp()) // check if button left is pressed
    {
      LCDML_BUTTON_resetLeft(); // reset the left button
      LCDML_BUTTON_resetUp(); // reset the left button
      g_button_value++;
      
      // update lcd content
      char buf[17];
      sprintf (buf, "count: %d of 3", g_button_value);
      
      u8g.setFont(u8g_font_6x13);
      u8g.firstPage();  
      do {
        u8g.drawStr( 0, 13, F("press a or w button"));
        u8g.drawStr( 0, 26, buf);
      } while( u8g.nextPage() );        
    }    
  }
  
  // check if button count is three
  if (g_button_value >= 3) {
    // end function for callback
    LCDML_DISP_funcend();   
  } 
}

void LCDML_DISP_loop_end(LCDML_FUNC_p2) 
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing
}*/
