//********************************************************************************************************************************************************
void reverse(int x)
{ 
        mstop();
        read_front_uts();
        if (df!=x)
        {
          go_backwards();
          while (1)
          {
            read_front_uts();
            if (df==x)
            {
             return ;
            }
          }
        }
}  
//********************************************************************************************************************************************************

void mstop()
{
Serial.println("STOP ");
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE);
motor4.run(RELEASE);
}
//*************************************************************************************************************************************************************
void rotet()
{
    motor1.setSpeed(225);
    motor1.run(BACKWARD);
    motor2.setSpeed(225);
    motor2.run(BACKWARD);
    motor3.setSpeed(225);
    motor3.run(FORWARD);
    motor4.setSpeed(225);
    motor4.run(FORWARD);
    while(1)
    {
      readirsensors();
      if (right==LOW &&left==LOW && mid==LOW && right2==LOW &&left2==LOW)
      {
        break;
      }
    }
    while(1)
    {
      read_ir_mid();
      if (mid == HIGH)
      {return;}
      //else if(left==HIGH){turn_left();return;}
    }
}
//***********************************************************************************************************************************************************
void go_left()
{  
    motor1.setSpeed(i);
    motor1.run(FORWARD);
    motor2.setSpeed(i);
    motor2.run(FORWARD);
    motor3.setSpeed(j);
    motor3.run(BACKWARD);
    motor4.setSpeed(j);
    motor4.run(BACKWARD);
}
//***********************************************************************************************************************************************************
void go_right()
{
    motor1.setSpeed(j);
    motor1.run(BACKWARD);
    motor2.setSpeed(j);
    motor2.run(BACKWARD);
    motor3.setSpeed(i);
    motor3.run(FORWARD);
    motor4.setSpeed(i);
    motor4.run(FORWARD);
}
//***********************************************************************************************************************************************************
void go_forward()
{
  motor1.setSpeed(j);
  motor3.setSpeed(j);
  motor2.setSpeed(j);
  motor4.setSpeed(j);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void go_backwards()
{
  motor1.setSpeed(j);
  motor3.setSpeed(j);
  motor2.setSpeed(j);
  motor4.setSpeed(j);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
