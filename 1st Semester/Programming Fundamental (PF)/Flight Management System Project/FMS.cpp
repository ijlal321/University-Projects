#include <iostream>
#include<conio.h>
#include<windows.h>
#include<fstream>
#include<string>
#include <ctime>
#include<time.h>
using namespace std;

string currentrole = "none";
string currentId = "none";

string Username[20] ;     // this will have username of all accounts
string Password[20] ;     // this will have password of all accounts
string Role[20] ;       // this will tell if a account is admin or user
int nr_users = 0 - 1;

string flightFrom[20] ;         // this will have location where flight will leave
string flightDestination[20];   // this will have location where flight will reach
string flightDate[20] ;         // date of flight
string flightPrice[20] ;        // price of flight
int nr_flights = 0 - 1;         // stored in such way one element means 0 items

string bookedUsersId[20] ;          // will save id of users who has booked
int bookedUsersFlight[20] ;
string bookedUsersFood[20] ;
int nr_booking = 0-1;

void changeFood();
void everyEnd();



void printHeader();
void printStartupScreen();
void printEnterOption();

void printLoginScreen();
void printSignupScreen();

void printUserInterface();
void printAdminInterface();

void addFileComplain();

int enterIdPassword(string, string, string);

int checkIdPassword(string, string, string);

int newPasswordCheck(string);

void bookFlight();

int displayFlight(string, string, string, int);

void modifyFlight();      // not used anywhere as of now

int changePassword();
int changeId();

void exit();

void cancelFlight();

void displaySpecificUserFlight();

int adminAddFlight();
int adminSeeBookedFlight();
int adminRemoveFlight();
void adminRemoveCustomer();

string announcmentMessage[20] ;
int nr_announcements = 0-1;

void adminAddAccnouncement();
void adminRemoveAccnouncement();
void adminModifyAccnouncement();
void adminSearchFlight();
int subShowAllAnnouncement(string, int, string);


void seeAnnouncements();

string complainId[20];
string complainMessages[20];
int nr_complains = 0-1;

void removeComplain();

void adminPrintComplain();

string CheckAlphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
string CheckNumber = "123456789";

string contactNo = "04665952275";
string email = "flightmanagement@gmail.com";
string helpMessage = "You can find help here";

string resetContactNo = "04665952275";
string resetEmail = "flightmanagement@gmail.com";
string resetHelpMessage = "You can find help here";

void printHelpMenu();
void adminEditHelpMenu();
void clearWithoutHeader();

void exitToUserInterface(string, int);
void exitToAdminInterface(string, int);

void printSky();
void printPlane(int);
void clearSpace();

void oneTimeStartup();

int SeachWord(string, string);

//        ==================================  //
//              anim prototypes               //

void animprintRobo();
void animprintAdminInterface();
void animprintHowToLogo();
void animhowToUseFull();
void animprintRoboInterface();
void animStartupOneTimeAnim();
bool isAnimShown = false;

//        ==================================  //

void adminchangeAppearance();




//     VERSION 2.0 CHANGES      //
void storeIdPass();
void loadIdPass();

void storeAnnouncments();
void loadAnnouncments();

void storeAvailableFlights();
void loadAvailableFlights();

void storeBookedFlights();
void loadBookedFlights();

void storeComplains();
void loadComplains();

void loadAllFiles();

string getFieldFromRecord(string record, int option);


//     VERSION 2.1 CHANGES      //
void GeneralShowSingleFlight(string, string, string, string, int);
int subReturnCountAnnouncement();
int subReturnCountComplains();

bool isLocationAvailable(string, string);

string enterToLocation();
string enterFromLocation();

string enterDateCorrectly();
string enterfoodCorrectly();

void gotostartupscreen(string);

void changePrice();

string printTime();

void printUniqueLines();

int main()
{
    loadAllFiles();
    oneTimeStartup();

    // Start up screen
    printStartupScreen();
    printEnterOption();

    getch();
    return 0;
}

            // ===================================================================

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void oneTimeStartup()
{
    system("Color 03");
    gotoxy(28, 12);
    cout << "===== Enter full screen for best experience =====";
    gotoxy(0,0);
    getch();
    system("Color 3F");
    // system("color *blue**white*");
    // getch();
    printSky();
    gotoxy(90,30);
    cout << "LOADING...";
    
    for (int i =1; i <= 30; i++)    // 17x5 = 85  \\ 300
    {
        printPlane(i);
        Sleep(120);
        clearSpace();
    }
    printPlane(30);
    gotoxy(90,30);
    cout << "LOADED SUCCESSFULLY...";

    Sleep(1000);
    // system("Color 03");
    // getch();    
}

