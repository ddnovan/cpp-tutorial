#include <iostream>

int main()
{
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
}