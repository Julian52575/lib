/*
//
//
//
*/

int my_is_alpha(char *str1, char *str2)
{
    int i = 0;
    while(1) {
        if (str1[i] == '\0')
            return 1;
        if (str2[i] == '\0')
            return 0;

        if(str1[i] > str2[i])
            return 0;
    }
}
