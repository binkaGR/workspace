#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>

#define TITLE_STRING  "title"


typedef enum Sizes

{
	TAG_SIZE    = 3,
	TITLE_SIZE  = 30,
	eMaxSize    = 31
} eSizes;



typedef enum Offsets

{
	TAG_OFFSET    = -128,
	TITLE_OFFSET  = -125,
	eMaxOffset    = 0
} eOffsets;


void getTitle(const int);
void setTitle(const int, char*, size_t );
static char buffer[eMaxSize] = {0};


int main(int argc, char **argv)
{
    pid_t childPid = 0;
    childPid = fork();
    while(1)
    {
	    if(childPid >= 0)
	    {
            if(childPid==0)
    	    {   
            int fd = open("Kalimba.mp3", O_RDONLY);
			getTitle(fd);
            (void) printf("%s\n", buffer);
            // Reinitialize the buffer to 0.
			memset(buffer, 0, sizeof(buffer));
            (void) sleep(3);
            (void) close(fd);
            }
            else
            {
                int fd = open("Kalimba.mp3", O_WRONLY);
                    char newTitle[TITLE_SIZE];
                    ssize_t newTitleLenght = read(0, newTitle, TITLE_SIZE);
                    newTitle[newTitleLenght - 1]= '\0';
                    setTitle(fd , newTitle, newTitleLenght);
                    (void) sleep(3);
                    (void) close(fd);
                    //childPid==0;
            
            }
        }
    }
	return 0;
}

void getTitle(const int fd)
{
	// Get the offset byte.
	(void) lseek(fd, TITLE_OFFSET, SEEK_END);
	// Read the data and put into buffer.
	(void) read(fd, buffer, sizeof(char) * TITLE_SIZE);
	// Remove the white-space characters.
	(void) strtok(buffer, " ");
}

void setTitle(const int fd, char* newTitle, size_t newTitleLenght)
{
    (void) lseek(fd, TITLE_OFFSET, SEEK_END);
    (void) write(fd, newTitle, newTitleLenght);
}
