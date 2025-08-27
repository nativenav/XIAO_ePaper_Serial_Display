#include "TFT_eSPI.h"

#ifdef EPAPER_ENABLE
EPaper epaper;
#endif

String currentMessage = "";
String previousMessage = "";
bool needsUpdate = false;
const int maxMessageLength = 100; // Maximum characters per line
const int maxLines = 10; // Maximum number of lines to display
String messageLines[maxLines];
int lineCount = 0;
int textSize = 2;
int lineHeight = 30;
bool useFullRefresh = true; // Use full refresh to minimize ghosting

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(100); // Reduce timeout for more responsive serial reading
  
  #ifdef EPAPER_ENABLE
  epaper.begin();
  epaper.fillScreen(TFT_WHITE);
  
  // Display welcome message
  epaper.setTextSize(2);
  epaper.setTextColor(TFT_BLACK);
  epaper.drawString("XIAO ePaper Display Ready!", 10, 10);
  epaper.drawString("Type messages in Serial Monitor", 10, 40);
  epaper.drawString("Messages will appear below:", 10, 70);
  epaper.drawLine(0, 100, epaper.width(), 100, TFT_BLACK);
  epaper.update();
  
  Serial.println("ePaper Display initialized!");
  Serial.println("Type messages to display on screen:");
  Serial.println("Commands:");
  Serial.println("  clear - Clear the display");
  Serial.println("  size1 - Small text");
  Serial.println("  size2 - Medium text (default)");
  Serial.println("  size3 - Large text");
  Serial.println("  fullrefresh - Enable full refresh mode (slower, less ghosting)");
  Serial.println("  normalrefresh - Enable normal refresh mode (faster)");
  Serial.println("  cleanscreen - Deep clean to remove all ghosting");
  #else
  Serial.println("ePaper not enabled! Check driver.h configuration.");
  #endif
}

void loop() {
  // Check if there's new serial data
  if (Serial.available()) {
    currentMessage = Serial.readString();
    currentMessage.trim(); // Remove whitespace
    
    if (currentMessage.length() > 0) {
      Serial.println("Received: " + currentMessage);
      
      // Handle special commands
      if (currentMessage == "clear") {
        clearDisplay();
      } else if (currentMessage == "size1") {
        textSize = 1;
        lineHeight = 15;
        Serial.println("Text size set to 1 (small)");
      } else if (currentMessage == "size2") {
        textSize = 2;
        lineHeight = 30;
        Serial.println("Text size set to 2 (medium)");
      } else if (currentMessage == "size3") {
        textSize = 3;
        lineHeight = 45;
        Serial.println("Text size set to 3 (large)");
      } else if (currentMessage == "fullrefresh") {
        useFullRefresh = true;
        Serial.println("Full refresh mode enabled (slower, less ghosting)");
      } else if (currentMessage == "normalrefresh") {
        useFullRefresh = false;
        Serial.println("Normal refresh mode enabled (faster)");
      } else if (currentMessage == "cleanscreen") {
        deepCleanScreen();
      } else {
        // Add new message to display
        addMessageToDisplay(currentMessage);
      }
    }
  }
}

void addMessageToDisplay(String message) {
  #ifdef EPAPER_ENABLE
  
  // Shift existing lines up if we're at max capacity
  if (lineCount >= maxLines) {
    for (int i = 0; i < maxLines - 1; i++) {
      messageLines[i] = messageLines[i + 1];
    }
    lineCount = maxLines - 1;
  }
  
  // Add new message
  messageLines[lineCount] = message;
  lineCount++;
  
  // Redraw display
  updateDisplay();
  
  #endif
}

void updateDisplay() {
  #ifdef EPAPER_ENABLE
  
  if (useFullRefresh) {
    updateDisplayWithAntiGhosting();
  } else {
    updateDisplayNormal();
  }
  
  #endif
}

void updateDisplayNormal() {
  #ifdef EPAPER_ENABLE
  
  epaper.fillScreen(TFT_WHITE);
  
  // Draw header
  epaper.setTextSize(2);
  epaper.setTextColor(TFT_BLACK);
  epaper.drawString("XIAO ePaper Display", 10, 10);
  
  // Draw separator line
  epaper.drawLine(0, 50, epaper.width(), 50, TFT_BLACK);
  
  // Draw messages
  epaper.setTextSize(textSize);
  int yPos = 60;
  
  for (int i = 0; i < lineCount; i++) {
    if (yPos + lineHeight < epaper.height()) {
      epaper.drawString(messageLines[i], 10, yPos);
      yPos += lineHeight;
    }
  }
  
  // Draw status at bottom
  epaper.setTextSize(1);
  String status = "Lines: " + String(lineCount) + "/" + String(maxLines) + 
                  " | Text Size: " + String(textSize) + " | Mode: Normal";
  epaper.drawString(status, 10, epaper.height() - 20);
  
  epaper.update();
  
  Serial.println("Display updated (normal) with " + String(lineCount) + " messages");
  
  #endif
}

