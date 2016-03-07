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
  /*
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
  */

  printf("Creating edges matrix...\n");
  edges = new_matrix(4, 8);
  add_edge(edges, 0, 0, 1, 0, 100, 1); //(x0, y0, z0) = (1, 2, 3), (x1, y1, z1) = (4, 5, 6)
  add_edge(edges, 0, 100, 1, 100, 100, 1);
  add_edge(edges, 100, 100, 1, 100, 0, 1);
  add_edge(edges, 100, 0, 1, 0, 0, 1); 
  print_matrix(edges);
  
  //draw_lines(edges, s, c);
  /*
  struct matrix *rotX_matrix = new_matrix(4, 4);
  copy_matrix(make_rotX(60.0), rotX_matrix);
  print_matrix(make_rotX(60.0));
  for (int i = 0; i < 6; i++) {
    matrix_mult(rotX_matrix, edges);
    print_matrix(edges);
    draw_lines(edges, s, c);
    }
  printf("printing points matrix post-scalar...\n");
  double d = 2.0;
  scalar_mult(d, edges);
  print_matrix(edges);
  draw_lines(edges, s, c);
  //display(s);
  printf("\n");
    printf("printing points matrix post-ident...\n");
  ident(points);
  print_matrix(points);
  
  printf("printing points matrix post-matrix_mult...\n");
  matrix_mult(points, point);
  print_matrix(point);

  printf("Printing transform matrix...\n");
  c.red = 220;
  c.green = 45;
  c.blue = 87;
  
  transform = new_matrix(4, 4);
  add_edge(transform, 150, 100, 1, 150, 300, 1);
  add_edge(transform, 150, 300, 1, 350, 300, 1);
  //print_matrix(transform);
  
  draw_lines(transform, s, c);
  
  display(s);
  */
  draw_lines(edges, s, c);
  
  print_matrix(make_translate(100, 100, 0));
  struct matrix *translater = new_matrix(4, 4);
  copy_matrix(make_translate(30, 30, 0), translater);
  for (int i = 0; i < 13; i++) {
    matrix_mult(translater, edges);
    print_matrix(edges);
    draw_lines(edges, s, c);
  }

  c.red = 30;
  c.green = 100;
  c.blue = 190;

  struct matrix *translater_2 = new_matrix(4, 4);
  copy_matrix(make_translate(-400, -350, 0), translater_2);
  matrix_mult(translater_2, edges);
  

  struct matrix *scaler = new_matrix(4, 4);
  copy_matrix(make_scale(1.5, 2, 0), scaler);
  
  matrix_mult(scaler, edges);
  draw_lines(edges, s, c);

  for (int i = 0; i < 8; i++) {
    matrix_mult(translater, edges);
    //print_matrix(edges);
    draw_lines(edges, s, c);
  }

  struct matrix *translater_3 = new_matrix(4, 4);
  copy_matrix(make_translate(-150, -300, 0), translater_3);
  matrix_mult(translater_3, edges);
  draw_lines(edges, s, c);
  for (int i = 0; i < 8; i++) {
    matrix_mult(translater, edges);
    draw_lines(edges, s, c);
  }
  
  c.red = 200;
  c.green = 190;
  c.blue = 59;
  matrix_mult(translater_3, edges);
  matrix_mult(scaler, edges);
  
  for (int i = 0; i < 7; i++) {
    matrix_mult(translater, edges);
    draw_lines(edges, s, c);
  }
  c.red = 150;
  c.green = 90;
  c.blue = 29;
  struct matrix *translater_4 = new_matrix(4, 4);
  copy_matrix(make_translate(-70, -50, 0), translater_4);

  matrix_mult(translater_4, edges);
  matrix_mult(scaler, edges);

  for (int i = 0; i < 5; i++) {
    matrix_mult(translater, edges);
    draw_lines(edges, s, c);
  }
  display(s);
  save_extension(s, "matrix.png");
  free_matrix( edges );
}  
