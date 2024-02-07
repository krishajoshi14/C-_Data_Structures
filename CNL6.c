#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>  // Add this header for the 'sleep' function

struct frame 
{
    char ack;
    int data;
} frm[10];

int n, r;

int sender(void);
void recvack(void);
void resend_sr(void);
void resend_gb(void);
void goback(void);
void selective(void);

//Go back N ARQ
void goback() {
    sender();
    recvack();
    resend_gb();
    printf("\nAll frames sent successfully\n");
}

//Selective repeat ARQ
void selective() {
    sender();
    recvack();
    resend_sr();
    printf("\nAll frames sent successfully\n");
}

int sender() {
    int i;

    printf("\nEnter the number of frames to be sent: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("\nEnter data for frame [%d]: ", i);
        scanf("%d", &frm[i].data);
        frm[i].ack = 'y';
    } 
    return 0;
}

//Receive Acknowledgement
void recvack() {
    int i;
    rand ();
    r= rand()%n;

    frm[r].ack='n';
    for ( i = 1; i <= n; i++)
    {
        if (frm[i].ack=='n')
        printf ("\n the frame %d is not recieved \n",r);
    }
    
}

void resend_sr() 
{
    printf("\nResend frame ");
    sleep(2);
    frm[r].ack = 'y';
    printf("\nThe received frame is %d\n", frm[r].data);
}

void resend_gb() 
{
    int i;
    printf("\nResending from frames:\n",r);
    for (i = 1; i <= n; i++)
    {
        sleep(2);
        frm[i].ack='y';
        printf("\nRecieved data of frame %d is %d", i, frm[i].data);
    }
}

int main() 
{
    int c;

    do {
        printf("\n\n1. Selective repeat ARQ\n2. Goback ARQ\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                selective();
                break;
            case 2:
                goback();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (c > 4);

    return 0;
}