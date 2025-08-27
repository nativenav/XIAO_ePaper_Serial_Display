# XIAO ePaper Serial Display - Warp Drive Notebook

## 📋 Project Overview

**Hardware**: XIAO ESP32C3 + 7.5" ePaper Display (UC8179)  
**Library**: Seeed_GFX (https://github.com/Seeed-Studio/Seeed_GFX)  
**GitHub**: https://github.com/nativenav/XIAO_ePaper_Serial_Display  
**Local Path**: `/Users/nives/Documents/Arduino/XIAO_ePaper_Serial_Display`

## 🚀 Quick Start Commands

### Navigate to Project
```bash
cd /Users/nives/Documents/Arduino/XIAO_ePaper_Serial_Display
```

### Check Project Status
```bash
git status
ls -la *.ino *.h *.md
```

## 🔧 Development Workflow

### Standard Git Operations
```bash
# Check what changed
git status
git diff

# Commit changes
git add .
git commit -m "Descriptive commit message"
git push origin main

# View history
git log --oneline -10
```

### View Detailed Git History
```bash
git log --graph --pretty=format:'%h - %an, %ar : %s'
```

## 🧪 ePaper Testing Commands

### Serial Monitor Commands (115200 baud)
```
Hello World!
size1
This is small text
size2  
This is medium text
size3
This is large text
clear
cleanscreen
fullrefresh
normalrefresh
```

### Serial Monitor Setup
- **Baud Rate**: 115200
- **Line Ending**: Newline or Both NL & CR

## ⚙️ Hardware Configuration

### Pin Connections (XIAO ePaper Driver Board)
- SCLK: D8
- MISO: D9  
- MOSI: D10
- CS: D1
- DC: D3
- BUSY: D2
- RST: D0

### Driver Configuration (`driver.h`)
```c
#define BOARD_SCREEN_COMBO 502 // 7.5 inch monochrome ePaper Screen (UC8179)
#define USE_XIAO_EPAPER_DRIVER_BOARD
```

## 🎨 Display Features

### Anti-Ghosting Modes
- **Full Refresh** (default): Black → White → Content (slower, no ghosting)
- **Normal Refresh**: Standard ePaper update (faster, may ghost)
- **Deep Clean**: 3 black/white cycles to remove stubborn ghosting

### Text Sizes
- **size1**: Small text (15px line height)
- **size2**: Medium text (30px line height) - Default  
- **size3**: Large text (45px line height)

### Display Specs
- Resolution: 800 x 480 pixels
- Type: Monochrome ePaper (UC8179 controller)
- Update time: ~2-3 seconds (normal), ~6-8 seconds (full refresh)

## 🐛 Troubleshooting

### Common Issues
```bash
# If display doesn't update
# 1. Check serial monitor for errors
# 2. Try cleanscreen command
# 3. Verify pin connections

# If compilation fails
# 1. Check driver.h is in sketch folder
# 2. Verify Seeed_GFX library installed
# 3. Confirm XIAO ESP32C3 board selected
```

### Git Troubleshooting
```bash
# Revert to last commit
git reset --hard HEAD

# Revert to specific commit
git reset --hard <commit-hash>

# See what changed in a commit
git show <commit-hash>
```

## 📁 Project Files

### Core Files
- `XIAO_ePaper_Serial_Display.ino` - Main Arduino sketch
- `driver.h` - Hardware configuration  
- `README.md` - Project documentation
- `DEVELOPMENT.md` - Git workflow guide

### Key Functions in Sketch
- `updateDisplayWithAntiGhosting()` - Full refresh with ghosting prevention
- `updateDisplayNormal()` - Fast refresh mode
- `deepCleanScreen()` - Deep cleaning cycles
- `clearDisplay()` - Clear with optional anti-ghosting

## 🎯 Development Notes

### Recent Updates
- Anti-ghosting refresh system implemented
- Serial command interface working
- GitHub repository connected
- Full documentation complete

### Next Steps Ideas
- [ ] Add WiFi message receiving
- [ ] Create display templates/layouts  
- [ ] Implement partial screen updates
- [ ] Add image display capability
- [ ] Create configuration web interface

## 🔄 Warp Drive Usage

**Save this notebook to Warp Drive as**: "XIAO ePaper Project Notebook"

This single file contains everything needed to work with the project:
- Commands ready to copy/paste
- Hardware reference information  
- Troubleshooting guide
- Development workflow
- Testing procedures

Perfect for quick project resume and team sharing! 🚀
