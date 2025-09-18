# xblankwindow
a simple program for displaying a blank window you can't interact with

Compilation:
```
gcc blank.c -o xblankwindow -lX11
```

Optional steps:
```
sudo cp xblankwindow /usr/local/bin/xblankwindow
cp xblankwindow.desktop ~/.local/share/applications/xblankwindow.desktop
```

Usage:

xblankwindow

Options:

-t set window title<br>
-c set color (AARRGGBB)<br>
e.g. xblankwindow -t "Hello" -c AA2211FF

<br>
<br>
<br>
<br>
<br>

why does this exist?

looking for a blank window program just displays troubleshooting articles, this is an extremely simple program anyone can make but it's a bit of convenience.

the main purpose of this program is to be used as a "spacing window" for tiling window managers, for example:
