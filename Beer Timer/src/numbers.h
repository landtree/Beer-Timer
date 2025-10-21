

//Turn on the correct segments for the number to be displayed
void setOneDisplayNum(uint8_t num)
{   

    switch (num)
    {

    case 0:
        //1,2,4,5,6
        fill_solid(segOne, segLeds, On);
        fill_solid(segTwo, segLeds, On);
        fill_solid(segThree, segLeds, On);
        fill_solid(segFour, segLeds, On);
        fill_solid(segFive, segLeds, On);
        fill_solid(segSix, segLeds, On);
        fill_solid(segSeven, segLeds, Off);
        FastLED.show();
        break;
    case 1:
        //1,6
        fill_solid(segOne, segLeds, On);
        fill_solid(segTwo, segLeds, Off);
        fill_solid(segThree, segLeds, Off);
        fill_solid(segFour, segLeds, Off);
        fill_solid(segFive, segLeds, Off);
        fill_solid(segSix, segLeds, On);
        fill_solid(segSeven, segLeds, Off);
        FastLED.show();
        break;
     case 2:
        //2,1,7,4,5
        fill_solid(segOne, segLeds, On);
        fill_solid(segTwo, segLeds, On);
        fill_solid(segThree, segLeds, Off);
        fill_solid(segFour, segLeds, On);
        fill_solid(segFive, segLeds, On);
        fill_solid(segSix, segLeds, Off);
        fill_solid(segSeven, segLeds, On);
        FastLED.show();
        break;
    case 3:
        //2,1,5,6,7
        fill_solid(segOne, segLeds, On);
        fill_solid(segTwo, segLeds, On);
        fill_solid(segThree, segLeds, Off);
        fill_solid(segFour, segLeds, Off);
        fill_solid(segFive, segLeds, On);
        fill_solid(segSix, segLeds, On);
        fill_solid(segSeven, segLeds, On);
        FastLED.show();
        break;
    case 4:
        //1,3,6,7        
        fill_solid(segOne, segLeds, On);
        fill_solid(segTwo, segLeds, Off);
        fill_solid(segThree, segLeds, On);
        fill_solid(segFour, segLeds, Off);
        fill_solid(segFive, segLeds, Off);
        fill_solid(segSix, segLeds, On);
        fill_solid(segSeven, segLeds, On);
        FastLED.show();
        break;
    case 5:
        //2,3,5,6,7
        fill_solid(segOne, segLeds, Off);
        fill_solid(segTwo, segLeds, On);
        fill_solid(segThree, segLeds, On);
        fill_solid(segFour, segLeds, Off);
        fill_solid(segFive, segLeds, On);
        fill_solid(segSix, segLeds, On);
        fill_solid(segSeven, segLeds, On);
        FastLED.show();
        break;
    case 6:
        //2,3,4,5,6,7
        fill_solid(segOne, segLeds, Off);
        fill_solid(segTwo, segLeds, On);
        fill_solid(segThree, segLeds, On);
        fill_solid(segFour, segLeds, On);
        fill_solid(segFive, segLeds, On);
        fill_solid(segSix, segLeds, On);
        fill_solid(segSeven, segLeds, On);
        FastLED.show();
        break;
    case 7:
        //2,1,6
        fill_solid(segOne, segLeds, On);
        fill_solid(segTwo, segLeds, On);
        fill_solid(segThree, segLeds, Off);
        fill_solid(segFour, segLeds, Off);
        fill_solid(segFive, segLeds, Off);
        fill_solid(segSix, segLeds, On);
        fill_solid(segSeven, segLeds, Off);
        FastLED.show();
        break;
    case 8:
        //1,2,3,4,5,6,7
        fill_solid(segOne, segLeds, On);
        fill_solid(segTwo, segLeds, On);
        fill_solid(segThree, segLeds, On);
        fill_solid(segFour, segLeds, On);
        fill_solid(segFive, segLeds, On);
        fill_solid(segSix, segLeds, On);
        fill_solid(segSeven, segLeds, On);
        FastLED.show();
        break;
    case 9:
        //1,2,3,6,7
        fill_solid(segOne, segLeds, On);
        fill_solid(segTwo, segLeds, On);
        fill_solid(segThree, segLeds, On);
        fill_solid(segFour, segLeds, Off);
        fill_solid(segFive, segLeds, Off);
        fill_solid(segSix, segLeds, On);
        fill_solid(segSeven, segLeds, On);
        FastLED.show();
        break;
    }

}


