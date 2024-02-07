#include<stdio.h>
#include<stdbool.h>
#define MAX_FRAMES 100
#define MAX_PAGES 100

int frames[MAX_FRAMES];
int page_list[MAX_PAGES];
int n_frames,n_pages;
int page_faults=0;

//returns the index of the frame that contains the least recently used page

int get_lru_frame(int *counters)
{
    int lru_frame=0;
    int min_count=counters[0];

    for(int i=1;i<n_frames;i++)
    {
        if(counters[i]<min_count)
        {
            lru_frame=i;
            min_count=counters[i];
        }
    }
    return lru_frame;
}

int main()
{
    printf("Enter the number of frames:");
    scanf("%d",&n_frames);
    printf("Enter the number of pages:");
    scanf("%d",&n_pages);
    printf("Enter the page reference string:");
    for(int i=0;i<n_pages;i++)
    {
        scanf("%d",&page_list[i]);
    }

    int counters[MAX_FRAMES]={0};
    bool is_page_fault=true;

    //loop through each page in the page reference string
    for(int i=0;i<n_pages;i++)
    {
        is_page_fault=true;

        //check if page is already in one of the frames

        for(int j=0;j<n_frames;j++)
        {
            if(frames[j] == page_faults)
            {
                int lru_frame= get_lru_frame(counters);
                frames[lru_frame]=page_list[i];
                counters[lru_frame]=i;
                page_faults++;
            }
        }
        //print the current state of the frames after processing the current page

        printf("Page %d", page_list[i]);
        for(int j=0;j<n_frames;j++)
        {
            printf("%d",frames[j]);
        }
        printf("\n");
    }

    printf("Total pages faults: %d\n", page_faults);
    return 0;
}