using namespace std;
#include <ArduinoSTL.h>
#include <cmath>
#include <complex>
#include "MPU9250.h"
#include "FFT.h"

#define num_samples 512 // must be power of 2: 2^x
const unsigned long period = 1000; // 1ms = 1kHz

//MPU9250 IMU(Wire,0x68); // an MPU9250 object with the MPU-9250 sensor on I2C bus 0 with address 0x68
int status;

// stack:
//Im_t X[num_samples] = {1,0,0,0};

// heap:
Im_t * X = malloc(num_samples * sizeof(Im_t));



void setup() {
  Serial.begin(115200);
  while(!Serial);
  pinMode(A1, INPUT);
  
//  Serial.println("begin");
//  status = IMU.begin();
//  if (status < 0) {
//    Serial.println("IMU initialization unsuccessful");
//    Serial.println("Check IMU wiring or try cycling power");
//    Serial.print("Status: ");
//    Serial.println(status);
//    while(1) {}
//  }
//  Serial.println("configuring sensor ...");
//  
//  IMU.setAccelRange(MPU9250::ACCEL_RANGE_8G);// setting the accelerometer full scale range to +/-8G 
  //IMU.setDlpfBandwidth(MPU9250::DLPF_BANDWIDTH_20HZ); // setting DLPF bandwidth to 20 Hz
  //IMU.setSrd(19); // setting SRD to 19 for a 50 Hz update rate
}

void loop() {
  // perform sampling of data
  unsigned long p = 0;
  uint16_t i = 0;
  while(i < num_samples){
    if((micros()-p) > period){
      p = micros();
      //IMU.readSensor();
      //X[i] = {float(IMU.getAccelX_mss()), 0};
      X[i] = {analogRead(A1), 0};
      i++;
    }
  }
  
  iFFT(X, num_samples); // this will overwrite X to save memory!!! I can only get away with this because I know I do not need time domain and freq. domain at the same time
  print_complex_array(X, num_samples);

}
