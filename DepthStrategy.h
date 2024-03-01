#include "ISimulateStrategy.h"
#include "Movement.h"
#include <chrono>
#include <functional>
#include <set>
#include <unordered_map>
#include <vector>
#include <thread>

using namespace std; 

class DepthStrategy: public ISimulateStrategy, Movement{

  private:
    vector<Point> Directions = {Point(-1,0),Point(0,1),Point(1,0),Point(0,-1)}; 
    vector<Point> Path;
    int Distance = 0;
    bool done = false;

  public: 

    void ExecutionSpeed()
    {
      while (!done) cin >> Delay; 
    }

    void Execution(){
      // SimulatePlayerPath();
    }

    bool DFS(Point& Source,Point& Direction,Point& Target){

      GamePrinter::PrintMap();

      if(Source == Target)
        return true;

      string& cell = GameContext::MapAt(Direction);

      if(cell != "  " || Path.size() == Distance )
        return false;

      if(!CanBeMoved(Source,Direction,false))
        return false;

      if(cell != PLAYER && cell != BASKET){
        cell = TEST;
        Path.push_back(Source);
      }

      for (auto Side : Directions) 
      {
        Point next = Direction+Side;
        if(DFS(Direction,next,Target))
          return true;
      }

      if(cell != PLAYER){
        cell = "  "; 
        Path.pop_back();
      }

      return false;
    }

    void Simulate() override
    {
      thread Speed([this]{this->ExecutionSpeed();});
      thread Execute([this]{this->Execution();});

      Speed.join();
      Execute.join();

      for (auto point : Path) {
        MoveTo(Player, point);
        Delay = 300;
        GamePrinter::PrintMap();
      }

      if(!CanBeMoved(Player, Boxes[0], true)){
        GamePrinter::GameLost();
        return; 
      }

      GamePrinter::CongratsMap();
      sleep_for(seconds(1));
      GamePrinter::GameWon();

    }
  
};
