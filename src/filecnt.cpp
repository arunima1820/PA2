#include <stdio.h>  // c std i/o library
#include <string.h> // c string librarys
#include <iostream>
#include <sstream>
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

        // countFiles(in.c_str(), 0);
        stringstream result(popening(in, 1));
        result >> file;
    }

    void countFiles(const char *rootPath, const int level)
    {
        char path[1000];
        struct dirent *dp;
        DIR *dir = opendir(rootPath);

        if (!dir)
        {
            return;
        }

        directory++;

        while ((dp = readdir(dir)) != NULL)
        {
            if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
            {
                file++;

                strcpy(path, rootPath);
                strcat(path, "/");
                strcat(path, dp->d_name);

                countFiles(path, level + 2);
            }
        }

        closedir(dir);
    }

    string popening(string path, int option)
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
            command += " | egrep '^(d|-) | awk '{print $5}' | awk '{total += $0} END {print total}'";
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

    void print()
    {
        printf("The number of files in %s is: %d\n", in.substr(in.find_last_of('/')).c_str(), file);
        printf("The number of directories in %s is: %d\n", in.substr(in.find_last_of('/')).c_str(), directory);
        printf("The number of bytes in %s is: %d\n", in.substr(in.find_last_of('/')).c_str(), byte);
    }
};

// gets terminal input and parses it
// NOTE: function call is also an argument
int main(int argc, char **argv)
{
    filecnt f;

    f.addInput(argv[1]);
    f.print();

    return 0;
}