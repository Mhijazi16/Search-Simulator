#include <cmath>
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

  bool operator==(const Point& other) const {
    return other.X == X && other.Y == Y;
  }

  Point& operator=(const Point& other){
    if(this != &other){
      this->X = other.X;
      this->Y = other.Y;
    }

    return *this;
  }

  Point operator*(const int number) const{
    return Point(number * X, number * Y);
  }

  Point operator-(const Point& other) const{
    return Point(X-other.X, Y - other.Y);
  }

  Point operator+(const Point& other) const{
    return Point(X-other.X, Y - other.Y);
  }

  static int GetDistance(const Point one, const Point two){
    return sqrt(pow(one.X - two.X, 2) + pow(one.X - two.Y, 2));
  }

};
