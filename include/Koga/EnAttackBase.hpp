#ifndef EN_ATTACK_BASE_H_
#define EN_ATTACK_BASE_H_

#include <Koga/CharacterEventObserver.hpp>
#include <Sato/EnemyStrategy.hpp>

class EnAttackBase : public EnemyStrategy, public Koga::CharacterEventObserver {
public:
    /* 0x08 */ virtual ~EnAttackBase(); //TODO: Could be weak symbol as well
    /* 0x70 */ virtual void* vt_70() { return _20; } //Weak symbol

public:
    /* 0x18 */ s32 _18;
    /* 0x1C */ s32 _1C;
    /* 0x20 */ void* _20;
};

#endif
