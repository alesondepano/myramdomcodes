#include <iostream>
using namespace std;

int main()
{
    string name;
    float age;
    char food;

    //menus
    float buffA = 250;
    float steakB = 300;
    float yagC = 170;

    float chickA = 120;
    float pizzB = 125;

    //
    char loychoice;
    float loyalty;

    char ordm;
    char newuser;

    do {
        //paymennt and total renewed ineach user turn
        float payment = 0;
        float total;

        //acceptingname and age
        cout << "Hello and Welcome dear customer!\n\n"
            << "- - - - - - - - - - - - - - - - - -\n"
            << "\t[USER SIGN UP]\n"
            << "Please enter your name: ";
        cin >> name;

        //validating age
        do {
            cout << "\nPlease enter your age: ";
            cin >> age;
            if (age < 0) {
                cout << "\nPlease enter a valid age (greater than or equal to 0):\n";
            }
        } while (age < 0);

        system("cls");

        cout << "Hello, " << name << " You are " << age << " years old!\n\n";

        //providingf menus for <16 and >16

        if (age > 16) {
            cout << "Since you are " << age << " years old... You are eligible for the 16 and above menu!\n\n";

            do {
                cout << "- - - - - - - - - - - - - - - - - -\n"
                    << "\t[MENU]\n"
                    << "A.\tSpicy Buffalo Chicken\t\t\tPhp 250\n"
                    << "B.\tMedium Rare Steak with Carbonara\tPhp 300\n"
                    << "C.\tYagnyeom x2 Garlic with Rice\t\tPhp 170\n\n"
                    << "Chosen menu: ";
                cin >> food;

                switch (toupper(food)) {
                case 'A':
                    cout << "\n\nYou have chosen A! Also known as Spicy Buffalo Chicken";
                    payment += buffA;
                    break;

                case 'B':
                    cout << "\n\nYou have chosen B! Also known as Medium Rare Steak with Carbonara";
                    payment += steakB;
                    break;

                case 'C':
                    cout << "\n\nYou have chosen C! Also known as Yagnyeom x2 Garlic with Rice";
                    payment += yagC;
                    break;

                default:
                    cout << "That wasn't part of any of the choices, please try again!";
                    break;
                }

                cout << "\n\nYour payment is now: Php " << payment << endl;

                cout << "\n\nWould you still like to order? (Y/N): ";
                cin >> ordm;

                system("cls");

            } while (ordm == 'Y' || ordm == 'y');

        }


        else if (age < 16) {
            cout << "Since you are " << age << " years old... You are eligible for the 16 and below menu!\n\n";
            do {
                cout << "- - - - - - - - - - - - - - - - - -\n"
                    << "\t[MENU]\n"
                    << "A.\tFried Chicken with fries\tPhp 120\n"
                    << "B.\tHawaiian Pizza slice\t\tPhp 125\n"
                    << "Chosen menu: ";
                cin >> food;

                switch (toupper(food)) {
                case 'A':
                    cout << "\n\nYou have chosen A! Also known as Fried Chicken with fries";
                    payment += chickA;
                    break;

                case 'B':
                    cout << "\n\nYou have chosen B! Also known as Hawaiian Pizza slice";
                    payment += pizzB;
                    break;

                default:
                    cout << "That wasn't part of any of the choices, please try again!";
                    break;
                }

                cout << "\n\nYour payment is now: Php " << payment << endl;

                cout << "\n\nWould you still like to order? (Y/N): ";
                cin >> ordm;

                system("cls");

            } while (ordm == 'Y' || ordm == 'y');
        }

        //asking user if they have have loyalty if they have provide dis of 5 %

        cout << "\nProceeding to payment page...\n\n";
        system("pause");
        system("cls");

        cout << "- - - - - - - - - - - - - - - - - -\n"
            << "\t[PAYMENT]\n"
            << "User: " << name << endl
            << "Age: " << age << endl
            << "Total Amount to pay: " << payment << endl
            << "\n\nDo you have loyalty? (Y/N): ";
        cin >> loychoice;

        switch (toupper(loychoice)) {
        case 'Y':
            cout << "\nYou have loyalty! We will be discounting you 5 percent!\n";
            loyalty = payment * 0.05;
            total = payment - loyalty;
            cout << "Your total payment after discount is: Php " << total << endl;
            break;

        case 'N':
            cout << "\nYou have no loyalty!\n";
            total = payment;
            cout << "Your total payment is: Php " << total << endl;
            break;

        default:
            cout << "Please enter a valid choice!\n";
            break;
        }

        cout << "\n\nIs another user gonna order? (Y/N): ";
        cin >> newuser;
        system("cls");

    } while (newuser == 'Y' || newuser == 'y');

    cout << "Thank you for using our service! Goodbye!\n\n";

    return 0;
}