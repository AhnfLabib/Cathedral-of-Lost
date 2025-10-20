#include "global_score.h"
#include "../utils/unity_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a new GlobalScore instance
GlobalScore* GlobalScore_Create(GameObject* scoreDisplay) {
    GlobalScore* score = (GlobalScore*)malloc(sizeof(GlobalScore));
    if (!score) return NULL;
    
    score->scoreDisplay = scoreDisplay;
    score->currentScore = 0;
    score->isActive = true;
    
    return score;
}

// Destroy GlobalScore instance
void GlobalScore_Destroy(GlobalScore* score) {
    if (score) {
        free(score);
    }
}

// Start function - equivalent to C# Start()
void GlobalScore_Start(GlobalScore* score) {
    if (!score || !score->isActive) return;
    
    GlobalScore_Reset(score);
}

// Reset score - equivalent to C# resetScore()
void GlobalScore_Reset(GlobalScore* score) {
    if (!score || !score->isActive) return;
    
    score->currentScore = 0;
}

// Get current score - equivalent to C# getScore()
int GlobalScore_GetScore(const GlobalScore* score) {
    if (!score) return 0;
    return score->currentScore;
}

// Increase score - equivalent to C# increaseScore()
void GlobalScore_IncreaseScore(GlobalScore* score, int gemValue) {
    if (!score || !score->isActive) return;
    
    score->currentScore += gemValue;
}

// Update function - equivalent to C# Update()
void GlobalScore_Update(GlobalScore* score) {
    if (!score || !score->isActive || !score->scoreDisplay) return;
    
    // Get the TextMeshProUGUI component from the scoreDisplay GameObject
    TextMeshProUGUI* textComponent = (TextMeshProUGUI*)score->scoreDisplay->audioSource; // Assuming audioSource field holds the text component
    
    if (textComponent) {
        char scoreText[256];
        snprintf(scoreText, sizeof(scoreText), 
                 "Souls Collected: %d", 
                 score->currentScore);
        
        TextMeshProUGUI_SetText(textComponent, scoreText);
    }
}
