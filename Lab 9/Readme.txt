>> Compiling
`make` to compile all 3 files or `make <cube/sphere/teapot>` for individual fles

>> Running
First `export LD_LIBRARY_PATH=$PWD` then `./<cube/sphere/teapot>`
Audio may glitch in the begining

>> Structure
├── breakout.mp3 (cube audio)
├── bensound-newdawn.mp3 (sphere audio)
├── bensound-sadday.mp3 (teapot audio)
├── cube.c (cube file)
├── earth.jpg (earth texture)
├── ikpMP3.so (plugin for playing .mp3 files)
├── include (header files for playing music)
├── libIrrKlang.so (.so for playing music)
├── makefile
├── sphere.c (sphere file)
├── stb_image.h (required file to load textures)
├── teapot.c (teapot file)
├── teapot.png (teapot texture)
└── wall.jpg (wall texture)



>> Credits:
Texture loading Library: github.com/nothings/stb/blob/master/stb_image.h
Music Library: www.ambiera.com/irrklang/

Brick Texture: learnopengl.com/img/textures/wall.jpg
Earth Texture: planetpixelemporium.com/earth.html
Teapot Texture: pixabay.com/en/pattern-nature-design-patterns-3177414/

Cube Music: 
Sphere Music: https: www.bensound.com
Teapot Music:

.
├── a.out


10 directories, 41 files
