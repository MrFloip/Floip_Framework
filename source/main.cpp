#include "image_cache.hpp"
#include "flog.hpp"
#include "f_exception.hpp"
#include "include_gl.hpp"
#include "VertexBuffer.hpp"
#include <sstream>
//#include <SFML/OpenGL.hpp>

int main()
{
	
	ft::Flog *flog = ft::Flog::getInstance();
	flog->setLogMode(ft::LogMode::CONSOLE);
	sf::ContextSettings settings;
	flog->setColor(ft::LogColor::BLUE | ft::LogColor::INTENSITY);
	ft::Flog *penis = ft::Flog::getInstance();

	*penis << "%tCreating OpenGL Window...\n";

	sf::Window window;
	window.create(sf::VideoMode(800,800,32),"SFML Window test",sf::Style::Default,settings);
	window.setVerticalSyncEnabled(true);
	sf::Event event;		

	GLenum err;
	*flog << "%tInitiating glew..\n";
	err = glewInit();
	if(err == GLEW_OK)
	{
		*flog << "%tinitiation succeeded.\n";
	}
	else
	{
		const unsigned char* errorStr = glewGetErrorString(err);
		stringstream s;
		s << errorStr;
		string penis = s.str();
		*flog << "%tinitiation failed." << penis  << "\n"; 
	}

	*flog << "%tSetting up OpenGL...\n";
	// Set color and depth clear value
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(1.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	
	int vSize = 6*2*sizeof(GLfloat);
	GLfloat vertex[] =
	{
		 0.0f, 0.0f,
		 0.0f, -0.25f,
		 0.25f, -0.25f,
		 0.25f, -0.25f,
		 0.5f, 0.0f,
		 0.0f, 0.0f

	};
	int colorSize = 6*3*sizeof(float);
	float colorData[] =	
	{
		1.0f, 1.0f, 1.0f,
		0.5f, 0.5f, 0.5f,
		1.0f, 1.0f, 1.0f,
		0.5f, 0.5f, 0.5f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 0.5f
	};


	ft::VertexBuffer test(true,false);
	test.generateBuffer(ft::VERTEX_ARRAY);
	test.bufferVertexData(ft::VERTEX_ARRAY,vSize,vertex,GL_STATIC_DRAW);
	test.arrayPointer(ft::VERTEX_ARRAY,GL_FLOAT,2);
	test.generateBuffer(ft::COLOR_ARRAY);
	test.bufferVertexData(ft::COLOR_ARRAY,colorSize,colorData,GL_STATIC_DRAW);


	try
	{
    // run the main loop
	bool running = true;
    while (running)
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
				*flog << "%tClosing...\n";
                // end the program
                running = false;
            }
            else if (event.type == sf::Event::Resized)
            {
				*flog << "%tResizing window...\n";
                // adjust the viewport when the window is resized
                glViewport(0, 0, event.size.width, event.size.height);
            }
        }

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		test.drawArrays(GL_TRIANGLES,0,sizeof(vertex)/sizeof(GLfloat));
		window.display();
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
	
	flog->closeLog();
    return EXIT_SUCCESS;
}


