#include "ISimulateStrategy.h"
#include "Movement.h"

class HumanStrategy : public ISimulateStrategy, Movement{

  private:
    char input; 
  public:
    void Simulate() override{

      GamePrinter::PrintMap(); 
      while (Meat.size() != score && !Lost) {

        GamePrinter::PrintMap();
        cin >> input; 

        if(input == 'w')
          CanBeMoved(Player,Player.Top(),true);
        else if(input == 's')
          CanBeMoved(Player,Player.Bottom(),true);
        else if(input == 'a')
          CanBeMoved(Player,Player.Left(),true);
        else if(input == 'd')
          CanBeMoved(Player,Player.Right(),true);
        else 
          break;
      }

      if(!Lost){
        GamePrinter::CongratsMap();
        GamePrinter::GameWon();
      }

    }

};


