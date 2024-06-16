/*
 * Author: Kaia Walker
 * Description: This is a calculator that can preform operations of ^ * / + and -
 * Does not follow any PEMDAS. Also prints a list of values previously calculated
 */

#include <iostream>
#include <string>
#include "calculator.hpp"

/*
 * Function: print_error
 * Description: Prints an error message explaining that the user supplied
 * 		an invalid arithmetic expression.
 */
void print_error() {
	std::cout << "That isn't a valid arithmetic expression." << std::endl;
}

/*
 * Function: prompt_for_arithmetic_expression
 * Description: Prompts the user for an arithmetic expression and returns
 * 		whatever text they supply, whether that text represents a valid
 * 		arithmetic expression or not (validity should be checked elsewhere;
 * 		checking validity is not this particular function's responsibility).
 * Returns: An entire line of text supplied by the user via the terminal when
 * 		prompted for an arithmetic expression
 */
std::string prompt_for_arithmetic_expression() {
	std::cout << "Enter a valid arithmetic expression: ";
	std::string user_input;
	std::getline(std::cin, user_input);
	return user_input;
}

/*
 * Function: prompt_for_retry
 * Description: Asks the user whether they'd like to enter another arithmetic
 * 		expression and returns their entire line-of-text response
 * Returns: An entire line of text supplied by the user via the terminal when
 * 		asked if they'd like to enter another arithmetic expression. If this
 * 		function returns the string "Y", then that means the user would like
 * 		to enter another arithmetic expression.
 */
std::string prompt_for_retry() {
	std::cout << "Would you like to enter another expression? Enter Y for "
		"yes: ";

	std::string user_input;
	std::getline(std::cin, user_input);
	return user_input;
}

/*
 * Function: print_history_header
 * Description: Prints the header that precedes the history of values to be
 * 		printed at the end of the program.
 */
void print_history_header() {
	std::cout << "History of computed values:" << std::endl;
}

/*
Function: print_history_array
Description: Loops through the elements in the array and prints them out with a space in 
between each value
*/
void print_history_array(double arr[], int size) {
	for (int j = 0; j < size; j++) {
		std::cout << arr[j] << " ";
	}
	std::cout << "\n" << std::endl;
}

int main() {
	double arr[100];
	int i = 0;
	std::string go_again;


	do {
		std::string expression = prompt_for_arithmetic_expression();

		// Check if expression is valid by using the is_valid_expression
		// function, to be defined in calculator.cpp
		if (is_valid_expression(expression)) {
			// Expression is valid. Compute its value by using the
			// compute_value function, to be defined in calculator.cpp.
			double value = compute_value(expression);

			// assigns solved value to arr and adds to i for next place of index to add
			arr[i] = value;
			i++;
			// Print value
			std::cout << value << std::endl;


			go_again = prompt_for_retry();
		} else {
			std::cout << "That isn't a valid arithmetic expression." <<
				std::endl;
			go_again = "Y";
		}
	} while(go_again == "Y");

	// Print history header
	std::cout << std::endl;
	print_history_header();
	print_history_array(arr, i);

}
