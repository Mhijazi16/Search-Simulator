#include "GamePrinter.h"
#include <chrono>
#include <thread>

class Movement{
  private: 
    bool onMeat = false;

  public:

    bool InCorner(Point& Box){

      int x = Box.X;
      int y = Box.Y;

      auto Top = GameContext::MapAt(Point(x,y-1));
      auto Bottom = GameContext::MapAt(Point(x,y+1));
      auto Right = GameContext::MapAt(Point(x+1,y));
      auto Left = GameContext::MapAt(Point(x-1,y));

      bool upright = Top == WOOD && Right == WOOD;  
      bool upleft = Top == WOOD && Left == WOOD;  
      bool downright = Bottom == WOOD && Right == WOOD;  
      bool downleft = Bottom == WOOD && Left == WOOD;  

      if(upright || upleft || downleft || downright){
        cout << RED << "!!! " << BASKET << " IS STUCK " << "🐊" << " CAN\"T SOLVE THE GAME !!!" << endl;
        GamePrinter::GameLost();
        return true;
      }

      return false;

    }

    bool virtual CanBePushed(Point Source, Point& Target, bool Push){

      string& src = GameContext::MapAt(Source);
      string& tar = GameContext::MapAt(Target); 

      if(InCorner(Source)){
        Lost = true;
        return false;
      }

      if(tar == WOOD || tar == BASKET){
        if(Push) GamePrinter::Alert();
        return false;
      }

      if (Push) 
        PushBox(Source, Target);

      return true;
    }

    bool virtual PushBox(Point Source, Point& Target){

      string& src = GameContext::MapAt(Source);
      string& tar = GameContext::MapAt(Target); 

      if(tar == MEAT){
        score++;
        tar = POINT;
      }
      else 
        tar = src; 

      src = SPACE;
      Source = Target;
      return true;
    }

    bool CanBeMoved(Point& Source, Point Target, bool Move){

      string& src = GameContext::MapAt(Source);
      string& tar = GameContext::MapAt(Target); 

      if(src == tar)
        return true;

      if(tar == WOOD || tar == POINT ){
        if(Move) GamePrinter::Alert();
        return false;
      }

      if(tar == BASKET){
        auto Next = Target.GetPushPoint(Source); 
        if(CanBePushed(Target,Next,Move) == false)
          return false;
      }

      if(onMeat){
        onMeat = false;
        tar = src; 
        src = MEAT;
        Source = Target;
        return true;
      }

      if(tar == MEAT)
        onMeat = true;

      if(Move)
        MoveTo(Source, Target);
      return true;
    }
  
    bool virtual MoveTo(Point& Source, Point Target){

      string& src = GameContext::MapAt(Source);
      string& tar = GameContext::MapAt(Target); 

      src = SPACE; 
      tar = PLAYER;
      Source = Target;
      return true;
    }

  Point CloserDirection(Point& Source, Point& Target){

    Point Next = Target - Source;
    //GO UP
    if(Next.X < 0 && CanBeMoved(Source, Source + Point(-1,0), false))
      return Source + Point(-1,0);
    //GO DOWN
    else if(Next.X > 0 && CanBeMoved(Source, Source + Point(1,0), false))
      return Source + Point(1,0);
    //GO LEFT
    else if(Next.Y < 0 && CanBeMoved(Source, Source + Point(0,-1), false))
      return Source + Point(0,-1);
    //GO Right
    else if(Next.Y > 0 && CanBeMoved(Source, Source + Point(0,1), false))
      return Source + Point(0,1);

    return Point(0,0);
  }

};
