#include "Menu.h"

Menu::Menu(float width, float height)
{
	if (!MenuBG.loadFromFile(MAIN_MENU_BACKGROUND_FILEPATH)) {
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
	BG.setTexture(&MenuBG);

}
