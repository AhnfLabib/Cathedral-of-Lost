// using UnityEngine;
// using TMPro;

// public class LevelScoreManager : MonoBehaviour
// {
//     [Header("Level Settings")]
//     [Tooltip("How many total pickups in this level")]
//     public int totalCollectibles = 10;

//     [Header("UI")]
//     [Tooltip("The TMP text that shows: “Souls Collected on this Level: X/total”")]
//     public TextMeshProUGUI counterText;

//     private int _currentCount = 0;
//     public int CurrentCount => _currentCount;

//     void Start()
//     {
//         UpdateUI();
//     }

//     /// <summary>Call this from each collectible when picked up.</summary>
//     public void CollectOne()
//     {
//         _currentCount = Mathf.Min(_currentCount + 1, totalCollectibles);
//         UpdateUI();
//     }

//     private void UpdateUI()
//     {
//         if (counterText != null)
//             counterText.text = $"Souls Collected on this Level: {_currentCount}/{totalCollectibles}";
//     }
// }
