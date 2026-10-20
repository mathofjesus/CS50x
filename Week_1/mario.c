#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int height;
    char input[128];

    while (1)
    {
        printf("Height: ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            return 1;
        }

        // Reject overlong lines instead of accepting a numeric prefix.
        int character;
        int too_long = 0;
        if (input[0] != '\0' && input[strlen(input) - 1] != '\n' && !feof(stdin))
        {
            too_long = 1;
            while ((character = getchar()) != '\n' && character != EOF)
            {
            }
        }

        errno = 0;
        char *end;
        long parsed_height = strtol(input, &end, 10);
        while (isspace((unsigned char) *end))
        {
            end++;
        }

        if (too_long || end == input || *end != '\0' || errno == ERANGE || parsed_height < 1 || parsed_height > 8)
        {
            continue;
        }

        height = (int) parsed_height;
        break;
    }

    for (int row = 0; row < height; row++)
    {
        for (int space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }
        for (int hash = 0; hash <= row; hash++)
        {
            printf("#");
        }
        printf("\n");
    }
}
