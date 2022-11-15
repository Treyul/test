void readirsensors()
{
read_ir_left();
read_ir_mid();
read_ir_left2();
read_ir_right();
read_ir_right2();
}
void read_ultrasonic()
{
read_front_uts();
read_left_uts();
read_right_uts();
}
void read_front_uts()
{
  delayMicroseconds(100);
  df = fsonar.ping_cm();
}
void read_left_uts()
{
  delayMicroseconds(100);
  dl = lsonar.ping_cm();
}
void read_right_uts()
{
  delayMicroseconds(100);
  dr = rsonar.ping_cm(); 
}
void read_ir_mid()
{
  mid = digitalRead(irm);
}
void read_ir_left()
{
  left = digitalRead(irl);
}
void read_ir_left2()
{
  left2=digitalRead(irl2); 
}
void read_ir_right()
{
  right = digitalRead(irr);
}
void read_ir_right2()
{
  right2=digitalRead(irr2);
}
