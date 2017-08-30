# Viobyte

You are a computer virus trying to steal as much data as possible. The system
is defended by the Generic Host Offensive Software Terminators (GHOST).

# Building

Viobyte is Pac-Man like game designed for the TinyScreen/TinyDruino platform.
Load the viobyte.ino in the Arduino IDE. Install the TinyScreen library and you
should be able to build it for your device.

If you want to play it on a Linux computer, you can use the tinyscreensim
program (https://github.com/dulsi/tinyscreensim). Install glfw3 library.
Download the tinyscreensim. Run it with the command like:

../tinyscreensim/tinyscreensim viobyte viobyte.ino Sprite.cpp

Now you should be able to run viobyte.

# Thanks
Viobyte uses a modified tinyscreen-spritetile-lib by jonwingrove
https://github.com/jonwingrove/tinyscreen-spritetile-lib
