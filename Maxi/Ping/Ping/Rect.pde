public class Rect
{
  int startX;
  int startY;
  int sizeX;
  int sizeY;
  int x;
  int y;
  
  public Rect(int startX, int startY, int sizeX, int sizeY)
  {
    this.startX = startX;
    this.startY = startY;
    this.sizeX = sizeX;
    this.sizeY = sizeY;
  }
  
  public void initRect()
  {
     rect(startX, startY, sizeX, sizeY);
  }
  
  public void moveRect()
  {
    rect(mouseX, startY, sizeX, sizeY);
    x = mouseX;
    y = startY;
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
