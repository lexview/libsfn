#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>

#include "sfn.h"



struct sfn_t*
sfn_create()
{
    struct sfn_t* sfn;

    sfn = (struct sfn_t*)malloc(sizeof(struct sfn_t));
    if (sfn != NULL) {
        sfn->width = 0;
        sfn->height = 0;
    }

    return sfn;
}

int sfn_load(struct sfn_t* sfn, char *path)
{
    FILE *pFile;
    size_t size;

    // Open file
    pFile = fopen(path, "rb");
    if (pFile == NULL) {
        return -1;
    }

    // Determine font size
    fseek(pFile, 0L, SEEK_END);
    size = ftell(pFile);
    fseek(pFile, 0L, SEEK_SET);

    // Populate font structure
    sfn->width = 8;
    sfn->height = size / SFN_CHAR_COUNT;

    sfn->data = (unsigned char *)malloc(SFN_CHAR_COUNT * sfn->height * sfn->width);

    fread(sfn->data, sfn->height * SFN_CHAR_COUNT, 1, pFile);

    fclose(pFile);

    return 0;
}

int sfn_char(unsigned char ch, void *cb)
{
    register int cx, cy;
    char bm;

//    for(cy=0; cy < font[id].height; cy++) {
//        bm = *(font[id].data + (font[id].width*font[id].height>>3)*ch + (font[id].width>>3)*cy);

//        for(cx=0; cx < font[id].width; cx++) {
//            if ( bm>>cx & 1) 
                //cb ... (display, window, gc, x + font[id].width-cx, y + cy);
//        }
//    }

    return 0;
}

void sfn_dispose(struct sfn_t* sfn)
{
    if (sfn != NULL) {
        if (sfn->data != NULL) {
            free(sfn->data);
        }
        free(sfn);
    }
}
