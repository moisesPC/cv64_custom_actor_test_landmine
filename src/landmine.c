#include "landmine.h"
#include "player.h"
#include "cv64.h"

// Entrypoint function. Executed every frame as long as the landmine is active
void landmine_entrypoint(landmine* self) {
    
    // Avoid triggering other explosions if you've been hit already
    // (in case you touch another landmine while exploding)
    if ((player_flags & DEAD) == FALSE) {
        self->header.functionInfo_ID++;
        landmine_functions[self->header.current_function[self->header.functionInfo_ID].function](self);
        self->header.functionInfo_ID--;
    }
}

// Initialization function. Only executed once
void landmine_init(landmine* self) {
    model_info* (*ptr_modelInfo_createRootNode)(u32, void*) = modelInfo_createRootNode;
    void (*ptr_actor_model_set_pos)(void*, model_info*) = actor_model_set_pos;
    void (*ptr_goToNextFunc)(s8*, s16*) = goToNextFunc;

    self->nitroExplosion = NULL;
    
    self->model = ptr_modelInfo_createRootNode(4, ptr_array_8018CDE0[0]);
    self->model->assets_file_ID = LANDMINE_ASSETS_FILE;                     // Landmine's assets file ID in the Nisitenma-Ichigo table
    self->model->display_list_address = LANDMINE_DL;                        // Landmine's main display list segment address
    self->model->flags |= (LOOK_AT_CAMERA_PITCH | LOOK_AT_CAMERA_YAW);      // Make the landmine texture look at the camera

    ptr_actor_model_set_pos(self, self->model);

    // Initialize landmine's size
    self->model->size.x = self->model->size.y = self->model->size.z = LANDMINE_MODEL_SIZE;

    // Go to the first state function (landmine_rise_up)
    ptr_goToNextFunc(self->header.current_function, &self->header.functionInfo_ID);
}

void landmine_loop(landmine* self) {
    u32 (*ptr_playerIsInsideActorSpawnRadius)(model_info*, model_info*, f32, u32) = playerIsInsideActorSpawnRadius;
    void* (*ptr_module_createAndSetChild)(void* parent, s32 ID) = module_createAndSetChild;
    
    if (ptr_playerIsInsideActorSpawnRadius(&player_model, self->model, LANDMINE_TRIGGER_RADIUS, XYZ)) {
        self->nitroExplosion = ptr_module_createAndSetChild(self, ACTOR_NITRO_EXPLOSION);
        self->model->type |= HIDE;
    }
}