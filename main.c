#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char minus[] = {
    "   "
    "___"
    "   ",
};
char *lcd[10] = {
    " _ "
    "| |"
    "|_|",
    "   "
    "  |"
    "  |",
    " _ "
    " _|"
    "|_ ",
    " _ "
    " _|"
    " _|",
    "   "
    "|_|"
    "  |",
    " _ "
    "|_ "
    " _|",
    " _ "
    "|_ "
    "|_|",
    " _ "
    "  |"
    "  |",
    " _ "
    "|_|"
    "|_|",
    " _ "
    "|_|"
    "  |",
};

int main(int argc, char **argv)
{
    if (argc != 2) {
        fputs("You need to provide 2 arguments.", stderr);
        return 1;
    }

    errno = 0;
    char *end = NULL;
    strtol(argv[1], &end, 10);

    if (*end || errno) {
        fprintf(stderr, "Cannot convert \"%s\" to a long.", argv[1]);
        return 1;
    }

    char const *number = argv[1];
    size_t number_length = strlen(number);

    for (int row = 0; row < 3; ++row) {
        for (int i = 0; i < number_length; ++i) {
            char *c = (number[i] == '-') ? minus : lcd[number[i] - '0'];
            printf("%.3s", c + row * 3);
        }

        printf("\n");
    }

    fflush(stdout);

    return 0;
}
