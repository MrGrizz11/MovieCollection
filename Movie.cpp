#include "Movie.h"

Movie::Movie(std::string movie_name, std::string movie_description, std::string movie_rating, std::string movie_views)
    : name{movie_name}
    , description{movie_description}
    , rating{movie_rating}
    , views{movie_views}
{
}

std::string Movie::show_name()
{
    return name;
}

std::string Movie::show_description()
{
    return description;
}

std::string Movie::show_rating()
{
    return rating;
}

std::string Movie::show_views()
{
    return views;
}

Movie::~Movie()
{
}
