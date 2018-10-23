
#include <U8g2lib.h>
//U8X8_SSD1306_128X64_NONAME_SW_I2C       u8x8(22, 21 );
//U8G2_SSD1306_128X64_NONAME_F_SW_I2C       u8g2(U8G2_R0, 22, 21 );
U8G2_SSD1306_128X64_NONAME_F_HW_I2C     u8g2(U8G2_R0);
//U8G2_SSD1306_128X64_NONAME_F_2ND_HW_I2C u8g2(U8G2_R0);

char buf [255];


/* u8x8.begin() is required and will sent the setup/init sequence to the display */
void setup(void)
{
  u8g2.begin();
}

void loop(void)
{
  static int iCounter = 0;
  iCounter++;
  
  sprintf (buf, "%i", iCounter);
  
// u8g2.firstPage();
//  do
//  {
//  }while(u8g2.nextPage()); 
//  
//  
//  u8g2.firstPage();
//  do
//  {
//    delay(1500);
//    u8g2.setFont(u8g2_font_ncenB14_tr);
//    u8g2.drawStr(10,10,"Citac:");
//    u8g2.drawCircle(20, 25, 10, U8G2_DRAW_ALL);
//    u8g2.drawStr(0,50,buf);
//  }while(u8g2.nextPage());
//  delay(1000);

    u8g2.clearBuffer();
    u8g2.sendBuffer();
    delay(500);
    u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.drawStr(10,10,"Citac:");
    u8g2.drawCircle(20, 25, 10, U8G2_DRAW_ALL);
    u8g2.drawStr(0,50,buf);
    u8g2.sendBuffer();
    delay(500);
    

}



