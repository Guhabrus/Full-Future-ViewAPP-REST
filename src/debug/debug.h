#ifndef DEBUG_H
#define DEBIG_H

#define PRINT_DEBUG
#define PRINT_ERROR

#ifdef PRINT_DEBUG
    #include <stdio.h>
    #define print_debug(...) printf(__VA_ARGS__)
#else
    #define print_debug(...) do{}while(0)
#endif




#ifdef PRINT_ERROR
    #include <stdio.h>
    #define print_error(...) fprintf(stderr,__VA_ARGS__)
#else
    #define print_error(...) do{}while(0)
#endif

#endif