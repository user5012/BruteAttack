#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <cstdlib>

int main(int argc, char** argv) {
	std::string filename;
	std::cout << "File name: ";
	std::getline(std::cin ,filename);

	std::string dicname;
	std::cout << "DicName: ";
	std::getline(std::cin, dicname);

	std::ifstream dictionary(dicname);
	if (!dictionary.is_open()) {
		std::cerr << "Failed to open " << dicname << std::endl;
		std::cout << "Press Enter to continue...";
		std::cin.get();
		return -1;
	}
	int times = 0;
	std::string line;
	while (std::getline(dictionary, line)) {
		//std::cout << "testing pass: " << line << std::endl;
		
		std::string command = "\"\"C:\\Program Files\\7-Zip\\7z.exe\" t \"" + filename + "\" -p\"" + line + "\"\"";
		int result = system(command.c_str());
		if (result == 0) {
			std::cout << "pass found: " << line << " took: " << times << " to finish" << std::endl;
			break;
		}
		else
		{
			std::cout << "pass incorect: " << line << std::endl;
			times++;
		}
	}

	std::cout << "finished dictionary, ran all " << times << " possible passwords" << "\n";

	dictionary.close();

	std::cout << "Press Enter to continue...";
	std::cin.get();

	return 0;
}