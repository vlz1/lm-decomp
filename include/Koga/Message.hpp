#ifndef MESSAGE_H_
#define MESSAGE_H_

#include "types.h"

class MessageSender {
public:
    typedef bool (MessageSender::*MessageSenderCallback)(int val);

    class unkSubClass {
    public:
        unkSubClass();
        ~unkSubClass();

        void addSenderCallback(MessageSenderCallback**);
        s32 getCurrentFuncCount() const { return mCurFuncCount; }
        MessageSenderCallback getFuncCallback(s32 idx) const { return *mFuncCallbacks[idx]; }

        /* 0x00 */ MessageSenderCallback* mFuncCallbacks[12];
        /* 0x30 */ s32 mCurFuncCount;
    };

    MessageSender();

    /* 0x08 */ virtual ~MessageSender();
    /* 0x0C */ virtual void vt_0C() = 0;
    /* 0x10 */ virtual void vt_10() = 0;
    /* 0x14 */ virtual s32 vt_14(MessageSenderCallback* param_1, int param_2);
    /* 0x18 */ virtual void vt_18();

    bool fn_800EA684(MessageSenderCallback*);

public:
    /* 0x4 */ unkSubClass _4;
};

class IMessageReciever {
public:
    //Seems to be inlined where its used and doesn't show up in the final binary
    /* 0x08 */ inline virtual ~IMessageReciever() { }
    /* 0x0C */ virtual s32 vt_0C() = 0;
    /* 0x10 */ virtual s32 vt_10() = 0;
    /* 0x14 */ virtual s32 vt_14() = 0;
};

class MessageReciever : public IMessageReciever {
public:
    MessageReciever();

    /* 0x08 */ virtual ~MessageReciever();
    /* 0x0C */ virtual s32 vt_0C();
    /* 0x10 */ virtual s32 vt_10();
    /* 0x14 */ virtual s32 vt_14();
};

#endif
