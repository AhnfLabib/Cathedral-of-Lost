#ifndef COLLECTIBLE_H
#define COLLECTIBLE_H

#include <stdbool.h>
#include <stdint.h>
#include "utils/unity_types.h"

// Forward declarations
// GameObject, AudioSource are defined in unity_types.h
typedef struct DialogueSequence DialogueSequence;
typedef struct GameManager GameManager;

// CollectGreenGem structure
typedef struct CollectGreenGem {
    GameObject* gameObject;
    AudioSource* collectSound;
    DialogueSequence* dialogueSequence;
    GameManager* gameManager;
    bool isActive;
} CollectGreenGem;

// Function declarations
CollectGreenGem* CollectGreenGem_Create(GameObject* obj);
void CollectGreenGem_Destroy(CollectGreenGem* gem);
void CollectGreenGem_OnTriggerEnter(CollectGreenGem* gem, GameObject* other);
void CollectGreenGem_Reset(CollectGreenGem* gem);
bool CollectGreenGem_IsPlayer(GameObject* obj);

#endif // COLLECTIBLE_H
