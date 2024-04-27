#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// Base class for games
class Game {
public:
    Game(const string& g, const string& n, int size, const string& sizeType) 
        : genre(g), gameName(n), gameSize(size), sizeType(sizeType) {}

    virtual string getGenre() const {
        return genre;
    }

    string getSizeType() const {
        return sizeType;
    }

    virtual string getGameName() const {
        return gameName;
    }

    virtual int getGameSize() const {
        return gameSize;
    }

    virtual ~Game() {} // Virtual destructor for polymorphism

protected:
    string genre;
    string gameName;
    int gameSize;
    string sizeType;
};

// Function to display the library of games
void displayLibrary(const vector<Game*>& gamesLibrary) {
    if (gamesLibrary.empty()) {
        cout << "Your game library is currently empty. You can add your first game!" << endl;
    } else {
        cout << endl;
        cout << "Games in the library:" << endl;
        for (const auto& game : gamesLibrary) {
            cout << "Name: " << game->getGameName() << ", ";
            cout << "Genre: " << game->getGenre() << ", ";
            cout << "Size: " << game->getGameSize() << " " << game->getSizeType() << endl;
        }
    }
}

// Function to display size type options
void displaySizeType() {
    cout << "1. MB (Megabytes)" << endl;
    cout << "2. GB (Gigabytes)" << endl;
}

// Function to display genre options
void displayGenres() {
    cout << "1. Action" << endl;
    cout << "2. Adventure" << endl;
    cout << "3. Role-playing (RPG)" << endl;
    cout << "4. Shooter" << endl;
    cout << "5. Strategy" << endl;
    cout << "6. Simulation" << endl;
    cout << "7. Puzzle" << endl;
    cout << "8. Racing" << endl;
    cout << "9. Sports" << endl;
    cout << "10. Fighting" << endl;
    cout << "11. Horror" << endl;
    cout << "12. Sandbox" << endl;
    cout << "13. Platformer" << endl;
    cout << "14. Stealth" << endl;
    cout << "15. Survival" << endl;
    cout << "16. Open world" << endl;
    cout << "17. Massively multiplayer online (MMO)" << endl;
    cout << "18. Educational" << endl;
    cout << "19. Music/rhythm" << endl;
    cout << "20. Party/mini-games" << endl;
    cout << "21. Other" << endl;
}

// Function to add a game to the library
void addGame(vector<Game*>& gamesLibrary) {
    string genre, name, sizeType;
    int size;
    int sizeTypeChoice;

    displayGenres();
    cout << "Enter game genre: ";
    cin >> sizeTypeChoice;
    switch (sizeTypeChoice) {
        case 1: genre = "Action"; break;
        case 2: genre = "Adventure"; break;
        case 3: genre = "Role-playing (RPG)"; break;
        case 4: genre = "Shooter"; break;
        case 5: genre = "Strategy"; break;
        case 6: genre = "Simulation"; break;
        case 7: genre = "Puzzle"; break;
        case 8: genre = "Racing"; break;
        case 9: genre = "Sports"; break;
        case 10: genre = "Fighting"; break;
        case 11: genre = "Horror"; break;
        case 12: genre = "Sandbox"; break;
        case 13: genre = "Platformer"; break;
        case 14: genre = "Stealth"; break;
        case 15: genre = "Survival"; break;
        case 16: genre = "Open world"; break;
        case 17: genre = "Massively multiplayer online (MMO)"; break;
        case 18: genre = "Educational"; break;
        case 19: genre = "Music/rhythm"; break;
        case 20: genre = "Party/mini-games"; break;
        case 21: genre = "Other"; break;
        default:
            throw invalid_argument("Invalid input for game genre!");
    }

    cout << "Enter game name: ";
    cin.ignore();
    getline(cin, name);

    displaySizeType();
    try {
        cout << "Enter game size type (1 for MB, 2 for GB): ";
        cin >> sizeTypeChoice;
        switch (sizeTypeChoice) {
            case 1:
                sizeType = "MB";
                cout << "Enter game size in MB: ";
                break;
            case 2:
                sizeType = "GB";
                cout << "Enter game size in GB: ";
                break;
            default:
                throw invalid_argument("Invalid input for game size type!");
        }
        cin >> size;

        if (cin.fail()) {
            throw invalid_argument("Invalid input for game size!");
        }

        gamesLibrary.push_back(new Game(genre, name, size, sizeType));
        cout << "Game added successfully!\n" << endl;
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
    }
}

// Function to remove a game from the library
void removeGame(vector<Game*>& gamesLibrary) {
    if (gamesLibrary.empty()) {
        cout << "Your game library is currently empty. There are no games to remove." << endl;
        return;
    }

    string name;
    cout << "Enter the name of the game you want to remove: ";
    cin.ignore(); // Ignore newline character left in buffer
    getline(cin, name);

    auto it = find_if(gamesLibrary.begin(), gamesLibrary.end(), [&name](const Game* game) {
        return game->getGameName() == name;
    });

    if (it != gamesLibrary.end()) {
        delete *it; // Delete the game object
        gamesLibrary.erase(it); // Remove the pointer from the vector
        cout << "Game removed successfully!\n" << endl;
    } else {
        cout << "Game not found." << endl;
    }
}

int main() {
    vector<Game*> gamesLibrary;

    cout << "Welcome to your Digital Game Library." << endl;
    
    int choice;
    do {
        cout << "\nWhat would you like to do?" << endl;
        cout << "1. View Game Library" << endl;
        cout << "2. Add a game" << endl;
        cout << "3. Remove a game" << endl;
        cout << "4. Exit the library" << endl;
        cout << "5. Delete your library" << endl;
        cout << "\nMake a choice: ";

        cin >> choice;
        switch (choice) {
            case 1:
                displayLibrary(gamesLibrary);
                break;
            case 2:
                addGame(gamesLibrary);
                break;
            case 3:
                removeGame(gamesLibrary);
                break;
            case 4:
                cout << "Exiting your library now." << endl;
                // Clean up dynamically allocated memory
                for (const auto& game : gamesLibrary) {
                    delete game;
                }
                break;
            case 5:
                char confirm;
                cout << "Are you sure you want to delete your library? (y/n): ";
                cin >> confirm;
                if (confirm == 'y' || confirm == 'Y') {
                    for (const auto& game : gamesLibrary) {
                        delete game;
                    }
                    gamesLibrary.clear();
                    cout << "Your library has been deleted." << endl;
                } else if (confirm == 'n' || confirm == 'N') {
                    cout << "Operation canceled." << endl;
                } else {
                    cout << "Invalid input. Operation canceled." << endl;
                }
                break;
            default:
                cout << "Invalid choice. Please choose a number from 1 to 5." << endl;
                // Clear error flags and ignore remaining input until newline
                cin.clear(); 
                cin.ignore(numeric_limits<int>::max(), '\n'); 
                break;
        }
    } while (choice != 4);

    return 0;
}
