//This is fabricated
#ifndef J3D_LOAD_HPP
#define J3D_LOAD_HPP

#include <dolphin/gx.h>
#include <types.h>

void loadCullMode(u8);
void loadTexNo(u32, const u16&);
void loadChanMatColor(u8, GXColor);
void loadChanAmbColor(u8, GXColor);
void loadColorChanNum(u8);
void loadTexGenNum(u8);
void loadDither(u8);

#endif
