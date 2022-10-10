#include <stdio.h>
#include <math.h>
#define f1(x, y, z) (2 - y - z) / 4
#define f2(x, y, z) (-6 - x - 2 * z) / 5
#define f3(x, y, z) (-4 - x - 2 * y) / 3
#define accuracy (1 / pow(10, 10))
void main()
{
  float x0 = 0, y0 = 0, z0 = 0, x1, y1, z1, e1, e2, e3;
  int step = 1;
  printf("\nStep\tx\ty\tz\n");
  do
  {
    x1 = f1(x0, y0, z0);
    y1 = f2(x0, y0, z0);
    z1 = f3(x0, y0, z0);
    printf("%d\t%0.4f\t%0.4f\t%0.4f\n", step, x1, y1, z1);
    e1 = fabs(x0 - x1);
    e2 = fabs(y0 - y1);
    e3 = fabs(z0 - z1);
    step++;
    x0 = x1;
    y0 = y1;
    z0 = z1;
  } while (e1 > accuracy && e2 > accuracy && e3 > accuracy);
  printf("\nSolution: x1 = %0.3f, x2=%0.3f and x3 = %0.3f\n", x1, y1, z1);
}