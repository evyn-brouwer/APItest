/*
Kristian Menes	100383679

Christian Mariani	100661661


Evyn Brouwer 100702629


Steph	100706123

Vincent 	100709888
*/
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