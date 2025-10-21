#include <Arduino.h>
#include <defines.h>
#include <numbers.h>

void setup() 
{

  pinMode(ledPin, OUTPUT);
  pinMode(reedPin, INPUT_PULLUP);

  resetBtn.attach(resetPin, INPUT_PULLUP);
  resetBtn.setPressedState(LOW);
  resetBtn.interval(5);

  //ignore if it errors, it compiles just fine.
  FastLED.addLeds<WS2812, ledPin, GRB>(fullStrip, numLeds); 
  FastLED.setBrightness(255);

  Serial.begin(9600);
  
  Serial.print("total Leds: ");
  Serial.println(numLeds);

  Serial.print("Section LEDS: ");
  Serial.println(segLeds);
  watch.start();
  
  //Set Leds to black on restart
  FastLED.clear();
  FastLED.show();

}

void win()
{
  if(!chase.running())
  {  

    //This has a smoother transtions between colors
    // fill_rainbow(seg1,chaseCount,hue,5);
    // fill_rainbow(seg2,chaseCount,hue,5);
    // fill_rainbow(seg3,chaseCount,hue,5);
    // fill_rainbow(seg4,chaseCount,hue,5);

    //This is a less smooth transtion almost like sprinkles
    fill_rainbow_circular(seg1,chaseCount,hue);
    fill_rainbow_circular(seg2,chaseCount,hue);
    fill_rainbow_circular(seg3,chaseCount,hue);
    fill_rainbow_circular(seg4,chaseCount,hue);

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
    //This is going to go fast
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
  first = 0;
  second = 0;
  third = 0;
  fourth = 0;

  setOneDisplayNum(first);
  setTwoDisplayNum(second);
  setThirdDisplayNum(third);
  setFourthDisplayNum(fourth);

  winValue = 0;

  handleReturn = 0;

  needsReset = 0;
}


void loop() 
{

  //Set the handle state
  //We might need to add logic to account for "feathering" the handle
  //will have to test against the real setup

  handlePulled = checkSensor();
  // Serial.print("Handle State: ");
  // Serial.println(handlePulled);

  Serial.print("Handle Return: ");
  Serial.println(handleReturn);  

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

  if(handleReturn == 2)
  {
    checkCount = 1;
    //increment forward to prevent a double check
    needsReset = 1;
    handleReturn = 3;
  }
  
  if(checkCount)
  {
    if(fourth == win1 && third == win2 && second == win3 && first == win4)
    {
      //set to play win
      winValue = 1;
    }
    else
    {
      winValue = 0;
    }

    inGame = 0;
    checkCount = 0;
  }


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


  resetBtn.update();

  if(resetBtn.isPressed())
  {
    resetLeds();
  }
  
}
