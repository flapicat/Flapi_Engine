call vendor\premake\premake5.exe vs2022

xcopy Flapi_Engine\assets bin\Debug-windows-x86_64\Flapi_Engine\assets /E /I /Y
xcopy Flapi_Engine\assets bin\Release-windows-x86_64\Flapi_Engine\assets /E /I /Y

PAUSE