package com.test.triangle;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;
import android.opengl.GLSurfaceView.Renderer;
/**
 * Created by Панда on 12.06.2016.
 */
public class OpenGLRenderer implements Renderer {

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        NanovgWrapper.on_surface_created();
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        NanovgWrapper.on_surface_changed(width, height);
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        NanovgWrapper.on_draw_frame();
    }
}
