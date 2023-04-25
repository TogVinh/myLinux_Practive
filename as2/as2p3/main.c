#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

void softLink(char *pathfile, char *nameSyml)
{
    int sLink = symlink(pathfile, nameSyml);
    if (sLink == 0)
    {
        printf("Soft Link created successfuly\n");
    }

    else
    {
        printf("Soft Link created Fail \n");
    }
}

void hardLink(char *pathfile, char *nameHardl)
{
    int hLink = link(pathfile, nameHardl);
    if (hLink == 0)
    {
        printf("Hard Link was created succuessfuly \n");
    }
    else
    {
        printf("Hard Link created Fail\n");
    }
}

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;
    char nameSyml[20];
    char nameHardl[20];

    if (argc != 3)
    {
        printf("./file_run pathfile file\n");
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
        {
            printf("%s\n", dirp->d_name);
        }
    }

    // // tao syslink
    printf("input name of Soft Link : ");
    scanf("%s", nameSyml);

    printf("input name of Soft Link : ");
    scanf("%s", nameHardl);

    softLink(argv[1], nameSyml);
    hardLink(argv[1], nameHardl);

    // int symLink = symlink(argv[1], nameSyml);
    // if (symLink == 0)
    // {
    //     printf("Soft Link created successfuly\n");
    // }

    // else
    // {
    //     printf("\nsymlink created Fail \n");
    // }

    closedir(dp);
    return 0;
}