public class Ball
{
  int startX;
  int startY;
  int size;
  int x;
  int y;
  
  public Ball(int startX, int startY, int size)
  {
      this.startX = startX;
      this.startY = startY;
      this.size = size;
      
      //initBall();
      
  }
  
  public void initBall()
  {
    fill(255, 255, 255);
    circle(startX, startY, size);
  }
  
  public void moveBall(int x, int y)
  {
     circle(x, y, size); 
     this.x = x;
     this.y = y;
  }
  
  public int getStartX()
  {
    return startX;
  }
  public int getStartY()
  {
    return startY;
  }
  
  public int getX()
  {
     return x; 
  }
  
  public int getY()
  {
     return y; 
  }
}
