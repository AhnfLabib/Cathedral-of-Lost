using UnityEngine;

public class Teleport : MonoBehaviour
{
	public GameObject player;
	public GameObject destination;
	
    void OnTriggerEnter()
    {
		player.transform.position = destination.transform.position;
    }
}
