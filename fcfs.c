#include <stdio.h>
#include <string.h>

int main(){
    int n, AT[100], b[100], i, j, tmp, WT[100], TAT[100], time[100];
    int TotWT=0, TotTA=0;
    float AvWT, AvTA;
    char name[20][20], tmpName[20];

    printf("\t Algoritma CPU Scheduling FCFS \n\n");
    printf("Jumlah Proses = "); 
    scanf("%d", &n);
    printf("\n");

    for(i=0; i<n; i++){
        printf("Nama Proses = "); 
        scanf("%s", name[i]);      // PERBAIKAN
        printf("Arrival time = "); 
        scanf("%d", &AT[i]);
        printf("Burst time = "); 
        scanf("%d", &b[i]);
        printf("\n");
    }

    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(AT[i] > AT[j]){
                strcpy(tmpName, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], tmpName);

                tmp = AT[i];
                AT[i] = AT[j];
                AT[j] = tmp;

                tmp = b[i];
                b[i] = b[j];
                b[j] = tmp;
            }
        }
    }

    time[0] = AT[0];

    printf("\n\t Tabel Proses\n");
    printf("==========================================\n");
    printf("| no | proses | arrival | burst |\n");
    printf("==========================================\n");

    for(i=0; i<n; i++){
        printf("| %2d | %s | %7d | %5d |\n", i+1, name[i], AT[i], b[i]);

        time[i+1] = time[i] + b[i];
        WT[i] = time[i] - AT[i];
        TAT[i] = time[i+1] - AT[i];
        TotWT += WT[i];
        TotTA += TAT[i];
    }

    printf("==========================================\n\n");

    printf("Total waiting time = %d\n", TotWT);
    printf("Total turn around time = %d\n\n", TotTA);

    printf("Gantt Chart:\n");
    for(i=0; i<n; i++){
        printf(" %s ", name[i]);
    }
    printf("\n");

    for(i=0; i<n; i++){
        printf("|========");
    }
    printf("|\n");

    for(i=0; i<=n; i++){
        printf("%d\t", time[i]);
    }
    printf("\n\n");

    AvWT = (float) TotWT / n;
    AvTA = (float) TotTA / n;

    printf("Average Waiting Time : %.2f\n", AvWT);
    printf("Average Turn Around Time : %.2f\n", AvTA);

    return 0;
}
