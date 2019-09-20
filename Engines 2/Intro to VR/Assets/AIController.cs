using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class AIController : MonoBehaviour {

    public GameObject target;
    private NavMeshAgent nmAgent;
	
	
    void Start() {

        nmAgent = GetComponent<NavMeshAgent>();
    }
	
	
    void Update() {

        if (target)
            nmAgent.SetDestination(target.transform.position);
    }
}
