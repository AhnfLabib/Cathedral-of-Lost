// using UnityEngine;

// [RequireComponent(typeof(Collider))]
// public class FragmentCollector : MonoBehaviour
// {
//     public enum FragmentType { Knight, Bishop }

//     [Tooltip("Select whether this is a Knight fragment or a hidden Bishop fragment")]
//     public FragmentType fragmentType;

//     [Tooltip("Tag used to identify the player object")]
//     public string playerTag = "Player";

//     private void Reset()
//     {
//         // Automatically configure the collider as a trigger
//         var col = GetComponent<Collider>();
//         col.isTrigger = true;
//     }

//     private void OnTriggerEnter(Collider other)
//     {
//         if (!other.CompareTag(playerTag))
//             return;

//         // Increment the appropriate counter in GameManager
//         switch (fragmentType)
//         {
//             case FragmentType.Knight:
//                 GameManager.Instance.CollectKnightFragment();
//                 break;
//             case FragmentType.Bishop:
//                 GameManager.Instance.CollectBishopFragment();
//                 break;
//         }

//         // Remove this fragment from the scene
//         Destroy(gameObject);
//     }
// }
