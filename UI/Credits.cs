using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Credits : MonoBehaviour
{
    void Start()
    {
        StartCoroutine(RunCredits());
    }

    IEnumerator RunCredits()
    {
        yield return new WaitForSeconds(10);
        SceneManager.LoadScene(0);
    }
}
