using UnityEngine;
using System.Collections;

public class Character : MonoBehaviour {


    public enum m_AnimationStates {
        Idle,
        Walking,
        Jump,
        Hit,
        Attack,
        PowerUp,
        Death
    }

  
    public float                        speed;
    public float                        jumpSpeed;
    public float                        gravity;

    private bool                        dead = false;
    private int                         junkFood = 0;
    private Vector3                     moveDirection = Vector3.zero;
    private Animator                    animator;
    private CharacterController         characterController;


    void Start() {

        characterController = GetComponent<CharacterController>();
        animator = GetComponent<Animator>();
    }

    void Update() {

        if (characterController.isGrounded) {

            moveDirection = new Vector3(Input.GetAxis("Horizontal"), 0.0f, Input.GetAxis("Vertical"));
            moveDirection *= speed;

            SetAnimationState(m_AnimationStates.Walking);

            if (Input.GetButton("Jump")) {
                moveDirection.y = jumpSpeed;
                SetAnimationState(m_AnimationStates.Jump);
            }

            if (Input.GetButton("Fire1")) {
                SetAnimationState(m_AnimationStates.Attack);
            }
        }

        if (dead)
            moveDirection = new Vector3(0.0f, moveDirection.y, 0.0f);

        moveDirection.y -= gravity * Time.deltaTime;
        characterController.Move(moveDirection * Time.deltaTime);
    }

    void OnTriggerEnter(Collider hit) {
        switch (hit.gameObject.tag) {
            case "Death":
                Death(hit);
                SetAnimationState(m_AnimationStates.Death);
                break;
            case "PowerUp":
                CollectFood(hit);
                SetAnimationState(m_AnimationStates.PowerUp);
                break;
            default:
                break;
        }
    }

    /// <summary>
    /// Set animations here
    /// Run any animation dependant code here
    /// </summary>
    void SetAnimationState(m_AnimationStates anim) {

        switch (anim) {
            case m_AnimationStates.Idle:
                break;
            case m_AnimationStates.Walking:
                animator.SetFloat("Speed", Mathf.Abs(moveDirection.x) + Mathf.Abs(moveDirection.z));
                break;
            case m_AnimationStates.Jump:
                animator.SetTrigger("Jump");
                break;
            case m_AnimationStates.Hit:
                animator.SetTrigger("Hit");
                break;
            case m_AnimationStates.Attack:
                animator.SetTrigger("Attack");
                break;
            case m_AnimationStates.PowerUp:
                animator.SetTrigger("PowerUp");
                break;
            case m_AnimationStates.Death:
                animator.SetTrigger("Death");
                break;
            default:
                break;
        }
    }

    void Death(Collider hit) {
        dead = true;
        Debug.Log("You died");
        Destroy(hit.gameObject);
    }

    void CollectFood(Collider hit) {
        junkFood++;
        Debug.Log("You have " + junkFood + " junk foods!");
        Destroy(hit.gameObject);
    }
}
