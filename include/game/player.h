#ifndef PLAYER_H
#define PLAYER_H

#include "model_info.h"
#include <ultratypes.h>

enum enum_player_flags {
    DEAD = 0x80000000
};

enum axis_enum {
    X =   1,
    Y =   2,
    Z =   4,
    XYZ = 8
};

extern u32 player_flags;
extern model_info* player_model;
extern u32 playerIsInsideActorSpawnRadius(model_info* player_model, model_info* actor_model, f32 actor_spawn_radius, u32 axis);

#endif