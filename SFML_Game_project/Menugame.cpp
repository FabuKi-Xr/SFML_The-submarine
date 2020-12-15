#include "Menugame.h"

Menugame::Menugame(float width, float height,int gamestate)
{
	//loading resource
	if (!MENU_BG.loadFromFile(MAIN_MENU_BACKGROUND_FILEPATH)) {
		printf("loading failure BG");
	}
	if (!ButtonTexture[0][0].loadFromFile(MAIN_MENU_PLAY_BUTTON_DEFAULT)) {
		printf("cant open play_default");
	}
	if (!ButtonTexture[0][1].loadFromFile(MAIN_MENU_PLAY_BUTTON_ONCLICK)) {
		printf("cant open play_onclick");
	}
	if (!ButtonTexture[0][2].loadFromFile(MAIN_MENU_PLAY_BUTTON_CLICKED)) {
		printf("cant open play_clicked");
	}
	if (!ButtonTexture[1][0].loadFromFile(MAIN_MENU_OPTION_BUTTON_DEFAULT)) {
		printf("cant open option_default");
	}
	if (!ButtonTexture[1][1].loadFromFile(MAIN_MENU_OPTION_BUTTON_ONCLICK)) {
		printf("cant open MAIN_MENU_OPTION_BUTTON_ONCLICK");
	}
	if (!ButtonTexture[1][2].loadFromFile(MAIN_MENU_OPTION_BUTTON_CLICKED)) {
		printf("cant open MAIN_MENU_OPTION_BUTTON_CLICKED");
	}
	if (!ButtonTexture[2][0].loadFromFile(MAIN_MENU_EXIT_BUTTON_DEFAULT)) {
		printf("cant open MAIN_MENU_EXIT_BUTTON_DEFAULT");
	}
	if (!ButtonTexture[2][1].loadFromFile(MAIN_MENU_EXIT_BUTTON_ONCLICK)) {
		printf("cant open MAIN_MENU_EXIT_BUTTON_ONCLICK");
	}
	if (!ButtonTexture[2][2].loadFromFile(MAIN_MENU_EXIT_BUTTON_CLICKED)) {
		printf("cant open MAIN_MENU_EXIT_BUTTON_CLICKED");
	}
	if (!marine.loadFromFile("img/player.png"))
	{
		printf("cant open player.png");
	}
	if (!bubble.loadFromFile("img/bubble.png"))
	{
		printf("cant open bubble.png");
	}
	if (!howToPlay[0].loadFromFile(MAIN_HOW_TO_PLAY_BUTTON))
	{
		printf("cant open howToplay1");
	}
	if (!howToPlay[1].loadFromFile(MAIN_HOW_TO_PLAY_INTRO))
	{
		printf("cant open howtoplay2");
	}
	if (!nextButtonTexture.loadFromFile(MAIN_NEXT_BUTTTON))
	{
		std::cout << "cant open nextbutton" << std::endl;
	}
	if (!closeTexture.loadFromFile(MAIN_CLOSE_HOW_TO_PLAY))
	{
		std::cout << "cant open closeHowToPlay" << std::endl;
	}
	if (menutheme.openFromFile("soundtrack/menuTheme.ogg"))
	{
		std::cout << "cant open menuTheme.ogg" << std::endl;
	}
	menutheme.setVolume(80.0f);
	menutheme.setLoop(true);
	BG.setTexture(MENU_BG);

	menutheme.play();
	MENU_BG.setSmooth(true);
	OBJECT.setSmooth(true);
	ButtonTexture[0][0].setSmooth(true);
	ButtonTexture[0][1].setSmooth(true);
	ButtonTexture[0][2].setSmooth(true);
	ButtonTexture[1][0].setSmooth(true);
	ButtonTexture[1][1].setSmooth(true);
	ButtonTexture[1][2].setSmooth(true);
	ButtonTexture[2][0].setSmooth(true);
	ButtonTexture[2][1].setSmooth(true);
	ButtonTexture[2][2].setSmooth(true);
	marine.setSmooth(true);

	//init object//
	submarine.setTexture(&marine);
	submarine.setPosition(-300.0f, 75.0f);
	submarine.setSize(sf::Vector2f(600.0f, 600.0f));

	// initbutton //
	playButtonBody.setTexture(&ButtonTexture[0][0]);
	playButtonBody.setSize(sf::Vector2f(BUTTON_SCALEX, BUTTON_SCALEY));
	playButtonBody.setOutlineColor(sf::Color::Transparent);
	playButtonBody.setOutlineThickness(1.0f);
	playButtonBody.setPosition(700.0f, 280.0f);

	optionButtonBody.setTexture(&ButtonTexture[1][0]);
	optionButtonBody.setSize(sf::Vector2f(BUTTON_SCALEX, BUTTON_SCALEY));
	optionButtonBody.setPosition(700.0f, 420.0f);

	exitButtonBody.setTexture(&ButtonTexture[2][0]);
	exitButtonBody.setSize(sf::Vector2f(BUTTON_SCALEX, BUTTON_SCALEY));
	exitButtonBody.setPosition(700.0f, 560.0f);

	// inithowtoplay //
	howToPlay[0].setSmooth(true);
	howToPlay[1].setSmooth(true);
	howToplaypage.setTexture(&howToPlay[0]);
	howToplaypage.setSize(sf::Vector2f(1080.0f, 720.0f));
	howToplaypage.setPosition(sf::Vector2f(0.0f, 0.0f));

	//  initNextButton  //
	nextButtonTexture.setSmooth(true);
	nextButton.setTexture(&nextButtonTexture);
	nextButton.setSize(sf::Vector2f(100.0f,100.0f));
	nextButton.setPosition(sf::Vector2f(800.0f,550.0f));

	// initcloseButton //
	closeTexture.setSmooth(true);
	close.setTexture(&closeTexture);
	close.setSize(sf::Vector2f(100.0f, 100.0f));
	close.setPosition(sf::Vector2f(890.0f,45.0f));
}
Menugame::~Menugame()
{

}
void Menugame::update(float deltaTime, bool mouseState, sf::CircleShape& MousePosition,int &gameState)
{
	this->velocity;
	velocity.x = 200.0f;
	if (submarine.getPosition().x <= 0)
	{
		submarine.move(deltaTime * 200.0f, 0.0f);

	}

	playButtonBody.setTexture(&ButtonTexture[0][0]);
	playButtonState = Default;

	optionButtonBody.setTexture(&ButtonTexture[1][0]);
	optionButtonState = Default;

	exitButtonBody.setTexture(&ButtonTexture[2][0]);
	exitButtonState = Default;

	//std::cout << "state: " << isHowToPlayOn << std::endl;
	if (playButtonBody.getGlobalBounds().intersects(MousePosition.getGlobalBounds()) && isHowToPlayOn == false)
	{

		if (playButtonState == Default)
		{
			playButtonBody.setTexture(&ButtonTexture[0][1]);
			playButtonBody.setSize(sf::Vector2f(BUTTON_SCALEX, BUTTON_SCALEY));
			playButtonBody.setPosition(700.0f, 280.0f);
			playButtonState = onclick;
		}
		if ((playButtonState == onclick) && mouseState == true)
		{
			playButtonBody.setTexture(&ButtonTexture[0][2]);
			playButtonBody.setSize(sf::Vector2f(BUTTON_SCALEX, BUTTON_SCALEY));
			playButtonBody.setPosition(700.0f, 280.0f);
			gameState = 1;
			mouseState = false;
		}

	}

	if (optionButtonBody.getGlobalBounds().intersects(MousePosition.getGlobalBounds()) && isHowToPlayOn == false)
	{

		if (optionButtonState == Default)
		{
			optionButtonBody.setTexture(&ButtonTexture[1][1]);
			optionButtonBody.setSize(sf::Vector2f(BUTTON_SCALEX, BUTTON_SCALEY));
			optionButtonBody.setPosition(700.0f, 420.0f);
			optionButtonState = onclick;
		}
		if ((optionButtonState == onclick) && mouseState == true)
		{
			optionButtonBody.setTexture(&ButtonTexture[1][2]);
			optionButtonBody.setSize(sf::Vector2f(BUTTON_SCALEX, BUTTON_SCALEY));
			optionButtonBody.setPosition(700.0f, 420.0f);
			mouseState == false;
			state = true;
			isNextButtonOn = true;
		}

	}

	if (exitButtonBody.getGlobalBounds().intersects(MousePosition.getGlobalBounds())&& isHowToPlayOn==false)
	{

		if (exitButtonState == Default)
		{
			exitButtonBody.setTexture(&ButtonTexture[2][1]);
			exitButtonBody.setSize(sf::Vector2f(BUTTON_SCALEX, BUTTON_SCALEY));
			exitButtonBody.setPosition(700.0f, 560.0f);
			exitButtonState = onclick;
		}
		if ((exitButtonState == onclick) && mouseState == true)
		{
			exitButtonBody.setTexture(&ButtonTexture[2][2]);
			exitButtonBody.setSize(sf::Vector2f(BUTTON_SCALEX, BUTTON_SCALEY));
			exitButtonBody.setPosition(700.0f, 560.0f);
			gameState = 2;
			mouseState = false;
		}

	}
	if (state == true)
	{
		isHowToPlayOn = true;
		if (nextButton.getGlobalBounds().intersects(MousePosition.getGlobalBounds())&&mouseState == true)
		{
			howToplaypage.setTexture(&howToPlay[1]);
			howToplaypage.setSize(sf::Vector2f(1080.0f, 720.0f));
			howToplaypage.setPosition(sf::Vector2f(0.0f, 0.0f));
			playButtonState == 100;
			optionButtonState = 100;
			exitButtonState = 100;
			isNextButtonOn = false;
		}
		if (close.getGlobalBounds().intersects(MousePosition.getGlobalBounds()) && mouseState == true)
		{
			state = false;
			isHowToPlayOn = false;
			howToplaypage.setTexture(&howToPlay[0]);
			howToplaypage.setSize(sf::Vector2f(1080.0f, 720.0f));
			howToplaypage.setPosition(sf::Vector2f(0.0f, 0.0f));
		}
		mouseState = false;
	}
}
void Menugame::draw(sf::RenderWindow& window)
{
	window.draw(BG);
	window.draw(submarine);
	window.draw(playButtonBody);
	window.draw(optionButtonBody);
	window.draw(exitButtonBody);
	if (state == true)
	{
		window.draw(howToplaypage);
		if (isNextButtonOn == true)
		{
			window.draw(nextButton);
		}
		window.draw(close);
	}
}





