#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

#define strcut_newline(str) ((str)[strlen(str) - 1] == '\n') ? (str)[strlen(str) - 1] = '\0' : 0;
#define MAX 255

int main()
{
    DIR *dir;
    struct dirent *entry;
    char path[MAX] = {'0'};
    fflush(stdin);
    printf("nhap file path :  ");
    fgets(path, MAX, stdin);
    strcut_newline(path);

    dir = opendir(path); // mo thu muc
    char fullPath[MAX];

    if (dir)
    {
        while ( (entry = readdir(dir)) != NULL )
        {
            /* code */
                fullPath[0] = '\0';
                strcat(fullPath, path);
                strcat(fullPath, "/");
                strcat(fullPath, entry->d_name);
                printf("%s\n", fullPath);
        }

        closedir(dir);
    }
    else
    {
        printf("open Unsucessfully !!\n");
    }

    return 0;
}



// int main()
// {
//     DIR *dir;
//     struct dirent *entry;

//     if ((dir = opendir("/home/kane/workspace/Linux_Tranning")) == NULL)
//         perror("opendir() error");
//     else
//     {
//         puts("contents of root:");
//         while ((entry = readdir(dir)) != NULL)
//         {
            
//             printf("%s\n", entry->d_name);
//         }

//         closedir(dir);
//     }
// }