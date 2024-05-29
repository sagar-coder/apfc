void Correction(int x);
void Measure();
#include<LiquidCrystal.h>
#include<math.h>
LiquidCrystal LCD(7,6,5,4,3,2,1);
int R1 = 9;
int R2 = 10;
int R3 = 11;
int R4 = 8;
int ReadDur= 0;
float PF, Angle;
int dur = 0;
int Case = 0;
void setup() {
  // put your setup code here, to run once:

 LCD.begin(16, 2);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(R4, OUTPUT);
  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW);
  digitalWrite(R3, LOW);
  digitalWrite(R4, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  
   
    while(PF<0.95)
    {
    
     Case++;
     if (Case>15)
     {
     break;}
     Correction(Case);
     delay(100);
      Measure();
     delay(500);
   
     if(Angle>20 || PF>0.95)
     break;
     delay(400);
    } 
    
}
void Measure()

 {dur = pulseIn(ReadDur, HIGH);
  Angle = dur * 0.018; //time to angle (in degree) convert
  Angle = Angle-90; // (-90) is for offseting the angle
  PF = cos(Angle*0.0174533); //angle conversion from degree to radian, then PF calcultion

  LCD.setCursor(0,0);  //setCursor(x,y)    x=column  y=row
  LCD.print("Angle = ");
  LCD.print(Angle);
  LCD.setCursor(0,1);
  LCD.print("PF = ");
  LCD.print(PF);
}



  void Correction(int x)
{
  if(x==1)
  {
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
    digitalWrite(R3, LOW);
    digitalWrite(R4, LOW);
  }

  else if(x==2)
  {
  digitalWrite(R1, LOW);
  digitalWrite(R2, HIGH);
  digitalWrite(R3, LOW);
  digitalWrite(R4, LOW);

  }

  else if(x==3)
  {
     digitalWrite(R1, HIGH);
    digitalWrite(R2, HIGH);
    digitalWrite(R3, LOW);
    digitalWrite(R4, LOW);
  }

  else if(x==4)
  {
     digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);
   digitalWrite(R3, HIGH);
    digitalWrite(R4, LOW);
  }

  else if(x==5)
  {
    digitalWrite(R1, HIGH);
   digitalWrite(R2, LOW);
    digitalWrite(R3, HIGH);
   digitalWrite(R4, LOW);
  }

  else if(x==6)
  {
    digitalWrite(R1, LOW);
   digitalWrite(R2, HIGH);
    digitalWrite(R3, HIGH);
    digitalWrite(R4, LOW);
  }

  else if(x==7)
  {
    digitalWrite(R1, HIGH);
    digitalWrite(R2, HIGH);
    digitalWrite(R3, HIGH);
    digitalWrite(R4, LOW);
  }
  else if(x==8)
  {
    digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);
   digitalWrite(R3, LOW);
    digitalWrite(R4, HIGH);
  }
  else if(x==9)
  {
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
    digitalWrite(R3, LOW);
    digitalWrite(R4, HIGH);
  }
  else if(x==10)
  {
    digitalWrite(R1, LOW);
    digitalWrite(R2, HIGH);
    digitalWrite(R3, LOW);
    digitalWrite(R4, HIGH);
  }
  else if(x==11)
  {
    digitalWrite(R1, HIGH);
    digitalWrite(R2, HIGH);
    digitalWrite(R3, LOW);
    digitalWrite(R4, HIGH);
  }
  else if(x==12)
  {
    digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);
    digitalWrite(R3, HIGH);
    digitalWrite(R4, HIGH);
  }
  else if(x==13)
  {
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
    digitalWrite(R3, HIGH);
    digitalWrite(R4, HIGH);
  }
  else if(x==14)
  {
    digitalWrite(R1, LOW);
    digitalWrite(R2, HIGH);
    digitalWrite(R3, HIGH);
    digitalWrite(R4, HIGH);
  }
  else if(x==15)
  {
    digitalWrite(R1, HIGH);
    digitalWrite(R2, HIGH);
    digitalWrite(R3, HIGH);
    digitalWrite(R4, HIGH);
  }
  else
  {
    digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);
    digitalWrite(R3, LOW);
    digitalWrite(R4, LOW);
  } 
}
