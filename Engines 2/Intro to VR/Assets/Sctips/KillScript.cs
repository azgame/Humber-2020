using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class KillScript : MonoBehaviour {

    public GameObject target;
    public float timeToSelect = 3.0f;
    float countDown;
	
	
    void Start() {

        countDown = timeToSelect;
    }
	
	
    void Update() {

        Transform camera = Camera.main.transform;
        Ray ray = new Ray(camera.position, camera.rotation * Vector3.forward);

        RaycastHit hit;

        if (Physics.Raycast(ray, out hit) &&
            hit.collider.gameObject == target) {

            if (countDown > 0) countDown -= Time.deltaTime;
            else {
                Killed();
                countDown = timeToSelect;
            }
        }
        else countDown = timeToSelect;
    }

    void Killed() {

    }
}
