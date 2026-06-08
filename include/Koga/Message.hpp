#ifndef MESSAGE_H_
#define MESSAGE_H_

#include "types.h"

class MessageSender {
public:
    virtual ~MessageSender();
    virtual void vt_0C() = 0;
    virtual void vt_10() = 0;
    virtual void vt_14();
    virtual void vt_18();
};

#endif
