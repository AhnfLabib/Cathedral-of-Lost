#ifndef SEQUENCES_H
#define SEQUENCES_H

#include <stdbool.h>
#include <stdint.h>
#include "../utils/unity_types.h"

// Forward declarations
// GameObject, AudioSource, Button are defined in unity_types.h
typedef struct Coroutine Coroutine;

// DialogueSequence structure
typedef struct DialogueSequence {
    GameObject* blocker;
    GameObject* dialogueImage;
    Button* okButton;
    float okDelay;
    bool isDialogueActive;
    bool isActive;
} DialogueSequence;

// FinishSequence structure
typedef struct FinishSequence {
    GameObject* blocker;
    AudioSource* levelAudio;
    AudioSource* finishSound;
    GameObject* timerText;
    GameObject* scoreText;
    GameObject* level2Panel;
    float transitionDuration;
    bool isFinished;
    bool isActive;
} FinishSequence;

// Function declarations for DialogueSequence
DialogueSequence* DialogueSequence_Create(GameObject* blocker, GameObject* dialogueImage, 
                                         Button* okButton, float okDelay);
void DialogueSequence_Destroy(DialogueSequence* dialogue);
void DialogueSequence_Awake(DialogueSequence* dialogue);
void DialogueSequence_ShowDialogue(DialogueSequence* dialogue);
void DialogueSequence_EnableOkAfterDelay(DialogueSequence* dialogue);
void DialogueSequence_HideDialogue(DialogueSequence* dialogue);

// Function declarations for FinishSequence
FinishSequence* FinishSequence_Create(GameObject* blocker, AudioSource* levelAudio, 
                                     AudioSource* finishSound, GameObject* timerText,
                                     GameObject* scoreText, GameObject* level2Panel, 
                                     float transitionDuration);
void FinishSequence_Destroy(FinishSequence* finish);
void FinishSequence_Start(FinishSequence* finish);
void FinishSequence_OnTriggerEnter(FinishSequence* finish, GameObject* other);
void FinishSequence_Finish(FinishSequence* finish);

// Scene management (simplified)
void SceneManager_LoadScene(int sceneIndex);

#endif // SEQUENCES_H
