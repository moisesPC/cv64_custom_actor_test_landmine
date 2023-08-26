#ifndef LANDMINE_H
#define LANDMINE_H

#include "model_info.h"
#include "module.h"
#include "actor_settings.h"
#include "landmine_constants.h"

typedef struct {
    ModuleHeader header;
    u8 field_0x20[4];               // Necessary padding because "model" should be field 0x24
    model_info* model;
    void* nitroExplosion;           // Module 0x007F
    u8 padding[0x70 - 0x2C];        // Necessary padding because "settings" should be field 0x70
    actor_settings* settings;
} landmine;

void landmine_entrypoint(landmine* self);
void landmine_init(landmine* self);
void landmine_loop(landmine* self);

void (*landmine_functions[])(landmine* self) = {
    landmine_init,
    landmine_loop
};

#endif
