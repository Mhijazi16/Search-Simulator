#include "Constants.h"
#include <vector>
#include <thread>
#include <chrono>

using namespace std; 


class GameContext{

  public:

  static void ResetContext(){
    Map = {
      {"  ","🪵","🪵","🪵","🪵","🪵","🪵"},
      {"  ","🪵","  ","  ","  ","  ","🪵"},
      {"🪵","🪵","  ","  ","🧺","  ","🪵"},
      {"🪵","  ","  ","  ","  ","🥩","🪵"},
      {"🪵","  ","  ","  ","🪵","  ","🪵"},
      {"🪵","🥩","  ","🐊","  ","  ","🪵"},
      {"🪵","🧺","  ","🪵","  ","🪵","🪵"},
      {"🪵","  ","  ","  ","  ","🪵","  "},
      {"🪵","  ","  ","  ","  ","🪵","  "},
      {"🪵","🪵","🪵","🪵","🪵","🪵","  "},};
    Backup = Map;
    row_limit = Map.size();
    col_limit = Map[0].size();
    score = 0;
    Lost = false;
    RefreshContext();
  };

  static void RefreshContext(){

    if(!Meat.empty() || !Boxes.empty()){
      Meat.clear(); 
      Boxes.clear();
    }

    for (int i = 0; i < row_limit; i++) 
      for (int j = 0; j < col_limit; j++) {
        if(Map[i][j] == MEAT)
          Meat.push_back(Point(i,j));
        else if(Map[i][j] == PLAYER)
          Player = Point(i,j);
        else if(Map[i][j] == BASKET)
          Boxes.push_back(Point(i,j));
      }
  }

  static Point EmptyLocation(Point& location){

    if(MapAt(location.Top()) == "  ")
      return location.Top();
    else if(MapAt(location.Bottom()) == "  ")
      return location.Bottom();
    else if(MapAt(location.Right()) == "  ")
      return location.Right();

      return location.Left();
  }

  static string& MapAt(const Point& location){
    return Map[location.X][location.Y];
  }

};

