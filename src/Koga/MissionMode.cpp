#include "Koga/MissionMode.hpp"
#include "Koga/MapColl.hpp"
#include "Koga/EnTypesManager.hpp"
#include "Koga/EnManager.hpp"
#include "Koga/EnemyGenManager.hpp"
#include "Koga/JMPMessage.hpp"
#include "Koga/CharacterColManager.hpp"
#include "Koga/SimpleModeler.hpp"

dummy_float_data()

namespace Koga {

    MissionMode::MissionMode()
        : GameMode()
        , mEnTypesMgr(nullptr)
        , mEnMgr(nullptr)
        , mEnGenMgr(nullptr)
        , _10(0)
        , _14(0)
        , _18(0)
        , mCharColMgr(nullptr)
        , mJmpMsgSender(nullptr)
    {
        MapColl::newMapColl();
        EnTypesManager::newManager();
        mEnTypesMgr = EnTypesManager::getManager();
        mEnMgr = new EnManager();
        mCharColMgr = new CharacterColManager();
        mJmpMsgSender = new JmpMessageSender();
        mEnGenMgr = new EnemyGenManager();
        SimpleModeler::newSimpleModeler();

        vt_C();
    }

    MissionMode* Koga::MissionMode::create() {
        if (Koga::GameModeBase::getGameModeCount() == 0) {
            sMissionMode = new Koga::MissionMode();
        }
        return sMissionMode;
    }
}
