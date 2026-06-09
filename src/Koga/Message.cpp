#include "Koga/Message.hpp"

dummy_float_data()

MessageReceiver::MessageReceiver() {}

MessageReceiver::~MessageReceiver() {}

s32 MessageReceiver::vt_0C() { return 0; }

s32 MessageReceiver::vt_10(int arg0) { return 0; }

s32 MessageReceiver::vt_14(int arg0, int arg1) { return 0; }

//https://decomp.me/scratch/FS7IN
MessageSender::MessageSender() { }

//https://decomp.me/scratch/AvZyL
MessageSender::~MessageSender() { }

bool MessageSender::fn_800EA684(MessageReceiver* param_1) {
    if (_4.getCurrentReceiverCount() < 12) {
        _4.addReceiver(&param_1);
        return true;
    }

    return false;
}

//https://decomp.me/scratch/pKs7k
s32 MessageSender::vt_14(MessageCallback1 fn, int arg0) {
    s32 funcCount = _4.getCurrentReceiverCount();
    MessageReceiver** instance = (MessageReceiver**)_4.mReceivers;
    s32 i = 0;
    while (i < funcCount) {
        u32 result = (*instance->*fn)(arg0);
        u32 value = result & 0xFF;
        if (value != 0) {
            return true;
        }
        ++instance;
        ++i;
    }
    return false;
}

s32 MessageSender::vt_18(MessageCallback2 fn, int arg0, int arg1) {
    s32 funcCount = _4.getCurrentReceiverCount();
    MessageReceiver** instance = (MessageReceiver**)_4.mReceivers;
    s32 i = 0;
    while (i < funcCount) {
        u32 result = (*instance->*fn)(arg0, arg1);
        u32 value = result & 0xFF;
        if (value != 0) {
            return true;
        }
        ++instance;
        ++i;
    }
    return false;
}

MessageSender::unkSubClass::unkSubClass()
{
    mCurReceiverCount = 0;
}

MessageSender::unkSubClass::~unkSubClass() {}

void MessageSender::unkSubClass::addReceiver(MessageReceiver** receiver) {
    mReceivers[mCurReceiverCount++] = *receiver;
}
