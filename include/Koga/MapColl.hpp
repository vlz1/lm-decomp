#ifndef MAP_COLL_H_
#define MAP_COLL_H_

#include "types.h"
#include <JSystem/JORReflexible.hpp>

namespace Koga {
    class MapColl : public JORReflexible {
    public:
        MapColl();
        /* 0x08 */ virtual ~MapColl();

        static void newMapColl();

    public:
        /* 0x04 */  s32 _4;
        /* 0x08 */ u16 _8;
        /* 0x0C */ s32 _C;
        /* 0x10 */ s32 _10;

        static MapColl* sCurMapColl;
    };

};

#endif
