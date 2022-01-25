#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>

class Movie
{
public:
    std::string show_name();
    std::string show_description();
    std::string show_rating();
    std::string show_views();

    Movie(std::string, std::string, std::string, std::string);
    ~Movie();

private:
    std::string name;
    std::string description;
    std::string rating;
    std::string views;
};

#endif // _MOVIE_H_
