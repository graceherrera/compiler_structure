#include <iostream>
#include <string>
#include "grammar/koreanGrammar.cpp"

using namespace std;

int main() {
	cout << "START" << endl;
	startParser();
	std::cout << "JAMO COUNT: ";
	std::cout << jamos.size() << std::endl;

	std::cout << "HANGUL COUNT: ";
	std::cout << compounds.size() << std::endl;

	//std::cout << compounds << std::endl;
	return 0;
}
