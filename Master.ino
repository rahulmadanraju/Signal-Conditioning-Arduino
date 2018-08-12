@@ -0,0 +1,344 @@
#include<Wire.h>

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Wire.begin();
}

int CTC1 =7;
int CTC2 =8;
int CTC3 =9;

int AC1 =1;
int AC2 =2;
int AC3 =3;

int VD1 =4;
int VD2 =5;
int VD3 =6;

int noSelGF =16;
int G1 =1;
int G2 =2;
int G3 =3;
int F1 =4;
int F2 =5;
int F3 =6;
int G1F1 =7;
int G1F2 =8;
int G1F3 =9;
int G2F1 =10;
int G2F2 =11;
int G2F3 =12;
int G3F1 =13;
int G3F2 =14;
int G3F3 =15;

int control_value = 0;


void loop() {
  // put your main code here, to run repeatedly:

while (Serial.available() == 8){ // while (Serial.available() >3 )

  char b1= Serial.read();
      Serial.print("byte 1 read: ");
      Serial.println(b1);
  if (b1 == 's' || b1 == 'S'){ 
       
  char b2 = Serial.read();  
      Serial.print("byte 2 read: ");
      Serial.println(b2);
  
  switch(b2){
            case '1' : Serial.println("sensor1 selected"); break;
            case '2' : Serial.println("sensor2 selected"); break;
            default: Serial.println(" Invaild Choice sensor "); control_value = 1; break;
        }
  }
  else {
    control_value = 1;
    Serial.println(" Invaild input byte 1");
  }

  
if( control_value == 0){
  // if previous input is right then continue with reading 3rd byte
  int check_s1 = 0;
    Wire.beginTransmission(9); // Begin transmission to slave 1
  
  char b3 = Serial.read();  
      Serial.print("byte 3 read: ");
      Serial.println(b3);
   char b4 = Serial.read();
          Serial.print("byte 4  read: ");
          Serial.println(b4);    
  if (b3 == 'c' || b3 == 'C'){
        Serial.println("CTC selected");
         switch(b4){
            
            case '1' : Serial.println("c1 selected"); Wire.write(CTC1); check_s1 = 1; break;
            case '2' : Serial.println("c2 selected"); Wire.write(CTC2); check_s1 = 1;break;
            case '3' : Serial.println("c3 selected"); Wire.write(CTC3); check_s1 = 1;break;
            default: Serial.println(" Invalid Choice C "); control_value = 1; break;
        }
      }
        else if (b3 == 'v' || b3 == 'V'){
        Serial.println("VD selected");
        
          switch(b4){
            
            case '1' : Serial.println("v1 selected"); Wire.write(VD1);check_s1 = 1; break;
            case '2' : Serial.println("v2 selected"); Wire.write(VD2);check_s1 = 1; break;
            case '3' : Serial.println("v3 selected"); Wire.write(VD3);check_s1 = 1; break;
            default: Serial.println(" Invalid Choice V "); control_value = 1; break;
          }
        }
          else if (b3 == 'a' || b3 == 'A'){
          Serial.println("AC bridge selected");
          switch(b4){
            
            case '1' : Serial.println("A1 selected"); Wire.write(AC1);check_s1 = 1; break;
            case '2' : Serial.println("A2 selected"); Wire.write(AC2);check_s1 = 1; break;
            case '3' : Serial.println("A3 selected"); Wire.write(AC3);check_s1 = 1; break;
            default: Serial.println(" Invalid Choice A "); control_value = 1; break;
            }
          }

          else {
            Serial.println(" Invalid Choice; choose byte 3 : C/V/A ");
            control_value = 1;
            }

             Wire.endTransmission(); // End transmission to slave 1

             if (check_s1 == 1){
      Serial.println("Slave 1 successful transmission");
     }
     else{
      Serial.println("Slave 1 unsuccessful transmission");
     }
}


if( control_value == 0){
  // if bytes 1,2,3,4 are correct (control_value = 0) then continue  
  
     String gainFilterSel = String ("");
        
    char b5 = Serial.read();  
      Serial.print("byte 5 read: ");
      Serial.println(b5);
      char b6 = Serial.read();
          Serial.print("byte 6  read: ");
          Serial.println(b6);
      
      gainFilterSel = gainFilterSel + b5 + b6;      
      
      if (b5 == 'g' || b5 == 'G'){
        Serial.println("Gain selected");
          switch(b6){
            
            case '1' : Serial.println(" g10 selected"); break;
            case '2' : Serial.println(" g100 selected"); break;
            case '3' : Serial.println(" g500 selected"); break;
            default: Serial.println(" Invalid Choice G "); break;
        }
      }
    else if (b5 == '0' || b5 == '0'){
      Serial.println(" No gain selected");
    }
       char b7 = Serial.read();
      Serial.print("byte 7 read: ");
      Serial.println(b7);
      char b8 = Serial.read();
          Serial.print("byte 8 read: ");
          Serial.println(b8);

     gainFilterSel = gainFilterSel + b7 + b8; 
          
     if (b7 == 'f' || b7 == 'F'){
        Serial.println("Filter selected");
        switch(b8){
            
            case '1' : Serial.println("LP selected"); break;
            case '2' : Serial.println("HP selected"); break;
            case '3' : Serial.println("BP selected"); break;
            default: Serial.println(" Invalid Choice F "); break;
          }
        }
    else if (b7 == '0' || b7 == '0'){
      Serial.println(" No filter selected");
    }


    gainFilterSel.toUpperCase();
    Serial.println(gainFilterSel);
    int check = 0;
  Wire.beginTransmission(10); // Begin transmission with slave 2

  if (gainFilterSel.equals("0000")){
    Wire.write(noSelGF);
    check = 1;
  }
  else if (gainFilterSel.equals("G100")){
    Wire.write(G1);
    check = 1;
  }
  else if (gainFilterSel.equals("G200")){
    Wire.write(G2);
    check = 1;
  }
  else if (gainFilterSel.equals("G300")){
    Wire.write(G3);
    check = 1;
  }
  else if (gainFilterSel.equals("00F1")){
    Wire.write(F1);
    check = 1;
  }
  else if (gainFilterSel.equals("00F2")){
    Wire.write(F2);
    check = 1;
  }
  else if (gainFilterSel.equals("00F3")){
    Wire.write(F3);
    check = 1;
  }
  else if (gainFilterSel.equals("G1F1")){
    Wire.write(G1F1);
    check = 1;
  }
  else if (gainFilterSel.equals("G1F2")){
    Wire.write(G1F2);
    check = 1;
  }
  else if (gainFilterSel.equals("G1F3")){
    Wire.write(G1F3);
    check = 1;
  }
  else if (gainFilterSel.equals("G2F1")){
    Wire.write(G2F1);
    check = 1;
  }
  else if (gainFilterSel.equals("G2F2")){
    Wire.write(G2F2);
    check = 1;
  }
  else if (gainFilterSel.equals("G2F3")){
    Wire.write(G2F3);
    check = 1;
  }
  else if (gainFilterSel.equals("G3F1")){
    Wire.write(G3F1);
    check = 1;
  }
  else if (gainFilterSel.equals("G3F2")){
    Wire.write(G3F2);
    check = 1;
  }
  else if (gainFilterSel.equals("G3F3")){
    Wire.write(G3F3);
    check = 1;
  }
  else {
    Serial.println(" gain Filter selection not transmitted");
    }

if (check == 1){
  Serial.println("Slave 2 transmission successfull");
}

    Wire.endTransmission(); // end transmission slave 2
  
}

    while(Serial.available()){

      Serial.read(); // remove all extra data from buffer
     }


      
}

}







/* // read string from serial port and display

Wire.beginTransmission(5);
while(Serial.available()<5){
  c1 = Serial.readString();
  Serial.print(c1);
  }

// Wire Lib need array of characters not string
char buffer[4];
 c1.toCharArray(buffer,4);
Wire.write(buffer);
Wire.endTransmission();  
}*/

/*while(Serial.available()){
c1 = Serial.read();
}

Wire.beginTransmission(5);
if (c1== 'H'){
  Wire.write('H');
    }
if (c1== 'L'){
  Wire.write('L');
    }
 
Wire.endTransmission();

delay(1000);

Wire.beginTransmission(6);
if (c1== 'H'){
  Wire.write('H');
    }
if (c1== 'L'){
  Wire.write('L');
    }
 
Wire.endTransmission();
  
}*/

/*while(Serial.available()>1){

  char c1 = Serial.read();
  Serial.print("Read byte 1 ");
  Serial.println(c1);
  if (c1== 'H'){
    char c2 = Serial.read();
    Serial.print("Read byte 2 ");
    Serial.println(c2);
     }
     while(Serial.available()){

      Serial.read(); // remove all extra data from buffer
     }
  
     
  }
} */








