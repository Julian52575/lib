/*
** EPITECH PROJECT, 2022
** my_get_file_size
** File description:
** return the file size in bytes
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

//returns the file size in bytes, and modify prev_sb if given
int get_file_size(char *file_path, struct stat *prev_sb)
{
    if (!prev_sb) {
        struct stat sb;
        if ( stat(file_path, &sb) == -1) return -84;
        return sb.st_size;
    } else {
        if ( stat(file_path, prev_sb) == -1) return -84;
        return prev_sb->st_size;
    }
}
