struct sfn_t {
//    unsigend char id;
    unsigned char width;
    unsigned char height;

    unsigned char *data;
};

#define SFN_CHAR_COUNT  0x100

struct sfn_t* sfn_create(void);
int sfb_load(char *path);
int sfn_char(unsigned char ch, void *cb);
void sfn_dispose(struct sfn_t*);
