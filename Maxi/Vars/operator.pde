public class Operator
{
  int counter = 0;
  int y;
  int x;
  int textSize;
  
  public Operator(int x, int y, int textSize)
  {
    this.x = x;
    this.x = x;
    this.textSize = textSize;
  }
  
  public int addition(int input1, int input2)
  {
    return input1 + input2;
  }
  
  public void subtraction(int input1, int input2)
  {
    println(input1 + " + " + input2 +  " = " + (input1 - input2));
    text(input1 + " + " + input2 +  " = " + (input1 - input2), x, y);
  }
  
  public void programm()
  {
    switch(counter)
    {
      case 0: background(255,0,0); counter++; break;
      case 1: background(0,255,0); counter++; break;
      case 2: background(0,0,255); counter = 0; break;
      default: break;
    }
  }
}
