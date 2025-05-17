//#include <fstream>
//#include <iostream>
//#include <GL/glut.h>
//
//#define checkImageWidth 512
//#define checkImageHeight 512
//
//using namespace std;
//
//typedef unsigned short ushort;
//typedef unsigned long ulong;
//typedef unsigned char uchar;
//
//static fstream inf;
//static GLubyte checkImage[checkImageHeight][checkImageWidth][4];
//
//class mRGB {
//public:
//    uchar r, g, b, a;
//    mRGB() : r(0), g(0), b(0), a(255) {}
//};
//
//class RGBpixmap {
//public:
//    int nRows = 0, nCols = 0;
//    mRGB* pixel = nullptr;
//
//    RGBpixmap();  // Constructor declaration
//    ~RGBpixmap(); // Destructor declaration
//
//    void makeCheckImage();
//    void makeCheckerBoard();
//    void readBMPFile(const char* fname);
//    void setTexture(GLuint textureName);
//};
//
//// Destructor Definition Outside the Class
//RGBpixmap::~RGBpixmap() {
//    delete[] pixel;  // Deallocate memory for pixel array
//}
//
//void RGBpixmap::makeCheckImage() {
//    for (int i = 0; i < checkImageHeight; i++) {
//        for (int j = 0; j < checkImageWidth; j++) {
//            int c = (((i & 0x8) == 0) ^ ((j & 0x8) == 0)) * 255;
//            checkImage[i][j][0] = (GLubyte)c;
//            checkImage[i][j][1] = (GLubyte)c;
//            checkImage[i][j][2] = (GLubyte)c;
//            checkImage[i][j][3] = (GLubyte)255;
//        }
//    }
//}
//
//void RGBpixmap::makeCheckerBoard() {
//    nRows = nCols = 64;
//    pixel = new mRGB[nRows * nCols];
//    if (!pixel) {
//        cerr << "Out of memory!\n";
//        return;
//    }
//
//    long count = 0;
//    for (int i = 0; i < nRows; i++) {
//        for (int j = 0; j < nCols; j++) {
//            int c = (((i / 8) + (j / 8)) % 2) * 255;
//            if (count < nRows * nCols) {
//                pixel[count].r = c;
//                pixel[count].g = c;
//                pixel[count++].b = 0;
//            }
//        }
//    }
//}
//
//void RGBpixmap::setTexture(GLuint textureName) {
//    glBindTexture(GL_TEXTURE_2D, textureName);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
//    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
//
//    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
//
//    if (textureName == 1) {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth, checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, checkImage);
//    }
//    else if (pixel) {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, nCols, nRows, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixel);
//    }
//
//    glEnable(GL_TEXTURE_GEN_S);
//    glEnable(GL_TEXTURE_GEN_T);
//}
//
//ushort getShort() {
//    char ic;
//    ushort ip;
//    inf.get(ic); ip = (uchar)ic;
//    inf.get(ic); ip |= ((ushort)(uchar)ic << 8);
//    return ip;
//}
//
//ulong getLong() {
//    ulong ip = 0;
//    char ic = 0;
//    unsigned char uc;
//    inf.get(ic); uc = (unsigned char)ic; ip = uc;
//    inf.get(ic); uc = (unsigned char)ic; ip |= ((ulong)uc << 8);
//    inf.get(ic); uc = (unsigned char)ic; ip |= ((ulong)uc << 16);
//    inf.get(ic); uc = (unsigned char)ic; ip |= ((ulong)uc << 24);
//    return ip;
//}
//
//void RGBpixmap::readBMPFile(const char* fname) {
//    inf.open(fname, ios::in | ios::binary);
//    if (!inf) {
//        cerr << "Cannot open file: " << fname << endl;
//        return;
//    }
//
//    char ch1, ch2;
//    inf.get(ch1); inf.get(ch2);
//    ulong fileSize = getLong();
//    ushort reserved1 = getShort();
//    ushort reserved2 = getShort();
//    ulong offBits = getLong();
//    ulong headerSize = getLong();
//    ulong numCols = getLong();
//    ulong numRows = getLong();
//    ushort planes = getShort();
//    ushort bitsPerPixel = getShort();
//    ulong compression = getLong();
//    ulong imageSize = getLong();
//    ulong xPels = getLong();
//    ulong yPels = getLong();
//    ulong numLUTentries = getLong();
//    ulong impColors = getLong();
//
//    if (bitsPerPixel != 24 || compression != 0) {
//        cerr << "Not a 24-bit uncompressed BMP file.\n";
//        inf.close();
//        return;
//    }
//
//    int nBytesInRow = ((3 * numCols + 3) / 4) * 4;
//    int numPadBytes = nBytesInRow - 3 * numCols;
//
//    nRows = static_cast<int>(numRows);
//    nCols = static_cast<int>(numCols);
//
//    delete[] pixel;  // Ensure the previous pixel array is deleted before allocating new memory
//    pixel = new mRGB[nRows * nCols];
//    if (!pixel) {
//        cerr << "Memory allocation failed.\n";
//        inf.close();
//        return;
//    }
//
//    long count = 0;
//    for (int row = 0; row < nRows; row++) {
//        for (int col = 0; col < nCols; col++) {
//            char b, g, r;
//            inf.get(b); inf.get(g); inf.get(r);
//            if (count < nRows * nCols) {
//                pixel[count].r = static_cast<uchar>(r);
//                pixel[count].g = static_cast<uchar>(g);
//                pixel[count++].b = static_cast<uchar>(b);
//            }
//        }
//        inf.ignore(numPadBytes);
//    }
//
//    inf.close();
//}
//




