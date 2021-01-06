
#include <stdio.h>
#include <math.h>
#include <time.h>
double testFun(double var)
{
    double c;
    c = var * 2.011;
    return c;
}
int main()
{
    double a = 1.0, b = 1.2, c, d, e, f, g, h;
    c = a * b;
    d = b = e = f = g = h = 1.1;
    d = b = e = f = g = h = a * b;
    e = a * (b + c + d);
    f = a + (b + c) + c * d * e;
    g = b + c / (d * e) + f;
    h = a + testFun(b) + c + d + e;
    g = a * b + c * d;
    g = h / a / b + h / (a / b);
    g = (a + b) * (c + d);
    g = (a + b) + (c + d);
    g = -4 + 3 * d * (c + b) - d * d * (c + b) * (c + b) + exp(-d * (c + b)) * (4 + d * (c + b));
    int i = 3;
    g = g * h * i;
    return 0;
}
