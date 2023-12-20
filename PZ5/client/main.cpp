#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>	/* for clock_gettime */

#define BILLION 1000000000L
#define PORT 8080

struct my_data{
    timespec time_receive;
    timespec time_transmit;
};
int main(int argc, char const* argv[])
{
    int status, valread, client_fd;
    struct sockaddr_in serv_addr;
    uint64_t diff_tx, diff_rx;
    timespec cur_time;

    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
 
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
 
    // Convert IPv4 and IPv6 addresses from text to binary
    // form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)
        <= 0) {
        printf(
            "\nInvalid address/ Address not supported \n");
        return -1;
    }
 
    if ((status
         = connect(client_fd, (struct sockaddr*)&serv_addr,
                   sizeof(serv_addr)))
        < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    my_data data;

    clock_gettime(CLOCK_MONOTONIC, &data.time_transmit);	/* mark start time */

    send(client_fd, &data, sizeof(data), 0);
    
    valread = read(client_fd, &data, sizeof(data)); // subtract 1 for the null terminator at the end
    
    clock_gettime(CLOCK_MONOTONIC, &cur_time);
    diff_tx = BILLION * (data.time_receive.tv_sec - data.time_transmit.tv_sec) + data.time_receive.tv_nsec - data.time_transmit.tv_nsec;
	diff_rx = BILLION * (cur_time.tv_sec - data.time_receive.tv_sec) + cur_time.tv_nsec - data.time_receive.tv_nsec;

    printf("ping tx = %llu nanoseconds\nping_rx = %llu nanoseconds\n\n", (long long unsigned int) diff_tx, (long long unsigned int) diff_rx);
 
    // closing the connected socket
    close(client_fd);
    return 0;
}