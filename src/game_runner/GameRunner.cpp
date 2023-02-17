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

  Game aGame;

  aGame.add("Chet");
  aGame.add("Pat");
  aGame.add("Sue");

  bool still_no_winner = true;

  do
  {
    aGame.roll(rand() % 5 + 1);

    if (rand() % 9 == 7) {
      still_no_winner = aGame.wrongAnswer();
    }
    else {
      still_no_winner = aGame.wasCorrectlyAnswered();
    }
  } while (still_no_winner);
}
