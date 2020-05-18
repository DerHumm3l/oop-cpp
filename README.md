# oop-cpp

This project contains the exercises for "Objektorientierte Programmierung mit C++ (ASQ)" (SS2019). Every subfolder includes the respective `.cpp` files for the exercises.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

You need any kind of C++ compiler in order to run the code on your machine. If you want to build this project with VS Code, the Microsoft Visual C++ (MSVC) compiler toolset is recommended. Follow this [Guide](https://code.visualstudio.com/docs/cpp/config-msvc) for configuring VS Code to compile and debug C++. The following guidance only work for Windows machines properly.

### Installing

After setting up VS Code to compile and debug the C++ code, the `launch.json` and `tasks.json` should be configured like this:

#### launch.json

```
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "cl.exe - Aktive Datei erstellen und debuggen",
            "type": "cppvsdbg",
            "request": "launch",
            "program": "${fileDirname}\\bin\\${fileBasenameNoExtension}.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "preLaunchTask": "shell: cl.exe build active file"
        }
    ]
}
```

#### tasks.json

```
{
    "version": "2.0.0",
    "tasks": [
        {
            "type": "shell",
            "label": "shell: cl.exe build active file",
            "command": "cl.exe",
            "args": [
                "/Zi",
                "/EHsc",
                "/Fd:",
                "${fileDirname}\\bin\\program.pdb",
                "/Fo:",
                "${fileDirname}\\bin\\${fileBasenameNoExtension}.obj",
                "/Fe:",
                "${fileDirname}\\bin\\${fileBasenameNoExtension}.exe",
                "${file}"
            ],
            "problemMatcher": [
                "$msCompile"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        },
    ]
}
```

You also have to create a `<exercise>\bin` folder, because the compiler is not able to create it on compiling the code.

### Running

You need to start VS Code from the Developer Command Prompt. If it was not started from the Developer Command Prompt the compiler will not be found and compiling is not possible. If you want to debug, just press F5 and the active file will be compilied and debugged. All necessary files, including `.exe` file, will be created in `<exercise>\bin`. But there is a issue with user input, when debugging inside VS Code. You should compile inside VS Code and test it with a additional command prompt outside of VS Code for now. 

## Authors

* **Lukas Maibaum** - *Initial work* - Student at Friedrich-Schiller Universität Jena

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

This README was created from this [template](https://gist.github.com/PurpleBooth/109311bb0361f32d87a2).
