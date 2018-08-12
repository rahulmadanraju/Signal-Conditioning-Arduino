@@ -0,0 +1,316 @@
#include <Wire.h>

/*int analogReadPin   = A0;   // read voltage from master
int analogRdAmpOp   = A1;   // read amplifier output
int analogWrtAmp1   = 11;  // write voltage to Amplifier1 input
int analogWrtAmp2   = 10;  // write voltage to Amplifier2 input
int analogWrtFilter1 = 9;  // write voltage to Filter1 input
int analogWrtFilter2 = 6;  // write voltage to filter2 input*/

int DM1S0 = 7;
int DM1S1 = 8;
int DM2S0 = 9;
int DM2S1 = 10;

int swtch_int ;

void setup() {
  Wire.begin(10);                // join i2c bus with address #10
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void receiveEvent(int howMany) {
  while ( Wire.available()) { // loop through all but the last
   swtch_int = Wire.read();    // receive byte as an integer
  Serial.println(swtch_int);         // print the integer
}
switch(swtch_int){
            case 1 : Serial.println("Gain1 10 selected"); digitalWrite(DM1S0, LOW); digitalWrite(DM1S1, LOW); digitalWrite(DM2S0, HIGH); digitalWrite(DM2S1, HIGH); break;
       
            case 2 : Serial.println("Gain2 100 selected"); digitalWrite(DM1S0, LOW); digitalWrite(DM1S1, HIGH); digitalWrite(DM2S0, HIGH); digitalWrite(DM2S1, HIGH);break;

            case 3 : Serial.println("Gain3 500 selected"); digitalWrite(DM1S0, HIGH); digitalWrite(DM1S1, LOW); digitalWrite(DM2S0, HIGH); digitalWrite(DM2S1, HIGH);break;

            case 4 : Serial.println("Low pass filter selected"); digitalWrite(DM1S0, HIGH); digitalWrite(DM1S1, HIGH); digitalWrite(DM2S0, LOW); digitalWrite(DM2S1, LOW);break;

            case 5 : Serial.println("High pass filter selected"); digitalWrite(DM1S0, HIGH); digitalWrite(DM1S1, HIGH); digitalWrite(DM2S0, LOW); digitalWrite(DM2S1, HIGH);break;

            case 6 : Serial.println("Band pass selected"); digitalWrite(DM1S0, HIGH); digitalWrite(DM1S1, HIGH); digitalWrite(DM2S0, HIGH); digitalWrite(DM2S1, LOW);break;

            case 7 : Serial.println("Gain1 and Low pass filter selected"); digitalWrite(DM1S0, LOW); digitalWrite(DM1S1, LOW); digitalWrite(DM2S0, LOW); digitalWrite(DM2S1, LOW);break;

            case 8 : Serial.println("Gain1 and High pass filter selected"); digitalWrite(DM1S0, LOW); digitalWrite(DM1S1, LOW); digitalWrite(DM2S0, LOW); digitalWrite(DM2S1, HIGH);break;

            case 9 : Serial.println("Gain1 and Band pass filter selected"); digitalWrite(DM1S0, LOW); digitalWrite(DM1S1, LOW); digitalWrite(DM2S0, HIGH); digitalWrite(DM2S1, LOW);break;

            case 10 : Serial.println("Gain2 and Low pass filter selected"); digitalWrite(DM1S0, LOW); digitalWrite(DM1S1, HIGH); digitalWrite(DM2S0, LOW); digitalWrite(DM2S1, LOW);break;

            case 11 : Serial.println("Gain2 and High pass filter selected"); digitalWrite(DM1S0, LOW); digitalWrite(DM1S1, HIGH); digitalWrite(DM2S0, LOW); digitalWrite(DM2S1, HIGH);break;

            case 12 : Serial.println("Gain2 and Band pass filter selected"); digitalWrite(DM1S0, LOW); digitalWrite(DM1S1, HIGH); digitalWrite(DM2S0, HIGH); digitalWrite(DM2S1, LOW);break;

            case 13 : Serial.println("Gain3 and Low pass filter selected"); digitalWrite(DM1S0, HIGH); digitalWrite(DM1S1, LOW); digitalWrite(DM2S0, LOW); digitalWrite(DM2S1, LOW);break;

            case 14 : Serial.println("Gain3 and High pass filter selected"); digitalWrite(DM1S0, HIGH); digitalWrite(DM1S1, LOW); digitalWrite(DM2S0, LOW); digitalWrite(DM2S1, HIGH);break;

            case 15 : Serial.println("Gain3 and Band pass filter selected"); digitalWrite(DM1S0, HIGH); digitalWrite(DM1S1, LOW); digitalWrite(DM2S0, HIGH); digitalWrite(DM2S1, LOW);break;

            case 16 : Serial.println("No gain and no filter selected"); digitalWrite(DM1S0, HIGH); digitalWrite(DM1S1, HIGH); digitalWrite(DM2S0, HIGH); digitalWrite(DM2S1, HIGH);break;
            
            default   : Serial.println(" Invaild Choice "); break;
        }
}


void loop() {
  
  
}





// if (bitRead(y,4) == 0 && bitRead(y,3) == 0 && bitRead(y,2) == 0 && bitRead(y,1) == 0 ){
//  
//    Serial.println("Amplifier 1 selected ");
//              digitalWrite(DM1S1, LOW);
//              digitalWrite(DM1S0, LOW);
//              digitalWrite(DM2S1, HIGH);
//              digitalWrite(DM2S0, HIGH);
// }
// else if (bitRead(y,4) == 0 && bitRead(y,3) == 0 && bitRead(y,2) == 0 && bitRead(y,1) == 1 ){
//  
//  Serial.println("Amplifier 2 selected ");
//              digitalWrite(DM1S2, LOW);
//              digitalWrite(DM1S1, LOW);
//              digitalWrite(DM1S0, HIGH);
//              digitalWrite(DM2S1, HIGH);
//              digitalWrite(DM2S0, HIGH);
//  
// }
// else if (bitRead(y,4) == 0 && bitRead(y,3) == 0 && bitRead(y,2) == 1 && bitRead(y,1) == 0 ){
//  
//  Serial.println("Filter 1 selected ");
//              digitalWrite(DM1S2, LOW);
//              digitalWrite(DM1S1, HIGH);
//              digitalWrite(DM1S0, LOW);
//  
// }
// else if (bitRead(y,4) == 0 && bitRead(y,3) == 0 && bitRead(y,2) == 1 && bitRead(y,1) == 1 ){
//  
//  Serial.println("Filter 2 selected ");
//              digitalWrite(DM1S2, LOW);
//              digitalWrite(DM1S1, HIGH);
//              digitalWrite(DM1S0, HIGH);
//  
// } 
//else if (bitRead(y,4) == 0 && bitRead(y,3) == 1 && bitRead(y,2) == 0 && bitRead(y,1) == 0 ){
//  
//  Serial.println("Direct sensor o/p selected ");
//              digitalWrite(DM1S2, HIGH);
//              digitalWrite(DM1S1, LOW);
//              digitalWrite(DM1S0, LOW);
//  
// }
// else if (bitRead(y,4) == 0 && bitRead(y,3) == 1 && bitRead(y,2) == 0 && bitRead(y,1) == 1 ){
//  
//  Serial.println("A1F1 o/p selected ");
//              digitalWrite(DM1S2, LOW);
//              digitalWrite(DM1S1, LOW);
//              digitalWrite(DM1S0, LOW);
//              digitalWrite(DM2S1, LOW);
//              digitalWrite(DM2S0, LOW);
//  
// }
//  else if (bitRead(y,4) == 0 && bitRead(y,3) == 1 && bitRead(y,2) == 1 && bitRead(y,1) == 0 ){
//  
//  Serial.println("A1F2 o/p selected ");
//              digitalWrite(DM1S2, LOW);
//              digitalWrite(DM1S1, LOW);
//              digitalWrite(DM1S0, LOW);
//              digitalWrite(DM2S1, LOW);
//              digitalWrite(DM2S0, HIGH);
//  
// }
//  else if (bitRead(y,4) == 0 && bitRead(y,3) == 1 && bitRead(y,2) == 1 && bitRead(y,1) == 1 ){
//  
//  Serial.println("A2F1 o/p selected ");
//              digitalWrite(DM1S2, LOW);
//              digitalWrite(DM1S1, LOW);
//              digitalWrite(DM1S0, HIGH);
//              digitalWrite(DM2S1, LOW);
//              digitalWrite(DM2S0, LOW);
//  
// }
// else if (bitRead(y,4) == 1 && bitRead(y,3) == 0 && bitRead(y,2) == 0 && bitRead(y,1) == 0 ){
//  
//  Serial.println("A2F2 o/p selected ");
//              digitalWrite(DM1S2, LOW);
//              digitalWrite(DM1S1, LOW);
//              digitalWrite(DM1S0, HIGH);
//              digitalWrite(DM2S1, LOW);
//              digitalWrite(DM2S0, HIGH);
//  
// }
//
// delay(1000);
//}
//void receiveEvent(int howMany) {
//  while (Wire.available()) { // loop through all but the last
//    y = Wire.read(); // read control data byte 
//     Serial.println(" control data byte: ");
//    Serial.println(y);
//    //Serial.print(c);         // print the character
//  }
//      receive byte as an integer

 
 
    
      
   /* if (bitRead(y,2) == 0){
      Serial.println("Amplifier only");

            if(bitRead(y,1) == 0){
              Serial.println("Amplifier1 selected");
              digitalWrite(DM1S0, LOW);
              digitalWrite(DM1S1, LOW);
              digitalWrite(DM1S2, LOW);
              digitalWrite(DM2S0, HIGH);
              digitalWrite(DM2S1, HIGH);
          }
            else if (bitRead(y,1) == 1){
              Serial.println("Amplifier2 selected");  
              digitalWrite(DM1S0, HIGH);
              digitalWrite(DM1S1, LOW);              
              digitalWrite(DM1S2, LOW);
              digitalWrite(DM2S0, HIGH);
              digitalWrite(DM2S1, HIGH);
            }
            else 
            { // direct output to ADC
              digitalWrite(DM1S0, LOW);
              digitalWrite(DM1S1, LOW);
              digitalWrite(DM1S2, HIGH); }  
              
    }
    else {
      Serial.println("Filter only");
            if(bitRead(y,1) == 0){
              Serial.println("Filter1 selected");
              digitalWrite(DM1S0, LOW);
              digitalWrite(DM1S1, HIGH);
              digitalWrite(DM1S2, LOW); 
          }
            else if(bitRead(y,1) == 1) {
              Serial.println("Filter2 selected");
              digitalWrite(DM1S0, HIGH);
              digitalWrite(DM1S1, HIGH);
              digitalWrite(DM1S2, LOW);                
            }
            else 
            { // direct output to ADC
               digitalWrite(DM1S0, LOW);
              digitalWrite(DM1S1, LOW);
              digitalWrite(DM1S2, HIGH);
            }
    }
                                       
  }
  else if (bitRead(y,3) == 1){
     Serial.println("Amplifier and Filter selected");
     //int ampOp = analogRead(analogRdAmpOp);
          
  if ( (y&B00000010)== 2)
  {                         
    Serial.println("Amplifier and Filter1 selected");
              digitalWrite(DM1S0, LOW);
              digitalWrite(DM1S1, LOW);
              digitalWrite(DM1S2, HIGH);                                 
  }
  else if ( (y&B00000100)== 4)
   {
    Serial.println("Amplifier and Filter2 selected");
    analogWrite(analogWrtAmp2, val);
    analogWrite(analogWrtFilter1, ampOp);                  
   }
   else if ((y&00000110)==6)
   {
    Serial.println("Amplifier2 and Filter2 selected");                  
    analogWrite(analogWrtAmp2, val);
    analogWrite(analogWrtFilter2, ampOp); 
   }
   else 
   {
    Serial.println("Amplifier1 and Filter1 selected"); 
    analogWrite(analogWrtAmp1, val);
    analogWrite(analogWrtFilter1, ampOp);                  
   }
  }*/
 
  
//}
/*
//// function that executes whenever data is received from master
//// this function is registered as an event, see setup()




char ampFilterSelect(int y){
  char AF = 0;
  Serial.println("In AF select");

  if ( (y&B00000010)== 2)
  {                         // A = amplifier 2 , F = filter1, G = filter2, B= amplifier1
    AF = 'A'; 
  }
  else if ( (y&B00000100)== 4)
   {
    AF = 'F'; 
   }
   else if ((y&00000110)==6)
   {
    AF = 'G';
   }
   else 
   {
    AF = 'B';
   }
   return AF;
  }

  
void AmpSel (char sAF){

  switch(sAF){
    case 'A':
              analogWrite(analogWrtAmp2, val);

    case 'B':
              analogWrite(analogWrtAmp1, val);
    default:
            Serial.println("Invalid Choice");
  }
  
}

void FilterSel (char sAF){

  switch(sAF){
    case 'F':
              analogWrite(analogWrtFilter1, val);          
    
    case 'G':
              analogWrite(analogWrtFilter2, val);

    default:
            Serial.println("Invalid Choice");
  }
  
}*/

//}
