#include "Array.hpp"
#include <cstdlib>

int	main(void)
{
	unsigned int i = 9;
	Array<> intNum = Array<>(i);
	for (unsigned int j = 0; j < intNum.size(); ++j) {
		intNum[j] = j;
	}
	for (unsigned int j = 0; j < intNum.size(); ++j) {
		std::cout << intNum[j] << std::endl;
	}
	try {
		intNum[9] = 42;
	}
	catch (std::range_error e){
		std::cout << e.what() << std::endl;
	}
	Array<int> intNum2 = Array<int>(10);
	for (unsigned int j = 0; j < intNum2.size(); ++j) {
		intNum2[j] = j;
	}
	intNum = intNum2;
	for (unsigned int j = 0; j < intNum.size(); ++j) {
		std::cout << intNum[j] << std::endl;
	}
}