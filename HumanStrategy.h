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
          MoveTo(Player,Player.Top());
        else if(input == 's')
          MoveTo(Player,Player.Bottom());
        else if(input == 'a')
          MoveTo(Player,Player.Left());
        else if(input == 'd')
          MoveTo(Player,Player.Right());
        else 
          break;
      }

      if(!Lost)
        GamePrinter::GameWon();

    }

};


