#include <iostream>
#include <cstring>
#include <fstream>

int	main(int ac, char **av) {
	if (ac != 4 || !(strlen(av[1])) ||
		!(strlen(av[2])) || !(strlen(av[3]))) {
		std::cout << "Bad usage!" << std::endl;
		std::cout << "./replace <filename> <str1> <str2>";
		std::cout << std::endl;
		std::cout << "arguments cannot be empty";
		std::cout << std::endl;
	}
	else {
		std::string		filename = (std::string)av[1];
		std::string		str1 = (std::string)av[2];
		std::string		str2 = (std::string)av[3];
		std::ifstream	ifs(filename.c_str());
		std::string		content;
		std::string		sub = str1 + str2;
		std::string		paste = str2 + str1;
		
		if (ifs.good() == true) {
			while (ifs.eof() == false) {
				std::string buf;
				getline(ifs, buf);
				buf.push_back('\n');
				content += buf;
			}
			content = content.substr(0, content.size() - 1);
			ifs.close();
			size_t position = content.find(sub, 0);
			while (position != std::string::npos) {
				content.replace(position, sub.size(), paste);
				position = content.find(sub, position + 1);
			}
			std::locale	loc;
			std::string	replace_filename;
			for (size_t i = 0; i < filename.length(); ++i) {
				replace_filename.push_back(toupper(filename[i], loc));
			}
			replace_filename = replace_filename + ".replace";
			std::ofstream	ofs(replace_filename.c_str());
			ofs << content;
			ofs.close();
		}
		else {
			std::cout << "Open file error occured!" << std::endl;
		}
	}
	return (0);
}