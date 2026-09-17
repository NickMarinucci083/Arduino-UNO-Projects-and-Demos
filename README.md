# Arduino UNO Projects

A collection of Arduino UNO sketches covering the basics and a bunch of useful little hardware experiments. There is a mix of simple LED/button exercises, sensors, motors and servos, LCD/OLED/TFT displays, NeoPixels, serial communication, and a few projects that combine several of those ideas.

Most folders are standalone sketches, so you can open one, wire up the hardware it expects, and upload it to an Arduino UNO. The code is intentionally fairly direct and beginner-friendly rather than being turned into one big reusable framework.

## Projects

| Project | What it does |
|---|---|
| `7_Segment_display_control_Sketch` | Drives a single 7-segment display and cycles through 0–9. |
| `Analog_Joystick_Demo` | Reads joystick X/Y position and its push button, then reports direction over Serial. |
| `Animating_Images_on_16x2_LCD` | Uses custom LCD characters to make a small animation controlled by an analog input. |
| `Animating_Images_on_16x2_LCD_version_2` | Another 16x2 LCD custom-character animation experiment. |
| `Arduino_Battery_tester_using_ADC` | Reads a battery through the ADC and displays the measured voltage on an SH1106 OLED. |
| `Arduino_Voltmeter_Using_ADC` | Reads four analog inputs and shows their voltage readings on an OLED. |
| `Automatic_light_sensor_switch_with_ultrasonic_sensor` | Uses an HC-SR04 distance sensor to switch an active-low relay. |
| `Breathing_LED_Sketch` | Fades an LED up and down using PWM. |
| `Button_Debouncer_and_toggler` | Debounces two buttons and uses them to toggle two LEDs. |
| `Combined_LED_experimiment_Sketch` | Combines three buttons, three LEDs, and a buzzer into a simple control experiment. |
| `Control_Active_Buzzer_Sketch` | Turns an active buzzer on and off in a repeating pattern. |
| `Control_LED_via_Tiltswitch_Sketch` | Uses a tilt switch to control an LED. |
| `Control_Servo_With_2_Buttons` | Moves a servo using two debounced buttons. |
| `Controlling_2_Servos_Sketch` | Basic control of two servos. |
| `Controlling_Continous_and_positional_servos` | Demonstrates the difference between positional and continuous-rotation servos. |
| `Controlling_RGB_LED_Sketch` | Controls the red, green, and blue channels of an RGB LED with PWM. |
| `Controlling_Relay_Breakout_Sketch` | Basic on/off control of a relay breakout. |
| `Controlling_Servo_No_Libraries` | Generates the servo control signal manually without using `Servo.h`. |
| `Controlling_Servo_With_Rotary_encoder` | Uses a rotary encoder to set a servo position. |
| `Controlling_Servo_With_Rotary_encoder_WITH_LCD` | Same basic idea as above, with the selected servo position shown on a 16x2 LCD. |
| `Controlling_Servo_with_Infared_Sensor` | Uses an infrared/light sensor reading to control a servo. |
| `Controlling_Servo_with_ultrasonic_sensor_Sketch` | Maps ultrasonic distance to servo position. |
| `Controlling_a_4x8_LED_Matrix` | Controls a small 4x8 LED matrix by switching individual LEDs. |
| `Controlling_a_Servo_Motor_Sketch` | Simple `Servo.h` example that moves a servo through positions. |
| `Controlling_a_continous_servo` | Basic continuous-rotation servo control. |
| `Custom_Characters_on_16x2_LCD` | Creates and displays custom characters on a character LCD. |
| `DC_Motor_Control_With_L9110S_IC_Sketch` | Controls a DC motor through an L9110S motor driver. |
| `Debouncing_2_Buttons_LED_Control` | Uses `ezButton` to debounce two buttons and control LEDs. |
| `Displaying_info_on_OLED` | Basic SH1106 OLED text/information display experiment. |
| `Door_Alarm_using_Ultrasonic_Sensor` | Uses ultrasonic distance to trigger an alarm with a buzzer. |
| `EPK4131_Digpot_Control` | Communicates with an EPK4131 digital potentiometer over SPI. |
| `Electronic_Arduino_Dice` | Electronic dice using LEDs, a button, and pseudo-random selection. |
| `Fan_Speed_Conrol_With_Rotary_Encoder_and_LCD` | Adjusts fan speed with a rotary encoder and shows the setting on an LCD. |
| `Fonts_on_OLED_display_demo` | Cycles through different Adafruit GFX fonts on an SH1106 OLED. |
| `Image_Animation_on_OLED` | Displays animated bitmap-style images on an OLED. |
| `Infared_light_sensor_test_sketch` | Reads an infrared/light sensor through an analog input and prints the result. |
| `LCD_Control_Sketch` | Basic control and timing experiment using a 16x2 LCD. |
| `LCD_Functions_Arduino` | Small demonstration of common `LiquidCrystal` functions. |
| `LED_Blinker_Sketch` | The classic blinking LED example, with Serial output. |
| `LED_Brightness_Control_via_POT_Sketch` | Uses a potentiometer to control LED brightness with PWM. |
| `LED_Button_Control_Sketch` | Turns an LED on/off based on a push button. |
| `LED_Flowing_Lights_Sketch` | Creates a flowing/chasing LED effect. |
| `NeoPixel_16x16_Grid_Demo` | Drives a 16x16 NeoPixel grid and demonstrates gradients/color calculations. |
| `NeoPixel_1x8_LED_Strip_demo` | Basic effects and random colors on an 8-pixel NeoPixel strip. |
| `OLED_SH1106_Catch_Game` | A small catch-style game using an SH1106 OLED, buttons/sensors, and sound. |
| `OLED_SH1106_Catch_Game_Improved_Graphics` | Updated version of the OLED catch game with improved graphics and startup sound. |
| `OLED_SH1106_Custom_Images_Gallery` | Displays a gallery of custom bitmap images on an SH1106 OLED. |
| `OLED_SH1106_Functions_I2C_Arduino` | General SH1106/I2C graphics and function demonstrations. |
| `OLED_Typing` | Simple text/typing-style OLED experiment using Serial input. |
| `Photoresistor_result_on_LCD_Sketch` | Reads a photoresistor and displays its analog result on a 16x2 LCD. |
| `Pixel_art_with_OLED_screen` | Turns an SH1106 OLED into a tiny pixel-art drawing tool. |
| `Reading_Internal_CPU_temp_of_ATMEGA328P` | Reads the ATmega328P's internal temperature sensor and displays the result. |
| `Reversing_Radar_Sketch` | Uses an ultrasonic sensor, motor/servo-style control, and buzzer behavior to make a reversing-radar experiment. |
| `Rotary_Encoder_Interpretation_Sketch` | Reads a rotary encoder and reports its direction/value over Serial. |
| `School_Digitech_CAT_Water_Pump_Controller` | Combines an OLED, analog sensing, buttons, and a pump output into a larger controller project. |
| `Serial_Communication_Sketch` | Basic Serial communication and LED control experiment. |
| `Serial_Monitor_Password_Controlling_relay` | Accepts a password through the Serial Monitor before controlling a relay. |
| `Stick_Figure_walking_across_16x2_LCD` | Animates a stick figure walking across a 16x2 character LCD. |
| `TFT_Bitmap_Display_Demo` | Displays bitmap graphics on a parallel MCUFRIEND TFT. |
| `TFT_Clock_without_RTC_module` | Touchscreen TFT clock/calendar-style project that keeps time in software rather than using a dedicated RTC module. |
| `TFT_Color_Drawing` | Touchscreen drawing interface with colors, menus, borders, and reset/clear controls. |
| `TFT_Display_demo` | Demonstrates TFT colors, shapes, lines, pixels, text, and inversion. |
| `TFT_Random_Color_Generator` | Fills a TFT with randomly generated RGB565 colors. |
| `TFT_Text_Fonts_Demo` | Demonstrates multiple Adafruit GFX fonts on the TFT. |
| `TFT_Touchscreen_Demo` | Reads touchscreen coordinates and displays the results. |
| `Temprature_Alarm_Sketch` | Calculates thermistor temperature and activates an LED/buzzer above a threshold. |
| `Thermistor_result_on_LCD_Sketch` | Calculates thermistor temperature and displays it on a 16x2 LCD. |
| `Ultrasonic_Fan_Sketch` | Maps ultrasonic distance to PWM fan speed. |
| `Ultrasonic_distance_Sensor_Interpretation_Sketch` | Measures HC-SR04 distance and displays centimeters/meters on an LCD. |

