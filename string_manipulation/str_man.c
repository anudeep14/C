// 1.strcat : string concatenation (appending at end)
// 2.strchr : find the first occurance of character in the given string
// 3.strcmp : string compare
// 4.strcpy : string copy
// 5.strlen : string length
// 6.strncat : string concatenation for n bytes
// 7.strncmp : string compare for n bytes
// 8.strncpy : string compare for n bytes
// 9.strlcpy : string copy for a given length
// 10.strlcat : string concatenation for a given length
// 11.strrchr : find the last occurance of character in the given string
// 12.strstr : find a given substring in the given string

#include <stdio.h>
#include <string.h>

/**
 * appends the null terminated source string pointed to by src at the end of
 * char array pointed to by dest.
 * Undefined behavior if
 * 1. the destination string is not long enough to accommodate source string
 * 2. the destination and source string are overlapping
 * 3. either the dest is not a pointer to char array or src is not a pointer
 *    to a char array.
 * @param src constant pointer to a null terminated string.
 * @param dest pointer to the first element of char array
 * @return the modified destination string
 */
char* myStrCat(char* dest, const char* src)
{
   //implement graceful exist if undefined behaviour is encountered
   if((dest == NULL) || (src == NULL)) {
    printf("Dest / Src cannot be NULL");
    return NULL;
   }

   char* ptr = dest;
   ptr += strlen(dest);

   while(*src != '\0') {
    *ptr++ = *src++;
   }
   *ptr = '\0';

   return dest;
}

/**
 * strncat
 * concatenates no more than n bytes from a string to a dest buffer and returns the buffer
 * @param
 */
char* myStrnCat(char* dest, const char* src, size_t size) {

    if((dest == NULL) || (src == NULL)) {
        printf("Dest / Src cannot be NULL");
        return NULL;
    }
    char* ptr = dest;
    ptr += strlen(dest);

    

    while(size > 0 && *src != '\0') {
        *ptr++ = *src++;
        size--;
    }
    *ptr = '\0';
    return dest;    
}

/**
 * copies the null terminated byte string pointed to by src including null terminator to
 * the character array whose first element is pointed to by dest.
 * UB if:
 * 1. dest / src is NULL
 * 2. dest array is not large enough
 * 3. either dest or src overlap
 * 4. either dest is not pointing to frst element of char array or src is not pointing to null terminated string
 * @param src null terminated byte string pointed to by src
 * @param dest char array whose first element is pointed to by dest
 * @return modified destination string
 */
char* myStrCpy(char* dest, const char* src)
{
    if((dest == NULL) || (src == NULL)) {
        printf("dest / src cannot be NULL");
        return NULL;
    }

    char* ptr = dest;
    while(*src != '\0')
        *ptr++ = *src++;
    return dest;
}

/**
 * copies no more than n bytes of src string to the dest char buffer
 * 
 */
char* myStrnCpy(char* dest, const char* src, size_t size)
{
    if((dest == NULL) || (src == NULL)) {
        printf("dest / src cannot be NULL");
        return NULL;
    }

    char* ptr = dest;

    while (size > 0 && *src != '\0')
    {
    *ptr++ = *src++;
    size--;
    }
    return dest;
}

int main()
{
    char dest[15] = "Hello ";
    printf("Original char array: %s\n", dest);
    myStrCat(dest, "World");
    printf("Modified char array after myStrCat: %s\n\n", dest);

    char dest1[15] = "Cancer";
    printf("Original char array: %s\n", dest1);
    myStrCpy(dest1, "Dan");
    printf("Modified char array after myStrCpy: %s\n\n", dest1);

    char dest2[20] = "String";
    printf("Original char array: %s\n", dest2);
    myStrnCat(dest2, "Concatenated", strlen("Concatenate"));
    printf("Modified char array after myStrnCat: %s\n\n", dest2);

    char dest3[15] = "Hello";
    printf("Original char array: %s\n", dest3);
    myStrnCpy(dest3, "Character", strlen("Cha"));
    printf("Modified char array after myStrnCpy: %s\n\n", dest3);
    
    return 0;
}
