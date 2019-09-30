using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class VertexDisp : MonoBehaviour {

    MeshRenderer meshRender;
    float displacementAmount = 0;

    void Start() {
        meshRender = GetComponent<MeshRenderer>();
    }

    void Update() {
        if (Input.GetButtonDown("Jump"))
            displacementAmount++;

        displacementAmount = Mathf.Lerp(displacementAmount, 0, Time.deltaTime);
        meshRender.material.SetFloat("_Amount", displacementAmount);
    }
}
