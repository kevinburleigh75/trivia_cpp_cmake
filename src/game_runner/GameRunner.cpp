#include <cstdlib>

#include "Game.h"

using namespace std;

int main(int argc, char** argv)
{
  if (argc == 1) {
    srand(time(NULL));
  }
  else {
    unsigned seed = stoi(argv[1]);
    srand(seed);
  }

  Game game;

  game.addPlayer("Chet");
  game.addPlayer("Pat");
  game.addPlayer("Sue");

  while (game.continuePlaying())
  {
    game.roll(rand() % 5 + 1);

    if (rand() % 9 == 7) {
      game.handleIncorrectAnswer();
    }
    else {
      game.handleCorrectAnswer();
    }

    if (game.continuePlaying()) {
      game.advanceCurrentPlayer();
    }
  }
}
