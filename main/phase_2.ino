/*** PHASE FOR T - JUNCTION LINE **/

void phase_2_()
{
  mstop();
  delay(3000);
  reverse(20);
  rotet();
  //mstop();
  movebot2();
  return;
}
//****************************************************************************************************************************************************************
 void movebot2()
{
  while (1)
  { 
          movebot2_start:
          readirsensors();
           if ( mid == HIGH && left==LOW && right==LOW)
             {
              move_forward();
              goto movebot2_start;
             } 
           else if ((left2 == LOW)&&(left == HIGH) && (mid == LOW) && (right == LOW)&&(right2 == LOW))//move left
              {
               go_left();
               goto movebot2_start;
              } 
          
           else if ((left2 == LOW)&&(left == LOW) && (mid == LOW) && (right == HIGH)&&(right2 == LOW))//move right
              {
                go_right();
                goto movebot2_start;   
              }
           else if ((left2 == HIGH)&&(left == LOW) && (mid == LOW) && (right == LOW)&&(right2 == LOW))//move left
              {
               turn_left();
               goto movebot2_start;
              } 
           else if ((left2 == LOW)&&(left == LOW) && (mid == LOW) && (right == LOW)&&(right2 == HIGH))//move left
              {
               turn_right();
               goto movebot2_start;
              } 
           else if (((left2 == LOW) ||(left == LOW)) && ((mid == HIGH) || (right == HIGH))&&(right2 == HIGH))
              {
                mstop();
                flag =3;
                return; 
              }
   }
        
}
//********************************************************************************************************************************************************
void backwards()
{ 
  motor1.setSpeed(j);
  motor3.setSpeed(j);
  motor2.setSpeed(j);
  motor4.setSpeed(j);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD); 
  while(1)
  {
  readirsensors();
   if ((mid == LOW) ||(left==HIGH && right==HIGH))//move left
      {
       return;
      } 
  }
}
//***************************************************************************************************************************************************************************************************
