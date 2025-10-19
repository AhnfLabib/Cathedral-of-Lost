using System.Collections;
using UnityEngine;
using UnityEngine.SceneManagement;

[RequireComponent(typeof(Collider))]
public class EndingSequence : MonoBehaviour
{
    [Header("UI References")]
    [Tooltip("Full-screen UI panel that blocks input when ending sequence starts")]
    public GameObject blocker;
    [Tooltip("The panel or image showing your final screen/scroll")]
    public GameObject endingImage;

    [Header("Audio")]
    [Tooltip("The audio source currently playing the level music")]
    public AudioSource levelMusicSource;
    [Tooltip("Audio source that will play the ending music (clip should already be assigned)")]
    public AudioSource endingMusicSource;

    [Header("Timing")]
    [Tooltip("How long before the credits scene loads (seconds)")]
    public float delayBeforeCredits = 5f;

    [Header("Player Settings")]
    [Tooltip("Tag used by your player GameObject to detect the trigger")]
    public string playerTag = "Player";

    private bool isEndingActive = false;

    private void Reset()
    {
        // ensure there's a trigger collider
        var col = GetComponent<Collider>();
        col.isTrigger = true;
    }

    private void Awake()
    {
        blocker?.SetActive(false);
        endingImage?.SetActive(false);

        if (endingMusicSource != null)
            endingMusicSource.playOnAwake = false;
    }

    private void OnTriggerEnter(Collider other)
    {
        if (isEndingActive) return;
        if (!other.CompareTag(playerTag)) return;

        StartEnding();
    }

    /// <summary>
    /// Begins the ending sequence.
    /// </summary>
    public void StartEnding()
    {
        isEndingActive = true;

        blocker?.SetActive(true);
        endingImage?.SetActive(true);

        if (levelMusicSource != null && levelMusicSource.isPlaying)
            levelMusicSource.Stop();

        if (endingMusicSource != null)
            endingMusicSource.Play();

        StartCoroutine(GoToCreditsAfterDelay());
    }

    private IEnumerator GoToCreditsAfterDelay()
    {
        yield return new WaitForSeconds(delayBeforeCredits);
        SceneManager.LoadScene(4); // Change to your actual credits scene index or name
    }
}
