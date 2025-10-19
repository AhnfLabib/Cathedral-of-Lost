using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Gripper : MonoBehaviour
{
    public GameObject player;
    public GameObject platform;

    // when player enters gripper, set player's parent to be the moving platform
    void OnTriggerEnter()
    {
		player.transform.parent = platform.transform;
    }

    // when player exists gripper, set player's parent to be null (back to root hierarchy)
    void OnTriggerExit()
    {
		if (player.transform.parent == platform.transform)
			player.transform.parent = null;
    }

}
