# Warp Drive Workflows for XIAO ePaper Project

## 🔧 Development Workflows

### 1. Project Setup Workflow
```bash
# Navigate to project
cd /Users/nives/Documents/Arduino/XIAO_ePaper_Serial_Display

# Check Git status
git status

# View recent commits
git log --oneline -5
```

### 2. Code Development Workflow
```bash
# Make changes, then commit
git add .
git commit -m "Descriptive commit message"
git push origin main
```

### 3. Arduino Upload Workflow
```bash
# Compile check (if using arduino-cli)
arduino-cli compile --fqbn esp32:esp32:XIAO_ESP32C3 .

# Upload to board
arduino-cli upload -p /dev/cu.usbmodem* --fqbn esp32:esp32:XIAO_ESP32C3 .
```

### 4. Testing Workflow
```bash
# Monitor serial output
screen /dev/cu.usbmodem* 115200

# Or if you have Arduino IDE, use its Serial Monitor
```

### 5. Git History and Troubleshooting
```bash
# View detailed commit history
git log --graph --pretty=format:'%h - %an, %ar : %s'

# See what changed in last commit
git show HEAD

# Revert to previous commit if needed
git reset --hard HEAD~1
```

## 📁 Project Context

- **Hardware**: XIAO ESP32C3 + 7.5" ePaper Display (UC8179)
- **Library**: Seeed_GFX (https://github.com/Seeed-Studio/Seeed_GFX)
- **GitHub**: https://github.com/nativenav/XIAO_ePaper_Serial_Display
- **Features**: Anti-ghosting, serial commands, text sizing, display modes

## 🎯 Common Serial Commands to Test

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
