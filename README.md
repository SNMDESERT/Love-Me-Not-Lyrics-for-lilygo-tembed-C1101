# Love Me Not Lyrics for LilyGo T-Embed C1101

A small embedded project for the LilyGo T-Embed C1101 that displays animated lyrics or visual text on the device screen.

## Overview

This project is built around the Arduino/ESP32-style programming environment and uses a frame-based animation structure to render display content. The repository includes the main sketch file and a large generated animation frames header file.

## Files

- `LoveMeNot_T-Embed-C1101.ino` - main sketch
- `animation_frames.h` - frame data used for display rendering
- `README.md` - project documentation
- `LICENSE` - MIT license

## Features

- Display-based animated text/lyrics output
- Compatible with LilyGo T-Embed C1101 hardware
- Custom visual frame renderer for screen animation
- Minimal project structure for embedded experimentation and customization

## Hardware

- LilyGo T-Embed C1101
- Supported device display and controller setup as used in the sketch

## Build and Flash

1. Open the `.ino` file in the Arduino IDE or compatible environment.
2. Select the appropriate board and port for your LilyGo device.
3. Install any required libraries referenced by the sketch.
4. Compile and upload the project.

## Customization

You can adjust:

- animation timing
- displayed text content
- color and frame behavior
- visual layout and transitions

## License

MIT License

---

A compact embedded display project for showing animated lyrics on a LilyGo T-Embed C1101 screen.
