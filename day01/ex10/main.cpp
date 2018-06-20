#include <iostream>
#include <fstream>

int		main(int ac, char **av) {
	if (ac == 1) {
		while (true) {
			std::string buffer;
			if (!(getline(std::cin, buffer))) {
				return (0);
			}
			std::cout << buffer << std::endl;
		}
	}
	else {
		for (int i = 1; i < ac; ++i) {
			std::string		content;
			std::ifstream	ifs(av[i]);
			if (ifs.good()) {
				while (ifs.eof() == false) {
					std::string buf;
					getline(ifs, buf);
					buf.push_back('\n');
					content += buf;
				}
				ifs.close();
				content = content.substr(0, content.size() - 1);
				std::cout << content;
			}
			else {
				std::cout << "cato9tails: " << av[i];
				std::cout << ": No such file or directory" << std::endl;
			}
		}
	}
	return (0);
}