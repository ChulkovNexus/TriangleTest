#include <jni.h>

#include <GLES2/gl2.h>
#include <GLES3/gl3.h>

#define NANOVG_GL2_IMPLEMENTATION   // Use GL2 implementation.
#include "nanovg/nanovg_gl.h"

struct NVGcontext *vg;

int w = 500, h = 1000;
int centerHorisontal, centerVertical;
float lenX = 400, lenY = 400;


JNIEXPORT void JNICALL
Java_com_test_triangle_NanovgWrapper_on_1surface_1created(JNIEnv *env, jclass type) {
    glClearColor(255, 0, 0, 0);
}

JNIEXPORT void JNICALL
Java_com_test_triangle_NanovgWrapper_on_1surface_1changed(JNIEnv *env, jclass type, jint width,
                                                          jint height) {

    vg = nvgCreateGL2(NVG_ANTIALIAS | NVG_STENCIL_STROKES | NVG_DEBUG);

    centerHorisontal = w / 2;
    centerVertical = h / 2;
}

JNIEXPORT void JNICALL
Java_com_test_triangle_NanovgWrapper_on_1draw_1frame(JNIEnv *env, jclass type) {

    glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    drawTriangle();
}


void drawTriangle(){
    nvgBeginFrame(vg, w, h, h / w);
    nvgBeginPath(vg);
    nvgMoveTo(vg, centerHorisontal,  centerVertical - lenY / 2);
    nvgLineTo(vg, centerHorisontal - lenX / 2, centerVertical + lenY / 2);
    nvgLineTo(vg, centerHorisontal + lenX / 2, centerVertical + lenY / 2);
    nvgFillColor(vg, nvgRGBA(0, 255, 0, 255));
    nvgFill(vg);
    nvgEndFrame(vg);
}
