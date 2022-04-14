#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]) {
	int num;
	std::string lineText; // Find out why I don't need to #include <string>

	std::cout << "Number of arguments: " << argc - 1 << std::endl;
	if (argc > 1) {
		std::cout << "Arguments: ";
		for (int i = 1; i < argc; i++) {
			// Start at 1 as argv[0] is the filename/Program name.
			std::cout << argv[i] << ", ";
		}
		std::cout << std::endl;
	}

	std::ifstream ReadTestFile("test.txt"); // Open test.txt for reading.

	std::cout << "File Contents: ";
	while(getline (ReadTestFile, lineText)) {
		std::cout << lineText << std::endl;
	}
	std::cout << std::endl;

	ReadTestFile.close();

	std::fstream WriteTestFile("test.txt"); // Open test.txt for writing.

	std::cout << "Enter Number: ";
	std::cin >> num;
	std::cout << "Updated file with: " << num;

	WriteTestFile << num;
	
	WriteTestFile.close();

	return 0;
}