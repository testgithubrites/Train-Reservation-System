#include <iostream>
#include <string.h>
#include <fstream>
#include <windows.h>
#include <unistd.h>
#include <iomanip> //including header files
using namespace std;
static int p = 0;// declaring a variable and fixing its value as 0

class a  //declaring class
{
    char Train_no[10],Train_Name[100],arrive[5], depart[5], from[10], to[10], seat[8][4][10], Ticket_Price[10]; //declaring variables of type class
    int x=25,y=25;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

public:
    void install();
    void allotment();                                         
    void empty();
    void show();
    void avail();
    void position(int i);
    //declaring public functions
} 
Train[10];       //object of class
void vline(char ch)
{
    for (int i = 80; i > 0; i--)
        cout << ch;
}
void a::install()
{
    SetConsoleTextAttribute(h,11);
    //installing train by entering its important credentials
    cout << "Enter Train no:     \t ";
    cin >> Train[p].Train_no;
    
    cout<< "Enter Train Name:  \t";
    cin>> Train[p].Train_Name;

    cout << "\nArrival Time: \t\t";
    cin >> Train[p].arrive;

    cout << "\nDeparture Time: \t"; 
    cin >> Train[p].depart;

    cout << "\nFrom: \t\t\t";
    cin >> Train[p].from;

    cout << "\nTo: \t\t\t";
    cin >> Train[p].to;

    cout<<"\nTicket Price: \t\t";
    cin>>Train[p].Ticket_Price;


    cout << "\n";
    Train[p].empty(); // checking if the train is empty or not
    p++;
    std::cout << "Your Train is installing";

    sleep(1);
    std::cout << "." << std::flush;
    sleep(1);
    std::cout << "." << std::flush;
    sleep(1);
    std::cout << "." << std::flush;
    sleep(1);
    std::cout << "\b\b\b   \b\b\b" << std::flush;
    sleep(2);
    cout<<"\nTrain Installed!"<<endl;
}
void a::allotment() // function for alloting a seat to a passanger
{
    SetConsoleTextAttribute(h,11);
    int seat;
    char op;
    char number[10],name[100],depart1[5],arrive1[5],to1[10],from1[10];
    cout<<"Proceed to Reserve your seat(y/n)..." ;
    cin>>op;
    while(op=='y'||op=='Y')
    {
        cout<<"\nWant to reserve more than this seat?"<<endl<<"y for Yes or n for No  -  " ;

        cin>>op;
        top: //working using stack!
        SetConsoleTextAttribute(h,3);

        cout << "Train no.: ";
        cin >> number;
        
        cout << "Train Name:";
        cin >> name;
		
		cout << "From:";
		cin >> from1;
		
		cout << "To:";
		cin >> to1;
		
		cout << "Arrival Time";
		cin >> arrive1;
		 
		cout << "Departure time";
		cin >> depart1; 

        int n;
        for (n = 0; n <= p; n++)
        {
            if (strcmp(Train[n].Train_no, number) == 0) /*checking if the value of train no in the loop and the number entered is equal
                                                          to zero or not if yes breaking the loop*/
                break;
        }
        ofstream new_file;
        new_file.open("Train.txt",ios::app);
        while (n <= p)
        {
            cout << "\nSeat Number: "; //entering the seat number we want to allot
            cin >> seat;
            if (seat > 100) //if the seat no entered is more that 100, then printing that there are only 100 seats available/
            {
                cout << "\nThere are only 100 seats available in Train Coach.";
            }
            else //if not, then alloting the seat by inputing the passanger's name
            {
                if (strcmp(Train[n].seat[seat / 4][(seat % 4) - 1], "Empty") == 0)
                {
                    cout << "Enter passanger's name: ";
                    cin >> Train[n].seat[seat / 4][(seat % 4) - 1];
                    //int l=0;
                    new_file<<"Seat no. "<<"\t|\t"<<" Train no. "<<"\t|\t"<<"Name : \n"<<"\t|\t"<<"Train name "<<"\t|\t"<<"From"<<"\t|\t"<<"To"<<"\t|\t"<<"Arrival Time"<<"\t|\t"<<"Departure Time";   //Writing to file
                    new_file<<" "<<seat<<"\t        |\t        "<<number<<"\t|\t\t"<<Train[n].seat[seat / 4][(seat % 4) - 1]<<"\t|\t\t"<<name<<"\t|\t\t"<<from1<<"\t|\t\t"<<to1<<"\t|\t\t"<<arrive1<<"\t|\t\t"<<depart1<<endl;
                    new_file.close();

                    std::cout << "Reserving your seat ";

                    sleep(1);
                    std::cout << "." << std::flush;
                    sleep(1);
                    std::cout << "." << std::flush;
                    sleep(1);
                    std::cout << "." << std::flush;
                    sleep(1);
                    std::cout << "\b\b\b   \b\b\b" << std::flush;
                    sleep(2);
                    cout<<"\nSeat Reserved!! \n"<<endl;
                    break;
                }
                else
                    cout << "The seat no. is already reserved.\n";
            }
            if (n > p) //if the number entered for train is more than the number of trains we have, then printing to input the correct train no/
            {
                cout << "Enter correct Train no.\n";
                goto top;
            }
            else
            {
                cout << "\nSeat Number: "; //entering the seat number we want to allot
                cin >> seat;
                if (seat > 100) //if the seat no entered is more that 100, then printing that there are only 100 seats available/
                {
                    cout << "\nThere are only 100 seats available in this Train.";
                }
                else //if not, then alloting the seat by inputing the passanger's name
                {
                    goto top;
                }
            }
            SetConsoleTextAttribute(h,14);
            vline('-');
            cout<<endl;
        }
    }
}

