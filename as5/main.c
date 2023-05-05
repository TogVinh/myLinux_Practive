#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>

void *my_realloc(void *ptr, size_t size)
{
    unsigned char *old_ptr = (unsigned char *)ptr;
    void *new_ptr = NULL;
    size_t old_size = 0;
    if (!ptr) {
        return malloc(size);
    }
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    old_size = my_strlen_unsigned(old_ptr) + 1;
    new_ptr = malloc(size);
    if (!new_ptr) {
        return NULL;
    }
    my_memcpy(new_ptr, ptr, old_size < size ? old_size : size);
    free(ptr);
    return new_ptr;
}

void *my_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
    if (!dest || !src) return NULL;
    unsigned char *d = dest;
    const unsigned char *s = src;
    size_t i = 0;
    while (i < n && i < my_strlen_unsigned(s)) {
        *d = *s;
        d++;
        s++;
        i++;
    }
    return dest;
}

size_t my_strlen_unsigned(const unsigned char *s)
{
    size_t count = 0;
    if (s != NULL) {
        while (*s != 0) {
            count++;
            s++;
        }
    }
    return count;
}

size_t my_strlen(const char *s)
{
    size_t count = 0;
    if (s != NULL) {
        while (*s != 0) {
            count++;
            s++;
        }
    }
    return count;
}

char *my_str_clean(char *str)
{
    char *ptr = str;
    char *new_str = malloc(1);
    size_t i = 0;
    if (!new_str)
        return (NULL);
    while (*ptr) {
        if (*ptr != ' ' && *ptr != '\t' && *ptr != '\n') {
            new_str = my_realloc(new_str, (sizeof(char) * (i + 2)));
            new_str[i] = *ptr;
            i++;
        }
        ptr++;
    }
    new_str[i] = '\0';
    free(str);
    return (new_str);
}

int main(int argc, char **argv, char **env)
{
    char *test = malloc(15);
    test[0] = 'l';
    test[1] = 's';
    test[2] = ' ';
    test[3] = ' ';
    test[4] = ' ';
    test[5] = ' ';
    test[6] = ' ';
    test[7] = ' ';
    test[8] = ' ';
    test[9] = '-';
    test[10] = 'l';
    test[11] = ' ';
    test[12] = '-';
    test[13] = 'a';
    test[14] = '\0';
    char *clean = NULL;
    clean = my_str_clean(test);
    printf("%s\n", clean);
    free(clean);
}