void printSky()
{

    cout << "\n\n";                                                                                                                                                                                                                                                                                                                                                                                                     
    cout << "                                                              /@@%,/&@@/&@@.                                                             %#%@@%                                 " << endl ;        
    cout << "                                                           &@               *@,                                                      @@/      ,@@.                              " << endl ;    
    cout << "                                                         %&                    @.                                                 (@              @#*%&@&%.                     " << endl ;    
    cout << "                                                (@@@@@@@@/                      @,                                               &#                         %@.                 " << endl ;    
    cout << "                                            #@,                                  @                                             ./@                            (@                " << endl ;    
    cout << "                                          #@                    * * * *         #.  .*@@/             *          *          @@           * * * *               (%               " << endl ;    
    cout << "                                         %&                     *                        (@           * *      * *        &#             *                     **  ,&@/         " << endl ;    
    cout << "                                         @                      * * * *                    @.         *   *  *   *       (&              * * * *                       @*       " << endl ;    
    cout << "                                         @.                     *                           #%        *     *    *       (&                    *                        @       " << endl ;    
    cout << "                                         .@                     *                           @,        *          *        @(             * * * *                       ,@       " << endl ;    
    cout << "                                           @&                   *                          @*         *          *          @&                                       .@#        " << endl ;    
    cout << "                                             *@&  ..................................... &@,          ...............            ...................................             " << endl ;  
    cout << "                                                                                                                                                  " << endl ;    
    cout << "                                                                                                                                                                                                    " << endl ; 

    cout << "\n";   
    cout << "                                                                                                                                                       .^.                         " << endl;                              
    cout << "                                                                                                                                                      (( ))_________________       " << endl;                                              
    cout << "                                                                                                                                                       |#||########$$$#####|      " << endl;                                            
    cout << "                                                                                                                                                       |#||########$$$#####|      " << endl;                                            
    cout << "                                                                                                                                                       |#||########$$$#####|      " << endl;                                                                             
    cout << "                                                                                                                                                       |#||########$$$#####|      " << endl;                                            
    cout << "                                                                                                                                                       |#||########$$$#####|      " << endl;                                            
    cout << "                                                                                                                                                       |#||########$$$#####|      " << endl;                                            
    cout << "                                                                                                                                                       |#|'""""""""""""""""'      " << endl;                                            
    cout << "                                                                                                                                                       |#|                                " << endl;                  
    cout << "                                                                                                                                                       |#|                                " << endl;                                  
    cout << "                                                                                                                                                      //|\\                               " << endl;             

    cout << "\n\n\n\n";
    cout << "                                                                                                                                                                                                      " << endl ;    
    cout << "                         .&@@&**&@@&                                                           @@( /&@@/,&@*                                          *@@@(***@@@.                                    " << endl ;    
    cout << "                      *@*            /@,                                                    &&              ,@,                                    (@.            *@*(@@@@%.                          " << endl ;    
    cout << "                    .@                 ,@  &@@@@@@@,                                      .@                  (@                                 ,@                          @(                       " << endl ;    
    cout << "                    @       *       **              *@                              .&@@@@@.                      ./@@                          .@                            ,@@@@@@&                " << endl ;    
    cout << "              @@(           *      *  *                @.                         ,@*             **   ***               @.                     /&         ***  *   *   **             *@             " << endl ;    
    cout << "           /@               *      *  *                (@@@@@,                  .&%              *  *  *   *              @,                    %@          *   **  *  *  *             @@@*         " << endl ;    
    cout << "          %*                *      *  *                       *@.            *@,                 *  *  *   *                  &@             /@             *   **  *  *                     &@      " << endl ;    
    cout << "          @                 *      *  *                         @,          @(                   ****  *   *                    @(          &%              *   *  **  * **                    @     " << endl ;    
    cout << "          @,                *      *  *                         (&         .@                    *  *  *   *                     @          @.              *   *  **  *  *                    @*    " << endl ;    
    cout << "           @*               ****    **                        .@           @,                    *  *  ***                     (&          .@              ***  *   *   ***                   ,@     " << endl ;    
    cout << "             @@                                             .@*             %&                                                @*             &@                                           *@/      " << endl ;    
    cout << "                 ,*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*                    %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%                    *&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&/          " << endl ;    
    cout << "                                                                                                                                                                                                    " << endl ;    
    cout << "                                                                                                                                                                                                    " << endl ;    

}
void printPlane(int index)
{
    int margin = 3;
    int  y = 17;
    gotoxy(index*margin, y+1);
    cout << "          ______                                           ";  
    gotoxy(index*margin, y+2);
    cout << "          _\\ _~-\\___                                     " ;  
    gotoxy(index*margin, y+3);                                    
    cout << "  =  = ==(____AA____D                                      " ; 
    gotoxy(index*margin, y+4);                                         
    cout << "              \\_____\\___________________,-~~~~~~~`-.._   " ; 
    gotoxy(index*margin, y+5);                                                 
    cout << "              /     o O o o o o O O o o o o o o O o  |\\_  " ;
    gotoxy(index*margin, y+6);                                              
    cout << "              `~-.__        ___..----..                  ) " ;  
    gotoxy(index*margin, y+7);                                                
    cout << "                    `---~~\\___________/------------`````  ";  
    gotoxy(index*margin, y+8);                                        
    cout << "                    =  ===(_________D                      " ;              
}
void clearSpace()
{
    gotoxy(5,18);
    cout << "                                                                                                                                                 " << endl;  
    cout << "                                                                                                                                                  " << endl;  
    cout << "                                                                                                                                                    " << endl; 
    cout << "                                                                                                                                                    " << endl; 
    cout << "                                                                                                                                                    " << endl;
    cout << "                                                                                                                                                    " << endl;  
    cout << "                                                                                                                                                    " << endl;                                          
    cout << "                                                                                                                                                    " << endl;              
}


            // ==================================================================//


int SeachWord(string word, string sentence)
{
    int word_index = 0;
    int matching_Word = 0;
    int wordCheckSize = word.length();

    for(int i = 0; i <sentence.length(); i++)
    {
        if (sentence[i] == ' ')
        {
            word_index = 0;
            matching_Word = 0;
            continue;
        }
        if (sentence[i] == word[word_index])
        {
            matching_Word+=1;
            if (matching_Word == wordCheckSize )
                return 1;
        }
        word_index+=1;

    }
    return 0;
}

int displayFlight(string from = "any", string destination = "any", string date = "any", int option = nr_flights*2)
{
    cout << "\t  From               To               Time               Price " << endl;
    cout << "\n";

    int temp_nr_flights = 0;
    int j = 0;
    for (int i=0; i <= nr_flights; i++)
    {
        if (flightFrom[i] == from || from == "any")
        {
            if (flightFrom[i] == "none")
            {
                continue;
            }
            if (flightDestination[i] == destination || destination == "any")
            {
                if (flightDate[i] == date || date == "any")
                {
                    if (option == nr_flights*2)
                    {
                        temp_nr_flights+=1;
                        GeneralShowSingleFlight(flightFrom[i], flightDestination[i], flightDate[i], flightPrice[i], temp_nr_flights);
                    }
                    else
                    {
                        j+= 1;
                        if (option == j)
                            return i;
                    }

                }  
            }
        }

    }
    return temp_nr_flights;

}

int newPasswordCheck(string password)
{
    int alphabetCount = 0, numberCount = 0;

    for (int i = 0; i< password.length(); i++)
    {
        for (int j = 0; j < CheckAlphabet.length(); j++)
        {
            if (password[i] == CheckAlphabet[j])
            {
                alphabetCount+=1;
            }
        }
        for (int j = 0; j < CheckNumber.length(); j++)
        {
            if (password[i] == CheckNumber[j])
            {
                numberCount+=1;
                // cout << "1";
            }
        }
    }
    // cout << numberCount << "  " << alphabetCount;
    if (alphabetCount < 7 || numberCount < 3)
    {
        return 0;
    }
    return 1 ;
}

int checkIdPassword(string username, string password, string role ="none")
{
    for (int i = 0; i <= nr_users; i++)
    {
        if (username == Username[i])
        {
            if (password == Password[i])
            {
                if (role == "isadmin")
                {
                    if (Role[i] == "Admin")
                        return 1; 
                    else
                        return 0; 
                }
                if (role == "unknown")
                {
                    return 1;
                }
            } 
            if (role == "none")
            {
                return 1;
            }
        }
    }
    return 0;
}

int enterIdPassword(string username, string password, string role)
{

    if (checkIdPassword(username, password) == 1)
    {
        // username already exit
        return 0;
    }  
    nr_users += 1;
    Username[nr_users] = username;
    Password[nr_users] = password;
    Role[nr_users] = role;
    storeIdPass();
    cout << "added successfully";


}

int subShowAllAnnouncement(string method = "show all", int option = -1, string message = "none")
{
    int index = 1;
    int none = 0;
    for(int i = 0; i<= nr_announcements; i++)
    {
        string tempAnnouncement = announcmentMessage[i];
        if (tempAnnouncement == "none")
        {
            none+=1;
            continue;
        }
        if (method == "show all")
        {
            cout << "\t" << index << ".    " ;
            index+=1;
            for (int j = 0; j<=tempAnnouncement.length(); j++)
            {
                if (j>=30)
                {
                    cout << " ...";
                    break;
                }
                cout << tempAnnouncement[j];
            }
            cout << endl;
        }
        if (method == "show specific")
        {
            if (option == index)
            {
                cout << "\t" << index << ".    " ;
                for (int j = 0; j<=tempAnnouncement.length(); j++)
                {
                    if (j%60 == 0 && j!=0)
                    {
                        cout << endl<< "\t     ";
                    }
                    cout << tempAnnouncement[j];
                }
            cout << endl;
            }
            index+=1;
            // cout << endl;
        }
        if (method == "remove")
        {
            if (option == index)
            {
                announcmentMessage[i] = "none";
                cout << endl;
            }
            index+=1;
        }
        if (method == "modify")
        {
            if (option == index)
            {
                announcmentMessage[i] = message;
                cout << endl;
            }
            index+=1;
        }
    }
}

void exitToUserInterface(string option, int intoption = 1)
{
    if (option == "exit" || option == "Exit" || option == "EXIT" || option == "-1")
    {
        printUserInterface();
    }
    if (intoption == -1)
    {
        printUserInterface();
        // printAdminInterface();
    }
}

void exitToAdminInterface(string option, int intoption = 1)
{
    if (option == "exit" || option == "Exit" || option == "EXIT" || option == "-1")
    {
        printAdminInterface();
    }
    if (intoption == -1)
    {
        printAdminInterface();
    }
}

            // ==================================================================//

            // ================     VERSION 2.1 CHANGES      ===================//
    
void GeneralShowSingleFlight(string flight_from,string  flight_to,string  flight_date,string  flight_price, int index = -1)
{
    string temp;
    if (index == -1)
    {
    cout << "\t  " << flight_from;
    }
    else
    {
        cout << "\t" << index << " " << flight_from;
    }
    temp = flight_from;
    for (int i = 0; i <(19-temp.length()); i++)
    {
        cout <<" ";
    }
    cout << flight_to;

    temp = flight_to;
    for (int i = 0; i <(17-temp.length()); i++)
    {
        cout <<" ";
    }
    cout <<flight_date;
    for (int i = 0; i <(19-10); i++)
    {
        cout <<" ";
    }
    cout << flight_price;
    if (index != -2)
    {
        cout  << endl;
    }
}

int subReturnCountAnnouncement()
{
    int our_no = 0;
    for(int i = 0; i <= nr_announcements; i ++)
    {
        if (announcmentMessage[i] == "none")
        {
            continue;
        }
        our_no += 1;
    }
    return our_no ;
}

int subReturnCountComplains()
{
    int our_no = 0;
    for(int i = 0; i < nr_complains; i ++)
    {
        if (complainMessages[i] == "none")
        {
            continue;
        }
        our_no += 1;
    }
    return our_no;
}

bool isLocationAvailable(string location, string fromTo)
{
    if (fromTo == "from")
    {
        for(int i = 0; i <= nr_flights; i++)
        {
            if (flightFrom[i] == location)
            {
                return true;
            }
        }
    }
    else if (fromTo == "to")
    {
        for(int i = 0; i <= nr_flights; i++)
        {
            if (flightDestination[i] == location)
            {
                return true;
            }
        }
    }
    return false;
}

void gotostartupscreen(string option)
{
    if (option == "exit" || option == "Exit" || option == "EXIT" || option == "-1")
        printStartupScreen();
}

string enterDestinationLocation()
{
    string to;
    while(true)
    {
    cout << "\n\n";
    cout << "\t Enter Your destination(Name, any): ";
    cin >> to;
    exitToUserInterface(to);
    if (to == "any")
    {
        return to;
    } 
    if (isLocationAvailable(to, "to"))
    {
        return to;
        break;
    }
    else
    {
        cout << "\t please enter valid information";
    }
    }
}

string enterFromLocation()
{
    string from;
    while(true)
    {
        cout << "\n\n";
        cout << "\t Enter pickup point(Name, any): ";
        cin >> from;
        exitToUserInterface(from);
        if (from == "any")
        {
            return from;
        } 
        if (isLocationAvailable(from, "from"))
        {
            return from;
            break;
        }
        else
        {
            cout << "\t no flight available from this location";
        }
    }
}

string enterDateCorrectly()
{
    string fulldate;
    while(true)
    {
        cout << "\n\n";
        cout << "\t Enter Your fullDate(use 01-01-2003, any): ";
        cin >> fulldate;
        exitToUserInterface(fulldate);
        if (fulldate == "any")
        {
            return fulldate;
        }
        if (fulldate.length() != 10)
        {
            cout << "\t please enter valid info";
            continue; 
        }
        fulldate[2] = '-';
        fulldate[5] = '-';
        return fulldate;
    }
}

string enterfoodCorrectly()
{
    // cin.ignore();
    string food;

    while (true)
    {
        cout << "\n";
        cout << "\t Enter new food type (veg, non-Veg): ";
        cin >> food;
        exitToUserInterface(food);
        if (food == "non-veg" || food == "Non-Veg" || food == "Non-veg" || food == "non veg")
        {
            food = "Non-Veg";
            break;
        }
        if (food == "veg" || food == "Veg")
        {
            food = "Veg";
            break;
        }
        cout << "\t please chose from above options, try again \n\n ";
    }
    return food;

    
}

void changePrice()
{
    int temp_nr_flights;
    temp_nr_flights = displayFlight();

    if (temp_nr_flights == 0)
    {
        cout << "\n\tNo flights available, returning...";
        getch();
        printAdminInterface();
    }

    int option;
    while(true)
    {
        cout << "\n\tEnter flight you want to change Price: ";
        cin >> option;
        exitToAdminInterface("any", option);
        if (option < 1 || option > temp_nr_flights)
        {
            cout << "invalid option, try again\n";
        }
        else
            break;
    }

    string newPrice;
    cout << "\n\tenter new price: ";
    cin >> newPrice;

    int j=1;
    for(int i = 0; i <= nr_flights; i++)
    {
        if (flightFrom[i] == "none")
        {
            continue;
        }
        if(j==option)
        {
            int j = i;

            // change flight from database
            flightPrice[i] = newPrice;
            cout << "\n\tflight changes successfully";
        }
        j+=1;
    }

    storeAvailableFlights();
    getch();
    printAdminInterface();
}

string printTime()
{
    time_t ct = time(0);
    string currenttime = ctime(&ct);
    return currenttime;
}

            // Complain Section      Can do a fun here maybe
void seeComplain()
{
    int index = 1;
    cout << "     Your complains are: \n\n";
    for(int i = 0; i<=nr_complains; i++)
    {
        if(complainId[i] == currentId)
        {
            cout << "\t "<< index << ". " << complainMessages[i] << "\n\n";
            index+=1;
        }
    }
    if (index == 1)
    {
        cout << "\t  no complains available to see"; 
    }
    // getch();
    printUserInterface();
}

void removeComplain()
{
    int nr_complain = 0;
    int index = 1;
    cout << "    Your all complains are: \n\n";
    for(int i = 0; i<=nr_complains; i++)
    {
        if(complainId[i] == currentId)
        {
            nr_complain+=1;
            cout << "\t"<< index << ". " << complainMessages[i] << "\n\n";
            index+=1;
        }
    }

    if (nr_complain == 0)
    {
        cout << "\n     no complains available.";
        getch();
        printUserInterface();
    }

    int option;
    while(true)
    {
        cout << "     enter complain you want to remove: ";
        cin >> option;
        exitToUserInterface("any", option);
        if (option < 1 || option > nr_complain)
        {
            cout << "\t enter valid nr.\n";
        }
        else
            break;
    }
    int j=1;
    for(int i = 0; i<=nr_complains; i++)
    {
        if(complainId[i] == currentId)
        {
            if(option == j)
            {
                cout << "\n     The complain, \n   ----> " << complainMessages[i] << "\n     has been deleted." << endl;
                complainId[i] = "none";
                complainMessages[i] = "none";
            }
            j+=1;
        }

    }


    storeComplains();
    getch();
    printUserInterface();
}

void addFileComplain()
{
    string userComplain ;
    cout << "\n\t";
    cout << "Enter complain your : ";
    cin.ignore();
    getline(cin, userComplain);
    exitToUserInterface(userComplain);

    cout << "\n\t";
    nr_complains += 1;
    complainId[nr_complains] = currentId;
    complainMessages[nr_complains] = userComplain;

    cout << "\n\n\t Your message has been saved";
    storeComplains();

    // getch();
    printUserInterface();
}

void adminPrintComplain()
{
    int tempNrComplains = 0;
    cout << "\n    These are complains that are issues by user\n\n" << endl;
    cout << "\tUser id                        Message\n"<< endl;    // 31
    for(int i = 0; i<= nr_complains; i++)
    {
        if (complainMessages[i] != "none")
        {
            tempNrComplains += 1;
            cout << "\t" << tempNrComplains << " " << complainId[i] ;
            string id_temp = complainId[i];
            for(int i = 0; i < (31-id_temp.length()); i++ )
            {
                cout << " ";
            }
            string tempMessage = complainMessages[i];
            for(int j = 0; j<=tempMessage.length();j++)
            {
                if (j >= 20)
                {
                    cout << "....." ;
                    break;
                }
                cout << tempMessage[j];
            }
            cout << endl;
        }
    }

    if (tempNrComplains == 0)
    {
        cout << "no complains available";
        getch();
        printAdminInterface();
    }

    int option;
    while(true)
    {
        cout << "\n\tenter message you see properly: ";
        cin >> option;
        exitToAdminInterface("any", option);
        if (option <1 || option > tempNrComplains)
        {
            cout << "\tinvalid complain id, try again;  \n";
        }
        else
            break;
    }

    int j = 1;
    for(int i = 0; i<=nr_complains; i++)
    {
        if (complainMessages[i] != "none")
        {
            if(option == j)
            {
                cout << "\n\t---> " << complainMessages[i];
            }
            j+=1;
        }
    }
    getch();    
    printAdminInterface();

}



            // Announcement Section
void seeAnnouncements()
{
    cout << "\nAll aannouncements are: \n\n";
    subShowAllAnnouncement("show all");
    int option;

    while(true)
    {
        cout << "\nchose announcement you want to see: ";
        cin >> option;
        exitToUserInterface("any", option);
        // cout << "\n" << announcmentMessage[option-1];
        if(option < 1 || option > subReturnCountAnnouncement())
        {
            cout << "please enter valid announcement number\n";
        }
        else
        {
            break;
        }
    }
    subShowAllAnnouncement("show specific", option);


    getch();

    printUserInterface();

}

void adminModifyAccnouncement() 
{
    cout << "chose announcement you want to Modify \n" << endl;

    subShowAllAnnouncement("show all");

    int option;
    while(true)
    {
        cout << "\nchose announcement you want to modify: ";
        cin >> option;
        exitToAdminInterface("any", option);
        if (option < 1 || option > (subReturnCountAnnouncement()))
        {
            cout << "invalid option, try again\n\n";
        }
        else 
            break;
    }
    string new_announcement;
    cout << "\nEnter new announcement";
    cin.ignore();
    getline(cin, new_announcement);
    subShowAllAnnouncement("modify", option, new_announcement);

    cout << "Selected announcement has been modified";
    storeAnnouncments();
    // getch();
    printAdminInterface();
}

void adminRemoveAccnouncement() 
{
    cout << "     chose announcement you want to reomve " << endl;

    subShowAllAnnouncement("show all");

    int option;
    while(true)
    {
        cout << "\n     chose announcement you want to remove: ";
        cin >> option;
        exitToAdminInterface("any", option);
        // if (option < 1 || option > nr_announcements+1)
        if (option < 1 || option > (subReturnCountAnnouncement()))
        {
            cout << "     invalid option, try again\n\n";
        }
        else 
            break;
    }
    subShowAllAnnouncement("remove", option);

    cout << "     Selected announcement has been removed";
    storeAnnouncments();

    getch();
    printAdminInterface();
}

void adminAddAccnouncement()
{
    string announcement;
    cout << "\t enter new announcement: ";
    cin.ignore();
    getline(cin, announcement);
    exitToAdminInterface(announcement);
    nr_announcements+=1;

    announcmentMessage[nr_announcements] = announcement;
    cout << "\n\t Your record has been saved ";
    storeAnnouncments();
    
    // getch();
    printAdminInterface();
}



            // Admin Interface Section

int adminAddFlight()
{
    string to, from, date, price;
    cout << "\n";
    cout << "\tEnter flight Departure spot: ";
    cin >> from;
    exitToAdminInterface(from);
    cout << "\tEnter flight Destination: ";
    cin >> to;
    exitToAdminInterface(to);
    cout << "\tEnter Date of flight: ";
    cin >> date;
    exitToAdminInterface(date);
    cout << "\tEnter Price of flight: ";
    cin >> price;
    exitToAdminInterface(price);

    nr_flights+=1;
    flightFrom[nr_flights] = from;
    flightDestination[nr_flights] = to;
    flightDate[nr_flights] = date;
    flightPrice[nr_flights] = price;

    cout << "\nThe following flight has been added in database\n\n";

    cout << "\t  From               To               Time               Price " << endl;

    int j = nr_flights;
    GeneralShowSingleFlight(flightFrom[j], flightDestination[j], flightDate[j], flightPrice[j]);


    // cout << "\t" << flightFrom[nr_flights] << "    " << flightDestination[nr_flights] << "    "<< flightDate[nr_flights] << "    " << flightPrice[nr_flights] << endl; 

    storeAvailableFlights();
    getch();
    printAdminInterface();

}

int adminRemoveFlight()         // option validation self
{
    int temp_nr_flights = 0;
    // cout << "\t  From               To               Time               Price " << endl;

    temp_nr_flights = displayFlight();

    if (temp_nr_flights == 0)
    {
        cout << "\n\tNo flights available, returning...";
        getch();
        printAdminInterface();
    }


    int option;
    while(true)
    {
        cout << "\n\tEnter flight you want to remove: ";
        cin >> option;
        exitToAdminInterface("any", option);
        if (option < 1 || option > temp_nr_flights)
        {
            cout << "invalid option, try again\n";
        }
        else
            break;
    }
    int j=1;
    for(int i = 0; i <= nr_flights; i++)
    {
        if (flightFrom[i] == "none")
        {
            continue;
        }
        if(j==option)
        {
            int j = i;

            GeneralShowSingleFlight(flightFrom[j], flightDestination[j], flightDate[j], flightPrice[j]);

            for(int k = 0; k <= nr_booking; k++)
            {
                if (bookedUsersFlight[k] == i)
                {
                    bookedUsersId[k] = "none";
                    bookedUsersFlight[k] = -1;
                    bookedUsersFood[k] = "none";
                }
            }

            // removing flight from database
            flightFrom[i] = "none";
            flightDestination[i] = "none";
            flightDate[i] = "none";
            flightPrice[i] = "none";
        }
        j+=1;
    }
    
    storeAvailableFlights();
    getch();
    printAdminInterface();

}

int adminSeeBookedFlight()
{
    cout << "\t  ID                 From               To               Time               Price " << endl;
    int tempIndex = 1;
    for(int i = 0; i <= nr_booking; i++)
    {
        int j = bookedUsersFlight[i];
        if (bookedUsersId[i] == "none" || flightFrom[j] == "none")
        {
            continue;
        }

        string temp;
        cout << "\t" << tempIndex << " " << bookedUsersId[i];
        tempIndex += 1;
        temp = bookedUsersId[i];
        for (int i = 0; i <(19-temp.length()); i++)
        {
            cout <<" ";
        }
        cout << flightFrom[j];
        temp = flightFrom[j];
        for (int i = 0; i <(19-temp.length()); i++)
        {
            cout <<" ";
        }
        cout << flightDestination[j] ;

        temp = flightDestination[j] ;
        for (int i = 0; i <(17-temp.length()); i++)
        {
            cout <<" ";
        }
        cout <<flightDate[j];
        for (int i = 0; i <(19-10); i++)
        {
            cout <<" ";
        }
        cout << flightPrice[j] << endl;
        // cout << bookedUsersId[i] << "   " << bookedUsersFood[i] << "   " << flightFrom[j] << "   " << flightDestination[j] << "   " << flightDate[j] << "   " << flightPrice[j];
        // cout << endl;
    }
    cout << "\n\nPress any key to continue ;" <<endl;
    // getch();
    printAdminInterface();
}

void adminSearchFlight()
{
    string to, from, date;
    cout << "enter pickup point (name/ any): ";
    cin >> from;
    exitToAdminInterface(from);
    cout << "enter destinaton point (name/ any): ";
    cin >> to;
    exitToAdminInterface(to);
    cout << "enter Date (01-01-2003/ any): ";
    cin >> date;
    cout << "\n";
    exitToAdminInterface(date);

    displayFlight(from=from, to, date);

    cout << "\nAll results re shown...";
    
    getch();
    printAdminInterface();
}

void adminRemoveCustomer()
{
    cout << "     Chose user you want to remove. He/She must be User \n\n";
    cout << "\t  UserID          Passward          Role\n" << endl;
    string temp;
    int temp_nr_customers = 0;
    // cout <<  ;

    for(int i = 0; i<=nr_users; i++)
    {
        if(Role[i] == "User")
        {
            temp_nr_customers +=1;
            temp = Username[i];
            cout << "\t" << temp_nr_customers << " " << Username[i];
            for (int i = 0; i < (16-temp.length()); i++)
            {
                cout << " ";
            }
            temp = Password[i];
            cout << Password[i];
            for (int i = 0; i < (18-temp.length()); i++)
            {
                cout << " ";
            }
            cout << Role[i] << endl;

        }   
    }

    if (temp_nr_customers == 0)
    {
        cout << "\n     No Users to show";
        getch();
        printAdminInterface();
    }

    int option;
    while(true)
    {
        cout << "\n     enter user you want to remove";
        cin >> option;
        exitToAdminInterface("any", option);
        if (option < 1 || option > temp_nr_customers)
        {
            cout << "\n     invalid option, try again\n";
        }
        else 
            break;
    }

    int j = 1;
    for(int i = 0; i<=nr_users; i++)
    {
        if(Role[i] == "User")
        {
            if (j==option)
            {
                
                // removing lfights if any
                for (int k = 0; k<= nr_flights; k++)
                {
                    if (bookedUsersId[k] == Username[i])
                    {
                        bookedUsersId[k] = "none";
                        bookedUsersFlight[k] = -1;
                    }
                }


                 // removing from database
                Username[i] = "none";
                Password[i] = "none";
                Role[i] = "none";
            } 
            j+=1;
        }
  
    }
    cout << "\n     User removed Successfully and with his bookings";
    // storeIdPass();
    // storeBookedFlights();
    getch();
    printAdminInterface();

}




            // Help Section
void printHelpMenu()
{
    cout << "This is help menu \n\n";
    cout << "Contact No: "<< contactNo << "\n";
    cout << "Email: " << email << endl;
    cout << helpMessage;
    // getch();
    printUserInterface();
}

void adminEditHelpMenu()
{
    string option;
    cout << "\ndo you want to change contact nr(y/n):  ";
    cin >> option;
    exitToAdminInterface(option);
    if (option == "y")
    {
        string new_contact;
        cout << "enter new contact nr: ";
        cin >> new_contact;
        exitToAdminInterface(new_contact);
        contactNo = new_contact;
    }

    cout << "\ndo you want to change Email(y/n):  ";
    cin >> option;
    exitToAdminInterface(option);
    if (option == "y")
    {
        string new_email;
        cout << "enter new email: ";
        cin >> new_email;
        exitToAdminInterface(new_email);
        email = new_email;
    }

    cout << "\ndo you want to change Help Message(y/n):  ";
    cin >> option;
    exitToAdminInterface(option);
    if (option == "y")
    {
        string new_message;
        cout << "enter new message: ";
        cin >> new_message;
        helpMessage = new_message;
    }

    cout << "\ndo you want to reset evrything to default: ";
    cin >> option;
    exitToAdminInterface(option);
    if (option == "y")
    {
        contactNo = "04665952275";
        email = "flightmanagement@gmail.com";
        helpMessage = "You can find help here";
    }
    cout << "\nDone. Press anything to go back to admin interface...";
    printAdminInterface();
}



            // User Interface Section
void bookFlight()   
{
    string name, passport, from, destination, fullDate, timings, foodType;
    cout << "\n\n";
    cout << "     Chose Option" << endl;

    cout << "\n\n\n";
    cout << "\t Enter Your Name: ";
    cin >> name;
    getline(cin, name);
    exitToUserInterface(name);

    while (true)
    {
        cout << "\n\n";
        cout << "\t Enter 7 digit passport Number ";
        cin >> passport;
        exitToUserInterface(passport);
        if (passport.length() != 7)
        {
            cout << "\t please enter valid passport no.";
        }
        else
        {
            break;
        }
    }
    

    from =  enterFromLocation();

    destination = enterDestinationLocation();

    fullDate = enterDateCorrectly();
   
    cout << "\n";
    foodType = enterfoodCorrectly();
    system("cls");
    printHeader();

    cout << "\n\t Available Flights are: \n\n";
    int temp_ans = displayFlight(from, destination, fullDate);
    if (temp_ans == 0)
    {
        int option;
        cout << "\t no flights avail" << endl;
        cout << "\t Enter 1 to try again, enter 2 to go back: ";
        cin >> option;
        exitToUserInterface("any", option);
        if (option == 1)
        {
            printHeader();
            bookFlight();
        }
        else
        {
            printUserInterface();
        }
    }



    cout << "\n\n";
  

    int option;
    while(true)
    {
        cout << "\n\n\t chose option: ";
        cin >> option;
        cout << "\n";
        exitToUserInterface("any", option);
        if (option< 1 || option > temp_ans)
        {
            cout << "\t please enter valid flight.\n";
        }
        else 
            break;
    }

    int selectedOption = displayFlight(from, destination, fullDate, option);

    string temp = flightFrom[selectedOption];
    cout << "\t  " << flightFrom[selectedOption];
    for(int i = 0; i < (19- temp.length()); i++)
    {
        cout << " ";
    }
    temp = flightDestination[selectedOption];
    cout  << flightDestination[selectedOption];
    for(int i = 0; i < (17- temp.length()); i++)
    {
        cout << " ";
    }
    cout << flightDate[selectedOption];
    cout << "         ";
    cout << flightPrice[selectedOption] << endl; 


    nr_booking+=1;
    bookedUsersId[nr_booking] = currentId;
    bookedUsersFlight[nr_booking] = selectedOption;
    bookedUsersFood[nr_booking] = foodType;
    cout << "\n\t This flight has been booked.\n\n";
    storeBookedFlights();
    // cout << bookedUsersId[nr_booking] << bookedUsersFlight[nr_booking] << bookedUsersFood[nr_booking];

    cout << "\t Press anything to go back to user interface";
    getch();
    printUserInterface();
}

void cancelFlight()
{       

    cout << "\n";
    cout << "\t  From               To               Time               Price " << endl;
    int temp_nr_flights=0;
    for (int i = 0; i <= nr_booking; i++)
    {
        if (bookedUsersId[i] == currentId)
        {
            int j = bookedUsersFlight[i];
            if (flightFrom[j] == "none" || flightDestination[j] == "none")
            {
                continue;
            }
                // printing with proper syntax
            temp_nr_flights += 1;
            GeneralShowSingleFlight(flightFrom[j], flightDestination[j], flightDate[j], flightPrice[j], temp_nr_flights);
        } 
    }

    if (temp_nr_flights == 0)
    {
        cout << "\n\t no flight available to cancel, going back";
        getch();
        printUserInterface();
    }

    int option;
    while(true)
    {
        cout << "\n\t enter flight you want to cancel: ";
        cin >> option;
        cout << "\n";
        exitToUserInterface("any", option);
        if (option< 1 || option > temp_nr_flights)
        {
            cout << "\t plz enter valid flight nr.\n";
        }
        else 
            break;
    }

    int k=1;
    for (int i = 0; i <= nr_booking; i++)
    {
        if (bookedUsersId[i] == currentId)
        {
            if (option == k)
            {
                int j = bookedUsersFlight[i];
                if (flightFrom[j] == "none" || flightDestination[j] == "none")
                {
                    continue;
                }

                int selectedOption = j;
                GeneralShowSingleFlight(flightFrom[selectedOption], flightDestination[selectedOption], flightDate[selectedOption], flightPrice[selectedOption], option);
                // string temp = flightFrom[selectedOption];
                // cout << "\t  " << flightFrom[selectedOption];
                // for(int i = 0; i < (19- temp.length()); i++)
                // {
                //     cout << " ";
                // }
                // temp = flightDestination[selectedOption];
                // cout  << flightDestination[selectedOption];
                // for(int i = 0; i < (17- temp.length()); i++)
                // {
                //     cout << " ";
                // }
                // cout << flightDate[selectedOption];
                // cout << "         ";
                // cout << flightPrice[selectedOption] << endl; 




                // cout << "\n\t  " << flightFrom[j] << "    " << flightDestination[j] << "    "<< flightDate[j] << "    " << flightPrice[j] << endl; 
                bookedUsersId[i] = "none";
                bookedUsersFlight[i] = -1;
                bookedUsersFood[i] = "none";
                
            }
            k+=1;
        }
    }

    storeBookedFlights();
    cout << "\n\t This Flight has been cancelled ";
    getch();
    printUserInterface();


}

void displaySpecificUserFlight()
{
    int temp_nr_flights = 0;
    cout << "\t  From               To               Time               Price " << endl;
    cout << "\n";

    for (int i = 0; i <= nr_booking; i++)
    {
        if (bookedUsersId[i] == currentId)
        {
            int j = bookedUsersFlight[i];
            if (flightFrom[j] == "none" || flightDestination[j] == "none")
            {
                continue;
            }

                // proper index
            temp_nr_flights+=1;
            GeneralShowSingleFlight(flightFrom[j], flightDestination[j], flightDate[j], flightPrice[j], temp_nr_flights);


                // old no indendation
            // cout << "\t\t" << flightFrom[j] << "    " << flightDestination[j] << "    "<< flightDate[j] << "    " << flightPrice[j] << endl; 
        }
    }
    if (temp_nr_flights == 0)
    {
        cout << "\n\tNo flights are boooked as of now.";
    }
    // getch();
    printUserInterface();

}

void changeFood()
{
    int temp_nr_flights = 0;
    cout << "Please chose flight you want to change food type \n";
    cout << "\t  From               To               Time               Food Type " << endl;
    cout << "\n";

    for (int i = 0; i <= nr_booking; i++)
    {
        if (bookedUsersId[i] == currentId && flightFrom[bookedUsersFlight[i]] != "none")
        {
            int j = bookedUsersFlight[i];

                // proper indentation
            temp_nr_flights+=1;
            string temp;
            cout << "\t" << temp_nr_flights << " "<< flightFrom[j];
            temp = flightFrom[j];
            for (int i = 0; i <(19-temp.length()); i++)
            {
                cout <<" ";
            }
            cout << flightDestination[j];

            temp = flightDestination[j];
            for (int i = 0; i <(17-temp.length()); i++)
            {
                cout <<" ";
            }
            cout <<flightDate[j];
            for (int i = 0; i <(19-10); i++)
            {
                cout <<" ";
            }
            cout << bookedUsersFood[i] << endl;
        }
    }

    if (temp_nr_flights == 0)
    {
        cout << "\nNo flight has booked by user. Returning...";
        getch();
        printUserInterface();
    }

    int option;
    while(true)
    {
        cout << "\n\t Enter flight you want to change food: ";
        cin >> option;
        exitToUserInterface("any", option);
        if (option < 1 || option > temp_nr_flights)
        {
            cout << "please enter right option\n"; 
        }
        else
            break;
    }
    string new_food;
    new_food = enterfoodCorrectly();

    int k = 1;
    for (int i = 0; i <= nr_booking; i++)
    {
        if (bookedUsersId[i] == currentId && flightFrom[bookedUsersFlight[i]] != "none")
        {
            if (k == option)
            {
                bookedUsersFood[i] = new_food;
                cout << "\n\t changed successsfully";  
            }
            k+=1;
        }
    }
    
    storeBookedFlights();
    getch();
    printUserInterface();
    

}

int changeId()
{
    string oldPassword, newId;
    cout << "     You must first validate before changing password" << endl;
    cout << "     enter old password: ";
    cin >> oldPassword;
    exitToUserInterface(oldPassword);

    int tempUserIndex = -1;
    for (int i = 0; i <=nr_users; i++)
    {
        if (currentId == Username[i])
        {
            if (oldPassword == Password[i])
            {
                cout << "\n     Validation Successful";
                tempUserIndex = i;
            }
            else
            {
                cout <<  "\n     Validation failed, ";
                getch();
                printUserInterface();
            }
        }
    }

    if (tempUserIndex == -1)
    {
        cout <<  "\n     Validation failed, ";
        getch();
        printUserInterface();
    }

    cout << "     enter new username: ";
    cin >> newId;
    exitToUserInterface(newId);

    Username[tempUserIndex] = newId;
    cout << "     Id changed";
    storeIdPass();
    getch();
    printUserInterface();


}

int changePassword()
{
    string oldPassword, newPassword;
    cout << "     You must first validate before changing password" << endl;
    cout << "     enter old password: ";
    cin >> oldPassword;
    exitToUserInterface(oldPassword);

    int tempUserIndex;
    for (int i = 0; i <=nr_users; i++)
    {
        if (currentId == Username[i])
        {
            if (oldPassword == Password[i])
            {
                cout << "\n     Validation Successful";
                tempUserIndex = i;
            }
            else
            {
                cout <<  "\n     Validation failed, ";
                getch();
                printUserInterface();
            }
        }
    }
    cout << "\n     enter new password: ";
    cin >> newPassword;
    exitToUserInterface(newPassword);
    
    if (newPasswordCheck(newPassword) == 0)
    {
        cout << "     invalid, follow insturctions, returning";
        getch();
        printHeader();
        changePassword();
    }
    Password[tempUserIndex] = newPassword;
    cout << "     Password changed";
    storeIdPass();
    getch();
    printUserInterface();



}

            // Main Interfaces
void printAdminInterface()
{
    cin.ignore();
    printHeader();
    cout << "\n\n";
    cout << "    Chose Option" << endl;

    cout << "\n\n";
    cout << "\t  1. Add Flight                                7. Search Flights                  " ;
    cout << "\n";
    cout << "\t  2. Remove Flight                             8. Change Price";
    cout << "\n";
    cout << "\t  3. Check Booked Flights                      9. Add announcement";
    cout << "\n";
    cout << "\t  4. See Complain Box                          10. Remove announcement ";
    cout << "\n";
    cout << "\t  5. See How To Guide                          11. Modify announcement ";
    cout << "\n";
    cout << "\t  6. Change Contact info                       12. Remove customer ";
    cout << "\n";
    cout << "\t                            13. Exit                         ";
    cout << "\n\n";
 

    string option;
    // option = " ";
    printEnterOption();
    // cin.ignore();
    getline(cin, option);

    if  (  !SeachWord("see", option) && !SeachWord("remove", option) && (option == "1"       || ( ( SeachWord("enter", option) || SeachWord("add", option) || SeachWord("new", option))  && (SeachWord("flight", option) || SeachWord("flights", option))  )))
    {
        // Book Flight
        printHeader();
        adminAddFlight();
    }
    else if (option == "2"  || ( ( SeachWord("remove", option) || SeachWord("cancel", option) || SeachWord("delete", option))  && (SeachWord("flight", option) || SeachWord("flights", option) ))  )
    {
        // Remove Flight
        printHeader();
        adminRemoveFlight();
    }
    else if (option == "3"  || ( ( SeachWord("see", option) || SeachWord("show", option) || SeachWord("check", option)  || SeachWord("booked", option))  && (SeachWord("flight", option) || SeachWord("flights", option)) ))
    {
        // Book Flight
        // getch();
        printHeader();
        adminSeeBookedFlight();
    }
    else if (option == "4"  || (( SeachWord("see", option) || SeachWord("show", option) || SeachWord("box", option))  && (SeachWord("complain", option) || SeachWord("complains", option) ))  )
    {
        // Add Complain
        printHeader();
        adminPrintComplain();
        
    }
    else if (option == "5" || SeachWord("guide", option))
    {
        // See how to guide
        // getch();
        // printHeader();
        animStartupOneTimeAnim();
        printAdminInterface();
        
    }
    else if (option == "6"  || ( SeachWord("help", option)  ||  (SeachWord("contact", option))  ) ) 
    {
        // Change help menu
        printHeader();
        adminEditHelpMenu();
        
    }
    else if (option == "7" || ( SeachWord("search", option) || (SeachWord("find", option) ))  && ((SeachWord("flight", option) || (SeachWord("flights", option)) ) )  )
    {
        // Search Flight
        printHeader();  
        adminSearchFlight();        
    }
    else if (option == "12" || (( SeachWord("remove", option) || SeachWord("delete", option) )  && ( SeachWord("customer", option) || SeachWord("customers", option) ) ) )
    {
        // Remove Customer
        printHeader();
        adminRemoveCustomer();

        
    }
    else if ( !SeachWord("see", option) && !SeachWord("remove", option) &&  (option == "9" || (( SeachWord("add", option) || SeachWord("new", option) )  && ( SeachWord("announcement", option) || SeachWord("announcements", option) ) ) ))
    {
        // Add Announcement
        printHeader();
        adminAddAccnouncement();
        
    }
    else if (option == "10"|| (( SeachWord("remove", option) || SeachWord("cancel", option) || SeachWord("delete", option))  && ( SeachWord("announcement", option) || SeachWord("announcements", option) ) ))
    {
        // Remove Announcement
        printHeader();
        adminRemoveAccnouncement();

        
    }
    else if (option == "11" || (( SeachWord("modify", option) || SeachWord("edit", option)) && ( SeachWord("announcement", option) || SeachWord("announcements", option) ) ) )
    {
        // modify aannouncement
        printHeader();
        adminModifyAccnouncement();
        
    }
    else if (option == "8" ||  SeachWord("price", option)  ||  SeachWord("Price", option) )
    {
        // change price
        printHeader();
        changePrice();
    }
    else if (option == "13" || SeachWord("Exit", option) || SeachWord("exit", option) )
    {
        exit();
    }
    else 
    {
        cout << "no valid option selected";
        getch();
        printAdminInterface();
    }
}

void printUserInterface()
{
    cin.ignore();
    printHeader();
    cout << "\n\n";
    cout << "    Chose Option" << endl;
 
    cout << "\n\n";
    cout << "\t  1. Book Flight                                7. Change Food";
    cout << "\n";
    cout << "\t  2. Cancel Flight                              8. See Announcements";
    cout << "\n";
    cout << "\t  3. See My Flights                             9. Change Username";
    cout << "\n";
    cout << "\t  4. File Complain                              10. Change Password ";
    cout << "\n";
    cout << "\t  5. See Complain                               11. Help ";
    cout << "\n";
    cout << "\t  6. Remove Complain                            12. Exit ";
    cout << "\n\n";
 

    string option;
    printEnterOption();
    // cin.ignore();
    getline(cin, option);


    if (  !SeachWord("see", option) && !SeachWord("cancel", option) && (option == "1"  || ( (SeachWord("book", option)||SeachWord("add", option)||SeachWord("new", option))  &&  (SeachWord("flight", option)||SeachWord("flights", option))  )))
    {
        // Book Flight
        printHeader();
        bookFlight();
    }
    else if (option == "2" || ( (SeachWord("cancel", option)||SeachWord("remove", option)||SeachWord("delete", option))  &&  (SeachWord("flight", option)||SeachWord("flights", option))  ))
    {
        // Book Flight
        printHeader();
        cancelFlight();
    }
    else if (option == "3" || ( (SeachWord("see", option)||SeachWord("show", option)||SeachWord("boooked", option))  &&  (SeachWord("flight", option)||SeachWord("flights", option))  ))
    {
        // Book Flight
        printHeader();
        displaySpecificUserFlight();
    }
    else if ( !SeachWord("see", option) && !SeachWord("remove", option) && (option == "4" || ( (SeachWord("add", option)||SeachWord("new", option)||SeachWord("file", option))  &&  (SeachWord("complain", option)||SeachWord("complains", option))  )))
    {
        // Add Complain
        printHeader();
        addFileComplain();
        
    }
    else if (option == "5" || ( (SeachWord("see", option)||SeachWord("show", option))  &&  (SeachWord("complain", option)||SeachWord("complains", option))  ))
    {
        // See Complain
        printHeader();
        seeComplain();
        
    }
    else if (option == "6" || ( (SeachWord("remove", option)||SeachWord("delete", option))  &&  (SeachWord("complain", option)||SeachWord("complains", option))  ))
    {
        // Remove Complain
        printHeader();
        removeComplain();
        
    }
    else if (option == "7" || SeachWord("food", option)  || SeachWord("Food", option)) 
    {
        // Change Food
        printHeader();
        changeFood();

        
    }
    else if (option == "8" || ( (SeachWord("see", option)||SeachWord("show", option))  &&  (SeachWord("announcements", option)||SeachWord("announcement", option))  ))
    {
        // See announcements
        printHeader();
        seeAnnouncements();
    }
    else if (option == "9" || ( (SeachWord("change", option)||SeachWord("edit", option))  &&  (SeachWord("id", option)||SeachWord("username", option)||SeachWord("Username", option) )  ) ) 
    {
        // Change Id
        printHeader();
        changeId();
        
    }
    else if (option == "10" || ( (SeachWord("change", option)||SeachWord("edit", option))  &&  (SeachWord("password", option)||SeachWord("passward", option)||SeachWord("Password", option) )  ))
    {
        // Change Password
        printHeader();
        changePassword();
        
    }
    else if (option == "11" ||  SeachWord("help", option)  ||  SeachWord("contact", option) || SeachWord("Help", option)  ) 
    {
        printHeader();
        printHelpMenu();
        
    }
    else if (option == "12" ||  SeachWord("exit", option)  ||  SeachWord("Exit", option) )
    {
        exit();
    }
    else 
    {
        cout << "no valid option selected";
        getch();
        printUserInterface();

    }
}


            // Sub Interfaces
void printStartupScreen()
{
    system("cls");
    system("Color 03");
    printHeader();
    cout << "\n\n";
    cout << "     Chose Option" << endl;

    cout << "\n\n\n";
    cout << "\t  1.Login";
    cout << "\n\n";
    cout << "\t  2.Signup";
    cout << "\n\n\n";

    string option;
    // bool allow = 1;
    while(true)
    {
        cout << "\n\n     Enter option: ";
        cin >> option;
        if (option == "1")
        {
            // login Screen
            // printHeader();
            printLoginScreen();
        }
        else if (option == "2")
        {
            // login Screen
            // printHeader();
            printSignupScreen();
        }
        else
        {
            cout << "please select valid option";
        }

    }





}

void printSignupScreen()
{
    printHeader();
    string username, password, role;

    cout << "\n\n";
    cout << "     Chose Option" << endl;

    cout << "\n\n\n";

    while(true)
    {
        cout << "\n";
        cout << "\t Enter Username: ";
        cin >> username;
        gotostartupscreen(username);

        if (checkIdPassword(username, "none") == 1)
        {
            cout << "\t already exist, plz try again\n";
        }
        else{
            break;
        }
    }

    cout << "\n\n";

    
    while(true)
    {
        cout << "\n\t Enter a 10 digit password (must have atleast 7 characters and 3 numeric digits): \n\t ";
        cin >> password;
        gotostartupscreen(password);
        if (newPasswordCheck(password) == 0)
        {
            cout << "\t invalid pass plz enter full\n";
        }
        else{
            break;
        }
    }
    
    cout << "\n";

    while(true)
    {
        cout << "\n\t Chose Admin or User: ";
        cin >> role;
        gotostartupscreen(role);
        if (role == "user" || role == "User")
        {
            role = "User";
            break;
        }
        else if (role == "admin" || role == "Admin")
        {
            role = "Admin";
            break;
        }
        cout << "\t please chose from admin or user\n";
    }


    if (role == "Admin")
    {
        system("cls");
        string adminpass, adminid;
        cout << "\n\n\n";
        cout << "\t to register as admin, you must first ask an admin to enter his credentials\n";
        cout << "\n\n\t Enter Username of a admin: ";
        cin >> adminid;
        cout << "\n\n";
        cout << "\t Enter password for admin : ";
        cin >> adminpass;
        if (checkIdPassword(adminid, adminpass, "isadmin") == 1)
        {
            cout << "\n\t authentecation succesful, Admin ";
            enterIdPassword(username, password, role);
        }
        else{
            cout << "\n\t Admin Cannot be verified, please try again from start";
            getch();
            printHeader();
            printSignupScreen();
        }
        cout << "\n\n\n";
    }
    else if (role == "User")
    {
        cout << "\n\t ";
        enterIdPassword(username, password, role);
    }
    // cout << "\n\n\n";
    // cout << "\t  Enter Username of a admin: ";
    // cout << "\n\n\n";
    // cout << "\t  Enter password for admin : ";
    // cout << "\n\n\n";
    cout << "\n*********************************************************************************************";  
    everyEnd();

    // Startup Screen
    printStartupScreen();
}

void printLoginScreen()
{
    printHeader();
    string username, password;
    cout << "\n\n";
    cout << "     Chose Option" << endl;

    bool correctinfo = false;

    cout << "\n\n\n";
    while(correctinfo == false)
    {
        cout << "\t Enter Username: ";
        cin >> username;
        gotostartupscreen(username);
        cout << "\n\n";
        cout << "\t Enter Password: ";
        cin >> password;
        gotostartupscreen(password);

        if (checkIdPassword(username, password, "unknown") == 1)
        {
            cout << "\n\t Authentication successful";
            correctinfo = true;
            for (int i = 0; i <= nr_users; i++)
            {
                if (Username[i] == username)
                {
                    currentId = Username[i];
                    currentrole = Role[i];
                }
            }
        }
        else{
            cout << "\n\t Authentication unsuccessful, plz try again";
            Sleep(1500);
            printLoginScreen();
            cout << "\n\n";
        }
    }
    cout << "\n\n\n";


    everyEnd();

    if (isAnimShown == false)
    {
        animStartupOneTimeAnim();
        isAnimShown = true;
    }

    if (currentrole == "Admin")
    {
        // User Admin Screen
        printHeader();
        printAdminInterface();
        printEnterOption();
    }
    else if (currentrole == "User")
    {
        // User interface Screen
        // printHeader();
        printUserInterface();
        printEnterOption();
    }

}

void printHeader()
{
    system("cls");
    cout << "\n\n";

    cout << "\n";
    // cout << "\t\t\t\tflight management system                         " ;
    cout << "\t\t\t\tFLIGHT MANAGEMENT SYSTEM                         " ;
    cout << "\n" ;
    cout << "*********************************************************************************************" << endl;
    cout << "                                                                 " << printTime();

}

void printUniqueLines()
{
	cout<<"\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout  <<"\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"<<endl;

}


            // ============================================================= //


void printEnterOption()
{
    cout << "\n\n";
    cout << "    Enter Your Option...";
}


void everyEnd()
{
    cout << "\n\n     enter any key to continue";
    getch();
}


void exit()
{
    currentrole = "none";
    currentId = "none";

    // startup Screen
    // system("cls");
    // printHeader();
    printStartupScreen();
    printEnterOption();
}


//        ==================================  //
//          anim functions                    //

void animprintRoboInterface()
{
{
cout <<  "                      ****                                                                                    " << endl;
cout <<  "            ,,,,,,,,,,,,,,,,,,,,,,,,,                                                                         " << endl;
cout <<  "           /#%####/@@(#####@@@(###///                                                                         " << endl;
cout <<  "         *..##                   #///..,                  #################################################   " << endl;
cout <<  "         ,####     ##      ##    #///##*                  #                                               #   " << endl;
cout <<  "         *,%##                   *////,,                  #        The above you see is the interface     #   " << endl;
cout <<  "          .&##                   /////,                   #        You can select a choice from there     #   " << endl;
cout <<  "          .,,,,,,,,,,,,,,,,,,,,,,,,,,,*                   #                                               #   " << endl;
cout <<  "           ,,,,,,,,,,,,,,,,,,,,,,,,,,.                    #        We are proud to announce that          #   " << endl;
cout <<  "           ,,,,#@@@@@@@@@@@@@@@@@#,,,,                    #     our selection is not limited to numbers   #   " << endl;
cout <<  "         /,,,,,#@@@@@@@@@@@%@@@@@#,,,,,                   #       You can try LITERALLY ANYTHING like,    #   " << endl;
cout <<  "        *,,,,  #%%@@#@/@@@@@&@&&%#,,,,,,                  #                                               #   " << endl;
cout <<  "       ,,,,*   #@@@@@@@@@@@@@@@@@#,  ,,,,,                #      ---> I want to remove a flight           #   " << endl;
cout <<  "   . ,,,,,.    ##(##/,,,,,,,,##(##,   ,,,,,, ,            #      ---> Show me complains added by users    #   " << endl;
cout <<  " ,,,,,,,,      #(,,#,,,,,,,,,##,,#,     ,,,,,,,,,         #                                               #   " << endl;
cout <<  ",,,. ,,,,*      ..,@%###(**(####&,.       ,,,, ,,         #       any many more, or you can stick to      #   " << endl;
cout <<  "* .,,,.          ,%#(((/,,/####&,         .,,,            #       traditional 0s and 1. Your choice.      #   " << endl;
cout <<  "                 ,(((((/,,/####&*                         #                                               #   " << endl;
cout <<  "                 *%#(((/,,/####&(                         #       For any problem, see help menu...       #   " << endl;
cout <<  "             ,%%########//#########%,                     #################################################   " << endl;
cout <<  "            #########(///(//((########                                                                        " << endl;           
}    
}

void animhowToUseFull()
{
    system("cls");
    // getch();
    cout << "\n\n";
    animprintHowToLogo();
    cout << "\n\n";
    animprintRobo();
    getch();
}

void animprintHowToLogo()
{
cout << "             _    _                 _______       _    _              _____       _     _        "<< endl;
cout << "            | |  | |               |__   __|     | |  | |            / ____|     (_)   | |       "<< endl;
cout << "            | |__| | _____      __    | | ___    | |  | |___  ___    | |  __ _   _ _  __| | ___   "<< endl;
cout << "            |  __  |/ _ | | /| / /    | |/ _  |  | |  | / __|/ _  |  | | |_ | | | | |/ _` |/ _  |  "<< endl;
cout << "            | |  | | (_) | V  V /     | | (_) |  | |__|  |__ |  __/  | |__| | |_| | | (_| |  __/  "<< endl;
cout << "            |_|  |_| |___/ |_/|_/     |_| |___/  |____/|___/ |___|   |_____| |__,_|_| |__,_| |___|  "<< endl;
}

void animprintRobo()
{
cout <<  "                      ****                                                                                    " << endl;
cout <<  "            ,,,,,,,,,,,,,,,,,,,,,,,,,                                                                         " << endl;
cout <<  "           /#%####/@@(#####@@@(###///                                                                         " << endl;
cout <<  "         *..##                   #///..,                                                                      " << endl;
cout <<  "         ,####     ##      ##    #///##*                  #################################################   " << endl;
cout <<  "         *,%##                   *////,,                  #                                               #   " << endl;
cout <<  "          .&##                   /////,                   #                                               #   " << endl;
cout <<  "          .,,,,,,,,,,,,,,,,,,,,,,,,,,,*                   #        Hi i am Robo, Your assistant.          #   " << endl;
cout <<  "           ,,,,,,,,,,,,,,,,,,,,,,,,,,.                    #                                               #   " << endl;
cout <<  "           ,,,,#@@@@@@@@@@@@@@@@@#,,,,                    #        Welcome to our Flight company          #   " << endl;
cout <<  "         /,,,,,#@@@@@@@@@@@%@@@@@#,,,,,                   #                                               #   " << endl;
cout <<  "        *,,,,  #%%@@#@/@@@@@&@&&%#,,,,,,                  #         We want you to know you made          #   " << endl;
cout <<  "       ,,,,*   #@@@@@@@@@@@@@@@@@#,  ,,,,,                #       the right choice, let us start by       #   " << endl;
cout <<  "   . ,,,,,.    ##(##/,,,,,,,,##(##,   ,,,,,, ,            #        giving a quick how to use guide.       #   " << endl;
cout <<  " ,,,,,,,,      #(,,#,,,,,,,,,##,,#,     ,,,,,,,,,         #                                               #   " << endl;
cout <<  ",,,. ,,,,*      ..,@%###(**(####&,.       ,,,, ,,         #          PRESS ANYTHING TO CONTINUE...        #   " << endl;
cout <<  "* .,,,.          ,%#(((/,,/####&,         .,,,            #                                               #   " << endl;
cout <<  "                 ,(((((/,,/####&*                         #################################################   " << endl;
cout <<  "                 *%#(((/,,/####&(                                                                             " << endl;
cout <<  "             ,%%########//#########%,                                                                         " << endl;
cout <<  "            #########(///(//((########                                                                        " << endl;           
}              

void animprintAdminInterface()
{

    // printHeader();
    cout << "\n\n";
    cout << "    Chose Option" << endl;
 
    cout << "\n\n";
    cout << "\t  1. Add Flight                                7. Search Flights";
    cout << "\n";
    cout << "\t  2. Remove Flight                             8. Remove customer";
    cout << "\n";
    cout << "\t  3. Check Booked Flights                      9. Add announcement";
    cout << "\n";
    cout << "\t  4. See Complain Box                          10. Remove announcement ";
    cout << "\n";
    cout << "\t  5. Change Appearence                         11. Modify announcement ";
    cout << "\n";
    cout << "\t  6. Change Contact info                       12. Exit ";
    cout << "\n\n";
 
    cout << "\n\n\tEnter your choice: ";
}

void animStartupOneTimeAnim()
{
    animhowToUseFull();
    system("cls");

    printHeader();
    animprintAdminInterface();
    cout << "\n\n";
    animprintRoboInterface();
    getch();  
}

         //       VERSION 2.0 CHANGES   //
void storeIdPass()
{
    fstream file1;
    file1.open("textFiles/id_Pass.txt", ios::out);

    for( int i= 0 ; i <= nr_users ; i++)
    {
        file1 << Username[i] << "," << Password[i] << "," << Role[i] << endl;
    }
    file1.close();
}

void loadIdPass()
{
    nr_users = 0;
    string record = "";

    fstream file1;
    file1.open("textFiles/id_Pass.txt", ios::in);

    while(getline(file1, record))
    {
        Username[nr_users] = getFieldFromRecord(record, 0);
        Password[nr_users] = getFieldFromRecord(record, 1);
        Role[nr_users] = getFieldFromRecord(record, 2);
        nr_users += 1;
    }
    nr_users -=1;
    file1.close();
}

void storeAnnouncments()
{
    fstream file1;
    file1.open("textFiles/announcements.txt", ios::out);

    for( int i= 0 ; i <= nr_announcements ; i++)
    {
        file1 << announcmentMessage[i] << endl;
    }
    file1.close();
}

void loadAnnouncments()
{
    nr_announcements = 0;
    string record = "";

    fstream file1;
    file1.open("textFiles/announcements.txt", ios::in);

    while(getline(file1, record))
    {
        announcmentMessage[nr_announcements] = record;
        nr_announcements += 1;
    }
    nr_announcements -=1;
    file1.close();
}

void storeAvailableFlights()
{
    fstream file1;
    file1.open("textFiles/availableFlights.txt", ios::out);

    for( int i= 0 ; i <= nr_flights ; i++)
    {
        file1 << flightFrom[i] << "," << flightDestination[i] << "," << flightDate[i] << "," << flightPrice[i] << endl;
    }
    file1.close();
}

void loadAvailableFlights()
{
    nr_flights = 0;
    string record = "";

    fstream file1;
    file1.open("textFiles/availableFlights.txt", ios::in);

    while(getline(file1, record))
    {
        flightFrom[nr_flights] = getFieldFromRecord(record, 0);
        flightDestination[nr_flights] = getFieldFromRecord(record, 1);
        flightDate[nr_flights] = getFieldFromRecord(record, 2);
        flightPrice[nr_flights] = getFieldFromRecord(record, 3);
        nr_flights += 1;
    }
    nr_flights -=1;
    file1.close();
}

void storeBookedFlights()
{
    fstream file1;
    file1.open("textFiles/BookedFlights.txt", ios::out);

    for( int i= 0 ; i <= nr_booking ; i++)
    {
        file1 << bookedUsersId[i] << "," << bookedUsersFlight[i] << "," << bookedUsersFood[i] << endl;
    }
    file1.close();
}

void loadBookedFlights()
{
    nr_booking = 0;
    string record = "";

    fstream file1;
    file1.open("textFiles/BookedFlights.txt", ios::in);

    while(getline(file1, record))
    {
        bookedUsersId[nr_booking] = getFieldFromRecord(record, 0);
        bookedUsersFlight[nr_booking] = stoi(getFieldFromRecord(record, 1));
        bookedUsersFood[nr_booking] = getFieldFromRecord(record, 2);
        nr_booking += 1;
    }
    nr_booking -=1;
    file1.close();
}

void storeComplains()
{
    fstream file1;
    file1.open("textFiles/Complains.txt", ios::out);

    for( int i= 0 ; i <= nr_complains ; i++)
    {
        file1 << complainId[i] << endl << complainMessages[i] << endl;
    }
    file1.close();
}

void loadComplains()
{
    nr_complains = 0;
    string record = "";

    fstream file1;
    file1.open("textFiles/Complains.txt", ios::in);

    while(getline(file1, record))
    {
        complainId[nr_complains] = record;
        getline(file1, record);
        complainMessages[nr_complains] = record;
        nr_complains += 1;
    }
    nr_complains -=1;
    file1.close();
}

void loadAllFiles()
{
    loadIdPass();
    loadAnnouncments();
    loadAvailableFlights();
    loadBookedFlights();
    loadComplains();
}

string getFieldFromRecord(string record, int option)
{
    int count = 0;
    string field = "";
    for (int i = 0; i < record.length(); i++)
    {
        if (record[i] == ',')
        {
            count ++;
        }
        else if (count == option)
        {
            field = field + record[i];
        }
    }
    return field;
}

