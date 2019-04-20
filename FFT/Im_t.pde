
//#define polar

class Im_t {
  float r;
  float i;
  Im_t(){}

  Im_t(float a, float b){
    this.r = a;
    this.i = b;
  }

  float mag(){
    return sqrt( sq(this.r) + sq(this.i) );
  }

  float ang(){
    return atan( this.i / this.r );
  }
  
  Im_t add(Im_t a){
    return new Im_t(this.r+a.r, this.i+a.i);
  }

  Im_t sub(Im_t a){
    return new Im_t(this.r-a.r, this.i-a.i);
  }

  Im_t mult(Im_t a){
    return new Im_t(this.r*a.r-this.i*a.i, this.r*a.i+this.i*a.r);
  }

  Im_t div(Im_t a){
    float denom = a.mag();
    return new Im_t( (this.r*a.r + this.i*a.i)/denom , (this.i*a.r - this.r*a.i)/denom );
  }
};


// DFT has n^2 time complexity, pretty bad. Used as basis for
// wooly cooly pooly algorythm or whatever the hell it's called
// NOTE: this could probably be made way more efficent by implementing
// it using exponential notation due to the number of multiplies.
// arduino trig functions are notouriously slow even with FPU!

void DFT(float[] x, Im_t[] X, int N){
  for(int k = 0; k < N; k++){
    for (int n = 0; n < N; n++){
      X[k].r += x[n] * cos( TWO_PI * k * n / N);
      X[k].i += x[n] * sin( TWO_PI * k * n / N);
    }
  }
}