//Turn on the correct segments for the number to be displayed
void setTwoDisplayNum(uint8_t num)
{   

    switch (num)
    {

    case 0:
        //1,2,4,5,6
        fill_solid(oneSegOne, segLeds, On);
        fill_solid(oneSegTwo, segLeds, On);
        fill_solid(oneSegThree, segLeds, On);
        fill_solid(oneSegFour, segLeds, On);
        fill_solid(oneSegFive, segLeds, On);
        fill_solid(oneSegSix, segLeds, On);
        fill_solid(oneSegSeven, segLeds, Off);
        FastLED.show();
        break;
    case 1:
        //1,6
         fill_solid(oneSegOne, segLeds, On);
         fill_solid(oneSegTwo, segLeds, Off);
         fill_solid(oneSegThree, segLeds, Off);
         fill_solid(oneSegFour, segLeds, Off);
         fill_solid(oneSegFive, segLeds, Off);
         fill_solid(oneSegSix, segLeds, On);
         fill_solid(oneSegSeven, segLeds, Off);
        FastLED.show();
        break;
     case 2:
        //2,1,7,4,5
         fill_solid(oneSegOne, segLeds, On);
         fill_solid(oneSegTwo, segLeds, On);
         fill_solid(oneSegThree, segLeds, Off);
         fill_solid(oneSegFour, segLeds, On);
         fill_solid(oneSegFive, segLeds, On);
         fill_solid(oneSegSix, segLeds, Off);
         fill_solid(oneSegSeven, segLeds, On);
        FastLED.show();
        break;
    case 3:
        //2,1,5,6,7
         fill_solid(oneSegOne, segLeds, On);
         fill_solid(oneSegTwo, segLeds, On);
         fill_solid(oneSegThree, segLeds, Off);
         fill_solid(oneSegFour, segLeds, Off);
         fill_solid(oneSegFive, segLeds, On);
         fill_solid(oneSegSix, segLeds, On);
         fill_solid(oneSegSeven, segLeds, On);
        FastLED.show();
        break;
    case 4:
        //1,3,6,7        
        fill_solid(oneSegOne, segLeds, On);
        fill_solid(oneSegTwo, segLeds, Off);
        fill_solid(oneSegThree, segLeds, On);
        fill_solid(oneSegFour, segLeds, Off);
        fill_solid(oneSegFive, segLeds, Off);
        fill_solid(oneSegSix, segLeds, On);
        fill_solid(oneSegSeven, segLeds, On);
        FastLED.show();
        break;
    case 5:
        //2,3,5,6,7
        fill_solid(oneSegOne, segLeds, Off);
        fill_solid(oneSegTwo, segLeds, On);
        fill_solid(oneSegThree, segLeds, On);
        fill_solid(oneSegFour, segLeds, Off);
        fill_solid(oneSegFive, segLeds, On);
        fill_solid(oneSegSix, segLeds, On);
        fill_solid(oneSegSeven, segLeds, On);
        FastLED.show();
        break;
    case 6:
        //2,3,4,5,6,7
        fill_solid(oneSegOne, segLeds, Off);
        fill_solid(oneSegTwo, segLeds, On);
        fill_solid(oneSegThree, segLeds, On);
        fill_solid(oneSegFour, segLeds, On);
        fill_solid(oneSegFive, segLeds, On);
        fill_solid(oneSegSix, segLeds, On);
        fill_solid(oneSegSeven, segLeds, On);
        FastLED.show();
        break;
    case 7:
        //2,1,6
        fill_solid(oneSegOne, segLeds, On);
        fill_solid(oneSegTwo, segLeds, On);
        fill_solid(oneSegThree, segLeds, Off);
        fill_solid(oneSegFour, segLeds, Off);
        fill_solid(oneSegFive, segLeds, Off);
        fill_solid(oneSegSix, segLeds, On);
        fill_solid(oneSegSeven, segLeds, Off);
        FastLED.show();
        break;
    case 8:
        //1,2,3,4,5,6,7
        fill_solid(oneSegOne, segLeds, On);
        fill_solid(oneSegTwo, segLeds, On);
        fill_solid(oneSegThree, segLeds, On);
        fill_solid(oneSegFour, segLeds, On);
        fill_solid(oneSegFive, segLeds, On);
        fill_solid(oneSegSix, segLeds, On);
        fill_solid(oneSegSeven, segLeds, On);
        FastLED.show();
        break;
    case 9:
        //1,2,3,6,7
        fill_solid(oneSegOne, segLeds, On);
        fill_solid(oneSegTwo, segLeds, On);
        fill_solid(oneSegThree, segLeds, On);
        fill_solid(oneSegFour, segLeds, Off);
        fill_solid(oneSegFive, segLeds, Off);
        fill_solid(oneSegSix, segLeds, On);
        fill_solid(oneSegSeven, segLeds, On);
        FastLED.show();
        break;
    }

}


