//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <TM1637Display.h>
#include <string>

#define LCD_Backlight_Pin                  13

// 7  connection pins (Digital Pins)
#define CLK 14 //2
#define DIO 12 //3

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   2000

const uint8_t SEG_DONE[] = {
	SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
	SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
	SEG_C | SEG_E | SEG_G,                           // n
	SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
	};

TM1637Display display(CLK, DIO);


LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

char* message[] = {
  "12345678901234567890",
  "Marie et Ced!",
  "We want lobster!",
  "27 Avril 2024",
  "By JiLPi & Aure",
  "J'ai une blague sur ",
  "UDP, mais je suis",
  "pas sur que tu la ",
  "captes",
  "=====",
  "Deux paquets UDP",
  "discutent :",
  "  Ah bon ?",
  "  Il parait que je",
  "    peux arriver avant",
  "    toi",
  "====",
  "est L'ordre pour ",
  "critique UDP. faire", 
  "bonne blague une",
  "====",
  "Je te raconterai ",
  "cette blague TCP ",
  "jusqu'a ce que tu la",
  "captes.",
  "Je te raconterai ",
  "cette blague TCP ",
  "jusqu'a ce que tu la",
  "captes.",
  "Je te raconterai ",
  "cette blague TCP ",
  "jusqu'a ce que tu la",
  "captes.",
  "Je te raconterai ",
  "cette blague TCP ",
  "jusqu'a ce que tu la",
  "captes.",
  "====",
  "Desole, les blagues",
  "IPv4 sont epuisees.",
  "====",
  ""
};



void display_lines(char* message[4]) {
  for (int i=0; i<4; i++) {
    lcd.setCursor(0,i);
    lcd.print("                    ");
    lcd.setCursor(0,i);
    lcd.print(message[i]);
  }
}



void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();

  // Generation du signal PWM
  pinMode(LCD_Backlight_Pin, OUTPUT);                            // Definition de la broche D7 en tant que « SORTIE »
  analogWrite(LCD_Backlight_Pin, 200);    // Generation du signal PWM, avec le rapport cyclique voulu

  display.setBrightness(0x08);

  uint8_t zerozero7[] = { 0x00, display.encodeDigit(0), display.encodeDigit(0), display.encodeDigit(7)};
  display.setSegments(zerozero7);

}


void loop()
{

  int index=0;
  
  char* lines[4] = {
    "",
    "",
    "",
    ""
  };

  for (auto line: message) {
    for (int i=0; i<3; i++){
      lines[i]=lines[i+1];
    };
    lines[3]=line;

    display_lines(lines);
    delay(2000);
  };

}
