public class Gameboard
{
  int threashold;
   public Gameboard(int threashold)
   {
     this.threashold = threashold;
   }
   
   public int getBounce(int x, int y)
   {
     int ret = 4;
     if (x == (width - threashold)       && y >= threashold  && y <= (height - threashold) )   ret = 0;
     if (x == (threashold)               && y >= threashold  && y <= (height - threashold) )   ret = 1;
     if (y == (height - threashold)      && x >= threashold  && x <= (width - threashold) )    ret = 2;
     if (y == (threashold)               && x >= threashold  && x <= (width - threashold) )    ret = 3;
     
     return ret;
   }
   
   public int getBounceRect(int rectX, int rectY, int x, int y)
   {
     int ret = 4;
     
     println("X: " + x + "Y: " + x, "rectX: " + rectX + "rectY: " + rectY);
     if (y == rectY && x >= rectX - 30  && x <= rectX + 30  ) ret = 2;
     return ret;
   }
}
