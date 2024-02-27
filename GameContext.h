#include "Point.h"
#include "Constants.h"
#include <vector>

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
    }
};

