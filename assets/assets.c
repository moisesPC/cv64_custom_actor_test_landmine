#include <ultra64.h>

u64 LANDMINE_TXT[] = {
#include "../build/temp/LANDMINE_TXT.rgba16.c"
};

Vtx vertices[] = {
#include "./vertices.inc"
};

Gfx LANDMINE_DL[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
    gsSPClearGeometryMode(G_CULL_BOTH | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR),
    gsSPSetGeometryMode(G_CULL_BACK | G_FOG),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 1, 0, TEXEL0, 0, COMBINED, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED),
    gsDPLoadTextureBlock(LANDMINE_TXT, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR |
                            G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPVertex(vertices, 4, 0),
    gsSP2Triangles(2, 1, 0, 0, 3, 2, 0, 0),
    gsSPEndDisplayList(),
};