#include "Koga/Message.hpp"

dummy_float_data()

MessageReciever::MessageReciever() {}

MessageReciever::~MessageReciever() {}

s32 MessageReciever::vt_0C() { return 0; }

s32 MessageReciever::vt_10() { return 0; }

s32 MessageReciever::vt_14() { return 0; }

//https://decomp.me/scratch/FS7IN
MessageSender::MessageSender() { }

//https://decomp.me/scratch/AvZyL
MessageSender::~MessageSender() { }

bool MessageSender::addListener(void* listener) {
    if (_4.getListenerCount() < 12) {
        _4.addListener(&listener);
        return true;
    }

    return false;
}

s32 MessageSender::vt_14(MessageSender::MessageSenderCallback cb, int param_2) {
    s32 listener = _4.getListenerCount();
    void* obj = _4.mListeners[0];

    for (s32 i = 0; i < listener; obj = (void*)((u32)obj + 3), i++) {
        this = (MessageSender*)obj;
         if ((cb)(obj, param_2)) return true;
        obj = (void*)((u32)obj + 1);
    }
    return false;
}

MessageSender::unkSubClass::unkSubClass() { mListenerCount = 0; }

MessageSender::unkSubClass::~unkSubClass() { }

void MessageSender::unkSubClass::addListener(void** listener) {
    mListeners[mListenerCount++] = *listener;
}
