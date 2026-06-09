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

        MessageSenderCallback* mFuncCallbacks[12];
        s32 mCurFuncCount;
    };

    MessageSender();

    virtual ~MessageSender();
    virtual void vt_0C() = 0;
    virtual void vt_10() = 0;
    virtual s32 vt_14(MessageSenderCallback* param_1, int param_2);
    virtual void vt_18();

    bool fn_800EA684(MessageSenderCallback*);

public:
    /* 0x4 */ unkSubClass _4;
};

class IMessageReciever {
public:
    inline virtual ~IMessageReciever() { }
    virtual s32 vt_0C() = 0;
    virtual s32 vt_10() = 0;
    virtual s32 vt_14() = 0;
};

class MessageReciever : public IMessageReciever {
public:
    MessageReciever();

    virtual ~MessageReciever();
    virtual s32 vt_0C();
    virtual s32 vt_10();
    virtual s32 vt_14();
};

#endif
