// Submite by:
// Amichai malle - ID: 308476977
// Eliav cohen   - ID:318191913

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct serie {
    char serieName[20];
    int numSeasons;
    int rank;
    int code;
    int* watchingDetails;
}serie;

void showMenu();
int unifyDatabase();
serie **getUnifyDatabaseDetails(int);
void printSeriesList(serie**, int);
void getWatchingDetails(serie** , int);
void printWatchingDetails();
void printSeriesByRank(serie** , int);
void makeSeriesFileSortedByRank(serie**, int);
int getNum();
int code_number_check(int , int , serie **);

int main() {
    int MenuChoice, Flag = 0;
    int series_num;
    struct serie **p;
    while (1) {
        showMenu();
        MenuChoice = getNum();
        switch (MenuChoice) {
            case 1: {
                if (Flag == 0) {
                    series_num = unifyDatabase();
                    Flag = 1;
                    break;
                } else {
                    printf("Unify Database Has Been Done Already !!!\n");
                }
                break;
            }
            case 2: {
                if (Flag == 2) {
                    printf("Unify Database Details Has Been Done Already !!!\n");
                    break;
                } else {
                    if (Flag == 1) {
                        p = getUnifyDatabaseDetails(series_num);
                        Flag = 2;
                    } else {
                        printf("You must unify database before using this option!!!\n");
                    }
                    break;
                }
            }
            case 3: {
                if (Flag == 2) {
                    printf("Series List\n");
                    printSeriesList(p, series_num);
                } else {
                    if (Flag == 1) {
                        printf("You must Get Unify Database Details before using this option!!!\n");
                    } else {
                        printf("You must unify database before using this option!!!\n");
                    }
                }
                break;
            }
            case 4: {
                if (Flag == 2) {
                    getWatchingDetails(p, series_num);
                    break;
                } else {
                    if (Flag == 1) {
                        printf("You must Get Unify Database Details before using this option!!!\n");
                    } else {
                        printf("You must unify database before using this option!!!\n");
                    }
                }
                break;

            }
            case 5: {
                if (Flag == 2) {
                    printWatchingDetails();
                    break;
                } else {
                    if (Flag == 1) {
                        printf("You must Get Unify Database Details before using this option!!!\n");
                    } else {
                        printf("You must unify database before using this option!!!\n");
                    }
                }
                break;
            }
            case 6: {
                if (Flag == 2) {
                    printSeriesByRank(p, series_num);
                    break;
                } else {
                    if (Flag == 1) {
                        printf("You must Get Unify Database Details before using this option!!!\n");
                    } else {
                        printf("You must unify database before using this option!!!\n");
                    }
                }
                break;
            }
            case 7: {
                if (Flag == 2) {
                    makeSeriesFileSortedByRank(p, series_num);
                    break;
                } else {
                    if (Flag == 1) {
                        printf("You must Get Unify Database Details before using this option!!!\n");
                    } else {
                        printf("You must unify database before using this option!!!\n");
                    }
                }
                break;
            }
            case 8: {
                printf("End Of The Program...\n");
                free(p);
                exit(0);
            }
            default:
                printf("Wrong Option, Try Again !!!\n");
                break;
        }
    }
    return 0;
}
void showMenu(){
    printf("**********Main Menu **************\n");
    printf("1. Unify Database.\n");
    printf("2. Get Unify Database Details.\n");
    printf("3. Print The Series List Sorted By Code.\n");
    printf("4. Get Watching Details.\n");
    printf("5. Show All Watching Details.\n");
    printf("6. Print Series Sorted By Rank.\n");
    printf("7. Make Series File Sorted By Rank.\n");
    printf("8. Exit.\n");
    printf("Enter Your Selection:");
}
int getNum(){
    int num;
    fscanf(stdin, "%d", &num);
    return num;
}

int readNextVld(FILE *file, serie *ptempSerie, int Read) {
    char VldSerie = 'N';
    if (Read != 1) return 0;
    while (VldSerie != 'Y') {
        if (fscanf(file, "%[^,]%*c%d%*c%d%*c%c%*c", ptempSerie->serieName, &ptempSerie->code, &ptempSerie->numSeasons,
                   &VldSerie) != EOF) {
        } else {
            ptempSerie->code = 1000;
            return -1;
        }
    }
    return 0;
}

