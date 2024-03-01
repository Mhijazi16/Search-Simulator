// #include "HumanStrategy.h"
#include "DepthStrategy.h"

class Game{
  private:
    ISimulateStrategy* Strategy; 
  public: 
    Game(ISimulateStrategy* strategy): Strategy(strategy){};
    void Start(){
      GamePrinter::Welcome();
      GamePrinter::PrintMap();
      GamePrinter::Coordinates();
      GamePrinter::GameStart();
      cin.ignore();
      Strategy->Simulate();
    }
};


int main(){

  DepthStrategy* strat = new DepthStrategy();
  // HumanStrategy* strat = new HumanStrategy(); 
  GameContext::ResetContext();
  Game game = Game(strat); 
  game.Start();


  return 0;
}
