package com.test.triangle;

/**
 * Created by Панда on 11.06.2016.
 */
public class NanovgWrapper {
    static {
        System.loadLibrary("triangle_renderer");
    }

    public static native void on_surface_created();

    public static native void on_surface_changed(int width, int height);

    public static native void on_draw_frame();
}
