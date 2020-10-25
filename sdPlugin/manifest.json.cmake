{
  "Actions": [
    {
      "Icon": "discord-mic-off", 
      "States": [
        {
          "Image": "discord-mic-on"
        },
		{
		  "Image": "discord-mic-off"
		}
      ],
      "SupportedInMultiActions": false,
	    "Name": "Toggle Discord Mute",
      "Tooltip": "Toggle Self-Mute in Discord",
      "UUID": "com.fredemmott.discord.mute",
      "PropertyInspectorPath": "propertyinspector/index.html"
    },
    {
      "Icon": "discord-mic-on",
      "States": [
        {
          "Image": "discord-mic-on"
        },
        {
          "Image": "discord-mic-off"
        }
      ],
      "SupportedInMultiActions": true,
      "Name": "Set Discord Mute",
      "Tooltip": "Set Self-Mute in Discord",
      "UUID": "com.fredemmott.discord.muteset",
      "PropertyInspectorPath": "propertyinspector/set.html"
    },
	{
      "Icon": "discord-deafen-off", 
      "States": [
        {
          "Image": "discord-deafen-off"
        },
		{
		  "Image": "discord-deafen-on"
		}
      ],
      "SupportedInMultiActions": false,
	    "Name": "Toggle Discord Deafen",
      "Tooltip": "Toggle Self-Mute in Deafen",
      "UUID": "com.fredemmott.discord.deafen",
      "PropertyInspectorPath": "propertyinspector/index.html"
    }
  ], 
  "Author": "Fred Emmott", 
  "CodePathMac": "sddiscord",
  "CodePathWin": "sddiscord.exe",
  "Description": "Toggle and Set Discord Mute and Deafen.",
  "Name": "Discord Mute/Deafen", 
  "Icon": "discord-mic-off", 
  "Version": "${CMAKE_PROJECT_VERSION}",
  "URL": "https://github.com/fredemmott/streamdeck-discord",
  "OS": [
    {
        "Platform": "windows", 
        "MinimumVersion" : "10"
    },
    {
        "Platform": "mac",
        "MinimumVersion": "10.11"
    }
  ],
  "SDKVersion": 2,
  "Software": {
    "MinimumVersion" : "4.1"
  }
}
