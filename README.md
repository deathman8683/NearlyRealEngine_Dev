# NearlyRealEngine - 0.1 - Developpment branch

## Available features currently :
### World Generation/Managment
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

### Rendering / FX / Sound / Shader
* **Deferred Rendering**

    The engine dont' render scene with forward rendering, it use deferred rendering with 2 pass, the first for the geometry, the second for the SSAO computation. Finally the result is being coomputed when the Deferred Renderer is called. **Doesn't support transparency**.
    * *Blinn-Phong lighting*

    Blinn-Phong model is used to compute ambient/diffuse/specular component per-fragment in the engine, it can a lot of light without any lags
    * *Screen-Space Ambient Occlusion* **(SSAO)**

    SSAO is added to Blinn-Phong ambient component to compute simple shadow, low number of sample are used with a random/noise kernel rotation.
    * *Depth buffer Reconstruction*

    Deferred Rendering can be expensive while storing position/normal/diffuse component into the gBuffer, so the engine only use 2 texture :
        * The first for diffuse and SSAO component
        * The second for normal
    With the combination of a high precision depth buffer, position are being reconstructed.
    * *Water reflection*

    The engine compute water reflection based on a skybox texture and voxel type properties
* **SkyBox**

A full skybox support has been implemented, it's fast and simple to use. It's uses in shader to compute some effect

### Entity / Player Managment
* **Fixed/Moveable camera control**

The camera control in the engine are separated in several class (from basics key input to high level movelable camera). Fixed Camera are used for off-screen rendering.
* **Input system for any controller**

The input system use the KeyBinder feature, so any controller can be mapped in the application with relative ease.
* **Customizable binding system**

KeyBinder feature save all input into readable-file, so that a random user can remap all key from the file or in the application.

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

## Work in Progress :
### Exception Handling
* Strong exception system to prevent any error in the application

### World Generation/Managment
* **World interaction**

### Entity / Player Managment
* AI Entity

### 3D Modeling
* Full support to load 3D object
* **Custom voxel model support**

### Rendering / FX / Sound / Shader
* Full sound support
* Full Interface/Text support

## Stress Test

Memory taken for 51x51 world (80m+ voxels) : ~500Mo
Performance (limited to 60fps) *tested with 5 light source and all effect feature* :
* Average 60fps
* Worst case (all the world in the view frustum) : 20fps
