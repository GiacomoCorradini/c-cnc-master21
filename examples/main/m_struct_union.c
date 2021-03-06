#include "struct_union.h"

int main() {

  // alternative way to initialize a struct
  // point_t pt = {x:0, y:0, z:0};
  // point_t pt = {.x=0, .y=0, .z=0, {.x=1, .y=1, .z=1}};

  point_t pt;
  pt.x = 0;
  pt.y = 0;
  pt.z = 0;

  point_t *pt_ptr = &pt;
  pt_ptr->x = 10;
  pt.y = 20;

  print_point(pt_ptr);

  my_union another_pt;
  another_pt.x = 10;
  another_pt.y = 20;

  printf("Size of union: %lu\n", sizeof(another_pt));
  printf("Size of pt: %lu\n", sizeof(pt));

  printf("another_pt.x %f\n", another_pt.x);
  printf("another_pt.y %f\n", another_pt.y);

  data_t ary[ARY_LEN] = {10, 2};

  print_array(ary, ARY_LEN);

  return 0;
}