/* **************************************
 *  This example demonstrates text-to-
 *  speech and audio playback in MegunoLink.
 *  Open the companion MegunoLink project file
 *  (SpeechAndAudio.mlpz) in the same folder
 *  as this Arduino sketch. 
 *  
 *  For more information see: 
 *    https://www.megunolink.com/documentation/play-sounds/
 *    https://www.megunolink.com/documentation/arduino-libraries/arduino-timer/
 */
#include "MegunoLink.h"
#include "ArduinoTimer.h"

int nCounter = 10; 
::ArduinoTimer Countdown;
Audio Sounds;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  if (Countdown.TimePassed_Seconds(2))
  {
    if (nCounter > 0)
    { 
      Sounds.Speak(nCounter);
    }
    if (nCounter == 0)
    {
      Sounds.PlayAudioClip(F("Explosion"));
    }
    --nCounter;
  }
}
