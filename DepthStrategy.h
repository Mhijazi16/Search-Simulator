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
      // while (!done) cin >> Delay; 
    }

    void Execution(){
      // SimulatePlayerPath();
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
