#include <math.h>

#include "sources/introduction.h"
#include "sources/kvadratka.h"
#include "unit_tests/unit_tests.h"

int main()
{
    #ifdef MAIN

        introduction();

        double a = NAN, b = NAN, c = NAN;
        coefficients_input(&a, &b, &c);

        double x_1 = NAN, x_2 = NAN;
        enum Roots_count roots_count = solve_quadratic_equation(a, b, c, &x_1, &x_2);

        print_roots(x_1, x_2, roots_count);

    #endif

    #ifdef TESTS

        tests_introduction();

        int test_number = 1;
        solve_quadratic_eq_test(1, 2, 1, -1, NAN, ONE, &test_number);
        solve_quadratic_eq_test(0, 0, 1, NAN, NAN, ZERO, &test_number);
        solve_quadratic_eq_test(1, 2, 1, -1, NAN, ONE, &test_number);
        solve_quadratic_eq_test(-1, 0, 0, 0, NAN, ONE, &test_number);

    #endif

    return 0;
}
