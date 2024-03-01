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
      cout << "🏁🏁PRESS ENTER TO START🏁🏁";
      cin.ignore();
      Strategy->Simulate();
    }
};


int main(){

  DepthStrategy* strat = new DepthStrategy();
  GameContext::ResetContext();
  Game game = Game(strat); 
  game.Start();


  return 0;
}