## Hardware / libraries

These sketches are mainly written for an **Arduino UNO / ATmega328P**. A few projects need external hardware and libraries, so check the sketch before wiring everything up.

Common parts used across the collection include:

- Arduino UNO
- LEDs and resistors
- Push buttons and tilt switch
- Potentiometer
- Photoresistor / LDR
- Thermistor
- HC-SR04 ultrasonic sensor
- Active buzzer
- Relay module
- DC motor + L9110S driver
- Positional and continuous-rotation servos
- Rotary encoder
- 16x2 character LCD
- SH1106 OLED
- MCUFRIEND parallel TFT touchscreen
- WS2812/NeoPixel LEDs
- EPK4131 digital potentiometer

Common libraries:

- `LiquidCrystal`
- `Servo`
- `ezButton`
- `Wire`
- `Adafruit_GFX`
- `Adafruit_SH110X`
- `Adafruit_SSD1306`
- `Adafruit_NeoPixel`
- `MCUFRIEND_kbv`
- `TouchScreen`
- `SPI`

Most of these can be installed through **Arduino IDE → Library Manager**.

## Getting started

1. Open the project folder you want to try.
2. Open the `.ino` file in Arduino IDE.
3. Select **Arduino Uno** under **Tools → Board**.
4. Connect the hardware described by the sketch comments/constants.
5. Select the correct serial port.
6. Compile and upload.
7. If the project uses Serial, open the Serial Monitor at the baud rate used by that sketch.