// RGBpixmap.cpp
// RGBpixmap.cpp

#include <fstream>    // For file input/output operations (std::fstream)
#include <iostream>   // For standard input/output (std::cerr)
#include <GL/glut.h>  // Needed for GLubyte, GLuint, and OpenGL functions like glTexImage2D, glBindTexture, etc.

#include "rgbpixmap.h" // Include the header file containing RGBpixmap class declaration

// Keep specific defines used within this implementation file
#define checkImageWidth 512
#define checkImageHeight 512

// Global static variables used by this module (specific to this .cpp file)
static std::fstream inf; // File stream object for reading files.
static GLubyte checkImage[checkImageHeight][checkImageWidth][4]; // Static array for generated texture data.

// Note: typedefs for ushort, ulong, uchar, mRGB class, and RGBpixmap constructor/destructor
// DEFINITIONS are now in rgbpixmap.h

// --- Member Function Definitions for RGBpixmap (excluding constructor/destructor) ---

// Constructor definition - DELETE THIS BLOCK (now in header)
/*
RGBpixmap::RGBpixmap() {
    // Initialize members.
    nRows = 0;
    nCols = 0;
    pixel = nullptr; // Initialize pointer to null
}
*/

// Destructor definition - DELETE THIS BLOCK (now in header)
/*
RGBpixmap::~RGBpixmap() {
    delete[] pixel; // Free the dynamically allocated pixel array if it exists
    pixel = nullptr; // Good practice to nullify pointer after delete
}
*/


// Generates a fine-grained black and white checkerboard pattern
// Keep this definition
void RGBpixmap::makeCheckImage() {
    for (int i = 0; i < checkImageHeight; i++) {
        for (int j = 0; j < checkImageWidth; j++) {
            int c = (((i & 0x8) == 0) ^ ((j & 0x8) == 0)) * 255;
            checkImage[i][j][0] = (GLubyte)c; // Red
            checkImage[i][j][1] = (GLubyte)c; // Green
            checkImage[i][j][2] = (GLubyte)c; // Blue
            checkImage[i][j][3] = (GLubyte)255; // Alpha (opaque)
        }
    }
}

// Generates a larger, blocky black and yellow checkerboard
// Keep this definition
void RGBpixmap::makeCheckerBoard() {
    nRows = 64;
    nCols = 64;
    delete[] pixel; // Delete old data if any
    pixel = new mRGB[static_cast<long>(nRows) * nCols]; // Allocate memory using the mRGB type defined in the header
    if (!pixel) {
        std::cerr << "RGBpixmap::makeCheckerBoard: Out of memory!\n";
        return;
    }

    long count = 0;
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            int c = (((i / 8) + (j / 8)) % 2) * 255;
            if (count < static_cast<long>(nRows) * nCols) { // Corrected boundary check using long
                pixel[count].r = static_cast<uchar>(c);       // Use uchar type defined in header
                pixel[count].g = static_cast<uchar>(c);       // Use uchar type defined in header
                pixel[count].b = static_cast<uchar>(0);       // Use uchar type defined in header
                pixel[count].a = static_cast<uchar>(255);     // Use uchar type defined in header
                count++;
            }
        }
    }
}

// Configures OpenGL texture parameters and uploads image data
// Keep this definition
void RGBpixmap::setTexture(GLuint textureName) {
    glBindTexture(GL_TEXTURE_2D, textureName);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    // Upload texture data to GPU
    if (textureName == 1 && checkImageWidth > 0 && checkImageHeight > 0) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth, checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, checkImage);
    }
    else if (pixel && nCols > 0 && nRows > 0) {
        // Use pixel data from the mRGB array, casting to GLubyte* for glTexImage2D
        // Assuming mRGB is tightly packed bytes: r, g, b, a
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, nCols, nRows, 0, GL_RGBA, GL_UNSIGNED_BYTE, reinterpret_cast<GLubyte*>(pixel));
    }

    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
}

// --- Helper functions for reading BMP files (internal to this module) ---

