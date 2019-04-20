import serial
import numpy as np
import matplotlib.pyplot as plt
import time
import random
import datetime as dt
import matplotlib.animation as animation


S = serial.Serial('/dev/ttyACM0', 115200)  # open serial port

num_bins = 512 # limited memory on ATmega2560
freq = 1000 # Hz, based on sampling rate,


# Create figure for plotting
fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)
fft_result = []
for i in range(num_bins):
    fft_result.append(0)

xs = []
for i in range(num_bins):
    xs.append(freq * float(i)/num_bins) # frequency

print xs


# This function is called periodically from FuncAnimation
def animate(i, xs, fft_result):
    length = 0
    while(True):

        fft_result = S.readline().split(',')    # read line (everything up to \n) and convert to array
        fft_result = fft_result[:-1]            # the last element in the array is a newline and carrage return. Must be removed.

        if( len(fft_result) == num_bins):
            S.reset_input_buffer()               # clear input
            for i in range(num_bins):
                fft_result[i] = abs(complex(fft_result[i]))
            print "fft result: \n:" , fft_result
            break;


    # Draw x and y lists
    ax.clear()
    ax.plot(xs, fft_result)

    # Format plot
    plt.axis([0, freq, 0, 10000])
    # plt.xticks(rotation=45, ha='right')
    # plt.subplots_adjust(bottom=0.30)
    plt.title('title')
    plt.ylabel('y label')

# Set up plot to call animate() function periodically
ani = animation.FuncAnimation(fig, animate, fargs=(xs, fft_result), interval=1000)
plt.show()
