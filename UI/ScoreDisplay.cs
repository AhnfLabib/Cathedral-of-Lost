// // ScoreDisplay.cs
// using UnityEngine;
// using TMPro;

// public class ScoreDisplay : MonoBehaviour
// {
//     [Tooltip("TextMeshProUGUI that shows: 'Souls Collected: X/10'")]
//     public TextMeshProUGUI textField;

//     void Update()
//     {
//         if (GameManager.Instance != null && textField != null)
//         {
//             int score = GameManager.Instance.Collected;
//             int total = GameManager.Instance.totalCollectibles;
//             textField.text = $"Souls Collected: {score}/{total}";
//         }
//     }
// }
