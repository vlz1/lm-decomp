#ifndef CHARACTER_COLLISION_MANAGER_H_
#define CHARACTER_COLLISION_MANAGER_H_

#include "types.h"
#include <JSystem/JORReflexible.hpp>

class CharacterColManager : public JORReflexible {
public:
    CharacterColManager();
    /* 0x08 */ virtual ~CharacterColManager();


public:
    /* 0x04 */  s32 _4;
};

#endif
