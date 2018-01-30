#include "seq.h"

int pattern[16] = {91000, 90000, 90050, 90000,
                   91100, 90000, 90050, 90000,
                   91000, 90000, 90050, 90000,
                   91100, 90000, 90050, 90000};

int main(int argc, char *argv[]) {
    int i = 0;

    while (i < 16) {
        printf("%d\n", pattern[i]);
        fflush(stdout);
        i++;
        usleep(100000);
    }

    return 0;
}
