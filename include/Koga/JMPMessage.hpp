#ifndef JMP_MESSAGE_H_
#define JMP_MESSAGE_H_

#include "Koga/Message.hpp"

class JmpMessageSender : public MessageSender {
public:

    JmpMessageSender();

    /* 0x08 */ virtual ~JmpMessageSender();
    /* 0x0C */ virtual void vt_0C();
    /* 0x10 */ virtual void vt_10();
    /* 0x14 */ virtual s32 vt_14(MessageCallback1 fn, int arg0);
    /* 0x18 */ virtual s32 vt_18(MessageCallback2 fn, int arg0, int arg1);

    bool fn_800EA684(MessageSender*);

public:
    /* 0x38 */ u8 _38[0xDF0 - sizeof(MessageSender)];
};

#endif
