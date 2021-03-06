 
#include <U8x8lib.h>
//U8X8_SSD1306_64X32_NONAME_SW_I2C  u8x8(4, 5 );
U8X8_SH1106_64X32_SW_I2C  u8x8(4, 5 );

char buf [255];


/* u8x8.begin() is required and will sent the setup/init sequence to the display */
void setup(void)
{
  u8x8.begin();
}

void loop(void)
{
  static int iCounter = 0;
  iCounter++;
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.drawString(0,0,"Citac:");

  sprintf (buf, "%i", iCounter);
  u8x8.drawString(40,40,buf);
  u8x8.drawString(60,60,buf);
  delay(1000);
}
