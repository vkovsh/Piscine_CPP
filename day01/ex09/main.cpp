#include "Logger.hpp"

int	main(void) {
	Logger *logger = new Logger("Logfile.txt");
	std::string entry = "I am alive";
	logger->log("logToConsole", "I am alive!");
	logger->log("logToConsole", "Doing something.");
	logger->log("logToFile", "I am alive!");
	logger->log("logToFile", "Doing something.");
	logger->log("logToFile", "Doing something...");
	delete logger;
	return (0);
}