#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void init(ticket_t *t)
{
    t->ticketno = 0;
    t->screen = 0;
    t->movie = (char *)calloc(30, sizeof(char));
    t->seat = (char *)calloc(2, sizeof(char));
    t->time = (char *)calloc(20, sizeof(char));
    t->date = (char *)calloc(20, sizeof(char));
    t->price = 0;
}

int ticketid = 100;

int selectoption(void)
{
    int choice;
    printf("  ==================================================\n");
    printf("                      EIC CINEMA\n");
    printf("  ==================================================\n");
    printf("||             1- Book ticket                       ||\n");
    printf("||             2- Cancel ticket                     ||\n");
    printf("||             3- View history                      ||\n");
    printf("||             4- View available seats              ||\n");
    printf("||             5- Exit                              ||\n");
    printf("  ==================================================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int selectmovie(ticket_t *t)
{
    int i;
    // system("cls");
    printf("\t\t\tWhich movie you want to see?\n");
    printf("\t\t\t----------------------------\n\n");
    printf("\t\t\tpress 1 for Lagan special\n\n");
    printf("\t\t\tpress 2 for Hurry Om Hurry\n\n");
    scanf("%d", &i);
    if (i == 1)
    {
        strcpy(t->movie,"Lagan special");
        t->price = 1000;
        t->screen = 1;
    }
    else if (i == 2)
    {
        strcpy(t->movie,"Hurry Om Hurry");
        t->price = 500;
        t->screen = 2;
    }

    int time;
    // printf("Available timeings:\n1. 10:00 to 13:00\n2. 14:00 to 17:00\n3. 19:00 to 22:00\n");
    printf("Available timings:\n1. 10:00 to 13:00\n");
    printf("Choose the time:");
    scanf("%d", &time);

    if (time == 1)
    {
        strcpy(t->time,"10:00 to 13:00");
    }

    // else if (time == 2)
    // {
    //  t->time = "14:00 to 17:00";
    // }

    // else if (time == 3)
    // {
    //  t->time = "19:00 to 22:00";
    // }
    
    else
    {
        printf("Invalid choice\n");
    }

    return i;
}

char seatchar(int i)
{
    return i <= 4 ? 'A' : i <= 9 ? 'B'
                      : i <= 14  ? 'C'
                      : i <= 19  ? 'D'
                      : i <= 24  ? 'E'
                      : i <= 29  ? 'F'
                      : i <= 34  ? 'G'
                      : i <= 39  ? 'H'
                      : i <= 44  ? 'I'
                                 : 'J';
}

int str_to_int(char c[])
{
    int offset = 0;
    char a = c[0];
    offset = (a == 'A' ? 0 : a == 'B' ? 1
                         : a == 'C'   ? 2
                         : a == 'D'   ? 3
                         : a == 'E'   ? 4
                         : a == 'F'   ? 5
                         : a == 'G'   ? 6
                         : a == 'H'   ? 7
                         : a == 'I'   ? 8
                                      : 9);

    return offset * 5 + (c[1] - '0') - 1;
}

void print_available_seats(int *array)
{
    int i;
    printf("\n\t\tSCREEN\n\n\n");
    for (i = 0; i < 50; i++)
    {
        char c = seatchar(i);

        if (i % 5 == 0 && i != 0)
        {
            printf("\n\n");
        }

        if (array[i] == 0)
        {
            printf("%c%d\t", c, (i % 5) + 1);
        }

        else
        {
            printf("\t");
        }
    }

    printf("\n");
}

void reservation(int *array, ticket_t *t)
{
    int16_t i;
    char seat[2];

    print_available_seats(array);

    printf("Which seat number you want? ");
    scanf("%s", seat);
    int arrayseat = str_to_int(seat);

    // if (!(seat[0] >= 'A' && seat[0] <= 'J') || !(seat[1] >= 1 && seat[1] <= 5) || array[arrayseat] == 1)
    // {
    //  printf("Seat unavailable\n");
    // }

    // else
    // {
    array[arrayseat] = 1;
    t->seat = seat;
    printf("Your total amount=%d\n", t->price);
    // printf("Press 'y/n' to confirm:");
    // char l;
    // scanf("%c", &l);

    // if (l == 'y')
    // {
    tickets[ticketid % 100] = *t;
    t->ticketno = ticketid++;
    strcpy(t->date,"14/02/2024");
    print_ticket(t);
    // }
    // }
}

// void cancel(int *array)
void cancel(int **seat)
{
    int Cseat, i, stop;
    printf("Please enter ID number of ticket: ");
    scanf("%d", &Cseat);
    for (i = 0; i < 100; i++)
    {
        if (Cseat == tickets[i].ticketno)
        {
            stop = 5;
            // system("cls");
            printf("%d seat has been cancelled\n", tickets[i].ticketno);
            int screen = tickets[i].screen;
            int *arr;
            if (screen == 1)
                arr = seat[0];
            else
                arr = seat[1];
            int s = str_to_int(tickets[i].seat);
            arr[s] = 0;
            i = 100;
        }
    }
    if (stop != 5)
        printf("Ticket ID number is incorrect please enter right one to cancel ticket: \n");
}

void print_ticket(ticket_t *t)
{
    system("cls");
    printf("\n\n");
    printf("\t==============================================================\n");
    printf("\t|------------------------EIC CINEMA--------------------------|\n");
    printf("\t==============================================================\n");
    printf("\t Ticket No: %d \t\t\t\tMovie Ticket\n", t->ticketno);
    printf("\t==============================================================\n");
    printf("\t Screen: %d\t\t\t\t\t%s\n", t->screen, t->movie);
    printf("\t Seat: %c/%c\n", t->seat[0], t->seat[1]);
    printf("\t Tim: %s\n", t->time);
    printf("\t Date: %s\t\t\t\tPrice: %d\n", t->date, t->price);
    printf("\t==============================================================\n");
    printf("\t==============================================================\n");
    return;
}
