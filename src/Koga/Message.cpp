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

s32 MessageSender::vt_14(MessageCallback1 fn, int arg0) {
    s32 receiverCount = _4.getCurrentReceiverCount();
    MessageReceiver** instance = _4.getBaseReciever();

    for (s32 i = 0; i < receiverCount; ++instance, ++i) {
        if ((*instance->*fn)(arg0) != 0) {
            return true;
        }
    }

    return false;
}

s32 MessageSender::vt_18(MessageCallback2 fn, int arg0, int arg1) {
    s32 receiverCount = _4.getCurrentReceiverCount();
    MessageReceiver** instance = _4.getBaseReciever();

    for (s32 i = 0; i < receiverCount; ++instance, ++i) {
        if ((*instance->*fn)(arg0, arg1) != 0) {
            return true;
        }
    }

    return false;
}

bool MessageSender::addReceiver(void* receiver) {
    if (_4.getCurrentReceiverCount() < 12) {
        _4.addReceiver((MessageReceiver**)&receiver);
        return true;
    }

    return false;
}

MessageSender::unkSubClass::unkSubClass() { mCurReceiverCount = 0; }

MessageSender::unkSubClass::~unkSubClass() { }

void MessageSender::unkSubClass::addReceiver(MessageReceiver** receiver) {
    mReceivers[mCurReceiverCount++] = *receiver;
}
