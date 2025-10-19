using System.Collections;
using UnityEngine;
using UnityEngine.SceneManagement;

public class MainMenuFunction : MonoBehaviour
{
    [Header("SFX")]
    [Tooltip("One-shot sound for button clicks")]
    public AudioSource buttonPress;

    [Header("BGM")]
    [Tooltip("Background music for the main menu")]
    public AudioSource menuMusic;

    [Header("Level Intro")]
    [Tooltip("UI panel or Image GameObject with 'Level 1: Forsaken Halls'")]
    public GameObject levelIntroPanel;
    [Tooltip("How long to show the level intro before loading")]
    public float introDuration = 1.5f;

    private void Start()
    {
        if (menuMusic != null)
        {
            menuMusic.loop = true;
            menuMusic.Play();
        }
        else Debug.LogWarning("MainMenuFunction: No menuMusic assigned!");
        
        // Make sure the level intro is hidden until needed
        if (levelIntroPanel != null)
            levelIntroPanel.SetActive(false);
    }

    /// <summary>
    /// Called by the “Start Game” button
    /// </summary>
    public void StartGame()
    {
        StartCoroutine(PlayIntroThenLoad(1));
    }
    public void Credits()
    {
        StartCoroutine(PlayIntroThenLoad(4));
    }

    /// <summary>
    /// Called by the “Quit” button
    /// </summary>
    public void QuitGame()
    {
        Application.Quit();
    }

    private IEnumerator PlayIntroThenLoad(int sceneIndex)
    {
        // 1) click sound
        if (buttonPress != null)
            buttonPress.Play();

        // 2) stop menu music immediately
        if (menuMusic != null)
            menuMusic.Stop();

        // 3) show your "Level 1: Forsaken Halls" panel
        if (levelIntroPanel != null)
            levelIntroPanel.SetActive(true);

        // 4) wait the intro duration
        yield return new WaitForSeconds(introDuration);

        // 5) load the scene
        SceneManager.LoadScene(sceneIndex);
    }
}
