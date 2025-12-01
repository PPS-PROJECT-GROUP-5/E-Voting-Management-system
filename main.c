#include <stdio.h>
#include <stdlib.h>
#include "evoting.h"

int main() {
    int n, m, choice;

    printf("Enter number of voters: ");
    scanf("%d", &n);

    printf("Enter number of candidates: ");
    scanf("%d", &m);

    Voter *voters = (Voter *) malloc(n * sizeof(Voter));
    Candidate *candidates = (Candidate *) malloc(m * sizeof(Candidate));

    registerVoters(voters, n);
    registerCandidates(candidates, m);

    while (1) {
        printf("\n===== ELECTRONIC VOTING SYSTEM =====\n");
        printf("1. Cast Vote\n");
        printf("2. Show Results\n");
        printf("3. Graphical Results\n");
        printf("4. Save Results\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: castVote(voters, n, candidates, m); break;
            case 2: showResults(candidates, m, voters, n); break;
            case 3: showGraphicalResults(candidates, m, voters, n); break;
            case 4: saveResultsToFile(candidates, m, voters, n); break;
            case 5: printf("Exiting...\n"); return 0;
            default: printf("Invalid Input!\n");
        }
    }
    return 0;
}
