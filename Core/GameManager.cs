using UnityEngine;
using TMPro;

public class GameManager : MonoBehaviour
{
    [Header("Level Settings")]
    [Tooltip("How many collectibles to find in this level")]
    public int totalCollectibles = 10;

    [Header("UI")]
    [Tooltip("TextMeshProUGUI that shows “Souls Collected on this Level: X/total”")]
    public TextMeshProUGUI counterText;

    private int _collectedCount = 0;
    public int CollectedCount => _collectedCount;

    private void Start()
    {
        UpdateHUD();
    }

    /// <summary>Call this from each CollectGreenGem when picked up.</summary>
    public void CollectFragment()
    {
        _collectedCount = Mathf.Min(_collectedCount + 1, totalCollectibles);
        UpdateHUD();
    }

    private void UpdateHUD()
    {
        if (counterText != null)
            counterText.text = $"Souls Collected on this Level: {_collectedCount}/{totalCollectibles}";
    }
}