// Reads a 2-byte unsigned short from the file stream (little-endian)
// Keep this definition
static ushort getShort() { // Uses ushort type defined in header
    char ic;
    ushort ip;
    inf.get(ic); ip = static_cast<uchar>(ic); // Use uchar type defined in header
    inf.get(ic); ip |= (static_cast<ushort>(static_cast<uchar>(ic)) << 8); // Use ushort and uchar
    return ip;
}

// Reads a 4-byte unsigned long from the file stream (little-endian)
// Keep this definition
static ulong getLong() { // Uses ulong type defined in header
    ulong ip = 0;
    char ic = 0;
    unsigned char uc; // Use unsigned char for bitwise operations
    inf.get(ic); uc = static_cast<unsigned char>(ic); ip = uc;
    inf.get(ic); uc = static_cast<unsigned char>(ic); ip |= (static_cast<ulong>(uc) << 8); // Use ulong
    inf.get(ic); uc = static_cast<unsigned char>(ic); ip |= (static_cast<ulong>(uc) << 16); // Use ulong
    inf.get(ic); uc = static_cast<unsigned char>(ic); ip |= (static_cast<ulong>(uc) << 24); // Use ulong
    return ip;
}

// Reads a 24-bit uncompressed BMP file into the pixel array
// Keep this definition
void RGBpixmap::readBMPFile(const char* fname) {
    inf.open(fname, std::ios::in | std::ios::binary);
    if (!inf) {
        std::cerr << "RGBpixmap::readBMPFile: Cannot open BMP file: " << fname << std::endl;
        return;
    }

    // Read BMP File Header (14 bytes)
    char ch1, ch2;
    inf.get(ch1); inf.get(ch2);
    if (ch1 != 'B' || ch2 != 'M') {
        std::cerr << "RGBpixmap::readBMPFile: Not a BMP file: " << fname << std::endl;
        inf.close();
        return;
    }
    /* ulong fileSize = */ getLong();
    /* ushort reserved1 = */ getShort();
    /* ushort reserved2 = */ getShort();
    /* ulong offBits = */ getLong();

    // Read DIB Header (Bitmap Information Header - typically 40 bytes for BITMAPINFOHEADER)
    /* ulong headerSize = */ getLong();
    ulong numColsBMP = getLong(); // Variables declared HERE
    ulong numRowsBMP = getLong(); // Variables declared HERE
    /* ushort planes = */ getShort();
    ushort bitsPerPixel = getShort(); // Variables declared HERE
    ulong compression = getLong();    // Variables declared HERE
    /* ulong imageSize = */ getLong();
    /* ulong xPels = */ getLong();
    /* ulong yPels = */ getLong();
    /* ulong numLUTentries = */ getLong();
    /* ulong impColors = */ getLong();

    if (bitsPerPixel != 24 || compression != 0) { // Variables used HERE
        std::cerr << "RGBpixmap::readBMPFile: Not an uncompressed 24-bit BMP file: " << fname << std::endl;
        inf.close();
        return;
    }

    int nBytesInRow = static_cast<int>(((3 * numColsBMP + 3) / 4) * 4); // Variables used HERE
    int numPadBytes = nBytesInRow - static_cast<int>(3 * numColsBMP); // Variables used HERE

    nRows = static_cast<int>(numRowsBMP); // Variables used HERE
    nCols = static_cast<int>(numColsBMP); // Variables used HERE

    delete[] pixel;
    pixel = new mRGB[static_cast<long>(nRows) * nCols]; // Allocation using mRGB. nRows, nCols used HERE
    if (!pixel) {
        std::cerr << "RGBpixmap::readBMPFile: Memory allocation failed for pixel data.\n";
        inf.close();
        return;
    }

    // Read BMP files bottom-up and store top-down
    for (int row = 0; row < nRows; row++) { // nRows used HERE
        long targetRowStart = (static_cast<long>(nRows) - 1 - row) * static_cast<long>(nCols); // nRows, nCols used HERE

        for (int col = 0; col < nCols; col++) { // nCols used HERE
            char b_char, g_char, r_char;
            inf.get(b_char); inf.get(g_char); inf.get(r_char);

            if ((targetRowStart + col) < (static_cast<long>(nRows) * static_cast<long>(nCols))) { // nRows, nCols used HERE
                pixel[targetRowStart + col].r = static_cast<uchar>(r_char); // Use uchar
                pixel[targetRowStart + col].g = static_cast<uchar>(g_char); // Use uchar // Corrected typo: pixel[targetRowStart + col]
                pixel[targetRowStart + col].b = static_cast<uchar>(b_char); // Use uchar
                pixel[targetRowStart + col].a = static_cast<uchar>(255);    // Use uchar
            }
        }
        inf.ignore(numPadBytes); // numPadBytes used HERE
    }

    inf.close();
}