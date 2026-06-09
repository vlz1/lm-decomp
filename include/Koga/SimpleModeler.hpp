#ifndef SIMPLE_MODELER_H_
#define SIMPLE_MODELER_H_

#include "types.h"
#include <JSystem/JORReflexible.hpp>

namespace Koga {
    class SimpleModeler : public JORReflexible {
    public:
        SimpleModeler();
        /* 0x08 */ virtual ~SimpleModeler();

        static void newSimpleModeler();
        static void deleteSimpleModeler();
        static SimpleModeler* getCurSimpleModeler() { return sCurSimpleModeler; }
        void fn_800BB778();

    public:
        /* 0x04 */  u8 _4[0xC10];

        static SimpleModeler* sCurSimpleModeler;
    };

};

#endif
