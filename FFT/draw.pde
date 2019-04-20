
class Plot {
  int x, y;  // top left corner of graph
  int dx,dy; // width and height
  int num_points;
  int strokeweight = 5;
  
  float h_div = 100;
  float v_div = 100;
  
  
  float vertical_scale = 10;
  
  Plot(int x, int y, int dx, int dy, int num_points){
    fill(0);
    stroke(1);
    strokeWeight(strokeweight);
    this.x  = x;
    this.y  = y;
    this.dx = dx;
    this.dy = dy;
    this.num_points = num_points;
    rect(x, y, dx, dy, 10);
    
  }
  
  void draw(float[] data, int num_points){
    // Draw area
    strokeWeight(strokeweight);
    fill(0);
    rect(x, y, dx, dy, 10);
    
    strokeWeight(1);
    stroke(255,255,255,50);
    line(x+strokeweight/2, y+dy/2, dx-   strokeweight/2, y+dy/2);
    
    // draw line
    strokeWeight(1);
    stroke(0,255,0);
    fill(0,255,0);
    
    int step_size = (dx-strokeweight) / num_points;
    for(int n = 0; n < (num_points-1); n++){
      
      line(x + strokeweight/2 + n*step_size,
          (y + dy/2) - (data[n] * vertical_scale),
           x + strokeweight/2 + step_size + n*step_size,
          (y + dy/2) - (data[n+1] * vertical_scale)
          );
    }
  }
};
