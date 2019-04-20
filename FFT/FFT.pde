
int numSamples = 100;

float[] x = new float[numSamples]; // stupid java syntax C++ -> x[1000], guess everything is dynamically allocated.
Im_t[]  X = new Im_t[numSamples];

void setup(){
  
  size(1280,1280);
  background(20);
  
  for(int i = 0; i < numSamples; i++){
    x[i] = sin(TWO_PI * i/10);
    X[i] = new Im_t(); // initialize values with 0's
  }
  
  Plot timeplot = new Plot(20, 20, 1000, 500, numSamples);
  timeplot.draw(x, numSamples);
  printArray(x, numSamples);
  DFT(x, X, numSamples);
  
  
  
  println("done");
}

void draw(){
  
  
  
}

void printArray(float[] a, int n){
  int i = 0;
  print('[');
  do{
    print(a[i]);
    print(", ");
    i++;
  }
  while(i < n-1);
  print(a[i]);
  println("]");
}
