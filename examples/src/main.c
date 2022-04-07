#include "inout_p.h"

int main(){

  int n = 10;
  
  // First example
  float *a;
  printf("A address is: %p\n", a);
  a = f1(n);
  array_print(a, n);
  printf("A address is: %p\n", a);

  free(a);
  
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  printf("\n\tAnother example \n\n");
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  
  // Second example
  float *b = NULL;
  f2(b, n);
  printf("B address is: %p\n", b);
  // array_print(b, n);

  free(b);
  
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  printf("\n\tAnother example \n\n");
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  // Third example
  float *c = NULL;
  f3(&c, n);
  printf("C address is: %p\n", c);
  array_print(c, n);

  free(c);

  return 0;
}

/*
void array_print(float *a, int n){
  printf("[");
  for(int i = 0; i < n; i++){
    printf(" %f ", a[i]);
  }
  printf("]\n");
}

float* f1(int n){
  float *a = malloc(n*sizeof(float));
  printf("f1(%i) - a address is: %p\n", n, a);
  for(int i = 0; i < n; i++){
    a[i] = i;
  }
  array_print(a, n);
  return a;
}

void f2(float *a, int n){
  a = malloc(n*sizeof(float));
  printf("f2(%i) - a address is: %p\n", n, a);
  for(int i = 0; i < n; i++){
    a[i] = i;
  }
  array_print(a, n);
}

void f3(float **a, int n){
  *a = malloc(n*sizeof(float));
  printf("f3(%i) - a address is: %p\n", n, *a);
  for(int i = 0; i < n; i++){
    (*a)[i] = i;
  }
}
*/