#ifndef UNITY_TYPES_H
#define UNITY_TYPES_H

#include <stdbool.h>
#include <stdint.h>

// Basic Unity-like types for C implementation
typedef struct Vector3 {
    float x, y, z;
} Vector3;

typedef struct Transform {
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;
} Transform;

typedef struct GameObject {
    Transform transform;
    bool active;
    char tag[32];
    void* collider;
    void* audioSource;
} GameObject;

typedef struct Collider {
    bool isTrigger;
    bool enabled;
} Collider;

typedef struct AudioSource {
    bool isPlaying;
    float volume;
    void* clip;
} AudioSource;

typedef struct TextMeshProUGUI {
    char text[256];
    bool enabled;
} TextMeshProUGUI;

typedef struct Button {
    bool interactable;
    void (*onClick)(void);
} Button;

// Utility functions
Vector3 Vector3_Create(float x, float y, float z);
bool GameObject_CompareTag(const GameObject* obj, const char* tag);
void GameObject_SetActive(GameObject* obj, bool active);
void GameObject_Destroy(GameObject* obj);
void AudioSource_Play(AudioSource* audio);
void AudioSource_Stop(AudioSource* audio);
void TextMeshProUGUI_SetText(TextMeshProUGUI* text, const char* str);
// snprintf is provided by stdio.h

#endif // UNITY_TYPES_H
