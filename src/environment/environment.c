#include "environment.h"
#include "../core/game_manager.h"
#include "../utils/unity_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==================== TELEPORT ====================

Teleport* Teleport_Create(GameObject* player, GameObject* destination) {
    Teleport* teleport = (Teleport*)malloc(sizeof(Teleport));
    if (!teleport) return NULL;
    
    teleport->player = player;
    teleport->destination = destination;
    teleport->isActive = true;
    
    return teleport;
}

void Teleport_Destroy(Teleport* teleport) {
    if (teleport) {
        free(teleport);
    }
}

void Teleport_OnTriggerEnter(Teleport* teleport, GameObject* other) {
    if (!teleport || !teleport->isActive || !other || !teleport->player || !teleport->destination) return;
    
    // Simple teleport - move player to destination
    teleport->player->transform.position = teleport->destination->transform.position;
}

// ==================== WALL VANISH ====================

WallVanish* WallVanish_Create(GameObject* target, bool destroyInstead, const char* playerTag) {
    WallVanish* wallVanish = (WallVanish*)malloc(sizeof(WallVanish));
    if (!wallVanish) return NULL;
    
    wallVanish->target = target;
    wallVanish->destroyInstead = destroyInstead;
    strncpy(wallVanish->playerTag, playerTag ? playerTag : "Player", sizeof(wallVanish->playerTag) - 1);
    wallVanish->playerTag[sizeof(wallVanish->playerTag) - 1] = '\0';
    wallVanish->vanishSound = NULL;
    wallVanish->isActive = true;
    
    WallVanish_Reset(wallVanish);
    
    return wallVanish;
}

void WallVanish_Destroy(WallVanish* wallVanish) {
    if (wallVanish) {
        free(wallVanish);
    }
}

void WallVanish_Reset(WallVanish* wallVanish) {
    if (!wallVanish) return;
    
    // Ensure collider is set as trigger (would need collider access)
    // This is a placeholder - actual implementation would set collider->isTrigger = true
}

void WallVanish_OnTriggerEnter(WallVanish* wallVanish, GameObject* other) {
    if (!wallVanish || !wallVanish->isActive || !other) return;
    
    if (!GameObject_CompareTag(other, wallVanish->playerTag)) return;
    
    // Play the sound if assigned
    if (wallVanish->vanishSound) {
        AudioSource_Play(wallVanish->vanishSound);
    }
    
    // Vanish the target
    WallVanish_VanishTarget(wallVanish);
}

void WallVanish_VanishTarget(WallVanish* wallVanish) {
    if (!wallVanish || !wallVanish->target) return;
    
    if (wallVanish->destroyInstead) {
        GameObject_Destroy(wallVanish->target);
    } else {
        GameObject_SetActive(wallVanish->target, false);
    }
}

// ==================== BELL VANISH ====================

BellVanish* BellVanish_Create(AudioSource* bellSound, AudioSource* wallMovingSound, 
                              GameObject* wallTarget, bool destroyWall, float wallDelay,
                              GameManager* gameManager, const char* playerTag) {
    BellVanish* bellVanish = (BellVanish*)malloc(sizeof(BellVanish));
    if (!bellVanish) return NULL;
    
    bellVanish->bellSound = bellSound;
    bellVanish->wallMovingSound = wallMovingSound;
    bellVanish->wallTarget = wallTarget;
    bellVanish->destroyWall = destroyWall;
    bellVanish->wallDelay = wallDelay;
    bellVanish->gameManager = gameManager;
    strncpy(bellVanish->playerTag, playerTag ? playerTag : "Player", sizeof(bellVanish->playerTag) - 1);
    bellVanish->playerTag[sizeof(bellVanish->playerTag) - 1] = '\0';
    bellVanish->triggered = false;
    bellVanish->isActive = true;
    
    BellVanish_Reset(bellVanish);
    
    return bellVanish;
}

void BellVanish_Destroy(BellVanish* bellVanish) {
    if (bellVanish) {
        free(bellVanish);
    }
}

void BellVanish_Reset(BellVanish* bellVanish) {
    if (!bellVanish) return;
    
    // Ensure collider is set as trigger (would need collider access)
    // This is a placeholder - actual implementation would set collider->isTrigger = true
}

void BellVanish_OnTriggerEnter(BellVanish* bellVanish, GameObject* other) {
    if (!bellVanish || !bellVanish->isActive || !other) return;
    
    if (bellVanish->triggered || !GameObject_CompareTag(other, bellVanish->playerTag)) return;
    
    bellVanish->triggered = true;
    BellVanish_HandleBell(bellVanish);
}

void BellVanish_HandleBell(BellVanish* bellVanish) {
    if (!bellVanish) return;
    
    // Ring the bell for everyone
    if (bellVanish->bellSound) {
        AudioSource_Play(bellVanish->bellSound);
    }
    
    // Only open if you've collected all for THIS level
    if (!bellVanish->gameManager) {
        printf("BellVanish: GameManager not assigned!\n");
        return;
    }
    
    if (GameManager_GetCollectedCount(bellVanish->gameManager) < bellVanish->gameManager->totalCollectibles) {
        return;
    }
    
    // Wait then move the wall (simplified - no actual coroutine)
    // In a real implementation, this would use a coroutine system
    printf("Bell triggered - wall will move after delay\n");
    
    // For now, just move the wall immediately (in real implementation, use coroutine)
    if (bellVanish->wallMovingSound) {
        AudioSource_Play(bellVanish->wallMovingSound);
    }
    
    if (bellVanish->wallTarget) {
        if (bellVanish->destroyWall) {
            GameObject_Destroy(bellVanish->wallTarget);
        } else {
            GameObject_SetActive(bellVanish->wallTarget, false);
        }
    }
}

// ==================== COROUTINE SUPPORT ====================

Coroutine* Coroutine_Start(float delay, void (*callback)(void*), void* data) {
    Coroutine* coroutine = (Coroutine*)malloc(sizeof(Coroutine));
    if (!coroutine) return NULL;
    
    coroutine->isRunning = true;
    coroutine->delay = delay;
    coroutine->elapsed = 0.0f;
    coroutine->callback = callback;
    coroutine->data = data;
    
    return coroutine;
}

void Coroutine_Update(Coroutine* coroutine, float deltaTime) {
    if (!coroutine || !coroutine->isRunning) return;
    
    coroutine->elapsed += deltaTime;
    
    if (coroutine->elapsed >= coroutine->delay) {
        if (coroutine->callback) {
            coroutine->callback(coroutine->data);
        }
        coroutine->isRunning = false;
    }
}

void Coroutine_Stop(Coroutine* coroutine) {
    if (coroutine) {
        coroutine->isRunning = false;
    }
}
