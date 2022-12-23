I am trying to creat a game engine with C++ and showcase some possible things to do in the game engine such as
- A basic rendering system
- Resource management
- 3 Game engine components
- namespace classes accordingly

Specifics in tasks:

BASIC RENDERING SYSTEM
By default, the “camera” only renders polygons that are within -1~1 in X, Y and Z coordinates. Also, resizing the window to be non-square will stretch the rendered scene. This is because the projection matrix is the identity matrix. 
1. Change the projection matrix so that the rendered view is pixel perfect (1 OpenGL unit = 1 pixel) 
2. When the window is resized, update the viewport to have the same window content size.

RESOURCE MANAGEMENT
Add ResourceAllocator for managing your game resources. The ResourceAllocator should also implement a function to release unused resources (free memory) Component that uses resource MUST get its resource from ResourceAllocator rather than creating it themselves.

GAME ENGINE COMPONENTS
Add Transform component. It needs to: 1. Have position (XY), rotation (Z) and scaling (XY). 2. The Transform component MUST be added to GameObject by default on the GameObject’s creation. 3. Visualizations such as SpriteRenderer MUST make use of Transform values. For this, a Vector and Matrix class is provided (the same one in Computer Graphics course)

SPRITE RENDERER
Add SpriteRenderer component. Sprites are required to render as alpha blended (Transparent).  
The SpriteRenderer component needs to have these features: 
1. Have colour tinting and opacity. (the default is white colour with opacity of 1.0) a. setColour(r,g,b) b. setColour(Vec3) c. setOpacity(a) 
2. Able to set custom sprite size. (the default is the loaded texture size) a. setSize(w,h) b. setSize(Vec2) 
3. Able to set Sprite pivot (the default is x:0.5, y:0.5) a. setPivot(x,y) b. setPivot(Vec2) 
4. Use transform values from Transform component 

<FreeStyle> core game engine component
Design and implement one component that are useful for game developers. 
The component MUST be useful for developing games. Example: Button, Label, Camera.

NAMESPACE YOUR CODES
Ensure all your codes are properly namespaced. Objects that are part of the game engine should be namespaced XYZEngine, where XYZ is your chosen name.
Codes that are not part of game engine should be in different namespace, such as codes for showcase. 

i have some errors going so ChatGPT Please help me if youre reading this.

