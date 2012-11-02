#include <iostream>
#include <fstream>
#include "image_cache.hpp"
#include "flog.hpp"
#include "f_exception.hpp"

int main()
{
	ft::Flog flog = ft::Flog::getInstance();
	flog.setLogMode(ft::LogMode::CON_LOG);
	flog.setLogTime(true);
	flog.changeLogFile("fjefejuf.txt");

	sf::ContextSettings installningar;
	sf::RenderWindow app;
	app.create(sf::VideoMode(800,600,32),"SFML Window test");

	sf::Event event;		
	try
	{
		while(app.isOpen())
		{
			//ft::ImageCache::loadImage("resources/error.png");
			while(app.pollEvent(event))
			{
				if(event.type == sf::Event::Closed)
				{
					app.close();
				}
			}
						
			app.clear();
			app.display();

		}
		
		while(ft::ImageCache::discardBottomImage() > 0);
		
	}
	
	catch(ft::FException& fe)
	{
		std::cout << fe.what() << std::endl;
		system("pause");
	}
	catch(std::exception &e)
	{
			
		std::cout << e.what() << std::endl;
		system("pause");
	}
	
	flog.closeLog();
    return EXIT_SUCCESS;
}


