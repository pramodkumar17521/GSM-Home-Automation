// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 rtc;
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
#include <SimpleDHT.h>
int pinDHT11 = 8;
SimpleDHT11 dht11(pinDHT11);
int temp1=23;
int hum1=20;
String temps="26";
String hums="43";
int s1=0;
int s2=0;
int s3=0;
int s4=0;
  byte temp = 26;
  byte hum = 43;
String incomingString ="";
String phone ="";
String admin ="";
String mem1 ="";
String mem2 ="";
int startIndex = 0;
int startIndexi = 0;
int endIndex = 0;
 int startIndexl=0;
char ls[4]= {'L', 'L', 'L', 'L'};
char ps[4]= {'L', 'L','L', 'L'};
char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
#include <LiquidCrystal.h>
int led1 = 9;
int led2 = 10;
int led3 = 11;
int led4 = 12;
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 6, en = 5, d4 = 7, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void print_d();
 void print_s();
void setup () {
  Serial.begin(9600);
lcd.begin(16,2);
lcd.clear();
   lcd.setCursor(0, 0);
  lcd.print("Circuit Maker");
  delay(500);
   pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
   pinMode(A0, INPUT);
   pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
 digitalWrite(led1, LOW); 
 digitalWrite(led2, LOW);
   digitalWrite(led3, LOW);
   digitalWrite(led4, LOW);
   
 admin =  "+919887855307";
 mem1 = "+918209026502";
 mem2 = "+919887855307";
   
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
   //lcd.print("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // lcd.print("RTC not Running");
  }
// rtc.adjust(DateTime(2019, 03, 06, 00, 52, 30));
  /* int err = SimpleDHTErrSuccess;
  while ((err = dht11.read(&temp, &hum, NULL)) != SimpleDHTErrSuccess)
  { lcd.clear(); 
    lcd.print("dht error");
   Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  } 
    String hums= (String)hum;
    String temps= (String)temp;
    Serial.println("\ntemprature = \""+temps+"C\"\n humidity = \""+hums+"%\"\r"); */
  /*  Serial.println(admin);
    Serial.print("**");
    Serial.println(mem1);
    Serial.println(mem2);*/
  print_s();
  delay(2000);
  print_d();
  delay(500);
  //--Start: Send SMS --
phone= "8209026502";
  Serial.println("AT+CMGF=1\r");    

  delay(1000);



  //Serial.print("AT+CMGD=1,4\r");  // Deletes all SMS saved in SIM memory

  //Serial.println("AT+CMGDA=\""); 

  //Serial.println("DEL ALL\"");

  
  delay(1000);

  Serial.println("AT+CMGS=\""+admin+"\"\r");    //Number to which you want to send the sms



  delay(1000);

  Serial.println("Test SMS - Hello Circuit Makers....\r");   //The text of the message to be sent

  delay(1000);

  Serial.write(0x1A);

  delay(1000);


 // Serial.flush();
 // Serial.print("[2J");

  Serial.println("AT+CNMI=2,2,0,0,0\r"); 

  delay(1000);
 // phone= "";
 //lcd.print("setup over");
}

