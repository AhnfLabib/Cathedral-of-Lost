#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <stdbool.h>
#include <stdint.h>
#include "../utils/unity_types.h"

// Forward declarations
// GameObject, AudioSource are defined in unity_types.h
typedef struct GameManager GameManager;

// Teleport structure
typedef struct Teleport {
    GameObject* player;
    GameObject* destination;
    bool isActive;
} Teleport;

// WallVanish structure
typedef struct WallVanish {
    GameObject* target;
    bool destroyInstead;
    char playerTag[32];
    AudioSource* vanishSound;
    bool isActive;
} WallVanish;

// BellVanish structure
typedef struct BellVanish {
    AudioSource* bellSound;
    AudioSource* wallMovingSound;
    GameObject* wallTarget;
    bool destroyWall;
    float wallDelay;
    GameManager* gameManager;
    char playerTag[32];
    bool triggered;
    bool isActive;
} BellVanish;

// Function declarations for Teleport
Teleport* Teleport_Create(GameObject* player, GameObject* destination);
void Teleport_Destroy(Teleport* teleport);
void Teleport_OnTriggerEnter(Teleport* teleport, GameObject* other);

// Function declarations for WallVanish
WallVanish* WallVanish_Create(GameObject* target, bool destroyInstead, const char* playerTag);
void WallVanish_Destroy(WallVanish* wallVanish);
void WallVanish_Reset(WallVanish* wallVanish);
void WallVanish_OnTriggerEnter(WallVanish* wallVanish, GameObject* other);
void WallVanish_VanishTarget(WallVanish* wallVanish);

// Function declarations for BellVanish
BellVanish* BellVanish_Create(AudioSource* bellSound, AudioSource* wallMovingSound, 
                              GameObject* wallTarget, bool destroyWall, float wallDelay,
                              GameManager* gameManager, const char* playerTag);
void BellVanish_Destroy(BellVanish* bellVanish);
void BellVanish_Reset(BellVanish* bellVanish);
void BellVanish_OnTriggerEnter(BellVanish* bellVanish, GameObject* other);
void BellVanish_HandleBell(BellVanish* bellVanish);

// Coroutine support (simplified)
typedef struct Coroutine {
    bool isRunning;
    float delay;
    float elapsed;
    void (*callback)(void*);
    void* data;
} Coroutine;

Coroutine* Coroutine_Start(float delay, void (*callback)(void*), void* data);
void Coroutine_Update(Coroutine* coroutine, float deltaTime);
void Coroutine_Stop(Coroutine* coroutine);

#endif // ENVIRONMENT_H