int unifyDatabase() {
    FILE *fp1, *fp2;
    char f1[20], f2[20];
    int Flag1 = 0, Flag2 = 0;
    FILE *SeriesFile;
    int NumberOfSeries = 0;
    int Read1=1, Read2=1;
    serie *ptempSerie1, *ptempSerie2;
    ptempSerie1 = (serie*)malloc(sizeof(serie));
    ptempSerie2 = (serie*)malloc(sizeof(serie));
    while (Flag1 == 0) {
        printf("Enter First File Name: \n");
        fscanf(stdin, "%s", f1);
        fp1 = fopen(f1, "r");
        if (!fp1) {
            printf("error in opening file %s !!!\n", f1);
            Flag1 = 0;
        } else {
            Flag1 = 1;
            break;
        }
    }
    while (Flag2 == 0) {
        printf("Enter Second File Name: \n");
        fscanf(stdin, "%s", f2);
        fp2 = fopen(f2, "r");
        if (!fp2) {
            printf("error in opening file %s !!!\n", f2);
            Flag2 = 0;
        } else {
            Flag2 = 1;
            break;
        }
    }
    SeriesFile = fopen("series.txt", "w");
    while (readNextVld(fp1, ptempSerie1, Read1) != -1 && readNextVld(fp2, ptempSerie2, Read2) != -1) {
        if (ptempSerie1->code == ptempSerie2->code) {
            if (ptempSerie1->numSeasons > ptempSerie2->numSeasons) {
                fprintf(SeriesFile,"%s,%d,%d\n",ptempSerie1->serieName,ptempSerie1->code,ptempSerie1->numSeasons);
            } else {
                fprintf(SeriesFile,"%s,%d,%d\n",ptempSerie2->serieName,ptempSerie2->code,ptempSerie2->numSeasons);
            }
            Read1 = 1;
            Read2 = 1;
        } else if (ptempSerie1->code < ptempSerie2->code) {
            fprintf(SeriesFile,"%s,%d,%d\n",ptempSerie1->serieName,ptempSerie1->code,ptempSerie1->numSeasons);
            Read1 = 1;
            Read2 = 0;
        } else if (ptempSerie1->code > ptempSerie2->code) {
            fprintf(SeriesFile,"%s,%d,%d\n",ptempSerie2->serieName,ptempSerie2->code,ptempSerie2->numSeasons);
            Read1 = 0;
            Read2 = 1;
        }
        NumberOfSeries++;
    }
    free(ptempSerie1);
    free(ptempSerie2);
    fclose(SeriesFile);
    fclose(fp1);
    fclose(fp2);
    printf("Unify Succeeded\n");
    return NumberOfSeries;
}


