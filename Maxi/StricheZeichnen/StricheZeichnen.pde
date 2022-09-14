int offset = 10;

void setup()
{
  size(1000, 1000);
  background(255);
  textSize(10);


  mainProg();
}

void zeichneBeschrifteteLinie(int x1, int y1, int x2, int y2, int farbe)
{
  int[] mPunkt = mittelpunkt(x1, y1, x2, y2);
  float[] transFrabe = hsvtorgb(farbe);
  
  String str1 = "( " + x1 + " | " + y1 + " )";
  String str2 = "( " + x2 + " | " + y2 + " )";
  String str3 = "( " + mPunkt[0] + " | " + mPunkt[1] + " )" + " -> " + "Laenge: " + leange(x1, y1, x2, y2);
  
  fill((int)transFrabe[0], (int)transFrabe[1], (int)transFrabe[2]);
  stroke((int)transFrabe[0], (int)transFrabe[1], (int)transFrabe[2]);
  
  line(x1, y1, x2, y2);

  circle(x1, y1, 10);
  text(str1, (x1 + offset), y1);
  println("Start: " + str1);

  circle(x2, y2, 10);
  text(str2, (x2 + offset), y2);
  println("Ende: " + str2);

  circle(mPunkt[0], mPunkt[1], 10);
  text(str3, (mPunkt[0] + offset), mPunkt[1]);
  println("Mittelpunk: " + str3);
}

float leange(int x1, int y1, int x2, int y2)
{
  float x = (float) x1 - x2;
  float y = (float) y1 - y2;

  return sqrt(pow(x, 2.0) + pow(y, 2.0));
}

float mittelwert(int value1, int value2)
{
  return (float)((value1 + value2) / 2);
}

int[] mittelpunkt(int x1, int y1, int x2, int y2)
{
  int x = (int) ((x2 - x1) / 2) + x1;
  int y = (int) ((y2 - y1) / 2) + y1;

  int[] ret = {x, y};

  return ret;
}

float[] hsvtorgb(int value)
{
  float r = 0;
  float g = 0;
  float b = 0;

  float h = value;
  float s = 150;
  float v = 150;

  h = h / 360;
  s = s / 100;
  v = v / 100;

  float i = floor(h * 6);
  float f = (h * 6) - i;
  float p = v * (1 - s);
  float q = v * (1 - (f * s));
  float t = v * (1 - (1 - f) * s);

  switch((int)i)
  {
  case 0: 
    r =  v * 255; 
    g =  t * 255; 
    b =  p * 255; 
    break;
  case 1: 
    r =  q * 255; 
    g =  v * 255; 
    b =  p * 255; 
    break;
  case 2: 
    r =  p * 255; 
    g =  v * 255; 
    b =  t * 255; 
    break;
  case 3: 
    r =  p * 255; 
    g =  q * 255; 
    b =  v * 255; 
    break;
  case 4: 
    r =  t * 255; 
    g =  p * 255; 
    b =  v * 255; 
    break;
  case 5: 
    r =  v * 255; 
    g =  p * 255; 
    b =  q * 255; 
    break;
  case 6: 
    r =  v * 255; 
    g =  t * 255; 
    b =  p * 255; 
    break;
  }
  
  float[] ret = {r, g, b};
  
  return ret;
}

void mainProg()
{
  zeichneBeschrifteteLinie(50, 50, 350, 350, 50);
  zeichneBeschrifteteLinie(50, 50, 600, 400, 100);
  zeichneBeschrifteteLinie(50, 50, 400, 600, 200);
}
