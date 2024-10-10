// Main.cpp
#include <iostream>
#include "LinkedList.h"
#include "Rainfall.h"

void printMenu() {
    std::cout << "Enter your choice" << std::endl;
    std::cout << "A -- Add a month of statistics" << std::endl;
    std::cout << "E -- Edit a month of statistics" << std::endl;
    std::cout << "P -- Print report" << std::endl;
    std::cout << "Q -- Quit" << std::endl;
    std::cout << "Choice: ";
}

int main() {
    LinkedList<Rainfall> rainfallList;
    char choice;
    std::string month;
    int rainfall;
    int numMonths;
    bool found;

    std::cout << "Enter the number of months to be saved: ";
    std::cin >> numMonths;

    do {
        printMenu();
        std::cin >> choice;
        choice = toupper(choice);

        switch (choice) {
        case 'A':
            if (rainfallList.getLength() < numMonths) {
                std::cout << "Enter Month: ";
                std::cin >> month;
                std::cout << "Enter Rainfall (in Inches): ";
                std::cin >> rainfall;
                Rainfall newRainfall(month, rainfall);
                rainfallList.insert(rainfallList.getLength() + 1, newRainfall);
            }
            else {
                std::cout << "ERROR: Cannot add more months. Limit reached." << std::endl;
            }
            break;
        case 'E':
            std::cout << "Enter Month: ";
            std::cin >> month;
            found = false;
            for (int i = 1; i <= rainfallList.getLength(); i++) {
                if (rainfallList.getEntry(i).getMonth() == month) {
                    std::cout << "Enter Rainfall (in Inches): ";
                    std::cin >> rainfall;
                    Rainfall editedRainfall(month, rainfall);
                    rainfallList.setEntry(i, editedRainfall);
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "ERROR: Invalid Month" << std::endl;
            }
            break;
        case 'P':
            if (rainfallList.getLength() > 0) {
                int totalRainfall = 0;
                int maxRainfall = rainfallList.getEntry(1).getRainfall();
                int minRainfall = rainfallList.getEntry(1).getRainfall();
                std::string maxMonth = rainfallList.getEntry(1).getMonth();
                std::string minMonth = rainfallList.getEntry(1).getMonth();

                for (int i = 1; i <= rainfallList.getLength(); i++) {
                    int currentRainfall = rainfallList.getEntry(i).getRainfall();
                    std::string currentMonth = rainfallList.getEntry(i).getMonth();
                    totalRainfall += currentRainfall;

                    if (currentRainfall > maxRainfall) {
                        maxRainfall = currentRainfall;
                        maxMonth = currentMonth;
                    }
                    if (currentRainfall < minRainfall) {
                        minRainfall = currentRainfall;
                        minMonth = currentMonth;
                    }
                }

                double averageRainfall = static_cast<double>(totalRainfall) / rainfallList.getLength();

                std::cout << "Total Rainfall: " << totalRainfall << " inches" << std::endl;
                std::cout << "Average Rainfall: " << averageRainfall << " inches" << std::endl;
                std::cout << "Most Rainfall: " << maxMonth << " had " << maxRainfall << " inches" << std::endl;
                std::cout << "Least Rainfall: " << minMonth << " had " << minRainfall << " inches" << std::endl;
            }
            else {
                std::cout << "No data available." << std::endl;
            }
            break;
        case 'Q':
            std::cout << "Goodbye!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 'Q');

    return 0;
}
