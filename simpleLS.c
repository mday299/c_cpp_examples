//for things like printf
#include<stdio.h>

#include <sys/types.h>
#include <dirent.h>

int main (int argc, char *argv[]) {
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2) {
        //Linux typically prints usage statements like this
        printf("usage: ls directory_name\n");
        return 1;
    }

    if ((dp = opendir(argv[1])) == NULL) {
        printf("can't open %s\n", argv[1]);
        return 2;
    }

    while ((dirp = readdir(dp)) != NULL)
        printf("%s\n", dirp->d_name);

    closedir(dp);

    //Returning zero tells the operating system there were no errors
    return(0);
}