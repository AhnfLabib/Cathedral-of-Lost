using System.Collections;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Level2EndSequence : MonoBehaviour
{
    [Header("Block & Audio")]
    [Tooltip("UI blocker to prevent player input during ending")]
    public GameObject blocker;

    [Tooltip("Audio Source playing the level’s background music")]
    public AudioSource levelAudio;
    [Tooltip("Audio Source for the ending theme")]
    public AudioSource endingMusic;

    [Header("Ending UI")]
    [Tooltip("Images or panels with your final messages, disabled by default")]
    public GameObject[] endingImages;
    [Tooltip("How long to display the ending images before returning to main menu")]
    public float endingDisplayTime = 4f;

    [Header("Main Menu")]
    [Tooltip("Build index or name of your Main Menu scene")]
    public string mainMenuSceneName = "MainMenu";

    private bool isEnded = false;

    private void OnTriggerEnter(Collider other)
    {
        if (isEnded) return;
        if (!other.CompareTag("Player")) return;

        isEnded = true;
        StartCoroutine(PlayEndingSequence());
    }

    private IEnumerator PlayEndingSequence()
    {
        // 1) block player input
        if (blocker != null)
            blocker.SetActive(true);

        // 2) stop level music
        if (levelAudio != null)
            levelAudio.Stop();

        // 3) play ending theme
        if (endingMusic != null)
        {
            endingMusic.loop = false;
            endingMusic.Play();
        }

        // 4) show ending images
        foreach (var img in endingImages)
        {
            if (img != null)
                img.SetActive(true);
        }

        // 5) wait until display time elapses
        yield return new WaitForSeconds(endingDisplayTime);

        // 6) load main menu
        SceneManager.LoadScene(mainMenuSceneName);
    }
}
