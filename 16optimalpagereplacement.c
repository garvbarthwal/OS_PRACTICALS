#include <stdio.h>

int main() {
    int pages[50], frame[10];
    int n, f, i, j, k, faults=0, flag;

    printf("Enter number of pages: ");
    scanf("%d",&n);

    printf("Enter page sequence: ");
    for(i=0;i<n;i++)
        scanf("%d",&pages[i]);

    printf("Enter number of frames: ");
    scanf("%d",&f);

    for(i=0;i<f;i++)
        frame[i] = -1;

    for(i=0;i<n;i++){
        flag = 0;

        for(j=0;j<f;j++){
            if(frame[j] == pages[i]){
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            int pos[10], replace_index=0;

            for(j=0;j<f;j++){
                int next = -1;
                for(k=i+1;k<n;k++)
                    if(frame[j] == pages[k]){
                        next = k;
                        break;
                    }
                pos[j] = next;
            }

            for(j=1;j<f;j++){
                if(pos[j] == -1){
                    replace_index = j;
                    break;
                }
                if(pos[j] > pos[replace_index])
                    replace_index = j;
            }

            frame[replace_index] = pages[i];
            faults++;
        }
    }

    printf("\nPage Faults: %d\n", faults);
    return 0;
}
