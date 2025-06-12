#pragma once
// Utils.h
#ifndef UTILS_H
#define UTILS_H
#include <graphics.h>
#include <windows.h>
#pragma comment(lib, "MSIMG32.LIB")
inline void transparentimage3(IMAGE* dstimg, double x, double y, IMAGE* srcimg) {
    HDC dstDC = GetImageHDC(dstimg);
    HDC srcDC = GetImageHDC(srcimg);
    int w = srcimg->getwidth();
    int h = srcimg->getheight();
    BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
    AlphaBlend(dstDC, static_cast<int>(x), static_cast<int>(y), w, h, srcDC, 0, 0, w, h, bf);
}
inline void drawSelection(IMAGE* buffer, double x, double y) {
    setlinecolor(RED);
    rectangle(static_cast<int>(x), static_cast<int>(y), static_cast<int>(x + 66), static_cast<int>(y + 66));
}

#endif
