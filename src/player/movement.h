#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <stdbool.h>
#include <stdint.h>
#include "../utils/unity_types.h"

// Forward declarations
typedef struct CharacterController CharacterController;

// FirstPersonMovementImproved structure
typedef struct FirstPersonMovementImproved {
    GameObject* player;
    float speed;
    Vector3 velocity;
    float gravity;
    Transform* groundCheck;
    float groundDistance;
    uint32_t groundMask;
    bool isGrounded;
    float jumpHeight;
    bool isActive;
} FirstPersonMovementImproved;

// Function declarations
FirstPersonMovementImproved* FirstPersonMovementImproved_Create(GameObject* player);
void FirstPersonMovementImproved_Destroy(FirstPersonMovementImproved* movement);
void FirstPersonMovementImproved_Update(FirstPersonMovementImproved* movement);
void FirstPersonMovementImproved_CheckGround(FirstPersonMovementImproved* movement);
void FirstPersonMovementImproved_ApplyGravity(FirstPersonMovementImproved* movement);
void FirstPersonMovementImproved_HandleJump(FirstPersonMovementImproved* movement);
Vector3 FirstPersonMovementImproved_GetInput(FirstPersonMovementImproved* movement);
void FirstPersonMovementImproved_Move(FirstPersonMovementImproved* movement, Vector3 move);

// Input functions (would be provided by input system)
float GetAxis(const char* axis);
bool GetButtonDown(const char* button);

#endif // MOVEMENT_H
