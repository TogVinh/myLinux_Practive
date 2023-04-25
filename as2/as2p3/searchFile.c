#include <dirent.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if (argc != 3)
    {
        printf("usage: ./out_Name dir_name file_name");
        return 0;
    }

    if ((dp = opendir(argv[1])) == NULL)
    {
        printf("can't open %s", argv[1]);
        return 1;
    }
    while ((dirp = readdir(dp)) != NULL)
    {
        if (!strcmp(dirp->d_name, argv[2]))
            printf("%s\n", dirp->d_name);
    }
    closedir(dp);
    return 0;
}
