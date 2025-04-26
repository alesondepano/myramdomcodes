#include <iostream>
#include <string>
using namespace std;

void DisplayCatalog(string product[], double price[], int quantity[], int itemCount);
void ProcessOrder(string product[], double price[], int quantityArr[], int itemCount, int soldCount[], string clientNames[], double clientTotals[], int& clientCount);
void DisplayMostSoldItems(string product[], int soldCount[], int itemCount);

const int MAX_CLIENTS = 5;
const int ITEM_COUNT = 5;

int main()
{
    string product[ITEM_COUNT] = { "Paracetamol", "Ibuprofen", "Antihistamine", "Loperamide", "Diphenhydramine" };
    double price[ITEM_COUNT] = { 5.00, 7.00, 3.00, 4.00, 6.00 };
    int quantity[ITEM_COUNT] = { 25, 10, 30, 15, 20 };
    int soldCount[ITEM_COUNT] = { 0 };

    string clientNames[MAX_CLIENTS];
    double clientTotals[MAX_CLIENTS] = { 0 };
    int clientCount = 0;

    char continueShopping;
    int choice;

    do {
        system("cls");
        cout << "\n\t[Dashboard]" << endl;
        cout << "\t---------------------------\n";
        cout << "\t1. Buy Products\n\t2. View Most Sold Items\n\t3. Exit\n";
        cout << "\t---------------------------\n";
        cout << "\n\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            ProcessOrder(product, price, quantity, ITEM_COUNT, soldCount, clientNames, clientTotals, clientCount);
            if (clientCount >= MAX_CLIENTS) {
                cout << "\n\tReached the maximum number of clients. Exiting the system.\n";
                system("pause");
                return 0;
            }
            break;
        case 2:
            DisplayMostSoldItems(product, soldCount, ITEM_COUNT);
            system("pause"); 
            break;
        case 3:
            cout << "\n\tThank you for shopping!\n";
            system("pause"); 
            return 0;
        default:
            cout << "\tInvalid choice. Please try again.\n";
            system("pause");
        }

        if (clientCount >= MAX_CLIENTS) {
            cout << "\n\tReached the maximum number of clients. Exiting the system.\n";
            system("pause");
            break;
        }

        cout << "\n\tIs there another user who wants to shop? (y/n): ";
        cin >> continueShopping;
    } while ((continueShopping == 'y' || continueShopping == 'Y') && clientCount < MAX_CLIENTS);

    cout << "\n\tThank you for shopping!\n";
    system("pause");
    return 0;
}

void DisplayCatalog(string product[], double price[], int quantity[], int itemCount) {
    cout << "\n\t[Product Catalog]\n" << endl;
    cout << "\t-------------------------------------------------------------------\n";
    cout << "\tCode\tProducts\t\t\t\tPrice\t\tQty." << endl;
    cout << "\t-------------------------------------------------------------------\n";

    for (int i = 0; i < itemCount; i++) {
        cout << "\t " << i + 1 << "\t" << product[i] << "\t\t\t\t" << price[i] <<".00" << "\t\t" << quantity[i] << endl;
    }

    cout << "\t-------------------------------------------------------------------\n";
}

void ProcessOrder(string product[], double price[], int quantityArr[], int itemCount, int soldCount[], string clientNames[], double clientTotals[], int& clientCount)
{
    int choice, orderQuantity;
    double totalCost = 0;
    string orderSummary = "";
    string clientName;
    char viewMostSold;

    cout << "\n\tEnter your name: ";
    cin.ignore();
    getline(cin, clientName);

    do {
        system("cls");
        DisplayCatalog(product, price, quantityArr, itemCount);

        cout << "\n\tEnter the product number you wish to purchase (or 0 to checkout): ";
        cin >> choice;

        if (choice == 0) {
            break;
        }

        if (choice < 1 || choice > itemCount) {
            cout << "\tInvalid product number.\n";
            system("pause");
            continue;
        }

        cout << "\tEnter the quantity: ";
        cin >> orderQuantity;

        if (orderQuantity > quantityArr[choice - 1]) {
            cout << "\tInsufficient quantity in stock.\n";
            system("pause");
            continue;
        }

        quantityArr[choice - 1] -= orderQuantity;
        soldCount[choice - 1] += orderQuantity;
        double cost = orderQuantity * price[choice - 1];
        totalCost += cost;
        orderSummary += "\t" + to_string(orderQuantity) + " x " + product[choice - 1] + " Php" + to_string(price[choice - 1]) + " each = Php" + to_string(cost) + "\n";
        cout << "\t" << orderQuantity << " " << product[choice - 1] << "(s) added to your order.\n";
        system("pause");

    } while (choice != 0);

    if (totalCost > 0) {
        cout << "\n\t[Order Summary]\n";
        cout << "\t--------------------------------------------------------------\n";
        cout << orderSummary;
        cout << "\t--------------------------------------------------------------\n";
        cout << "\tTotal Cost: Php" << totalCost << "\n";

        double payment;
        do {
            cout << "\tEnter payment amount: Php";
            cin >> payment;
            if (payment < totalCost) {
                cout << "\tInsufficient payment. Please enter at least Php" << totalCost << ".\n";
            }
        } while (payment < totalCost);

        double change = payment - totalCost;
        cout << "\tPayment received. Thank you!\n";
        cout << "\tChange: Php" << change << "\n";

        if (clientCount < MAX_CLIENTS) {
            clientNames[clientCount] = clientName;
            clientTotals[clientCount] = totalCost;
            clientCount++;
        }

        cout << "\n\tDo you want to see the most sold items? (y/n): ";
        cin >> viewMostSold;

        if (viewMostSold == 'y' || viewMostSold == 'Y') {
            DisplayMostSoldItems(product, soldCount, itemCount);
            system("pause");
        }
    }
    else {
        cout << "\n\tNo items were purchased.\n";
    }
    system("pause");
}


void DisplayMostSoldItems(string product[], int soldCount[], int itemCount) {
    cout << "\n\t[Most Sold Items]\n" << endl;
    cout << "\t--------------------------------------------------------------\n";
    cout << "\tProducts\t\t\t\tQty. Sold" << endl;
    cout << "\t--------------------------------------------------------------\n";

    for (int i = 0; i < itemCount; i++) {
        if (soldCount[i] > 0) {
            cout << "\t" << product[i] << "\t\t\t\t" << soldCount[i] << endl;
        }
    }
    cout << "\t--------------------------------------------------------------\n";
}