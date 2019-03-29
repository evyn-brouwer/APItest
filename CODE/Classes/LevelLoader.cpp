#include "LevelLoader.h"

LevelLoader::LevelLoader(std::string path) {
	std::ifstream file;
	file.open(path);
	// This part loads our spreadsheet into a 2d array
	std::string line;

	while (std::getline(file, line)) {
		std::vector<std::string> row;
		std::stringstream iss(line);
		int c = 0;
		std::string val;

		while (std::getline(iss, val, ',')) {
			std::stringstream converter(val);
			std::string sval = converter.str();
			row.push_back(sval);
		}
		this->map.push_back(row);
	}
}

ChangeLevel::ChangeLevel()
{
}

void ChangeLevel::changeLevel(int level)
{
	using namespace std;

	ifstream in("curLevel.txt");
	ofstream out("newLevel.txt");

	string inNum;
	int levelNum;

	getline(in, inNum);

	levelNum = stoi(inNum);

	levelNum = level;

	out << levelNum;

	in.close();
	out.close();

	remove("curLevel.txt");
	rename("newLevel.txt", "curLevel.txt");
}

int ChangeLevel::getLevel()
{
	std::string inNum;
	int levelNum;

	std::ifstream in("curLevel.txt");

	std::getline(in, inNum);

	levelNum = stoi(inNum);

	in.close();
	return levelNum;
}
