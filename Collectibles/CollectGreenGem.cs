using UnityEngine;

[RequireComponent(typeof(Collider))]
public class CollectGreenGem : MonoBehaviour
{
    [Header("SFX & UI Popup")]
    [Tooltip("One‐shot sound played when collected")]
    public AudioSource collectSound;
    [Tooltip("Your DialogueSequence component in the scene")]
    public DialogueSequence dialogueSequence;

    [Header("Level Counter")]
    [Tooltip("Drag this level’s GameManager here")]
    public GameManager gameManager;

    private void Reset()
    {
        GetComponent<Collider>().isTrigger = true;
    }

    private void OnTriggerEnter(Collider other)
    {
        if (!other.CompareTag("Player")) return;

        // 1) Play pickup SFX
        collectSound?.Play();

        // 2) Increment the level counter
        if (gameManager != null)
            gameManager.CollectFragment();
        else
            Debug.LogWarning("CollectGreenGem: GameManager not assigned!");

        // 3) Show your dialogue UI (blocks input, shows image, OK after delay)
        if (dialogueSequence != null)
            dialogueSequence.ShowDialogue();
        else
            Debug.LogWarning("CollectGreenGem: DialogueSequence not assigned!");

        // 4) Destroy this collectible so it can’t be re‐collected
        Destroy(gameObject);
    }
}
