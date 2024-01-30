#include <iostream>
#include <fstream>
#include "DataTree.h"

DataTree loadDataFromCSV(const std::string& filePath);
void saveDataToBinaryFile(const std::string& binaryFilePath, const DataTree& dataTree) {
    std::ofstream binaryFile(binaryFilePath, std::ios::binary);
    if (!binaryFile.is_open()) {
        std::cerr << "Błąd: Nie można otworzyć pliku binarnego do zapisu." << std::endl;
        return;
    }
    size_t dataSize = sizeof(DataTree);
    binaryFile.write(reinterpret_cast<const char*>(&dataSize), sizeof(size_t));
    binaryFile.write(reinterpret_cast<const char*>(&dataTree), sizeof(DataTree));
    std::cout << "Dane zapisane do pliku binarnego." << std::endl;
}
DataTree loadDataFromBinaryFile(const std::string& binaryFilePath) {
    DataTree dataTree;
    std::ifstream binaryFile(binaryFilePath, std::ios::binary);
    if (!binaryFile.is_open()) {
        std::cerr << "Błąd: Nie można otworzyć pliku binarnego do odczytu." << std::endl;
        return dataTree;
    }
    size_t dataSize;
    binaryFile.read(reinterpret_cast<char*>(&dataSize), sizeof(size_t));
    if (dataSize == sizeof(DataTree)) {
        binaryFile.read(reinterpret_cast<char*>(&dataTree), sizeof(DataTree));
        std::cout << "Dane odczytane z pliku binarnego." << std::endl;
    } else {
        std::cerr << "Błąd: Nieprawidłowy rozmiar danych w pliku binarnym." << std::endl;
    }
    return dataTree;
}
int main() {
    DataTree dataTree;
    while (true) {
        std::cout << "1. Wczytaj plik CSV\n"
                  << "2. Zapisz dane do pliku binarnego\n"
                  << "3. Odczytaj dane z pliku binarnego\n"
                  << "4. Wypisz sumę autokonsumpcji w danym przedziale\n"
                  << "5. Wypisz sumę eksportu w danym przedziale\n"
                  << "6. Wypisz sumę importu w danym przedziale\n"
                  << "7. Wypisz sumę poboru w danym przedziale\n"
                  << "8. Wypisz sumę produkcji w danym przedziale\n"
                  << "9. Wyjście\n"
                  << "Wybierz opcję: ";
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1: {
                std::string filePath;
                std::cout << "Podaj ścieżkę do pliku CSV: ";
                std::cin >> filePath;
                dataTree = loadDataFromCSV(filePath);
                std::cout << "Dane wczytane pomyślnie." << std::endl;
                break;
            }
            case 2: {
                std::string binaryFilePath;
                std::cout << "Podaj ścieżkę do pliku binarnego do zapisu: ";
                std::cin >> binaryFilePath;
                saveDataToBinaryFile(binaryFilePath, dataTree);
                break;
            }
            case 3: {
                std::string binaryFilePath;
                std::cout << "Podaj ścieżkę do pliku binarnego do odczytu: ";
                std::cin >> binaryFilePath;
                dataTree = loadDataFromBinaryFile(binaryFilePath);
                break;
            }
            case 4: {
                std::string startDateTime, endDateTime;
                std::cout << "Podaj początkową datę i godzinę (np. 2024-01-01 00:00:00): ";
                std::cin >> startDateTime;
                std::cout << "Podaj końcową datę i godzinę (np. 2024-01-01 23:59:59): ";
                std::cin >> endDateTime;
                double sum = dataTree.sumAutokonsumpcja(startDateTime, endDateTime);
                std::cout << "Suma autokonsumpcji w podanym przedziale: " << sum << std::endl;
                break;
            }
            case 5: {
                std::string startDateTime, endDateTime;
                std::cout << "Podaj początkową datę i godzinę (np. 2024-01-01 00:00:00): ";
                std::cin >> startDateTime;
                std::cout << "Podaj końcową datę i godzinę (np. 2024-01-01 23:59:59): ";
                std::cin >> endDateTime;
                double sum = dataTree.sumEksport(startDateTime, endDateTime);
                std::cout << "Suma eksportu w podanym przedziale: " << sum << std::endl;
                break;
            }
            case 6: {
                std::string startDateTime, endDateTime;
                std::cout << "Podaj początkową datę i godzinę (np. 2024-01-01 00:00:00): ";
                std::cin >> startDateTime;
                std::cout << "Podaj końcową datę i godzinę (np. 2024-01-01 23:59:59): ";
                std::cin >> endDateTime;
                double sum = dataTree.sumImport(startDateTime, endDateTime);
                std::cout << "Suma importu w podanym przedziale: " << sum << std::endl;
                break;
            }
            case 7: {
                std::string startDateTime, endDateTime;
                std::cout << "Podaj początkową datę i godzinę (np. 2024-01-01 00:00:00): ";
                std::cin >> startDateTime;
                std::cout << "Podaj końcową datę i godzinę (np. 2024-01-01 23:59:59): ";
                std::cin >> endDateTime;
                double sum = dataTree.sumPobor(startDateTime, endDateTime);
                std::cout << "Suma poboru w podanym przedziale: " << sum << std::endl;
                break;
            }
            case 8: {
                std::string startDateTime, endDateTime;
                std::cout << "Podaj początkową datę i godzinę (np. 2024-01-01 00:00:00): ";
                std::cin >> startDateTime;
                std::cout << "Podaj końcową datę i godzinę (np. 2024-01-01 23:59:59): ";
                std::cin >> endDateTime;
                double sum = dataTree.sumProdukcja(startDateTime, endDateTime);
                std::cout << "Suma produkcji w podanym przedziale: " << sum << std::endl;
                break;
            }
            case 9:
                return 0;
            default:
                std::cerr << "Nieprawidłowy wybór. Spróbuj ponownie." << std::endl;
        }
    }
    return 0;
}

DataTree loadDataFromCSV(const std::string& filePath) {
    DataTree dataTree;
    return dataTree;
}