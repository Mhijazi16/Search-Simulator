#include "ISimulateStrategy.h"
#include "Movement.h"
#include <vector>

class DepthStrategy: public ISimulateStrategy, Movement{

  private:
    vector<Point> Directions; 
  public: 

  void RefreshDirections(){
    if(!Directions.empty())
      Directions.clear();

    Directions.push_back(Player.Top());
    Directions.push_back(Player.Left());
    Directions.push_back(Player.Bottom());
    Directions.push_back(Player.Right());
  }
  
  void Simulate() override{
    RefreshDirections();
  }
};
