# NearlyRealEngine - 0.1 - Developpment branch

![WallPaper](https://github.com/AbelDoc/NearlyRealEngine_Dev/blob/master/WallPaper.png)

## Available features currently :
### World Generation/Management
* **Fast voxel mesh construction**

A fast voxel mesh construction system has been built in the engine, it use hashmap and several visual optimization in order to construct chunk's mesh in less than 1-2ms.
* **Procedural world generation**

Using FastNoise library, the engine own a procedural world generation system, used when the chunk are dynamicly loaded around the player, or just for static world.
* **Fast RegionFile system**

Chunks' Data are groupped together using Region file system, it manage chunk's data compression chunks' save/load system. It's improving a lot the engine performancein reducing the number of file readed to load world.
* **Frustum culling**

Chunk's that are not in the view frustum are not being rendering, it use the FixedCamera's Frustum feature.
* **Voxel face culling**

All voxel face that are not visible are culled, so only visible face are rendered, that's a part of the fast voxel mesh construction algorithm.
* **Voxel merging**

Voxels are merged together if they have same properties (type, ...), that's a part of the fast voxel construction algorithm.
* **World shifting**

While the player / camera move, the world load/save dynamicly chunk around it.
* **World interaction**

The player can destroy/place block in the world, still WIP.

### Rendering / FX / Sound / Shader
* **Deferred Rendering**

    The engine dont' render scene with forward rendering, it use deferred rendering with 2 pass, the first for the geometry, the second for the SSAO computation. Finally the result is being coomputed when the Deferred Renderer is called. **Doesn't support transparency**.
    * *Physically Based Rendering* **PBR**

    The engine use PBR to display object, it use material loaded on fly (Texture file) to compute needed value
    * *Screen-Space Ambient Occlusion* **(SSAO)**

    SSAO is added to PBR ambient component to compute simple shadow, low number of sample are used with a random/noise kernel rotation.
    * *Depth buffer Reconstruction*

    Deferred Rendering can be expensive while storing position/normal/diffuse component into the gBuffer, so the engine only use 2 texture :

        * The first for diffuse and SSAO component
        * The second for normal

    With the combination of a high precision depth buffer, position are being reconstructed.
    * *Water reflection*

    The engine compute water reflection based on a skybox texture and voxel type properties
    * *Texture mapping*

    The engine can support texturing, in addition to the material system.
    * *Normal mapping*

    A technique of vertex displacement to show elevation in texture, in order to make things less flat and more realistic combined with PBR lighting.
* **EnvironmentMap**

Environment map are used in the engine to represent advanced skybox, they are loaded with equirectangular HDR image.
Some calculation are done on fly to process object reflections with them.

### Entity / Player Management
* **Fixed/Moveable camera control**

The camera control in the engine are separated in several class (from basics key input to high level movelable camera). Fixed Camera are used for off-screen rendering.
* **Input system for any controller**

The input system use the KeyBinder feature, so any controller can be mapped in the application with relative ease.
* **Customizable binding system**

KeyBinder feature save all input into readable-file, so that a random user can remap all key from the file or in the application.

### Object Management
* **2D object support**

The engine support 2D object rendering, they can be loaded with texture and display with relative ease

* **3D and Voxel object support**

Complex 3D model can be loaded using Assimp library, as voxel model can be loaded from custom compressed file.
They are optimized to work with the engine's mesh system.

### Wrapper
* Wrap a lot of OpenGL functionnality into class
    * VAO
    * IBO
    * Texture
    * Buffer
    * ...
* Wrap a lot of SDL functionnality into class
    * Surface
    * Window
    * Event
    * ...

### Misceallenous
* **Mathematical module**
    * *2-3-4D Point, Vector*

    No inheritance between them, they are build to simplify OpenGL call, so they are build with fixed size array (2, 3 or 4 coordinates)
    * *2-3-4x4 Matrix*

    Matrix module manage all transformations that can be done on matrix (projection, translation, ...)
    * *Frustum*

    The Frustum manage the Frustum culling with simple geometry, need to be coupled to camera in order to work
* **Color system (HSL-A, RGB-A)**

Color conversion system is implemented in order to work with RGB color as HSL color (which are converted to RGB before passed to OpenGL)
* **Time module**

A simple time module with several class to manage date, timestep, application clock, cpu management
    * Control CPU utilization

* **IO Module**

A full IO system has been created to secure in and output with exception, it's used in the whole engine
Also used to write/read from file with more ease than standard stream.

## Work in Progress :

### Entity / Player Managment
* AI Entity

### Rendering / FX / Sound / Shader
* Full sound support
* Full Interface/Text support

## Stress Test

Memory taken for 51x51 world (80m+ voxels) : ~500Mo
+ 1M Vertices model

Performance (limited to 60fps) *tested with 5 light source and all effect feature* :
* Average 60fps
* Worst case (all the world in the view frustum) : 20fps
