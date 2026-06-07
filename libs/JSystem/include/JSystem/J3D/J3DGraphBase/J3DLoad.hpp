//This is fabricated
#ifndef J3D_LOAD_HPP
#define J3D_LOAD_HPP

#include <JSystem/J3D/J3DGraphBase/Components/J3DGXColor.hpp>
#include "JSystem/J3D/J3DGraphBase/Components/J3DGXColorS10.hpp"
#include <JSystem/J3D/J3DGraphBase/Components/J3DIndTexMtx.hpp>
#include <JSystem/J3D/J3DGraphBase/Components/J3DTexCoord.hpp>
#include <dolphin/gx.h>
#include <types.h>

void loadCullMode(u8);
void loadTexNo(u8, const u16&);
void loadChanMatColor(u8, const GXColor&);
void loadChanAmbColor(u8, const GXColor&);
void loadColorChanNum(u8);
void loadTexGenNum(u8);
void loadDither(u8);
void loadTexCoordGen(J3DTexCoord, u8);
void loadTevColor(u8, const J3DGXColorS10& color);
void loadTevKColor(u8, const J3DGXColor& color);
//void loadTevKColor
#endif