void a::empty() //function for checking that seat is empty or not
{
    SetConsoleTextAttribute(h,11);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 4; j++)
            strcpy(Train[p].seat[i][j], "Empty");
    }
}

void a::show() //function for showing how many seats are available in a particular bus
{
    SetConsoleTextAttribute(h,11);
    int n;
    char number[5];

    cout << "\nEnter Train no.: ";
    cin >> number;

    for (n = 0; n <= p; n++)
    {
        if (strcmp(Train[n].Train_no, number) == 0)
            break;
    }
    std::cout << "Loading Please Wait ";
    sleep(1);
    std::cout << "." << std::flush;
    sleep(1);
    std::cout << "." << std::flush;
    sleep(1);
    std::cout << "." << std::flush;
    sleep(1);
    std::cout << "\b\b\b   \b\b\b" << std::flush;
    sleep(2);
    cout<<"\n";


    while (n <= p) //checking condition
    {
        SetConsoleTextAttribute(h,14);
        vline('*');
        SetConsoleTextAttribute(h,13);
        cout << "\nTrain no: \t" << Train[n].Train_no
             << "\nTrain Name: \t"<< Train[n].Train_Name 
             << "\tArrival time: \n"<< Train[n].arrive
             << "\n\tDeparture time: \n" << Train[n].depart
             << "\nFrom: \t\t" << Train[n].from
             << "\tTo: \t\t" << Train[n].to
             << "\nTicket Price: \t\t" << Train[n].Ticket_Price
			 << "\n";//printing the values of all the credentials
        SetConsoleTextAttribute(h,13);
        vline('*');
        cout<<"\n";
        Train[0].position(n); //calling position function
        int a = 1;

        SetConsoleTextAttribute(h,11);
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                a++;
                if (strcmp(Train[n].seat[i][j], "Empty") != 0)
                    cout << "\nSeat no " << (a - 1) << " is reserved for " << Train[n].seat[i][j] << "." << endl;
            }
        }
        break;
    }
    if (n > p)
        cout << "Enter correct Train no: ";
}

