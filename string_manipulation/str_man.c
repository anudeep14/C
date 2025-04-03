// 1.myStrCat  : string concatenation (appending at end)
// 2.myStrnCat : string concatenation no more than n bytes
// 3.myStrCpy  : string copy to a destination buffer
// 4.myStrnCpy : string compare for n bytes
// 5.myStrLen  : find the length of the string
// 6.myStrCmp  : Compare the two strings and return the difference
// 7.myStrnCmp : Compare the two strings no more than n bytes and return diff
// 8.myStrChr  : position of the character in the given string
// 9.strlcpy : string copy for a given length
// 10.strlcat : string concatenation for a given length
// 11.strrchr : find the last occurance of character in the given string
// 12.strstr : find a given substring in the given string

#include <stdio.h>

//forward declarations
int myStrLen(const char*);

/**
 * appends the null terminated source string pointed to by src at the end of
 * char array pointed to by dest.
 * Undefined behavior if
 * 1. the destination string is not long enough to accommodate source string
 * 2. the destination and source string are overlapping
 * 3. either the dest is not a pointer to char array or src is not a pointer
 *    to a char array.
 * @param dest pointer to the first element of char array
 * @param src constant pointer to a null terminated string.
 * @return modified destination buffer
 */
char* myStrCat(char* dest, const char* src)
{
   //implement graceful exist if undefined behaviour is encountered
   if((dest == NULL) || (src == NULL)) {
    printf("Dest / Src cannot be NULL");
    return NULL;
   }

   char* ptr = dest;
   ptr += myStrLen(dest);

   while(*src != '\0') {
    *ptr++ = *src++;
   }
   *ptr = '\0';

   return dest;
}

/**
 * strncat
 * concatenates no more than n bytes from a string to a dest buffer and returns the buffer
 * @param dest pointer to the first element of char array
 * @param src constant pointer to a null terminated string.
 * @param size size of the string ought to be copied
 * @return modified destination buffer
 */
char* myStrnCat(char* dest, const char* src, size_t size) {

    if((dest == NULL) || (src == NULL)) {
        printf("Dest / Src cannot be NULL");
        return NULL;
    }
    char* ptr = dest;
    ptr += myStrLen(dest);

    

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
 * @param dest char array whose first element is pointed to by dest
 * @param src null terminated byte string pointed to by src
 * @return modified destination buffer
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
 * @param dest char array whose first element is pointed to by dest
 * @param src null terminated byte string pointed to by src
 * @param size size of the string ought to be copied
 * @return modified destination buffer
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

/**
 * To find the length of the string, excluding the null character
 * @param src strig whose length is sought
 * @return length of the string
 */
int myStrLen(const char* src)
{
    if(src == NULL)
        printf("src cannot be NULL");

    int count = 0;
    while(*src++ != '\0')
        count++;
    
    return count;
}

/**
 * To compare both the strings
 * @param str1 string1
 * @param str2 string2
 * @return 0 if strings equal or
 *         (value) = difference between the first pair of characters that differ,
 *                   included with sign (less => - and more => +)
 */
int myStrCmp(const char* str1, const char* str2)
{
    if(str1 == NULL || str2 == NULL)
        printf("str1 / str2 cannot be NULL");
    
    while(*str1 && *str2) {
        if(*str1 == *str2) {
            str1++;
            str2++;
        } else {
            return *str1 - *str2; //returns lexicogrpahical diff
        }
    }
    return *str1 - *str2; //when one string is longer than other
}

/**
 * To compare two strings no more than n bytes
 * @param str1 string1
 * @param str2 string2
 * @return 0 if strings equal till size inputted or
 *         (value) = difference between the first pair of characters that differ,
 *                   included with sign (less => - and more => +)
 */
int myStrnCmp(const char* str1, const char* str2, size_t size)
{
    if(str1 == NULL || str2 == NULL)
        printf("str1 / str2 cannot be NULL");

    if(size < 0)
        printf("%ld size not valid", size);

    while ((size > 0) && (*str1 && *str2)) {
        if(*str1 == *str2) {
            str1++;
            str2++;
            size--;
        } else {
            return *str1 - *str2;
        }
    }
    return 0; //both strings are equal till the size inputted
}
/**
 * return the first occurance of character that is inputted
 * @param str input string
 * @param targetChar character if found to be returned
 * @return pointer to the input character found in string
 */
char* myStrChr(const char* str, int char_input)
{
    while((*str != '\0') || (*str == (unsigned char)char_input)) {
        if(*str == (unsigned char)char_input)
            return (char*)str; //return pointer to the char found
        str++;
    }
    return (char *)NULL; //target character not found
}

int main()
{
    //myStrCat
    char dest[15] = "Hello ";
    printf("Original char array: %s\n", dest);
    myStrCat(dest, "World");
    printf("Modified char array after myStrCat: %s\n\n", dest);

    //myStrCpy
    char dest1[15] = "Cancer";
    printf("Original char array: %s\n", dest1);
    myStrCpy(dest1, "Dan");
    printf("Modified char array after myStrCpy: %s\n\n", dest1);

    //myStrnCat
    char dest2[20] = "String";
    printf("Original char array: %s\n", dest2);
    myStrnCat(dest2, "Concatenated", myStrLen("Concatenate"));
    printf("Modified char array after myStrnCat: %s\n\n", dest2);

    //myStrnCpy
    char dest3[15] = "Hello";
    printf("Original char array: %s\n", dest3);
    myStrnCpy(dest3, "Character", myStrLen("Cha"));
    printf("Modified char array after myStrnCpy: %s\n\n", dest3);

    //myStrLen
    const char* str4 = "String Length";
    printf("Length of the string is %d\n\n", myStrLen(str4));

    //myStrCmp
    const char* str5 = "HelloA";
    const char* str6 = "Hello";
    int diff = myStrCmp(str5,str6);
    printf("%d\n",diff); // prints 'A' = 65.

    //myStrnCmp
    int diff1 = myStrnCmp(str5, str6,myStrLen(str6));
    printf("%d\n",diff1); // prints 0, since string length passed to compare only till "Hello"

    //myStrChr
    char target = 'l';
    const char* str7 = "Hello";
    char* ptr  = myStrChr(str7, target);
    if(ptr) {
        printf("%c\t%ld\n", *ptr, ptr-str7); //ptr-str7 prints the position of char starting from 0
    } else {
        printf("%c not found\n", target); //executes to print if char not part of string.
    }
    

    return 0;

}
