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
    };

  public:
    vector<Point> Boxes; 
    vector<Point> Meat; 
    Point Player; 
    int row_limit; 
    int col_limit;
    int score = 0;

    GameContext& operator=(const GameContext&) = delete;
    GameContext(const GameContext&) = delete;

    static GameContext& getInstance(){
      static GameContext context = GameContext(); 
      return context;
    }

    vector<vector<string>> getMap(){
      return Map;
    }

    string& MapAt(const Point& location){
      return Map[location.Y][location.X];
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
};

