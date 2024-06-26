# VecGFX
A simple Vector and Matrix math library focused on the operations related to 2D and 3D Graphics rendering.

VecGFX uses fixed length vector and matrix classes to make it convinient to pass the types to the GPU and to graphic's APIs such as OpenGL.



##  Installation
Steps 
1. Clone the repository
2. Run `make install` which will install the library onto your machine by putting the .so file, headers 
and the man pages into the correct place

## Usage
The relevant header files for the library can be included with `#include<vecgfx/VecGFX.hpp>`
When compiling with g++ the library can be linked with the `-lvecgfx` flag

## Documentation
Included in the source code is three types of documentation
1. HTML documentation which can be viewed by opening docs/html/index.html in a web browser
2. rtf documentation which can be viewed by opening rtf/refman.rtf 
3. man page documentation which can be read with the `man` command after running `make install`
    - To view the documentation enter `man VecGFX_{class to view}`

### List of Classes
- Vec4 
- Vec3
- Mat4
- Mat3

