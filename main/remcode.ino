void go_to_left_line()
{
  go_forward();
  while (1)
  {  
  read_ir_left2();
  if (left2==LOW)
    {
      mstop();
      go_left();
      while(1)
      {
        read_ir_right2();
        if (right2==HIGH)
        {
          while(1)
          {
            read_ir_mid();
            if (mid==HIGH)
            {
              mstop();
              return;
            }
          }
        }
      }
    }
  }
}
