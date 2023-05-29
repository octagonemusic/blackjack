#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Game of Blackjack

// draw a card
int drawCard()
{
    // generate a random number between 1 and 10

    int card = rand() % 10 + 1;
    // return the card
    return card;
}

void main()
{
    // draw card for user
    // draw card for dealer
    srand(time(NULL));
    int userCards = drawCard();
    int dealerCards = drawCard();
    int newCard;
    char choice[] = "hit";

    printf("Your total: %d\n", userCards);
    printf("Dealer's total: %d\n", dealerCards);
    printf("Do you want to hit or stay?\n\nYour choice: ");
    scanf("%s", choice);

    for (int i = 0; choice[i]; i++)
    {
        choice[i] = tolower(choice[i]);
    }

    while (strcmp(choice, "hit") == 0)
    {
        newCard = drawCard();
        userCards = userCards + newCard;
        printf("\n--------------------\n\n");
        printf("You drew a %d\n\n", newCard);
        printf("Your total: %d\n", userCards);
        printf("Dealer's total: %d\n", dealerCards);
        if (userCards >= 21)
        {
            break;
        }
        else
        {
            printf("Do you want to hit or stay?\n\nYour choice: ");
            scanf("%s", choice);
            for (int i = 0; choice[i]; i++)
            {
                choice[i] = tolower(choice[i]);
            }
        }
    }

    printf("\n--------------------\n\n");

    if (userCards > 21)
    {
        printf("Your total has exceeded 21! You've been busted!\n");
    }
    else if (userCards == 21)
    {
        printf("Your total has hit exactly 21! You have won 1.5x your bet!\n");
    }
    else
    {
        printf("You've chosen to stay. Dealer's turn.\n");
        printf("\n--------------------\n\n");
        while (dealerCards < 17)
        {
            dealerCards += drawCard();
        }

        printf("Your total: %d\n", userCards);
        printf("Dealer's total: %d\n", dealerCards);
        printf("\n--------------------\n\n");

        if (dealerCards > 21)
        {
            printf("Dealer's total has exceeded 21! You've won!\n");
        }
        else if (dealerCards == 21)
        {
            printf("Dealer's total has hit exactly 21! You've lost!\n");
        }
        else
        {
            if (userCards > dealerCards)
            {
                printf("Your total is higher than the dealer's! You've won!\n");
            }
            else if (userCards < dealerCards)
            {
                printf("Your total is lower than the dealer's! You've lost!\n");
            }
            else
            {
                printf("Your total is equal to the dealer's! It's a tie!\n");
            }
        }
    }
}