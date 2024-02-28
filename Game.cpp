#include "ISimulateStrategy.h"
#include "GamePrinter.h"

class Game{
  private:
    ISimulateStrategy* Strategy; 
  public: 
    Game(ISimulateStrategy* strategy): Strategy(strategy){};
    void Start(){
      GamePrinter::Welcome();
      GamePrinter::PrintMap();
      GamePrinter::GameMenu();
      GamePrinter::Coordinates();
      Strategy->Simulate();
    }
};

int main(){

  return 0;
}
