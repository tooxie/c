/*
 * Write a function called that takes a string of parentheses, and determines
 * if the order of the parentheses is valid. The function should return true if
 * the string is valid, and false if it's invalid.
 *
 * Examples
 * "()"              =>  true
 * ")(()))"          =>  false
 * "("               =>  false
 * "(())((()())())"  =>  true
 * Constraints
 * 0 <= input.length <= 100
 *
 * Along with opening (() and closing ()) parenthesis, input may contain any
 * valid ASCII characters. Furthermore, the input string may be empty and/or
 * not contain any parentheses at all. Do not treat other forms of brackets as
 * parentheses (e.g. [], {}, <>).
 */
#include <stdbool.h>

bool validParentheses(const char* strin)
{
    int c = 0;
    while(*strin) {
        switch(*strin) {
            case '(':
                c++; break;
            case ')':
                if (c == 0) return false;
                c--; break;
        }
        strin++;
    }

    return c == 0;
}

#include <stdio.h>
int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Invalid argument\n");
        return 1;
    }

    printf("%s\n", validParentheses(argv[1]) ? "true" : "false");
}

/*
 * Top-voted solution:
 *
 * #include <stdbool.h>
 *
 * bool validParentheses(const char* p) {
 *     int n = 0;
 *     for (; *p; p++) if ((n += (*p == '(') - (*p == ')')) < 0) break;
 *     return n == 0;
 * }
 */
