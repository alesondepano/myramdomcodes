#include <iostream>
using namespace std;

// Display menu about the Cafeteria.

void menu(void) {
	cout << "" << endl;
	cout << "\t\t\t\t\t===========================================" << endl;
	cout << "\t\t\t\t\t|            FEUTECH CAFETERIA            |\n";
	cout << "\t\t\t\t\t| --------------------------------------- |" << endl;
	cout << "\t\t\t\t\t|                FOOD KIOSK               |" << endl;
	cout << "\t\t\t\t\t|          A. KM Crumbs                   |" << endl;
	cout << "\t\t\t\t\t|          B. CRAMBAYAN                   |" << endl;
	cout << "\t\t\t\t\t|          C. KAMAYAN CLUB                |" << endl;
	cout << "\t\t\t\t\t|          D. Exit                        |" << endl;
	cout << "\t\t\t\t\t===========================================" << endl;
	
}

// 3 choices function whenever the user input the specific letter of their choice.

char get_choice(void) {
    char choice;
    cout << "\t\t\t\t\tPlease pick your choice: ";
    cin >> choice;
    return choice;
}

void KMCrumbs(void) {
	
	cout << "" << endl;
	cout << "\t\t\t\t\t===========================================" << endl;
	cout << "\t\t\t\t\t|            Welecome to KM Crumbs!       |\n";
	cout << "\t\t\t\t\t| --------------------------------------- |" << endl;
	cout << "\t\t\t\t\t|                Today's Menu:            |" << endl;
	cout << "\t\t\t\t\t|          1. Tapsilong  php 75.00        |" << endl;
	cout << "\t\t\t\t\t|          2. Longsilong php 85.00        |" << endl;
	cout << "\t\t\t\t\t|          3. Hotsilong  php 65.00        |" << endl;
	cout << "\t\t\t\t\t|          4. Hamsilog   php 55.00        |" << endl;
	cout << "\t\t\t\t\t===========================================" << endl;
	cout << endl;
}

void Crambayan(void) {
	
	cout << "" << endl;
	cout << "\t\t\t\t\t===============================================" << endl;
	cout << "\t\t\t\t\t|              Welecome to CRAMBAYAN!         |\n";
	cout << "\t\t\t\t\t| ------------------------------------------- |" << endl;
	cout << "\t\t\t\t\t|                  Today's Menu:              |" << endl;
	cout << "\t\t\t\t\t|  1. Sinigang na Baboy with rice  php 150.00 |" << endl;
	cout << "\t\t\t\t\t|  2. Kare-kare with rice          php 165.00 |" << endl;
	cout << "\t\t\t\t\t|  3. Sisig with rice              php 100.00 |" << endl;
	cout << "\t\t\t\t\t|  4. Beef Kaldereta with rice     php 140.00 |" << endl;
	cout << "\t\t\t\t\t===============================================" << endl;
	cout << endl;
}

void KamayanClub(void) {
	
	cout << "" << endl;
	cout << "\t\t\t\t\t===============================================" << endl;
	cout << "\t\t\t\t\t|              Welecome to KAMAYAM CLUB!      |\n";
	cout << "\t\t\t\t\t| ------------------------------------------- |" << endl;
	cout << "\t\t\t\t\t|                  Today's Menu:              |" << endl;
	cout << "\t\t\t\t\t|  1. Cordon Bleu                 php 120.00  |" << endl;
	cout << "\t\t\t\t\t|  2. Pork Menudo with rice       php 110.00  |" << endl;
	cout << "\t\t\t\t\t|  3. Bicol Express with rice     php 115.00  |" << endl;
	cout << "\t\t\t\t\t|  4. Fried Chicken with rice     php 100.00  |" << endl;
	cout << "\t\t\t\t\t===============================================" << endl;
	cout << endl;
	
}

// Nested switch case with 'if statements' inside from the user choice whether from the 3 choices and then choose within the 4 dishes.


