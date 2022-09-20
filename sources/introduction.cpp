#include <stdio.h>
#include <assert.h>
#include <math.h>

void introduction()
{
    printf("\nЗдравствуйте!\n");
    printf("Эта программа поможет вам в решении квадратного уравнения (уравнения вида ax^2 + bx + c = 0).\n\n");
}

static void skip_line()
{
    int symbol = 0;
    do {
       symbol = getchar();
    } while (symbol != '\n' && symbol != EOF);
}

void coefficients_input(double* a, double* b, double* c)
{
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    printf("Введите три коэффициента a, b и c через пробел: ");
    while (scanf("%lf %lf %lf", a, b, c) != 3)
    {
        skip_line();
        printf("Некорректный ввод!\n\n");
        printf("Введите три коэффициента a, b и c через пробел: ");
    }

    assert(isfinite(*a));
    assert(isfinite(*b));
    assert(isfinite(*c));
}
