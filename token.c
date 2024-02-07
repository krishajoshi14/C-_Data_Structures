#include <stdio.h>
#include <unistd.h>

int main() 
{
    int token_bucket_size, token_rate, n;
    int tokens = 0;

    printf("Enter token bucket size, token rate, and number of requests: ");
    scanf("%d %d %d", &token_bucket_size, &token_rate, &n);

    while (n > 0) {
        int request_size;
        printf("Enter the request size: ");
        scanf("%d", &request_size);

        if (request_size <= token_bucket_size) {
            if (request_size <= tokens) {
                printf("Request of size %d granted. Sending data...\n", request_size);
                tokens -= request_size;
            } else {
                printf("Request of size %d denied. Insufficient tokens.\n", request_size);
            }
        } else {
            printf("Request of size %d is too large to be granted.\n", request_size);
        }

        // Simulate token replenishment (1 token per second)
        sleep(1);
        tokens += token_rate;
        if (tokens > token_bucket_size) {
            tokens = token_bucket_size; // Ensure the bucket doesn't overflow
        }

        n--;
    }

    return 0;
}