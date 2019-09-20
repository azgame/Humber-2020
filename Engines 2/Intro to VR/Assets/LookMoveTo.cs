using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LookMoveTo : MonoBehaviour {


    public GameObject ground;
	
	
    void Update() {

        Transform camera = Camera.main.transform;
        Ray ray;
        RaycastHit[] hits;

        Debug.DrawRay(camera.position, camera.rotation * Vector3.forward * 100, Color.red);

        ray = new Ray(camera.position, camera.rotation * Vector3.forward);
        hits = Physics.RaycastAll(ray);

        for (int i = 0; i < hits.Length; i++) {
            if(hits[i].collider.gameObject == ground) {
                transform.position = hits[i].point;
            }
        }
    }
}
