#include "Game.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

using namespace std;

SCENARIO ("Game construction")
{
  WHEN ("a Game instance is constructed")
  {
    Game game;

    THEN ("the current player is player 0")
    {
      //REQUIRE(game.currentPlayer == 0);
    }

    THEN ("there are no players")
    {
      //REQUIRE(game.players.size() == 0); 
    }

  }
}


