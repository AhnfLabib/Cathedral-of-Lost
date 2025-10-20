#include "game_manager.h"
#include "../utils/unity_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a new GameManager instance
GameManager* GameManager_Create(int totalCollectibles, TextMeshProUGUI* counterText) {
    GameManager* manager = (GameManager*)malloc(sizeof(GameManager));
    if (!manager) return NULL;
    
    manager->totalCollectibles = totalCollectibles;
    manager->counterText = counterText;
    manager->collectedCount = 0;
    manager->isActive = true;
    
    return manager;
}

// Destroy GameManager instance
void GameManager_Destroy(GameManager* manager) {
    if (manager) {
        free(manager);
    }
}

// Start function - equivalent to C# Start()
void GameManager_Start(GameManager* manager) {
    if (!manager || !manager->isActive) return;
    
    GameManager_UpdateHUD(manager);
}

// CollectFragment function - equivalent to C# CollectFragment()
void GameManager_CollectFragment(GameManager* manager) {
    if (!manager || !manager->isActive) return;
    
    // Increment collected count, but don't exceed total
    if (manager->collectedCount < manager->totalCollectibles) {
        manager->collectedCount++;
    }
    
    GameManager_UpdateHUD(manager);
}

// Get collected count - equivalent to C# CollectedCount property
int GameManager_GetCollectedCount(const GameManager* manager) {
    if (!manager) return 0;
    return manager->collectedCount;
}

// UpdateHUD function - equivalent to C# UpdateHUD()
void GameManager_UpdateHUD(GameManager* manager) {
    if (!manager || !manager->isActive || !manager->counterText) return;
    
    char hudText[256];
    snprintf(hudText, sizeof(hudText), 
             "Souls Collected on this Level: %d/%d", 
             manager->collectedCount, 
             manager->totalCollectibles);
    
    TextMeshProUGUI_SetText(manager->counterText, hudText);
}