void loop () { 
  ///////////
   /* int err = SimpleDHTErrSuccess;
  while ((err = dht11.read(&temp, &hum, NULL)) != SimpleDHTErrSuccess)
  { lcd.clear(); 
    lcd.print("dht error");
    Serial.print("Read DHT11 failed, err="); Serial.println(err);//delay(1000);
    return;
  } */
   //Serial.println("\nin looopppp");
  // print the string when a newline arrives:

  if (stringComplete && inputString!="") 
    { print_s();
    delay(500);
    Serial.print("AT+CMGL\r");
    //   Serial.println("\ndisplay");
    inputString.toLowerCase();

// ................................................

    if(inputString=="@light1 on#" )

    {

      digitalWrite(led1, HIGH);
      int s1=digitalRead(A0); 
      Serial.println("\nlight1 on");
     // lcd.write("led1 ON");
      
  Serial.println("AT+CMGF=1\r");    
  delay(1000);
  Serial.println("AT+CMGS=\""+phone+"\"\r"); 
      delay(1000);
       Serial.println("Light1 on\r");   
  delay(1000);
  Serial.write(0x1A);
  delay(1000);
    Serial.flush();
  Serial.print("[2J");
  Serial.print("\n");
   phone ="";
  if(s1==HIGH)
  { char temp =ps[0];
         ps[0]='H';
         ls[0]=temp;
    }
    }

    else if(inputString=="@light1 off#")


    {
      
      digitalWrite(led1, LOW); 
        Serial.println("\nlight1 off");
       s1 = digitalRead(A0);
       // lcd.write("led1 OFF");
        
  Serial.println("AT+CMGF=1\r");    
  delay(1000);
  Serial.println("AT+CMGS=\""+phone+"\"\r"); 
      delay(1000);
       Serial.println("Light1 off\r");   
  delay(1000);
  Serial.write(0x1A);
  delay(1000);
  Serial.flush();
  Serial.print("[2J");
  Serial.print("\n");
          delay(1000);
           phone ="";
       if(s1==LOW)
  { char  temp =ps[0];
         ps[0]='L';
         ls[0]=temp;
    }
    }

//....................................................

  else if(inputString=="@fan2 on#")
    {

      digitalWrite(led4, HIGH); 
      int s4= digitalRead(A3);
      Serial.println("\nfan2 on");
       Serial.println("AT+CMGF=1\r");    
  delay(1000);
  Serial.println("AT+CMGS=\""+phone+"\"\r"); 
      delay(1000);
       Serial.println("fan2 on\r");   
  delay(1000);
  Serial.write(0x1A);
  delay(1000);   
  Serial.flush();
  Serial.print("[2J");
  Serial.print("\n");
   phone ="";
     // lcd.write("led4 ON");
   if(s4==HIGH)
  {char temp =ps[3];
         ps[3]='H';
         ls[3]=temp;
    }
    }

    else if(inputString=="@fan2 off#")
  {
      digitalWrite(led4, LOW);
       s4= digitalRead(A3);
        Serial.println("fan2 off");
          delay(1000);
          
  Serial.println("AT+CMGF=1\r");    
  delay(1000);
  Serial.println("AT+CMGS=\""+phone+"\"\r"); 
      delay(1000);
       Serial.println("fan2 off\r");   
  delay(1000);
  Serial.write(0x1A);
  delay(1000);
  
  Serial.flush();
  Serial.print("[2J");
   phone ="";
   if(s4==LOW)
  { char temp =ps[3];
         ps[3]='L';
         ls[3]=temp;
    }
    }
    //................................................
    else if(inputString=="@light2 on#")
    {
      digitalWrite(led2, HIGH);
     s2= digitalRead(A1); 
      Serial.println("\nlight2 on");
     // lcd.write("led2 ON");
      
  Serial.println("AT+CMGF=1\r");    
  delay(1000);
  Serial.println("AT+CMGS=\""+phone+"\"\r"); 
      delay(1000);
       Serial.println("Light2 on\r");   
  delay(1000);
  Serial.write(0x1A);
  delay(1000);
  Serial.flush();
  Serial.print("[2J");  
      delay(1000);
       phone ="";
       if(s2==HIGH)
  { char temp =ps[1];
         ps[1]='H';
         ls[1]=temp;
    }
    }

    else if(inputString=="@light2 off#") 

    {
       
      digitalWrite(led2, LOW); 
      s2=digitalRead(A1);
        Serial.println("\nlight2 off");
       // lcd.write("led2 OFF");
  Serial.println("AT+CMGF=1\r");    
  delay(1000);
  Serial.println("AT+CMGS=\""+phone+"\"\r"); 
      delay(1000);
       Serial.println("Light2 off\r");   
  delay(1000);
  Serial.write(0x1A);
  delay(1000);
  Serial.flush();
  Serial.print("[2J");
  Serial.print("\n");
                 delay(1000);
          phone ="";
          if(s2==LOW)
  { char temp =ps[1];
         ps[1]='L';
         ls[1]=temp;
    }        
    }
//............................................
 else if(inputString=="@fan1 on#")
    {
      digitalWrite(led3, HIGH);
      s3= digitalRead(A2); 
      Serial.println("fan1 on");
      
  Serial.println("AT+CMGF=1\r");    
  delay(1000);
  Serial.println("AT+CMGS=\""+phone+"\"\r"); 
      delay(1000);
       Serial.println("fan1 is on\r");   
  delay(1000);
  Serial.write(0x1A);
  delay(1000);
  Serial.flush();
  Serial.print("[2J");
  Serial.print("\n");
        delay(1000);
         phone ="";
         if(s3==HIGH)
  { char temp =ps[2];
         ps[2]='H';
         ls[2]=temp;
    }
         
    }

    else if(inputString=="@fan1 off#")
    {
      digitalWrite(led3, LOW); 
      s3= digitalRead(A2);
        Serial.println("fan1 off");
       // lcd.write("\nled3 OFF");
        
  Serial.println("AT+CMGF=1\r");    
  delay(1000);
  Serial.println("AT+CMGS=\""+phone+"\"\r"); 
      delay(1000);
       Serial.println("fan1 off\r");   
  delay(1000);
  Serial.write(0x1A);
  delay(1000);
  Serial.flush();
  Serial.print("[2J");
  Serial.print("\n");
          delay(1000);
          phone ="";
          if(s3==LOW)
  { char temp =ps[2];
         ps[2]='L';
         ls[2]=temp;
    }
    }
     else if(inputString=="@all on#")
    {     
      digitalWrite(led1, HIGH);      
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
        Serial.println("all on");
       // lcd.write("\nled3 OFF");
         s1= digitalRead(A0);
         s2= digitalRead(A1); 
         s3= digitalRead(A2);
          s4= digitalRead(A3);        
  Serial.println("AT+CMGF=1\r");    
  delay(1000);
  Serial.println("AT+CMGS=\""+phone+"\"\r"); 
      delay(1000);
       Serial.println("all on\r");   
  delay(1000);
  Serial.write(0x1A);
  delay(1000);
  Serial.flush();
  Serial.print("[2J");
  Serial.print("\n");
          delay(1000);
          phone ="";
       if(s3==HIGH && s2==HIGH && s1==HIGH && s4==HIGH)
      { for(int i=0; i<4; i++)
         {  char temp =ps[i];
         ps[i]='H';
         ls[i]=temp;
          }
       }
          
    }
 else if(inputString=="@all off#")

    {

      digitalWrite(led1, LOW); 
       digitalWrite(led2, LOW); 
        digitalWrite(led3, LOW);   
      s1= digitalRead(A0);
         s2= digitalRead(A1); 
         s3= digitalRead(A2);
          s4= digitalRead(A3);
         digitalWrite(led4, LOW);
          
        Serial.println("all off");
       // lcd.write("\nall OFF");
        
  Serial.println("AT+CMGF=1\r");    
  delay(1000);
  Serial.println("AT+CMGS=\""+phone+"\"\r"); 
      delay(1000);
       Serial.println("all off\r");   
  delay(1000);
  Serial.write(0x1A);
  delay(1000);
  Serial.flush();
  Serial.print("[2J");
  Serial.print("\n");
          delay(1000);
          phone ="";
           if(s3==LOW && s2==LOW && s1==LOW && s4==LOW)
      { for(int i=0; i<4; i++)
         {  char temp =ps[i];
         ps[i]='L';
         ls[i]=temp;
          }
       }
    }
   else if(inputString=="@temp#")

    { /* dht11.read(&temp, &hum, NULL);
     delay(500);
    String hums= (String)hum;
     String temps= (String)temp;
    */
      
     // lcd.write("led1 ON");
      
  Serial.println("AT+CMGF=1\r");    
  delay(1000);
  Serial.println("AT+CMGS=\""+phone+"\"\r"); 
      delay(1000);
       Serial.println("\ntemprature = \""+temps+"C\"\n humidity = \""+hums+"%\"\r");
  delay(1000);
  Serial.write(0x1A);
  delay(1000);
    Serial.flush();
  Serial.print("[2J");
  Serial.print("\n");
   phone ="";
  
    }

//...........................................
   //Serial.println("AT+CMGDA=\""); 

   //Serial.println("DEL ALL\""); // To Delete Messages from SIM Memory
    print_s();
   delay(1000);

  // clear the string:
   
   inputString = "";

   stringComplete = false;

  }
//Serial.println("end of loop");
}

