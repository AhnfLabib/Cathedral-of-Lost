using System.Collections;
using UnityEngine;

[RequireComponent(typeof(Collider))]
public class BellVanish : MonoBehaviour
{
    [Header("Bell & Wall Settings")]
    public AudioSource bellSound;
    public AudioSource wallMovingSound;
    public GameObject  wallTarget;
    public bool        destroyWall = false;
    public float       wallDelay = 1f;

    [Header("References")]
    [Tooltip("Drag this level’s GameManager here")]
    public GameManager gameManager;
    [Tooltip("Player tag")]
    public string      playerTag = "Player";

    private bool _triggered = false;

    private void Reset() => GetComponent<Collider>().isTrigger = true;

    private void OnTriggerEnter(Collider other)
    {
        if (_triggered || !other.CompareTag(playerTag)) return;
        _triggered = true;
        StartCoroutine(HandleBell());
    }

    private IEnumerator HandleBell()
    {
        // ring the bell for everyone
        bellSound?.Play();

        // only open if you’ve collected all for THIS level
        if (gameManager == null)
        {
            Debug.LogWarning("BellVanish: GameManager not assigned!");
            yield break;
        }
        if (gameManager.CollectedCount < gameManager.totalCollectibles)
            yield break;

        // wait then move the wall
        yield return new WaitForSeconds(wallDelay);
        wallMovingSound?.Play();

        if (wallTarget != null)
        {
            if (destroyWall) Destroy(wallTarget);
            else             wallTarget.SetActive(false);
        }
    }
}
