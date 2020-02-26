/*
    Author:     Arunima Mittra
    Net ID:     AXM170025
    Course:     CS 3377.0W1 Spring 2020
    Assignment: PA 02
*/

#include <stdio.h>  // c std i/o library
#include <string.h> // c string librarys
#include <iostream>
#include <sstream>  // string stream library to convert string to int
#include <dirent.h> // library to enter directories

using namespace std;

class filecnt
{
private:
    int directory;
    int file;
    int byte;

    string in;

public:
    // constructor
    filecnt()
    {
        directory = -1;
        file = 0;
        byte = 0;
        in = "";
    }

    // getters
    int dirCount() { return directory; }
    int fileCount() { return file; }
    int byteCount() { return byte; }
    string input() { return in; }

    void addInput(string s)
    {
        in += s;

        if (in.empty())
            return;

        // File count
        stringstream fileFinder(countFiles(in, 1));
        fileFinder >> file;

        // Directory count
        stringstream dirFinder(countFiles(in, 2));
        dirFinder >> directory;

        // Byte count
        stringstream byteFinder(countFiles(in, 3));
        byteFinder >> byte;
    }

    string countFiles(string path, int option)
    {
        string command = "ls -lR " + path;
        if (option == 1) // files
        {
            command += " | grep '^-' | wc -l";
        }
        else if (option == 2) // directories
        {
            command += " | grep '^d' | wc -l";
        }
        else if (option == 3) // bytes
        {
            command += " | egrep '^(d|-)' | awk '{print $5}' | awk '{total += $0} END {print total}'";
        }

        string data;
        FILE *stream;
        const int max_buffer = 256;
        char buffer[max_buffer];
        command.append(" 2>&1");

        stream = popen(command.c_str(), "r");
        if (stream)
        {
            while (!feof(stream))
                if (fgets(buffer, max_buffer, stream) != NULL)
                    data.append(buffer);
            pclose(stream);
        }
        return data;
    }

    void print(string path)
    {
        addInput(path);

        
        printf("%d %d %d", file, directory, byte);
    }
};

// gets terminal input and parses it
// NOTE: function call is also an argument
int main(int argc, char **argv)
{
    filecnt f;
    f.print(argv[1]);

    return 0;
}