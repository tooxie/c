/*
 * You live in the city of Cartesia where all roads are laid out in a perfect
 * grid. You arrived ten minutes too early to an appointment, so you decided
 * to take the opportunity to go for a short walk. The city provides its
 * citizens with a Walk Generating App on their phones -- everytime you press
 * the button it sends you an array of one-letter strings representing
 * directions to walk (eg. ['n', 's', 'w', 'e']). You always walk only a single
 * block in a direction and you know it takes you one minute to traverse one
 * city block, so create a function that will return true if the walk the app
 * gives you will take you exactly ten minutes (you don't want to be early or
 * late!) and will, of course, return you to your starting point. Return false
 * otherwise.
 *
 * Note: you will always receive a valid array containing a random assortment
 * of direction letters ('n', 's', 'e', or 'w' only). It will never give you an
 * empty array (that's not a walk, that's standing still!).
 */
#include <stdbool.h>
#include <stdio.h>

bool isValidWalk(const char* walk) {
    int i = 0, x = 0, y = 0;
    while (walk[i] != '\0') {
        switch (walk[i]) {
            case 'n' : y++; break;
            case 's' : y--; break;
            case 'e' : x++; break;
            case 'w' : x--; break;
        }
        i++;
    }

    return (x == 0 && y == 0 && i == 9);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Invalid argument\n");
        return 1;
    }

    if(isValidWalk(argv[1])) {
        printf("Valid route\n");
        return 0;
    } else {
        printf("No good\n");
        return 2;
    }
}

/*
 * Top-voted solution:
 *
 * bool isValidWalk(const char *walk) {
 *   if (strlen(walk) != 10) return 0;
 *
 *   int h = 0, v = 0;
 *   while(*walk) {
 *     switch(*walk) {
 *       case 'n': ++v; break;
 *       case 's': --v; break;
 *       case 'e': ++h; break;
 *       case 'w': --h; break;
 *     }
 *     ++walk;
 *   }
 *   return h == 0 && v == 0;
 * }
 */
