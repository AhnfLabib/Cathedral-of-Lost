using UnityEngine;

[RequireComponent(typeof(Collider))]
public class WallVanish : MonoBehaviour
{
    [Header("Vanish Target")]
    [Tooltip("The GameObject to disappear")]
    public GameObject target;
    [Tooltip("Destroy instead of deactivate?")]
    public bool destroyInstead = false;

    [Header("Player Settings")]
    [Tooltip("Tag used by your player GameObject")]
    public string playerTag = "Player";

    [Header("SFX")]
    [Tooltip("AudioSource that will play the vanish sound")]
    public AudioSource vanishSound;

    private void Reset()
    {
        // Ensure this collider is set as a trigger
        var col = GetComponent<Collider>();
        col.isTrigger = true;
    }

    private void OnTriggerEnter(Collider other)
    {
        if (!other.CompareTag(playerTag))
            return;

        // Play the sound if assigned
        if (vanishSound != null)
            vanishSound.Play();

        // Vanish the target
        if (target != null)
        {
            if (destroyInstead)
                Destroy(target);
            else
                target.SetActive(false);
        }
        else
        {
            Debug.LogWarning($"{name}: No target assigned for WallVanish.");
        }
    }
}
