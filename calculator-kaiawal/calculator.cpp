#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
/*
 * THIS IS A HELPER FUNCTION. YOU AREN'T REQUIRED TO USE IT, AND YOU CAN
 * MODIFY IT IF YOU WANT, BUT I STRONGLY RECOMMEND THAT YOU USE IT AS-IS.
 * YOU MAY FIND IT VERY HELPFUL.
 * Function: is_number
 * Description: Determines whether a given string holds a valid numeric value
 * Returns: True if the given string holds a valid numeric value, or false
 * 		otherwise. If this function returns true, it's safe to use std::stod()
 * 		on the string to convert it to a number (double) afterwards. Otherwise,
 * 		the given string does not contain a valid numeric value, and attempting
 * 		to use std::stod() on the string may crash your program.
 */
bool is_number(std::string str) {
	// A valid number must contain at least one digit and at most one
	// decimal point
	int num_digits = 0;
	int num_points = 0;
	for (int i = 0; i < str.length(); i++) {
		bool is_point = str.at(i) == '.';
		// A negative sign is a dash at the beginning of the string
		bool is_negative_sign = str.at(i) == '-' && i == 0;
		bool is_number = str.at(i) >= '0' && str.at(i) <= '9';

		if (is_point) {
			// If the character is a decimal point, increment
			// the number of points found, and return false if
			// it's greater than 1
			num_points++;
			if (num_points > 1) {
				return false;
			}
		}
		if (is_number) {
			// If the character is a digit, increment the number of
			// digits found
			num_digits++;
		}

		// If the character isn't any of the three valid possibilities,
		// return false, immediately ending the function
		if (!is_point && !is_negative_sign && !is_number) {
			return false;
		}
	}

	// Return true only if at least one digit was found
	return num_digits > 0;
}


// TODO Write other functions as you see fit.


/*
 * THIS IS A REQUIRED FUNCTION. YOU MAY NOT ALTER ITS HEADER (NAME, PARAMETERS,
 * OR RETURN TYPE) IN ANY WAY.
 * Function: is_valid_expression
 * Description: Determines whether a given string holds a valid arithmetic
 * 		expression, as defined in the assignment document.
 * Parameters:
 * 		expression (std::string): A string holding the expression to be checked
 * 			for validity.
 * Returns: True if the given string holds a valid arithmetic expression, or
 * 		false otherwise.
 *
 * For example, is_valid_expression("1 + 3 * 4") should return true, but
 * is_valid_expression("1+3*4") should return false (notice the lack of spaces;
 * see the assignment document for an explanation of what constitutes a valid
 * arithmetic expression for this assignment).
 */
