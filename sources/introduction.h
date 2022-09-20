/**
 * @mainpage Information page
 * @section info_sec Info
 * 
 * "Kvadratka" is a variety of functions in C++ which can solve any quadratic equation and print roots in the terminal
 */

/**
 * @file introduction.h 
 * @brief File with introduction to "Kvadratka" program and coefficients input functions
 */

#ifndef SRC_INTRODUCTION_H_
#define SRC_INTRODUCTION_H_

/**
 * @brief Prints an introduction message to "Kvadratka" programm
 */
void introduction();

/**
 * @brief Checks if the input of the coefficients (a, b, c) is right
 * 
 * @param [out] a Coefficient a
 * @param [out] b Coefficient b
 * @param [out] c Coefficient c
 */
void coefficients_input(double* a, double* b, double* c);

#endif  // SRC_INTRODUCTION_H_
