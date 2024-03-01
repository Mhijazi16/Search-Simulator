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
    vector<Point> BoxPath;
    int Distance = 0;
    int index = 0;
    bool done = false;

  public: 

    void ExecutionSpeed(){
      while (!done) cin >> Delay; 
    }

    void Execution(){

      SimulteBoxPath();
      BoxPath = vector<Point>(Path.begin(),Path.end());
      BoxPath.push_back(Meat[index]);
      Path.clear();

      for (int i = 1; i < BoxPath.size(); i++) {

        SimulatePlayerPath(BoxPath[i]);
        for (auto point : Path) {
          MoveTo(Player, point);
          Delay = 300;
          GamePrinter::PrintMap();
        }
        Path.clear();
        if(!CanBeMoved(Player, Boxes[index], true)){
          GamePrinter::GameLost();
          return; 
        }
        Boxes[index] = BoxPath[i];
      }

      done = true;
    }

    void SimulteBoxPath(){


      auto Target = CloserDirection(Meat[index], Boxes[index]);
      Point next = CloserDirection(Boxes[index], Target);
      Distance = Point::GetDistance(Boxes[index], Target);

      if(Distance == 0){
        Path.push_back(Boxes[index]);
        return;
      }

      while (!DFS(Boxes[index],next,Target)){
        Distance++;
        Delay = 200;
        GamePrinter::LimitExceeded(Distance);
        sleep_for(seconds(2));
      }

      GameContext::MapAt(Target) = TEST;
      Path.push_back(Target);
    }

    void SimulatePlayerPath(Point& Dest){

      auto Target = Boxes[index].GetPushPoint(Dest);
      Distance = Point::GetDistance(Player, Target);
      auto next = CloserDirection(Player, Target); 

      while (!DFS(Player,next,Target) && *(Path.end()-1) != Target){
        Distance++;
        Delay = 200;
        GamePrinter::LimitExceeded(Distance);
        sleep_for(seconds(2));
      }

      GameContext::MapAt(Target) = TEST;
      Path.push_back(Target);
    }

    bool DFS(Point& Source,Point& Direction,Point& Target){

      GamePrinter::PrintMap();
      cout << PLAYER << ": " << Player << " " << BASKET << ": " << Boxes[index] << endl;
      cout << RED << "Current : " <<  Source << endl; 
      cout << GREEN << "Next : " <<  Direction << endl; 
      cout << CYAN << "Target :" << Target << RESET << endl;

      if(Source == Target)
        return true;

      string& cell = GameContext::MapAt(Direction);

      if(cell == TEST)
        return false;

      if(cell != "  " || Path.size() > Distance )
        return false;

      if(!CanBeMoved(Source,Direction,false))
        return false;

      cell = TEST;
      Path.push_back(Source);

      for (auto Side : Directions) 
      {
        Point next = Direction+Side;
        if(DFS(Direction,next,Target))
          return true;
      }

      cell = "  "; 
      Path.pop_back();

      return false;
    }

    void Simulate() override {

      int len = Boxes.size();
      for (; index < len; index++) {
        done = false;
        thread Speed([this]{this->ExecutionSpeed();});
        thread Execute([this]{this->Execution();});

        Speed.join();
        Execute.join();
      }



      GamePrinter::CongratsMap();
      sleep_for(seconds(1));
      GamePrinter::GameWon();

    }
  
};