bool is_valid_expression(std::string expression) {
	
	// checks that beginning and end of expression are numbers
	if (!((expression.at(0) >= '0' && expression.at(0) <= '9') || expression.at(0) == '-')) {
		return false;
	} else if (!(expression.at(expression.length() - 1) >= '0' && expression.at(expression.length() - 1) <= '9')) {
		return false;
	} else if (expression.length() == 0) {
		return false;
	}
	
	std::string x;
	bool isnum = false;
	bool isoperator = false;

	// loop that expression is valid 
	while (expression.length() != 0) {
		
		// checks if there is a space in expression remaining
		if (expression.find(" ") != std::string::npos) {
			// if so sets x equal to it and erases up to and including that space found
			x = expression.substr(0, expression.find(" "));
			expression.erase(0, expression.find(" ") + 1);
			if (expression.find(" ") == 0) {
				return false;
			}

		} else {
			// for end cases, makes expression empty and the loop won't loop again
			x = expression;
			expression = "";
		}

		// this checks if x is a number, and if is_number says that it isn't a valid number, returns false
		if (((x.at(0) >= '0' && x.at(0) <= '9') || (x.at(0) == '-' && x.length() > 1)) && !(is_number(x))) {
			std::cout << "in first if" << std::endl;
			return false;

			// if the length of x is greater than one and it includes an operator, returns false
		} else if (x.length() > 1 && (x.find("^") != std::string::npos || x.find("*") != std::string::npos ||
		x.find("/") != std::string::npos || x.find("+") != std::string::npos)) {
			return false;

			// if x is not a number or a valid operator, returns false
		} else if (!(x == "^" || x == "*" || x == "/" || x == "+" || x == "-" || (x.at(0) >= '0' && x.at(0) <= '9'))) {
			return false;

			// if isnum is true, means last index was a number as well, so returns false
		} else if (is_number(x) && isnum) {
			return false;

			// if x is an operator and isoperator is true, meaning last index was also an 
			// operator, so returns false
		} else if ((x == "^" || x == "*" || x == "/" || x == "+" || x == "-" ) && isoperator) {
			return false;
		}
		
		// if number, makes isnum true and isoperator false so we know to check for that next iteration
		if (is_number(x)) {
			isnum = true;
			isoperator = false;
		} else {
			isoperator = true;
			isnum = false;
		}
	}
	return true;
}
/*
Function: isolate_num
Description: It takes the string entered and finds the next availiable value, while also deleting it from
expression.
Parameters: <string>& expression - the user inputed equation to solve
Returns: returns the isolated number found
*/
double isolate_num(std::string& expression) {
	std::string num;

	// if a space exists, num = the number from index 0 to index of space. 
	// erase values in expression
	if (expression.find(" ") != std::string::npos) {
		num = expression.substr(0, expression.find(" "));
		expression.erase(0, num.length() + 1);

		// last number case
	} else {
		num = expression;
	}
	// if this is a valid number, return num
	if (is_number(num)) {
		return std::stod(num);

		// otherwise return 0
	} else {
		return 0;
	}
}
/* 
Fucntion: isolate_operation
Description: this function takes in the expression and returns the char for the operation to be 
performed
Parameters: <string>& expression - the user inputed equation that's been modified
Returns: the isolated operation as a char
*/
char isolate_operation(std::string& expression) {

	// sets the first value to the char and erases the taken char and following space from expression
	char operation = expression[0];
	expression.erase(0, 2);
	return operation;
}


/*
 * THIS IS A REQUIRED FUNCTION. YOU MAY NOT ALTER ITS HEADER (NAME, PARAMETERS,
 * OR RETURN TYPE) IN ANY WAY.
 * Function: compute_value
 * Description: Computes and returns the value of the given arithmetic
 * 		expression. This function should ASSUME that the given string is indeed
 * 		a valid arithmetic expression. That is, your program should check whether
 * 		a string contains a valid arithmetic expression (e.g., using your
 * 		is_valid_expression function) BEFORE passing it into this function.
 * Parameters:
 * 		expression (std::string): A string holding the arithmetic expression
 * 			to be evaluated.
 * Returns (double): The value of the given arithmetic expression, computed
 * 		according to the rules described in the assignment document
 *
 * For example: compute_value("1 + 3 * 4") should return 16, assuming you don't
 * complete the order-of-operations extra credit.
 */
double compute_value(std::string expression) {

	double num1;
	double num2;
	char operation;
	double temp;

	// main bread and butter of program. Iterates through and solves the equation
	while (expression.find(" ") != std::string::npos) {

		// isolates each number and operator and deletes those from expression
		num1 = isolate_num(expression);
		operation = isolate_operation(expression);
		num2 = isolate_num(expression);

		// this sees what operation char has in its value and preforms the operation
		if (operation == '^') {
			temp = pow(num1, num2);
		} else if (operation == '*') {
			temp = num1 * num2;
		} else if (operation == '/') {
			temp = num1 / num2;
		} else if (operation == '+') {
			temp = num1 + num2;
		} else if (operation == '-') {
			temp = num1 - num2;
		} else {
			// if isolate_operation returned something else, end and return. This is 
			// normally the end of the function.
			return temp;
		}

		// adds temp variable to expression to continue the math for the next loop
		if (is_number(std::to_string(temp))) {
			expression = std::to_string(temp) + " " + expression;
		} 
	}

	return std::stod(expression);
}
