#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include<string.h>

#define strcut_newline(str)  ((str)[strlen(str) - 1] == '\n') ? (str)[strlen(str) - 1] = '\0':0;
//remove "\n" of fgets function

int main(void)
{
    //DIR *d;
    //struct dirent *dir;
    //char path[500]="/home/kane/workspace/Linux_Tranning";
    //char path[5000] = {'0'};
    // printf("nhap path file \n");
    // fgets(path, 200, stdin);
    // //fgets(path, 200, stdin);
    // strcut_newline(path);
    
    //d = opendir(path);
    //char full_path[500];
    //if (d)
    //{
        //while ((dir = readdir(d)) != NULL)
        //{
            // Condition to check regular file.
            //if(dir->d_type==DT_REG){
                //full_path[0]='\0';
                //strcat(full_path,path);
                //strcat(full_path,"/");
                //strcat(full_path,dir->d_name);
                //printf("%s\n",full_path);
            //}
        //}
        //closedir(d);
    //}
    //return(0);   


     DIR *dr;
    struct dirent *en;
    dr = opendir("."); //open all or present directory
    if (dr) {
       while ((en = readdir(dr)) != NULL) {
          printf("%s\n", en->d_name); //print all directory name
       }
       closedir(dr); //close all directory
    }
    return(0);
}
