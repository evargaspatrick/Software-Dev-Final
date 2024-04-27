#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <fstream>
#include <sstream>

using namespace std;

// Base class for games
class Game {
public:
    Game(const string& g, const string& n, int size, const string& sizeType)
        : genre(g), gameName(n), gameSize(size), sizeType(sizeType) {}

    string getGenre() const {
        return genre;
    }

    void setGenre(const string& g) {
        genre = g;
    }

    string getSizeType() const {
        return sizeType;
    }

    void setSizeType(const string& type) {
        sizeType = type;
    }

    string getGameName() const {
        return gameName;
    }

    void setGameName(const string& name) {
        gameName = name;
    }

    int getGameSize() const {
        return gameSize;
    }

    void setGameSize(int size) {
        gameSize = size;
    }

    virtual ~Game() {} // Virtual destructor for polymorphism

protected:
    string genre;
    string gameName;
    int gameSize;
    string sizeType;
};

void saveLibraryToFile(const vector<Game*>& gamesLibrary) {
    ofstream outputFile("C++GameLib.txt"); // Open a file named "C++GameLib.txt" for writing
    if (outputFile.is_open()) { // Check if the file is successfully opened
        for (const auto& game : gamesLibrary) {
            // Write game information to the file
            outputFile << game->getGenre() << ",";
            outputFile << game->getGameName() << ",";
            outputFile << game->getGameSize() << ",";
            outputFile << game->getSizeType() << "\n"; // Add a newline character after each game
        }
        outputFile.close(); // Close the file
        cout << "Game library saved to file 'C++GameLib.txt'." << endl;
    } else {
        cout << "Unable to open file for writing." << endl;
    }
}

void loadLibraryFromFile(vector<Game*>& gamesLibrary) {
    ifstream file("C++GameLib.txt"); // Open the file
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            // Parse each line and extract game information
            // Format: Genre,Name,Size,SizeType
            stringstream ss(line);
            string genre, name, sizeType;
            int size;
            getline(ss, genre, ',');
            getline(ss, name, ',');
            ss >> size;
            ss.ignore(); // Ignore the comma
            getline(ss, sizeType);
            // Create a new game object and add it to the library
            gamesLibrary.push_back(new Game(genre, name, size, sizeType));
        }
        cout << "Library loaded successfully from file.\n" << endl;
        file.close(); // Close the file
    } else {
        cout << "No existing library found. Starting with an empty library.\n" << endl;
    }
}

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
    cout << "Genres:" << endl;
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

    try {
        displayGenres();
        cout << "Enter game genre: ";
        cin >> sizeTypeChoice;
        if (sizeTypeChoice < 1 || sizeTypeChoice > 21) {
            throw invalid_argument("Invalid input for game genre!");
        }
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

        // Check for duplicate game name
        for (const auto& game : gamesLibrary) {
            if (game->getGameName() == name) {
                cout << "A game with the same name already exists in the library." << endl;
                cout << "Please enter a different name or update the existing entry." << endl;
                return;
            }
        }

        displaySizeType();
        cout << "Enter game size type (1 for MB, 2 for GB): ";
        cin >> sizeTypeChoice;
        if (sizeTypeChoice != 1 && sizeTypeChoice != 2) {
            throw invalid_argument("Invalid input for game size type!");
        }
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
        saveLibraryToFile(gamesLibrary);
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
        cout << "Returning to the main menu.\n" << endl;
        return; // Return control to the main menu
    }
}