A lot of the older sketches contain wiring comments directly in the source, so those are worth checking before connecting anything.

## Quick hardware notes

### 16x2 LCD

Several LCD projects use `LiquidCrystal`. A common arrangement in this collection is:

- RS → 10
- EN → 11
- Data pins → 0–7

Other LCD sketches use pins 2–7 for RS/EN/data, so **always check the specific sketch** before wiring it.

### Ultrasonic sensors

Several projects use an HC-SR04. Typical sketches use:

- Trigger → 6 or 9
- Echo → 5 or 8

The code normally sends a trigger pulse and measures the echo using `pulseIn()`. Distance is then calculated from the pulse width.

### Servos

Servo projects use `Servo.h` unless the folder specifically says **No Libraries**. Continuous-rotation servos are controlled differently from normal positional servos: the command generally represents speed/direction rather than an angle.

### OLEDs

The SH1106 projects normally use an I2C OLED at address `0x3C` with `Adafruit_GFX` and `Adafruit_SH110X`. The display size used in most of these projects is 128×64.

The battery tester and some other display projects use an `Adafruit_SH1106G` object, while the larger water-pump project uses `Adafruit_SSD1306`.

### TFT touchscreen

The TFT projects use `MCUFRIEND_kbv`, with `TouchScreen` added for touchscreen sketches. The touch calibration values are part of the code, so a different shield may need different values.

### NeoPixels

The NeoPixel projects use `Adafruit_NeoPixel`. These LEDs are digitally controlled, so the data pin and strip/grid wiring need to match the sketch.

## A few useful concepts shown in the collection

### ADC readings

The UNO's normal analog inputs produce values from **0–1023**. A number of these projects turn that raw reading into a voltage, percentage, brightness value, temperature, or other useful measurement.

Some of the voltage/battery sketches take multiple ADC samples and average them. This is a simple way of making the displayed value less jumpy.

### PWM

Projects such as the breathing LED, RGB LED, DC motor, and fan controller use PWM through `analogWrite()`. The usual UNO PWM range is 0–255:

- `0` → off
- `255` → full output
- values between them → intermediate duty cycle

### Buttons and debouncing

A physical button can rapidly switch between HIGH and LOW for a few milliseconds when pressed. The `Button_Debouncer_and_toggler` and `Debouncing_2_Buttons_LED_Control` projects demonstrate using `ezButton` to handle this cleanly.

### Servo control

There are examples ranging from very simple `Servo.h` usage to controlling a servo from an encoder, buttons, infrared/light input, or ultrasonic distance. The no-library example is useful if you want to see what the library is doing at a lower level.

### Custom LCD characters

The 16x2 LCD only has a small built-in character set, but `LiquidCrystal` lets you define custom 5×8 characters. The animation and stick-figure projects build on that idea to create simple graphics.

### OLED graphics

The OLED projects go beyond text and demonstrate pixels, shapes, bitmaps, fonts, animation, games, and a small drawing program. They are a good progression from basic display output to simple graphics programming.

### TFT graphics and touch

The TFT examples show a much larger color display, including RGB565 colors, bitmap images, fonts, drawing primitives, random colors, and touchscreen input.

## Project groups

