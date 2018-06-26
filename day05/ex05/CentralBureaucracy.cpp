#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy() {

}

CentralBureaucracy::~CentralBureaucracy() {}

OfficeBlock	*CentralBureaucracy::getBlock(int index) {
	return _blocks[index];
}