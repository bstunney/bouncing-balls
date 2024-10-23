//
// Created by Ben Tunney on 1/12/23.
//

// C++ Standard Libraries
#include <iostream>
// Third Party Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>
#include <fstream>
#include <string>
#include <math.h>
#include <random>
#include <chrono>
#include <sys/time.h>
#include <ctime>

// #include "ArgumentSettings.hpp"

// to compile: g++ -std=c++17 -g ./src/*.cpp -o prog -I./include -lsfml-graphics -lsfml-window -lsfml-system -lpthread
// to run: ./prog 25


// Entry point into the program
int main(int argc, char* argv[]) {

    // check arg settings
    // neu::ArgumentSettings args(argc, argv);


    // Create an SFML Window
    // This window allows us to 'render graphics' onto a Window.
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "colors and sounds!");


    // This is an infinite loop
    // This loop will continuously run our application
    // until we receive an event to close the window.

    int redx = 200;
    sf::CircleShape shape1(40.0f);
    shape1.setFillColor(sf::Color::Red);
    shape1.setPosition(redx,200);
    bool redforward = true;

    int orangex = 200;
    sf::CircleShape shape2(40.0f);
    shape2.setFillColor(sf::Color(255, 87, 51));
    shape2.setPosition(orangex,300);
    bool orangeforward = true;

    int yellowx = 200;
    sf::CircleShape shape3(40.0f);
    shape3.setFillColor(sf::Color(255,215,0));
    shape3.setPosition(yellowx,400);
    bool yellowforward = true;

    int greenx = 200;
    sf::CircleShape shape4(40.0f);
    shape4.setFillColor(sf::Color::Green);
    shape4.setPosition(greenx,500);
    bool greenforward = true;

    int bluex = 200;
    sf::CircleShape shape5(40.0f);
    shape5.setFillColor(sf::Color::Blue);
    shape5.setPosition(bluex,600);
    bool blueforward = true;

    int purplex = 200;
    sf::CircleShape shape6(40.0f);
    shape6.setFillColor(sf::Color(138,43,226));
    shape6.setPosition(purplex,700);
    bool purpleforward = true;


    struct timeval time_now{};
    gettimeofday(&time_now, nullptr);
    time_t msecs_time = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);

    int begin = msecs_time;
    int timesince = 0;

    sf::SoundBuffer note1;
    if (!note1.loadFromFile("316899__jaz-the-man-2__do-stretched.wav"))
        return -1;
    sf::SoundBuffer note2;
    if (!note2.loadFromFile("316907__jaz-the-man-2__mi-stretched.wav"))
        return -1;
    sf::SoundBuffer note3;
    if (!note3.loadFromFile("316911__jaz-the-man-2__sol-stretched.wav"))
        return -1;
    sf::SoundBuffer note4;
    if (!note4.loadFromFile("316900__jaz-the-man-2__do-stretched-octave.wav"))
        return -1;

    sf::Sound sound1;
    sound1.setBuffer(note1);
    sf::Sound sound2;
    sound2.setBuffer(note2);
    sf::Sound sound3;
    sound3.setBuffer(note3);
    sf::Sound sound4;
    sound4.setBuffer(note4);




    while (window.isOpen()) {

        // Within our loop (local scope) we create
        // an event. It is the first thing that we
        // do.
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }


        // Handle mouse clicks
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

            // Retrieve the position of the mouse
            sf::Vector2i position = sf::Mouse::getPosition(window);

            // if pressing the plot
            if (position.x < 550 and position.x > 50 and position.y > 50 and position.y < 550) {

                // hasClicked = true;
                // get random test data point
                //int range = CleanTest.size() - 0 + 1;
                //KIndex = rand() % range;
            }
        } else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        }

        // Clear the window at the start of every frame
        window.clear();

        // make gray background
        sf::RectangleShape rectangle(sf::Vector2f(1000, 1000));
        rectangle.setFillColor(sf::Color(220, 220, 220));
        window.draw(rectangle);

        // make box for into
        sf::RectangleShape intro(sf::Vector2f(800, 1000));
        intro.setPosition(100, 0);
        intro.setFillColor(sf::Color::White);
        intro.setOutlineThickness(10.0);
        intro.setOutlineColor(sf::Color(136, 139, 141));
        window.draw(intro);


        if (timesince % 7 == 0){
            if (redforward) {
                // red circle
                if (redx > 879) {
                    redforward = false;
                }

                redx += 1;
                shape1.setPosition(redx, 200);

            } else {
                if (redx < 51) {
                    redforward = true;
                }
                redx -= 1;
                shape1.setPosition(redx, 200);

            }
        }


        if (timesince % 6 == 0){
            if (orangeforward) {
                // red circle
                if (orangex == 879) {
                    orangeforward = false;
                }

                orangex += 1;
                shape2.setPosition(orangex, 300);

            } else {
                if (orangex == 51) {
                    orangeforward = true;
                }
                orangex -= 1;
                shape2.setPosition(orangex, 300);

            }
        }


        if (timesince % 5 == 0){
            if (yellowforward) {
                // red circle
                if (yellowx == 879) {
                    yellowforward = false;
                    sound1.play();
                }

                yellowx += 1;
                shape3.setPosition(yellowx, 400);

            } else {
                if (yellowx == 51) {
                    yellowforward = true;
                    sound1.play();
                }
                yellowx -= 1;
                shape3.setPosition(yellowx, 400);

            }
        }



        if (timesince % 4 == 0){
            if (greenforward) {
                // red circle
                if (greenx == 879) {
                    greenforward = false;
                    sound2.play();
                }

                greenx += 1;
                shape4.setPosition(greenx, 500);

            } else {
                if (greenx == 51) {
                    greenforward = true;
                    sound2.play();
                }
                greenx -= 1;
                shape4.setPosition(greenx, 500);


            }
        }



        if (timesince % 2 == 0){
            if (blueforward) {
                // red circle
                if (bluex == 879) {
                    blueforward = false;
                    sound3.play();
                }

                bluex += 1;
                shape5.setPosition(bluex, 600);

            } else {
                if (bluex == 51) {
                    blueforward = true;
                    sound3.play();
                }
                bluex -= 1;
                shape5.setPosition(bluex, 600);

            }
        }



        if (timesince % 1 == 0){
            if (purpleforward) {
                // red circle
                if (purplex == 879) {
                    purpleforward = false;
                    sound4.play();
                }

                purplex += 1;
                shape6.setPosition(purplex, 700);

            } else {
                if (purplex == 51) {
                    purpleforward = true;
                    sound4.play();
                }
                purplex -= 1;
                shape6.setPosition(purplex, 700);

            }
        }


        gettimeofday(&time_now, nullptr);
        // get time since start or since interval
        timesince = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000) - begin;

        //window.draw(shape1);
        //window.draw(shape2);
        //window.draw(shape3);
        window.draw(shape4);
        window.draw(shape5);
        window.draw(shape6);

        gettimeofday(&time_now, nullptr);

        // Display to the window
        window.display();
    }

    return 0;
}






