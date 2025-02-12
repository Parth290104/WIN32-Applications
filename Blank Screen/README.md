# WIN32-Applications
This is a source code written in C which uses the WIN32 SDK to display a blank screen. This is the "hello world" application of WIN32

Compiling Linking And Running
Enter the following commands command prompt provided by Visual Studio (x64 native is preferred)

Compiling - cl.exe /c /EHsc HelloWin.c
Linking - link.exe HelloWin.obj USER32.lib GDI32.lib /SUBSYSTEM:WINDOWS
Running - HelloWin.exe
