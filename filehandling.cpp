#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Player {
    string nickname;
    int age;
    double score1;
    double score2;
};

struct Node {
    Player player;
    Node* next;
};

Node* head = nullptr;

void addRecord(const Player& player) {
    Node* newNode = new Node;
    newNode->player = player;
    newNode->next = head;
    head = newNode;
}

void viewRecords() {
    if (head == nullptr) {
        cout << "No records to display!!!" << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        cout << "Nickname: " << current->player.nickname << endl;
        cout << "Age: " << current->player.age << endl;
        cout << "Score1: " << current->player.score1 << endl;
        cout << "Score2: " << current->player.score2 << endl;
        cout << "----------------------" << endl;
        current = current->next;
    }
}

void viewSpecificRecord(const string& nickname) {
    if (head == nullptr) {
        cout << "No records to display !!!" << endl;
        return;
    }

    Node* current = head;
    bool found = false;
    while (current != nullptr) {
        if (current->player.nickname == nickname) {
            cout << "Nickname: " << current->player.nickname << endl;
            cout << "Age: " << current->player.age << endl;
            cout << "Score 1: " << current->player.score1 << endl;
            cout << "Score 2: " << current->player.score2 << endl;
            cout << "----------------------------------" << endl;
            found = true;
            break;
        }
        current = current->next;
    }
    if (!found) {
        cout << "Record not found!!!" << endl;
    }
}

void computeAverage() {
    if (head == nullptr) {
        cout << "No records to  compute averages!!!" << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        double average = (current->player.score1 + current->player.score2) / 2.0;
        cout << "Nickname: " << current->player.nickname << endl;
        cout << "Average: " << average << endl;
        cout << "----------------------" << endl;
        current = current->next;
    }
}

void showMaxAverage() {
    if (head == nullptr) {
        cout << "No records to compute max average!!!" << endl;
        return;
    }

    Node* current = head;
    double maxAverage = -1;
    while (current != nullptr) {
        double average = (current->player.score1 + current->player.score2) / 2.0;
        if (average > maxAverage) {
            maxAverage = average;
        }
        current = current->next;
    }

    current = head;
    while (current != nullptr) {
        double average = (current->player.score1 + current->player.score2) / 2.0;
        if (average == maxAverage) {
            cout << "Nickname: " << current->player.nickname << endl;
            cout << "Average: " << average << endl;
            cout << "----------------------" << endl;
        }
        current = current->next;
    }
}

void showMinAverage() {
    if (head == nullptr) {
        cout << "No records to compute min average!" << endl;
        return;
    }

    Node* current = head;
    double minAverage = 999999;
    while (current != nullptr) {
        double average = (current->player.score1 + current->player.score2) / 2.0;
        if (average < minAverage) {
            minAverage = average;
        }
        current = current->next;
    }

    current = head;
    while (current != nullptr) {
        double average = (current->player.score1 + current->player.score2) / 2.0;
        if (average == minAverage) {
            cout << "Nickname: " << current->player.nickname << endl;
            cout << "Average Score: " << average << endl;
            cout << "----------------------------------" << endl;
        }
        current = current->next;
    }
}

void deleteRecords() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

void deleteSpecificRecord(const string& nickname) {
    if (head == nullptr) {
        cout << "No records to delete!" << endl;
        return;
    }

    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->player.nickname != nickname) {
        previous = current;
        current = current->next;
    }
    if (current == nullptr) {
        cout << "Record with nickname " << nickname << " not found!" << endl;
        return;
    }

    if (previous == nullptr) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    delete current;
    cout << "Record with nickname " << nickname << " deleted!" << endl;
}

void openFile() {
    ofstream outFile("player_records.txt");
    Node* current = head;
    while (current != nullptr) {
        outFile << current->player.nickname << endl;
        outFile << current->player.age << endl;
        outFile << current->player.score1 << " " << current->player.score2 << endl;
        current = current->next;
    }
    outFile.close();
    cout << "Records saved to 'player_records.txt'." << endl;
}

void closeFile() {
    cout << "File closed." << endl;
}

int main() {
    int choice;
    do {
        cout << "==============================================" << endl;
        cout << "\t\tMENU" << endl;
        cout << "==============================================" << endl;
        cout << "1. Add record" << endl;
        cout << "2. View specific player's records" << endl;
        cout << "3. Compute for the average" << endl;
        cout << "4. Show the player(s) who get the max average." << endl;
        cout << "5. Show the player(s) who get the min average." << endl;
        cout << "6. View all players records" << endl;
        cout << "7. Delete specific record" << endl;
        cout << "8. Delete all records" << endl;
        cout << "9. Open to file" << endl;
        cout << "10. Close to file" << endl;
        cout << "11. Exit" << endl;
        cout << "==============================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Player newPlayer;
                cout << "Enter nickname: ";
                cin >> newPlayer.nickname;
                cout << "Enter age: ";
                cin >> newPlayer.age;
                cout << "Enter score 1: ";
                cin >> newPlayer.score1;
                cout << "Enter score 2: ";
                cin >> newPlayer.score2;
                addRecord(newPlayer);
                break;
            }

            case 2: {
                string nicknameToView;
                cout << "Enter the nickname of the player: ";
                cin >> nicknameToView;
                viewSpecificRecord(nicknameToView);
                break;
            }

            case 3: {
                computeAverage();
                break;
            }

            case 4: {
                showMaxAverage();
                break;
            }

            case 5: {
                showMinAverage();
                break;
            }

            case 6: {
                viewRecords();
                break;
            }

            case 7: {
                string nicknameToDelete;
                cout << "Enter the nickname of the player to delete: ";
                cin >> nicknameToDelete;
                deleteSpecificRecord(nicknameToDelete);
                break;
            }

            case 8: {
                deleteRecords();
                break;
            }

            case 9: {
                openFile();
                break;
            }

            case 10: {
                closeFile();
                break;
            }

            case 11: {
                cout << "Exiting program..." << endl;
            break;}

            }

        } while (choice != 11);

 return 0;
    }