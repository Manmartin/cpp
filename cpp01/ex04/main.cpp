#include <iostream>
#include <string>
#include <fstream>


void    read_file(std::string file, std::string s1, std::string s2)
{
	std::ifstream   		ifs(file.c_str(), std::ios::in);
	std::string     		text;
	std::string     		aux;
	unsigned long		find_nb;

	if (ifs.fail()) {
		std::cout << "Wrong file" << std::endl;
			ifs.close();
		return;
	}
	std::ofstream			ofs(std::string(file + ".replace").c_str());
	while (!ifs.eof()) {
		getline(ifs, text);
		int last = 0;
		while ((find_nb = text.find(s1, last)) != std::string::npos) {
			aux = text.substr(find_nb + s1.size());
			text.erase(find_nb);
			text += s2 + aux;
			last = find_nb + s2.size();
		}
		ofs << text;
		if (!ifs.eof())
			ofs << "\n";
	}
	ofs.close();
	ifs.close();
}

int main(int argc, char *argv[]) {


	if (argc == 4) {
		if (!argv[2][0] || !argv[3][0]) {
			std::cout << "Strings can't be empty" << std::endl;
			return (0);
		}
		read_file(argv[1], argv[2], argv[3]);
	}
	else
		std::cout << "Wrong amount of arguments" << std::endl;
	return (0);
}
