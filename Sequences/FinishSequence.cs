using System.Collections;
using UnityEngine;
using UnityEngine.SceneManagement;

public class FinishSequence : MonoBehaviour
{
    [Header("Block & Audio")]
    public GameObject blocker;
    public AudioSource levelAudio; 
    public AudioSource finishSound;
    
    [Header("HUD Elements")]
    public GameObject timerText;
    public GameObject scoreText;

    [Header("Level 2 Transition")]
    [Tooltip("Your 'Level 2' UI panel/image, disabled by default")]
    public GameObject level2Panel;
    [Tooltip("How long to show the Level 2 panel before loading")]
    public float transitionDuration = 1.5f;

    private bool isFinished = false;

    private void Start()
    {
        // make sure the Level 2 panel is hidden at the start
        if (level2Panel != null)
            level2Panel.SetActive(false);
    }

    private void OnTriggerEnter()
    {
        StartCoroutine(Finish());
    }
	
    private IEnumerator Finish()
    {
        if (isFinished)
            yield break;
        isFinished = true;

        // 1) block player
        blocker.SetActive(true);
        blocker.transform.parent = null;
	
        // 2) stop level audio and play finish sound
        levelAudio.Stop();
        finishSound.Play();
                
        // 3) hide in-game HUD
        timerText.SetActive(false); 
        scoreText.SetActive(false);

        // 4) show Level 2 transition
        if (level2Panel != null)
            level2Panel.SetActive(true);

        yield return new WaitForSeconds(transitionDuration);

        // 5) load the next scene
        SceneManager.LoadScene(2);
    }
}
