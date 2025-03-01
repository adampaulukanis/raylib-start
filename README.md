# raylib-start

raylib library must be installed first.

It is quite easy to do so, follow instructions for cmake build.
```
$ gIt cl0ne ...raylib-repo
$ cd raylib-repo
$ mkdir build ...
...
$ doas make install
...
$ pkg-config --libs --cflags raylib
-I"/usr/local/include" -L"/usr/local/lib" -lraylib
```

And it should look like this:

```
[adam@controlc ~/Learning/raylib-start]$ ./minimal
INFO: Initializing raylib 5.6-dev
INFO: Platform backend: DESKTOP (GLFW)
INFO: Supported raylib modules:
INFO:     > rcore:..... loaded (mandatory)
INFO:     > rlgl:...... loaded (mandatory)
INFO:     > rshapes:... loaded (optional)
INFO:     > rtextures:. loaded (optional)
INFO:     > rtext:..... loaded (optional)
INFO:     > rmodels:... loaded (optional)
INFO:     > raudio:.... loaded (optional)
INFO: DISPLAY: Device initialized successfully
INFO:     > Display size: 1366 x 768
INFO:     > Screen size:  800 x 450
INFO:     > Render size:  800 x 450
INFO:     > Viewport offsets: 0, 0
INFO: GLAD: OpenGL extensions loaded successfully
INFO: GL: Supported extensions count: 224
INFO: GL: OpenGL device information:
INFO:     > Vendor:   AMD
INFO:     > Renderer: OLAND (radeonsi, , LLVM 16.0.6, DRM 2.50, 7.6)
INFO:     > Version:  4.5 (Core Profile) Mesa 23.3.6
INFO:     > GLSL:     4.50
INFO: GL: VAO extension detected, VAO functions loaded successfully
INFO: GL: NPOT textures extension detected, full NPOT textures supported
INFO: GL: DXT compressed textures supported
INFO: GL: ETC2/EAC compressed textures supported
INFO: PLATFORM: DESKTOP (GLFW - X11): Initialized successfully
INFO: TEXTURE: [ID 1] Texture loaded successfully (1x1 | R8G8B8A8 | 1 mipmaps)
INFO: TEXTURE: [ID 1] Default texture loaded successfully
INFO: SHADER: [ID 1] Vertex shader compiled successfully
INFO: SHADER: [ID 2] Fragment shader compiled successfully
INFO: SHADER: [ID 3] Program shader loaded successfully
INFO: SHADER: [ID 3] Default shader loaded successfully
INFO: RLGL: Render batch vertex buffers loaded successfully in RAM (CPU)
INFO: RLGL: Render batch vertex buffers loaded successfully in VRAM (GPU)
INFO: RLGL: Default OpenGL state initialized successfully
INFO: TEXTURE: [ID 2] Texture loaded successfully (128x128 | GRAY_ALPHA | 1 mipmaps)
INFO: FONT: Default font loaded successfully (224 glyphs)
INFO: SYSTEM: Working Directory: /home/adam/Learning/raylib-start
INFO: TIMER: Target time per frame: 16.667 milliseconds
INFO: TEXTURE: [ID 2] Unloaded texture data from VRAM (GPU)
INFO: SHADER: [ID 3] Default shader unloaded successfully
INFO: TEXTURE: [ID 1] Default texture unloaded successfully
INFO: Window closed successfully
```
