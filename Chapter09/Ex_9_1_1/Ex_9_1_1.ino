int buzzerPin=9;
int songLength=142;

char notes[] = "e e e cdefg c c cdefggffeedcggffedc de e e cdefg c c cdefggffeedcggffedc d efg cefg gfecbfe efg efg egfcbfe gfe cgfe ceecbecbecbgf gfecbgf gf ";
int beats[] = {2,2,2,2,2,2,1,1,1,1,2,2,2,2,2,2,1,1,1,1,2,2,2,2,2,1,3,2,2,2,2,2,2,1,1,1,3,2,2,2,2,2,2,1,1,1,1,2,2,2,2,2,2,1,1,1,1,2,2,2,2,2,1,3,2,2,2,2,2,2,1,1,1,3,4,1,1,2,3,1,1,1,2,3,1,1,1,1,1,4,4,4,1,1,2,4,1,1,2,1,1,2,2,1,1,4,4,4,1,1,2,3,1,1,1,2,3,1,1,1,1,1,2,1,1,2,1,1,2,2,2,2,4,2,1,1,2,2,2,2,4,4};
int tempo = 150;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int duration;

  for(int i = 0; i< songLength; i++){
    duration = beats[i] * tempo;
    if(notes[i] == ' '){
      delay(duration);
    }else{
      tone(buzzerPin, frequency(notes[i]), duration);
      delay(duration);
    }
    delay(tempo/10);
  }
}

int frequency(char note){
  int i;
  int notes = 8;
  char names[] = {'c','d','e','f','g','a','b','c'};
  int frequencies[] = {523, 587,622 , 698, 784, 880, 466, 1046};

  for(i = 0; i<notes; i++){
    if(names[i] == note){
      return frequencies[i];
    }
  }
  return 0;
}
