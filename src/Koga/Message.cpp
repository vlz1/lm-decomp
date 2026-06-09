#include "Koga/Message.hpp"

dummy_float_data()



MessageReciever::MessageReciever() {}

MessageReciever::~MessageReciever() {}

s32 MessageReciever::vt_0C() { return 0; }

s32 MessageReciever::vt_10() { return 0; }

s32 MessageReciever::vt_14() { return 0; }

MessageSender::MessageSender() { }

MessageSender::~MessageSender() { }

bool MessageSender::fn_800EA684(MessageSenderCallback* param_1) {
    if (_4.getCurrentFuncCount() < 12) {
        _4.addSenderCallback(&param_1);
        return true;
    }

    return false;
}

s32 MessageSender::vt_14(MessageSenderCallback* param_1, int param_2) {
    s32 funcCount = _4.getCurrentFuncCount();
    MessageSenderCallback* func = _4.mFuncCallbacks[0];

    for (s32 i = 0; i < funcCount; i++) {
         if ((this->**func)(param_2)) return true;
        //if (_4.getFuncCallback(i)) return true;
        //func = ((func) + 1;
        func = func + 1;
    }
    return false;
}

MessageSender::unkSubClass::unkSubClass()
{
    mCurFuncCount = 0;
}

MessageSender::unkSubClass::~unkSubClass() {}

void MessageSender::unkSubClass::addSenderCallback(MessageSenderCallback** newFunc) {
    mFuncCallbacks[mCurFuncCount++] = *newFunc;
}
