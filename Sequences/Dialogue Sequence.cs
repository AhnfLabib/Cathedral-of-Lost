using System.Collections;
using UnityEngine;
using UnityEngine.UI;

public class DialogueSequence : MonoBehaviour
{
    [Header("UI References")]
    [Tooltip("Full-screen UI panel that blocks input when dialogue is up")]
    public GameObject blocker;
    [Tooltip("The panel or image showing your dialogue/scroll")]
    public GameObject dialogueImage;
    [Tooltip("The OK button that resumes play")]
    public Button okButton;

    [Header("Timing")]
    [Tooltip("How long before the OK button appears (seconds)")]
    public float okDelay = 3f;

    bool isDialogueActive = false;

    private void Awake()
    {
        // hide all at start
        blocker?.SetActive(false);
        dialogueImage?.SetActive(false);
        okButton?.gameObject.SetActive(false);

        okButton.onClick.AddListener(HideDialogue);
    }

    /// <summary>
    /// Call this to show the dialogue popup.
    /// </summary>
    public void ShowDialogue()
    {
        if (isDialogueActive) return;
        isDialogueActive = true;

        blocker?.SetActive(true);
        dialogueImage?.SetActive(true);
        okButton.gameObject.SetActive(false);

        StartCoroutine(EnableOkAfterDelay());
    }

    private IEnumerator EnableOkAfterDelay()
    {
        yield return new WaitForSeconds(okDelay);
        okButton?.gameObject.SetActive(true);
    }

    private void HideDialogue()
    {
        blocker?.SetActive(false);
        dialogueImage?.SetActive(false);
        okButton?.gameObject.SetActive(false);
        isDialogueActive = false;
    }
}
