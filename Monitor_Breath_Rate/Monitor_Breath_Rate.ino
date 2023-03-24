/*   "Breath Rate Monitor project" 
This code measure the number of peaks to calculate breath rate by a mathematical equation.
The code also measures Inhalation time and Exhalation time.
*/
//define echo and trigger pins
#define trig 13
#define echo 12
//declaration of some variables
int distance[10]; 
double time[10];
double duration;
double breathRate;
int iInhalation;
int iExhalation;

void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}

void loop() {
int peaksNum=0;
double inhalationTime=0;
double exhalationTime=0;  
Serial.println("distances: ");
for(int i=0; i<10;i++){
//data sheet
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(5);
  digitalWrite(trig,LOW);
//take distances & calc duration of ultrasound 
  duration=pulseIn(echo,HIGH);
  if (duration<1457){
    time[i]=duration;
    distance[i]=(0.0343)*(duration/2); 
  }   
//wait 0.7 second
  delay(700);
//print distences  
  Serial.println(distance[i]);
}

//calc peaks number
for(int i=1; i<10;i++){
  if ((distance[i]<distance[i-1])&& (distance[i]<distance[i+1])){
    peaksNum = peaksNum+1; 
  } 
}
//calc inhalation time  
for( int i=1; i<10;i++){
  if (distance[i]<distance[i+1]){
    iInhalation = i;
    for(int j=0; j<=iInhalation;j++)
    inhalationTime+=time[j];
    break;
  } 
}
//calc exhalation time  
for( int i=iInhalation; i<10;i++){
  if (distance[i]>distance[i+1]){
    iExhalation = i;
    for(int j=iInhalation; j<=iExhalation;j++)
    exhalationTime+=time[j];
    break; 
  }
}
//calc breath rate per minute  //breath rate=number of cycles/time in minutes
  breathRate=(1000.00*60.0)/(inhalationTime+exhalationTime);

//print some data
  Serial.print("Inhalation time in seconds is: ");
  Serial.println(inhalationTime*0.001);
  Serial.print("Exhalation time in seconds is: ");
  Serial.println(exhalationTime*0.001);
  Serial.print("Inhalation to exhalation time (ratio): ");
  Serial.println(inhalationTime/exhalationTime);
  Serial.print("Peaks Number: ");
  Serial.println(peaksNum);
  Serial.print("Breath rate: ");
  Serial.println(breathRate);

//print patient's condition
if(breathRate>=12&&breathRate<=20)   Serial.println("Normal breathing ^_^ ");
else if(breathRate<12)   Serial.println("Bradypnea breathing -_- ");
else if(breathRate>20)   Serial.println("Tachypnea breathing -_- ");
}