#ifndef GLOBAL_SCORE_H
#define GLOBAL_SCORE_H

#include <stdbool.h>
#include <stdint.h>
#include "../utils/unity_types.h"

// GlobalScore structure
typedef struct GlobalScore {
    GameObject* scoreDisplay;
    int currentScore;
    bool isActive;
} GlobalScore;

// Function declarations
GlobalScore* GlobalScore_Create(GameObject* scoreDisplay);
void GlobalScore_Destroy(GlobalScore* score);
void GlobalScore_Start(GlobalScore* score);
void GlobalScore_Reset(GlobalScore* score);
int GlobalScore_GetScore(const GlobalScore* score);
void GlobalScore_IncreaseScore(GlobalScore* score, int gemValue);
void GlobalScore_Update(GlobalScore* score);

#endif // GLOBAL_SCORE_H
