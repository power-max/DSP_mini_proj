
#include <cmath>
#include <complex>
#define PROFIT 0
typedef complex<float> Im_t;

// helper functions for FFT:
// returns log2(n) if the input is a power of 2, -1 otherwise
uint8_t lg(uint32_t N) {
  int s = 0;
  int p = 0;
  for(int i = 0; i < 32; i++){
    s += N&1;
    if(N & 1)
      p = i;
    N =  N >> 1; // right shift by 1, aka ( N *= 2).
  }
  if(s != 1)
    return -1; // N is not a power of 2
  else
    return p;
}


// reverses bits for up to 32 bit 
uint32_t bit_reverse(uint32_t i, uint8_t num) {
  uint32_t mask = 0x55555555; // 0101...
  i = ((i & mask) << 1) | ((i >> 1) & mask);
  mask = 0x33333333; // 0011...
  i = ((i & mask) << 2) | ((i >> 2) & mask);
  mask = 0x0f0f0f0f; // 00001111...
  i = ((i & mask) << 4) | ((i >> 4) & mask);
  mask = 0x00ff00ff; // 0000000011111111...
  i = ((i & mask) << 8) | ((i >> 8) & mask);
  // 00000000000000001111111111111111 no need for mask
  i = (i << 16) | (i >> 16);
  i >>= (32 - num);
  return i;
  // sauce: https://equilibriumofnothing.wordpress.com/2013/10/14/algorithm-iterative-fft/
}


// idderitive algorythm: less common? harder to
// implement but more easy-going on both memory
// and probably a bit faster
int8_t iFFT(Im_t * x, Im_t * X, uint32_t N){

  // step 0: check that input is an even power of 2
  const uint8_t P = lg(N); // number of total operations needed
  if( P < 0){return -1;}
  
  // step 1: bit reversal: copy real x into Im_t X
  for( int n = 0; n < N; n++) {
    X[n] = x[bit_reverse(n, P)];
  }

  // step 2: butterfly DFTs
  const complex<float> J(0, 1); 

  for (int s = 1; s <= P; ++s) { 
    int m  = 1 << s; // 2 power s 
    int m2 = m >> 1; // m2 = m/2 -1 
    Im_t w(1, 0);

    // principle root of nth complex root of unity.
    // Im_t wm = exp(J * (M_PI / m2)); // this does not work because STL is not properly supported by the AVR compiler, so had to do it manually. works by eulers method
    Im_t wm(cos(M_PI / m2), sin(M_PI / m2));
    
    for (int j = 0; j < m2; ++j) { 
      for (int k = j; k < N; k += m) {
        Im_t t = w * X[k + m2]; // t = twiddle factor
        Im_t u = X[k];
        X[k] = u + t; // similar calculating y[k] 
        X[k + m2] = u - t; // similar calculating y[k+n/2] 
      }
      w *= wm; 
    }
  }
  
  /* step 3: ???
   * sauce:
   * https://www.geeksforgeeks.org/iterative-fast-fourier-transformation-polynomial-multiplication/
   */
  
  // step 4: PROFIT
  return PROFIT;
}
