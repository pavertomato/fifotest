#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include "led.h"

int main(int argc, char * argv [] )
{
    int r_fifo, w_fifo; 

    std::string fifo;

    if(argc>1)
        fifo=argv[1];
    else
        fifo="./fif";

    unlink(fifo.c_str());
    if((mkfifo(fifo.c_str(), 0666)) == -1)
    {
        perror("fifo create"); 
        return 2;
    }

    Led led;
    char buf[45];
    
    while(true)
    {
        if (( r_fifo=open(fifo.c_str(), O_RDONLY))<0)
        {
            perror("r_fifo open");
            return 2;       
        }     
        int rx_length=read(r_fifo, &buf, sizeof(buf));
        buf[rx_length] = '\0';
        std::string input(buf);
        const char *buffer=led.textCommand(input).c_str();    
        close(r_fifo);
        
        if((w_fifo=open(fifo.c_str(), O_WRONLY))<0)
        {
            perror("w_fifo open");  
            return 2;     
        }
        write(w_fifo, buffer, strlen(buffer));
        close(w_fifo);
            
    }
  return 0;
} 
