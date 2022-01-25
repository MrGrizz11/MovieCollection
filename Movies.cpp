#include "Movies.h"
#include "helper.h"
#include <fstream>
#include <iostream>
#include <string>

int movie_counter {};
std::string movie_counter_file("movie_counter.txt");
std::string movie_collection_file("movie_collection.txt");

void Movies::get_movie_collection()
{
    int cnt { 1 };
    std::fstream file(movie_collection_file);

    for(int i = 0; i < movie_counter; i++) {

        GotoLine(file, i + cnt);
        std::string name;
        file >> name;
        cnt++;

        GotoLine(file, i + cnt);
        std::string description;
        file >> description;
        cnt++;

        GotoLine(file, i + cnt);
        std::string rating;
        file >> rating;
        cnt++;

        GotoLine(file, i + cnt);
        std::string views;
        file >> views;

        movie_list.push_back(Movie(name, description, rating, views));
    }
}

void Movies::add_movie()
{
    movie_counter = get_movie_counter(movie_counter);

    std::string name {};
    std::string description {};
    std::string name_full {};
    std::string description_full {};
    std::string rating {};
    std::string views {};

    std::cout << std::endl << "Movie name:" << std::endl;
    std::cin >> name_full;
    std::getline(std::cin, name);
    name_full.append(name);

    std::cout << "Movie description:" << std::endl;
    std::cin >> description_full;
    std::getline(std::cin, description);
    description_full.append(description);

    std::cout << "Movie rating:" << std::endl;
    std::cin >> rating;

    std::cout << "Times watched:" << std::endl;
    std::cin >> views;

    movie_counter++;
    std::fstream(movie_counter_file) << movie_counter;

    add_movie_to_file(name_full, description_full, rating, views);
    Movie current_movie = Movie(name_full, description_full, rating, views);
    movie_list.push_back(current_movie);

    std::cout << std::endl << "Movie added succesfully" << std::endl << std::endl;
    std::cout << "____________________________________________" << std::endl << std::endl;
    display_actions(3);
}

void Movies::show_movies(int first_use)
{
    if(movie_counter == 0) {
        movie_counter = get_movie_counter(movie_counter);
        get_movie_collection();
    }

    if(movie_list.empty()) {
        if(first_use == 1) {
            std::cout << std::endl << "Looks like you don`t have any movies in your collection!" << std::endl;
            std::cout << "Do you want to add some?  (y/n)" << std::endl;
        } else if(first_use == 2) {
            std::cout << std::endl << "Invalid answear, please try again" << std::endl;
            std::cout << "Do you want to add a movie to your collection?  (y/n)" << std::endl;
        }

        char answear {};
        std::cin >> answear;
        std::cout << "_____________________________________________" << std::endl;
        if(answear == 'y') {
            add_movie();
        } else if(answear == 'n') {
            display_actions(3);
        } else {
            show_movies(2);
        }

    } else {
        if(movie_counter == 1)
            std::cout << std::endl << "You have " << movie_counter << " movie in your collection!" << std::endl;
        else if(movie_counter > 1)
            std::cout << std::endl << "You have " << movie_counter << " movies in your collection!" << std::endl;

        for(int i {}; i < movie_counter; i++) {
            std::cout << std::endl << i + 1 << ". Movie" << std::endl;
            std::cout << "Name: " << movie_list.at(i).show_name() << std::endl;
            std::cout << "Description: " << movie_list.at(i).show_description() << std::endl;
            std::cout << "Rating: " << movie_list.at(i).show_rating() << std::endl;
            std::cout << "Views: " << movie_list.at(i).show_views() << std::endl << std::endl;
        }
        std::cout << "_____________________________________________" << std::endl;
        display_actions(3);
    }
}