const int NUM = 3;
const int BUF_NUM = 5;

int counter = 0;
int buf[NUM][BUF_NUM] = {0};

void setup(){
  Serial.begin(9600);
}

void loop(){
  unsigned long data = 0;
  
  for(int i=0; i<NUM; ++i){
    int current = analogRead(i);
    buf[i][counter] = current;
    
    float av = 0;
    for(int j=0; j<BUF_NUM; ++j){
      av += buf[i][j];
    }
    
    av /= BUF_NUM;
    
    if(av < 150){
      bitWrite(data, i, 1);
    }
  }
  
  Serial.write(data);
  
  delay(30);
  
  counter = (counter < BUF_NUM-1) ? counter + 1 : 0 ;
}
