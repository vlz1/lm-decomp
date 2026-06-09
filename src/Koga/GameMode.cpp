#include "Koga/GameMode.hpp"

namespace Koga {
    GameMode* GameModeBase::sCurrentGameMode = nullptr;
    int GameModeBase::sGameModeCount = 0;

    GameMode::GameMode() { }
    GameMode::~GameMode() { }

    void GameMode::init() { }
    void GameMode::vt_10() { }
    void GameMode::vt_14() { }
    void GameMode::vt_18() { }

    GameModeBase::GameModeBase() {
        incrementGameModeCount();
    }

    void GameModeBase::incrementGameModeCount() {
        GameModeBase::sGameModeCount += 1;
    }
}
