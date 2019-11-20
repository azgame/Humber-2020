using UnityEngine;
using UnityEditor;
using UnityEngine.UI;

// Declare type of Custom Editor
[CustomEditor(typeof(TankController))] //1
public class TankControllerEditor : Editor 
{
    float thumbnailWidth = 70;
    float thumbnailHeight = 70;
    float labelWidth = 150f;

    string playerName = "Player 1";
    string playerLevel = "1";
    string playerElo = "5";
    string playerScore = "100";

    // OnInspector GUI
    public override void OnInspectorGUI()
    {
        // Call base class method
        base.OnInspectorGUI(); // if not here, can't edit anything in inspector

        GUILayout.Space(20);
        GUILayout.Label("Custom Editor Elements", EditorStyles.boldLabel);
        GUILayout.BeginHorizontal();
        GUILayout.Label("Player Name", GUILayout.Width(labelWidth));
        playerName = GUILayout.TextField(playerName);


        GUILayout.EndHorizontal();
    }

    // Custom form for Player Preferences
    // Custom Buttons with Image as Thumbnail
}