int main() {
    char ch, choice;
    float cash,total;

    do {
        menu();
        ch = get_choice();
        
    
// Choice A


        if (ch == 'A' || ch == 'a') {
            KMCrumbs();
            cout << "\t\t\t\t\tPlease pick one of your choices (1,2,3,4): ";
            cin >> choice;

            switch (choice) {
                case '1':
			{
                	cout << "\t\t\t\t\tTapsilog:   php 75.00\n";
                    cout << "\t\t\t\t\tHow much is your cash? ";
                    cin >> cash;

					if (cash >= 75.00) { 
						total = cash - 75.00;
						cout << "\t\t\t\t\tYour change is: php " << total << endl;
						cout << endl;
						cout << "\t\t\t\t\tThank you!" << endl;
					} else {
						cout << "\t\t\t\t\tInsufficient Balance! Try again!";
					}; break;
			}
                case '2':
			{
                    cout << "\t\t\t\t\tLongsilog:  php 85.00\n";
                    cout << "\t\t\t\t\tHow much is your cash? ";
                    cin >> cash;

					if (cash >= 85.00) { 
						total = cash - 85.00;
						cout << "\t\t\t\t\tYour change is: php " << total << endl;
						cout << endl;
						cout << "\t\t\t\t\tThank you!" << endl;
					} else {
						cout << "\t\t\t\t\tInsufficient Balance! Try again!";
					}; break;
			}
                case '3':
			{
                    cout << "\t\t\t\t\tHotsilog:   php 65.00\n";
                    cout << "\t\t\t\t\tHow much is your cash? ";
                    cin >> cash;

					if (cash >= 65.00) { 
						total = cash - 65.00;
						cout << "\t\t\t\t\tYour change is: php " << total << endl;
						cout << endl;
						cout << "\t\t\t\t\tThank you!" << endl;
					} else {
						cout << "\t\t\t\t\tInsufficient Balance! Try again!";
					}; break;
			}
                case '4':
			{
                    cout << "\t\t\t\t\tHamsilog:   php 55.00\n";
                    cout << "\t\t\t\t\tHow much is your cash? ";
                    cin >> cash;

					if (cash >= 55.00) { 
						total = cash - 55.00;
						cout << "\t\t\t\t\tYour change is: php " << total << endl;
						cout << endl;
						cout << "\t\t\t\t\tThank you!" << endl;
					} else {
						cout << "\t\t\t\t\tInsufficient Balance! Try again!";
					}; break;
			}
                
                default:
                    {
                    cout << "\t\t\t\t\tInvalid input!" << endl;
                    continue;
					}
            }
            
    // Choice B
            
        } else if (ch == 'B' || ch == 'b') {
            Crambayan();
            cout << "\t\t\t\t\tPlease pick one of your choices (1,2,3,4): ";
            cin >> choice;

            switch (choice) {
                case '1':
            {
                    cout << "\t\t\t\t\tSinigang na baboy with rice: php 150.00\n";
                    cout << "\t\t\t\t\tHow much is your cash? ";
                    cin >> cash;

					if (cash >= 150.00) { 
						total = cash - 55.00;
						cout << "\t\t\t\t\tYour change is: php " << total << endl;
						cout << endl;
						cout << "\t\t\t\t\tThank you!" << endl;
					} else {
						cout << "\t\t\t\t\tInsufficient Balance! Try again!";
					}; break;
			}
                case '2':
            {
                    cout << "\t\t\t\t\tKare-kare with rice: php 165.00\n";
                    cout << "\t\t\t\t\tHow much is your cash? ";
                    cin >> cash;

					if (cash >= 165.00) { 
						total = cash - 160.00;
						cout << "\t\t\t\t\tYour change is: php " << total << endl;
						cout << endl;
						cout << "\t\t\t\t\tThank you!" << endl;
					} else {
						cout << "\t\t\t\t\tInsufficient Balance! Try again!";
					}; break;
			}
                case '3':
            {
                    cout << "\t\t\t\t\tSisig with rice: php 100.00\n";
                    cout << "\t\t\t\t\tHow much is your cash? ";
                    cin >> cash;

					if (cash >= 100.00) { 
						total = cash - 100.00;
						cout << "\t\t\t\t\tYour change is: php " << total << endl;
						cout << endl;
						cout << "\t\t\t\t\tThank you!" << endl;
					} else {
						cout << "\t\t\t\t\tInsufficient Balance! Try again!";
					}; break;
			}
                case '4':
            {
                    cout << "\t\t\t\t\tKaldereta with rice: php 140.00\n";
                    cout << "\t\t\t\t\tHow much is your cash? ";
                    cin >> cash;

					if (cash >= 140.00) { 
						total = cash - 140.00;
						cout << "\t\t\t\t\tYour change is: php " << total << endl;
						cout << endl;
						cout << "\t\t\t\t\tThank you!" << endl;
					} else {
						cout << "\t\t\t\t\tInsufficient Balance! Try again!";
					}; break;
			}
                default:
                   {
                   	cout << "\t\t\t\t\tInvalid input!" << endl;
                    continue;
				   }
            }
    // Choice C

        } else if (ch == 'C' || ch == 'c') {
            KamayanClub();
            cout << "\t\t\t\t\tPlease pick one of your choices (1,2,3,4): ";
            cin >> choice;

            switch (choice) {
                case '1':
            {
                    cout << "\t\t\t\t\tkaldireta with rice: php 120.00\n";
                    cout << "\t\t\t\t\tHow much is your cash? ";
                    cin >> cash;

					if (cash >= 120.00) { 
						total = cash - 120.00;
						cout << "\t\t\t\t\tYour change is: php " << total << endl;
						cout << endl;
						cout << "\t\t\t\t\tThank you!" << endl;
					} else {
						cout << "\t\t\t\t\tInsufficient Balance! Try again!";
					}; break;
			}

                case '2':
            {
                    cout << "\t\t\t\t\tMenudo with rice: php 110.00\n";
                    cout << "\t\t\t\t\tHow much is your cash? ";
                    cin >> cash;

					if (cash >= 110.00) { 
						total = cash - 110.00;
						cout << "\t\t\t\t\tYour change is: php " << total << endl;
						cout << endl;
						cout << "\t\t\t\t\tThank you!" << endl;
					} else {
						cout << "\t\t\t\t\tInsufficient Balance! Try again!";
					}; break;
			}
                case '3':
            {
                   	cout << "\t\t\t\t\tBicol express with rice: php 115.00\n";
                    cout << "\t\t\t\t\tHow much is your cash? ";
                    cin >> cash;

					if (cash >= 115.00) { 
						total = cash - 115.00;
						cout << "\t\t\t\t\tYour change is: php " << total << endl;
						cout << endl;
						cout << "\t\t\t\t\tThank you!" << endl;
					} else {
						cout << "\t\t\t\t\tInsufficient Balance! Try again!";
					}; break;
			}
                case '4':
            {
                   	cout << "\t\t\t\t\tFried chicken with rice: php 100.00\n";
                    cout << "\t\t\t\t\tHow much is your cash? ";
                    cin >> cash;

					if (cash >= 100.00) { 
						total = cash - 100.00;
						cout << "\t\t\t\t\tYour change is: php " << total << endl;
						cout << endl;
						cout << "\t\t\t\t\t\tThank you!" << endl;
					} else {
						cout << "\t\t\t\t\tInsufficient Balance! Try again!";
					}; break;
			}
                default:
                    {
                    cout << "\t\t\t\t\tInvalid input!" << endl;
                    continue;
					}
            }
            
	// Exit
	
        } else if (ch == 'D' || ch == 'd') {
			cout << endl;
            cout << "\t\t\t\t\tThank you for visiting FEUTECH cafeteria!" << endl;
            break;
        } else {
            cout << "\t\t\t\t\tInvalid input!" << endl;
        }
    } while (ch != 'D' && ch != 'd');

    return 0;
}
