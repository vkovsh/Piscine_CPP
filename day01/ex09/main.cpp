#include "Logger.hpp"

int	main(void) {
	Logger *logger = new Logger();
	std::string entry = "I am alive";
	logger->log("0", "I am alive!");
	logger->log("0", "Doing something.");
	logger->log("1", "I am alive!");
	logger->log("1", "Doing something.");
	logger->log("1", "Doing something...");
	delete logger;
	return (0);
}