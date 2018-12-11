//Luus–Jaakola

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define D 2

long double erro = 1.e-8;

double func(double x[D]);

int main()
{
    double x[D], x_new[D];

    double min[D] = {10.0, -10.0};
    double max[D] = {10.0, 10.0};

    int i, j, k, cont = 0;

    for (i = 0; i < D; i++)
        x[i] = min[i] + (max[i] - min[i]) * (rand() / (double)RAND_MAX);

    int n_int = 1000,
        n_ext = 30;

    double r = 1, R, e = 0.1;

    while ((cont < n_int * n_ext) && (fabs(func(x)) > erro))
    {
        for (i = 0; i < n_ext; i++)
        {
            for (j = 0; j < n_int; j++)
            {
                printf("\n      %d      %f      %f      %g", cont, x[0], x[1], func(x));
                cont++;

                for (k = 0; k < D; k++)
                {
                    R = (double)rand() / RAND_MAX - 0.5;
                    x_new[k] = x[k] + R * r;
                }
                if (func(x_new) < func(x))
                    for (k = 0; k < D; k++)
                        x[k] = x_new[k];

                if (fabs(func(x)) < e)
                {
                    j = n_int;
                    i = n_ext;
                }
            }
            r = (1 - e) * r;
        }
    }
}
double func(double x[D])
{
    double f;
    //f(x) = x²;
    //f=x[0]*x[0]+x[1]*x[1];

    //f(x,y) =(2x+y-5)² + (x - y -1 );
    f = (2 * x[0] + x[1] - 5) * (2 * x[0] + x[1] - 5) + (x[0] - x[1] - 1) * (x[0] - x[1] - 1);

    return f;
}
