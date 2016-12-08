package com.bcch.neilconnatty.odgcontroller;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity
{
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

        final EditText text = (EditText) findViewById(R.id.message_input);
        Button button = (Button) findViewById(R.id.send_message);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                sendMessage(text.getText().toString());
                text.setText("");
            }
        });

        button = (Button) findViewById(R.id.show_image);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                showImage();
            }
        });

        button = (Button) findViewById(R.id.hide_image);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                hideImage();
            }
        });

        button = (Button) findViewById(R.id.zoom_image);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                zoomImage();
            }
        });

        button = (Button) findViewById(R.id.reload_image);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                reloadImage();
            }
        });

        button = (Button) findViewById(R.id.take_image);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                uploadImage();
            }
        });

        button = (Button) findViewById(R.id.scroll_left);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                scrollLeft();
            }
        });

        button = (Button) findViewById(R.id.scroll_right);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                scrollRight();
            }
        });

        button = (Button) findViewById(R.id.flip_view);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                flipView();
            }
        });
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