void a::position(int l) //function to set position
{
    int s = 0;
    p = 0;
    SetConsoleTextAttribute(h,11);

    for (int i = 0; i < 8; i++)
    {
        cout << "\n";
        for (int j = 0; j < 4; j++)
        {
            s++;
            if (strcmp(Train[l].seat[i][j], "Empty") == 0) /*comparing values of seat and value in the nested loop
      and checking if it is equal to zero or not*/
            {
                cout.width(8);
                cout.fill(' ');
                cout << s << ".";
                cout.width(12);
                cout.fill(' ');
                cout << Train[l].seat[i][j];
                p++;
            }
            else
            {
                cout.width(8);
                cout.fill(' ');
                cout << s << ".";
                cout.width(12);
                cout.fill(' ');
                cout << Train[l].seat[i][j];
            }
        }
    }
    cout << "\n\nSeats vacant= " << p << " in Train No.: " << Train[l].Train_no;
}

void a::avail() //function for checking whether the bus is available or not
{
    for (int n = 0; n <= p-1; n++)
    {
        SetConsoleTextAttribute(h,14);
        vline('*');
        SetConsoleTextAttribute(h,11);
        cout<<"\nThere are "<< p <<" Trains available.";
        cout<<"\n";
        cout << "\nTrain no: \t" << Train[n].Train_no
             << "\nTrain Name: \t"<< Train[n].Train_Name        
             << "\nArrival time: \t" << Train[n].arrive
             << "\n\tDeparture Time: \n" << Train[n].depart
             << "\nFrom: \t\t" << Train[n].from
             << "\t\tTo: \t" << Train[n].to
             <<"\nTicket Price: \t\t" << Train[n].Ticket_Price
			 << "\n";
		cout<<"\n";
    }
}
int main() //main function
{
    int w;
    a a1;
    int x = 25, y = 25 ;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,15);
    cout<<"                       TRAIN RESERVATION SYSTEM                 \n";
    cout<<"                       ===== =========== ======                 \n";
    SetConsoleTextAttribute(h,10);
    vline('*');
    cout << "\n";
    SetConsoleTextAttribute(h,10);
    vline('-');
    SetConsoleTextAttribute(h,11);
    cout<< "\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    SetConsoleTextAttribute(h,11);
    cout<<"*                                                                       *\n";
    SetConsoleTextAttribute(h,11);
    cout<<"*\t- - -       - - -       - - -       - - -       - - -       - - -  *\n";
    SetConsoleTextAttribute(h,11);
    cout<<"*      |/ / /|     |/ / /|     |/ / /|     |/ / /|     |/ / /|     |/ / /|    *\n";
    cout<<"*       - - -       - - -       - - -       - - -       - - -       - - -        *\n"; 
    SetConsoleTextAttribute(h,199);
    cout<<"*   \t\t\t WELCOME TO TRAIN RESERVATION SYSTEM                        *\n";;;;;
    SetConsoleTextAttribute(h,11);
    cout<<"*                                                                                      *\n";   
    SetConsoleTextAttribute(h,11);
    cout<<"*                                                                                         *\n";
    SetConsoleTextAttribute(h,11);
    cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    SetConsoleTextAttribute(h,14);
    cout<<"O O      O O      O O      O O      O O      O O      O O      O O      O O      O O";
    SetConsoleTextAttribute(h,10);
    while (1)
    {
        SetConsoleTextAttribute(h,10);
        cout<<"\n";
        vline('*');
        vline('*');
        cout << "\n";
        vline('-');
        vline('-');
        SetConsoleTextAttribute(h,15);
        cout << "\n1.Install\n"
             << "2.Reservation\n"
             << "3.Trains available\n"
             << "4.Show\n"
             << "5.Exit \n";
             SetConsoleTextAttribute(h,10);
        cout << "\n\t\t\tEnter your choice-> "; //asking for choice
        cin >> w;

        switch (w)
        {
        case 1:
            Train[p].install();
            break;
        case 2:
            Train[p].allotment();
            break;

        case 3:
            Train[p].avail();
            break;

        case 4:
            Train[p].show();
            break;


        case 5:
            exit(p);
        }
    }
    return 0;
}

