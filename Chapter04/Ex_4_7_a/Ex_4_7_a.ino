/*

  예제 4.7을 MAX7219를 활용하여 응용한 예제입니다.
  방향 표시 애니메이션이 포함됩니다.

*/

#include <LedControl.h>
#define DIN 12
#define CLK 11
#define CS  10

LedControl lc(DIN, CLK, CS, 1);

unsigned char anim[][8] = {
  {0x00, 0x00, 0x18, 0x24, 0x5A, 0xA5, 0x42, 0x81},
  {0x00, 0x18, 0x24, 0x5A, 0xA5, 0x42, 0x81, 0x00},
  {0x18, 0x24, 0x5A, 0xA5, 0x42, 0x81, 0x00, 0x00}
};

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 4);
  lc.clearDisplay(0);
}
  
void loop() {
  for(int i = 0 ;i< 3; i++)
  {
    for(int j=0; j<8;j++)
    {
      lc.setRow(0, j, anim[i][j]);      
    }
    delay(500);
  }
}
