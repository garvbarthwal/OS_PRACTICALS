#include <stdio.h>

int main() 
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n];
    
    // Input
    for(int i = 0; i < n; i++) {
        printf("Enter PID, AT, BT: ");
        scanf("%d %d %d", &pid[i], &at[i], &bt[i]);
    }

    // Sort by arrival time (simple bubble sort)
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(at[j] < at[i]) {
                int temp;

                temp = at[i]; at[i] = at[j]; at[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = pid[i]; pid[i] = pid[j]; pid[j] = temp;
            }
        }
    }

    // Calculations
    int time = 0;
    for(int i = 0; i < n; i++) {

        if(time < at[i])
            time = at[i]; // CPU idle wait

        ct[i] = time + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        time = ct[i];
    }

    // Output
    printf("\nPID  AT  BT  CT  TAT  WT\n");
    for(int i = 0; i < n; i++) {
        printf("%d   %d   %d   %d   %d    %d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
