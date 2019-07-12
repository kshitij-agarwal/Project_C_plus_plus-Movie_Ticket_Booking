/*

Problem Statement:

A Cinema booking system by making use of linked lists. You have to perform the following three actions in order to simulate the cinema booking system
1. User should be able to view both occupied and available seats
2. User can book ticket and booked ticket should be marked as occupied in the list
3. User can cancel the ticket and cancelled ticket should be marked as available



TODO: Add feature - book random seats in the beginning.
TODO: Add feature - cancellation feature
TODO: Add feature - Price quotation   

*points to remember/improve/add:

1. to keep a track of number of seats being occupied
2. gfg - GeeksForGeeks.

 */

// #include <cdoex.h>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cctype>
#include <stdlib.h>

using namespace std;

void display();
void welcome();
void input();
void exit1();
string check(string x);

//To keep a track of number of seats as a case is possible that user is trying to book the 8 seats and only 3 are avaliable
int seatsLeft = 94;
int tickets = 0;
string seat[11][11]
{
    {"\b", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J"},
    {"0", "*", "*", "*", "#", "#", "#", "#", "*", "*", "*"},
    {"1", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"2", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"3", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"4", "#", "#", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"5", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"6", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"7", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"8", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
    {"9", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"},
};

void display()
{
    cout << "\n\n";
    for (int i = 0; i < 11; i++)
    {
        if (i == 1) 
        {
            cout << endl;
            // cout << "\t\t\t\t\tRs. 250\n";
        }

        //* Price Variation
        // if (i==2)
        // {
        //     cout << endl;
        //     cout << "\t\t\t\t\tRs. 200\n";
        // }
        // if (i==7)
        // {
        //     cout << endl;
        //     cout << "\t\t\t\t\tRs. 150\n";
        // }

        for (int j = 0; j < 11; j++)
        {
            cout << seat[i][j] << "\t";
        }
        cout << endl;
    }
}

void welcome()
{
    cout << "\n\nWelcome to the Cinema Ticket Booking Portal\n\n\n"
         << "Some points to be taken into consideration:\n\n"
         << "1. * represents the avaliable seats.\n"
         << "2. # represents the occupied seats.\n"
         << "3. First you have to enter the number of seats you want to book (not more than 10 at a time).\n"
         << "4. Secondly you need to enter the each seat no. individually in the following format. \n"
         << "\t4.1. First will be the column no. and then the row no. For example:- D0, F7, e2, g6. \n"
         << "\t4.2. No space in between column no. and row no.\n"
         << "\t4.3. If any other seat number is entered which doesn't exist or already booked has to be entered again.\n"
         << "\t4.4. Once a seat has been booked it cannot be cancelled.\n";
}

void input()
{
    string seat_check = "";
    string temp_seat = "";

    // to store the position of the tickets;
    string tkt_pos[tickets];
    // int size_tkt_pos = *(&tkt_pos + 1) - tkt_pos;   //from gfg
    // cout<<"\nsize of array = " << size_tkt_pos;

    for (int i = 0; i < tickets; i++)
    {
        do
        {
            cout << "\nEnter the " << (i + 1) << " seat no. = ";
            cin >> temp_seat;
            seat_check = check(temp_seat);
            if (seat_check != "OK")
                cout << endl
                     << seat_check;

        } while (seat_check != "OK");
        // book the ticket
        tkt_pos[i] = temp_seat;
        seatsLeft--;
        seat[(int)(temp_seat[1]) - 48 + 1][(int)(toupper(temp_seat[0])) - 64] = "#";
        cout << "Voila";
    }
    cout << "\n\n";
    display();
    cout << "\n\nYou have booked " << tickets << " tickets.\n";
    cout << "Seats: ";
    for (size_t i = 0; i < tickets; i++)
    {
        cout << tkt_pos[i] << "  ";
    }
    // from here it will go to main()

}

string check(string x)
{
    // check the following conditions:
    // length of the string should be two
    // ischar and isdigit
    // is the seat number is correct or not
    // is the seat occupied or not

    // To check the length of the input
    if (x.length() == 2)
    {
        // to check if the format is right or not
        int temp_alpha = toupper(x[0]);
        int temp_dig = x[1];
        if ( (temp_alpha>=65 && temp_alpha<=90) && (temp_dig>=48 && temp_dig<=57))
        {
            if (toupper(x[0]) >= 'A' && toupper(x[0]) <= 'J')
            {
                // to check if the input is in range
                if (seat[(int)(x[1]) - 48 + 1][(int)(toupper(x[0])) - 64] == "*")
                {
                    return "OK";
                }
                else
                {
                    return "The seat is occupied!!";
                }
            }
            else
            {
                return "The range is from A to J. That's it!!";
            }
        }
        else
        {
            return "Enter in the correct format";
        }
    }
    else
    {
        return "You just had to enter two characters!!";
    }
}

void exit1()
{    
    
    cout<<"\n\nThank you.";

    cout << endl
         << endl;
    exit(1);
}

int main()
{
    char rep;
    welcome();

    cout << "\nHope you are here to book tickets and not to check the prices. \n#IndianMentality ";
    cout << "\n\nHit Y to continue or N to exit = ";
    cin >> rep;
    if (rep == 'N' || rep == 'n')
    {
        exit1();
    }
    // put here if condition (seatsleft>0) if we need to add cancellation feature along with random seat allocation.
    do
    {
        cout << "Total " << seatsLeft << " seats are left.\n";
        cout << "Enter the number of tickets you want to book = ";
        cin >> tickets;
        if (tickets > 10)
        {
            cout << "Read rule number 3!!\n\n";
        }

    } while (tickets > 10 || tickets > seatsLeft);

    cout << "";
    display();
    input();

    cout << endl
         << endl;
    return 0;
}
