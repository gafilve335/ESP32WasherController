#include <BlynkGOv3.h>
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_G5  784
#define NOTE_A5  880
uint8_t SPEAKER_PIN = 2;

int melody[] = {
  NOTE_G5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_G5,
};

int noteDurations[] = {8, 8, 8, 8, 4,};

namespace MELODY{

    void playMelody(){
        for (int i = 0; i < sizeof(melody)/sizeof(melody[0]); i++) {
            int noteDuration = 1000 / noteDurations[i]; 
            tone(SPEAKER_PIN, melody[i], noteDuration); 
            int pauseBetweenNotes = noteDuration * 1.30;
            delay(pauseBetweenNotes);
            noTone(SPEAKER_PIN); 
        }
    } 
} 






