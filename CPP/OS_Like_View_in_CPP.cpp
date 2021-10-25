//==============================================================================
//                           LIBRARIES OR HEADERZ
//==============================================================================
 
 #define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>
#include <mmsystem.h>
#include <strmif.h>
#include <control.h>
 #include<iostream>
 #include<conio.h>
 #include<fstream>
 #include<math.h>
 #include<string.h>
 #include<stdio.h>
 #include<windows.h>
 #include<iomanip>
 #include<dos.h>
 
 



 
 using namespace std;
 
 #pragma comment(lib, "strmiids.lib")
 
 int box1()
{cout<<"   ";
     for(int a=1;a<=7;a++)
        {
            cout<<"-";
        }
            cout<<endl;
            
for(int b=1;b<=2;b++)
    {
    for(int c=1;c<=1;c++)
        {
                cout<<"   |";
        }
        for(int d=1;d<=5;d++)
              {
                cout<<" ";
              }
                cout<<"|"<<endl;
       }
       cout<<" ";
for(int e=1;e<=11;e++)
 {
 cout<<"-";
 }
 
 
 
 for(int b=1;b<=2;b++)
    {if(b==1)
    {cout<<"\n";
	}
	
    
        for(int d=1;d<=5;d++)
              {if(b==1)
              continue;
              else
			  {
			  
			   cout<<"l";
              }
                cout<<"*"<<endl;
       }
       cout<<" ";
for(int e=1;e<=11;e++)
 {
 cout<<"-";
 }
 
 cout<<"\n MY COMPUTER";
 cout<<"\n";
 return 0;
}}

int box2()
{cout<<"   ";
     for(int a=1;a<=7;a++)
        {
            cout<<" ";
        }
            cout<<endl;
            
for(int b=1;b<=2;b++)
    {
    for(int c=1;c<=1;c++)
        {
                cout<<"   |";
        }
        for(int d=1;d<=5;d++)
              {
                cout<<" ";
              }
                cout<<"|"<<endl;
       }
       cout<<"   ";
for(int e=1;e<=7;e++)
 {
 cout<<"-";
 }
 
 
 

 
 cout<<"\n RECYCLE BIN";
 cout<<"\n";
 return 0;
}
 