void setThirdDisplayNum(uint8_t num)
{   

    switch (num)
    {

    case 0:
        //1,2,4,5,6
        fill_solid(twoSegOne, segLeds, On);
        fill_solid(twoSegTwo, segLeds, On);
        fill_solid(twoSegThree, segLeds, On);
        fill_solid(twoSegFour, segLeds, On);
        fill_solid(twoSegFive, segLeds, On);
        fill_solid(twoSegSix, segLeds, On);
        fill_solid(twoSegSeven, segLeds, Off);
        FastLED.show();
        break;
    case 1:
        //1,6
         fill_solid(twoSegOne, segLeds, On);
         fill_solid(twoSegTwo, segLeds, Off);
         fill_solid(twoSegThree, segLeds, Off);
         fill_solid(twoSegFour, segLeds, Off);
         fill_solid(twoSegFive, segLeds, Off);
         fill_solid(twoSegSix, segLeds, On);
         fill_solid(twoSegSeven, segLeds, Off);
        FastLED.show();
        break;
     case 2:
        //2,1,7,4,5
         fill_solid(twoSegOne, segLeds, On);
         fill_solid(twoSegTwo, segLeds, On);
         fill_solid(twoSegThree, segLeds, Off);
         fill_solid(twoSegFour, segLeds, On);
         fill_solid(twoSegFive, segLeds, On);
         fill_solid(twoSegSix, segLeds, Off);
         fill_solid(twoSegSeven, segLeds, On);
        FastLED.show();
        break;
    case 3:
        //2,1,5,6,7
        fill_solid(twoSegOne, segLeds, On);
        fill_solid(twoSegTwo, segLeds, On);
        fill_solid(twoSegThree, segLeds, Off);
        fill_solid(twoSegFour, segLeds, Off);
        fill_solid(twoSegFive, segLeds, On);
        fill_solid(twoSegSix, segLeds, On);
        fill_solid(twoSegSeven, segLeds, On);
        FastLED.show();
        break;
    case 4:
        //1,3,6,7        
        fill_solid(twoSegOne, segLeds, On);
        fill_solid(twoSegTwo, segLeds, Off);
        fill_solid(twoSegThree, segLeds, On);
        fill_solid(twoSegFour, segLeds, Off);
        fill_solid(twoSegFive, segLeds, Off);
        fill_solid(twoSegSix, segLeds, On);
        fill_solid(twoSegSeven, segLeds, On);
        FastLED.show();
        break;
    case 5:
        //2,3,5,6,7
        fill_solid(twoSegOne, segLeds, Off);
        fill_solid(twoSegTwo, segLeds, On);
        fill_solid(twoSegThree, segLeds, On);
        fill_solid(twoSegFour, segLeds, Off);
        fill_solid(twoSegFive, segLeds, On);
        fill_solid(twoSegSix, segLeds, On);
        fill_solid(twoSegSeven, segLeds, On);
        FastLED.show();
        break;
    case 6:
        //2,3,4,5,6,7
        fill_solid(twoSegOne, segLeds, Off);
        fill_solid(twoSegTwo, segLeds, On);
        fill_solid(twoSegThree, segLeds, On);
        fill_solid(twoSegFour, segLeds, On);
        fill_solid(twoSegFive, segLeds, On);
        fill_solid(twoSegSix, segLeds, On);
        fill_solid(twoSegSeven, segLeds, On);
        FastLED.show();
        break;
    case 7:
        //2,1,6
        fill_solid(twoSegOne, segLeds, On);
        fill_solid(twoSegTwo, segLeds, On);
        fill_solid(twoSegThree, segLeds, Off);
        fill_solid(twoSegFour, segLeds, Off);
        fill_solid(twoSegFive, segLeds, Off);
        fill_solid(twoSegSix, segLeds, On);
        fill_solid(twoSegSeven, segLeds, Off);
        FastLED.show();
        break;
    case 8:
        //1,2,3,4,5,6,7
        fill_solid(twoSegOne, segLeds, On);
        fill_solid(twoSegTwo, segLeds, On);
        fill_solid(twoSegThree, segLeds, On);
        fill_solid(twoSegFour, segLeds, On);
        fill_solid(twoSegFive, segLeds, On);
        fill_solid(twoSegSix, segLeds, On);
        fill_solid(twoSegSeven, segLeds, On);
        FastLED.show();
        break;
    case 9:
        //1,2,3,6,7
        fill_solid(twoSegOne, segLeds, On);
        fill_solid(twoSegTwo, segLeds, On);
        fill_solid(twoSegThree, segLeds, On);
        fill_solid(twoSegFour, segLeds, Off);
        fill_solid(twoSegFive, segLeds, Off);
        fill_solid(twoSegSix, segLeds, On);
        fill_solid(twoSegSeven, segLeds, On);
        FastLED.show();
        break;
    }

}

