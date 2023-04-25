
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>

void traverse(char *fn, int indent)
{
  DIR *dir;
  struct dirent *entry;
  int count;
  char path[1025];
  struct stat info;

  for (count = 0; count < indent; count++)
    {
    	printf("  ");
    }
  printf("%s\n", fn);

  if ((dir = opendir(fn)) == NULL)
    perror("opendir() error");
  else
  {
    while ((entry = readdir(dir)) != NULL)
    {
      if (entry->d_name[0] != '.')
      {
        strcpy(path, fn);
        strcat(path, "/");
        strcat(path, entry->d_name);
        if (stat(path, &info) != 0)
          fprintf(stderr, "stat() error on %s: %s\n", path,
                  strerror(errno));
        else if (S_ISDIR(info.st_mode))
          traverse(path, indent + 3);
      }
    }
    closedir(dir);
  }
}

int main()
{
  puts("Directory structure:");
  traverse("/home/kane/workspace", 0);
}



// int main (void)
// {
//   DIR *dp;
//   struct dirent *ep;

//   dp = opendir ("./");
//   if (dp != NULL)
//     {
//       while (ep = readdir (dp))
//       {
//         puts (ep->d_name);
//         printf("---------------\n");
//       }
//       closedir (dp);
//     }
//   else
//     perror ("Couldn't open the directory");

//   return 0;
// }
