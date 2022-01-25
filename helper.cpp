#include "Movies.h"
#include "helper.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>

using namespace std;
Movies movie_collection_object;

void add_movie_to_file(std::string name, std::string description, std::string rating, std::string views)
{
    std::ofstream file_out;

    file_out.open("movie_collection.txt", std::ios_base::app);

    file_out << name << std::endl;
    file_out << description << std::endl;
    file_out << rating << std::endl;
    file_out << views << std::endl;

    file_out.close();
}

int get_movie_counter(int movie_counter)
{
    if(std::fstream("movie_counter.txt")) {
        std::string str_movie_cnt {};
        std::getline(std::ifstream("movie_counter.txt"), str_movie_cnt);
        std::stringstream str_to_int(str_movie_cnt);
        str_to_int >> movie_counter;
    } else {
        std::ofstream counter_file("movie_counter.txt");
    }

    return movie_counter;
}

std::fstream& GotoLine(std::fstream& file, unsigned int num)
{
    file.seekg(std::ios::beg);
    for(unsigned int i = 0; i < num - 1; ++i) {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return file;
};

void display_actions(int display_model)
{
    if(display_model == 1)
        cout << "Welcome to your movie collection list" << endl << endl;
    else if(display_model == 2)
        cout << endl << "Please enter a valid action:" << endl << endl;
    else if(display_model == 3)
        cout << endl << "Choose an action:" << endl << endl;

    cout << "1. See your collection" << endl;
    cout << "2. Add a movie to collection" << endl;
    cout << "3. Edit collection" << endl << endl;

    choose_action();
}

void choose_action()
{
    cout << " - Choose an action from the list above: ";
    int answear {};
    cin >> answear;
    cout << "____________________________________________" << endl;

    if(answear == 1) {
        movie_collection_object.show_movies(1);
    } else if(answear == 2) {
        movie_collection_object.add_movie();
    } else if(answear == 3) {
        cout << std::endl << "ok edit it, bye" << endl << endl;
        display_actions(3);
    } else {
        display_actions(2);
        choose_action();
    }
}