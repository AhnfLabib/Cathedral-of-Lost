using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

public class GlobalTimer : MonoBehaviour
{
    public GameObject timeDisplay;
    private int currentTimer = 0;
    private bool isTakingTime = false;

    // Start is called before the first frame update
    void Start()
    {
        resetTimer();
    }

    public void resetTimer()
    {
        currentTimer = 0;
    }

    public int getTimer()
    {
        return currentTimer;
    }

    // Update is called once per frame
    void Update()
    {
        if (isTakingTime == false)
        {
            StartCoroutine(AddSecond());
        }
    }

    IEnumerator AddSecond()
    {
        isTakingTime = true;
        currentTimer += 1;
        timeDisplay.GetComponent<TextMeshProUGUI>().text = "Timer: "+ currentTimer;
        yield return new WaitForSeconds(1);
        isTakingTime = false;
    }
}
