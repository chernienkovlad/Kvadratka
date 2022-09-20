#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "kvadratka.h"

int is_zero(double num)
{
    assert(isfinite(num));

    return fabs(num) < epsilon;
}

static double get_discriminant(double a, double b, double c)
{
    return ((b*b) - (4*a*c));
}

static enum Roots_count get_quadratic_eq_roots_count(double discriminant)
{
    enum Roots_count roots_count = ZERO;

    if (is_zero(discriminant))
    {
        roots_count = ONE;
    }
    else if (discriminant > 0)
    {
        roots_count = TWO;
    }

    return roots_count;
}

static enum Roots_count get_linear_eq_roots_count(double b, double c)
{
    enum Roots_count roots_count = ONE;

    if (is_zero(b) && is_zero(c))
    {
        roots_count = INFINITE_NUMBER;
    }
    else if (is_zero(b) && !is_zero(c))
    {
        roots_count = ZERO;
    }

    return roots_count;
}

enum Roots_count solve_quadratic_equation(double a, double b, double c, double* x_1, double* x_2)
{
    assert(x_1 != NULL);
    assert(x_2 != NULL);
    assert(x_1 != x_2);

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    *x_1 = NAN;
    *x_2 = NAN;

    enum Roots_count roots_count = ZERO;
    
    if (!is_zero(a))
    {
        double discriminant = get_discriminant(a, b, c);

        roots_count = get_quadratic_eq_roots_count(discriminant);

        if (roots_count == TWO)
        {
            double sqrt_discriminant = sqrt(discriminant);
            *x_1 = (-b + sqrt_discriminant) / (2 * a);
            *x_2 = (-b - sqrt_discriminant) / (2 * a);
        }
        else if (roots_count == ONE)
        {
            *x_1 = -b / (2 * a);
        }
    }
    else
    {
        roots_count = solve_linear_equation(b, c, x_1);
    }

    return roots_count;
}

enum Roots_count solve_linear_equation(double b, double c, double* root)
{
    assert(root != NULL);

    assert(isfinite(b));
    assert(isfinite(c));

    *root = NAN;

    enum Roots_count roots_count = get_linear_eq_roots_count(b, c);

    if (roots_count == ONE)
    {
        *root = (-c) / b;
    }

    return roots_count;
}

void print_roots(double x_1, double x_2, enum Roots_count roots_count)
{
    if (roots_count == ZERO)
    {
        printf("\n\nДанное уравнение не имеет корней.\n\n");
    }
    else if (roots_count == ONE)
    {
        assert(isfinite(x_1));
        printf("\n\nОдин корень: x = %lf\n\n", x_1);
    }
    else if (roots_count == TWO)
    {
        assert(isfinite(x_1));
        assert(isfinite(x_2));
        printf("\n\nДва корня: x_1 = %lf, x_2 = %lf\n\n", x_1, x_2);
    }
    else if (roots_count == INFINITE_NUMBER)
    {
        printf("\n\nДанное уравнение имеет бесконечно много корней.\n\n");
    }
    else
    {
        assert(0);
    }
}
