void phase_3()
{
//  go_to_left_line();
  move_bot_3();
}


void move_bot_3()
{
   while(1)
    {
          movebot_3_start:
          readirsensors();
          read_front_uts();
          Serial.println(df);

          /*** follow mid line ***/
          if ((mid == HIGH && (left == LOW || right == LOW)))
             {
              go_foward_p1();
              goto movebot_3_start;
             } 
          /**** move left ****/
           else if ((left2 == LOW)&&(left == HIGH) && (mid == LOW) && (right == LOW)&&(right2 == LOW))
              {
               go_left();
               goto movebot_3_start;
              } 
          /*** move right ***/
           else if ((left2 == LOW)&&(left == LOW) && (mid == LOW) && (right == HIGH)&&(right2 == LOW))
              {
                go_right();
                goto movebot_3_start;
              }

           /*** move left ***/
           else if ((left2 == HIGH)&&(left == LOW) && (mid == LOW) && (right == LOW)&&(right2 == LOW))
              {
               turn_left();
               goto movebot_3_start;
              } 
          /**** moe right ***/
           else if ((left2 == LOW)&&(left == LOW) && (mid == LOW) && (right == LOW)&&(right2 == HIGH))
              {
                turn_right(); 
                goto movebot_3_start;
              }
    }
}

//***********************************************************************************************************************************************************
void go_foward_p1()
{
  go_forward();
//  while (1)
//  {
    read_front_uts();
    read_ir_mid();
    if (df<=obstacle_offset)
    {
//        reverse(obstacle_offset);
        mstop();
        short_turn();
        delay(1000);
        
    }
  
//    else if (mid==LOW)
//    {break;}
//  }
}
//*********************************************************************************************************************************

void short_turn()
{
  do
  {
    read_ir_left2();
    turn_right();
  } while (left2 != HIGH );
  
  read_front_uts();

  int left_dist = df;

    do
  {
    read_ir_right2();
    turn_left();
    Serial.print("Right side");
    Serial.println(right2 != HIGH);
  } while (right2 != HIGH );
  
  
  read_front_uts();

  Serial.println("next step");
  int right_dist = df;

  Serial.println(right2,left2);
  if (right_dist < left_dist)
  {
    turn_left();
  }
  else if (left_dist < right_dist)
  {
    turn_right();
  }
  return;
}
