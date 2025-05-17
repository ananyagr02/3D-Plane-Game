// rgbpixmap.h
#ifndef RGBPIXMAP_H // Include guard to prevent multiple inclusions
#define RGBPIXMAP_H

#include <GL/glut.h> // For GLubyte, GLuint etc.
#include <iostream> // Needed for std::cerr used in member functions

// Type aliases
typedef unsigned short ushort;
typedef unsigned long ulong;
typedef unsigned char uchar;

// Helper class for pixel data
class mRGB {
public:
    uchar r, g, b, a;
    mRGB() : r(0), g(0), b(0), a(255) {} // Default to black, opaque
};

// Class declaration for RGBpixmap
class RGBpixmap {
public:
    int nRows, nCols;
    mRGB* pixel;

    // Constructor definition (moved from cpp, now inline)
    RGBpixmap() {
        nRows = 0;
        nCols = 0;
        pixel = nullptr; // Initialize pointer to null
    }

    // Destructor definition (moved from cpp, now inline)
    ~RGBpixmap() {
        delete[] pixel; // Free the dynamically allocated pixel array if it exists
        pixel = nullptr; // Good practice to nullify pointer after delete
    }

    // Member function declarations (implementations remain in cpp)
    void makeCheckImage();
    void makeCheckerBoard();
    void readBMPFile(const char* fname);
    void setTexture(GLuint textureName);

    // Declare helper functions as friends if they need access to private/protected members,
    // or keep them static in the cpp file if they only use public interface or globals.
    // Based on your current cpp, they use 'inf' which is static global.
    // If they were static member functions, their definitions would also be in the cpp.
    // Keeping them static global in the cpp is fine as they are only used internally there.
};

// Define static helper functions' *declarations* here so they can be used by readBMPFile declaration (though readBMPFile calls them)
// Alternatively, define them *before* readBMPFile in the .cpp file.
// Let's keep them static in the cpp as they are now, it's less header clutter.

#endif // RGBPIXMAP_H