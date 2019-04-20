# DSP_mini_proj: accelerometer aliasing on quadcopters

## Motivation:

Quadcopters suffer from many technical challenges resulting from the fact that they are not inherently stable flight platforms. They require the use of a flight controller in order to adjust the throttle of each thruster in real-time in order to stabilize the aircraft. In order for the feedback to work properly, it is critical that the accelerometer and gyroscope do not respond to vibrations caused by typical propellers, as these high frequency vibrations get mixed down to lower frequencies due to aliasing act to introduce feedback error. For this mini-project I would like to investigate how the MPU responds to undesired vibrations and frequencies.

## Procedure (tentative)

My project idea will be to write a bit of code that interfaces an IMU via a microcontroller for the purpose of polling it at a known rate fs and sending this data to a PC over a UART or serial connection. The PC will perform an FFT on the data in real time and display the frequency content in a GUI. This will allow me to investigate how vibrations from the quadcopter propeller (simulated via some form of a speaker or solonoid) result in aliased signals, and to what extent such problems occur. I am planning to use a Teensy 3.6 and arduino for the MCU. The Processing IDE provides plain simple interface to the serial port and I am sure I can find a java library for an FFT and DSP operations in general. Or in case not, I can use matlab assuming I can figure out how to interface the Serial ports and create a GUI that can display data.
