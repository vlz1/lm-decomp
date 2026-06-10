#ifndef KOGA_ARRAY_H_
#define KOGA_ARRAY_H_

#include "types.h"

namespace Koga {
    template <typename T, s32 S>
    class Array {
    public:
        Array() { FORCE_DONT_INLINE mArraySize = 0; }
        ~Array() {  FORCE_DONT_INLINE }

        void add(T* member) {
            FORCE_DONT_INLINE;
            mArr[mArraySize++] = *member;
        }

        s32 getArraySize() const { return mArraySize; }
        T* getArrayMember(s32 idx) const { return mArr[idx]; }
        T* getArray() { return mArr; }

        /* 0x00 */ T mArr[S];
        /* (0x4 * S) + 4 */ s32 mArraySize;
    };

};

#endif
