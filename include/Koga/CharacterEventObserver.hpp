#ifndef CHARACTER_EVENT_OBSERVER_H_
#define CHARACTER_EVENT_OBSERVER_H_

#include "Koga/Observer.hpp"
#include "dolphin/types.h"

namespace Koga {
    class CharacterEvent {
    public:
        enum Message {
            MESSAGE_TRUE,
            MESSAGE_ENTERED_FLASHLIGHT_BEAM = 2,
            MESSAGE_CAPTURE_BEGIN,
            MESSAGE_CAPTURE_END,
            MESSAGE_UNK8 = 8,
            MESSAGE_FISHING_BEGIN,
            MESSAGE_PLAYER_LEFT_ROOM,
            MESSAGE_PLAYER_ENTERED_ROOM,
            MESSAGE_COLLIDE_WITH_PLAYER,
            MESSAGE_SPRAYED_WITH_FIRE,
            MESSAGE_SPRAYED_WITH_ICE,
            MESSAGE_SPRAYED_WITH_WATER,
            MESSAGE_HIT_WITH_FIREBALL,
            MESSAGE_HIT_WITH_ICEBALL ,
            MESSAGE_HIT_WITH_WATERBALL,
            MESSAGE_PLAYER_TAPPED,
            MESSAGE_UNK_29 = 29
        };

        CharacterEvent(const Message& message);

        /* 0x00 */ Message mMessage;
        /* 0x04 */ s32 m_4;
        /* 0x08 */ s32 m_8;
        /* 0x0C */ s32 m_C;
        /* 0x10 */ s32 m_10;
        /* 0x14 */ s32 m_14;
        /* 0x18 */ s32 m_18;

        /* 0x1C */ bool* mUnknownEntityBools;
    };

    class CharacterEventObserver : public Observer< CharacterEvent, bool > {
    public:
        virtual bool receiveMessage(CharacterEvent* msg);

        /* Called while the actor is inside the flashlight cone. */
        virtual bool onEnteredFlashlightBeam(CharacterEvent* msg);

        /* Called when the actor's HP hits 0 while being fished. */
        virtual bool onCaptureBegin(CharacterEvent* msg);
        /* Called when the actor has been sucked into the Poltergust. */
        virtual bool onCaptureEnd(CharacterEvent* msg);

        /* TODO: What does this do? */
        virtual bool vt_10(CharacterEvent* msg);

        /* Called when the actor collides with the player. */
        virtual bool onCollideWithPlayer(CharacterEvent* msg);

        /* Called when the actor is exposed to fire. */
        virtual bool onSprayedWithFire(CharacterEvent* msg);
        /* Called when the actor is exposed to ice. */
        virtual bool onSprayedWithIce(CharacterEvent* msg);
        /* Called when the actor is exposed to water. */
        virtual bool onSprayedWithWater(CharacterEvent* msg);

        /* Called when the actor is hit with a fire elemental ball. */
        virtual bool onHitWithFireBall(CharacterEvent* msg);
        /* Called when the actor is hit with an ice elemental ball. */
        virtual bool onHitWithIceBall(CharacterEvent* msg);
        /* Called when the actor is hit with a water elemental ball. */
        virtual bool onHitWithWaterBall(CharacterEvent* msg);

        /* Called when the actor is hooked by the Poltergust. */
        virtual bool onFishingBegin(CharacterEvent* msg);

        /* Called when the player leaves the actor's current room. */
        virtual bool onPlayerLeftRoom(CharacterEvent* msg);
        /* Called when the player enters the actor's current room. */
        virtual bool onPlayerEnteredRoom(CharacterEvent* msg);

        /* Called when the player presses the A button on the actor; treasure chests only? */
        virtual bool onPlayerTapped(CharacterEvent* msg);

        /* TODO: What does this do? */
        virtual bool vt_40(CharacterEvent* msg);
    };
}  // namespace Koga

#endif
