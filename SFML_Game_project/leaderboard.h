#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
class leaderboard
{

public:
	leaderboard(int &state,sf::Event event);

	void addBG();
	void leaderboardUpdate(int& state);
	void drawleaderboard(sf::RenderWindow& window, int state);
	~leaderboard();

private :
	sf::Texture leaderboardTexture;
	sf::RectangleShape leaderboardBG;
	std::string playerName;
	int playerScore = 0;
	sf::Text name;
	std::string allname[6] = {};
	int allscore[6] = {};
	sf::Text text[6] = {};
	std::string str;
};

