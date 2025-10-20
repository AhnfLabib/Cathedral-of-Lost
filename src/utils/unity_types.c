#include "unity_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Vector3 implementation
Vector3 Vector3_Create(float x, float y, float z) {
    Vector3 vec;
    vec.x = x;
    vec.y = y;
    vec.z = z;
    return vec;
}

// GameObject implementation
bool GameObject_CompareTag(const GameObject* obj, const char* tag) {
    if (!obj || !tag) return false;
    return strcmp(obj->tag, tag) == 0;
}

void GameObject_SetActive(GameObject* obj, bool active) {
    if (!obj) return;
    obj->active = active;
}

void GameObject_Destroy(GameObject* obj) {
    if (!obj) return;
    obj->active = false;
    // In a real implementation, this would free the object
    // free(obj);
}

// AudioSource implementation
void AudioSource_Play(AudioSource* audio) {
    if (!audio) return;
    audio->isPlaying = true;
    printf("Playing audio clip\n");
}

void AudioSource_Stop(AudioSource* audio) {
    if (!audio) return;
    audio->isPlaying = false;
    printf("Stopping audio clip\n");
}

// TextMeshProUGUI implementation
void TextMeshProUGUI_SetText(TextMeshProUGUI* text, const char* str) {
    if (!text || !str) return;
    strncpy(text->text, str, sizeof(text->text) - 1);
    text->text[sizeof(text->text) - 1] = '\0';
    printf("Text updated: %s\n", text->text);
}
