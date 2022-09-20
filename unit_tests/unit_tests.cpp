#include <stdio.h>
#include <math.h>

#include "../sources/kvadratka.h"

void tests_introduction()
{
    printf("-------------------------------------------\n");
    printf("        KVADRATKA MODULE UNIT TESTS        \n");
    printf("-------------------------------------------\n\n");
}

void solve_quadratic_eq_test(double a, double b, double c, double root_1, double root_2, enum Roots_count nRoots, int* test_number)
{
    double x_1 = NAN, x_2 = NAN;
    enum Roots_count roots_count = solve_quadratic_equation(a, b, c, &x_1, &x_2);

    printf("TEST %d: ", *test_number);
    (*test_number)++;

    if (roots_count != nRoots)
    {
        printf("FAILED (INVALID ROOTS COUNT VALUE)! ");
        printf("EXPECTED: %d; ", nRoots);
        printf("RECIEVED: %d\n", roots_count);
    }
    else if (roots_count == TWO && !is_zero(root_1 - x_1) && !is_zero(root_2 - x_2))
    {
        printf("FAILED (INVALID ROOTS VALUES)!  ");
        printf("EXPECTED: x_1 = %lf, x_2 = %lf; ", root_1, root_2);
        printf("RECIEVED: x_1 = %lf, x_2 = %lf\n", x_1, x_2);
    }
    else if ((roots_count == ONE || roots_count == TWO) && !is_zero(root_1 - x_1))
    {
        printf("FAILED (INVALID FIRST ROOT VALUE)! ");
        printf("EXPECTED: x_1 = %lf; ", root_1);
        printf("RECIEVED: x_1 = %lf\n", x_1);
    }
    else if (roots_count == TWO && !is_zero(root_2 - x_2))
    {
        printf("FAILED (INVALID SECOND ROOT VALUE)! ");
        printf("EXPECTED: x_2 = %lf; ", root_2);
        printf("RECIEVED: x_2 = %lf\n", x_2);
    }
    else
    {
        printf("PASSED\n");
    }
}
