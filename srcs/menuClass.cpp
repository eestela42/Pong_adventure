#include "menuClass.hpp"

		menuClass::menuClass(): state("menu")
{
	mapFunctions.insert(std::pair<std::string, void(menuClass::*)()>("menu", &menuClass::menu));
	mapFunctions.insert(std::pair<std::string, void(menuClass::*)()>("game", &menuClass::game));
}

		menuClass::~menuClass()
{
}

int	menu_mouse_click()
{
    int pos[2] = {GetMouseX() , GetMouseY()};
    if (pos[0] < 150 || pos[0] > 250)
        return (0);
    if (pos[1] > 150 && pos[1] < 200)
        return(1);
    else if (pos[1] > 300 && pos[1] < 350)
        return (1);
    return (0);
}

int	menuClass::render()
{
	Texture2D title = LoadTexture("sprites/Title.png");
	
	while (1)
	{
		BeginDrawing();
		DrawTexture(title, -50, -50, WHITE);
		DrawText("BORDERCLONE", 0, 0, 50, WHITE);
		DrawText("Play",150, 150, 50, WHITE);
		DrawText("Exit",150, 300, 50, WHITE);
		EndDrawing();
		if(WindowShouldClose())
			return 0;
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && menu_mouse_click())
			return 1;
	}
}


void	menuClass::menu()
{
	(this->*mapFunctions[state])();
}

void	menuClass::game()
{
	(this->*mapFunctions[state])();
}