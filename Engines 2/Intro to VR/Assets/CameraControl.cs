using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraControl : MonoBehaviour {

    void Start() {
	
        
    }
	
	
    void Update() {

        float m_horizontal = Input.GetAxis("Horizontal");
        float m_vertical = Input.GetAxis("Vertical");
        
        transform.position = new Vector3(transform.position.x + m_horizontal, transform.position.y, transform.position.z + m_vertical);
    }
}
