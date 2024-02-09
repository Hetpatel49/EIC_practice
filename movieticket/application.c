#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main()
{
    tickets = (ticket_t *)calloc(100, sizeof(ticket_t));
    int **seat, choice, price = 500, selected_seat, i;
    seat = (int **)calloc(2, sizeof(int *));
    for (i = 0; i < 2; i++)
        *(seat + i) = (int *)calloc(50, sizeof(int));
    int x;
    ticket_t *t = (ticket_t *)calloc(1, sizeof(ticket_t));
    init(t);

    while (x != 5)
    {
        choice = selectoption();
        switch (choice)
        {
        case 1:
        {
            int selected_seat;
            selected_seat = selectmovie(t);
            reservation(seat[selected_seat - 1], t);
            break;
        }

        case 2:
        {
            cancel(seat);
            break;
        }

        case 3:
            break;

        case 4:
        {
            printf("Screen 1:Lagan special\nScreen 2: Hurry Om Hurry\nEnter Screen No.: ");
            int screen;
            scanf("%d", &screen);
            if (screen == 1)
                print_available_seats(seat[0]);
            else if (screen == 2)
                print_available_seats(seat[1]);
            else
                printf("Invalid choice\n");
            break;
        }

        case 5:
        {
            x = 5;
            break;
        }

        default:
        {
            printf("Choice not available\n");
            break;
        }
        }
    }
}
