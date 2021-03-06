#include "saturn_engine/core/_lib.h"

// public
char* saten_get_filepath(const char *fn)
{
    char *res =
        (char*)malloc(strlen(saten_base_path)+1+strlen(fn));
    if (res == NULL) {
        return NULL;
    }
    saten_strcpy(res, saten_base_path);
    saten_strcat(res, fn);
    return res;
}

// public
void* saten_malloc(size_t size)
{
    void *ptr = NULL;
    ptr = malloc(size);
    if (ptr == NULL) {
        saten_killf = true;
        saten_errhandler(7);
    } else {
        memset(ptr, 0, size);
    }
    return ptr;
}

// public
char* saten_strclone(char *str)
{
    int l = strlen(str) + 1;
    char *newstr = saten_malloc(l * sizeof(char));
    return (char*) memcpy(newstr, str, l);
}

// public
char* saten_strappuniq(char *str, char c)
{
    // Only appends c if last character in str is not c
    int l = strlen(str) + 1;
    if (str[l-2] == c)
        return str;
    str = saten_realloc(str, sizeof(char) * l+1);
    str[l] = str[l-1]; // Move terminating character
    str[l-1] = c;
    return str;
}

// public
void* saten_realloc(void* ptr, size_t size)
{
    ptr = realloc(ptr, size);
    if (ptr == NULL) {
        saten_killf = true;
        saten_errhandler(7);
    }
    return ptr;
}

// public
bool saten_test_rgb(uint8_t r, uint8_t g, uint8_t b, uint8_t t)
{
    return (r == t && g == t && b == t);
}

// public
bool saten_test_rgbi(SDL_Color inp, SDL_Color test)
{
    return (
            (inp.r == test.r) &&
            (inp.g == test.g) &&
            (inp.b == test.b) &&
            (inp.a == test.a));
}

// public
// https://stackoverflow.com/a/3068420
size_t saten_intlen(int a)
{
    int8_t add = 1;
    if (a < 0)
        add += 1;
    if (a == 0)
        return 1;
    else
        return floor(log10(abs(a))) + add;
}

// private
int saten_square(int a)
{
    return a * a;
}

// private
void saten_strcpy(char *str1, const char *str2)
{
#ifdef _WIN32
    strcpy_s(str1, strlen(str2)+1, str2);
#else
    strcpy(str1, str2);
#endif
}

// private
void saten_strcat(char *str1, const char *str2)
{
#ifdef _WIN32
    strcat_s(str1, strlen(str1)+strlen(str2)+1, str2);
#else
    strcat(str1, str2);
#endif
}

// private
struct tm* saten_localtime( const time_t *timer)
{
#ifdef _WIN32
    struct tm *tm = (struct tm*)saten_malloc(sizeof(struct tm));
    localtime_s(tm, timer);
    return tm;
#else
    // not thread safe as localtime uses a single internal buffer
    return localtime(timer);
#endif
}

// private
void saten_fopen(FILE **fp, const char *filename, const char *mode)
{
    //FIXME error checking
#ifdef _WIN32
    fopen_s(fp, filename, mode);
#else
    *fp = fopen(filename, mode);
#endif
    if (*fp == NULL) {
#ifdef _DEBUG
        fprintf(stderr, "[%s]\n", filename);
#endif
        saten_errhandler(39);
    }
}

// public
SDL_Point saten_coords_from_arrindex(int i, int pitch)
{
    if (pitch < 1) {
        saten_errhandler(72);
        saten_killf = true;
        pitch = 1;
    }

    SDL_Point pos;
    pos.x = i % pitch;
    pos.y = floor(i/pitch);
    return pos;
}

// public
bool saten_inrange(int n, int min, int max)
{
    return ((n >= min) && (n <= max));
}

// public
bool saten_sdlpntcmp(SDL_Point *p1, SDL_Point *p2)
{
    return ((p1->x == p2->x) && (p1->y == p2->y));
}

