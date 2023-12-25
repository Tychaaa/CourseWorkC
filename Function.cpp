#include "Function.h"

// Функция для вывода заставки игры
void gameTitle()
{
    system("cls");

    // ASCII-арт, разбитый на строки
    string asciiArt[] = {
        " ____   __,     ____, ____,  ____,  ____,    ____,  ____,    ____,  ____,  ____,  ____,  __,   _,  _, _  _, ",
        "(-|__) (-|     (-/_| (-|  \\ (-|_,  (-(__    (-/  \\ (-|_,    (-|  \\ (-|_,  (-(__  (-|    (-|   (-|\\ | (-\\_/  ",
        " _|__)  _|__,  _/  |, _|__/  _|__,  ____)    _\\__/, _|       _|__/  _|__,  ____)  _|,    _|_,  _| \\|,  _|,  ",
        "(      (      (      (      (      (        (      (        (      (      (      (      (     (       (     "
    };

    // Выводим ASCII-арт построчно с задержкой
    for (const auto& line : asciiArt) {
        cout << line << '\n';
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    cout << "\n" << endl;

    Sleep(1200);
}

// Функция для вывода заставки разработчиков
void prodTitle()
{
    system("cls");

    // ASCII-арт, разбитый на строки
    vector<string> asciiArt = {
        " _______               _      _                  ",
        "|__   __|             | |    | |                 ",
        "   | |    _   _   ___ | |__  | | __  ___  __   __",
        "   | |   | | | | / __|| '_ \\ | |/ / / _ \\ \\ \\ / /",
        "   | |   | |_| || (__ | | | ||   < | (_) | \\ V / ",
        "   |_|    \\__, | \\___||_| |_||_|\\_\\ \\___/   \\_/  ",
        "           __/ |                                 ",
        "          |___/                                  ",
        "                   _                             ",
        "                  | |                            ",
        "  __ _  _ __    __| |                            ",
        " / _` || '_ \\  / _` |                            ",
        "| (_| || | | || (_| |                            ",
        " \\__,_||_| |_| \\__,_|                            ",
        "                                                 ",
        "                                                 ",
        "  _____  _                   _                      ",
        " / ____|| |                 | |                     ",
        "| (___  | |__    ___ __   __| |_  ___   ___  __   __",
        " \\___ \\ | '_ \\  / _ \\\\ \\ / /| __|/ __| / _ \\ \\ \\ / /",
        " ____) || | | ||  __/ \\ V / | |_ \\__ \\| (_) | \\ V / ",
        "|_____/ |_| |_| \\___/  \\_/   \\__||___/ \\___/   \\_/  ",
        "                                                     ",
        "                                                     ",
        " _____                    _               _    _               ",
        "|  __ \\                  | |             | |  (_)              ",
        "| |__) | _ __   ___    __| |  __ _   ___ | |_  _   ___   _ __  ",
        "|  ___/ | '__| / _ \\  / _` | / _` | / __|| __|| | / _ \\ | '_ \\ ",
        "| |     | |   | (_) || (_| || (_| || (__ | |_ | || (_) || | | |",
        "|_|     |_|    \\___/  \\__,_| \\__,_| \\___| \\__||_| \\___/ |_| |_|",
        "                                                                "
    };

    // Выводим ASCII-арт построчно с задержкой
    for (const auto& line : asciiArt) {
        cout << line << '\n';
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    Sleep(1000);
}

// Функция для вывода главного меню игры
void mainMenu()
{
    int choice;

    do {

        gameTitle();

        cout << "Главное меню:\n" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "1. Начать игру" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "2. Авторы" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "3. Выйти из игры" << endl;

        cout << "\nВыберите опцию: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Начать игру
            break;
        case 2:
            // Показать информацию об авторах
            prodTitle();

            cout << "Тимофей Тычков - студент 2 курса АлтГТУ группы ПИ-23" << endl;
            this_thread::sleep_for(chrono::milliseconds(100));
            cout << "Артём Шевцов - студент 2 курса АлтГТУ группы ПИ-23\n" << endl;
            this_thread::sleep_for(chrono::milliseconds(100));

            cout << "Игра выполнена в рамках курсовой работы за 2 курс" << endl;
            this_thread::sleep_for(chrono::milliseconds(100));
            cout << "на тему \"Текстовая RPG в консоли\" на языке C++\n" << endl;
            this_thread::sleep_for(chrono::milliseconds(100));

            cout << "По любым вопросам, предложениям или баг репортам" << endl;
            this_thread::sleep_for(chrono::milliseconds(100));
            cout << "обращайтесь на почту timofeytychkov@gmail.com" << endl;
            this_thread::sleep_for(chrono::milliseconds(100));

            cout << "\nЧтобы продолжить нажмите любую кнопку" << endl;
            _getch();
            break;
        case 3:
            // Выйти из игры
            cout << "\nДо свидания! Спасибо за игру.\n";
            exit(0);  // Завершить программу
            break;
        default:
            cout << "\nНеверный выбор. Пожалуйста, выберите существующий вариант.\n";
            break;
        }
    } while (choice != 1);  // Цикл продолжается, пока пользователь не выберет "Начать игру"
}

// Функция для создания главного героя
Character createMainCharacter()
{
    Weapon* sword = new Weapon("Меч Храбреца", 20, 5);
    Magic* fireball = new Magic("Огненная Вспышка", 30, 10);

    cin.ignore();

    // Вводим имя героя
    cout << "\nВведите имя героя: ";
    string name;
    getline(cin, name);

    // Создаем героя с базовыми параметрами
    Character mainCharacter(name, 100, 50, 50, sword, fireball);

    // Выводим информацию о герое
    cout << "\nСоздан главный герой:\n";
    cout << "Имя: " << mainCharacter.getName() << endl;
    cout << "Уровень: " << mainCharacter.getLevel() << endl;
    cout << "Здоровье: " << mainCharacter.getHealth() << endl;
    cout << "Мана: " << mainCharacter.getMana() << endl;
    cout << "Выносливость: " << mainCharacter.getStamina() << endl;

    return mainCharacter;
}
