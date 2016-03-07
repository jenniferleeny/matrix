#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matrix.h"

/*-------------- struct matrix *new_matrix() --------------
Inputs:  int rows
         int cols 
Returns: 
Once allocated, access the matrix as follows:
m->m[r][c]=something;
if (m->lastcol)... 
*/
struct matrix *new_matrix(int rows, int cols) {
  double **tmp;
  int i;
  struct matrix *m;

  tmp = (double **)malloc(rows * sizeof(double *));
  for (i=0;i<rows;i++) {
    tmp[i]=(double *)malloc(cols * sizeof(double));
  }

  m=(struct matrix *)malloc(sizeof(struct matrix));
  m->m=tmp;
  m->rows = rows;
  m->cols = cols;
  m->lastcol = 0;

  return m;
}


/*-------------- void free_matrix() --------------
Inputs:  struct matrix *m 
Returns: 
1. free individual rows
2. free array holding row pointers
3. free actual matrix
*/
void free_matrix(struct matrix *m) {
  int i;
  for (i=0;i<m->rows;i++) {
    free(m->m[i]);
  }
  free(m->m);
  free(m);
}


/*======== void grow_matrix() ==========
Inputs:  struct matrix *m
         int newcols 
Returns: 
Reallocates the memory for m->m such that it now has
newcols number of collumns
====================*/
void grow_matrix(struct matrix *m, int newcols) {
  
  int i;
  for (i=0;i<m->rows;i++) {
    m->m[i] = realloc(m->m[i],newcols*sizeof(double));
  }
  m->cols = newcols;
}


/*-------------- void print_matrix() --------------
Inputs:  struct matrix *m 
Returns: 
print the matrix
*/
void print_matrix(struct matrix *m) {
  //int r = m->rows;
  //int c = m->cols;
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) 
      printf("%fl\t", m->m[i][j]);
    printf("\n");
  }
}

/*-------------- void ident() --------------
Inputs:  struct matrix *m <-- assumes m is a square matrix
Returns: 
turns m in to an identity matrix
*/
void ident(struct matrix *m) {
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      if (i == j)
	m->m[i][j] = 1;
      else
	m->m[i][j] = 0;
    }
  }
}

/*-------------- void scalar_mult() --------------
Inputs:  double x
         struct matrix *m 
Returns: 
multiply each element of m by x
*/
void scalar_mult(double x, struct matrix *m) {
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      m->m[i][j] = x*m->m[i][j];
    }
  }
}


/*-------------- void matrix_mult() --------------
Inputs:  struct matrix *a
         struct matrix *b 
Returns: 
a*b -> b
*/
void matrix_mult(struct matrix *a, struct matrix *b) {
  //goes across and down b matrix to refill it
  double sum = 0.0;
  struct matrix *c = new_matrix(a->rows, b->cols);
  if (a->cols != b->rows || a->rows != b->cols) 
    printf("MATRIC_MULT: A AND B DO NOT FULFILL THE REQUIREMENT FOR MULTIPLCATION.\n");
  else {
    for (int g = 0; g < c->rows; g++) {
      for (int h = 0; h < c->cols; h++) {
	//adds multiplied numbers to sum
	for (int i = 0; i < b->rows;i++) {
	  sum += b->m[i][h] * a->m[g][i];
	}
	c->m[g][h] = sum;
	printf("sum: %lf\n", sum);
	sum = 0;
      }
    }
    copy_matrix(c, b);
  }
}

/*-------------- void copy_matrix() --------------
Inputs:  struct matrix *a
         struct matrix *b 
Returns: 
copy matrix a to matrix b
*/
void copy_matrix(struct matrix *a, struct matrix *b) {
  
  int r, c;
  
  for (r=0; r < a->rows; r++) 
    for (c=0; c < a->cols; c++)  
      b->m[r][c] = a->m[r][c];  
}

/*======== struct matrix * make_translate() ==========
  Inputs:  int x
         int y
         int z 
	 Returns: The translation matrix created using x, y and z 
	 as the translation offsets.
	 ====================*/
struct matrix * make_translate(double x, double y, double z) {
  struct matrix *a = new_matrix(4, 4);
  for (int i = 0; i < a->row; i++) {
    for (int j = 0; j < a -> col; j++) {
      if (i == j)
	a->m[i][j] = 1;
      else
	a->m[i][j] = 0;
    }
  }
  a->m[0][3] = x;
  a->m[1][3] = y;
  a->m[2][3] = z;
}

/*======== struct matrix * make_scale() ==========
  Inputs:  int x
  int y
         int z 
	 Returns: The translation matrix creates using x, y and z
as the scale factors
====================*/
/*struct matrix * make_scale(double x, double y, double z) {
  }*/

/*======== struct matrix * make_rotX() ==========
Inputs:  double theta
Returns: The rotation matrix created using theta as the 
angle of rotation and X as the axis of rotation.
====================*/
/*
struct matrix * make_rotX(double theta) {
}
*/
/*======== struct matrix * make_rotY() ==========
Inputs:  double theta
Returns: The rotation matrix created using theta as the 
angle of rotation and Y as the axis of rotation.
====================*/
/*
struct matrix * make_rotY(double theta) {
}
*/
/*======== struct matrix * make_rotZ() ==========
Inputs:  double theta
Returns: The rotation matrix created using theta as the 
angle of rotation and Z as the axis of rotation.
====================*/
/*
struct matrix * make_rotZ(double theta) {
}
*/
