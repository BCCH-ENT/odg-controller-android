package com.bcch.neilconnatty.odgcontroller;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("MessagingService");
    }

    @Override
    protected void onCreate (Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        initializeMessenger();
    }

    @Override
    protected void onDestroy ()
    {
        super.onDestroy();
        stopMessenger();
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native int initializeMessenger();
    public native void stopMessenger();
    public native void sendMessage(String msg);
    public native void showImage();
    public native void hideImage();
    public native void zoomImage();
    public native void reloadImage();
    public native void uploadImage();
    public native void scrollLeft();
    public native void scrollRight();
    public native void flipView();
}
