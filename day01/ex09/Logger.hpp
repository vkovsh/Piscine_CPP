#ifndef LOGGER_H
# define LOGGER_H
# include <iostream>
# include <fstream>
# include <ctime>
#include <sstream>

class Logger	{
	typedef void (Logger::*log_func)(std::string const &);
	private:
		static std::string	_logTypeNames[2];
		log_func	_log_streams[2];
		std::string	_dst;

		static std::string	createTimestamp( void );
		void				logToConsole(std::string const & logEntry);
		void				logToFile(std::string const & logEntry);
		std::string			makeLogEntry(std::string const & message);

	public:
		void log(std::string const & dest, std::string const & message);
		
		Logger( std::string dst = "log" );
		~Logger( void );
};

#endif