#include "movement.h"
#include "../utils/unity_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Create a new FirstPersonMovementImproved instance
FirstPersonMovementImproved* FirstPersonMovementImproved_Create(GameObject* player) {
    FirstPersonMovementImproved* movement = (FirstPersonMovementImproved*)malloc(sizeof(FirstPersonMovementImproved));
    if (!movement) return NULL;
    
    movement->player = player;
    movement->speed = 20.0f;
    movement->velocity = Vector3_Create(0, 0, 0);
    movement->gravity = -9.81f;
    movement->groundCheck = NULL;
    movement->groundDistance = 0.4f;
    movement->groundMask = 0;
    movement->isGrounded = false;
    movement->jumpHeight = 3.0f;
    movement->isActive = true;
    
    return movement;
}

// Destroy FirstPersonMovementImproved instance
void FirstPersonMovementImproved_Destroy(FirstPersonMovementImproved* movement) {
    if (movement) {
        free(movement);
    }
}

// Update function - equivalent to C# Update()
void FirstPersonMovementImproved_Update(FirstPersonMovementImproved* movement) {
    if (!movement || !movement->isActive || !movement->player) return;
    
    // Ground check (commented out in original C#)
    // FirstPersonMovementImproved_CheckGround(movement);
    
    // Step 1: get input and move player
    Vector3 input = FirstPersonMovementImproved_GetInput(movement);
    FirstPersonMovementImproved_Move(movement, input);
    
    // Gravity (commented out in original C#)
    // FirstPersonMovementImproved_ApplyGravity(movement);
    
    // Jump (commented out in original C#)
    // FirstPersonMovementImproved_HandleJump(movement);
}

// Check ground - equivalent to commented ground check in C#
void FirstPersonMovementImproved_CheckGround(FirstPersonMovementImproved* movement) {
    if (!movement || !movement->groundCheck) return;
    
    // This would require a physics system implementation
    // isGrounded = Physics.CheckSphere(groundCheck.position, groundDistance, groundMask);
    // if (isGrounded && velocity.y < 0) {
    //     velocity.y = -2f;
    // }
}

// Apply gravity - equivalent to commented gravity in C#
void FirstPersonMovementImproved_ApplyGravity(FirstPersonMovementImproved* movement) {
    if (!movement) return;
    
    // velocity.y += gravity * Time.deltaTime;
    // controller.Move(velocity * Time.deltaTime);
}

// Handle jump - equivalent to commented jump in C#
void FirstPersonMovementImproved_HandleJump(FirstPersonMovementImproved* movement) {
    if (!movement) return;
    
    // if (isGrounded && Input.GetButtonDown("Jump")) {
    //     velocity.y = Mathf.Sqrt(jumpHeight * -2f * gravity);
    // }
}

// Get input - equivalent to Input.GetAxis calls
Vector3 FirstPersonMovementImproved_GetInput(FirstPersonMovementImproved* movement) {
    if (!movement) return Vector3_Create(0, 0, 0);
    
    float x = GetAxis("Horizontal");
    float z = GetAxis("Vertical");
    
    // This would need transform.right and transform.forward calculations
    // For now, return basic input
    return Vector3_Create(x, 0, z);
}

// Move player - equivalent to controller.Move()
void FirstPersonMovementImproved_Move(FirstPersonMovementImproved* movement, Vector3 move) {
    if (!movement || !movement->player) return;
    
    // Scale by speed and delta time
    move.x *= movement->speed;
    move.z *= movement->speed;
    
    // This would need CharacterController implementation
    // CharacterController* controller = (CharacterController*)movement->player->collider;
    // controller->Move(move * Time.deltaTime);
    
    // For now, just update position directly
    movement->player->transform.position.x += move.x * 0.016f; // Assuming 60 FPS
    movement->player->transform.position.z += move.z * 0.016f;
}

// Input system functions (would be provided by actual input system)
float GetAxis(const char* axis) {
    // This would interface with actual input system
    // For now, return 0
    return 0.0f;
}

bool GetButtonDown(const char* button) {
    // This would interface with actual input system
    // For now, return false
    return false;
}
