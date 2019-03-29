#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>
#include <stdio.h>

class LevelLoader {
public:
	//      y   x
	std::vector<std::vector<std::string>> map;
	LevelLoader(std::string path);
private:

};

class ChangeLevel {
public:
	ChangeLevel();
	void changeLevel(int level);
	int getLevel();
};