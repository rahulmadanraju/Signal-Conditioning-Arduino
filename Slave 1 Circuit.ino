@@ -0,0 +1,502 @@
#include <Wire.h>

int M1S0 = 7;
int M1S1 = 8;
int M1S2 = 9;
int M1S3 = 10;

int swtch_int ;

void setup() {
  Wire.begin(9);                // join i2c bus with address #9
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void receiveEvent(int howMany) {   // stores how many bytes its receiving from master 
  while ( Wire.available()) { // loop through all but the last
   swtch_int = Wire.read();    // receive byte as an integer
  Serial.println(swtch_int);         // print the integer
switch(swtch_int){
            case 1 : Serial.println("Sensor1 AC bridge1 selected"); digitalWrite(M1S3, LOW); digitalWrite(M1S2, LOW); digitalWrite(M1S1, LOW); digitalWrite(M1S0, LOW); break;
       
            case 2 : Serial.println("Sensor1 AC bridge2 selected"); digitalWrite(M1S3, LOW); digitalWrite(M1S2, LOW); digitalWrite(M1S1, LOW); digitalWrite(M1S0, HIGH); break;

            case 3 : Serial.println("Sensor1 AC bridge3 selected"); digitalWrite(M1S3, LOW); digitalWrite(M1S2, LOW); digitalWrite(M1S1, HIGH); digitalWrite(M1S0, LOW); break;

            case 4 : Serial.println("Sensor1 Voltage divider1 selected"); digitalWrite(M1S3, LOW); digitalWrite(M1S2, LOW); digitalWrite(M1S1, HIGH); digitalWrite(M1S0, HIGH); break;

            case 5 : Serial.println("Sensor1 Voltage divider2 selected"); digitalWrite(M1S3, LOW); digitalWrite(M1S2, HIGH); digitalWrite(M1S1, LOW); digitalWrite(M1S0, LOW); break;

            case 6 : Serial.println("Sensor1 Voltage divider3 selected"); digitalWrite(M1S3, LOW); digitalWrite(M1S2, HIGH); digitalWrite(M1S1, LOW); digitalWrite(M1S0, HIGH); break;

            case 7 : Serial.println("Sensor1 Charger Transfer1 selected"); digitalWrite(M1S3, LOW); digitalWrite(M1S2, HIGH); digitalWrite(M1S1, HIGH); digitalWrite(M1S0, LOW); break;

            case 8 : Serial.println("Sensor1 Charger Transfer2 selected"); digitalWrite(M1S3, LOW); digitalWrite(M1S2, HIGH); digitalWrite(M1S1, HIGH); digitalWrite(M1S0, HIGH); break;

            case 9 : Serial.println("Sensor1 Charger Transfer3 selected"); digitalWrite(M1S3, HIGH); digitalWrite(M1S2, LOW); digitalWrite(M1S1, LOW); digitalWrite(M1S0, LOW); break;

            case 10 : Serial.println("No circuit selected"); digitalWrite(M1S3, HIGH); digitalWrite(M1S2, LOW); digitalWrite(M1S1, LOW); digitalWrite(M1S0, HIGH); break;
            
            default   : Serial.println(" Invaild Choice "); break;
        
       }
       
}

}
void loop() {

}   
  


//void loop() {
// 
//   Serial.println("call vw select");
//   char sRC = vwSelect(y);
////   Serial.println("call AF select");
////  char sAF = ampFilterSelect(y);
//   Serial.println("call mux control");
//  muxcontrol(sRC,x);
//  //val = analogRead(analogReadPin);     // read the input pin
//  //Serial.println("Analog value: "+val);
//  //analogWrite(analogWrtMstPin, val);
////  if (sAF){3
////    analogWrite(analogWrtSlvPin, val);
////  }
////  else {
////    analogWrite(analogWrtMstPin, val);
////  }
// delay(1000);
//}
//
//// function that executes whenever data is received from master
//// this function is registered as an event, see setup()
//void receiveEvent(int howMany) {
//  while (Wire.available()) { // loop through all but the last
//    x = Wire.read(); // read RC byte as integer 
//    y = Wire.read(); // read control data byte
//    Serial.println(" control data byte: ");
//    Serial.println(y);
//    Serial.println("Select byte Voltage divider circuit: ");
//    Serial.print(x);         // print the character
//  }
//     // receive byte as an integer
//}


//char vwSelect(int y)
//{
//   Serial.println("In vw select");
//  char RC = 0;
//  if (bitRead(y,0)==0)
//  {
//    RC='V';
//  }
//  else //(bitRead(y,0)==1)
//  {
//    RC='W';
//  }
//  return RC;
//}
//
//void muxcontrol(char sRC, int x) {
// Serial.println("In mux control");
//  switch (sRC){
//    case 'V': 
//     Serial.println("vd select");
//          switch(x){
//                     case 0:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     case 1:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     
//                     break;
//                     case 2:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     case 3:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     case 4:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     case 5:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     case 6:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     case 7:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);                     
//                     break;
//                     case 8:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     case 9:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     case 10:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     case 11:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     case 12:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     case 13:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     case 14:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     case 15:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     default: Serial.println("Invalid Choice");
//          }
//          break;
//            
//
// 
//     
//    case 'W': 
//     Serial.println("WH select");
//          switch(x){
//                     case 0:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     case 16:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     
//                     break;
//                     case 32:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     case 48:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     case 64:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     case 80:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     case 96:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     case 112:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);                     
//                     break;
//                     case 128:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     case 144:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     case 160:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     case 176:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     case 192:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     case 208:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     case 224:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     case 240:
//                                r0 = bitRead(x,0); 
//                                r1 = bitRead(x,1); 
//                                r2 = bitRead(x,2); 
//                                r3 = bitRead(x,3);
// 
//                            digitalWrite(2, r0); // For MUX2: s0, s1, s2, s3 = digital pins(2,3,4,5)
//                            digitalWrite(3, r1);
//                            digitalWrite(4, r2);
//                            digitalWrite(5, r3);
//                     break;
//                     default: Serial.println("Invalid Choice");
//          }
//      break;
//
//      default: 
//           Serial.println("Invalid Choice");
//  }
//}

//      for (int count=0; count < 16 ; count++) 
//        {
//          Serial.println("In vd select");  
//        
//            int  bin [] = {0000, 1, 10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111};//list of binary values
//            int x = bin[count]; //channel 5 = 5th element in the bin list -> 101 etc. 
//        
//            int r0 = bitRead(x,0); 
//            int r1 = bitRead(x,1); 
//            int r2 = bitRead(x,2); 
//            int r3 = bitRead(row,3);
// 
//            digitalWrite(2, r0); // For MUX1: s0, s1, s2, s3 = digital pins(2,3,4,5)
//            digitalWrite(3, r1);
//            digitalWrite(4, r2);
//            digitalWrite(5, r3);
//          }



