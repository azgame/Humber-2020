using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RandomPosition : MonoBehaviour {
	
	
    void Start() {

        StartCoroutine(RandomPositionWithDelay());
    }
	
	
    IEnumerator RandomPositionWithDelay() {

        while (true) {

            SetPosition();
            yield return new WaitForSeconds(2);
        }
    }

    void SetPosition() {

        transform.position = new Vector3(
            Random.Range(-5,5), 0, Random.Range(-5,5));
    }
}
