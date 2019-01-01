#include "expatcpp.h"
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <stdio.h>

static inline void ltrim(std::string &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s)
{
    ltrim(s);
    rtrim(s);
}

struct Tunnel
{
  Tunnel() : type(0) {};

  int posX;
  int posY;
  int desX;
  int desY;
  int type;
};

struct Star
{
  int x;
  int y;
  int type;
};

class TiledParser : public ExpatXMLParser
{
 public:
  TiledParser() :  mapCSVNext(true) {}
  virtual void startElement(const XML_Char *name, const XML_Char **atts);
  virtual void endElement(const XML_Char *name);
  virtual void characterData(const XML_Char *s, int len);
  void convert(int mapNum);

 private:
  int dotsFirst;
  int dotsSize;
  int wallsFirst;
  int width;
  int height;
  std::string mapCSV;
  bool mapCSVNext;
};

void TiledParser::startElement(const XML_Char *name, const XML_Char **atts)
{
 if (std::strcmp(name, "data") == 0)
  mapCSVNext = true;
 else if (std::strcmp(name, "layer") == 0)
 {
  for (int i = 0; atts[i]; i += 2)
  {
   if (std::strcmp(atts[i], "height") == 0)
    height = atol(atts[i + 1]);
   else if (std::strcmp(atts[i], "width") == 0)
    width = atol(atts[i + 1]);
  }
 }
 else if (std::strcmp(name, "tileset") == 0)
 {
  int first = 0;
  int count = 0;
  std::string source;
  for (int i = 0; atts[i]; i += 2)
  {
   if (std::strcmp(atts[i], "name") == 0)
    source = atts[i + 1];
   else if (std::strcmp(atts[i], "firstgid") == 0)
    first = atol(atts[i + 1]);
   else if (std::strcmp(atts[i], "tilecount") == 0)
    count = atol(atts[i + 1]);
  }
  if (std::strcmp(source.c_str(), "dots") == 0)
  {
   dotsFirst = first;
   dotsSize = count;
  }
  else if (std::strcmp(source.c_str(), "walls") == 0)
  {
   wallsFirst = first;
  }
 }
}

void TiledParser::endElement(const XML_Char *name)
{
 if (std::strcmp(name, "data") == 0)
  mapCSVNext = false;
}

void TiledParser::characterData(const XML_Char *s, int len)
{
 if (mapCSVNext)
 {
  std::string line(s, len);
  trim(line);
  mapCSV += line;
 }
}

void TiledParser::convert(int mapNum)
{
 std::vector<int> vect;
 std::stringstream ss(mapCSV);
 int i;

 while (ss >> i)
 {
  vect.push_back(i);
  if (ss.peek() == ',')
   ss.ignore();
 }
 if (vect.size() != height * width)
  printf("Data incorrect\n");
 else
 {
  printf("const spriteMap PROGMEM spriteMap%d[228] =\n", mapNum);
  printf("{\n");
  int ghostX, ghostY;
  int vioX, vioY;
  for (int y = 0; y < height; y++)
  {
   for (int x = 0; x < width; x++)
   {
    int value = vect[y * width + x];
    if ((value >= dotsFirst) && (value < dotsFirst + dotsSize))
    {
     if (value == dotsFirst + 3)
     {
      vioX = x;
      vioY = y;
     }
     printf("    0%s", ((x + 1 == width) ? ((y + 1 == height) ? "": ",") : ", "));
    }
    else
    {
     value = value - wallsFirst + 1;
     if (value == 22)
     {
      ghostX = x;
      ghostY = y;
     }
     printf("&s_B%c%s", ((value < 10) ? value + '0' : value - 10 + 'A'), ((x + 1 == width) ? ((y + 1 == height) ? "": ",") : ", "));
    }
   }
   printf("\n");
  }
  printf("};\n");
  printf("\n");
  printf("const bool PROGMEM dots%d[228] = {\n", mapNum);
  Star s[4];
  int curStar = 0;
  Tunnel t[2];
  for (int y = 0; y < height; y++)
  {
   for (int x = 0; x < width; x++)
   {
    int value = vect[y * width + x];
    if (value == dotsFirst)
     printf("false%s", ((x + 1 == width) ? ((y + 1 == height) ? "": ",") : ", "));
    else
    {
     if (value == dotsFirst + 2)
     {
      s[curStar].x = x;
      s[curStar].y = y;
      curStar++;
     }
     if ((value > dotsFirst + 3) && (value < dotsFirst + dotsSize))
     {
      int ty = (value - 1) / 2;
      for (int i = 0; i < 2; i++)
      {
       if ((t[i].type == ty) || (t[i].type == 0))
       {
        t[i].type = ty;
        if ((value - 1) % 2 == 0)
        {
         t[i].posX = x * 5;
         t[i].posY = y * 5;
        }
        else
        {
         t[i].desX = x * 5;
         t[i].desY = y * 5;
        }
        break;
       }
      }
     }
     printf(" true%s", ((x + 1 == width) ? ((y + 1 == height) ? "": ",") : ", "));
    }
   }
   printf("\n");
  }
  printf("};\n");
  printf("const LevelMap PROGMEM map%d = { {", mapNum);
  for (int i = 0; i < 2; i++)
  {
   if (t[i].type == 0)
   {
    printf("{0, 0, 0, 0}");
   }
   else
   {
    if (t[i].posX == 0)
    {
     t[i].posX = -4;
     t[i].desX += 4;
    }
    else
    {
     t[i].posY = -4;
     t[i].desY += 4;
    }
    printf("{%d, %d, %d, %d}", t[i].posX, t[i].posY, t[i].desX, t[i].desY);
   }
   if (i < 1)
    printf(", ");
  }
  printf("}, %d*5, %d*5, %d*5, %d*5, spriteMap%d, dots%d, {", vioX, vioY, ghostX, ghostY, mapNum, mapNum);
  for (int i = 0; i < 4; i++)
   printf(" {%d, %d, VIOBYTESTATE_PHASING}%s", s[i].x, s[i].y, (i < 3) ? "," : "");
  printf("} };\n");
 }
}

int main(int argc, char *argv[])
{
 TiledParser t;
 t.parse(argv[1], false);
 int mapNum = 1;
 if (argc > 2)
  sscanf(argv[2], "%d", &mapNum);
 t.convert(mapNum);
 return 0;
}
