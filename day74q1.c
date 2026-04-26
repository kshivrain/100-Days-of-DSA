/*Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.*/
#include <stdio.h>
#include <string.h>

#define MAX 1000
#define NAME_LEN 50

int main() {
    int n;

    printf("Enter number of votes: ");
    scanf("%d", &n);

    char names[MAX][NAME_LEN];

    printf("Enter candidate names:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    char winner[NAME_LEN];
    int maxVotes = 0;

    for (int i = 0; i < n; i++) {
        int count = 1;

        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) == 0) {
                count++;
            }
        }

        if (count > maxVotes) {
            maxVotes = count;
            strcpy(winner, names[i]);
        } 
        else if (count == maxVotes) {
            if (strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("Winner: %s\n", winner);
    printf("Votes: %d\n", maxVotes);

    return 0;
}
