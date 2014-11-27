YUI.add("yuidoc-meta", function(Y) {
   Y.YUIDoc = { meta: {
    "classes": [
        "Commander",
        "ExternalCommand",
        "cdCommand"
    ],
    "modules": [
        "classes",
        "commands"
    ],
    "allModules": [
        {
            "displayName": "classes",
            "name": "classes",
            "description": "A (very) simple representation of an IOC container. Maps command names to\ncreator functions."
        },
        {
            "displayName": "commands",
            "name": "commands",
            "description": "Command to change the current directory during shell execution"
        }
    ]
} };
});