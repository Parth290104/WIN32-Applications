This is a simple application that changes the background color on the button press, and the color changes to white on pressing it again(toggling is possible).
Compile - cl.exe /c /EHsc bg_color_change.c
Link - link.exe bg_color_change.obj USER32.lib GDI32.lib /SUBSYSTEM:WINDOWS
