# XIAO ePaper Serial Display Project

This project allows you to display messages typed in the Arduino IDE Serial Monitor on your Seeed Studio XIAO ESP32C3 with a 7.5" ePaper display.

## Hardware Setup

### Connections
The XIAO ePaper Driver Board should be connected to your XIAO ESP32C3. The pin mappings are:
- SCLK: D8
- MISO: D9  
- MOSI: D10
- CS: D1
- DC: D3
- BUSY: D2
- RST: D0

## Software Setup

### 1. Arduino IDE Configuration
1. Open Arduino IDE
2. Select Board: "XIAO_ESP32C3" from the ESP32 boards
3. Select the correct COM port for your XIAO

### 2. Library Dependencies
Make sure you have the Seeed_GFX library installed from:
https://github.com/Seeed-Studio/Seeed_GFX

### 3. Upload the Sketch
1. Open `XIAO_ePaper_Serial_Display.ino` in Arduino IDE
2. Make sure both `driver.h` and the `.ino` file are in the same folder
3. Compile and upload to your XIAO ESP32C3

## Usage

### 1. Open Serial Monitor
- Set baud rate to 115200
- Set line ending to "Newline" or "Both NL & CR"

### 2. Commands
- Type any text message to display it on screen
- `clear` - Clears all messages from the display
- `size1` - Sets text to small size
- `size2` - Sets text to medium size (default)
- `size3` - Sets text to large size
- `fullrefresh` - Enable full refresh mode (slower, reduces ghosting)
- `normalrefresh` - Enable normal refresh mode (faster)
- `cleanscreen` - Deep clean to remove all ghosting (3 cycles)

### 3. Features
- Displays up to 10 lines of text
- Automatically scrolls when more than 10 messages are sent
- Shows current line count and text size at bottom of screen
- Advanced anti-ghosting refresh modes
- Deep screen cleaning functionality

## Anti-Ghosting Features

ePaper displays can show "ghosting" - faint traces of previously displayed content. This project includes several methods to combat ghosting:

### Refresh Modes
- **Full Refresh Mode** (default): Each update fills the screen black, then white, then draws new content. Slower but eliminates most ghosting.
- **Normal Refresh Mode**: Standard ePaper update. Faster but may show some ghosting over time.

### Anti-Ghosting Commands
- `fullrefresh` - Enable full refresh mode (recommended for best image quality)
- `normalrefresh` - Enable normal refresh mode (use for faster updates)
- `cleanscreen` - Performs 3 cycles of black→white→black→white to deep clean the display

### When to Use Each Mode
- Use **full refresh** when ghosting is visible or for important content
- Use **normal refresh** for rapid updates where some ghosting is acceptable
- Use **cleanscreen** when display has accumulated significant ghosting

## Troubleshooting

### If the display doesn't work:
1. Check that the XIAO ESP32C3 board is properly selected
2. Verify the Seeed_GFX library is installed correctly
3. Make sure the `driver.h` file is in the same folder as the sketch
4. Check serial monitor for any error messages
5. Verify physical connections between XIAO and ePaper display

### If compilation fails:
1. Make sure the `driver.h` file exists in your sketch folder
2. Verify the Seeed_GFX library is properly installed
3. Check that you've selected the correct board (XIAO ESP32C3)

## Display Specifications
- Resolution: 800 x 480 pixels
- Type: Monochrome ePaper (UC8179 controller)
- Update time: ~2-3 seconds per refresh (typical for ePaper)
