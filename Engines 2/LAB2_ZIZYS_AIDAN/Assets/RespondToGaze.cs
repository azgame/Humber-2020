using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;

public class RespondToGaze : MonoBehaviour
{

    public bool highlight = true;
    Button button;

    public bool timedClick = true;
    public float delay = 2.0f;
    float timer;

    public Slider slider;

    // Start is called before the first frame update
    void Start()
    {
        button = GetComponent<Button>();
    }

    // Update is called once per frame
    void Update()
    {
        Transform camera = Camera.main.transform;
        Ray ray = new Ray(camera.position, camera.rotation * Vector3.forward);
        RaycastHit hit;

        if (Physics.Raycast(ray, out hit) && (hit.transform.parent != null) && (hit.transform.parent.gameObject == gameObject)) {
            if (highlight)
                button.Select();
            if (timedClick) {
                timer += Time.deltaTime;
                slider.value = timer / delay;
                if (timer >= delay)
                    button.onClick.Invoke();
            }
        }
        else {
            if (EventSystem.current)
                EventSystem.current.SetSelectedGameObject(null);
            timer = 0.0f;
            slider.value = 0.0f;
        }
    }
}