int box3()
{cout<<"   ";

     for(int a=1;a<=7;a++)
        {
            cout<<"-";
        }
            cout<<endl;
            
for(int b=1;b<=2;b++)
    {
    for(int c=1;c<=1;c++)
        {
                cout<<"   |";
        }
        for(int d=1;d<=5;d++)
              {
                cout<<" ";
              }
                cout<<"|"<<"------\n";
       }
       cout<<"   ";
for(int e=1;e<=7;e++)
 {
 cout<<"-";
 }
 
 
 

 
 cout<<"\n CONTROL PANNEL";
 cout<<"\n";
 return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
// Map dimensions
const int mapwidth = 20;
const int mapheight = 20;

const int size = 400;

// The tile values for the map
int map[size];

// Snake head details
int headxpos;
int headypos;
int direction;

// Amount of food the snake has (How long the body is)
int food = 3;

// Determine if game is running
bool running;
 
int headerr()
{
		cout<<"                            ALEX MERCER OPERATING SYSTEM                    ";
cout<<"\n";
cout<<"\n";
cout<<"\n===============================================================================";
cout<<"\n";

	
}

void generateFood() {
    int x = 0;
    int y = 0;
    do {
        // Generate random x and y values within the map
        x = rand() % (mapwidth - 2) + 1;
        y = rand() % (mapheight - 2) + 1;

        // If location is not free try again
    } while (map[x + y * mapwidth] != 0);

    // Place new food
    map[x + y * mapwidth] = -2;
}



char getMapValue(int value)
{
    // Returns a part of snake body
    if (value > 0) return 'o';

    switch (value) {
        // Return wall
    case -1: return 'X';
        // Return food
    case -2: return 'O';
    }
}

void move(int dx, int dy) {
    // determine new head position
    int newx = headxpos + dx;
    int newy = headypos + dy;

    // Check if there is food at location
    if (map[newx + newy * mapwidth] == -2) {
        // Increase food value (body length)
        food++;

        // Generate new food on map
        generateFood();
    }

    // Check location is free
    else if (map[newx + newy * mapwidth] != 0) {
        running = false;
    }

    // Move head to new location
    headxpos = newx;
    headypos = newy;
    map[headxpos + headypos * mapwidth] = food + 1;

}

void printMap()
{
    for (int x = 0; x < mapwidth; ++x) {
        for (int y = 0; y < mapheight; ++y) {
            // Prints the value at current x,y location
            std::cout << getMapValue(map[x + y * mapwidth]);
        }
        // Ends the line for next x value
        std::cout << std::endl;
    }
}

void initMap()
{
    // Places the initual head location in middle of map
    headxpos = mapwidth / 2;
    headypos = mapheight / 2;
    map[headxpos + headypos * mapwidth] = 1;

    // Places top and bottom walls 
    for (int x = 0; x < mapwidth; ++x) {
        map[x] = -1;
        map[x + (mapheight - 1) * mapwidth] = -1;
    }

    // Places left and right walls
    for (int y = 0; y < mapheight; y++) {
        map[0 + y * mapwidth] = -1;
        map[(mapwidth - 1) + y * mapwidth] = -1;
    }

    // Generates first food
    generateFood();
}

void update() {
    // Move in direction indicated
    switch (direction) {
    case 0: move(-1, 0);
        break;
    case 1: move(0, 1);
        break;
    case 2: move(1, 0);
        break;
    case 3: move(0, -1);
        break;
    }

    // Reduce snake values on map by 1
    for (int i = 0; i < size; i++) {
        if (map[i] > 0) map[i]--;
    }
}



void clearScreen() {
    // Clear the screen
    system("cls");
}



void changeDirection(char key) {
    /*
      W
    A + D
      S
      1
    4 + 2
      3
    */
    switch (key) {
    case 'w':
        if (direction != 2) direction = 0;
        break;
    case 'd':
        if (direction != 3) direction = 1;
        break;
    case 's':
        if (direction != 4) direction = 2;
        break;
    case 'a':
        if (direction != 5) direction = 3;
        break;
    }
}


void run()
{
    // Initialize the map
    initMap();
    running = true;
    while (running) {
        // If a key is pressed
        if (kbhit()) {
            // Change to direction determined by key pressed
            changeDirection(getch());
        }
        // Upate the map
        update();

        // Clear the screen
        clearScreen();

        // Print the map
        printMap();

        // wait 0.5 seconds
        _sleep(500);
    }

    // Print out game over text
    std::cout << "\t\t!!!Game over!" << std::endl << "\t\tYour score is: " << food;

    // Stop console from closing instantly
    std::cin.ignore();
}

char getMapValue(int value);



 
bool validPick(int numStones)
{   
    if((numStones < 1) || (numStones >3))
        cout << "Invalid Selection. 1-3 is all you can have!";
    else
        return numStones;
}

int computerPick(int stones_in_pile, int player2taken)
{
    if(player2taken == 0)
        stones_in_pile -= 1;
    else
    {
        if(player2taken == 1)
            stones_in_pile -= 3;
            else
                if(player2taken == 2)
                    stones_in_pile -= 2;
                        else
                            stones_in_pile -=1;
    }
    return stones_in_pile;  

}

int playerPick(int stones_in_pile)
{
    cout << "Please choose the ammount of stones. 1-3 only! : ";
    cin >> stones_in_pile;
    return stones_in_pile;
}

 int student()
 {{

    FILE *fp, *ft;

    char another, choice;



struct student {

        char first_name[50], last_name[50];

        char course[100];

        int section;

    };



    struct student e;
    char xfirst_name[50], xlast_name[50];
    long int recsize;

    fp=fopen("users.txt","rb+");

    if (fp == NULL) {
        fp = fopen("users.txt","wb+");

        if (fp==NULL)
        {
             puts("Cannot open file");
             return 0;
        }
    }


 recsize = sizeof(e);

 while(1) {
     system("cls");
     	system("cls");
	headerr();
     cout << "\t\t====== STUDENT INFORMATION SYSTEM ======";
     cout <<"\n\n                                          ";
     cout << "\n\n";
     cout<<" \n\t\t\t===========================================";
     cout << "\n \t\t\t  1.        Add         Records";
     cout << "\n \t\t\t  2.        List        Records";
     cout << "\n \t\t\t  3.        Modify      Records";
     cout << "\n \t\t\t  4.        Delete      Records";
     cout << "\n \t\t\t  5.        Exit        Program";
     cout<<" \n\t\t\t===========================================";
     cout << "\n\n";
     cout << "\t\t\t Select Your Choice ::";
     fflush(stdin);
     choice = getche();
     switch(choice)
     {
      case '1' :
            fseek(fp,0,SEEK_END);
            another ='Y';
            while(another == 'Y' || another == 'y')
            {
                  system("cls");
                  	system("cls");
	headerr();
                cout << "Enter the First Name : ";
                cin >> e.first_name;
                cout << "Enter the Last Name : ";
                cin >> e.last_name;
                cout << "Enter the Course    : ";
                cin >> e.course;
                cout << "Enter the Section   : ";
                cin >> e.section;
                fwrite(&e,recsize,1,fp);
                cout << "\n Add Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;
   case '2':
            system("cls");
            	system("cls");
	headerr();
           rewind(fp);
           cout << "=== View the Records in the Database ===";
           cout << "\n";
           while (fread(&e,recsize,1,fp) == 1){
           cout << "\n";
           cout <<"\nName     :: " <<e.first_name <<" "<<e.last_name;
           //cout << "\n";
           cout <<"\nCourse   :: " <<e.course ;
           cout <<"\nSection  :: "<<e.section;
           }
           cout << "\n\n";
           system("pause");
           break;

   case '3' :
            system("cls");
            	system("cls");
	headerr();
          another = 'Y';
          while (another == 'Y'|| another == 'y')
          {
              cout << "\n Enter the last name of the student : ";
              cin >> xlast_name;

            rewind(fp);
            while (fread(&e,recsize,1,fp) == 1)
            {
                if (strcmp(e.last_name,xlast_name) == 0)
                {
                cout << "Enter new the Firt Name : ";
                cin >> e.first_name;
                cout << "Enter new the Last Name : ";
                cin >> e.last_name;
                cout << "Enter new the Course    : ";
                cin >> e.course;
                cout << "Enter new the Section   : ";
                cin >> e.section;
                fseek(fp, - recsize, SEEK_CUR);
                fwrite(&e,recsize,1,fp);
                break;
                }
                else
                cout<<"record not found";
            }
            cout << "\n Modify Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;


     case '4':
       system("cls");
       	system("cls");
	headerr();
           another = 'Y';
          while (another == 'Y'|| another == 'y')
          {
              cout << "\n Enter the last name of the student to delete : ";
              cin >> xlast_name;

              ft = fopen("temp.dat", "wb");

              rewind(fp);
              while (fread (&e, recsize,1,fp) == 1)

                 if (strcmp(e.last_name,xlast_name) != 0)
                {
                    fwrite(&e,recsize,1,ft);
                }
                fclose(fp);
                fclose(ft);
                rename("users.txt","rec.txt");
                rename("temp.dat","users.txt");

                fp=fopen("users.txt","rb+");

                cout << "\n Delete Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
              }

              break;

              case '5':
              fclose(fp);
              cout << "\n\n";
              cout << "\t\t     THANK YOU FOR USING THIS SOFTWARE";
              cout << "\n\n";
              exit(0);
          }
     }
system("pause");
return 0;
}
 }
//==============================================================================
//                       FUNCTION FOR THE AXIS (GOTOXY)
//==============================================================================
 void gotoxy(int x, int y){
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//==============================================================================
//                      FUNCTIONZ TO CLEAR CONSOLE WINDOWZ
//==============================================================================
void clearWindow(){
     int i,j;
     for(i=15; i<65; i++){
           for(j=0; j<25; j++){
                 gotoxy(i,j); printf(" ");
        }
    }
    return;
}
void clearWindowz(){
     int i,j;
     for(i=1; i<80; i++){
           for(j=0; j<25; j++){
                 gotoxy(i,j); printf(" ");
        }
    }
    return;
}
//==============================================================================
//                               MAIN CLASS
//==============================================================================
  class Bank {
        
        public:
               char fname[12], lname[12], nationality[30], accType;
               int openAmt, accNo;
        private:
                int i;
        public:
        // ADMIN FUNCTIONZ
        char openAcc(){
             clearWindow();
             	system("cls");
	headerr();
             int i;
             accNo = rand() % 100 + 10;
             gotoxy(15,3); printf("\xC9"); // Left upper corner 
             for(i=1;i<=48;i++) printf("\xCD"); // Upper horizontal line 
             gotoxy(64,3); printf("\xBB"); // Right upper corner
             gotoxy(15,24); printf("\xC8"); // Lower left corner
             for(i=1;i<=48;i++) printf("\xCD"); // Lower horizontal line 
             gotoxy(64,24); printf("\xBC"); // Lower right corner
             for(i=1;i<21;i++){ gotoxy(15,i+3); printf("\xBA");}// Left vertical
             for(i=1;i<21;i++){ gotoxy(64,i+3); printf("\xBA");}// Right vertical
             
             //=================================================================
             gotoxy(8+19,0); printf("\xC9"); // Upper left corner
             for(i=1;i<=25;i++) printf("\xCD"); // Upper horizontal line 
             gotoxy(52,0); printf("\xBB"); // Upper right corner
             gotoxy(8+19,2); printf("\xC8"); // Lower left corner
             for(i=1;i<=25;i++) printf("\xCD"); // Lower horizontal line 
             gotoxy(52,2); printf("\xBC"); // Lower right corner
             for(i=1;i<2;i++){ gotoxy(27,i+0); printf("\xBA");}// Left vertical
             for(i=1;i<2;i++){ gotoxy(52,i+0); printf("\xBA");}// Right vertical
             
             //=================================================================
             // SMALL BOX
             //=================================================================
             gotoxy(17,4); printf("%c",218); // Left Upper Corner
             gotoxy(62,4); printf("%c",191); // Right Upper Corner 
             gotoxy(17,23); printf("%c",192); // Left Lower Corner
             gotoxy(62,23); printf("%c",217); // Right Lower Corner
             for(i=1;i<=44;i++) { gotoxy(17+i,4); printf("%c",196);}// Upper Horizontal
             for(i=1;i<=44;i++) { gotoxy(17+i,23); printf("%c",196);}// Lower Horizontal
             for(i=1;i<=44;i++) { gotoxy(17+i,19); printf("%c",196);}// Middle horizontal
             for(i=1;i<=18;i++) { gotoxy(17,4+i); printf("%c",179);}// Left Vertical
             for(i=1;i<=18;i++) { gotoxy(62,4+i); printf("%c",179);}// Right VerticaL
             gotoxy(31,1); std::cout<<" ALEX MERCER BANK INC.";
             gotoxy(19,4); std::cout<<" ADD RECORD ";
             gotoxy(18,7); std::cout<<" FIRST NAME : ";
             gotoxy(18,9); std::cout<<" OTHER NAME : ";
             gotoxy(18,11); std::cout<<" NATIONALITY : ";
             gotoxy(18,13); std::cout<<" ACCOUNT TYPE [C/S] : ";
             gotoxy(18,15); std::cout<<" OPENING AMOUNT [C=1000 /S=500] : ";
             gotoxy(18,17); std::cout<<" ACCOUNT NUMBER : ";
             gotoxy(36,19); std::cout<<" NOTE ";
             gotoxy(25,21); std::cout<<" USE UNDERSCORE FOR SPACES... ";
             gotoxy(32,7); std::cin>>fname;
             gotoxy(32,9); std::cin>>lname;
             gotoxy(33,11); std::cin>>nationality;
             gotoxy(40,13); std::cin>>accType;
             accType=toupper(accType);
             gotoxy(52,15); std::cin>>openAmt;
             gotoxy(36,17); std::cout<<accNo;
             gotoxy(25,21); std::cout<<" ACCOUNT OPENED SUCCESSFULLY!";
             getch();
        }
        
        void viewAcc1(){
        	
        		system("cls");
	headerr();
             gotoxy(18,9); std::cout<<" FIRST NAME : ";
             gotoxy(18,11); std::cout<<" OTHER NAME : ";
             gotoxy(18,13); std::cout<<" NATIONALITY : ";
             gotoxy(18,15); std::cout<<" ACCOUNT TYPE [C/S] : ";
             gotoxy(18,17); std::cout<<" OPENING AMOUNT [C=1000 /S=500] : ";
             //=================================================================
             // SMALL ACCOUNT NUMBER BOX
             //=================================================================
             gotoxy(31,5); printf("%c",218); // Left Upper Corner
             gotoxy(48,5); printf("%c",191); // Right Upper Corner 
             gotoxy(31,7); printf("%c",192); // Left Lower Corner
             gotoxy(48,7); printf("%c",217); // Right Lower Corner
             for(i=1;i<=16;i++) { gotoxy(31+i,5); printf("%c",196);}// Upper Horizontal
             for(i=1;i<=16;i++) { gotoxy(31+i,7); printf("%c",196);}// Lower Horizontal
             for(i=1;i<=1;i++) { gotoxy(30+i,6); printf("%c",179);}// Left Vertical
             for(i=1;i<=1;i++) { gotoxy(48,5+i); printf("%c",179);}// Right Vertical
             gotoxy(32,9); std::cout<<fname;
             gotoxy(32,11); std::cout<<lname;
             gotoxy(33,13); std::cout<<nationality;
             gotoxy(40,15); std::cout<<accType;
             gotoxy(52,17); std::cout<<openAmt;
             gotoxy(33,19); std::cout<<" NOTIFICATION ";
             gotoxy(32,6); std::cout<<" ACCOUNT NO: ";
             gotoxy(44,6); std::cout<<accNo;
        }
            
        void viewAllAcc(){
        		system("cls");
	headerr();
             int i, n;
             gotoxy(1,3); printf("\xC9"); // Upper left corner
             for(i=1;i<=76;i++) printf("\xCD"); // Upper left right horizontal  
             gotoxy(78,3); printf("\xBB"); // Upper right corner
             gotoxy(1,24); printf("\xC8"); // Lower left corner
             for(i=1;i<=76;i++) printf("\xCD"); // Lower left right horizontal 
             gotoxy(78,24); printf("\xBC"); // Lower right corner
             for(i=1;i<21;i++){ gotoxy(1,i+3); printf("\xBA");}// Left vertical
             for(i=1;i<21;i++){ gotoxy(78,i+3); printf("\xBA");}// Right vertical
             
             //=================================================================
             gotoxy(8+19,0); printf("\xC9"); // Upper left corner
             for(i=1;i<=25;i++) printf("\xCD"); // Upper left right horizontal 
             gotoxy(52,0); printf("\xBB"); // Upper right corner
             gotoxy(8+19,2); printf("\xC8"); // Lower left corner
             for(i=1;i<=25;i++) printf("\xCD"); // Lower left right horizontal  
             gotoxy(52,2); printf("\xBC"); // Lower right corner
             for(i=1;i<2;i++){ gotoxy(27,i+0); printf("\xBA");}// Left vertical 
             for(i=1;i<2;i++){ gotoxy(52,i+0); printf("\xBA");}// Right vertical
             
             //=================================================================
             // SMALL BOX
             //=================================================================
            gotoxy(3,4); printf("%c",218); // Left Upper Corner
            gotoxy(76,4); printf("%c",191); // Right Upper Corner 
            gotoxy(3,23); printf("%c",192); // Left Lower Corner
            gotoxy(76,23); printf("%c",217); // Right Lower Corner
            for(i=1;i<=72;i++) { gotoxy(3+i,4); printf("%c",196);}// Upper Horizontal
            for(i=1;i<=72;i++) { gotoxy(3+i,23); printf("%c",196);}// Lower Horizontal
            for(i=1;i<=72;i++) { gotoxy(3+i,20); printf("%c",196);}// Middle horizontal
            for(i=1;i<=18;i++) { gotoxy(3,4+i); printf("%c",179);}// Left Vertical
            for(i=1;i<=18;i++) { gotoxy(76,4+i); printf("%c",179);}// Right Vertical
            gotoxy(31,1); std::cout<<" ALEX MERCER BANK INC.";
            gotoxy(5,4); std::cout<<" VIEW ALL ACCOUNTS ";
            gotoxy(32,20); std::cout<<" NOTIFICATION ";
            for(i=1;i<=70;i++) { gotoxy(4+i,7); printf("%c",196); }
            gotoxy(4,6); std::cout<<" ACC_NO ";
            gotoxy(13,6); std::cout<<" FIRST_NAME ";
            gotoxy(26,6); std::cout<<" LAST_NAME ";
            gotoxy(38,6); std::cout<<" NATIONALITY ";
            gotoxy(52,6); std::cout<<" ACC_TYPE ";
            gotoxy(63,6); std::cout<<" ACC_BALANCE ";
            gotoxy(20,22); std::cout<<" PRESS ENTER TO GO BACK TO MAIN MENU... ";
            }
            
        void delviewAcc(){
        		system("cls");
	headerr();
             gotoxy(18,7); std::cout<<" FIRST NAME : ";
             gotoxy(18,9); std::cout<<" OTHER NAME : ";
             gotoxy(18,11); std::cout<<" NATIONALITY : ";
             gotoxy(18,13); std::cout<<" ACCOUNT TYPE [C/S] : ";
             gotoxy(18,15); std::cout<<" OPENING AMOUNT [C=1000 /S=500] : ";
             gotoxy(32,7); std::cout<<fname;
             gotoxy(32,9); std::cout<<lname;
             gotoxy(33,11); std::cout<<nationality;
             gotoxy(40,13); std::cout<<accType;
             gotoxy(52,15); std::cout<<openAmt;
             gotoxy(33,19); std::cout<<" NOTIFICATION ";
             gotoxy(19,21); std::cout<<" DELETE THIS RECORD? [Y/N] : ";
        }
            
        void adminMenuGraphicz(){
        		system("cls");
	headerr();
             gotoxy(16,5); printf("\xC9"); // Upper left corner
             for(i=1;i<=47;i++) printf("\xCD"); // Upper left right horizontal 
             gotoxy(64,5); printf("\xBB"); // Upper right corner
             gotoxy(16,23); printf("\xC8"); // Lower left corner
             for(i=1;i<=47;i++) printf("\xCD"); // Lower left right horizontal 
             gotoxy(64,23); printf("\xBC"); // Lower right corner
             for(i=1;i<18;i++){ gotoxy(16,i+5); printf("\xBA");}// Left vertical
             for(i=1;i<18;i++){ gotoxy(64,i+5); printf("\xBA");}// Right vertical
             gotoxy(16,19); printf("\xCC"); // Left inside lower corner
             for(i=1;i<=47;i++) printf("\xCD"); // Inside lower left right horizontal 
             gotoxy(64,19); printf("\xB9"); // Right inside lower corner
             
             //=================================================================
             gotoxy(8+19,2); printf("\xC9"); // Upper left corner
             for(i=1;i<=25;i++) printf("\xCD"); // Upper left right horizontal 
             gotoxy(52,2); printf("\xBB"); // Upper right corner
             gotoxy(8+19,4); printf("\xC8"); // Lower left corner
             for(i=1;i<=25;i++) printf("\xCD"); // Lower left to right horizontal 
             gotoxy(52,4); printf("\xBC"); // Lower right corner
             for(i=1;i<2;i++){ gotoxy(27,i+2); printf("\xBA");} // Left vertical
             for(i=1;i<2;i++){ gotoxy(52,i+2); printf("\xBA");}// Right vertical
             
             //=================================================================
             gotoxy(45,7); printf("\xC9"); // Upper left corner
             for(i=1;i<=16;i++) printf("\xCD"); // Upper left right horizontal 
             gotoxy(62,7); printf("\xBB"); // Upper right corner
             gotoxy(45,17); printf("\xC8"); // Lower left corner
             for(i=1;i<=16;i++) printf("\xCD"); // Lower left right horizontal 
             gotoxy(62,17); printf("\xBC"); // Lower right corner
             for(i=1;i<10;i++){ gotoxy(45,i+7); printf("\xBA"); } // Left vertical
             for(i=1;i<10;i++){ gotoxy(62,i+7); printf("\xBA"); }// Right vertical
        }
             
        void deleteRecordGraphicz(){
        		system("cls");
	headerr();
             gotoxy(15,3); printf("\xC9"); // Upper left corner
             for(i=1;i<=48;i++) printf("\xCD"); // Upper left right horizontal 
             gotoxy(64,3); printf("\xBB"); // Upper right corner
             gotoxy(15,24); printf("\xC8"); // Lower left corner
             for(i=1;i<=48;i++) printf("\xCD"); // Lower left right horizontal 
             gotoxy(64,24); printf("\xBC"); // Lower right corner
             for(i=1;i<21;i++){ gotoxy(15,i+3); printf("\xBA"); } // Left vertical
             for(i=1;i<21;i++){ gotoxy(64,i+3); printf("\xBA"); }// Right vertical
             
             //=================================================================
             gotoxy(8+19,0); printf("\xC9"); // Upper left corner
             for(i=1;i<=25;i++) printf("\xCD"); // Upper left right horizontal 
             gotoxy(52,0); printf("\xBB"); // Upper right corner
             gotoxy(8+19,2); printf("\xC8"); // Lower left corner
             for(i=1;i<=25;i++) printf("\xCD"); // Lower left right horizontal 
             gotoxy(52,2); printf("\xBC"); // Lower right corner
             for(i=1;i<2;i++){ gotoxy(27,i+0); printf("\xBA"); } // Left vertical
             for(i=1;i<2;i++){ gotoxy(52,i+0); printf("\xBA"); }// Right vertical
             
             //=================================================================
             // SMALL BOX
             //=================================================================
             gotoxy(17,4); printf("%c",218); // Left Upper Corner
             gotoxy(62,4); printf("%c",191); // Right Upper Corner 
             gotoxy(17,23); printf("%c",192); // Left Lower Corner
             gotoxy(62,23); printf("%c",217); // Right Lower Corner
             for(i=1;i<=44;i++) { gotoxy(17+i,4); printf("%c",196); } // Upper Horizontal
             for(i=1;i<=44;i++) { gotoxy(17+i,23); printf("%c",196); } // Lower Horizontal
             for(i=1;i<=44;i++) { gotoxy(17+i,19); printf("%c",196); } // Middle horizontal
             for(i=1;i<=18;i++) { gotoxy(17,4+i); printf("%c",179); } // Left Vertical
             for(i=1;i<=18;i++) { gotoxy(62,4+i); printf("%c",179); } // Right Vertical
             
             //=================================================================
             // SMALL BOX
             //=================================================================
             gotoxy(17,4); printf("%c",218); // Left Upper Corner
             gotoxy(62,4); printf("%c",191); // Right Upper Corner 
             gotoxy(17,23); printf("%c",192); // Left Lower Corner
             gotoxy(62,23); printf("%c",217); // Right Lower Corner
             for(i=1;i<=44;i++) { gotoxy(17+i,4); printf("%c",196); } // Upper Horizontal
             for(i=1;i<=44;i++) { gotoxy(17+i,23); printf("%c",196); } // Lower Horizontal
             for(i=1;i<=44;i++) { gotoxy(17+i,19); printf("%c",196); } // Middle horizontal
             for(i=1;i<=18;i++) { gotoxy(17,4+i); printf("%c",179); } // Left Vertical
             for(i=1;i<=18;i++) { gotoxy(62,4+i); printf("%c",179); } // Right Vertical
        }
             
        void displayRecordGraphicz(){
        		system("cls");
	headerr();
             gotoxy(15,3); printf("\xC9"); // Upper left corner
             for(i=1;i<=48;i++) printf("\xCD"); // Upper left right horizontal
             gotoxy(64,3); printf("\xBB"); // Upper right corner
             gotoxy(15,24); printf("\xC8"); // Lower left corner
             for(i=1;i<=48;i++) printf("\xCD"); // Lower left right horizontal 
             gotoxy(64,24); printf("\xBC"); // Lower right corner
             for(i=1;i<21;i++){ gotoxy(15,i+3); printf("\xBA"); } // Left vertical
             for(i=1;i<21;i++){ gotoxy(64,i+3); printf("\xBA"); }// Right vertical
             
             //=================================================================
             gotoxy(8+19,0); printf("\xC9"); // Upper left corner
             for(i=1;i<=25;i++) printf("\xCD"); // Upper left right horizontal 
             gotoxy(52,0); printf("\xBB"); // Upper right corner
             gotoxy(8+19,2); printf("\xC8"); // Lower left corner
             for(i=1;i<=25;i++) printf("\xCD"); // Lower left right horizontal 
             gotoxy(52,2); printf("\xBC"); // Lower right corner
             for(i=1;i<2;i++){ gotoxy(27,i+0); printf("\xBA"); } // Left vertical
             for(i=1;i<2;i++){ gotoxy(52,i+0); printf("\xBA"); }// Right vertical
             
             //=================================================================
             // SMALL BOX
             //=================================================================
             gotoxy(17,4); printf("%c",218); // Left Upper Corner
             gotoxy(62,4); printf("%c",191); // Right Upper Corner 
             gotoxy(17,23); printf("%c",192); // Left Lower Corner
             gotoxy(62,23); printf("%c",217); // Right Lower Corner
             for(i=1;i<=44;i++) { gotoxy(17+i,4); printf("%c",196); } // Upper Horizontal
             for(i=1;i<=44;i++) { gotoxy(17+i,23); printf("%c",196); } // Lower Horizontal
             for(i=1;i<=44;i++) { gotoxy(17+i,19); printf("%c",196); } // Middle horizontal
             for(i=1;i<=18;i++) { gotoxy(17,4+i); printf("%c",179); } // Left Vertical
             for(i=1;i<=18;i++) { gotoxy(62,4+i); printf("%c",179); } // Right Vertical
             
             //=================================================================
             // SMALL BOX
             //=================================================================
             gotoxy(17,4); printf("%c",218); // Left Upper Corner
             gotoxy(62,4); printf("%c",191); // Right Upper Corner 
             gotoxy(17,23); printf("%c",192); // Left Lower Corner
             gotoxy(62,23); printf("%c",217); // Right Lower Corner
             for(i=1;i<=44;i++) { gotoxy(17+i,4); printf("%c",196); } // Upper Horizontal
             for(i=1;i<=44;i++) { gotoxy(17+i,23); printf("%c",196); } // Lower Horizontal
             for(i=1;i<=44;i++) { gotoxy(17+i,19); printf("%c",196); } // Middle horizontal
             for(i=1;i<=18;i++) { gotoxy(17,4+i); printf("%c",179); } // Left Vertical
             for(i=1;i<=18;i++) { gotoxy(62,4+i); printf("%c",179); } // Right Vertical
        }
             
        void adminLoginGraphicz(){
        		system("cls");
	headerr();
             gotoxy(20,3); printf("\xC9"); // Upper left corner
             for(i=1;i<=40;i++) printf("\xCD"); // Upper left right horizontal
             gotoxy(61,3); printf("\xBB"); // Upper right corner
             gotoxy(20,22); printf("\xC8"); // Lower left corner
             for(i=1;i<=40;i++) printf("\xCD"); // Lower left right horizontal 
             gotoxy(61,22); printf("\xBC"); // Lower right corner
             for(i=1;i<19;i++) { gotoxy(20,i+3); printf("\xBA"); } // Left vertical
             for(i=1;i<19;i++) { gotoxy(61,i+3); printf("\xBA"); } // Right vertical
             
             //=================================================================
             gotoxy(20,7); printf("\xCC"); // Left inside upper corner
             for(i=1;i<=40;i++) printf("\xCD"); // Inside upper left right horizontal 
             gotoxy(20,17); printf("\xCC"); // Left inside lower corner
             for(i=1;i<=40;i++) printf("\xCD"); // Inside lower left right horizontal
             gotoxy(61,7); printf("\xB9"); // Right inside upper corner
             gotoxy(61,17); printf("\xB9"); // Right inside lower corner
             
             //=================================================================
             gotoxy(28,10); printf("\xC9"); // Upper left corner
             for(i=1;i<=24;i++) printf("\xCD"); // Upper left right horizontal 
             gotoxy(52,10); printf("\xBB"); // Upper right corner
             gotoxy(28,14); printf("\xC8"); // Lower left corner 
             for(i=1;i<=24;i++) printf("\xCD"); // Lower left right horizontal
             gotoxy(52,14); printf("\xBC"); // Lower right corner
             for(i=1;i<4;i++){ gotoxy(28,i+10); printf("\xBA"); } // Left vertical
             for(i=1;i<4;i++){ gotoxy(52,i+10); printf("\xBA"); } // Right vertical
        }
             
        void progressBarGraphicz(){
        		system("cls");
	headerr();
             gotoxy(27,5); std::cout<<"ALEX MERCER BANK INCORPORATED";
             gotoxy(8,3); printf("\xC9"); // Upper left corner
             for(i=1;i<=61;i++) printf("\xCD"); // Upper left right horizontal 
             gotoxy(70,3); printf("\xBB"); // Upper right corner
             gotoxy(8,22); printf("\xC8"); // Lower left corner
             for(i=1;i<=61;i++) printf("\xCD");// Lower left right horizontal 
             gotoxy(70,22); printf("\xBC"); // Lower right corner
             for(i=1;i<19;i++){ gotoxy(8,i+3); printf("\xBA"); } // Left vertical
             for(i=1;i<19;i++){ gotoxy(70,i+3); printf("\xBA"); }// Right vertical
              
             //=================================================================
             gotoxy(8,7); printf("\xCC"); // Left inside upper corner
             for(i=1;i<=61;i++) printf("\xCD"); // Inside upper left right horizontal 
             gotoxy(8,17); printf("\xCC"); // Left inside lower corner
             for(i=1;i<=61;i++) printf("\xCD"); // Inside lower left right horizontal 
             gotoxy(70,7); printf("\xB9"); // Right inside upper corner
             gotoxy(70,17); printf("\xB9"); // Right inside lower corner
             gotoxy(35,17); std::cout<<" LOADING ";
        }
              
        void aboutProgrammerGraphicz(){
        		system("cls");
	headerr();
             gotoxy(20,3); printf("\xC9"); // Upper left corner
             for(i=1;i<=40;i++) printf("\xCD"); // Upper left right horizontal 
             gotoxy(61,3); printf("\xBB"); // Upper right corner
             gotoxy(20,22); printf("\xC8"); // Lower left corner
             for(i=1;i<=40;i++) printf("\xCD"); // Lower left right horizontal 
             gotoxy(61,22); printf("\xBC"); // Lower right corner
             for(i=1;i<19;i++) { gotoxy(20,i+3); printf("\xBA"); } // Left vertical
             for(i=1;i<19;i++) { gotoxy(61,i+3); printf("\xBA"); } // Right vertical
             
             //=================================================================
             gotoxy(20,7); printf("\xCC"); // Left inside upper corner
             for(i=1;i<=40;i++) printf("\xCD"); // Inside upper left right horizontal 
             gotoxy(20,17); printf("\xCC"); // Left inside lower corner
             for(i=1;i<=40;i++) printf("\xCD"); // Inside lower left right horizontal
             gotoxy(61,7); printf("\xB9"); // Right inside upper corner
             gotoxy(61,17); printf("\xB9"); // Right inside lower corner
             
             //=================================================================
             gotoxy(25,10); printf("\xC9"); // Upper left corner
             for(i=1;i<=30;i++) printf("\xCD"); // Upper left right horizontal 
             gotoxy(55,10); printf("\xBB"); // Upper right corner
             gotoxy(25,14); printf("\xC8"); // Lower left corner 
             for(i=1;i<=30;i++) printf("\xCD"); // Lower left right horizontal
             gotoxy(55,14); printf("\xBC"); // Lower right corner
             for(i=1;i<4;i++){ gotoxy(25,i+10); printf("\xBA"); } // Left vertical
             for(i=1;i<4;i++){ gotoxy(55,i+10); printf("\xBA"); } // Right vertical
        }
             
        void mainMenuGraphicz(){
        		system("cls");
	headerr();
             gotoxy(21,5); printf("\xC9"); // Upper left corner
             for(i=1;i<=38;i++) printf("\xCD"); // Upper left right horizontal 
             gotoxy(60,5); printf("\xBB"); // Upper right corner
             gotoxy(21,23); printf("\xC8"); // Lower left corner
             for(i=1;i<=38;i++) printf("\xCD"); // Lower left right horizontal 
             gotoxy(60,23); printf("\xBC"); // Lower right corner
             for(i=1;i<18;i++){ gotoxy(21,i+5); printf("\xBA"); } // Left vertical
             for(i=1;i<18;i++){ gotoxy(60,i+5); printf("\xBA"); }// Right vertical
             gotoxy(21,19); printf("\xCC"); // Left inside lower corner
             for(i=1;i<=38;i++) printf("\xCD"); // Inside lower left right horizontal 
             gotoxy(60,19); printf("\xB9"); // Right inside lower corner
             
             //=================================================================
             gotoxy(8+19,2); printf("\xC9"); // Upper left corner
             for(i=1;i<=25;i++) printf("\xCD"); // Upper left right horizontal 
             gotoxy(52,2); printf("\xBB"); // Upper right corner
             gotoxy(8+19,4); printf("\xC8"); // Lower left corner
             for(i=1;i<=25;i++) printf("\xCD"); // Lower left right horizontal 
             gotoxy(52,4); printf("\xBC"); // Lower right corner
             for(i=1;i<2;i++){ gotoxy(27,i+2); printf("\xBA"); } // Left vertical
             for(i=1;i<2;i++){ gotoxy(52,i+2); printf("\xBA"); }// Right vertical
             
             //=================================================================
             gotoxy(41,7); printf("\xC9"); // Upper left corner
             for(i=1;i<=16;i++) printf("\xCD"); // Upper left right horizontal 
             gotoxy(58,7); printf("\xBB"); // Upper right corner
             gotoxy(41,17); printf("\xC8"); // Lower left corner
             for(i=1;i<=16;i++) printf("\xCD"); // Lower left right horizontal 
             gotoxy(58,17); printf("\xBC"); // Lower right corner
             for(i=1;i<10;i++){ gotoxy(41,i+7); printf("\xBA"); } // Left vertical
             for(i=1;i<10;i++){ gotoxy(58,i+7); printf("\xBA"); }// Right vertical
        }
             
        void modifyRecordGraphicz(){
        		system("cls");
	headerr();
             int i, n;
             clearWindow();
             gotoxy(1,3); printf("\xC9"); // Upper left corner
             for(i=1;i<=76;i++) printf("\xCD"); // Upper left right horizontal 
             gotoxy(78,3); printf("\xBB"); // Upper right corner
             gotoxy(1,24); printf("\xC8"); // Lower left corner
             for(i=1;i<=76;i++) printf("\xCD"); // Lower left right horizontal 
             gotoxy(78,24); printf("\xBC"); // Lower right corner
             for(i=1;i<21;i++){ gotoxy(1,i+3); printf("\xBA"); } // Left vertical
             for(i=1;i<21;i++){ gotoxy(78,i+3); printf("\xBA"); }// Right vertical
             
             //=================================================================
             gotoxy(8+19,0); printf("\xC9"); // Upper left corner
             for(i=1;i<=25;i++) printf("\xCD"); // Upper left right horizontal 
             gotoxy(52,0); printf("\xBB"); // Upper right corner
             gotoxy(8+19,2); printf("\xC8"); // Lower left corner
             for(i=1;i<=25;i++) printf("\xCD"); // Lower left right horizontal 
             gotoxy(52,2); printf("\xBC"); // Lower right corner
             for(i=1;i<2;i++){ gotoxy(27,i+0); printf("\xBA"); } // Left vertical
             for(i=1;i<2;i++){ gotoxy(52,i+0); printf("\xBA"); }// Right vertical
             
             //=================================================================
             // SMALL BOX
             //=================================================================
             gotoxy(3,4); printf("%c",218); // Left Upper Corner
             gotoxy(76,4); printf("%c",191); // Right Upper Corner 
             gotoxy(3,23); printf("%c",192); // Left Lower Corner
             gotoxy(76,23); printf("%c",217); // Right Lower Corner
             for(i=1;i<=72;i++) { gotoxy(3+i,4); printf("%c",196); } // Upper Horizontal
             for(i=1;i<=72;i++) { gotoxy(3+i,23); printf("%c",196); } // Lower Horizontal
             for(i=1;i<=72;i++) { gotoxy(3+i,19); printf("%c",196); } // Middle horizontal
             for(i=1;i<=18;i++) { gotoxy(3,4+i); printf("%c",179); } // Left Vertical
             for(i=1;i<=18;i++) { gotoxy(76,4+i); printf("%c",179); } // Right Vertical
            
             //=================================================================
             // SMALL BOX
             //=================================================================
             gotoxy(32,4); printf("%c",218); // Left Upper Corner
             gotoxy(47,4); printf("%c",191); // Right Upper Corner 
             gotoxy(32,6); printf("%c",192); // Left Lower Corner
             gotoxy(47,6); printf("%c",217); // Right Lower Corner
             for(i=1;i<=14;i++) { gotoxy(32+i,6); printf("%c",196); } // Lower Horizontal
             for(i=1;i<=1;i++) { gotoxy(32,4+i); printf("%c",179); } // Left Vertical
             for(i=1;i<=1;i++) { gotoxy(47,4+i); printf("%c",179); } // Right Vertical
            
             for(i=1;i<=12;i++) { gotoxy(40,6+i); printf("%c",179); } // Cutting Vertical
            
             gotoxy(31,1); std::cout<<" ALEX MERCER BANK INC.";
             gotoxy(12,4); std::cout<<" CURRENT ";
             gotoxy(57,4); std::cout<<" UPDATED ";
             gotoxy(33,3); std::cout<<" EDIT RECORD ";
             gotoxy(33,5); std::cout<<" ACC NO: ";
        }
        
        void modifyRecordDetailz(){
        		system("cls");
	headerr();
             gotoxy(4,9); std::cout<<" FIRST NAME : ";
             gotoxy(4,11); std::cout<<" OTHER NAME : ";
             gotoxy(4,13); std::cout<<" NATIONALITY : ";
             gotoxy(4,15); std::cout<<" ACCOUNT TYPE [C/S] : ";
             gotoxy(4,17); std::cout<<" ACCOUNT BALANCE : ";
             gotoxy(18,9); std::cout<<fname;
             gotoxy(18,11); std::cout<<lname;
             gotoxy(19,13); std::cout<<nationality;
             gotoxy(26,15); std::cout<<accType;
             gotoxy(23,17); std::cout<<openAmt;
             gotoxy(41,9); std::cout<<" FIRST NAME : ";
             gotoxy(41,11); std::cout<<" OTHER NAME : ";
             gotoxy(41,13); std::cout<<" NATIONALITY : ";
             gotoxy(41,15); std::cout<<" ACCOUNT TYPE [C/S] : ";
             gotoxy(41,17); std::cout<<" UPGRADING AMOUNT : ";
             gotoxy(55,9); std::cin>>fname;
             gotoxy(55,11); std::cin>>lname;
             gotoxy(56,13); std::cin>>nationality;
             gotoxy(63,15); std::cin>>accType;
             gotoxy(61,17); std::cin>>openAmt;
        }

        void aboutUs(){
        		system("cls");
	headerr();
             int i, n;
             system("cls");
             gotoxy(1,3); printf("\xC9"); // Upper left corner
             for(i=1;i<=76;i++) printf("\xCD"); // Upper left to right horizontal line 
             gotoxy(78,3); printf("\xBB"); // Upper right corner
             gotoxy(1,24); printf("\xC8"); // Lower left corner
             for(i=1;i<=76;i++) printf("\xCD"); // Lower left to right horizontal line 
             gotoxy(78,24); printf("\xBC"); // Lower right corner
             for(i=1;i<21;i++){ gotoxy(1,i+3); printf("\xBA"); } // Left vertical line
             for(i=1;i<21;i++){ gotoxy(78,i+3); printf("\xBA"); }// Right vertical line
             
             //==========================================================================
             gotoxy(8+19,0); printf("\xC9"); // Upper left corner
             for(i=1;i<=25;i++) printf("\xCD"); // Upper left to right horizontal line 
             gotoxy(52,0); printf("\xBB"); // Upper right corner
             gotoxy(8+19,2); printf("\xC8"); // Lower left corner
             for(i=1;i<=25;i++) printf("\xCD"); // Lower left to right horizontal line 
             gotoxy(52,2); printf("\xBC"); // Lower right corner
             for(i=1;i<2;i++){ gotoxy(27,i+0); printf("\xBA"); } // Left vertical line
             for(i=1;i<2;i++){ gotoxy(52,i+0); printf("\xBA"); }// Right vertical line
             
             //===========================================================================
             // SMALL BOX
             //===========================================================================
            gotoxy(3,4); printf("%c",218); // Left Upper Corner
            gotoxy(76,4); printf("%c",191); // Right Upper Corner 
            gotoxy(3,23); printf("%c",192); // Left Lower Corner
            gotoxy(76,23); printf("%c",217); // Right Lower Corner
            for(i=1;i<=72;i++) { gotoxy(3+i,4); printf("%c",196); } // Upper Horizontal line
            for(i=1;i<=72;i++) { gotoxy(3+i,23); printf("%c",196); } // Lower Horizontal line
            for(i=1;i<=72;i++) { gotoxy(3+i,19); printf("%c",196); } // Middle horizontal line
            for(i=1;i<=18;i++) { gotoxy(3,4+i); printf("%c",179); } // Left Vertical Line
            for(i=1;i<=18;i++) { gotoxy(76,4+i); printf("%c",179); } // Right Vertical Line
            gotoxy(31,1); std::cout<<" ALEX MERCER Bank INC.";
            gotoxy(5,4); std::cout<<" ABOUT US ";
            gotoxy(4,6); std::cout<<" ALEX MERCER BANK INC. WAZ STARTED IN 2017 IN HONOUR OF THE ";
            gotoxy(4,7); std::cout<<" ANUJ SIR. THE IDEA STARTED WITH A PROJECT GIVEN TO US IN CLASS" ;
            gotoxy(4,8); std::cout<<"  12TH SO I DECIDED TO CREATE THIS";
            gotoxy(4,9); std::cout<<" A BANK PROJECT AND NAMED IT ALEX MERCER BANK INCORPORATED. ALEX MERCER";
            gotoxy(4,10); std::cout<<"BANKERS OUT THERE LIVING  INC. WAZ STARTED ON  A PARTICULAR PURPOSE";
            gotoxy(4,11); std::cout<<" TO SERVE ALL THE PERSONAL  FREE AND FIND IT HARD MAKING IT IN LIFE. ";
            gotoxy(4,12); std::cout<<"ALEX MERCER BANK INC IS A   PRIVATLEY OWNED SOFTWARE AND ITS NOT";
            gotoxy(4,13); std::cout<<" AFFILIATED TO ANY BANK. ALEX MERCER BANK IS SITUATED IN HINDALCO COLONY ";
            gotoxy(4,14); std::cout<<"BUT SOON GOING GLOBAL. ALEX MERCER BANK INC IS FUNDED BY MARK ZUKERBERG ";
            gotoxy(4,15); std::cout<<"AND THE PEOPLE WORKING IN THE AREA FACEBOOK SERVES. IN SHORT THE";
            gotoxy(4,16); std::cout<<" JOURNEY TO BUILDING THIZ BANK TO BE WHERE IT IS TODAY HAS BEEN A ";
            gotoxy(4,17); std::cout<<"HARD ONE FROM DODGING THE BULLETZ AND THE POLICE TO THUGGIN ALL DAY";
            gotoxy(32,19); std::cout<<". OUTLAW TILL I DROP!! - ALEX MERCER ";
            gotoxy(32,20); std::cout<<"NOTIFICATION ";
            gotoxy(18,21); std::cout<<" PRESS ANY KEY TO GO BACK TO THE MAIN MENU.. ";
            getch();
            }
                     
        int retAccNo(){
            return accNo;
            }
        int returnDeposit(){
            return openAmt;
            }
        char returnAcctype(){
             return accType;
             }
        void dep(int x){
             openAmt+=x;
             }
        void withdraw(int x){
             openAmt-=x;
             }
  };
//==============================================================================
//             CLASS OBJECTS DECLARATION AND FILE STREAM OBJECTS
//==============================================================================
   Bank banky;
   FILE *outFile, *inFile;
//==============================================================================
//             FUNCTION - DEPOSIT AMOUNT
//==============================================================================
   void depositAmountz(){
        	system("cls");
	headerr();
		int amt, n;
        bool found=false;
        char ch;
        do{
        clearWindow();
        banky.deleteRecordGraphicz();
        gotoxy(31,1); std::cout<<" ALEX MERCER BANK INC.";
        gotoxy(19,4); std::cout<<" DEPOSIT AMOUNT ";
        gotoxy(18,21); std::cout<<" ENTER ACCOUNT NUMBER : ";
        fflush(stdin);
        gotoxy(42,21); std::cin>>n;
        inFile = fopen("ACCOUNTZ.dat","rb+");
        if(inFile == NULL){
        MessageBox(0," FILE COULD NOT BE OPENED! \n OR DOES NOT EXIST!","Error",0);
        getch();
        return;
        }
        while(fread(&banky, sizeof(banky),1,inFile) == 1){
        if(banky.retAccNo()==n){
        banky.viewAcc1();
        gotoxy(18,21); std::cout<<" ENTER AMOUNT TO DEPOSIT: ";
        gotoxy(44,21); std::cin>>amt;
        banky.dep(amt);
        fseek(inFile,-sizeof(banky), SEEK_CUR);
        fwrite(&banky,sizeof(banky), 1, inFile);
        gotoxy(18,21); std::cout<<"UG SHS AMOUNT "<<amt<<" DEPOSITED SUCCESSFULLY!";
        getch();
        gotoxy(18,21); std::cout<<"DO YOU WANT TO DEPOSIT MORE AMOUNT? [Y/N]:";
        gotoxy(60,21); std::cin>>ch;
        found=true;
        break;
        }
        }
        if(banky.retAccNo()!=n){
        gotoxy(18,21); std::cout<<" SORRY! ACCOUNT NUMBER " <<n<<" DOES NOT EXIST!";
        getch();
        gotoxy(18,21); std::cout<<"DO U WISH TO RE-TYPE YO ACCOUNT NO? [Y/N]:";
        gotoxy(60,21); std::cin>>ch;
        }
        fclose(inFile);
        }
        while(ch=='y' || ch=='Y');
        gotoxy(18,21); std::cout<<" PLEASE PRESS ENTER TO GO BACK TO MAIN MENU";
        getch();
		return;
  }
//==============================================================================
//                        FUNCTION - BALANCE CHECK
//==============================================================================
   void balanceCheck(){
   		system("cls");
	headerr();
        int amt, n, i;
        bool found=false;
        char ch;
        do{
        clearWindow();
        banky.displayRecordGraphicz();
        gotoxy(31,1); std::cout<<" ALEX MERCER BANK INC.";
        gotoxy(19,4); std::cout<<" BALANCE CHECK ";
        gotoxy(18,21); std::cout<<" ENTER ACCOUNT NUMBER : ";
        fflush(stdin);
        gotoxy(42,21); std::cin>>n;
        inFile = fopen("ACCOUNTZ.dat","rb+");
        if(inFile == NULL){
        MessageBox(0," FILE COULD NOT BE OPENED! \n OR DOES NOT EXIST!","Error",0);
        getch();
        return;
        }
        while(fread(&banky, sizeof(banky),1,inFile) == 1){
        if(banky.retAccNo()==n){
        gotoxy(31,5); printf("%c",218); // Left Upper Corner
        gotoxy(48,5); printf("%c",191); // Right Upper Corner 
        gotoxy(31,7); printf("%c",192); // Left Lower Corner
        gotoxy(48,7); printf("%c",217); // Right Lower Corner
        for(i=1;i<=16;i++){ gotoxy(31+i,5); printf("%c",196);}// Upper Horizontal
        for(i=1;i<=16;i++){ gotoxy(31+i,7); printf("%c",196);}// Lower Horizontal
        for(i=1;i<=1;i++){ gotoxy(30+i,6); printf("%c",179);}// Left Vertical
        for(i=1;i<=1;i++){ gotoxy(48,5+i); printf("%c",179);}// Right Vertical     
        gotoxy(33,19); std::cout<<" NOTIFICATION ";
        gotoxy(32,6); std::cout<<" ACCOUNT NO: ";
        gotoxy(44,6); std::cout<<banky.accNo;
        gotoxy(18,9);std::cout<<" NAME : "<<banky.fname;
        gotoxy(18,11);std::cout<<" ACCOUNT TYPE : "<<banky.returnAcctype();
        gotoxy(18,13);std::cout<<" YOUR ACCOUNT BALANCE : "<<banky.returnDeposit();
        gotoxy(18,15);std::cout<<" THANK YOU SO MUCH "<<banky.fname<<" FOR BANKING";
        gotoxy(18,17);std::cout<<" WITH ALEX MERCER BANK INCORPORATED!!";
        getch();
        gotoxy(18,21); std::cout<<"WANT TO CHECK MORE ACCOUNT BALANCE? [Y/N]:";
        gotoxy(60,21); std::cin>>ch;
        found=true;
        break;
        }
        }
        if(banky.retAccNo()!=n){
        gotoxy(18,21); std::cout<<" SORRY! ACCOUNT NUMBER " <<n<<" DOES NOT EXIST!";
        getch();
        gotoxy(18,21); std::cout<<"DO U WISH TO RE-TYPE YO ACCOUNT NO? [Y/N]:";
        gotoxy(60,21); std::cin>>ch;
        }
        fclose(inFile);
        }
        while(ch=='y' || ch=='Y');
        gotoxy(18,21); std::cout<<" PLEASE PRESS ENTER TO GO BACK TO MAIN MENU";
        getch();
		return;
  }
//==============================================================================
//             FUNCTION - WITHDRAW AMOUNT
//==============================================================================
   void withdrawAmountz(){
   		system("cls");
	headerr();
        int amt, n;
        bool found=false;
        char ch;
        do{
        clearWindow();
        banky.deleteRecordGraphicz();
        gotoxy(31,1); std::cout<<" ALEX MERCER BANK INC.";
        gotoxy(19,4); std::cout<<" WITHDRAW AMOUNT ";
        gotoxy(18,21); std::cout<<" ENTER ACCOUNT NUMBER : ";
        fflush(stdin);
        gotoxy(42,21); std::cin>>n;
        inFile = fopen("ACCOUNTZ.dat","rb+");
        if(inFile == NULL){
        MessageBox(0," FILE COULD NOT BE OPENED! \n OR DOES NOT EXIST!","Error",0);
        getch();
        return;
        }
        while(fread(&banky, sizeof(banky),1,inFile) == 1){
        if(banky.retAccNo()==n){
        banky.viewAcc1();
        gotoxy(18,21); std::cout<<" ENTER AMOUNT TO WITHDRAW : ";
        gotoxy(46,21); std::cin>>amt;
        int bal=banky.returnDeposit()-amt;
        if((bal<=500 && banky.returnAcctype()=='s' || bal<=500 && banky.returnAcctype()=='S') 
        || (bal<=1000 && banky.returnAcctype()=='c' || bal<=1000 && banky.returnAcctype()=='C')){
        gotoxy(18,21); std::cout<<" SORRY! YOUR ACCOUNT BALANCE IS TOO LOW!";
        getch();
        gotoxy(18,21); std::cout<<"DO U WISH TO TRY AGAIN WITHDRAWING? [Y/N]:";
        gotoxy(60,21); std::cin>>ch;
        break;
        }
        if((bal>500 && banky.returnAcctype()=='s' || bal>500 && banky.returnAcctype()=='S') 
        || (bal>1000 && banky.returnAcctype()=='c' || bal>1000 && banky.returnAcctype()=='C')){
        banky.withdraw(amt);
        fseek(inFile,-sizeof(banky), SEEK_CUR);
        fwrite(&banky,sizeof(banky), 1, inFile);
        gotoxy(18,21); std::cout<<"UG SHS AMOUNT "<<amt<<" WITHDRAWN SUCCESSFULLY!";
        getch();
        gotoxy(18,21); std::cout<<"DO YOU WISH TO WITHDRAW MORE CASH? [Y/N]:";
        gotoxy(60,21); std::cin>>ch;
        break;
        }
        }
        }
        if(banky.retAccNo()!=n){
        gotoxy(18,21); std::cout<<" SORRY! ACCOUNT NUMBER " <<n<<" DOES NOT EXIST!";
        getch();
        gotoxy(18,21); std::cout<<"DO U WANT TO RE-TYPE YO ACCOUNT NO? [Y/N]:";
        gotoxy(60,21); std::cin>>ch;
        }
        fclose(inFile);
        }
        while(ch=='y' || ch=='Y');
        gotoxy(18,21); std::cout<<" PLEASE PRESS ENTER TO GO BACK TO MAIN MENU";
        getch();
		return;
  }
//==============================================================================
//                        FUNCTION MAIN BANKER MENU 
//==============================================================================
  void bankerMenu(){
  		system("cls");
	headerr();
       int i, n;
       do {
           system("cls");
           system("color 09");
           banky.adminMenuGraphicz();
           gotoxy(32,3); std::cout<<"ALEX MERCER BANK INC.";
           gotoxy(18,8); std::cout<<"[1] ABOUT US";
           gotoxy(18,10); std::cout<<"[2] DEPOSIT AMOUNT";
           gotoxy(18,12); std::cout<<"[3] BALANCE CHECK";
           gotoxy(18,14); std::cout<<"[4] WITHDRAW AMOUNT";
           gotoxy(18,16); std::cout<<"[5] LOG OUT";
           gotoxy(19,21); std::cout<<"SELECT FROM [1-5] : ";
           gotoxy(39,21); std::cin>>n;
           
       switch(n){
                 case 1: banky.aboutUs();
                 break;
                 case 2: depositAmountz();
                 break;
                 case 3: balanceCheck();
                 break;
                 case 4: withdrawAmountz();
                 break;
                 default: gotoxy(19,21); std::cout<<" THANK YOU SO MUCH FOR BANKING WITH US!";
                 getch();
                 gotoxy(19,21); std::cout<<" PLEASE PRESS ENTER TO GO BACK TO MAIN MENU";
                 getch();
                 }
                 }
                 while(n!=5); 
  }    
//==============================================================================
//                     FUNCTION - BANKER LOGIN
//==============================================================================
   void bankerLogin(void){
   	system("cls");
	headerr();        
        int i, j, k, n;
        bool found=false;
        char ch;
        do{
        clearWindow();
        banky.adminLoginGraphicz();
        gotoxy(30,5); std::cout<<"ALEX MERCER BANK INC.";
        gotoxy(30,12); std::cout<<"Account No:__________";
        gotoxy(33,17); std::cout<<" NOTIFICATION ";
        gotoxy(41,12); std::cin>>n;
        inFile = fopen("ACCOUNTZ.dat","rb+");
        if(inFile == NULL){
        MessageBox(0," FILE COULD NOT BE OPENED! \n OR DOES NOT EXIST!","Error",0);
        getch();
        return;
        }
        while(fread(&banky,sizeof(banky),1,inFile) == 1){        
        if(banky.retAccNo()==n){
        for(j=1;j<=1;j++){
        if(j==1){gotoxy(25,21);printf("Loading Banker Menu Please Wait...");}
        for(k=22;k<60;k++){gotoxy(k,20);printf("\BA");}
        for(k=22;k<60;k++){gotoxy(k,20); putch(10000);
        Sleep(150);
        }
        }
        bankerMenu();
        return;
        }
        found = true;                
        }
        if(banky.retAccNo()!=n){
        gotoxy(21,20); std::cout<<" SORRY ACCOUNT NUMBER "<<n<<" DOESNT EXIST";
        getch();
        gotoxy(21,20); std::cout<<" DO YOU WANT TO TRY RE-ENTERIN? [Y/N]: ";
        gotoxy(59,20); std::cin>>ch;
        }
        fclose(inFile);
        }
        while(ch=='y' || ch=='Y');
        gotoxy(21,20); std::cout<<" PRESS ENTER TO GO BACK TO THE MAIN MENU";
        getch();
        return;
   }
//==============================================================================
//                   FUNCTION TO WRITE RECORDZ TO FILE
//==============================================================================
    void addRecord(){
    		system("cls");
	headerr();
       char ch;
       do{
       clearWindow();
       outFile = fopen("ACCOUNTZ.dat","ab+");
       if(outFile == NULL){
       MessageBox(0,"ERROR! FILE COULD NOT BE CREATED!","Warning",0);
       }
       else {
       fflush(stdin);
       banky.openAcc();
       fwrite(&banky, sizeof(banky), 1, outFile);
       gotoxy(18,21); std::cout<<" DO U WISH TO OPEN MORE ACCOUNTZ? [Y/N]: ";
       gotoxy(59,21); std::cin>>ch;
       fflush(stdin);
       }
       fclose(outFile);
       }
       while(ch=='y' || ch=='Y');
       gotoxy(18,21); std::cout<<" PLEASE PRESS ENTER TO GO BACK TO MAIN MENU";
       getch();
       return;
       }
//==============================================================================
//           FUNCTION TO SEARCH AND SHOW A SPECIFIC RECORD
//==============================================================================
    void displayRecord(){
    		system("cls");
	headerr();
       char ch;
       int n, isFound = 0;
       do{
         clearWindow();
         banky.displayRecordGraphicz();
         gotoxy(31,1); std::cout<<" ALEX MERCER BANK INC.";
         gotoxy(19,4); std::cout<<" VIEW RECORD ";
         gotoxy(18,21); std::cout<<" ENTER ACCOUNT NUMBER : ";
         gotoxy(42,21); std::cin>>n;
         fflush(stdin);
         inFile = fopen("ACCOUNTZ.dat","rb");
         if(inFile == NULL){
         MessageBox(0," FILE COULD NOT BE OPENED! \n OR DOES NOT EXIST!","Error",0);
         getch();
         return;
         }
         while(fread(&banky,sizeof(banky),1,inFile)){
         if(banky.retAccNo()==n){
         banky.viewAcc1();
         gotoxy(18,21); std::cout<<"DO YOU WANT TO CHECK MORE ACCOUNTZ? [Y/N]: ";
         gotoxy(60,21); std::cin>>ch;
         isFound = 1;                
         break;
         }
         }
         if(banky.retAccNo()!=n){
         gotoxy(19,21); std::cout<<"SORRY! THE ACCOUNT NUMBER DOESN'T EXIST!";
         getch();
         gotoxy(18,21); std::cout<<"DO YOU WANT TO CHECK MORE ACCOUNTZ? [Y/N]: ";
         gotoxy(60,21); std::cin>>ch;
         }
         fclose(inFile);
         }
         while(ch=='y' || ch=='Y');
         gotoxy(18,21); std::cout<<" PLEASE PRESS ENTER TO GO BACK TO MAIN MENU";
         getch();
         return;
    }
//==============================================================================
//                    FUNCTION TO DISPLAY ALL ACCOUNTZ
//==============================================================================
  void displayAllRecordz(int j=8){
  		system("cls");
	headerr();
       clearWindow();
       inFile = fopen("ACCOUNTZ.dat","rb");
       if(inFile == NULL){
       MessageBox(0," FILE COULD NOT BE OPENED! \n OR DOES NOT EXIST!","Error",0);
       getch();
       return;
       }
       else {
       fflush(stdin);
       while(fread(&banky,sizeof(banky),1,inFile) == 1){
       banky.viewAllAcc();
       gotoxy(6,j); printf("%d",banky.accNo);
       gotoxy(14,j); printf("%s",banky.fname);
       gotoxy(27,j); printf("%s",banky.lname);
       gotoxy(40,j); printf("%s",banky.nationality);
       gotoxy(56,j); std::cout<<banky.accType;
       gotoxy(66,j); printf("%d",banky.openAmt);
       j=j+1;
       }
       }
       fclose(inFile);
       getch();
       return;
  }
//==============================================================================
//             FUNCTION TO MODIFY RECORD IN FILE [DATABASE]
//==============================================================================
  void editRecord(){
  		system("cls");
	headerr();
       int n, isFound = 0;
       char ch;
       do{
       clearWindowz();
       banky.modifyRecordGraphicz();
       gotoxy(42,5); std::cin>>n;
       inFile = fopen("ACCOUNTZ.dat","rb+");
       if(inFile == NULL){
       MessageBox(0," FILE COULD NOT BE OPENED! \n OR DOES NOT EXIST!","Error",0);
       getch();
       return;
       }
       while(fread(&banky, sizeof(banky),1,inFile) == 1){
       if(banky.retAccNo()==n){
       fflush(stdin);
       banky.modifyRecordDetailz();
       fseek(inFile,-sizeof(banky), SEEK_CUR);
       fwrite(&banky,sizeof(banky), 1, inFile);
       gotoxy(26,21); std::cout<<" ACCOUNT UPDATED SUCCESSFULLY!";
       getch();
       gotoxy(17,21); std::cout<<"DO YOU WANT TO UPDATE MORE ACCOUNTZ? [Y/N]: ";
       gotoxy(61,21); std::cin>>ch;
       isFound = 1;
       break;
       }
       }
       if(banky.retAccNo()!=n){
       gotoxy(19,21); std::cout<<" SORRY! ACCOUNT NUMBER "<<n<<" DOES NOT EXIST!";
       getch();
       gotoxy(18,21); std::cout<<" DO YOU WANT TO UPDATE MORE ACCOUNTZ? [Y/N]: ";
       gotoxy(63,21); std::cin>>ch;
       }
       fclose(inFile);
       }
       while(ch=='y' || ch=='Y');
       gotoxy(16,21); std::cout<<" PLEASE PRESS ENTER KEY TO GO BACK TO THE MAIN MENU";
       getch();
       return;
  }
//==============================================================================
//          FUNCTION ERASE/ DELETE BANKER DATA FROM FILE [DATABASE]
//==============================================================================
  void deleteRecord(){
  		system("cls");
	headerr();
       int n;
       char ch;
       clearWindow();
       banky.deleteRecordGraphicz();
       gotoxy(31,1); std::cout<<" ALEX MERCER BANK INC.";
       gotoxy(19,4); std::cout<<" DELETE RECORD ";
       gotoxy(18,21); std::cout<<" ENTER ACCOUNT NUMBER : ";
       fflush(stdin);
       gotoxy(42,21); std::cin>>n;
       inFile = fopen("ACCOUNTZ.dat","rb");
       if(inFile == NULL){
       MessageBox(0," FILE COULD NOT BE OPENED! \n OR DOES NOT EXIST!","Error",0);
       getch();
       return;
       }
       outFile = fopen("TEMP.dat", "wb");
       while(fread(&banky, sizeof(banky),1,inFile) == 1){
       if(banky.retAccNo()!=n){
       fwrite(&banky,sizeof(banky),1,outFile);
       }
       }
       gotoxy(18,21); std::cout<<" ACCOUNT HAS BEEN DELETED SUCCESSFULLY!";
       getch();
       fclose(inFile);
       fclose(outFile);
       rename("ACCOUNTZ.dat","recy.txt");
       rename("TEMP.dat","ACCOUNTZ.dat");
       gotoxy(18,21); std::cout<<" PRESS ENTER KEY TO GO BACK TO THE MAIN MENU";
       getch();   
       return;
  }
//==============================================================================
//                      ADMINISTRATOR MENU GRAPHICZ
//==============================================================================
 void adminMenu(){
 	system("cls");
	headerr();  
    int i, n;
    do {
    system("cls");
    system("color 09");
    banky.adminMenuGraphicz();
    gotoxy(32,3); std::cout<<"ALEX MERCER BANK INC.";
    gotoxy(18,7); std::cout<<"[1] OPEN ACCOUNT";
    gotoxy(18,9); std::cout<<"[2] VIEW SPEC. ACCOUNT";
    gotoxy(18,11); std::cout<<"[3] VIEW ALL ACCOUNTZ";
    gotoxy(18,13); std::cout<<"[4] MODIFY ACCOUNT";
    gotoxy(18,15); std::cout<<"[5] CLOSE ACCOUNT";
    gotoxy(18,17); std::cout<<"[6] LOG OUT";
    gotoxy(19,21); std::cout<<"SELECT FROM [1-6] : ";
    gotoxy(39,21); std::cin>>n;
    
    switch(n){
              case 1: addRecord();
              break;
              case 2: displayRecord();
              break;
              case 3: displayAllRecordz();
              break;
              case 4: editRecord();
              break;
              case 5: deleteRecord();
              break;
              default: gotoxy(19,21); std::cout<<" BYE BYE ADMIN HOPE TO SEE YOU AGAIN SOON!";
              getch();
              gotoxy(19,21); std::cout<<" PLEASE PRESS ENTER TO GO BACK TO MAIN MENU!";
              getch();
              }
              }
              while(n!=6);
    }   
//==============================================================================
//                         ADMINISTRATOR GRAPHICZ
//==============================================================================
 void adminLogin(void){
 		system("cls");
	headerr();
      string adminName, pass;
      int i, j, k;
      char ch;
      do{
          clearWindow();
          banky.adminLoginGraphicz();
          gotoxy(30,5); std::cout<<"ALEX MERCER BANK INC.";
          gotoxy(30,11); std::cout<<"Username: ___________ ";
          gotoxy(30,13); std::cout<<"Password: ___________ ";
          gotoxy(33,17); std::cout<<" NOTIFICATION ";
          gotoxy(40,11); std::cin>>adminName;
          gotoxy(40,13); std::cin>>pass;
          if(adminName=="PRINCE" && pass=="ALLRIGHT"){
          for(j=1;j<=1;j++){
          if(j==1){gotoxy(28,21);printf("Loading Admin MENU Please Wait...");}
          for(k=22;k<60;k++){gotoxy(k,20);printf("\BA");}
          for(k=22;k<60;k++){gotoxy(k,20); putch(10000);
          Sleep(150);
          }
          }
          adminMenu();
          return;
          }
          else {
               gotoxy(23,20); std::cout<<"SORRY! WRONG ADMIN NAME OR PASSWORD!";
               getch();
               gotoxy(21,20); std::cout<<" DO YOU WANT TO TRY RE-ENTERIN? [Y/N]: ";
               gotoxy(59,20); std::cin>>ch;
               }     
          }
          while(ch == 'y' || ch == 'Y');
          return;
      }
      
      char adminName[]="PRINCE"; char pass[]="ALLRIGHT";
      
//==============================================================================
//                       FUNCTION ABOUT THE PROGRAMMER
//==============================================================================
 void aboutProgrammer(void)
 {	system("cls");
	headerr();
 	
      int i, j, k;
      clearWindow();
      banky.aboutProgrammerGraphicz();
      gotoxy(30,5); std::cout<<"ALEX MERCER BANK INC.";
      gotoxy(26,11); std::cout<<"PROGRAMMER: ALEX MERCER";
      gotoxy(26,13); std::cout<<"EMAIL: STONY5913@GMAIL.COM";
      gotoxy(33,17); std::cout<<" NOTIFICATION ";
      for(j=1;j<=1;j++){
      if(j==1){gotoxy(30,21);printf("EXITING SYSTEM... BYE!!");}
      for(k=22;k<60;k++){gotoxy(k,20);printf("\BA");}
      for(k=22;k<60;k++){gotoxy(k,20); putch(10000);
      Sleep(200);
      }
      exit(0);
      }
 } 
//==============================================================================
//               FUNCTION MAIN MENU [ADMINISTRATOR/ BANKER MENU]
//==============================================================================
  void mainMenu(void){
  		system("cls");
	headerr();
       int i, j;
       system("cls");
       system("color 09");
       banky.mainMenuGraphicz();
       do {
           gotoxy(25,8); std::cout<<"MAIN MENU";
           for(i=1;i<=9;i++) { gotoxy(24+i,9); printf("%c",196); }
           gotoxy(23,11); std::cout<<"[1] CUSTOMER ";
           gotoxy(23,13); std::cout<<"[2] ADMINISTRATOR ";
           gotoxy(23,15); std::cout<<"[3] EXIT ";
           gotoxy(32,3); std::cout<<"ALEX MERCER BANK INC.";
           gotoxy(24,21); std::cout<<"SELECT FROM [1-3] : ";
           gotoxy(44,21); std::cin>>j; 
           
           switch(j){
                     case 1: bankerLogin();
                     break;
                     case 2: adminLogin();
                     break;
                     default: aboutProgrammer();
                     }
                     clearWindow();
                     banky.mainMenuGraphicz();
                     }  
                     while(j>0 && j<=2);
           }
//==============================================================================
//                      FUNCTION WELCOME SCREEN/ PROGRESS BAR
//==============================================================================
 void progressBar(){
 	system("cls");
	headerr();   
    int i, j, k;
    system("cls");
    system("color 09");
    banky.progressBarGraphicz();
    for(j=1;j<=3;j++){
    if(j==1){gotoxy(32,21);printf("Checking folders...");
	gotoxy(22,10);printf("FOR MORE SOFTWARES LIKE THIS OR ADVANCED.");
	gotoxy(26,11);printf("amanojha5913.weebly.com.");   }
    if(j==2){gotoxy(32,21);printf("Checking files...");}
    if(j==3){gotoxy(32,21);printf("Loading System...");}
    for(k=10;k<69;k++){gotoxy(k,20);printf("\BA");}
    for(k=10;k<69;k++){gotoxy(k,20); putch(10000);
    Sleep(120);
    }
    }
    system("cls");
    mainMenu();
    getch();
 }



int bankers=8907;

int baankerpass;




int aman()
{
		system("cls");
	headerr();
	int baank;
	
	cout<<"\n ENTER THE PASSWORD  ";
	cin>>baank;
	if(bankers==baank)
	{progressBar();
	}
}



int prog()
{

     
     system("cls");




system("color 09");
  
    	system("cls");
	headerr();
   char br='y';
   int n;
   
   while(br=='Y'||br=='y')
   {system("color 3F");
 {
   
    
	system("cls");
	headerr();
cout<<"1. BANKING DBMS";
cout<<"\n2. STUDENT DBMS";
cout<<"\n3. GAMES";
cout<<"\n4. NOTEPAD";
cout<<"\n";
cout<<"\n";
cout<<"\n ENTER UR CHOICE =   ";
   cin>>n;
   
   
}
   
   if(n==1)
     {
	  aman();
	  cout<<"WANT TO CONTINUE";
	  cout<<"IF YES TYPE(Y) AND IF NO TYPE(N)";
	  cin>>br;
     }
   if(n==2)
     {student();
      cout<<"WANT TO CONTINUE";
	  cout<<"IF YES TYPE(Y) AND IF NO TYPE(N)";
	  cin>>br;
	 }
   if(n==3)
     { int pr;
     		system("cls");
	headerr();
     
	 cout<<"\n1. 13 STONES";
	 cout<<"\n2. SNAKE GAME";
	 cout<<"\n ENTER YOUR DEZIRED GAME NUMBER  ";
	 cin>>pr;
	 
	 switch(pr)
	 {case 1: 
	 
	 	 {
		     int stones_left = 13, P1Taken, P2Taken;

             cout << "You have shosen to play the game 13 stones against me, the MIGHTY "
             << "COMPUTER!\nThe object of the game is to take 1, 2 or 3 stones from"
             << " the pile on your turn.\nThe player that removes the last stone "
             << "or stones from the pile wins the game.\nGood Luck... You will need"
             << " it! I NEVER LOOSE!!"
             << endl << endl;

             computerPick(stones_left, P2Taken);
             playerPick(P1Taken);
             validPick(stones_left);

            //game logic here -- This is far from done.
             stones_left -= P1Taken;
             stones_left -= P2Taken;
             return 0;
         }
	 
	 case 2: run();
	         break;
     }
     	
}
}



}




int stude()
{
	
	ifstream fin;
	fin.open("rec.txt");
	char ch90;
	while(!fin.eof())
	{fin>>ch90;
	 cout<<ch90;
	}
	fin.close();
}

int banki()
{
	
	ifstream fin;
	fin.open("recy.txt");
	char ch90;
	while(!fin.eof())
	{fin>>ch90;
	 cout<<ch90;
	}
	fin.close();
	
}

int gaami()
{
}


int rec()
{
	system("cls");
	system("color 3F");
	int gh;
	system("cls");
	headerr();
    cout<<"\n 1. DELETE STUDENT RECORDS";
    cout<<"\n 2. DELETE BANK RECORDS";
    cout<<"\n 3. DELETE GAMES";
    cin>>gh;
    
    switch(gh)
    {case 1: stude();
     case 2: banki();
     case 3: gaami();
	}
	
	cout<<"\t";
	getch();
}


int bsp()
{
		system("cls");
	headerr();
	int newpass,oldpass;
	cout<<"\n ENTER THE OLD PASSWORD  ";
	cin>>oldpass;
	if(bankers==oldpass)
	{cout<<"\n ENTER THE NEW PASSWORD  ";
	 cin>>newpass;
	 bankers=newpass;
	 cout<<"\n THE PASSWORD HAS BEEN CHANGED!!!!!!!";
	 
	}
}

int k=500765;

int osp()
{
		system("cls");
	headerr();
	int newpass,oldpass;
	cout<<"\n ENTER THE OLD PASSWORD  ";
	cin>>oldpass;
	if(k==oldpass)
	{cout<<"\n ENTER THE NEW PASSWORD ";
	 cin>>newpass;
	 k=newpass;
	 cout<<"\n THE PASSWORD HAS BEEN CHANGED!!!!!!!";
	}
}


int hgs=50;

int cpp()
{
		system("cls");
	headerr();
	int oldpass,newpass;
	cout<<"\n ENTER THE OLD PASSWORD  ";
	cin>>oldpass;
	if(hgs==oldpass)
	{cout<<"\n ENTER THE NEW PASSWORD  ";
	 cin>>newpass;
	 hgs=newpass;
	 cout<<"\n THE PASSWORD HAS BEEN CHANGED!!!!!!!";
	}
}



int sys1()
{
	
	system("cls");
	headerr();
	int gfd;
	cout<<"\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\n 1. CHANGE THE CONTROL PANNEL PASSWORD";
	cout<<"\n 2. CHANGE THE OPERATING SYSTEM PASSWORD";
	cout<<"\n 3. CHANGE THE BANKING SYSTEM PASSWORD";
	cin>>gfd;
	switch(gfd)
	{case 1: cpp();
	 case 2: osp();
	 case 3: bsp();
	}
}





int sys()
{
	
	system("cls");
	headerr();
	int hgs1;
	cout<<"\n ENTER THE CONTROL PANNEL PASSWORD  ";
	cin>>hgs1;
	
	if(hgs=hgs1)
	{sys1();
	}
}

int asdf()
{
	
	system("cls");
	int k;
	
	system("color 3F");
	
headerr();

{
	
	
	box1();
	box2();
	box3();
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\n ENTER YOUR OPTION (1-3)";
	cin>>k;
	
	switch(k)
	{case 1: prog();
	         break;
	 case 2: rec();
	         break;
	 case 3: sys();
	         getch();
	}
}

}





int guest()
{int lol=0;
	cout<<"\n ENTER UR CHOICE";
	cin>>lol;
	if(lol==10)
	   sys1();
	else if(lol!=10)
	   system("cls");
	int k;
	
	system("color 3F");
	
headerr();

{
	
	
	box1();
	box2();
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\n ENTER YOUR OPTION (1-3)";
	cin>>k;
	
	switch(k)
	{case 1: prog();
	         break;
	 case 2: rec();
	         break;
	     }
}

}




void print(int b, char a);

int passs()
{
	
	int jk;
	
	
	int g;
	
	system("color 3F");
	
headerr();
	system("cls");
	headerr();
	cout<<"\n ";
	{cout<<"           ";

     for(int a=1;a<=7;a++)
        {
            cout<<"-";
        }
        cout<<"               |             -------";
            cout<<endl;
            
for(int b=1;b<=2;b++)
    {
    for(int c=1;c<=1;c++)
        {
                cout<<"            |";
        }
        for(int d=1;d<=5;d++)
              {
                cout<<" ";
              }
                cout<<"|               |             |     |"<<"\n";
       }
       cout<<"            ";
for(int e=1;e<=7;e++)
 {
 cout<<"-";
 }
 cout<<"               |             -------";
 
 
 

 
 cout<<"\n      1.    ADMIN                 |    2.       GUEST";
 cout<<"\n";
}

    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"\n ENTER YOUR CHOICE TO OPERATE   ";
    cin>>jk;
    if(jk==1)
	{system("cls");
		system("color 3F");
		headerr();
	   cout<<"\n ENTER THE PASSWORD (ADMIN) ==== ";
	cin>>g;
	
	if(k==g)
	{asdf();
	}
	
    else
    {cout<<"\n WRONG PASSWORD!!!!!!!!!!!!!!!!!";
	}
}
  else
       guest();
}

int loading()
{system("cls");
	char a = 178;
	int z;
	float l = 1.5;
	for (int i = 0; i<75; ++i)
	{
		system("cls");
        headerr();
        system("color 3F");
		z = 1 + rand() % (30 + 1 - 1) + 30;
		cout << "\n\n\n\n\n\n\n\n\t\t\t\tLoading " << (int)l << " %\n\n";
		cout << (char)201;
		print(76, 205);
		cout << (char)187 << endl << (char)186 << ' ';
		print(i, a);
		print(75 - i, ' ');
		cout << (char)186 << endl;

		//second line
		cout << (char)186 << ' ';
		print(i, a);
		print(75 - i, ' ');
		cout << (char)186 << endl;
		//second line

		//third line
		cout << (char)186 << ' ';
		print(i, a);
		print(75 - i, ' ');
		cout << (char)186 << endl;
		//third line

		//forth line
		cout << (char)186 << ' ';
		print(i, a);
		print(75 - i, ' ');
		cout << (char)186 << endl;
		//forth line

		cout << (char)200;
		print(76, 205);
		cout << (char)188;
		cout << "\n\n\t       LOADING JUST A RATHER VERY INTELLIGENT SYSTEM (J.A.R.V.I.S.).";
		l = l + 1.33333333;
		Sleep(z);
	}

	_sleep(500);
	passs();
}

void print(int b, char a = ' ')
{
	for (int uuu = 0; uuu<b; ++uuu)
		cout << a;
}

int loading1()
{char modi[]="STARTING JUST A RATHER VERY INTELLIGENT SYSTEM (J.A.R.V.I.S.) !!!!!!";
int i,l;
cout<<"\n";
cout<<"\n";
cout<<"\n";
cout<<"\n";
cout<<"\n";
cout<<"\n";
cout<<"\n";
cout<<"\n";
cout<<"\n";
cout<<"\n";
cout<<"\n";
cout<<"\n";
l=strlen(modi);
        for(i=0;i<=l;i++)
        {cout<<modi[i];
        _sleep(80);
		}
		loading();
}


int main()
{loading1();
}