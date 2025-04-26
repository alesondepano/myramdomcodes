#include <iostream>
using namespace std;
void askname(string& name, float& age, char& usercho) {
    cout << "Hello and Welcome dear customer\n\n";
    do {
        cout << "- - - -[USER SIGN UP] - - - -\n"
            << "Please enter your name: ";
        cin >> name;
        cout << "\n\nHello there " << name << "! nice to meet you!";
        do {
            cout << "\n\nNow, can you please enter your age: ";
            cin >> age;
            if (age < 0) {
                cout << "\nPlease enter a valid age (greaater than or equal to 0)\n\n";
            }
        } while (age < 0);
        system("cls");
        cout << "- - - -[USER SUMMARY] - - - -\n"
            << "Let us recap your information!\n\n"
            << "Your name is: " << name << endl
            << "Your age is: " << age;
        do {
            cout << "\n\nare the information above correct? (Y/N): ";
            cin >> usercho;
            switch (toupper(usercho)) {
            case 'Y':
                cout << "\n\nThat is good!\n\nNice to meet you " << name << "! We hope our service will be to your liking!\n\n";
                system("pause");
                break;
            case 'N':
                cout << "Oh our bad! Let us do that again!\n\n";
                system("pause");
                system("cls");
                break;
            default:
                cout << "You have not entered a valid response ! Please enter again!";
                break;
            }
        } while (usercho != 'Y' && usercho != 'y' && usercho != 'N' && usercho != 'n');
    } while (usercho == 'N' || usercho == 'n');
}
void displaymenu16() {
    system("cls");
    cout << "- - - -[MAIN MENU] - - - -\n"
        << "A.\tSpicy Buffalo Chicken\t\t\tPhp 250\n"
        << "B.\tMedium Rare Steak with Carbonara\tPhp 300\n"
        << "C.\tYagnyeom x2 with Kimchi fried Rice \tPhp 170\n"
        << "D.\tFried Chicken with fries\t\tPhp 120\n"
        << "E.\tFrench tacos with potato wedges\t\tPhp 190\n";
}
void choose16(char& choix, float& payment, char& orderm) {
    //intializing prizes for each food
    float chickA = 250;
    float steakB = 300;
    float yagC = 170;
    float frieD = 120;
    float tacosE = 190;
    do {
        displaymenu16();
        cout << "\n\nChosen Menu: ";
        cin >> choix;
        switch (toupper(choix))
        {
        case 'A':
            cout << "\n\nYou have chosen A also known as Spicy Buffalo Chicken.\nIt costs Php 250!";
            payment += chickA;
            cout << "\n\nYour payment is now: " << payment;
            break;
        case 'B':
            cout << "\n\nYou have chosen B also known as Medium Rare Steak with Carbonara.\nIt costs Php 300!";
            payment += steakB;
            cout << "\n\nYour payment is now: " << payment;
            break;
        case 'C':
            cout << "\n\nYou have chosen C also known as Yagnyeom x2 with Kimchi fried Rice.\nIt costs Php 170!";
            payment += yagC;
            cout << "\n\nYour payment is now: " << payment;
            break;
        case 'D':
            cout << "\n\nYou have chosen D also known as Fried Chicken with fries.\nIt costs Php 120!";
            payment += frieD;
            cout << "\n\nYour payment is now: " << payment;
            break;
        case 'E':
            cout << "\n\nYou have chosen E also known as French tacos with potato wedges.\nIt costs Php 190!";
            payment += tacosE;
            cout << "\n\nYour payment is now: " << payment;
            break;
        default:
            cout << "\n\nThat wasn't part of any of our choices, please try again !";
            break;
        }
        //asking to order more
        do {
            cout << "\n\nWould you like to order some more? (Y/N): ";
            cin >> orderm;
            switch (toupper(orderm)) {
            case 'Y':
                cout << "\n\nReloading to the main menu this will take a second...";
                system("pause");
                system("cls");
                break;
            case 'N':
                cout << "\n\nAlright... Proceeding to the payment page...\n\n";
                system("pause");
                system("cls");
                break;
            default:
                cout << "You have not entered a valid response ! Please enter again!";
                break;
            }
        } while (orderm != 'Y' && orderm != 'y' && orderm != 'N' && orderm != 'n');
    } while (orderm == 'Y' || orderm == 'y');
}
int main()
{
    string name;
    float age;
    char usercho;
    char choix;
    char orderm;
    float payment = 0;
    askname(name, age, usercho);
    if (age >= 16) {
        choose16(choix, payment, orderm);
    }
    return 0;
}