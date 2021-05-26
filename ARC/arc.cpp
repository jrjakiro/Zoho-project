/*
*Driver program to test above functions
*/
int main(int argc, char **argv)
{
    FILE *fp;
    time_t start, stop;

    if (argc == 3)
    {
        /*argv[1] is the cache size*/
        /*argv[2] is the Trace File Name*/
        iCacheSize = strtol(argv[1], nullptr, 10);
        fileName = argv[2];
    }
    else
    {
        printf("Cache Size and Trace File Name not supplied properly.\nProgram Terminating\n");
        getchar();
        exit(-1);
    }

    printf("Cache Size = %d\n", iCacheSize);
    printf("TraceFile Name = %s\n", fileName);

    /*Initialize cache can hold c pages*/
    initARCCache(iCacheSize);

    fp = fopen(fileName, "r");
    if (fp == nullptr)
    {
        printf("Error while opening the file: %s\n", fileName);
        getchar();
        exit(EXIT_FAILURE);
    }

    unsigned int iStartingBlock = 0, iNumberOfBlocks = 0, iIgnore = 0, iRequestNumber = 0;
    unsigned int i = 0;
    unsigned int iTotalRequests = 0;
    time(&start);

    while (1)
    {
        if (-1 != fscanf(fp, "%u %u %u %u", &iStartingBlock, &iNumberOfBlocks, &iIgnore, &iRequestNumber))
        {
            //printf("%u-->%u\n", iRequestNumber, cache.mru.icount);
#if PRINTDEBUGS == 1
            //printf("%u\n", iRequestNumber);
#endif
            //printf("%u\t\t%u/%u\t\t%u/%u\t\t%u/%u\t\t%u/%u\n", iRequestNumber, cache->mru.icount, cache->mru.inumber_of_frames, cache->mrug.icount, cache->mrug.inumber_of_frames, cache->mfu.icount, cache->mfu.inumber_of_frames, cache->mfug.icount, cache->mfug.inumber_of_frames);
            for (i = iStartingBlock; i < (iStartingBlock + iNumberOfBlocks); i++)
            {
                iTotalRequests++;
#if PRINTDEBUGS == 1
                printf("***************************************************************\nRequested Page = %u\n***************************************************************\n", i);
#endif
                /*Call to check if page is in cache or not*/
                find(i);
#if PRINTDEBUGS == 1
                print_values();
#endif
            }
        }
        else
        {
            break;
        }
    }

    time(&stop);
    /*Print the important statistics about the result for cache hit and miss ratios*/
    printf("Miss Count = %u\n", imiss_count);
    printf("Hit Count = %u\n", ihit_count);
    //printf("imiss_count + ihit_count = %u\n", imiss_count + ihit_count);
    //printf("Total Requests = %u\n", iTotalRequests);
    printf("Hit Ratio = %5.4f %%\n", ((float)(ihit_count * 100) / (ihit_count + imiss_count)));
    printf("Rounded Hit Ratio = %5.2f %%\n", floor(((float)(ihit_count * 100) / (ihit_count + imiss_count)) * 100 + 0.5) / 100);
    printf("Finished in about %.0f seconds. \n", difftime(stop, start));

    getchar();
    return 0;
}