//Turn on the correct segments for the number to be displayed
void setFourthDisplayNum(uint8_t num)
{   

    switch (num)
    {

    case 0:
        //1,2,4,5,6
        fill_solid(threeSegOne, segLeds, On);
        fill_solid(threeSegTwo, segLeds, On);
        fill_solid(threeSegThree, segLeds, On);
        fill_solid(threeSegFour, segLeds, On);
        fill_solid(threeSegFive, segLeds, On);
        fill_solid(threeSegSix, segLeds, On);
        fill_solid(threeSegSeven, segLeds, Off);
        FastLED.show();
        break;
    case 1:
        //1,6
        fill_solid(threeSegOne, segLeds, On);
        fill_solid(threeSegTwo, segLeds, Off);
        fill_solid(threeSegThree, segLeds, Off);
        fill_solid(threeSegFour, segLeds, Off);
        fill_solid(threeSegFive, segLeds, Off);
        fill_solid(threeSegSix, segLeds, On);
        fill_solid(threeSegSeven, segLeds, Off);
        FastLED.show();
        break;
     case 2:
        //2,1,7,4,5
         fill_solid(threeSegOne, segLeds, On);
         fill_solid(threeSegTwo, segLeds, On);
         fill_solid(threeSegThree, segLeds, Off);
         fill_solid(threeSegFour, segLeds, On);
         fill_solid(threeSegFive, segLeds, On);
         fill_solid(threeSegSix, segLeds, Off);
         fill_solid(threeSegSeven, segLeds, On);
        FastLED.show();
        break;
    case 3:
        //2,1,5,6,7
        fill_solid(threeSegOne, segLeds, On);
        fill_solid(threeSegTwo, segLeds, On);
        fill_solid(threeSegThree, segLeds, Off);
        fill_solid(threeSegFour, segLeds, Off);
        fill_solid(threeSegFive, segLeds, On);
        fill_solid(threeSegSix, segLeds, On);
        fill_solid(threeSegSeven, segLeds, On);
        FastLED.show();
        break;
    case 4:
        //1,3,6,7        
        fill_solid(threeSegOne, segLeds, On);
        fill_solid(threeSegTwo, segLeds, Off);
        fill_solid(threeSegThree, segLeds, On);
        fill_solid(threeSegFour, segLeds, Off);
        fill_solid(threeSegFive, segLeds, Off);
        fill_solid(threeSegSix, segLeds, On);
        fill_solid(threeSegSeven, segLeds, On);
        FastLED.show();
        break;
    case 5:
        //2,3,5,6,7
        fill_solid(threeSegOne, segLeds, Off);
        fill_solid(threeSegTwo, segLeds, On);
        fill_solid(threeSegThree, segLeds, On);
        fill_solid(threeSegFour, segLeds, Off);
        fill_solid(threeSegFive, segLeds, On);
        fill_solid(threeSegSix, segLeds, On);
        fill_solid(threeSegSeven, segLeds, On);
        FastLED.show();
        break;
    case 6:
        //2,3,4,5,6,7
        fill_solid(threeSegOne, segLeds, Off);
        fill_solid(threeSegTwo, segLeds, On);
        fill_solid(threeSegThree, segLeds, On);
        fill_solid(threeSegFour, segLeds, On);
        fill_solid(threeSegFive, segLeds, On);
        fill_solid(threeSegSix, segLeds, On);
        fill_solid(threeSegSeven, segLeds, On);
        FastLED.show();
        break;
    case 7:
        //2,1,6
        fill_solid(threeSegOne, segLeds, On);
        fill_solid(threeSegTwo, segLeds, On);
        fill_solid(threeSegThree, segLeds, Off);
        fill_solid(threeSegFour, segLeds, Off);
        fill_solid(threeSegFive, segLeds, Off);
        fill_solid(threeSegSix, segLeds, On);
        fill_solid(threeSegSeven, segLeds, Off);
        FastLED.show();
        break;
    case 8:
        //1,2,3,4,5,6,7
        fill_solid(threeSegOne, segLeds, On);
        fill_solid(threeSegTwo, segLeds, On);
        fill_solid(threeSegThree, segLeds, On);
        fill_solid(threeSegFour, segLeds, On);
        fill_solid(threeSegFive, segLeds, On);
        fill_solid(threeSegSix, segLeds, On);
        fill_solid(threeSegSeven, segLeds, On);
        FastLED.show();
        break;
    case 9:
        //1,2,3,6,7
        fill_solid(threeSegOne, segLeds, On);
        fill_solid(threeSegTwo, segLeds, On);
        fill_solid(threeSegThree, segLeds, On);
        fill_solid(threeSegFour, segLeds, Off);
        fill_solid(threeSegFive, segLeds, Off);
        fill_solid(threeSegSix, segLeds, On);
        fill_solid(threeSegSeven, segLeds, On);
        FastLED.show();
        break;
    }

}



















































































































