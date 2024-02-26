#include <iostream>

using namespace std; 

struct Point{
  int X; 
  int Y; 

  Point(int x,int y){
    X = x; 
    Y = y; 
  }

  friend ostream& operator<<(ostream& os, const Point& point){
    os << "[" << point.X << " " << point.Y << "]";
    return os;
  }
};
