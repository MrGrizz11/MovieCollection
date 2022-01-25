#ifndef _HELPER_H_
#define _HELPER_H_

#include <fstream>
#include <string>

void choose_action();
void display_actions(int);
int get_movie_counter(int);
std::fstream& GotoLine(std::fstream& file, unsigned int num);
void add_movie_to_file(std::string, std::string, std::string, std::string);

#endif