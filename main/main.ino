#include<NewPing.h>
#include <AFMotor.h>
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
#define ltrig A0
#define lecho A1 
#define ftrig A2
#define fecho A3
#define rtrig A4
#define recho A5
#define max_distance 600
NewPing fsonar(ftrig,fecho,max_distance);
NewPing rsonar(rtrig,recho,max_distance);
NewPing lsonar(ltrig,lecho,max_distance);
int ledp1= 28;
int ledp2=30;
int ledp3=32; 
int ledp4=34;
int df;
int dr;
int dl;
int irl2=44;
int irr2=42; 
int irr = 40;
int irl = 38; 
int irm = 36; 
int j =200;//backward speed
int i = 200;
int left2;
int right2;
int left; //left ir
int mid;//left ir
int right;//left ir
int flag = 3;
int obstacle_offset = 15;
void setup() 
{
  Serial.begin(9600);
  pinMode(irl,INPUT);
  pinMode(irl2,INPUT);
  pinMode(irr2,INPUT);
  pinMode(irm ,INPUT);
  pinMode(irr,INPUT);
  pinMode(ledp1,OUTPUT);
  pinMode(ledp2,OUTPUT);
  pinMode(ledp3,OUTPUT);
  pinMode(ledp4,OUTPUT);
}

void loop()
{
//  start:
//if (flag==0)
//    { 
           digitalWrite(ledp1,HIGH);
//           phase_1();
//    }
//else if(flag==1)
//    {
          digitalWrite(ledp2,HIGH);
//          phase_2_();
//    }
//else if (flag==3)
//    {
          digitalWrite(ledp3,HIGH);
          phase_3();      
//    }

}
