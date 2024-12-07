#include <stdio.h>
#include <string.h>

struct Player{
    int ballScores[12];
    char playerName[20];
    int totalScore;
};

struct Player p1[1];
struct Player p2[1];

int playGame(struct Player*);
int validateScore(int);
int findWinner(struct Player*, struct Player*);
void displayboard(struct Player*, struct Player*);


int main(){
    printf("Enter Player 1 name: ");
    fgets(p1->playerName, sizeof(p1->playerName), stdin);
    p1->playerName[strcspn(p1->playerName, "\n")] = '\0';
    printf("Enter Player 2 name: ");
    fgets(p2->playerName, sizeof(p2->playerName), stdin);
    p2->playerName[strcspn(p2->playerName, "\n")] = '\0';

    playGame(p1);
    playGame(p2);
    findWinner(p1, p2);
    displayboard(p1, p2);
    printf("\n\t\t\t\tGAME ENDED\t\t\t\t\n");


    return 0;
}

int playGame(struct Player* player){
    for (int i = 0; i < 12; i++){
        printf("Enter %s's Score for ball %d: ", player->playerName, i+1);
        scanf(" %d", &player[0].ballScores[i]);
        player[0].ballScores[i] = validateScore(player[0].ballScores[i]);
        player[0].totalScore = player[0].totalScore + player[0].ballScores[i];
    }
    printf("\n\nTurn has ended..\n\n");
    for (int i = 0; i < 12;i++){
        printf("%d, ", player[0].ballScores[i]);
    }
    printf("\n\n");
    return 0;
}


int validateScore(int score){
    if (score >= 0 && score <= 6){
        return score;
    }
    return 0;
}

int findWinner(struct Player* player1, struct Player* player2){
    if (player1[0].totalScore > player2[0].totalScore){
        printf("\t\t\t\t%s Wins!\n\n", player1->playerName);
    }
    else{
        printf("\t\t\t\t%s Wins!\n\n", player2->playerName);
    }
}


void displayboard(struct Player* player1, struct Player* player2){
    int avg_score1, avg_score2;
    for (int i = 0; i < 12; i++){
        avg_score1 += player1[0].ballScores[i];
    }
    avg_score1 /= 12;
    for (int i = 0; i < 12; i++){
        avg_score2 += player2[0].ballScores[i];
    }
    avg_score2 /= 12;

    printf("\t\tP1     P2\n");
    for (int i = 0; i < 12; i++){
        printf("Ball %d Score: \t%d       %d\n", i+1,
        player1[0].ballScores[i], player2[0].ballScores[i]);
    }

    printf("Average Score: %d       %d\n", avg_score1, avg_score2);
    printf("Total Score:  %d        %d\n", player1[0].totalScore, 
    player2[0].totalScore);
}
