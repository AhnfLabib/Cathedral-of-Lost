// using UnityEngine;

// public class Collectible : MonoBehaviour
// {
//     public enum Type { Scroll, Knight, Bishop }
//     public Type collectibleType;

//     private void OnTriggerEnter(Collider other)
//     {
//         if (!other.CompareTag("Player")) return;

//         // Update score if needed
//         switch (collectibleType)
//         {
//             case Type.Knight:
//                 GameManager.Instance.CollectKnightFragment();
//                 break;
//             case Type.Bishop:
//                 GameManager.Instance.CollectBishopFragment();
//                 break;
//             case Type.Scroll:
//                 // no score change
//                 break;
//         }

//         // Fire the dialogue UI
//         DialogueManager.Instance.ShowDialogue();

//         // Remove the collectible immediately
//         Destroy(gameObject);
//     }
// }
