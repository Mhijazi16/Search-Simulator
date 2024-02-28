#include "Point.h"
#include "Constants.h"
#include <vector>
#include <thread>
#include <chrono>

using namespace std; 


class GameContext{

  private:
    vector<vector<string>> Map; 
    vector<vector<string>> Backup; 
    vector<Point> Boxes; 
    vector<Point> Meat; 
    Point Player; 
    int row_limit; 
    int col_limit;
    int delay; 

  public:

    GameContext(){
      Map = {
        {"🪵","🪵","🪵","🪵","🪵","🪵","🪵"},
        {"🪵","  ","  ","  ","  ","  ","🪵"},
        {"🪵","  ","  ","  ","  ","  ","🪵"},
        {"🪵","  ","🥩","  ","  ","  ","🪵"},
        {"🪵","  ","  ","🧺","🪵","  ","🪵"},
        {"🪵","  ","  ","  ","  ","  ","🪵"},
        {"🪵","  ","  ","🪵","  ","  ","🪵"},
        {"🪵","  ","  ","  ","  ","  ","🪵"},
        {"🪵","  ","  ","  ","🐊","  ","🪵"},
        {"🪵","🪵","🪵","🪵","🪵","🪵","🪵"},};
      Backup = Map;
      row_limit = Map.size();
      col_limit = Map[0].size();
      RefreshContext();
    }

  void RefreshContext(){

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

  void PrintMap(){
    this_thread::sleep_for(chrono::milliseconds(delay));
    for(auto row : Map)
      for(auto cell : row)
        cout << cell << " ";
  }
};

