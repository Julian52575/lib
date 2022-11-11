/*
** EPITECH PROJECT, 2022
** my str to word array
** File description:
** Flat str becomes huge array
*/


char **my_str_to_word_array(char const *str)
{
    int a = 0;
    int s = 0;
    char **array = malloc(strlen(str) * 10);
    char *string = malloc(strlen(str));
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n'|| str[i] == ' ') {
            string[s++] = '\0';
            array[a] = malloc(strlen(string) + 1);
            my_strcpy(array[a++], string);
      
            free(string);
            string = malloc(strlen(str+i));
            s = 0;
            continue;
        }
        string[s++] = str[i];
    }
    string[s] = '\0';
    array[a] = string;
    return array;
}
