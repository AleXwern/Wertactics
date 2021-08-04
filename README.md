# Wertactics
# What?
I'm a big fan of different hardware and how companies/people make different pieces of software/games on them. <br>
I was playing some SNES games during evenings while I was at my summer cottage and took notice of many small things the developers had implemented into the games to give them a nice visual touch and then got bunch of ideas of my own and thus this started. <br>

# Why 3DS?
It's just a little bit more interesting to develop on than PC. Maybe it's because the hardware is more limited or that some of the libctru features are not that obvious, mainly audio. <br>
Also the need of optimization is much greated here than with PC. At least at the start the code is many things except good looking but as things procees I need to pay attention to things like memory usage (ex. can't load all music at once) or how I just implement any specific feature. The main aim is for the game to run smooth 60fps and never dip below that outside instances like loading zones.

# How do I compile this?
You will need install Msys2 from https://www.msys2.org/ and DevkitPro from https://devkitpro.org/ and install needed libraries and then it's just running the Makefile from terminal. The executable is Wer6.3dsx which can be run on 3DS on Citra. Audio does not work on Citra but absolutely fine on real hardware.<br>
Online about 52 in Makefile there's IPADDR which is supposed to be the local IP of the target 3DS -> Using 'make run' you can send the executable to your 3DS from the terminal. Open Homebrew Launcher and press Y and you can also find the 3DS IP here. Make sure both PC and 3DS are connected to same network.
Needed libraries can be installed with 'pacman -S [libraryname]'
1. 3ds-dev (all libraries assossiated)
2. 3ds-sdl
3. 3ds-sdl_mixer
4. 3ds-libmad
5. 3ds-libogg
6. 3ds-libvorbisidec
7. 3ds-mikmod
