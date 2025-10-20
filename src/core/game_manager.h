#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <stdbool.h>
#include <stdint.h>
#include "../utils/unity_types.h"

// GameManager structure
typedef struct GameManager {
    int totalCollectibles;
    TextMeshProUGUI* counterText;
    int collectedCount;
    bool isActive;
} GameManager;

// Function declarations
GameManager* GameManager_Create(int totalCollectibles, TextMeshProUGUI* counterText);
void GameManager_Destroy(GameManager* manager);
void GameManager_Start(GameManager* manager);
void GameManager_CollectFragment(GameManager* manager);
int GameManager_GetCollectedCount(const GameManager* manager);
void GameManager_UpdateHUD(GameManager* manager);

#endif // GAME_MANAGER_H
