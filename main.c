#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  
  color c;
  c.red = 20;
  c.green = 45;
  c.blue = 187;
  
  clear_screen(s);

  struct matrix *points;
  struct matrix *edges;
  struct matrix *transform;
  printf("Creating points matrix...\n");
  points = new_matrix(4, 4);
  add_point(points, 100, 200, 300);
  add_point(points, 100, 200, 300);
  add_point(points, 100, 200, 300);
  add_point(points, 100, 200, 300);
  print_matrix(points);
  printf("\n");
  
  //
  struct matrix *point;
  point = new_matrix(4, 4);
  add_point(point, 100, 200, 300);
  add_point(point, 100, 200, 300);
  add_point(point, 100, 200, 300);
  add_point(point, 100, 200, 300);


  printf("Creating edges matrix...\n");
  edges = new_matrix(4, 8);
  add_edge(edges, 50, 100, 1, 50, 300, 1); //(x0, y0, z0) = (1, 2, 3), (x1, y1, z1) = (4, 5, 6)
  add_edge(edges, 50, 300, 1, 250, 300, 1);
  add_edge(edges, 250, 300, 1, 250, 100, 1);
  add_edge(edges, 250, 100, 1, 50, 100, 1); 
  print_matrix(edges);
  
  //draw_line(0, 0, 200, 200 , s, c);
  draw_lines(edges, s, c);
  //display(s);
  printf("\n");
  
  printf("printing points matrix post-scalar...\n");
  double d = 2.0;
  scalar_mult(d, edges);
  print_matrix(edges);
  printf("\n");
  
  //display(s);
  /*
  printf("printing points matrix post-ident...\n");
  ident(points);
  print_matrix(points);
  
  printf("\n");
  */
  printf("printing points matrix post-matrix_mult...\n");
  matrix_mult(points, point);
  print_matrix(point);

  transform = new_matrix(4, 4);
  
  
  free_matrix( transform );
  free_matrix( edges );
  
}  