void editGameEntry(vector<Game*>& gamesLibrary) {
    if (gamesLibrary.empty()) {
        cout << "Your game library is currently empty. There are no games to edit." << endl;
        return;
    }

    string name;
    cout << "Enter the name of the game you want to edit (or type 'exit' to return to the main menu): ";
    cin.ignore(); // Ignore newline character left in buffer
    getline(cin, name);

    if (name == "exit") {
        cout << "Returning to the main menu." << endl;
        return; // Return to the main menu
    }

    auto it = find_if(gamesLibrary.begin(), gamesLibrary.end(), [&name](const Game* game) {
        // Convert both strings to lowercase for comparison
        string lowerName = name;
        transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
        string lowerGameName = game->getGameName();
        transform(lowerGameName.begin(), lowerGameName.end(), lowerGameName.begin(), ::tolower);
        return lowerGameName == lowerName;
    });

    if (it != gamesLibrary.end()) {
        cout << "Game found. What would you like to edit?" << endl;
        cout << "1. Edit genre" << endl;
        cout << "2. Edit name" << endl;
        cout << "3. Edit size" << endl;
        cout << "4. Edit size type" << endl;
        cout << "Make a choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                displayGenres();
                int genreChoice;
                cout << "Enter new genre number: ";
                if (!(cin >> genreChoice)) {
                    // If cin fails (e.g., user inputs a character), clear the error state and ignore the input
                    cin.clear();
                    cin.ignore(numeric_limits<int>::max(), '\n');
                    cout << "Invalid input. Please enter a number." << endl;
                    break;
                }
                if (genreChoice < 1 || genreChoice > 21) {
                    cout << "Invalid input. Genre number must be between 1 and 21." << endl;
                    break;
                }

                cin.ignore(); // Ignore newline character left in buffer

                string newGenre;
                switch (genreChoice) {
                    // Handle genre choices as before
                }

                (*it)->setGenre(newGenre); // Use setter function
                cout << "Genre updated successfully!\n" << endl;
                saveLibraryToFile(gamesLibrary);
                break;
            }
            case 2: {
                cout << "Enter new name: ";
                string newName;
                cin.ignore(); // Ignore newline character left in buffer
                getline(cin, newName);
                (*it)->setGameName(newName); // Use setter function
                cout << "Name updated successfully!\n" << endl;
                saveLibraryToFile(gamesLibrary);
                break;
            }
        case 3: {
            int newSize;
            do {
                cout << "Enter new size: ";
                cin >> newSize;
                if (cin.fail() || newSize <= 0) {
                    cout << "Invalid input. Size must be a positive integer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<int>::max(), '\n');
                } else {
                    (*it)->setGameSize(newSize); // Use setter function
                    cout << "Size updated successfully!\n" << endl;
                    saveLibraryToFile(gamesLibrary);
                    break;
                }
            } while (true);
            return;
        }
        case 4: {
            int newSizeType;
            do {
                cout << "Enter new size type (1 for MB, 2 for GB): ";
                cin >> newSizeType;
                if (cin.fail() || (newSizeType != 1 && newSizeType != 2)) {
                    cout << "Invalid input. Please enter 1 for MB or 2 for GB." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<int>::max(), '\n');
                } else {
                    string newType = (newSizeType == 1) ? "MB" : "GB";
                    (*it)->setSizeType(newType); // Use setter function
                    cout << "Size type updated successfully!\n" << endl;
                    saveLibraryToFile(gamesLibrary);
                    break;
                }
            } while (true);
            return;
        }
        default:
            cout << "Invalid choice." << endl;
        }
    } else {
        cout << "Game not found." << endl;
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
        // Convert both strings to lowercase for comparison
        string lowerName = name;
        transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
        string lowerGameName = game->getGameName();
        transform(lowerGameName.begin(), lowerGameName.end(), lowerGameName.begin(), ::tolower);
        return lowerGameName == lowerName;
    });

    if (it != gamesLibrary.end()) {
        delete *it; // Delete the game object
        gamesLibrary.erase(it); // Remove the pointer from the vector
        cout << "Game removed successfully!\n" << endl;
        saveLibraryToFile(gamesLibrary);
    } else {
        cout << "Game not found." << endl;
    }
}

int main() {
    vector<Game*> gamesLibrary;

    cout << "Welcome to your Digital Game Library." << endl;
    loadLibraryFromFile(gamesLibrary);

    int choice;
    do {
        cout << "\nWhat would you like to do?" << endl;
        cout << "1. View Game Library" << endl;
        cout << "2. Add a game" << endl;
        cout << "3. Remove a game" << endl;
        cout << "4. Edit a game entry" << endl;
        cout << "5. Exit the library" << endl;
        cout << "6. Delete your library" << endl;
        cout << "\nMake a choice: ";

        if (!(cin >> choice)) {
            // If cin fails (e.g., user inputs a character), clear the error state and ignore the input
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue; // Restart the loop to prompt the user again
        }

        // Check if the choice is out of range
        if (choice < 1 || choice > 6) {
            cout << "Invalid choice. Please choose a number from 1 to 6." << endl;
            continue; // Restart the loop to prompt the user again
        }

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
                editGameEntry(gamesLibrary);
                break;
            case 5:
                cout << "Exiting your library now." << endl;
                saveLibraryToFile(gamesLibrary);
                // Clean up dynamically allocated memory
                for (const auto& game : gamesLibrary) {
                    delete game;
                }
                break;
            case 6:
                string confirm;
                cout << "Are you sure you want to delete your library? (y/n): ";
                cin >> confirm;
                if (confirm.length() == 1) {
                    char confirmChar = confirm[0]; // Get the first character
                    if (confirmChar == 'y' || confirmChar == 'Y') {
                        for (const auto& game : gamesLibrary) {
                            delete game;
                        }
                        gamesLibrary.clear();
                        cout << "Your library has been deleted." << endl;
                        saveLibraryToFile(gamesLibrary);
                    } else if (confirmChar == 'n' || confirmChar == 'N') {
                        cout << "Operation canceled." << endl;
                    } else if (gamesLibrary.empty()) {
                        cout << "Your game library is currently empty. There are no games to remove." << endl;
                    } else {
                        cout << "Invalid input. Operation canceled." << endl;
                    }
                } else {
                    cout << "Invalid input. Operation canceled." << endl;
                }
                break;
        }
    } while (choice != 5);

    return 0;
}