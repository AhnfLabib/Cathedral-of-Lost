using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TPMovement : MonoBehaviour
{
    // public references (player and camera)
    public GameObject player;
    public Transform cam;

    // for smooth turning
    public float turnSmoothTime = 0.1f;
    float turnSmoothVelocity;

    // for movement speed
    public float speed = 20f;

    // for gravity
    public Vector3 velocity;
    public float gravity = -9.81f;

    // for ground check
    public Transform groundCheck;
    public float groundDistance = 0.4f;
    public LayerMask groundMask;
    bool isGrounded;

    // jump settings
    public float jumpHeight = 3f;

    // for double jump
    public int maxJumps = 2;
    int jumpCount;

    void Update()
    {
        CharacterController controller = player.GetComponent<CharacterController>();

        // check if grounded
        isGrounded = Physics.CheckSphere(groundCheck.position, groundDistance, groundMask);
        if (isGrounded)
        {
            if (velocity.y < 0)
            {
                velocity.y = -2f;
            }
            jumpCount = 0; // always reset when grounded
        }

        // get input and calculate move direction
        float horizontal = Input.GetAxisRaw("Horizontal");
        float vertical = Input.GetAxisRaw("Vertical");
        Vector3 direction = new Vector3(horizontal, 0f, vertical).normalized;

        // movement and rotation
        if (direction.magnitude >= 0.1f)
        {
            float targetAngle = Mathf.Atan2(direction.x, direction.z) * Mathf.Rad2Deg + cam.eulerAngles.y;
            float angle = Mathf.SmoothDampAngle(transform.eulerAngles.y, targetAngle, ref turnSmoothVelocity, turnSmoothTime);
            transform.rotation = Quaternion.Euler(0f, angle, 0f);

            Vector3 moveDir = Quaternion.Euler(0f, targetAngle, 0f) * Vector3.forward;
            controller.Move(moveDir.normalized * speed * Time.deltaTime);
        }

        // jump input (including double jump)
        if (Input.GetButtonDown("Jump") && jumpCount < maxJumps)
        {
            velocity.y = Mathf.Sqrt(jumpHeight * -2f * gravity);
            jumpCount++;
        }

        // apply gravity
        velocity.y += gravity * Time.deltaTime;
        controller.Move(velocity * Time.deltaTime);
    }
}
