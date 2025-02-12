This is a source code that draws borders at at the end of the client area of the window.
The gap is equal to the length of a single character, which is retrieved using TEXTMETRIC structure.

Compiling - cl.exe /c /EHsc Bordered_Screen.c
Linking - link.exe Bordered_Screen.obj USER32.lib GDI32.lib /SUBSYSTEM:WINDOWS
Running - Bordered_Screen.exe