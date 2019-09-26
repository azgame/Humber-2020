using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class InputController : MonoBehaviour {
    
	
    void Start() {
	
        
    }
	
	
    void Update() {
	
        
    }

    public bool ButtonDown() 
    {
#if UNITY_STANDALONE
#elif UNITY_ANDROID
#endif


        return true;
    }
}