void updateDisplayWithAntiGhosting() {
  #ifdef EPAPER_ENABLE
  
  Serial.println("Updating display with anti-ghosting...");
  
  // Step 1: Fill black to clear any ghosting
  epaper.fillScreen(TFT_BLACK);
  epaper.update();
  delay(200); // Short delay for ePaper to process
  
  // Step 2: Fill white to prepare for new content
  epaper.fillScreen(TFT_WHITE);
  epaper.update();
  delay(200); // Short delay for ePaper to process
  
  // Step 3: Draw new content
  epaper.fillScreen(TFT_WHITE);
  
  // Draw header
  epaper.setTextSize(2);
  epaper.setTextColor(TFT_BLACK);
  epaper.drawString("XIAO ePaper Display", 10, 10);
  
  // Draw separator line
  epaper.drawLine(0, 50, epaper.width(), 50, TFT_BLACK);
  
  // Draw messages
  epaper.setTextSize(textSize);
  int yPos = 60;
  
  for (int i = 0; i < lineCount; i++) {
    if (yPos + lineHeight < epaper.height()) {
      epaper.drawString(messageLines[i], 10, yPos);
      yPos += lineHeight;
    }
  }
  
  // Draw status at bottom
  epaper.setTextSize(1);
  String status = "Lines: " + String(lineCount) + "/" + String(maxLines) + 
                  " | Text Size: " + String(textSize) + " | Mode: Anti-Ghost";
  epaper.drawString(status, 10, epaper.height() - 20);
  
  // Final update
  epaper.update();
  
  Serial.println("Display updated (anti-ghosting) with " + String(lineCount) + " messages");
  
  #endif
}

void clearDisplay() {
  #ifdef EPAPER_ENABLE
  
  // Clear message array
  for (int i = 0; i < maxLines; i++) {
    messageLines[i] = "";
  }
  lineCount = 0;
  
  if (useFullRefresh) {
    // Anti-ghosting clear sequence
    epaper.fillScreen(TFT_BLACK);
    epaper.update();
    delay(300);
    
    epaper.fillScreen(TFT_WHITE);
    epaper.update();
    delay(300);
  }
  
  epaper.fillScreen(TFT_WHITE);
  epaper.setTextSize(2);
  epaper.setTextColor(TFT_BLACK);
  epaper.drawString("Display Cleared", 10, epaper.height() / 2 - 10);
  epaper.update();
  
  delay(1000); // Show cleared message briefly
  
  // Restore header with anti-ghosting if enabled
  if (useFullRefresh) {
    epaper.fillScreen(TFT_BLACK);
    epaper.update();
    delay(200);
    
    epaper.fillScreen(TFT_WHITE);
    epaper.update();
    delay(200);
  }
  
  epaper.fillScreen(TFT_WHITE);
  epaper.drawString("XIAO ePaper Display", 10, 10);
  epaper.drawLine(0, 50, epaper.width(), 50, TFT_BLACK);
  epaper.update();
  
  Serial.println("Display cleared!");
  
  #endif
}

void deepCleanScreen() {
  #ifdef EPAPER_ENABLE
  
  Serial.println("Performing deep clean to remove ghosting...");
  
  // Multiple black/white cycles to thoroughly clean the screen
  for (int cycle = 0; cycle < 3; cycle++) {
    Serial.println("Clean cycle " + String(cycle + 1) + "/3");
    
    // Fill black
    epaper.fillScreen(TFT_BLACK);
    epaper.update();
    delay(500); // Longer delay for deep cleaning
    
    // Fill white
    epaper.fillScreen(TFT_WHITE);
    epaper.update();
    delay(500); // Longer delay for deep cleaning
  }
  
  // Final state: restore the current display
  epaper.fillScreen(TFT_WHITE);
  epaper.setTextSize(2);
  epaper.setTextColor(TFT_BLACK);
  epaper.drawString("Screen Cleaned!", 10, epaper.height() / 2 - 10);
  epaper.drawString("Ghosting removed", 10, epaper.height() / 2 + 20);
  epaper.update();
  
  delay(2000); // Show clean message
  
  // Restore current content
  updateDisplay();
  
  Serial.println("Deep clean completed!");
  
  #endif
}
