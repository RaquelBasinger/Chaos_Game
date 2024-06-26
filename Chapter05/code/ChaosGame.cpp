// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib> 

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
    
	sf::Font font;
	sf::Text text1;
    sf::Text text2;
    if (!font.loadFromFile("fonts/KOMIKAP_.ttf"))
	{
    		cout << "Error Loading Font!" << endl;
	}
	text1.setFont(font);
	text1.setCharacterSize(50);
	text1.setFillColor(sf::Color::Red);
	text1.setPosition({100,0});
    
    text1.setString("Click on any three points on the screen");

    text2.setFont(font);
	text2.setCharacterSize(50);
	text2.setFillColor(sf::Color::Red);
	text2.setPosition({100,50});
    text2.setString("Click again to start");

	
	// Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game!", Style::Default);
	View view;
    view.setSize(1920.0, 1080.0);
    view.setCenter(1920 / 2.0, 1080.0 / 2.0);
    window.setView(view);
    vector<Vector2f> vertices;
    	vector<Vector2f> points;
	while (window.isOpen())
	{
		
        /*
		****************************************
		Handle the players input
		****************************************
		*/
        	Event event;
		while (window.pollEvent(event))
		{
            		if (event.type == Event::Closed)
            		{
				// Quit the game when the window is closed
				window.close();
            		}
            		if (event.type == sf::Event::MouseButtonPressed)
            		{
                		if (event.mouseButton.button == sf::Mouse::Left)
                		{
                    			std::cout << "the left button was pressed" << std::endl;
                    			std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    			std::cout << "mouse y: " << event.mouseButton.y << std::endl;

                    			if(vertices.size() < 3)
                    			{
                        			vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
                    			}
                   			else if(points.size() == 0)
                    			{                        			
						            points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
                        			///push back to points vector
                    			}
                		}
            		}
        	}
        	if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
        /*
		****************************************
		Update
		****************************************
		*/

        	if(points.size() > 0)
        	{
            		///generate more point(s)
            		///select random vertex
            		///calculate midpoint between random vertex and the last point in the vector
            		///push back the newly generated coord.
			int randomVertex;
			randomVertex = rand() % 3;
			float x1 = (vertices[randomVertex].x + points[(points.size() - 1)].x)/2;
			float y1 = (vertices[randomVertex].y + points[(points.size() - 1)].y)/2;
			points.push_back(Vector2f(x1,y1));		
        	}

        /*
		****************************************
		Draw
		****************************************
		*/
        	window.clear();
            window.draw(text1);
        	for(int i = 0; i < vertices.size(); i++)
        	{
            		RectangleShape rect(Vector2f(10,10));
            		rect.setPosition(Vector2f(vertices[i].x, vertices[i].y));
            		rect.setFillColor(Color::Blue);
            		window.draw(rect);
        	}
            if(vertices.size()==3){
                window.draw(text2);
            }
		for(int i = 0; i < points.size(); i++)
        	{
            		RectangleShape rect(Vector2f(10,10));
            		rect.setPosition(Vector2f(points[i].x, points[i].y));
            		rect.setFillColor(Color::Blue);
            		window.draw(rect);
        	}
        	window.display();
    	}
}
