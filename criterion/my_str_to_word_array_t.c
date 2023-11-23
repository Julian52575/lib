/*
** Rulian PROJECT, 2023
** Str to word array Criterion
** File description:
** my_str_to_word_array_t
*/

#include <criterion/criterion.h>
#include <unistd.h>

/*
 * Note: These tests assumes that the array always
 *  ends with a null pointer
*/

char **my_str_to_word_array(char *str);

static char *build_string(char *str)
{
    char *new = malloc( strlen(str) );
    int i = 0;


    if (!new) {
        (void) write(2, "Ya plus malloc.\n", 16);
        return NULL;
    }
    for (int i = 0; str[i]; i++) {
        new[i] = str[i];
    }
    new[i] = '\0';
    return str;
}


Test(Null, Null_string_as_argument)
{
    cr_assert( my_str_to_word_array( NULL ) == NULL );
}

Test(No_Delimiter, No_delimiter_in_argument)
{
    char **array = NULL;
    char *str = build_string("Hello");
    
    if (!str)
        return;
    array = my_str_to_word_array(str);
    cr_assert_not_null( array );
    cr_assert_str_eq( array[0], str);
    cr_assert_null( array[1] );
    free(str);
}

Test(Hello_World_Banane, Hello_World_Banane)
{
    char **array = NULL;
    char *str = build_string("Hello\nWorld\nBanane");

    if (!str)
        return;
    array = my_str_to_word_array( str );
    cr_assert_not_null( array );
    cr_assert_str_eq( array[0], "Hello" );
    cr_assert_str_eq( array[1], "World" );
    cr_assert_str_eq( array[2], "Banane" );
    cr_assert_null( array[3] );
    free(str);
}
