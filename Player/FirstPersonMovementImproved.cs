using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FirstPersonMovementImproved : MonoBehaviour
{
    public GameObject player;
    
    public float speed = 20f;

    // add gravity
    Vector3 velocity;
    public float gravity = -9.81f;

    // add ground check
    public Transform groundCheck;
    public float groundDistance = 0.4f;
    public LayerMask groundMask;
    bool isGrounded = false;
 
    // add jump
    public float jumpHeight = 3f;

    // Update is called once per frame
    void Update()
    {
        /*
        // add ground check
        isGrounded = Physics.CheckSphere(groundCheck.position, groundDistance, groundMask);
        if (isGrounded && velocity.y < 0)
        {
            velocity.y = -2f;
        }
        */

        // Step 1: get input and move player
        float x = Input.GetAxis("Horizontal");
        float z = Input.GetAxis("Vertical");

        Vector3 move = transform.right * x + transform.forward * z;
        CharacterController controller = player.GetComponent<CharacterController>();
        controller.Move(move * speed * Time.deltaTime);
        
        /*
        // Step 2: add gravity
        velocity.y += gravity * Time.deltaTime;
        controller.Move(velocity * Time.deltaTime);
        */
        
        /*
        // Step 3: add jump
        if (isGrounded && Input.GetButtonDown("Jump"))
        {
            velocity.y = Mathf.Sqrt(jumpHeight * -2f * gravity);
        }
        */
        
    }
}
