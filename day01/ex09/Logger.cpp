#include "Logger.hpp"

std::string	Logger::_logTypeNames[2] = {"logToConsole", "logToFile"};

std::string	Logger::createTimestamp( void ) {
	std::time_t t = std::time(0);
	std::tm	*now = std::localtime(&t);
	std::ostringstream time_str; 
	time_str << "[" << 1900 + now->tm_year;
	if (now->tm_mon < 10)
		time_str << "0";
	time_str << now->tm_mon;
	if (now->tm_mday < 10)
		time_str << "0";
	time_str << now->tm_mday;
	time_str << "_";
	if (now->tm_hour < 10)
		time_str << "0";
	time_str << now->tm_hour;
	if (now->tm_min < 10)
		time_str << "0";
	time_str << now->tm_min;
	if (now->tm_sec < 10)
		time_str << "0";
	time_str << now->tm_sec << "] ";
	return (time_str.str());
}

Logger::Logger( std::string dst ): _dst(dst) {
	this->_log_streams[0] = &Logger::logToConsole;
	this->_log_streams[1] = &Logger::logToFile;
	std::ofstream	ofs(this->_dst.c_str());
	ofs << "Creation time: " << Logger::createTimestamp() << std::endl;
	ofs.close();
}

std::string	Logger::makeLogEntry(std::string const & message) {
	std::string	logEntry;
	logEntry = Logger::createTimestamp() + message;
	return (logEntry);
}

void		Logger::logToConsole(std::string const & logEntry) {
	std::cout << logEntry << std::endl;
}

void		Logger::logToFile(std::string const & logEntry) {
	std::ofstream out;
	out.open(this->_dst.c_str(), std::ios::app);
	out << logEntry << std::endl;
	out.close();
}

void		Logger::log(std::string const & dest, std::string const & message) {
	for (int i = 0; i < 2; ++i) {
		if (Logger::_logTypeNames[i] == dest) {
			(this->*_log_streams[i])(this->makeLogEntry(message));
			break ;
		}
	}
}
		
Logger::~Logger( void ) {}
