#include "HumanStrategy.h"

class Game{
  private:
    ISimulateStrategy* Strategy; 
  public: 
    Game(ISimulateStrategy* strategy): Strategy(strategy){};
    void Start(){
      GamePrinter::Welcome();
      GamePrinter::PrintMap();
      GamePrinter::Coordinates();
      cin.ignore();
      GamePrinter::GameMenu();
      Strategy->Simulate();
    }
};


int main(){

  GameContext::ResetContext();
  GameContext::RefreshContext();
  HumanStrategy* strat = new HumanStrategy();
  Game game = Game(strat); 
  game.Start();


  return 0;
}
