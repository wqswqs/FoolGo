#include "../../src/game/monte_carlo_game.h"

#include <gtest/gtest.h>

#include "../../src/board/full_board.h"
#include "../../src/board/zob_hasher.h"
#include "../../src/math/rand.h"
#include "../def_for_test.h"
#include "../test.h"

namespace foolgo {
namespace game {

using board::FullBoard;
using board::ZobHasher;

class MonteCarloGameTest : public Test {
 protected:
  virtual void SetUp() {
    Test::SetUp();

    uint32_t seed = math::GetTimeSeed();
    std::cout << "seed:" << seed << std::endl;

    ZobHasher<DEFAULT_BOARD_LEN>::Init(seed);
    FullBoard<DEFAULT_BOARD_LEN> full_board_;
    full_board_.Init();

    game_ = new MonteCarloGame<DEFAULT_BOARD_LEN>(full_board_, seed, false);
  }

  virtual void TearDown() {
    delete game_;
  }

  MonteCarloGame<DEFAULT_BOARD_LEN> *game_ = nullptr;
};

TEST_F(MonteCarloGameTest, Run) {
  game_->Run();
}

}
}
