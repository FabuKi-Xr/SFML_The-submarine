#include "leaderboard.h"

leaderboard::leaderboard(int& state, sf::Event event)
{
	if (event.text.unicode < 128 and playerName.length() < 10 and event.text.unicode != 8 and event.text.unicode != 13)
	{
		playerName += event.text.unicode;
		name.setString(playerName);
	}
	else if (playerName.length() < 10 and playerName.length() > 0 and event.text.unicode == 8 and event.text.unicode != 13)
	{
		playerName.pop_back();
		name.setString(playerName);
	}
	else if (event.text.unicode == 13)
	{
		if (playerName != "")
		{
			std::ifstream f("leaderboard.txt");
			int i = 0;
			if (f)
			{
				while (!f.eof())
				{
					f >> allname[i];
					f >> allscore[i];
					i++;
				}
			}
			f.close();
			allname[5] = playerName;
			allscore[5] = playerScore;
			for (int i = 0; i < 6; i++)
			{
				std::cout << allname[i] << " :: " << allscore[i] << std::endl;
			}
			for (int z = 0; z < 5; z++)
			{
				for (int x = 0; x < 5 - z; x++)
				{
					if (allscore[x] < allscore[x + 1])
					{
						int temp = allscore[x];
						allscore[x] = allscore[x + 1];
						allscore[x + 1] = temp;
						std::string tempname = allname[x];
						allname[x] = allname[x + 1];
						allname[x + 1] = tempname;
					}
				}
			}
			std::ofstream ff("leaderboard.txt");
			if (ff)
			{
				for (int i = 0; i < 5; i++)
				{
					if (allscore[i] != 0)
						ff << allname[i] << " " << allscore[i] << "\n";
				}
			}
			ff.close();
			state = 0;
		}
	}
}

void leaderboard::addBG()
{
	if (!leaderboardTexture.loadFromFile("img/scoreboard.png"))
	{
		std::cout << "cant open scoreboard.png" << std::endl;
	}
	leaderboardTexture.setSmooth(true);
	leaderboardBG.setTexture(&leaderboardTexture);
	leaderboardBG.setSize(sf::Vector2f(1080.0f, 720.0f));
	leaderboardBG.setPosition(sf::Vector2f(0.0f, 0.0f));
}

void leaderboard::leaderboardUpdate(int &state)
{

	if (state == 5)
	{
		std::ifstream f("leaderboard.txt");
		std::string temp;
		int i = 0;
		if (f)
		{
			while (!f.eof())
			{
				temp.clear();
				str.clear();
				std::cout << i << std::endl;
				f >> temp;
				str.append(temp);
				std::cout << str.length() << std::endl;
				while (str.length() < 20)
				{
					str.append(" ");
				}
				f >> temp;
				str.append(temp);
				std::cout << str << std::endl;
				text[i].setString(str);
				/*text[i].setOrigin(0,text[i].getGlobalBounds().height/2);*/
				text[i].setPosition(320.0f, 86.0f* ((i +1)* 33.0f)); //?
				i++;
			}
		}f.close();
	}
}

void leaderboard::drawleaderboard(sf::RenderWindow& window,int state)
{
	if (state == 5)
	{
		window.draw(leaderboardBG);
		for (int i = 0; i < 5; i++)
		{
			window.draw(text[i]);
		}
	}
}
