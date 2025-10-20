#include "sequences.h"
#include "../environment/environment.h"
#include "../utils/unity_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==================== DIALOGUE SEQUENCE ====================

DialogueSequence* DialogueSequence_Create(GameObject* blocker, GameObject* dialogueImage, 
                                         Button* okButton, float okDelay) {
    DialogueSequence* dialogue = (DialogueSequence*)malloc(sizeof(DialogueSequence));
    if (!dialogue) return NULL;
    
    dialogue->blocker = blocker;
    dialogue->dialogueImage = dialogueImage;
    dialogue->okButton = okButton;
    dialogue->okDelay = okDelay;
    dialogue->isDialogueActive = false;
    dialogue->isActive = true;
    
    DialogueSequence_Awake(dialogue);
    
    return dialogue;
}

void DialogueSequence_Destroy(DialogueSequence* dialogue) {
    if (dialogue) {
        free(dialogue);
    }
}

void DialogueSequence_Awake(DialogueSequence* dialogue) {
    if (!dialogue) return;
    
    // Hide all at start
    if (dialogue->blocker) {
        GameObject_SetActive(dialogue->blocker, false);
    }
    if (dialogue->dialogueImage) {
        GameObject_SetActive(dialogue->dialogueImage, false);
    }
    if (dialogue->okButton) {
        GameObject_SetActive((GameObject*)dialogue->okButton, false);
    }
    
    // Set up button callback (simplified)
    if (dialogue->okButton) {
        dialogue->okButton->onClick = (void(*)(void))DialogueSequence_HideDialogue;
    }
}

void DialogueSequence_ShowDialogue(DialogueSequence* dialogue) {
    if (!dialogue || !dialogue->isActive || dialogue->isDialogueActive) return;
    
    dialogue->isDialogueActive = true;
    
    if (dialogue->blocker) {
        GameObject_SetActive(dialogue->blocker, true);
    }
    if (dialogue->dialogueImage) {
        GameObject_SetActive(dialogue->dialogueImage, true);
    }
    if (dialogue->okButton) {
        GameObject_SetActive((GameObject*)dialogue->okButton, false);
    }
    
    // Start coroutine to enable OK button after delay
    DialogueSequence_EnableOkAfterDelay(dialogue);
}

void DialogueSequence_EnableOkAfterDelay(DialogueSequence* dialogue) {
    if (!dialogue) return;
    
    // In a real implementation, this would use a coroutine system
    // For now, just enable the button after a delay (simplified)
    printf("Dialogue shown - OK button will be enabled after %.1f seconds\n", dialogue->okDelay);
    
    // Simulate enabling the button after delay
    if (dialogue->okButton) {
        GameObject_SetActive((GameObject*)dialogue->okButton, true);
    }
}

void DialogueSequence_HideDialogue(DialogueSequence* dialogue) {
    if (!dialogue) return;
    
    if (dialogue->blocker) {
        GameObject_SetActive(dialogue->blocker, false);
    }
    if (dialogue->dialogueImage) {
        GameObject_SetActive(dialogue->dialogueImage, false);
    }
    if (dialogue->okButton) {
        GameObject_SetActive((GameObject*)dialogue->okButton, false);
    }
    
    dialogue->isDialogueActive = false;
}

// ==================== FINISH SEQUENCE ====================

FinishSequence* FinishSequence_Create(GameObject* blocker, AudioSource* levelAudio, 
                                     AudioSource* finishSound, GameObject* timerText,
                                     GameObject* scoreText, GameObject* level2Panel, 
                                     float transitionDuration) {
    FinishSequence* finish = (FinishSequence*)malloc(sizeof(FinishSequence));
    if (!finish) return NULL;
    
    finish->blocker = blocker;
    finish->levelAudio = levelAudio;
    finish->finishSound = finishSound;
    finish->timerText = timerText;
    finish->scoreText = scoreText;
    finish->level2Panel = level2Panel;
    finish->transitionDuration = transitionDuration;
    finish->isFinished = false;
    finish->isActive = true;
    
    FinishSequence_Start(finish);
    
    return finish;
}

void FinishSequence_Destroy(FinishSequence* finish) {
    if (finish) {
        free(finish);
    }
}

void FinishSequence_Start(FinishSequence* finish) {
    if (!finish) return;
    
    // Make sure the Level 2 panel is hidden at the start
    if (finish->level2Panel) {
        GameObject_SetActive(finish->level2Panel, false);
    }
}

void FinishSequence_OnTriggerEnter(FinishSequence* finish, GameObject* other) {
    if (!finish || !finish->isActive || !other) return;
    
    FinishSequence_Finish(finish);
}

void FinishSequence_Finish(FinishSequence* finish) {
    if (!finish || !finish->isActive || finish->isFinished) return;
    
    finish->isFinished = true;
    
    // 1) Block player
    if (finish->blocker) {
        GameObject_SetActive(finish->blocker, true);
        // In Unity, this would set parent to null
        // finish->blocker->transform.parent = NULL;
    }
    
    // 2) Stop level audio and play finish sound
    if (finish->levelAudio) {
        AudioSource_Stop(finish->levelAudio);
    }
    if (finish->finishSound) {
        AudioSource_Play(finish->finishSound);
    }
    
    // 3) Hide in-game HUD
    if (finish->timerText) {
        GameObject_SetActive(finish->timerText, false);
    }
    if (finish->scoreText) {
        GameObject_SetActive(finish->scoreText, false);
    }
    
    // 4) Show Level 2 transition
    if (finish->level2Panel) {
        GameObject_SetActive(finish->level2Panel, true);
    }
    
    // 5) Load the next scene after transition duration
    printf("Level finished - transitioning to next scene after %.1f seconds\n", finish->transitionDuration);
    
    // In a real implementation, this would use a coroutine
    // For now, just simulate the scene load
    SceneManager_LoadScene(2);
}

// ==================== SCENE MANAGEMENT ====================

void SceneManager_LoadScene(int sceneIndex) {
    // This would interface with actual scene management system
    printf("Loading scene %d\n", sceneIndex);
}