void serialEvent() 
{   Serial.println("\n***in event***");
    if(stringComplete == false)
   {  incomingString = Serial.readString();
        if(incomingString!="")
        {Serial.println(incomingString);
          startIndex = incomingString.indexOf("@");
          endIndex = incomingString.indexOf("#");
                  
         startIndexi = incomingString.indexOf("\"");
         startIndexl= startIndexi+1;
         startIndexl = incomingString.indexOf("\"",startIndexl);   
          phone = incomingString.substring(startIndexi+1,startIndexl);
           
           delay(1000);
          if(startIndex>0 && endIndex>0)
          { inputString = incomingString.substring(startIndex,endIndex+1);
            stringComplete = true;
             //Serial.println(inputString);
             Serial.println("****phone no is****");
             Serial.println(phone);
            // char getch();
          }
 
 }
}
//print_d();
}

 void print_s()
 { 
  lcd.clear();  
 lcd.setCursor(0,0);
 lcd.print("CS ");
  //lcd.print("L1");
   lcd.print(ps[0]);
      lcd.print("/");
     lcd.print(ps[1]);
     lcd.print("/");
   lcd.print(ps[2]);
      lcd.print("/");
     lcd.print(ps[3]);
     lcd.setCursor(0,2);
 lcd.print("LS ");
  //lcd.print("L1=");
   lcd.print(ls[0]);
      lcd.print("/");
     lcd.print(ls[1]);
     lcd.print("/");
   lcd.print(ls[2]);
      lcd.print("/");
     lcd.print(ls[3]);
 }
   //lcd.print(0);
 //   lcd.print("/");
    void print_d()
    { 
     ///delay(2500);
     lcd.clear();

 
    DateTime now = rtc.now();
   
    
  // delay(3000);
 
// lcd.leftToRight();
   lcd.setCursor(10,0);
   hum1= (int)hum;
    temp1= (int)temp;
     lcd.print("H=");
 lcd.print(hum1);
 lcd.print("%");
     lcd.setCursor(13,2);
 lcd.print(temp1);
 lcd.print("C");
 lcd.setCursor(0,0);
 lcd.print(now.day(),DEC);
 //Serial.print("/");
  lcd.print("/");
 lcd.print(now.month(),DEC);
 lcd.print("/");
 
 lcd.print(now.year(),DEC);

 // delay(2500);
  
 
 lcd.setCursor(0,2);
 //lcd.leftToRight();
 
  
  lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
 lcd.print("/");
 lcd.print(now.hour(), DEC);
    lcd.print(':');
    lcd.print(now.minute(), DEC);
    lcd.print(':');
    lcd.print(now.second(), DEC);
    lcd.print(" ");
   
    
    Serial.println();
    } 
