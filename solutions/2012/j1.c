#include <stdio.h>

int main() {
    int limit, recorded;
    printf("Enter the speed limit: ");
    scanf("%d", &limit);
    printf("Enter the recorded speed of the car: ");
    scanf("%d", &recorded);
    if (recorded <= limit) {
        printf("Congratulations, you are within the speed limit!\n");
    } else if (recorded <= limit + 20) {
        printf("You are speeding and your fine is $100.\n");
    } else if (recorded <= limit + 30) {
        printf("You are speeding and your fine is $270.\n");
    } else {
        printf("You are speeding and your fine is $500.\n");
    }
    return 0;
}