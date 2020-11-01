#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#define SSIZE_MAX 10
/********************************************************************************
 *  Description:    1 Creat a TXT named test.txt 
 *                  2 Write a string in the TXT
 *                  3 Print the content 
 *                  4 Copy the TXT ,and named test.log
 *   Input Args:    None 
 *  Output Args:    the content of file <test.txt>
 * Return Value:    None
 ********************************************************************************/
int main(int argc, char **argv)
{
    int fd = 0;
    int fd1 = 0;
    char str[] = "0123456789";
    int len = 0;
    char buf[SSIZE_MAX];

    fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC);
    write(fd, str, strlen(str));
    close(fd);

    fd = open("test.txt", O_RDONLY);
    len = read(fd, buf, SSIZE_MAX);
    printf("str : %s\n", str);
    printf("buf : %s\nlen : %d\n", buf, len);
    printf("test.txt : %s\n", buf);

    fd1 = creat("test.log", 0644);
    write(fd1, buf, strlen(buf));

    close(fd);
    close(fd1);
    system("pause");
    return 0;
}