If you are working through these as a learning collection, this is a useful order to think about them:

1. **Basic outputs** — `LED_Blinker_Sketch`, `Control_Active_Buzzer_Sketch`, `LED_Button_Control_Sketch`
2. **Inputs** — `Analog_Joystick_Demo`, `Control_LED_via_Tiltswitch_Sketch`, `Infared_light_sensor_test_sketch`
3. **PWM** — `Breathing_LED_Sketch`, `LED_Brightness_Control_via_POT_Sketch`, `Controlling_RGB_LED_Sketch`
4. **Buttons** — `Button_Debouncer_and_toggler`, `Debouncing_2_Buttons_LED_Control`
5. **LCDs** — `LCD_Control_Sketch`, `Custom_Characters_on_16x2_LCD`, `Stick_Figure_walking_across_16x2_LCD`
6. **Motors and servos** — the `Controlling_*Servo*` and `DC_Motor_Control_With_L9110S_IC_Sketch` projects
7. **Sensors** — thermistor, photoresistor, ultrasonic, infrared, and internal-temperature examples
8. **OLED graphics** — `Displaying_info_on_OLED`, fonts, images, animation, and `Pixel_art_with_OLED_screen`
9. **NeoPixels** — the 1x8 strip and 16x16 grid projects
10. **TFT graphics** — display, bitmap, fonts, colors, and random-color demos
11. **Touchscreen** — `TFT_Touchscreen_Demo` and `TFT_Color_Drawing`
12. **Larger projects** — the OLED catch games, radar, pump controller, and TFT clock

## Troubleshooting

**Nothing appears on the LCD**
- Check the LCD contrast potentiometer.
- Confirm the RS/EN/data pins match the sketch.
- Make sure the LCD has the correct 5 V/GND connections.

**OLED says it cannot be found**
- Check SDA/SCL.
- Check the I2C address (`0x3C` is common in these sketches).
- Make sure the correct Adafruit display library is installed.

**TFT is blank or colors look wrong**
- Make sure the shield is actually compatible with `MCUFRIEND_kbv`.
- The display ID is read by the sketch, so make sure the shield is seated properly.
- Touch calibration values may need changing for another screen.

**Servo moves strangely**
- Servos can draw much more current than the UNO should supply directly.
- Try a suitable external 5 V supply and connect the grounds together.
- Check whether the sketch is written for a positional or continuous-rotation servo.

**Ultrasonic readings jump around**
- Make sure the sensor has a stable power supply.
- Give the sensor enough time between measurements.
- `pulseIn()` waits for the echo pulse, so the surrounding timing of the sketch matters too.

**NeoPixels behave randomly**
- Check the data direction and exact data pin.
- Make sure the strip/grid and UNO share ground.
- A separate power supply may be needed for larger numbers of LEDs.

**Serial output looks wrong**
- Set the Serial Monitor to the baud rate in the sketch. Some projects deliberately use unusually high speeds.

## Folder structure

```text
UNO/
├── 7_Segment_display_control_Sketch/
├── Analog_Joystick_Demo/
├── ...
├── TFT_Touchscreen_Demo/
├── Temprature_Alarm_Sketch/
├── Thermistor_result_on_LCD_Sketch/
├── Ultrasonic_Fan_Sketch/
└── Ultrasonic_distance_Sensor_Interpretation_Sketch/
```

Each project normally contains its own `.ino` file. There is also a nested duplicate `TFT_Color_Drawing/TFT_Color_Drawing/` path in the batch; both copies are the same kind of touchscreen drawing sketch.

## Notes

- These are small experiments, so some sketches intentionally favor simplicity over perfect structure or production-level error handling.
- Pin assignments are **project-specific**. Don't assume two sketches using the same type of hardware use the same pins.
- Some calculations assume a 5 V UNO ADC reference and specific component values. Changing the circuit can change the result.
- Motor, relay, fan, servo, and NeoPixel projects may need an external power supply. Don't try to power everything from the UNO's 5 V pin.
- The thermistor examples use the component values defined in the code, including a 10 K nominal resistance and a beta value of 3977.
- The battery tester uses a resistor-divider style measurement, so the divider and battery voltage limits should be checked before connecting an unknown battery.
- Some folder and variable names contain typos such as `Temprature` and `Continous`. They have been left as-is so the README matches the actual folders.

## License

No explicit license file was included with this batch. If these sketches are going onto a public repository and you want other people to reuse them, adding a license file is a good idea.
