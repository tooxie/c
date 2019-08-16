/*
 * Given two cells on the standard chess board, determine whether they have the
 * same color or not.
 *
 * Example
 * For cell1 = "A1" and cell2 = "C3", the output should be true.
 * For cell1 = "A1" and cell2 = "H3", the output should be false.
 *
 * Input/Output
 * [input] string cell1
 * [input] string cell2
 * [output] a boolean value
 *
 * true if both cells have the same color, false otherwise.
 */
#include <stdbool.h>
#include <stdlib.h>

bool iseven(const int n)
{
    return n % 2 == 0;
}

bool isblack(const int col, const int row)
{
    return iseven(col) ? iseven(row) : !iseven(row);
}

int coltoi(char c)
{
    return (int)c;
}

int rowtoi(char c)
{
    const int A = 65;
    char row[] = {c, '\n'};
    return atoi(row) - A;
}

bool chess_board_cell_color(const char* cell1, const char *cell2)
{
    int col1 = coltoi(cell1[0]);
    int row1 = rowtoi(cell1[1]);
    int col2 = coltoi(cell2[0]);
    int row2 = rowtoi(cell2[1]);

    return isblack(col1, row1) == isblack(col2, row2);
}

#include <stdio.h>
int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("Invalid arguments\n");
        return 1;
    }

    printf("%s\n", chess_board_cell_color(argv[1], argv[2]) ? "true" : "false");
}

/*
 * Top-voted solution:
 *
 * #include <stdbool.h>
 * bool chess_board_cell_color(const char* cell1, const char *cell2)
 * {
 *   return !((cell1[0]^cell1[1]^cell2[0]^cell2[1])&1);
 * }
 */
