Operator operator;

void setup()
{
  size(1000, 1000);
  background(255);
  operator = new Operator(100, 100, 20);
  frameRate(40);
}



void draw()
{
  println(operator.addition(2, 3));
  println(operator.addition(8, 12));
  operator.subtraction(6, 4);
  println(operator.addition(3, 1));
  println(operator.addition(-3, 1));
  
  //operator.programm();

  noLoop();
  

}
