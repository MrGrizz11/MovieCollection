#ifndef _MOVIES_H_
#define _MOVIES_H_

#include "Movie.h"
#include <vector>

class Movies
{
public:
    std::vector<Movie> movie_list;

    void add_movie();
    void show_movies(int);
    void get_movie_collection();
};

#endif