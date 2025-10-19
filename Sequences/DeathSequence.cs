using System.Collections;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

public class DeathSequence : MonoBehaviour
{
    [Header("Audio")]
    public AudioSource levelAudio;
    public AudioSource deathFallSound;

    [Header("UI Elements")]
    [Tooltip("Full-screen black Image for fade")]
    public Image blackFadeImage;
    [Tooltip("TextMeshProUGUI for death message")]
    public TextMeshProUGUI deathText;

    [Header("Timing")]
    [Tooltip("Seconds to fade in/out")]
    public float fadeDuration = 1f;
    [Tooltip("Seconds to wait after showing deathText before respawn")]
    public float respawnDelay = 1f;

    [Header("Respawn")]
    public Transform player;
    public Transform startPoint;

    private bool _triggered = false;

    private void Awake()
    {
        // Prepare both UI: active but invisible
        if (blackFadeImage != null)
        {
            blackFadeImage.gameObject.SetActive(true);
            var c = blackFadeImage.color; c.a = 0f;
            blackFadeImage.color = c;
        }
        if (deathText != null)
        {
            deathText.gameObject.SetActive(true);
            var tc = deathText.color; tc.a = 0f;
            deathText.color = tc;
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        if (_triggered || !other.CompareTag("Player")) return;
        _triggered = true;
        StartCoroutine(DeathRoutine());
    }

    private IEnumerator DeathRoutine()
    {
        // pause level audio, play death sound
        levelAudio?.Pause();
        deathFallSound?.Play();

        // fade in black overlay
        if (blackFadeImage != null)
            yield return StartCoroutine(FadeImageAlpha(blackFadeImage, 0f, 1f, fadeDuration));

        // fade in death text
        if (deathText != null)
            yield return StartCoroutine(FadeTextAlpha(deathText, 0f, 1f, fadeDuration));

        // wait then respawn
        yield return new WaitForSeconds(respawnDelay);
        if (player != null && startPoint != null)
            player.position = startPoint.position;

        // fade out death text
        if (deathText != null)
            yield return StartCoroutine(FadeTextAlpha(deathText, 1f, 0f, fadeDuration));

        // fade out black overlay
        if (blackFadeImage != null)
            yield return StartCoroutine(FadeImageAlpha(blackFadeImage, 1f, 0f, fadeDuration));

        // resume audio
        levelAudio?.Play();
        _triggered = false;
    }

    private IEnumerator FadeImageAlpha(Image img, float from, float to, float duration)
    {
        float elapsed = 0f;
        Color c = img.color;
        while (elapsed < duration)
        {
            elapsed += Time.deltaTime;
            c.a = Mathf.Lerp(from, to, elapsed / duration);
            img.color = c;
            yield return null;
        }
        c.a = to;
        img.color = c;
    }

    private IEnumerator FadeTextAlpha(TextMeshProUGUI txt, float from, float to, float duration)
    {
        float elapsed = 0f;
        Color c = txt.color;
        while (elapsed < duration)
        {
            elapsed += Time.deltaTime;
            c.a = Mathf.Lerp(from, to, elapsed / duration);
            txt.color = c;
            yield return null;
        }
        c.a = to;
        txt.color = c;
    }
}
