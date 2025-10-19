using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

public class GlobalScore : MonoBehaviour
{
    public GameObject scoreDisplay;
    private int currentScore;

    // Start is called before the first frame update
    void Start()
    {
        resetScore();
    }

    public void resetScore()
    {
        currentScore = 0;
    }

    public int getScore()
    {
        return currentScore;
    }

    public void increaseScore(int gemValue)
    {
        currentScore += gemValue;
    }

    // Update is called once per frame
    void Update()
    {
        scoreDisplay.GetComponent<TextMeshProUGUI>().text = "Souls Collected: " + currentScore;
    }
}
