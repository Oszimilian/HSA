Ball ball;
Gameboard gameboard;
Rect rect;

int i = 0;
boolean start = false;
int x, y;
int speedX = 2; 
int speedY = 2;
int bounceVar = 4;


void setup()
{
  size(500, 600);
  ball = new Ball(100, 100, 20);
  gameboard = new Gameboard(10);
  rect = new Rect(250, 550, 60, 10);
  ball.initBall();
}

void draw()
{
  background(0);
  if (!start)
  {
    x = ball.getStartX();
    y = ball.getStartY();
    start = true;
  }
  
  ball.moveBall(x, y);
  rect.moveRect();
  
  
  if (gameboard.getBounce(ball.getX(), ball.getY()) != 4)
  {
    //println( gameboard.getBounce(ball.getX(), ball.getY()) );
    bounceVar = gameboard.getBounce(ball.getX(), ball.getY());
  }
  
  if (gameboard.getBounceRect(rect.getX(), rect.getY(), ball.getX(), ball.getY()) != 4)
  {
    bounceVar = gameboard.getBounceRect(rect.getX(), rect.getY(), ball.getX(), ball.getY());
    println(bounceVar);
  }
  

  
  switch (bounceVar)
  {
     case 0: speedX *= -1; break;
     case 1: speedX *= -1; break;
     case 2: speedY *= -1; break;
     case 3: speedY *= -1; break; 
     default: break;
  }
  
  bounceVar = 4;
  
  x += speedX;
  y += speedY;
  
  
  
  

 
}
