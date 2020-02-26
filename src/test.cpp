#include <stdio.h>
#include <string.h>
#include <dirent.h>

void countFiles(char *basePath, const int root);

int main()
{
    // Directory path to list files
    char path[100];

    // Input path from user
    printf("Enter path to list files: ");
    scanf("%s", path);

    countFiles(path, 0);

    return 0;
}


void countFiles(char *basePath, const int root)
{
    int file = 0;
    int directory = 0;

    int i;
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    if (!dir) {
        return;
    }    

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            for (i=0; i<root; i++) 
            {
                if (i%2 == 0 || i == 0) {
                    directory++;
                }
                else {
                    printf("-");
                    file++;
                }

            }

            directory++;
            printf("%s\n", dp->d_name);

            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            countFiles(path, root + 2);
        }
    }

    closedir(dir);
}