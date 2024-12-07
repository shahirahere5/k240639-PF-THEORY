#include <stdio.h>
#include <stdlib.h>

struct Employee{
    int* rating;
    int totalScore;
};

struct Employee Employees;

void inputEmployees(int** ratings, int numEmployees, int numPeriods);
void displayPerformance(int** ratings, int numEmployees, int numPeriods);
int findEmployeeOfTheYear(int** ratings, int numEmployees, int numPeriods);
int findHighestRatedPeriod(int** ratings, int numEmployees, int numPeriods);
int findWorstPerformingEmployee(int** ratings, int numEmployees, int numPeriods);



int main(){
    int numE, numP;
    printf("Enter number of Employees: ");
    scanf(" %d", &numE);
    printf("Enter number of Evaluation Periods: ");
    scanf(" %d", &numP);

    int** ratings = malloc(sizeof(int*)*numE);
    for (int i = 0; i < numE; i++){
        ratings[i] = malloc(sizeof(int)*numP);
    }

    inputEmployees(ratings, numE, numP);
    displayPerformance(ratings, numE, numP);

    printf("\nEmployee of the Year Index: %d\n", 
    findEmployeeOfTheYear(ratings, numE,numP));

    printf("\nHighest Rated Period Index: %d\n", 
    findHighestRatedPeriod(ratings, numE, numP));

    printf("\nWorst Rated Employee Index: %d\n", 
    findWorstPerformingEmployee(ratings, numE, numP));

    for (int i = 0; i < numE; i++){
        free(ratings[i]);
    }
    free(ratings);

    return 0;
}

void inputEmployees(int** ratings, int numEmployees, int numPeriods){
    int rate;
    for (int E = 0; E < numEmployees; E++){
        for (int P = 0; P < numPeriods; P++){
            printf("Enter Rating for Employee %d in period %d: ", 
            E+1, P+1);
            scanf(" %d", &rate);
            if (rate >= 1 && rate <= 10){
                ratings[E][P] = rate;
            }
            else{
                ratings[E][P] = 0;
            }
        }
        printf("\n");
    }
}


void displayPerformance(int** ratings, int numEmployees, int numPeriods){
    for (int E = 0; E < numEmployees; E++){
        printf("Employee %d:", E+1);
        for (int P = 0; P < numPeriods; P++){
            printf("\t%d\t", ratings[E][P]);
        }
        printf("\n");
    }
}


int findEmployeeOfTheYear(int** ratings, int numEmployees, int numPeriods){
    double avg = 0, max = 0;
    int index;
    for (int E = 0; E < numEmployees; E++){
        avg = 0;
        for (int P = 0; P < numPeriods; P++){
            avg += ratings[E][P];
        }
        if (avg > max){
            max = avg;
            index = E;
        }
    }
    return index+1;
}

int findHighestRatedPeriod(int** ratings, int numEmployees, int numPeriods){
    double avg = 0, max = 0;
    int index;
    for (int P = 0; P < numPeriods; P++){
        avg = 0;
        for (int E = 0; E < numEmployees; E++){
            avg += ratings[E][P];
        }
        if (avg > max){
            max = avg;
            index = P;
        }
    }
    return index+1;
}


int findWorstPerformingEmployee(int** ratings, int numEmployees, int numPeriods){
    double avg = 0, min = 100;
    int index;
    for (int E = 0; E < numEmployees; E++){
        avg = 0;
        for (int P = 0; P < numPeriods; P++){
            avg += ratings[E][P];
        }
        if (avg < min){
            min = avg;
            index = E;
        }
    }
    return index+1;
}
