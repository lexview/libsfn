#include <stdio.h>

#include "sfn.h"


int main()
{
    struct sfn_t *sfn;

    sfn = sfn_create();
    sfn_load(sfn, "font0.sfn");

    fprintf(stdout, "Font:\n");
    fprintf(stdout, "\t.width = %d\n", sfn->width);
    fprintf(stdout, "\t.height = %d\n", sfn->height);

    sfn_dispose(sfn);

    return 0;
}