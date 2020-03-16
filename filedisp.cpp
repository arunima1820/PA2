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

    // std::cout << argc << std::endl;
    // for (int i = 0; i < argc; i++)
    //     std::cout << argv[i] << std::endl;

    char ch = argv[1][1];

    switch (ch)
    {
    case 'f':
        printf("The total number of files in %s is:   \t%s\n", argv[2], argv[3]);
        break;
    case 'd':
        printf("The total number of directories in %s is: \t%s\n", argv[2], argv[4]);
        break;
    case 'b':
        printf("The total number of bytes in %s is:   \t%s\n", argv[2], argv[5]);
        break;
        }
    return 0;
}