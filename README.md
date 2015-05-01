# animated-toque
####A super Canadian wearable to show sound visualizations while keeping your head warm!

Created in collaboration with [Justina Choi](http://justinachoi.com/) and [Adalyn Ordono](http://adalynordono.com/).

![image](https://cloud.githubusercontent.com/assets/9125578/7426384/b90b9e44-ef91-11e4-8f69-81063da3716e.png)

This wearable prototype has three options for the interactive sound visualization shown on the hat.
Each were made using [Adafruit's GFX library](https://github.com/adafruit/Adafruit-GFX-Library).
This is by no means exhaustive and there is a lot of room for more shapes and visualizations to be created using this library or other tools.

Keep in mind you will need at least 11V of power (including the power from the Arduino) for this project. Batteries are key!

###Technology used:
* Arduino Uno
* MAX9814 Electret Microphone Amplifier 
* 1.8 Color TFT LCD Screen Breakout
* Mini Breadboard
* Male-to-male wires
* USB A to USB B Cable

###Build Steps:

- Solder the screen to the cut-to-size header strip (included)
- Let the solder cool, then plug into the mini breadboard
- Connect TFT Screen to Arduino Uno using [Adafruit’s instructions](https://learn.adafruit.com/1-8-tft-display/breakout-wiring-and-test)

    **NOTE**: The “3-5V Vin” listed on Adafruit’s site corresponds to the VCC (power) and LITE (backlight) pins on the TFT screen we used -- you must power both separately. Similarly, the CS pin is actually TFT_CS and RST is RESET on our model

    Also, connect MISO to pin 11 (not listed on Adafruit’s instructions)

- Attach the electret microphone following the same instructions used in [this microphone project](https://github.com/andkerel/obnoxious-sound-meter)

    ![image](https://cloud.githubusercontent.com/assets/9125578/7426368/8164e66c-ef91-11e4-863e-5c09bb5dca7e.png)
    ![image](https://cloud.githubusercontent.com/assets/9125578/7426370/871e87d4-ef91-11e4-9929-b8119bc956da.png)

- Upload one of the code snippets provided in this repository to the Arduino. They each look something like this:

    ![image](https://cloud.githubusercontent.com/assets/9125578/7426377/abc9459c-ef91-11e4-9cc4-a92d2724a6b4.png)
    ![image](https://cloud.githubusercontent.com/assets/9125578/7426380/affa2050-ef91-11e4-9177-ef0853580c92.png)
    ![image](https://cloud.githubusercontent.com/assets/9125578/7426382/b462cae8-ef91-11e4-838e-7dff41857ef2.png)

- Acquire a hat with a wide foldover brim and cut a hole big enough for the TFT LCD screen to fit through
- Fit the TFT LCD screen into said cutout and hide the rest of the wiring behind the brim

    ![image](https://cloud.githubusercontent.com/assets/9125578/7426374/91a97fce-ef91-11e4-8d0e-506c445c69c1.png)

- Tape down all components using double-sided fabric tape
- Enjoy amazing all of your friends!

