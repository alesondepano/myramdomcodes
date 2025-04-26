#include <iostream>
#include <string>
using namespace std;

// Structure to store Transaction History Details
struct Transaction {
    string type;
    float amount;
} history;
// All of the Functions Declared
void BankMenu(void);
void GetChoice(char& choice, float balance, float& deposit, float& withdraw, int& bAttempts, int& dAttempts, int& wAttempts, Transaction history[], int& transactionCount);
void BalanceInquiry(float& balance, char& choice, int& bAttempts, Transaction history[], int& transactionCount);
void Deposit(float& deposit, float& balance, char& choice, int& dAttempts, Transaction history[], int& transactionCount);
void Withdrawal(float& withdraw, float& balance, char& choice, int& wAttempts, Transaction history[], int& transactionCount);
void DisplayTransactionHistory(Transaction history[], int transactionCount);
// Variable Initialization
int main()
{
    float balance = 3000, deposit = 0, withdraw = 0;
    char choice;

    int bAttempts = 0, dAttempts = 0, wAttempts = 0;
    int transactionCount = 0;
    Transaction tHistory[10];

    GetChoice(choice, balance, deposit, withdraw, bAttempts, dAttempts, wAttempts, tHistory, transactionCount);

    return 0;
}
// Displays The Bank Menu and the available options
void BankMenu(void)
{
    cout << "\n\t  [Bank et Mirasol]\n";
    cout << "\t---------------------" << endl;
    cout << "\t A. Balance Inquiry\n"
        << "\t B. Deposit\n"
        << "\t C. Withdraw\n"
        << "\t D. Exit\n";
}
// Main Program that loops and asks for user input
void GetChoice(char& choice, float balance, float& deposit, float& withdraw, int& bAttempts, int& dAttempts, int& wAttempts, Transaction history[], int& transactionCount)
{
    do {
        BankMenu();
        cout << "\n\tEnter Your Choice: ";
        cin >> choice;

        switch (toupper(choice)) // switch case for choice variable || toupper to convert small lowercase input to uppercase
        {
        case 'A':
            BalanceInquiry(balance, choice, bAttempts, history, transactionCount);
            break;
        case 'B':
            Deposit(deposit, balance, choice, dAttempts, history, transactionCount);
            break;
        case 'C':
            Withdrawal(withdraw, balance, choice, wAttempts, history, transactionCount);
            break;
        case 'D':
            system("cls");

            string choice1;
            cout << "\n\tDo you want to see Transaction History before Exit? (Yes/No):";
            cin >> choice1;
            if (choice1 == "Yes" || choice1 == "yes" || choice1 == "YES")
            {
                cout << "\n\t[Transaction History]\n";
                cout << "\t------------------------------------------" << endl;
                cout << "\tSuccessful Balance Inquiry: \t\t" << bAttempts << endl;
                cout << "\tSuccessful Deposit: \t\t\t" << dAttempts << endl;
                cout << "\tSuccessful Withdraw: \t\t\t" << wAttempts << endl;
                cout << "\n\t[Logs]\n";
                cout << "\t------------------------------------------" << endl;
                DisplayTransactionHistory(history, transactionCount);
            }
            else if (choice1 == "No" || choice1 == "NO" || choice1 == "no")
            {
                cout << "\n\tThank You for transacting at Banko et Mirasoul!\n\n";
            }
            break;
        }
    } while (toupper(choice) != 'D');
}
// Function for Balance Inquiry Option
void BalanceInquiry(float& balance, char& choice, int& bAttempts, Transaction history[], int& transactionCount)
{
    system("cls");
    cout << "\n\t[BALANCE INQUIRY]\n";
    cout << "\t-------------------------------------" << endl;
    cout << "\tYour Total Balance is: Php " << balance << endl << endl;

    bAttempts++;

    if (transactionCount < 10) {
        history[transactionCount].type = "Balance Inquiry: ";
        history[transactionCount].amount = balance;
        transactionCount++;
    }
    system("pause");
    system("cls");
}
// Function for Deposit Option
void Deposit(float& deposit, float& balance, char& choice, int& dAttempts, Transaction history[], int& transactionCount)
{
    system("cls");
    cout << "\n\t[DEPOSIT]\n";
    cout << "\t-------------------------------------" << endl;
    cout << "\tEnter Deposit Amount (Php): ";
    cin >> deposit;

    if (deposit <= 0) {
        cout << "\n\tError, Please Enter a valid number, Try Again! ";
    }
    else {
        balance += deposit;
        cout << "\n\tDeposit Successful! \n\tYour New Balance is: Php " << balance << endl << endl;
    }

    dAttempts++;

    if (transactionCount < 10) {
        history[transactionCount].type = "Deposit: \t";
        history[transactionCount].amount = deposit;
        transactionCount++;
    }
    system("pause");
    system("cls");
}
// Function for Withdrawal Option
void Withdrawal(float& withdraw, float& balance, char& choice, int& wAttempts, Transaction history[], int& transactionCount)
{
    system("cls");
    cout << "\n\t[WITHDRAWAL]\n";
    cout << "\t-------------------------------------" << endl;
    cout << "\tEnter Withdrawal Amount (Php): ";
    cin >> withdraw;

    if (balance - withdraw < 3000) // checks if the balance falls below the maintaining balance (Php 3000) before proceeding with the withdrawal
    {
        string choice2;
        cout << "\n\tBalance will be below the maintaining amount (Php 3000), proceeding with this transaction may incur a charge.";


        cout << "\n\tDo you want to proceed with this transaction? (Yes/No): "; // asks the user if he/she wants to proceed with the transaction despite the warning
        cin >> choice2;

        if (choice2 == "Yes" || choice2 == "yes" || choice2 == "YES") // nested if statement to confirm the user choice
        {
            balance -= withdraw; // balance = balance - withdraw amount input by the user
            cout << "\n\tYour Balance is: " << balance << endl; // shows the balance after a successful withdrawal
        }
        else if (choice2 == "No" || choice2 == "NO" || choice2 == "no")
        {
            cout << "\n\tReturning Back to MENU\n\n";
        }
    }
    else if (balance < withdraw) // if the balance is not sufficient to accommodate the withdrawal amount
    {
        cout << "\tInsufficient Balance\n";
    }
    else
    {
        balance -= withdraw; // balance = balance - withdraw amount input by the user
        cout << "\tYour Balance is: " << balance << endl << endl; // shows the balance after a successful withdrawal
    }

    wAttempts++; // increment on the number of attempts every time a user chooses a specific option (same case for deposit and balance inquiry function)

    if (transactionCount < 10) { // limits the history to show only the last 10 transactions
        history[transactionCount].type = "Withdrawal: \t"; // labels the history option as "Withdrawal"
        history[transactionCount].amount = withdraw; // gets the user input to determine the corresponding value
        transactionCount++; // increments the data of transaction history to show only the last 10
    }
    system("pause");
    system("cls");
}
// Function to Display Transaction History
void DisplayTransactionHistory(Transaction history[], int transactionCount)
{
    for (int i = 0; i < transactionCount; i++) {
        cout << "\t" << history[i].type << " \t\t Php " << history[i].amount << endl;
    }  // calls what option (type) was picked  // calls the amount the user input
}