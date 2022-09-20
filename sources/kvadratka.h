/**
 * @file kvadratka.h
 * @brief File with function which solve quadratic equation
 */

#ifndef SRC_KVADRATKA_H_
#define SRC_KVADRATKA_H_

//! Epsilon value
const double epsilon = 1e-7;

//! Number of roots
enum Roots_count
{
    ZERO = 0, ///< No roots
    ONE = 1, ///< One root
    TWO = 2, ///< Two roots
    INFINITE_NUMBER = 3 ///< Infinite number of roots
};

/**
 * @brief Checks if the variable type of "double" is equal to zero
 * 
 * @param [in] num Variable to check
 * 
 * @return 1 - if num is equal to zero, 0 - if it's not
 */
int is_zero(double num);

/**
 * @brief Solves quadratic equation (ax^2 + bx + c = 0)
 * 
 * @param [in] a Coefficient a
 * @param [in] b Coefficient b
 * @param [in] c Coefficient c
 * @param [out] x_1 Pointer to the first root
 * @param [out] x_2 Pointer to the second root
 * 
 * @return Number of roots
 * 
 * @note If the equation has only one root it will be placed at the address of x_1. If the equation has no roots or the number of roots is infinity nothing will be placed at the addresses of x_1 and x_2.
 */
enum Roots_count solve_quadratic_equation(double a, double b, double c, double* x_1, double* x_2);

/**
 * @brief Solves linear equation (bx + c = 0)
 * 
 * @param [in] b Coefficient b
 * @param [in] c Coefficient c
 * @param [out] Pointer to the root
 * 
 * @return Number of roots
 */
enum Roots_count solve_linear_equation(double b, double c, double* root);

/**
 * @brief Prints roots of quadratic equation to the console
 * 
 * @param [in] x_1 First root
 * @param [in] x_2 Second root
 * @param [in] roots_count Number of roots
 */
void print_roots(double x_1, double x_2, enum Roots_count roots_count);

#endif  // SRC_KVADRATKA_H_
