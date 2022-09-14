/*
*  Maximilian Hoffmann
*/

int strichBreite = 23;
int kurveBreite = strichBreite;

int startX = 150;
int startY = 100;

void setup() {
  size(800, 600);
  background(255, 152, 0);
  stroke(255, 255, 255);
  noFill();
}

void drawNose(int x, int y, int orientation, int weite, int hoehe)
{
   strokeWeight(strichBreite);
   if(orientation == 0)
   {
     line(x, y, (x + hoehe), (y + weite));
     line((x + hoehe), (y + weite), x, (y + weite));
   }else{
     line((x + hoehe), y, x, (y + weite));
     line(x, (y + weite), (x + hoehe), (y + weite));
   } 
}

void drawEys(int x, int y, int range, int count)
{
  strokeWeight(strichBreite);
  for (int i = 0; i <= count; i++)
  {
    point(x, y);
    x += range;
  }
}

void drawMouth(int x, int y, int typ, int leangh, int abstand, int hoehe)
{

  
  strokeWeight(strichBreite);
  switch(typ)
  {
    case 0: line(x, y, (x + leangh), y);
            line(x, (y + abstand), (x + leangh), (y + abstand));
    break;

    case 1: strokeWeight(kurveBreite);
            line(x, y, (x + leangh), y);
            
            arc((x + (leangh / 2)), y, leangh, hoehe, 0, PI);
    break;
    
    case 2: strokeWeight(kurveBreite);
            arc((x + (leangh / 2)), y, leangh, hoehe, 0, PI);
    break;
    
    default: break;
  }
}

void drawName(int x, int y, String str, int size)
{
   textSize(size);
   text(str, x, y); 
}

int nosePos(int id, int nr)
{
  return (id == 0) ? (startX + (200 * nr)) : startY; 
}

int eyePos(int id)
{
  return (id == 0) ? (startX - 50) : (startY + 50);
}

int mouthPos(int id, int nr)
{
  return (id == 0) ? (startX + 25 + (nr * 200)) : (startY + 250);
}



void draw() {
  
  
  drawNose(nosePos(0, 0), nosePos(1, 0), 0, 200, 100);
  drawNose(nosePos(0, 1), nosePos(1, 1), 1, 200, 100);
  drawNose(nosePos(0, 2), nosePos(1, 2), 1, 200, 100);

  
  drawEys(eyePos(0), eyePos(1),200, 4);
  
  drawMouth(mouthPos(0, 0) - 25, mouthPos(1, 0), 0, 50, 30, 50);
  drawMouth(mouthPos(0, 1), mouthPos(1, 1), 1, 75, 25, 75);
  drawMouth(mouthPos(0, 2), mouthPos(1, 2), 2, 75, 25, 25);
  
  drawName(100, 500, "MH", 40);
  
}
