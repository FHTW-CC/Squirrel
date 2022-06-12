# Squirrel

A C++ game engine based on the tutorials by TheCherno.
Currently it includes code up until video 15: "ImGui".

Use this command to clone the repo and all dependencies:
git clone https://github.com/FHTW-CC/Squirrel --recursive

Squirrel uses Premake as its build system which is included in the repository.

To generate the correct project files run GenerateProjectsVS##.bat corresponding to the version of Visual Studio you have installed.
If you want to try a version different than VS17, VS19 or VS22, edit one of the .bat files to use the version of your choice. 
Only VS19 and VS22 were tested.
The default setting uses Visual Studio 22.

The startup project should be "Sandbox" by default. If not, select it as the startup project before trying to run it.
