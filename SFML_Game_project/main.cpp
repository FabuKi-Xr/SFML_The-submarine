#include <stdio.h>
#include "game.h"
#include <conio.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include "Menu.h"
#include "Menugame.h"
#include "HP.h"
#include "bullet.h"
#include <stack>
#include "hostile.h"
#include "Collider.h"
#include "obstruct.h"
//--------------------------------------------------->>> initial <<<---------------------------------------------------------------------------------//
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int main() 
	{
	srand(time(NULL));
	int oceanx = 0;
	sf::Clock cl;

	/////////////////////// time for bullet player  ////////////////////////

	float bull = 0.0f;
	sf::Clock bullet_time;
	float deltaTime = 0.0f;

	/////////////////////// time for obstruct  /////////////////////////////

	sf::Clock obstruct_time;
	float obs = 0.0f;

	//////////////////////  time for hostile  ///////////////////////////////

	sf::Clock hostile_time; //ถ้า สมุนถูกกำจัดหมดเเล้วให้ boss เข้า
	float boss;
	sf::Clock bossBullet_time;
	float bull_boss;

	//////////////////////  time for obstacle  ////////////////////////////////
	float obstacle_time;
	sf::Clock obstacle_cl;
	Menugame menu(1080.0f,720.0f);

	/// mouse location ///

	sf::CircleShape mousePosition;
	mousePosition.setOutlineThickness(1.0f);
	mousePosition.setFillColor(sf::Color::Transparent);
	mousePosition.setOutlineColor(sf::Color::Transparent);
	mousePosition.setRadius(10.0f);
	mousePosition.setOrigin(5.0f,5.0f);
	
	int score = 0;
	//////////////////////////////////////////////////////  render window game  ///////////////////////////////////////////////////////////////////////////

	sf::RenderWindow window(sf::VideoMode(1080, 720), "The marine", sf::Style::Default );

	mousePosition.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));

	enum valueState { menustate=0 ,selectStage };

	int gameState = 0;
	//////////////////////////////////////////////////////////////////  Collider  ///////////////////////////////////////////////////////////////////////
	
	Collider collide;

	////////////////////////////////////////////////////////////  background  ////////////////////////////////////////////////////////////////////////////
	sf::Texture oceanTexture;
	if (!oceanTexture.loadFromFile("img/ocean_new.jpg")) {
		printf("loading failure");
	}
	sf::Sprite ocean1;
	sf::Sprite ocean2;
	ocean1.setTexture(oceanTexture);
	ocean1.setTextureRect(sf::IntRect(0, 0, 3000, 720));
	ocean1.setPosition(0.0f, 0.0f);
	ocean2.setTexture(oceanTexture);
	ocean2.setTextureRect(sf::IntRect(0, 0, 3000, 720));
	ocean2.setPosition(2999.0f, 0.0f);
	float mapSpeedx = 0.1f;
	//////////////////////////////////////////////////////////  texture submarine  ////////////////////////////////////////////////////////////////////////
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	player.setPosition(50.0f, 500.0f);
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("img/submarine1.png")) {
		printf("\nloading failure\n");
	}
	playerTexture.setSmooth(true);
	player.setTexture(&playerTexture);
	player.setOrigin(player.getSize() / 2.0f);

	//-->> hitbox <<--//
	sf::RectangleShape playerHitbox;
	printf("%f",playerHitbox.getSize().x);
	playerHitbox.setPosition(sf::Vector2f(player.getPosition().x+10,player.getPosition().y+10));
	playerHitbox.setFillColor(sf::Color::Transparent);
	playerHitbox.setSize(sf::Vector2f(80.0f,80.0f));
	playerHitbox.setOutlineColor(sf::Color::Transparent);
	playerHitbox.setOrigin(player.getSize() / 2.0f);
	playerHitbox.setOutlineThickness(1.0f);

	//////////////////////////////////////////////////////////  bullet texture  ////////////////////////////////////////////////////
	
	std::vector<bullet> bullet_vec;
	sf::Texture bullet_texture;
	if (!bullet_texture.loadFromFile("img/missile_sprite.png"))
	{
		printf("\ncant open bullet sprite\n");
	}
	//////////////////////////////////////////////////////   hostile  ////////////////////////////////////////////////////////////////////////////////////////////
	sf::Texture hostile_texture;
	sf::Texture boss_texture;
	std::vector<hostile> enemies_vec;
	
	if (!boss_texture.loadFromFile("img/hostile.png"))
	{
		printf("\ncant open boss.png\n");
	}
	if (!hostile_texture.loadFromFile("img/hostile.png"))
	{
		printf("\ncant open hostile.png\n");
	}
	hostile_texture.setSmooth(true);
	hostile host(&hostile_texture, sf::Vector2u(1, 1), .0f, sf::Vector2f(1300, 400));

	//====================hostile bullet=====================//
	sf::Texture hostile_bullet;
	std::vector<bullet> boss_bullet;
	if (!hostile_bullet.loadFromFile("img/missile_hostile1.png")) 
	{
		printf("cant open missile hostile pic!");
	}
	/////////////////////////////////////////////////////  HP bar  //////////////////////////////////////////////////////////////////////////////////
	HP calledhp;
	/*sf::Texture blood;
	sf::Texture heart;
	heart.setSmooth(true);
	blood.setSmooth(true);
	sf::RectangleShape heartbox(sf::Vector2f(50.0f, 50.0f));
	sf::RectangleShape bloodbar(sf::Vector2f(400.0f, 20.0f));
	if(!heart.loadFromFile("img/heart-icon.png"))
	{
		printf("\ncant open heart_icon\n");
	}
	if (!blood.loadFromFile("img/HP_bar.png")) {
		printf("\ncant open HP_bar\n");
	}*/

	////////////////////////////////////////////////// heart icon /////////////////////////////////////////////////////////////////////////////////////
	//bloodbar.setOutlineThickness(5.0f);
	//bloodbar.setOutlineColor(sf::Color::Black);
	//heartbox.setTexture(&heart);
	//heartbox.setPosition(30.0f, 20.0f);

	//bloodbar.setPosition(100.0f,35.0f);
	////printf("x:%f y:%f",bloodbar.getPosition().x, bloodbar.getPosition().y);
	//bloodbar.setTexture(&blood);
	//float MyHP = 78000;
	
	/*sf::RectangleShape HP(sf::Vector2f(MyHP / 250.0f, 30));
	HP.setPosition(sf::Vector2f(450, 46));
	HP.setFillColor(sf::Color::Magenta);
	HP.setSize(sf::Vector2f(MyHP / 320.f, 15));*/
	
	/*if (!bloodframe.loadFromFile("img/bloodframe.png")) 
	{
		printf("\ncant open HP_bar\n");
	}*/

	
	/////////////////////////////////////////////////////////////   obstruct   /////////////////////////////////////////////////////////////////////////////////////////////
	sf::Texture coral1;
	sf::Texture coral2;
	int coralState;
	if (!coral1.loadFromFile("img/coral1.png"))
	{
		std::cout << "cant open coral1.png" << std::endl;
	}
	if (!coral2.loadFromFile("img/coral2.png"))
	{
		std::cout << "cant open coral2.png" << std::endl;
	}
	coral1.setSmooth(true);
	coral2.setSmooth(true);

	////////////////////--------------------------------------------->>>  Game  <<<--------------------------------------------------/////////////////////////////////////////////// 
	while (window.isOpen()) 
	{
		deltaTime = cl.restart().asSeconds();
		if (deltaTime > 1.0f / 60.0f) { deltaTime = 1.0f / 60.0f; }
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{

				case sf::Event::KeyReleased: 
						break;

				case sf::Event::Closed:
						window.close();
						printf("\nWindow have closed\n");
						break;

				case sf::Event::Resized:
						printf("\nNew window width: %d New window height: %d\n",event.size.width,event.size.height);
						break;
			}
			if (event.type == event.Closed)
			{
				window.close();
			}
		}
		//----- hitbox update -----//

		playerHitbox.setPosition(sf::Vector2f(player.getPosition().x + 10, player.getPosition().y + 10));

		//-----^^^^------ menu -----^^^^------//
		
		/*if (gameState == menustate)
		{
			menu.update(deltaTime, sf::Mouse::isButtonPressed(sf::Mouse::Left), mousePosition);
		}*/

		////////////////////////////////////////// create bullet ////////////////////////////////////////////////////////////////////////////////
		bull = bullet_time.getElapsedTime().asMilliseconds();
		if (bull > 700) // it will be have item which increse time reloaded // 7 secs.
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				printf("\nMissile was released!\n");
				bullet_vec.push_back(bullet(&bullet_texture, sf::Vector2u(2,1), 0.05f, sf::Vector2f(player.getPosition().x+25, player.getPosition().y + 35)));
				bullet_time.restart();
			}
		}
		collide.bulletAndBoss(bullet_vec, host,score);
		for (bullet& bullet : bullet_vec) 
		{
			int i = 0;
			if (bullet.bulletGetPosition().x >= 1080)
			{
				bullet_vec.erase(bullet_vec.begin()+i);
			}
			else bullet.update(deltaTime);
			i++;
			
		}
		//std::cout << "size of bullet : " << bullet_vec.size() << std::endl;

		/////////////////////////////////////////////////////////  hostile  ///////////////////////////////////////////////////////////////////////////////////////////////
		
		//if(boss_time == 0) // ถ้าฆ่าลูกสมุนหมดเเล้ว/*{		}*/
		
		host.canMissileShoot(deltaTime,900.0f, &hostile_bullet);
		collide.bulletBossAndPlayer(host, playerHitbox);
		host.update(deltaTime,player.getPosition().y,player);
		
		/////////////////////////////////  obstruct  ////////////////////////////////
		obstruct coral(&coral1, &coral2, deltaTime);
		coral.update(deltaTime,mapSpeedx);

		////////////////////////////////////////////////////  map motion  /////////////////////////////
		ocean1.move(-0.1f, 0.0f);
		ocean2.move(-0.1f, 0.0f);
		oceanx++;
		if (oceanx == 6000) {
			ocean1.setPosition(0.0f, 0.0f);
			ocean2.setPosition(2999.0f, 0.0f);
			oceanx = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			if(player.getPosition().x >= 50) player.move(-0.2f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player.move(0.2f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			player.move(0.0f, -0.2f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			player.move(0.0f, 0.2f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			window.close();
		}
		
		//----------------------------
		mousePosition.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
		window.clear();
		
		/*if (gameState == 0)
		{
			menu.draw(window);
			window.draw(mousePosition);
		}*/

		/*window.draw(Obstacle[0]);
		window.draw(Obstacle[1]);
		window.draw(Obstacle[2]);*/
		
		//---game render---//
			window.draw(ocean1);
			window.draw(ocean2);
			window.draw(player);
			window.draw(playerHitbox);
			calledhp.draw(window);
		
		for (bullet& bullet : bullet_vec)
			bullet.draw(window);
		
		host.draw(window);
		coral.draw(window);
		//window.draw(HP);
		window.display();
	}
	return 0;
}