//
// Created by indrek on 1.05.2016.
//

// set EXAMPLE to EXAMPLE_UART_USING_SERIAL in setup.h to activate
#include "setup.h"
#if EXAMPLE == 5

#include "Arduino.h"
#include "CameraOV7670.h"

static const uint16_t COLOR_GREEN = 0x07E0;
static const uint16_t COLOR_RED = 0xF800;

static const uint16_t UART_PIXEL_FORMAT_RGB565 = 1;
static const uint16_t UART_PIXEL_FORMAT_GRAYSCALE = 2;

// scaler values for specific refresh rates
static const uint8_t FPS_1_Hz = 9;
static const uint8_t FPS_0p5_Hz = 19;
static const uint8_t FPS_0p33_Hz = 29;

#define UART_MODE 3

#if UART_MODE == 1
static const uint16_t lineLength = 320;
static const uint16_t lineCount = 240;
static const uint32_t baud = 2000000; // may be unreliable
static const uint32_t uartSendWhileReadingCount = 1;
static const uint8_t uartPixelFormat = UART_PIXEL_FORMAT_RGB565;
CameraOV7670 camera(CameraOV7670::RESOLUTION_QVGA_320x240, CameraOV7670::PIXEL_RGB565, 11);
#endif

#if UART_MODE == 2
static const uint16_t lineLength = 320;
static const uint16_t lineCount = 240;
static const uint32_t baud = 1000000;
static const uint32_t uartSendWhileReadingCount = 2;
static const uint8_t uartPixelFormat = UART_PIXEL_FORMAT_RGB565;
CameraOV7670 camera(CameraOV7670::RESOLUTION_QVGA_320x240, CameraOV7670::PIXEL_RGB565, 18);
#endif

#if UART_MODE == 3
static const uint16_t lineLength = 160;
static const uint16_t lineCount = 120;
static const uint32_t baud = 1000000;
static const uint32_t uartSendWhileReadingCount = 4;
static const uint8_t uartPixelFormat = UART_PIXEL_FORMAT_RGB565;
CameraOV7670 camera(CameraOV7670::RESOLUTION_QQVGA_160x120, CameraOV7670::PIXEL_RGB565, 5);
#endif

#if UART_MODE == 4
static const uint16_t lineLength = 160;
static const uint16_t lineCount = 120;
static const uint32_t baud = 115200;
static const uint32_t uartSendWhileReadingCount = 4;
static const uint8_t uartPixelFormat = UART_PIXEL_FORMAT_RGB565;
CameraOV7670 camera(CameraOV7670::RESOLUTION_QQVGA_160x120, CameraOV7670::PIXEL_RGB565, 35);
#endif

#if UART_MODE == 5
static const uint16_t lineLength = 320;
static const uint16_t lineCount = 240;
static const uint32_t baud = 1000000;
static const uint32_t uartSendWhileReadingCount = 4;
static const uint8_t uartPixelFormat = UART_PIXEL_FORMAT_GRAYSCALE;
CameraOV7670 camera(CameraOV7670::RESOLUTION_QVGA_320x240, CameraOV7670::PIXEL_YUV422, 10);
#endif

#if UART_MODE == 6
static const uint16_t lineLength = 160;
static const uint16_t lineCount = 120;
static const uint32_t baud = 1000000;
static const uint32_t uartSendWhileReadingCount = 0;
static const uint8_t uartPixelFormat = UART_PIXEL_FORMAT_GRAYSCALE;
CameraOV7670 camera(CameraOV7670::RESOLUTION_QQVGA_160x120, CameraOV7670::PIXEL_YUV422, 2);
#endif

#if UART_MODE == 7
static const uint16_t lineLength = 640;
static const uint16_t lineCount = 480;
static const uint32_t baud = 1000000;
static const uint8_t uartPixelFormat = UART_PIXEL_FORMAT_GRAYSCALE;
CameraOV7670 camera(CameraOV7670::RESOLUTION_VGA_640x480, CameraOV7670::PIXEL_YUV422, 63);
#endif

void sendBlankFrame(uint16_t color);
String convertPixelByteH(uint8_t byte);
String convertPixelByteL(uint8_t byte);

// inline void startNewFrame(uint8_t pixelFormat) __attribute__((always_inline));
// inline void endOfLine(void) __attribute__((always_inline));
// inline void sendNextPixelByte() __attribute__((always_inline));
// inline void sendPixelByteH(uint8_t byte) __attribute__((always_inline));
// inline void sendPixelByteL(uint8_t byte) __attribute__((always_inline));
// inline void sendPixelByteGrayscale(uint8_t byte) __attribute__((always_inline));
// inline void pixelSendingDelay() __attribute__((always_inline));

// this is called in Arduino setup() function
void initializeScreenAndCamera()
{
  // Enable this for WAVGAT CPUs
  // For UART communiation we want to set WAVGAT Nano to 16Mhz to match Atmel based Arduino
  //CLKPR = 0x80; // enter clock rate change mode
  //CLKPR = 1; // set prescaler to 1. WAVGAT MCU has it 3 by default.

  Serial.begin(baud);
  while (!Serial)
    ;

  if (camera.init())
  {
    Serial.println("Camera initialized");
    sendBlankFrame(COLOR_GREEN);
    delay(1000);
  }
  else
  {
    Serial.println("Unable to initialize camera");
    sendBlankFrame(COLOR_RED);
    while (true)
      ; // Infinite loop
  }
}

String convertPixelByteH(uint8_t byte)
{
  //              RRRRRGGG
  return String(byte | 0b00001000); // make pixel color always slightly above 0 since zero is end of line marker
}

String convertPixelByteL(uint8_t byte)
{
  //              GGGBBBBB
  return String(byte | 0b00100001); // make pixel color always slightly above 0 since zero is end of line marker
}

void sendBlankFrame(uint16_t color)
{
  uint8_t colorH = (color >> 8) & 0xFF;
  uint8_t colorL = color & 0xFF;
  String chaine = "";

  Serial.println("Start Blank Frame");
  for (uint16_t j = 0; j < lineCount; j++)
  {
    for (uint16_t i = 0; i < lineLength; i++)
    {
      // chaine += convertPixelByteH(colorH);
      // chaine += convertPixelByteL(colorL);
      chaine += color;
    }

    Serial.println(chaine);
  }
  Serial.println("End Blank Frame");
}

// this is called in Arduino loop() function
void processFrame()
{
  camera.waitForVsync();

  uint8_t lowByte = 0;
  uint8_t bufferedLowByte = 0;
  String chaine = "";

  Serial.println("Start new Frame");
  for (uint16_t y = 0; y < lineCount; y++)
  {
    camera.waitForPixelClockRisingEdge();
    camera.readPixelByte(bufferedLowByte);

    for (uint16_t x = 0; x < lineLength - 1; x++)
    {
      chaine = "";
      camera.waitForPixelClockRisingEdge();
      uint8_t highByte;
      camera.readPixelByte(highByte);
      chaine += convertPixelByteH(highByte); // send pixel high byte

      lowByte = bufferedLowByte;

      camera.waitForPixelClockRisingEdge();
      camera.readPixelByte(bufferedLowByte);
      chaine += convertPixelByteL(lowByte); // send pixel low byte

      Serial.println(chaine);
    }

    // send last pixel
    camera.waitForPixelClockRisingEdge();
    uint8_t highByte;
    camera.readPixelByte(highByte);
    chaine += convertPixelByteL(highByte);        // send pixel high byte
    chaine += convertPixelByteH(bufferedLowByte); // send pixel low byte

    Serial.println(chaine);
  }

  Serial.println("End new Frame");
}

#endif
