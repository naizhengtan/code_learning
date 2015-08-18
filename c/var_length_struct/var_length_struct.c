#include <stdio.h>
#include <stdlib.h>

struct A {
  int aaa;
  int a[]; //int* a;
};

struct A b = {1,{2,3,4,5}};

int main() {
  static struct A b = {1,{2,3,4,5}};
  struct A *a = malloc(sizeof(int) + 20*sizeof(int));
  a->a[10] = 100000;
  printf("%lu\n", sizeof(*a));
  printf("%d\n", a->a[10]);
  printf("%d\n", b.a[1]);
}
