//CPC file parser
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	std::string line; //string variable

	std::vector<std::string> funcStart{ "{" };
	std::vector<std::string> funcEnd{ "}" };
	std::vector<std::string> keywords{ "void",};

	int lineNum = 0;
	int voidNum = 0;

	std::ifstream myfile("source/Serial.cpp"); //choose file to read from

	if (myfile.is_open()) //open file
	{
		while (myfile.good()) //if not corrupt 
		{
			getline(myfile, line); //read line 

			for (const auto& keyword: keywords)
			{
				auto pos = line.find(keyword);
				lineNum++;

				if (pos != string::npos) 
				{
					voidNum++;
					
				}
	
				std::cout << lineNum <<". "<< keyword << "[" << (pos == string::npos ? "not found" : line) << "]\n";
			}
			
		}
		myfile.close();
		std::cout << "Number of functions found: " << voidNum << endl;
	}
	else std::cout << "Unable to open file";

	system("pause");
	return 0;
}