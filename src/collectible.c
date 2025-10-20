#include "collectible.h"
#include "core/game_manager.h"
#include "utils/unity_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a new CollectGreenGem instance
CollectGreenGem* CollectGreenGem_Create(GameObject* obj) {
    CollectGreenGem* gem = (CollectGreenGem*)malloc(sizeof(CollectGreenGem));
    if (!gem) return NULL;
    
    gem->gameObject = obj;
    gem->collectSound = NULL;
    gem->dialogueSequence = NULL;
    gem->gameManager = NULL;
    gem->isActive = true;
    
    // Auto-setup collider as trigger (equivalent to Reset() in C#)
    CollectGreenGem_Reset(gem);
    
    return gem;
}

// Destroy CollectGreenGem instance
void CollectGreenGem_Destroy(CollectGreenGem* gem) {
    if (gem) {
        free(gem);
    }
}

// Reset function - equivalent to C# Reset()
void CollectGreenGem_Reset(CollectGreenGem* gem) {
    if (!gem || !gem->gameObject) return;
    
    // Set collider as trigger
    Collider* col = (Collider*)gem->gameObject->collider;
    if (col) {
        col->isTrigger = true;
    }
}

// Check if GameObject is player
bool CollectGreenGem_IsPlayer(GameObject* obj) {
    if (!obj) return false;
    return GameObject_CompareTag(obj, "Player");
}

// OnTriggerEnter equivalent
void CollectGreenGem_OnTriggerEnter(CollectGreenGem* gem, GameObject* other) {
    if (!gem || !gem->isActive || !other) return;
    
    // Check if other is player
    if (!CollectGreenGem_IsPlayer(other)) return;
    
    // 1) Play pickup SFX
    if (gem->collectSound) {
        AudioSource_Play(gem->collectSound);
    }
    
    // 2) Increment the level counter
    if (gem->gameManager) {
        GameManager_CollectFragment(gem->gameManager);
    } else {
        printf("CollectGreenGem: GameManager not assigned!\n");
    }
    
    // 3) Show dialogue UI (placeholder - would need DialogueSequence implementation)
    if (gem->dialogueSequence) {
        // DialogueSequence_ShowDialogue(gem->dialogueSequence);
        printf("Dialogue sequence would be shown here\n");
    } else {
        printf("CollectGreenGem: DialogueSequence not assigned!\n");
    }
    
    // 4) Destroy this collectible so it can't be re-collected
    gem->isActive = false;
    GameObject_Destroy(gem->gameObject);
}
