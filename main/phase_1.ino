/*** PHASE FOR STOP AND GO JUNCTION ****/

void phase_1()
{
  follow_mid_line();
  
}

                                                  /*********************************************************/
                                                  
void follow_mid_line()
{
  move_bot();
  return;
}
                                                 /***********************************************************/
                                                 
 void move_bot()
{
  while (1)
  {
   move_dot_start:
   readirsensors();
   if ((left == HIGH) && (mid == HIGH) && (right == HIGH)&&(right2 == HIGH)&&(left2 == HIGH))//priority to move straight but checking the sensors help to know when first stop is reached
      {
        
           read_ultrasonic();
           if ((df<15) && (dl<15) && (dr<15))//to check if it has reached first stop
                {
                  flag = 3;//this records the first stop
                  return; 
                }
                else
                {
                  move_forward(); 
                  goto move_dot_start;    
                }
      }
      
  else if ((mid == HIGH))
     {
      move_forward();
      goto move_dot_start; 
     } 
   else if ((left2 == LOW)&&(left == HIGH) && (mid == LOW) && (right == LOW)&&(right2 == LOW))//move left
      {
       go_left();
       goto move_dot_start; 
      } 
  
   else if ((left2 == LOW)&&(left == LOW) && (mid == LOW) && (right == HIGH)&&(right2 == LOW))//move right
      {
        go_right(); 
        goto move_dot_start;   
      }
   else if ((left2 == HIGH)&&(left == LOW) && (mid == LOW) && (right == LOW)&&(right2 == LOW))//move left
      {
       turn_left();
       goto move_dot_start; 
      } 
  
   else if ((left2 == LOW)&&(left == LOW) && (mid == LOW) && (right == LOW)&&(right2 == HIGH))//move right
      {
        turn_right();  
        goto move_dot_start;  
      }
  }
        
}
//********************************************************************************************************************************************************
void move_forward()
{ 
  motor1.setSpeed(j);
  motor3.setSpeed(j);
  motor2.setSpeed(j);
  motor4.setSpeed(j);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  while(1)
  {
  readirsensors();
   if ((mid == LOW) ||left==HIGH || right==HIGH||left2==HIGH || right2==HIGH)
      {
       return;
      } 
  } 
}
//*********************************************************************************************************************************
void turn_left()
{  
  go_left();
    while(1)
     {
      readirsensors();
      if (mid==HIGH && left==LOW && right== LOW ){return;}
      else if(right2==HIGH){go_right();return;}
     }
  
}
//**********************************************************************************************************************************************************************************************
void turn_right()
{
 go_right();
      while(1)
      {
          readirsensors();
          if (mid==HIGH && left==LOW && right== LOW){return;}
          if(left2==HIGH ){go_left();return;}
      }
}
//void manu_turn_right()
//{
//  go_right();
//  
//}
