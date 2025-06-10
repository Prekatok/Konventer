#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <limits>
#include <map>
#include <algorithm>

using namespace std;

// Класс для хранения статистики игрока
class PlayerStats {
private:
    int totalGames = 0;
    int wins = 0;
    int losses = 0;
    int currentStreak = 0;
    int maxStreak = 0;
    int recordEasy = INT_MAX;
    int recordMedium = INT_MAX;
    int recordHard = INT_MAX;
    int totalPoints = 0;
    int level = 1;

    map<int, int> levelRequirements = {
        {1, 0},
        {2, 100},
        {3, 250},
        {4, 500},
        {5, 1000},
        {6, 2000},
        {7, 4000},
        {8, 8000},
        {9, 15000},
        {10, 30000}
    };

public:
    // Добавление победы
    int addWin(const string& difficulty, int attempts) {
        totalGames++;
        wins++;
        currentStreak++;

        if (currentStreak > maxStreak) {
            maxStreak = currentStreak;
        }

        // Обновляем рекорды
        if (difficulty == "easy" && attempts < recordEasy) {
            recordEasy = attempts;
        }
        else if (difficulty == "medium" && attempts < recordMedium) {
            recordMedium = attempts;
        }
        else if (difficulty == "hard" && attempts < recordHard) {
            recordHard = attempts;
        }

        // Начисляем очки
        int points = calculatePoints(difficulty, attempts);
        totalPoints += points;

        // Проверяем уровень
        checkLevel();

        return points;
    }

    // Добавление поражения
    void addLoss() {
        totalGames++;
        losses++;
        currentStreak = 0;
    }

    // Расчет очков
    int calculatePoints(const string& difficulty, int attempts) {
        map<string, int> basePoints = {
            {"easy", 10},
            {"medium", 25},
            {"hard", 50}
        };

        // Чем меньше попыток, тем больше очков
        int multiplier = max(1, 10 - attempts);
        return basePoints[difficulty] * multiplier;
    }

    // Проверка уровня
    void checkLevel() {
        for (auto it = levelRequirements.rbegin(); it != levelRequirements.rend(); ++it) {
            if (totalPoints >= it->second) {
                level = it->first;
                break;
            }
        }
    }

    // Методы для сохранения/загрузки
    void saveToFile(const string& filename) {
        ofstream file(filename);
        if (file.is_open()) {
            file << totalGames << endl;
            file << wins << endl;
            file << losses << endl;
            file << currentStreak << endl;
            file << maxStreak << endl;
            file << recordEasy << endl;
            file << recordMedium << endl;
            file << recordHard << endl;
            file << totalPoints << endl;
            file << level << endl;
            file.close();
        }
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            file >> totalGames;
            file >> wins;
            file >> losses;
            file >> currentStreak;
            file >> maxStreak;
            file >> recordEasy;
            file >> recordMedium;
            file >> recordHard;
            file >> totalPoints;
            file >> level;
            file.close();
        }
    }

    // Вывод статистики
    void showStats() {
        cout << "\n=== Ваша статистика ===" << endl;
        cout << "Всего игр: " << totalGames << endl;
        cout << "Побед: " << wins << " | Поражений: " << losses << endl;
        cout << "Текущая серия побед: " << currentStreak << endl;
        cout << "Максимальная серия побед: " << maxStreak << endl;
        cout << "Рекорды:" << endl;
        cout << "  Легкий уровень: " << (recordEasy != INT_MAX ? to_string(recordEasy) : "N/A") << " попыток" << endl;
        cout << "  Средний уровень: " << (recordMedium != INT_MAX ? to_string(recordMedium) : "N/A") << " попыток" << endl;
        cout << "  Сложный уровень: " << (recordHard != INT_MAX ? to_string(recordHard) : "N/A") << " попыток" << endl;
        cout << "\nВсего очков: " << totalPoints << endl;
        cout << "Уровень: " << level << endl;
    }
};

// Функция для игры
bool playGame(PlayerStats& stats) {
    cout << "\nВыберите уровень сложности:" << endl;
    cout << "1. Легкий (1-50, 10 попыток)" << endl;
    cout << "2. Средний (1-100, 7 попыток)" << endl;
    cout << "3. Сложный (1-200, 5 попыток)" << endl;

    int choice;
    while (true) {
        cout << "Ваш выбор (1-3): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Пожалуйста, введите число от 1 до 3." << endl;
            continue;
        }

        if (choice >= 1 && choice <= 3) {
            break;
        }
        cout << "Пожалуйста, введите 1, 2 или 3." << endl;
    }

    string difficulty;
    int max_num, max_attempts;

    if (choice == 1) {
        difficulty = "easy";
        max_num = 50;
        max_attempts = 10;
    }
    else if (choice == 2) {
        difficulty = "medium";
        max_num = 100;
        max_attempts = 7;
    }
    else {
        difficulty = "hard";
        max_num = 200;
        max_attempts = 5;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, max_num);
    int secret_number = dis(gen);

    int attempts = 0;
    int guess;

    cout << "\nЯ загадал число от 1 до " << max_num << ". У вас есть " << max_attempts << " попыток." << endl;

    while (attempts < max_attempts) {
        attempts++;
        int remaining = max_attempts - attempts;

        cout << "Попытка " << attempts << ". Ваше предположение: ";
        cin >> guess;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Пожалуйста, введите целое число." << endl;
            attempts--;
            continue;
        }

        if (guess < 1 || guess > max_num) {
            cout << "Число должно быть в диапазоне от 1 до " << max_num << "." << endl;
            attempts--;
            continue;
        }

        if (guess == secret_number) {
            cout << "\nПоздравляю! Вы угадали число " << secret_number << " за " << attempts << " попыток!" << endl;
            int points = stats.addWin(difficulty, attempts);
            cout << "Вы заработали " << points << " очков!" << endl;
            return true;
        }

        if (guess < secret_number) {
            cout << "Загаданное число больше. Осталось попыток: " << remaining << endl;
        }
        else {
            cout << "Загаданное число меньше. Осталось попыток: " << remaining << endl;
        }
    }

    cout << "\nК сожалению, вы проиграли. Я загадал число " << secret_number << "." << endl;
    stats.addLoss();
    return false;
}

// Главное меню
int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Добро пожаловать в игру 'Угадай число'!" << endl;

    PlayerStats stats;
    stats.loadFromFile("guess_number_stats.txt");

    while (true) {
        cout << "\n=== Главное меню ===" << endl;
        cout << "1. Начать новую игру" << endl;
        cout << "2. Показать статистику" << endl;
        cout << "3. Выйти" << endl;

        int choice;
        cout << "Ваш выбор (1-3): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Пожалуйста, введите число от 1 до 3." << endl;
            continue;
        }

        switch (choice) {
        case 1:
            playGame(stats);
            stats.saveToFile("guess_number_stats.txt");
            break;
        case 2:
            stats.showStats();
            break;
        case 3:
            cout << "Спасибо за игру! До свидания!" << endl;
            return 0;
        default:
            cout << "Пожалуйста, выберите 1, 2 или 3." << endl;
        }
    }

    return 0;
}
