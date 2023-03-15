/*
** EPITECH PROJECT, 2022
** get_nb_files.c
** File description:
** get_nb_files.c
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../include/server.h"
#include "../../include/response_messages.h"

char **get_files_in_dir(const char *dir_path, int *num_files)
{
    DIR *dir = opendir(dir_path);
    struct dirent *entry;
    int count = get_int(dir);
    char **filenames = (char **) malloc(count * sizeof(char *));
    count = 0;
    rewinddir(dir);
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0)
            continue;
        filenames[count] = (char *) malloc(strlen(entry->d_name) + 1);
        strcpy(filenames[count], entry->d_name);
        count++;
    }
    closedir(dir);
    *num_files = count;
    return filenames;
}
