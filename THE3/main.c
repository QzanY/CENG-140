#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "the3.h"


int main(int argc, char** argv)
{
    Cache* cache;
    Media media1,media5,media2;

    /* Create the cache */
    cache = createCache();

    /* Add new media */
    media1.name = "video1";
    media1.size = 200;
    addMediaRequest(cache,media1,"tr");
    media2.name = "video2";
    media2.size = 300;
    media5.name = "video4";
    media5.size = 600;
    addMediaRequest(cache,media2,"tr");
    addMediaRequest(cache,media1,"tr");
    addMediaRequest(cache,media1,"tr");
    addMediaRequest(cache,media1,"tr");
    addMediaRequest(cache,media2,"tr");
    addMediaRequest(cache,media2,"tr");
   


    printCache(cache);
    
    return 0;
}