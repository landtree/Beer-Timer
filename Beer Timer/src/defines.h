#include <FastLED.h>
#include <Chrono.h>
#include <Bounce2.h>
#include <Timer.h>

Chrono watch;
MoToTimer chase,hueTimer;

Bounce2::Button resetBtn = Bounce2::Button();

#define ledPin 3
#define reedPin A1
#define resetPin 4

const uint8_t numOfSegments = 4;
const uint8_t segLeds = 3;

//Seven segments * the number of leds per segment
const uint8_t numLeds (7 * segLeds * numOfSegments);

//LEDs in 1 full 7 segment
const uint8_t numLedsSegment (7 * segLeds);

//create the full strip of leds
CRGB fullStrip[numLeds];


//Set this RGB value to set the colors of the segments
#define On CRGB( 255, 0, 0)

//This will set the segments off;
#define Off  CRGB( 0, 0, 0)


bool handlePulled = false;


//segment counters
//position from right to left
//ms to secs etc
uint8_t first = 0;
uint8_t second = 0;
uint8_t third = 0;
uint8_t fourth = 0;


uint8_t chaseCount = 0;
uint8_t hue = 0;


//These hold the values to check if we won
//values check from left to right
const uint8_t win1 = 0;
const uint8_t win2 = 0;
const uint8_t win3 = 1;
const uint8_t win4 = 4;
bool checkCount = 0;
bool inGame = 0;
bool needsReset = 0;

uint8_t handleReturn = 0;
uint8_t winValue = 3; //0 = fail; 1 = win; 3 = nothing;

//How fast the LED moves
uint8_t chaseTime = 25;
//How fast the LED shifts colors
uint8_t hueTime = 50;
//how fast the red chases
uint8_t failChase = 40;
//how instense the fade effect is on the fail sequence
//50-80 seems to be the sweet spot
//large the numer the shorter the tail
uint8_t fade = 60;

//These will break up the full strip into logical sections
//create pointers for 1 segment
CRGB* segOne = &fullStrip[0]; //0-2
CRGB* segTwo = &fullStrip[segLeds * 1]; // 3-5
CRGB* segThree = &fullStrip[segLeds * 2]; // 6-8
CRGB* segFour = &fullStrip[segLeds * 3]; // 9-11
CRGB* segFive = &fullStrip[segLeds * 4]; //12-14
CRGB* segSix = &fullStrip[segLeds * 5]; //15-17
CRGB* segSeven = &fullStrip[segLeds * 6]; //18-20

//create pointers for 2 segment
CRGB* oneSegOne = &fullStrip[segLeds * 7]; //21-23
CRGB* oneSegTwo = &fullStrip[segLeds * 8]; //24-26
CRGB* oneSegThree = &fullStrip[segLeds * 9]; //27-29
CRGB* oneSegFour = &fullStrip[segLeds * 10]; //30-32
CRGB* oneSegFive = &fullStrip[segLeds * 11]; //33-35
CRGB* oneSegSix = &fullStrip[segLeds * 12]; //36-38
CRGB* oneSegSeven = &fullStrip[segLeds * 13]; //39-41

//create pointers for 3 segment
CRGB* twoSegOne = &fullStrip[segLeds * 14]; 
CRGB* twoSegTwo = &fullStrip[segLeds * 15]; 
CRGB* twoSegThree = &fullStrip[segLeds * 16];
CRGB* twoSegFour = &fullStrip[segLeds * 17];
CRGB* twoSegFive = &fullStrip[segLeds * 18];
CRGB* twoSegSix = &fullStrip[segLeds * 19];
CRGB* twoSegSeven = &fullStrip[segLeds * 20];

//create pointers for 4 segment
CRGB* threeSegOne = &fullStrip[segLeds * 21]; 
CRGB* threeSegTwo = &fullStrip[segLeds * 22]; 
CRGB* threeSegThree = &fullStrip[segLeds * 23];
CRGB* threeSegFour = &fullStrip[segLeds * 24];
CRGB* threeSegFive = &fullStrip[segLeds * 25];
CRGB* threeSegSix = &fullStrip[segLeds * 26];
CRGB* threeSegSeven = &fullStrip[segLeds * 27];

//Create 4 full segment strips
CRGB* seg1 = &fullStrip[0];
CRGB* seg2 = &fullStrip[numLedsSegment];
CRGB* seg3 = &fullStrip[numLedsSegment * 2];
CRGB* seg4 = &fullStrip[numLedsSegment * 3];

