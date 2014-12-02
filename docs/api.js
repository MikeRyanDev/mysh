YUI.add("yuidoc-meta", function(Y) {
   Y.YUIDoc = { meta: {
    "classes": [
        "Command",
        "Commander",
        "ExternalCommand",
        "FileOutput",
        "Parser",
        "ShellError",
        "cdCommand",
        "changeNameCommand",
        "exitCommand",
        "pwdCommand",
        "verCommand"
    ],
    "modules": [
        "classes",
        "commands"
    ],
    "allModules": [
        {
            "displayName": "classes",
            "name": "classes",
            "description": "A (very) simple representation of an IOC container. Maps command names to\ncreator functions. \n\nExample of creator function:\n\n    class exampleCommand{\n        // Command logic\n        static Command *create(vector<string> args){\n            return new exampleCommand(args);\n        }\n    };\n\nRegistering the command with the IoC:\n\n    Commander commands;\n\n    commands.enable(\"example\", &exampleCommand::create);\n\nResolving the command later:\n\n    Command *exampleCmd = commands.resolve(\"example\", args);"
        },
        {
            "displayName": "commands",
            "name": "commands",
            "description": "Base abstract command class that acts like an interface\nfor all other commands to implement"
        }
    ]
} };
});