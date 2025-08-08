#include <iostream>

int inputNumber() {

	std::cout << "Input an integer, we'll double it: ";

	int num{};
	std::cin >> num;
	return num;
}

// Write a function called doubleNumber() that takes one integer parameter. 
// The function should return double the value of the parameter.
int doubleNumber(int num) {
	
	return num*2;
}

int main()
{
	/*

	// Chapter 1.1
	std::cout << "Hello, world!" << std::endl;
	// Chapter 1.2: (Implícito con comentarios)
	// Chapter 1.3
	std::cout << 5 << std::endl;
	std::cout << -6.7 << std::endl;
	std::cout << 'H' << std::endl;
	std::cout << "Texto" << std::endl;
	// Chapter 1.4:
	int x{0};   // direct-list-initialization with initial value 0
	std::cout << x << std::endl; // we're using that 0 value here
    int y{};      // value initialization
	std::cin >> y; // we're immediately replacing that value so an explicit 0 would be meaningless
	std::cout << y << std::endl;
	return 0;
	// Chapter 1.5:
	// Value-initialization, valores ceros en x,y,z.
    int x{}, y{}, z{};
	std::cout << "Value-initialization, everything with value zero: " << "x: "
			  << x << ", y:" << y << ", z:" << z << '\n';
	// Comprobado el funcionamiento de std::cin y sus extracciones.
	std::cout << "Enter three numbers: ";
    std::cin >> x >> y >> z;
    std::cout << "You entered " << x << ", " << y << ", " << "and " << z << "." << '\n';

	// Chapter 1.11
	// Make a program that multiply by 2 and 3 the user input
	std::cout << "Enter an integer: ";
	int num {};
	std::cin >> num;
	std::cout << "Double " << num << " is: " << num * 2 << '\n';
	std::cout << "Triple " << num << " is: " << num * 3 << '\n';

	*/

	// Chapter 2.4
	// Write a complete program that reads an integer from the user,
	// doubles it using the doubleNumber() function you wrote in the previous quiz question,
	// and then prints the doubled value out to the console.
	int inputNum { inputNumber() };
	int doubleInputNum = { doubleNumber(inputNum) };
	std::cout << "Double the input number: " << doubleInputNum << '\n';

    return 0;
}