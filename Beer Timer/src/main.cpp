#include <Arduino.h>
#include <defines.h>
#include <numbers.h>

void setup() 
{
  //Set pins
  pinMode(ledPin, OUTPUT);
  pinMode(reedPin, INPUT_PULLUP);

  //Create button
  resetBtn.attach(resetPin, INPUT_PULLUP);
  resetBtn.setPressedState(LOW);
  resetBtn.interval(5);

  //ignore if it errors, it compiles just fine.
  FastLED.addLeds<WS2812, ledPin, GRB>(fullStrip, numLeds); 
  
  //If you want to adjust how much voltage is being pulled
  //Your model uses 12V @ 4A for the full strip.
  //Basically you can software control the amp draw by dimming the LEDS.
  //FastLED.setMaxPowerInVoltsAndMilliamps(12,4000)
  
  //There is some Debug info
  Serial.begin(9600);
  
  Serial.print("total Leds: ");
  Serial.println(numLeds);

  Serial.print("Section LEDS: ");
  Serial.println(segLeds);
  watch.start();
  
  //Clear any data from LEDS
  FastLED.clear();
  FastLED.show();

  //Set Leds to 0
  setOneDisplayNum(first);
  setTwoDisplayNum(second);
  setThirdDisplayNum(third);
  setFourthDisplayNum(fourth);

}

void win()
{
  if(!chase.running())
  {  

    //uncomment or comment this to see which one you like better.

    //#define smooth
  
    #if defined(smooth)
      //This has a smoother transtions between colors
      fill_rainbow(seg1,chaseCount,hue,5);
      fill_rainbow(seg2,chaseCount,hue,5);
      fill_rainbow(seg3,chaseCount,hue,5);
      fill_rainbow(seg4,chaseCount,hue,5);

    #else
      //This forces the rainbow spectrum based on LED count
      //It makes it less smooth with small strips and more like sprinkles of colors
      fill_rainbow_circular(seg1,chaseCount,hue);
      fill_rainbow_circular(seg2,chaseCount,hue);
      fill_rainbow_circular(seg3,chaseCount,hue);
      fill_rainbow_circular(seg4,chaseCount,hue);
    #endif

    chase.setTime(chaseTime);
    chaseCount++;
    FastLED.show();
    if(chaseCount > numLedsSegment){chaseCount = 0;}
  }

  if(!hueTimer.running()){hue = hue +5; if(hue == 255){hue = 0;} hueTimer.setTime(hueTime);}

}

void fail()
{
  
  if(!chase.running())
  {  
    //display 1
    seg1[chaseCount] = CRGB::Red;
    fadeToBlackBy(seg1,numLedsSegment,fade);

    //display 2
    seg2[chaseCount] = CRGB::Red;
    fadeToBlackBy(seg2,numLedsSegment,fade);

    //display 3
    seg3[chaseCount] = CRGB::Red;
    fadeToBlackBy(seg3,numLedsSegment,fade);

    //display 4
    seg4[chaseCount] = CRGB::Red;
    fadeToBlackBy(seg4,numLedsSegment,fade);    

    FastLED.show();
    chaseCount++;
    
    if(chaseCount > (numLedsSegment - 4) ){chaseCount = 0;}
    chase.setTime(failChase);
  }

}



//Check and return if sensor is triggered or not
bool checkSensor()
{
  bool tempRead = digitalRead(reedPin);

  //If the handle was pulled away increment forward
  if(tempRead)
  {
    if(handleReturn == 0)
    {
    handleReturn++;
    }
  }

  //if the handle returned increment forward
  if(!tempRead)
  {  
    if(handleReturn == 1)
    {
      handleReturn++;
    }
  }

  return tempRead;
}

void startCount()
{
    //The timer in millis
    //When we hit 10 it rolls the next number up.
    
    //we will have to guess what we want the timing to be
    //This is going to go fast if it is a ture timer
    if(watch.hasPassed(300))
    {
      first++;

      if(first==10)
      {
        //reset millis
        first=0;
        //increase seconds position
        second++; 
        if(second==10)
        {
          //reset seconds
          second=0;

          third++;
          if(third == 10)
          {
            third=0;
            fourth++;

          }

        }
      }

      watch.restart();
    }
    //update the displays to match timers
    setOneDisplayNum(first);
    setTwoDisplayNum(second);
    setThirdDisplayNum(third);
    //setFourthDisplayNum(fourth);

}

void resetLeds()
{
  //resets when the button is pressed to clear out and start over
  first = 0;
  second = 0;
  third = 0;
  fourth = 0;

  setOneDisplayNum(first);
  setTwoDisplayNum(second);
  setThirdDisplayNum(third);
  setFourthDisplayNum(fourth);

  inGame = 0;
  winValue = 3;
  handleReturn = 0;
  needsReset = 0;
}


void loop() 
{

  //Set the handle state
  //We might need to add logic to account for "feathering" the handle
  //We are reading the reed digital but we can read analog to cerate a threshold if needing to.
  //will have to test against the real setup

  handlePulled = checkSensor();
  Serial.print("Handle State: ");
  Serial.println(handlePulled);

  Serial.print("Handle Return: ");
  Serial.println(handleReturn);  

  //only count while we are in game and not needing to reset
  if(!inGame)
  {   
   if(handlePulled) 
    {
      inGame = 1;
    }
  }else
  {
    if(!needsReset)
   { 
    startCount();
    }
  }

  //The handle has been returned
  //This is when we will check if they got it correct
  if(handleReturn == 2)
  {
    checkCount = 1;
    needsReset = 1;
    handleReturn = 3;
  }
  
  //Check the stored values to the timer values 
  if(checkCount)
  {
    if(fourth == win1 && third == win2 && second == win3 && first == win4)
    {
      //set to play win
      winValue = 1;
    }
    else
    {
      //set to play fail
      winValue = 0;
    }

    //exit the game and leave timer checking
    inGame = 0;
    checkCount = 0;
  }

  //if have a winValue other than default play the right sequence

  if(winValue !=3)
  {
    if(winValue == 1)
    {
      win();
    }
    if(winValue == 0)
    {
      fail();
    }
  }


  //Check to see if the reset button was pressed
  resetBtn.update();
  if(resetBtn.isPressed() && !btnDelay.running())
  {
    resetLeds();
    btnDelay.setTime(300);
  }
  
}
