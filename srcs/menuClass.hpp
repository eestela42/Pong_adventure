#ifndef MENUCLASS_HPP
#define MENUCLASS_HPP

#include <raylib.h>
#include <map>
#include <string>


class menuClass
{
	public:
		std::map<std::string, void(menuClass::*)()> 	mapFunctions;
		std::string 		state;
		menuClass();
		~menuClass();
		
		void menu();
		void game();
		int render();

};





#endif