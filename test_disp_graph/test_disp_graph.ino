
#include <U8g2lib.h>
//U8X8_SSD1306_128X64_NONAME_SW_I2C  u8x8(4, 5 );
//U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, 4, 5 );
//U8G2_SSD1306_128X64_ALT0_F_SW_I2C u8g2(U8G2_R0, 4, 5 ); 
U8G2_SSD1306_128X64_VCOMH0_F_SW_I2C u8g2(U8G2_R0, 4, 5 ); 
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
  u8g2.firstPage();
  do
  {
    u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.drawStr(0,25,"Citac:");
    u8g2.drawStr(0,50,buf);
  }while(u8g2.nextPage());
  delay(1000);
}



