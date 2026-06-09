#ifndef MISSION_MODE_H_
#define MISSION_MODE_H_

#include "Koga/GameMode.hpp"

class CharacterColManager;
class JmpMessageSender;

namespace Koga {
    class EnTypesManager;
    class EnManager;
    class EnemyGenManager;

    class MissionMode : public GameMode {
    public:
        MissionMode();
        ~MissionMode();

        /* 0x08 */ virtual void vt_8();

        /* 0x0C */ virtual void vt_C();
        /* 0x10 */ virtual void vt_10();
        /* 0x14 */ virtual void vt_14();
        /* 0x18 */ virtual void vt_18();

        static MissionMode* create();
    public:
        /* 0x04 */ EnTypesManager* mEnTypesMgr;
        /* 0x08 */ EnManager* mEnMgr;
        /* 0x0C */ EnemyGenManager* mEnGenMgr;
        /* 0x10 */ s32 _10;
        /* 0x14 */ s32 _14;
        /* 0x18 */ s32 _18;
        /* 0x1C */ CharacterColManager* mCharColMgr;
        /* 0x20 */ JmpMessageSender* mJmpMsgSender;

        static MissionMode* sMissionMode;
    };
}

#endif
