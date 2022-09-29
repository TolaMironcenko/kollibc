#ifndef IN_H
#define IN_H

struct in_addr {
    unsigned long s_addr;  // load with inet_aton()
};

struct sockaddr_in {
    short            sin_family;   // e.g. AF_INET
    unsigned short   sin_port;     // e.g. htons(3490)
    struct in_addr   sin_addr;     // see struct in_addr, below
    char             sin_zero[8];  // zero this if you want to
};

unsigned short htons(unsigned short a);


int inet_aton(const char *cp, struct in_addr *inp);
const char *inet_ntop(int af, const void *restrict src,
                             char *restrict dst, int size);

#endif // IN_H