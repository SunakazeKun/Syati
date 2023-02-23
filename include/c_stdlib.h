#ifndef __C_STDLIB_H
#define __C_STDLIB_H

#ifdef __cplusplus
extern "C" {
#endif

/*
* math.h
*/
double cos(double x);
double sin(double x);
double tan(double x);
double acos(double x);
double asin(double x);
double atan(double x);
double atan2(double y, double x);

double frexp(double x, int *exp);
double ldexp(double x, int exp);
double log10(double x);
double scalbn(double x, int n);

double pow(double base, double exponent);
double sqrt(double x);

double ceil(double x);
double floor(double x);
double fmod(double numer, double denom);

double copysign(double x, double y);
// there is "double nan" as well but I'm not sure if it takes a parameter or not

/*
* signal.h
*/
int raise(int sig);

/*
* stdarg.h
*/
typedef struct va_list_struct {
	char gpr, fpr, reserved[2], * input_arg_area, * reg_save_area;
} va_list[1];

extern void* __va_arg(void*, int);

#define va_start(ap, last) (__builtin_va_info(&ap))
#define va_arg(ap, type) (*((type *)__va_arg(ap, _var_arg_typeof(type))))
#define va_end(ap) ((void)0)

/*
* stdio.h
*/
struct FILE;
typedef unsigned long size_t;

int fclose(FILE * stream);
int fflush(FILE * stream);

int fprintf(FILE *stream, const char *format, ...);
int snprintf(char *s, size_t n, const char *format, ...);
int sprintf(char *str, const char *format, ...);
int sscanf(const char *s, const char *format, ...);
int vprintf(const char *format, va_list arg);
int vsnprintf(char *s, size_t n, const char *format, va_list arg);
int vsprintf(char *s, const char *format, va_list arg);

long int ftell(FILE * stream);

/*
* stdlib.h
*/
int atoi(const char *str);
unsigned long int strtoul(const char *str, char **endptr, int base);

void free(void *ptr);

void abort();
void exit();

int abs(int n);

int mbtowc(wchar_t *pwc, const char *pmb, size_t max);

size_t mbstowcs(wchar_t *dest, const char *src, size_t max);
size_t wcstombs(char *dest, const wchar_t *src, size_t max);

/*
* string.h
*/
void* memcpy(void *destination, const void *source, size_t num);
void* memmove(void *destination, const void *source, size_t num);
char* strcpy(char *destination, const char *source);
char* strncpy(char *destination, const char *source, size_t num);

char* strcat(char *destination, const char *source);

int memcmp(const void *ptr1, const void *ptr2, size_t num);
int strcmp(const char *str1, const char *str2);
int strncmp(const char *str1, const char *str2, size_t num);
int strcasecmp(const char *str1, const char *str2); // not standard

const void* memchr(const void *ptr, int value, size_t num);
const char* strchr(const char *str, int character);
const char* strrchr(const char *str, int character);
const char* strstr(const char *str1, const char *str2);

void* memset(void * ptr, int value, size_t num);
size_t strlen(const char * str);

/*
* wchar.h
*/
int fwide(FILE *stream, int mode);
int swprintf(wchar_t *ws, size_t len, const wchar_t *format, ...);
int vswprintf(wchar_t *ws, size_t len, const wchar_t *format, va_list arg);

const wchar_t* wcschr(const wchar_t *ws, wchar_t wc);
int wcscmp(const wchar_t *wcs1, const wchar_t *wcs2);
wchar_t* wcscpy(wchar_t *destination, const wchar_t *source);
size_t wcslen(const wchar_t *wcs);
wchar_t* wcsncpy(wchar_t *destination, const wchar_t *source, size_t num);
const wchar_t* wmemchr(const wchar_t *ptr, wchar_t wc, size_t num);
int wmemcmp(const wchar_t *ptr1, const wchar_t *ptr2, size_t num);

#ifdef __cplusplus
}
#endif

#endif // __C_STDLIB_H