serie **getUnifyDatabaseDetails(int series_num) {
    char serieName[20];
    int code, numSeasons;
    FILE *fp1, *fp2;
    fp1 = fopen("series.txt", "r");
    struct serie** p = (struct serie**)malloc(series_num * sizeof(struct serie*));
    for (int j = 0 ; j < series_num; j++) {
        p[j] = (struct serie *) malloc(sizeof(serie));}
    for (int i = 0; i < series_num; i++) {
        fscanf(fp1, "%[^,],%3d,%2d", serieName, &code, &numSeasons);
        strcpy(p[i]->serieName ,serieName );
        p[i]->numSeasons = numSeasons;
        p[i]->watchingDetails = (int *) malloc(sizeof(int) * numSeasons);
        for (int j = 0; j < numSeasons; j++) {
            p[i]->watchingDetails[j] = 0;
        }
        p[i]->rank = 0;
        p[i]->code = code;
        fgetc(fp1);//new line
        if (feof(fp1)) {
            break;
        }
    }
    fclose(fp1);
    fp2 = fopen("watching.txt", "w");
    printf("Get Unify Database Details Succeeded\n");
    fclose(fp2);
    return p;
}
void printSeriesList(serie** p, int series_num) {
    for (int i = 0; i < series_num; i++) {
        printf("%03d-%s(%d)\n", p[i]->code, p[i]->serieName, p[i]->numSeasons);
    }
    printf("\n");
}
void getWatchingDetails(serie ** p , int series_num) {
    FILE *fp1;
    int code, season, index;
    printf("Insert Serie Code:");
    code = getNum();
    while (code_number_check(code, series_num, p) == -1) {
        printf("wrong serie code, try again!!!\n");
        code = getNum();
    }
    index = code_number_check(code, series_num, p);
    printf("Insert Season Number (1 - %d):", p[index]->numSeasons);
    season = getNum();
    while (p[index]->numSeasons < season || season < 1) {
        printf("wrong season number, try again!!!\n");
        season = getNum();
    }
    printf("series: %d, season: %d accepted!!!\n", code, season);
    p[index]->watchingDetails[season - 1] += 1;
    p[index]->rank += 1;
    fp1 = fopen("watching.txt", "a");
    fprintf(fp1, "%03d,%d\n", code, season);
    fclose(fp1);
}
int code_number_check(int code, int series_num, serie **p) {
    for (int i = 0; i < series_num; i++){
        if (p[i]->code == code) {
            return i;
        }
    }
    return -1;
}
void printWatchingDetails(){
    FILE *fp1;
    int code, season;
    fp1 = fopen("watching.txt", "r");
    printf("Watching Details\n");
    while (1) {
        fscanf(fp1, "%d,%d", &code, &season);
        if (feof(fp1)) {
            break;
        }
        printf("Series Code:%03d, Season Number:%d\n", code, season);
    }
    fclose(fp1);

}
void printSeriesByRank(serie **p, int series_num) {
    int i, j;
    int highest_rank;
    struct serie temp;
    for (i = 0; i < series_num; i++) {
        for (j = i + 1; j < series_num; j++) {
            if (p[i]->rank < p[j]->rank) {
                temp = *p[i];
                *p[i] = *p[j];
                *p[j] = temp;
            }
        }
    }
    //sort the series by rank and then by code
    for (i = 0; i < series_num; i++) {
        for (j = i + 1; j < series_num; j++) {
            if (p[i]->rank == p[j]->rank) {
                if (p[i]->code > p[j]->code) {
                    temp = *p[i];
                    *p[i] = *p[j];
                    *p[j] = temp;
                }
            }
        }
    }
    highest_rank = p[0]->rank;
    //printf("Series By Rank:\n");
    for (i = 0; i < series_num; i++) {
        //print RANK just one for each rank from the highest to the lowest rank include in between
        if (i == 0) {
            printf("RANK %d\n", p[i]->rank);
        }
        while (p[i]->rank < highest_rank){
            printf("RANK %d\n", highest_rank - 1);
            highest_rank -= 1;
        }
        printf("%03d-%s\n", p[i]->code, p[i]->serieName);
        // print the watching details
        for (j = 0; j < p[i]->numSeasons; j++) {
            printf("Season %d:%d\n", j + 1, p[i]->watchingDetails[j]);
        }
    }
}
void makeSeriesFileSortedByRank(serie **p, int series_num){
    int i, j;
    struct serie temp;
    for (i = 0; i < series_num; i++) {
        for (j = i + 1; j < series_num; j++) {
            if (p[i]->rank < p[j]->rank) {
                temp = *p[i];
                *p[i] = *p[j];
                *p[j] = temp;
            }
        }
    }
    //sort the series by rank and then by code
    for (i = 0; i < series_num; i++) {
        for (j = i + 1; j < series_num; j++) {
            if (p[i]->rank == p[j]->rank) {
                if (p[i]->code > p[j]->code) {
                    temp = *p[i];
                    *p[i] = *p[j];
                    *p[j] = temp;
                }
            }
        }
    }
    FILE *fp1;
    fp1 = fopen("seriesRank.txt", "w");
    fclose(fp1);
    fp1 = fopen("seriesRank.txt", "a");
    for (i = 0; i < series_num; i++) {
        fprintf(fp1, "%03d(Rank:%d)-%s\n", p[i]->code, p[i]->rank, p[i]->serieName);
    }
    fclose(fp1);
}
