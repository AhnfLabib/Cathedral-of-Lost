using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GemRotate : MonoBehaviour
{
    public float rotateSpeed = 0.5f;

    // Update is called once per frame
    void Update()
    {
        transform.Rotate(0f, rotateSpeed, 0f, Space.World);
    }
}
