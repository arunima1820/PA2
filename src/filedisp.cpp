/*
    Author:     Arunima Mittra
    Net ID:     AXM170025
    Course:     CS 3377.0W1 Spring 2020
    Assignment: PA 02
*/

#include <iostream>
#include <string>

// gets terminal input and parses it
// NOTE: function call is also an argument
int main(int argc, char **argv)
{

    std::cout << argc << std::endl;
    for (int i = 0; i < argc; i++)
        std::cout << argv[i] << std::endl;

    // printf("The total number of files in %s is:   \t%d\n", in.substr(in.find_last_of('/')).c_str(), file);
    // printf("The total number of directories in %s is: \t%d\n", in.substr(in.find_last_of('/')).c_str(), directory);
    // printf("The total number of bytes in %s is:   \t%d\n", in.substr(in.find_last_of('/')).c_str(), byte);

    return 0;
}