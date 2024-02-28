#include "GamePrinter.h"

class Movement{
  private: 
    GameContext gameContext;
    bool onMeat = false;

    bool InCorner(Point& Box){

      int x = Box.X;
      int y = Box.Y;

      auto Top = gameContext.MapAt(Point(x,y-1));
      auto Bottom = gameContext.MapAt(Point(x,y+1));
      auto Right = gameContext.MapAt(Point(x+1,y));
      auto Left = gameContext.MapAt(Point(x-1,y));

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

  public:
    Movement(){
      gameContext = GameContext();
    }

};
