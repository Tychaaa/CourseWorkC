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

            cout << "Тимофей Тычков - студент АлтГТУ 2 курса группы ПИ-23" << endl;
            this_thread::sleep_for(chrono::milliseconds(100));
            cout << "Артём Шевцов - студент АлтГТУ 2 курса группы ПИ-23\n" << endl;
            this_thread::sleep_for(chrono::milliseconds(100));

            cout << "Игра выполнена в рамках курсовой работы за 2 курс" << endl;
            this_thread::sleep_for(chrono::milliseconds(100));
            cout << "на тему \"Текстовая RPG в консоли\" на языке C++\n" << endl;
            this_thread::sleep_for(chrono::milliseconds(100));

            cout << "По любым вопросам, предложениям или баг репортам" << endl;
            this_thread::sleep_for(chrono::milliseconds(100));
            cout << "обращайтесь в telegram: @tychaaaa или @Sh1chik" << endl;
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

// Глава "Пролог"
void introduction(Character character)
{
    // Рассказ о мире
    cout << "\nДобро пожаловать в увлекательный мир приключений!" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "\nДавным-давно, в таинственном мире, где свет и тьма танцуют вечный вальс, началось ваше приключение." << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\nЗдесь, среди древних руин и неисследованных земель, каждый шаг может привести к открытию тайны или смертельной опасности." << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\nТемный лес, городские переулки — перед вами открыты неисследованные земли." << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\nЭтот мир слышит своих героев, истории которых еще не написаны." << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\nИ вот вы просыпаетесь, ощущая, что ваше призвание велико, и что вас ждут невероятные испытания." << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\nГолос раздаётся в вашей голове!" << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\nРассказчик: \"- Привет, путник! Ты проснулся в мире, где каждое решение, каждый поступок,\nможет повлиять на судьбу всего мира. Я - твой проводник в этом удивительном приключении.\"" << endl;
    this_thread::sleep_for(chrono::milliseconds(2500));

    cout << "\n\"- Кто ты? Где я?\" - спрашиваете вы, смутно осознавая себя в этом загадочном мире." << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\nРассказчик: \"- Меня зовут Элдрик, рассказчик этого мира. Это Страна Семи Клинков.\"" << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\nРассказчик: \"- А ты — тот, кто изменит ход истории. Твое имя пока забыто, но оно станет легендой.\nТы вольный герой, и твой выбор определит судьбу этого мира.\"" << endl;
    this_thread::sleep_for(chrono::milliseconds(2500));

    // Задержка и создание главного героя
    cout << "\nРассказчик: \"- Секундочку, у меня есть несколько вопросов... Отвечай на вопросы внимательно, они определят твою судьбу.\"" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    character = createMainCharacter();

    cout << "\nРассказчик: \"- Теперь вы готовы начать свое приключение! Удачи, " << character.getName() << "!\"" << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    // Ожидаем нажатия клавиши перед продолжением
    cout << "\nНажмите Enter, чтобы продолжить...";
    cin.ignore();
    cin.get();
}

// Функция для создания главного героя
Character createMainCharacter()
{
    // Создаём объекты оружия и магии
    Weapon* sword = new Weapon("Меч Храбреца", 20, 5);
    Magic* fireball = new Magic("Огненная Вспышка", 30, 10);

    cin.ignore();

    // Вводим имя героя
    cout << "\nРассказчик: \"- Помнишь ли ты свое имя?\"" << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\nМеня зовут: ";
    string name;
    cin >> name;

    cout << "\nРассказчик: \"- Твое имя звучит великолепно, " << name << ". Но чего-то не хватает....\"" << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    // Вектор прилагательных для имени
    vector<string> adjectives = { "Драконорожденный", "Громовержец", "Сияющий", "Неустрашимый", "Магистр", "Повелитель огня", "Стальной", "Теневладыка", "Сокрушитель", "Бесстрашный" };

    // Выбираем случайное прилагательное
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % adjectives.size();
    string randomAdjective = adjectives[randomIndex];

    // Добавляем прилагательное к имени героя
    name = name + " " + randomAdjective;

    cout << "\nРассказчик: \" - Как насчёт - " << name << "?\"" << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));

    // Создаем героя с базовыми параметрами
    Character mainCharacter(name, 100, 50, 50, sword, fireball);

    // Выводим информацию о герое
    cout << "\n\t~~Приветствуйте нового героя~~\n" << endl;
    cout << "Имя: " << mainCharacter.getName() << endl;
    cout << "Уровень: " << mainCharacter.getLevel() << endl;
    cout << "Здоровье: " << mainCharacter.getHealth() << endl;
    cout << "Мана: " << mainCharacter.getMana() << endl;
    cout << "Выносливость: " << mainCharacter.getStamina() << endl;

    return mainCharacter;
}
