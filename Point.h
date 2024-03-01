#include <cmath>
#include <iostream>

using namespace std; 

struct Point{
  int X; 
  int Y; 

  Point(): X(0), Y(0){};
  Point(int x,int y): X(x), Y(y){};

  friend ostream& operator<<(ostream& os, const Point& point){
    os << "[" << point.Y << " " << point.X << "]";
    return os;
  }

  bool operator==(const Point& other) const {
    return other.X == X && other.Y == Y;
  }

  bool operator<(const Point other) const{
    return X < other.X && Y < other.Y;
  }

  bool operator>(const Point other) const{
    return X > other.X && Y > other.Y;
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
    return Point(X+other.X, Y + other.Y);
  }

  Point operator/(const Point& other) const{
    return Point(X/other.X , Y / other.Y);
  }

  Point GetPushPoint(const Point& Target) const{
    return *this * 2 - Target;
  }

  Point Top(){
    return Point(X-1,Y);
  }

  Point Bottom(){
    return Point(X+1,Y);
  }
  Point Left(){
    return Point(X,Y-1);
  }
  Point Right(){
    return Point(X,Y+1);
  }

  static int GetDistance(const Point one, const Point two){
    return sqrt(pow(one.X - two.X, 2) + pow(one.Y - two.Y, 2));
  }

};
