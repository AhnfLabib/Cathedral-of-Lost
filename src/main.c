#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils/unity_types.h"
#include "core/game_manager.h"
#include "core/global_score.h"
#include "collectible.h"
#include "player/movement.h"
#include "environment/environment.h"
#include "sequences/sequences.h"

// Example usage of the converted C code
int main() {
    printf("Cathedral of Lost Scripts - C Implementation Example\n");
    printf("==================================================\n\n");
    
    // Create basic game objects
    GameObject player = {0};
    strcpy(player.tag, "Player");
    player.active = true;
    player.transform.position = Vector3_Create(0, 0, 0);
    player.transform.rotation = Vector3_Create(0, 0, 0);
    player.transform.scale = Vector3_Create(1, 1, 1);
    
    GameObject gem = {0};
    strcpy(gem.tag, "Collectible");
    gem.active = true;
    gem.transform.position = Vector3_Create(5, 0, 5);
    gem.transform.rotation = Vector3_Create(0, 0, 0);
    gem.transform.scale = Vector3_Create(1, 1, 1);
    
    GameObject destination = {0};
    destination.active = true;
    destination.transform.position = Vector3_Create(10, 0, 10);
    destination.transform.rotation = Vector3_Create(0, 0, 0);
    destination.transform.scale = Vector3_Create(1, 1, 1);
    
    // Create UI components
    TextMeshProUGUI counterText = {0};
    counterText.enabled = true;
    
    TextMeshProUGUI scoreText = {0};
    scoreText.enabled = true;
    
    // Create game systems
    GameManager* gameManager = GameManager_Create(10, &counterText);
    GlobalScore* globalScore = GlobalScore_Create(&gem); // Using gem as scoreDisplay placeholder
    
    // Create collectible
    CollectGreenGem* collectible = CollectGreenGem_Create(&gem);
    collectible->gameManager = gameManager;
    
    // Create movement system
    FirstPersonMovementImproved* movement = FirstPersonMovementImproved_Create(&player);
    
    // Create environment objects
    Teleport* teleport = Teleport_Create(&player, &destination);
    
    GameObject wall = {0};
    wall.active = true;
    WallVanish* wallVanish = WallVanish_Create(&wall, false, "Player");
    
    AudioSource bellSound = {0};
    AudioSource wallSound = {0};
    BellVanish* bellVanish = BellVanish_Create(&bellSound, &wallSound, &wall, false, 1.0f, gameManager, "Player");
    
    // Create sequence objects
    GameObject blocker = {0};
    GameObject dialogueImage = {0};
    Button okButton = {0};
    DialogueSequence* dialogue = DialogueSequence_Create(&blocker, &dialogueImage, &okButton, 3.0f);
    
    GameObject timerText = {0};
    GameObject level2Panel = {0};
    AudioSource levelAudio = {0};
    AudioSource finishSound = {0};
    GameObject scoreTextObj = {0};
    FinishSequence* finish = FinishSequence_Create(&blocker, &levelAudio, &finishSound, 
                                                  &timerText, &scoreTextObj, &level2Panel, 1.5f);
    
    // Simulate game loop
    printf("\n--- Game Loop Simulation ---\n");
    
    // Start systems
    GameManager_Start(gameManager);
    GlobalScore_Start(globalScore);
    
    // Simulate collecting a gem
    printf("\nPlayer approaches gem...\n");
    CollectGreenGem_OnTriggerEnter(collectible, &player);
    
    // Update global score
    GlobalScore_IncreaseScore(globalScore, 10);
    GlobalScore_Update(globalScore);
    
    // Simulate teleport
    printf("\nPlayer enters teleport...\n");
    Teleport_OnTriggerEnter(teleport, &player);
    printf("Player teleported to: (%.1f, %.1f, %.1f)\n", 
           player.transform.position.x, player.transform.position.y, player.transform.position.z);
    
    // Simulate wall vanish
    printf("\nPlayer triggers wall vanish...\n");
    WallVanish_OnTriggerEnter(wallVanish, &player);
    
    // Simulate bell trigger
    printf("\nPlayer triggers bell...\n");
    BellVanish_OnTriggerEnter(bellVanish, &player);
    
    // Simulate dialogue
    printf("\nShowing dialogue...\n");
    DialogueSequence_ShowDialogue(dialogue);
    
    // Simulate finish sequence
    printf("\nPlayer reaches finish...\n");
    FinishSequence_OnTriggerEnter(finish, &player);
    
    // Cleanup
    printf("\n--- Cleanup ---\n");
    GameManager_Destroy(gameManager);
    GlobalScore_Destroy(globalScore);
    CollectGreenGem_Destroy(collectible);
    FirstPersonMovementImproved_Destroy(movement);
    Teleport_Destroy(teleport);
    WallVanish_Destroy(wallVanish);
    BellVanish_Destroy(bellVanish);
    DialogueSequence_Destroy(dialogue);
    FinishSequence_Destroy(finish);
    
    printf("\nC conversion complete! All systems demonstrated.\n");
    
    return 0;
}
