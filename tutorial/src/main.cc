#include <iostream>

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

	*/
	// Chapter 1.5:
	
	// Value-initialization, valores ceros en x,y,z.
    int x{}, y{}, z{};
	std::cout << "Value-initialization, everything with value zero: " << "x: "
			  << x << ", y:" << y << ", z:" << z << '\n';
	// Comprobado el funcionamiento de std::cin y sus extracciones.
	std::cout << "Enter three numbers: ";
    std::cin >> x >> y >> z;
    std::cout << "You entered " << x << ", " << y << ", " << "and " << z << "." << '\n';

    return 0;
}