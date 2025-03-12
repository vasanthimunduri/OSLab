#include <stdio.h>

int main() {
    int rs[50], i, j, k, m, f, cntr[20], a[20], min, pf = 0, freq[20];

    printf("\nEnter number of page references -- ");
    scanf("%d", &m);

    printf("\nEnter the reference string -- ");
    for(i = 0; i < m; i++) {
        scanf("%d", &rs[i]);
    }

    printf("\nEnter the available number of frames -- ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) {
        a[i] = -1;
        cntr[i] = 0;
        freq[i] = 0;
    }

    printf("\nThe Page Replacement Process is – \n");
    for(i = 0; i < m; i++) {
        int found = 0;

        for(j = 0; j < f; j++) {
            if(rs[i] == a[j]) {
                freq[j]++;
                found = 1;
                break;
            }
        }

        if(!found) {
            min = 0;
            for(k = 1; k < f; k++) {
                if(freq[k] < freq[min]) {
                    min = k;
                }
            }
            a[min] = rs[i];
            freq[min] = 1;
            pf++;
        }

        printf("\n");
        for(j = 0; j < f; j++) {
            printf("\t%d", a[j]);
        }

        if(j == f) {
            printf("\tPF No. %d", pf);
        }
    }

    printf("\n\n Total number of page faults -- %d", pf);

    return 0;
}
