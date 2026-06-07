//This is fabricated
#ifndef J3D_LOAD_HPP
#define J3D_LOAD_HPP

#include <JSystem/J3D/J3DGraphBase/Components/J3DTexCoord.hpp>
#include <dolphin/gx.h>
#include <types.h>

void loadCullMode(u8);
void loadTexNo(u8, const u16&);
void loadChanMatColor(u8, GXColor);
void loadChanAmbColor(u8, GXColor);
void loadColorChanNum(u8);
void loadTexGenNum(u8);
void loadDither(u8);
void loadTexCoordGen(J3DTexCoord, u8);

#endif
