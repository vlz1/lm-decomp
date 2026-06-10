#include "Koga/JmpMessage.hpp"
#include "Koga/ToolData.hpp"

dummy_float_data()

JmpMessageSender::JmpMessageSender() {
    _CE8 = 0;
}

JmpMessageSender::~JmpMessageSender() { }

BOOL JmpMessageSender::fn_800EA900(Koga::ToolData* data) {
    Koga::ToolData* toolData = data;

    if (_CBC.getArraySize() >= 10) {
        return FALSE;
    }
    if (toolData == nullptr) return FALSE;

    _CBC.add(&toolData);
    return true;
}

unkJmpMessageSender1Arr::unkJmpMessageSender1Arr() : _C80(0) { }

unkJmpMessageSender1Arr::~unkJmpMessageSender1Arr() { }

unkJmpMessageSender1::unkJmpMessageSender1() : _0(0) { }
