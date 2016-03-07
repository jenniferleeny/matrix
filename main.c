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
  /*  printf("Creating points matrix...\n");
  points = new_matrix(4, 4);
  add_point(points, 1, 2, 3);
  add_point(points, 1, 2, 3);
  add_point(points, 1, 2, 3);
  add_point(points, 1, 2, 3);
  print_matrix(points);
  printf("\n");
  */
  printf("Creating edges matrix...\n");
  edges = new_matrix(4, 4);
  add_edge(edges, 1, 50, 100, 34, 150, 160); //(x0, y0, z0) = (1, 2, 3), (x1, y1, z1) = (4, 5, 6)
  add_edge(edges, 40, 150, 160, 220, 310, 190);
  print_matrix(edges);
  
  //draw_line(0, 0, 200, 200 , s, c);
  draw_lines(edges, s, c);
  printf("\n");
  /*
  printf("printing points matrix post-scalar...\n");
  double d = 5.0;
  scalar_mult(d, points);
  print_matrix(points);
  printf("\n");
  
  printf("printing points matrix post-ident...\n");
  ident(points);
  print_matrix(points);
  
  printf("\n");
  
  printf("printing points matrix post-matrix_mult...\n");
  matrix_mult(points, edges);
  print_matrix(points);

  transform = new_matrix(4, 4);
  
  
  free_matrix( transform );
  free_matrix( edges );
  */
}  
