#include "Function.h"

// Функция для вывода заставки игры (медленно)
void gameTitleSlow()
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

    this_thread::sleep_for(chrono::milliseconds(1000));
}

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
    }

    cout << "\n" << endl;
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

    gameTitleSlow();

    do {
        cout << "Главное меню:\n" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "1. Начать игру" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "2. Авторы" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "3. Выйти из игры" << endl;

        cout << "\nВыберите опцию: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); // Сбрасываем флаг ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
        }

        switch (choice) {
        case 1:
            // Начать игру
            gameTitle();
            this_thread::sleep_for(chrono::milliseconds(1000));
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

            gameTitleSlow();
            break;
        case 3:
            // Выйти из игры
            cout << "\nРассказчик: \"Ты уверен, что хочешь покинуть этот захватывающий мир? Буду ждать твоего возвращения!\"\n";
            exit(0);  // Завершить программу
            break;
        default:
            cout << "\nРассказчик: \"- Ты что-то путаешь, мой дорогой. Выбирай внимательнее.\"" << endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
            system("cls");
            gameTitle();
            break;
        }
    } while (choice != 1);  // Цикл продолжается, пока пользователь не выберет "Начать игру"
}

// Вступление
void introduction(Character& character)
{
    // Определяем отступ слева
    int leftIndent = 10;

    // ASCII-арт для названия главы с отступом слева
    vector<string> chapterArt = {
        "     _____                _                            ",
        "    |  __ \\              | |                           ",
        "    | |__) | _ __   ___  | |  ___    __ _  _   _   ___ ",
        "    |  ___/ | '__| / _ \\ | | / _ \\  / _` || | | | / _ \\",
        "    | |     | |   | (_) || || (_) || (_| || |_| ||  __/",
        "    |_|     |_|    \\___/ |_| \\___/  \\__, | \\__,_| \\___|",
        "                                     __/ |              ",
        "                                    |___/               "
    };

    for (const string& line : chapterArt) {
        // Добавляем отступ слева
        cout << string(leftIndent, ' ') << line << endl;
    }

    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\n\n" << endl;

    // Рассказ о мире
    Screen::displayText("\nДобро пожаловать в увлекательный мир приключений!");
    this_thread::sleep_for(chrono::milliseconds(1000));

    Screen::displayText("\nДавным-давно, в таинственном мире, где свет и тьма танцуют вечный вальс, началось ваше приключение.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\nЗдесь, среди древних руин и неисследованных земель, каждый шаг может привести к открытию тайны или смертельной опасности.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\nТемный лес, городские переулки — перед вами открыты неисследованные земли.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\nЭтот мир слышит своих героев, истории которых еще не написаны.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\nИ вот вы просыпаетесь, ощущая, что ваше призвание велико, и что вас ждут невероятные испытания.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\nГолос раздаётся в вашей голове!");
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\nРассказчик: ";
    this_thread::sleep_for(chrono::milliseconds(500));
    Screen::displayCharacterByCharacter("\"- Привет, путник! Ты проснулся в мире, где каждое решение, каждый поступок,\nможет повлиять на судьбу всего мира. Я - твой проводник в этом удивительном приключении.\"\n");

    Screen::displayCharacterByCharacter("\n\"- Кто ты? Где я?\"");
    this_thread::sleep_for(chrono::milliseconds(1000));

    Screen::displayText(" - спрашиваете вы, смутно осознавая себя в этом загадочном мире.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\nРассказчик: ";
    this_thread::sleep_for(chrono::milliseconds(500));
    Screen::displayCharacterByCharacter("\"- Меня зовут Элдрик, рассказчик этого мира. Это Страна Семи Клинков.\"\n");

    cout << "\nРассказчик: ";
    this_thread::sleep_for(chrono::milliseconds(500));
    Screen::displayCharacterByCharacter("\"- А ты — тот, кто изменит ход истории. Твое имя пока забыто, но оно станет легендой.\nТы вольный герой, и твой выбор определит судьбу этого мира.\"\n");

    // Задержка и создание главного героя
    cout << "\nРассказчик: ";
    this_thread::sleep_for(chrono::milliseconds(500));
    Screen::displayCharacterByCharacter("\"- Секундочку, у меня есть несколько вопросов... Отвечай на вопросы внимательно, они определят твою судьбу.\"\n");

    character = createMainCharacter();

    cout << "\nРассказчик: ";
    this_thread::sleep_for(chrono::milliseconds(500));
    Screen::displayCharacterByCharacter("\"- Впереди вас ждет долгий путь. На востоке расположен прекрасный город Эмердейл. Туда и направляйтесь.\"\n");

    cout << "\nРассказчик: ";
    this_thread::sleep_for(chrono::milliseconds(500));
    Screen::displayCharacterByCharacter("\"- Удачи, " + character.getName() + "!\"\n");

    // Ожидаем нажатия клавиши перед продолжением
    Screen::displayText("\nНажмите Enter, чтобы продолжить...");
    cin.ignore();
    cin.get();
}

// Глава "Пролог"
void prologue(Character& character)
{
    gameTitle();

    // Переход от разговора с рассказчиком к началу путешествия
    Screen::displayText("\nРассветное утро озаряет страну, когда вы решаете следовать по указанию рассказчика.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\nВы отправляетесь в путь... Впереди виднеется повозка, стоящая на обочине дороги.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\nНа повозке сидит старый мужчина, собирающийся вот-вот отправиться в путь.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\nСтарик: ";
    this_thread::sleep_for(chrono::milliseconds(500));
    Screen::displayCharacterByCharacter("\"- Дорогой путник, судя по всему, наши пути совпадают. Желаете ли вы составить мне компанию в пути?\"\n");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("\n1. \"- Да, я присоединюсь. Безопаснее двигаться вдвоем.\"");
    this_thread::sleep_for(chrono::milliseconds(500));
    Screen::displayText("2. \"- Благодарю за предложение, но я предпочту идти в одиночестве.\"");
    this_thread::sleep_for(chrono::milliseconds(500));

    cout << "\nВаш ответ: ";

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\nСтарик: ";
        this_thread::sleep_for(chrono::milliseconds(500));
        Screen::displayCharacterByCharacter("\"- Отлично! Присаживайтесь, в путь!\"\n");
        this_thread::sleep_for(chrono::milliseconds(1500));

        Screen::displayText("\nВы садитесь на повозку и начинаете беседовать с попутчиком.");

        cout << "\nСтарик: ";
        this_thread::sleep_for(chrono::milliseconds(500));
        Screen::displayCharacterByCharacter("\"- Куда направляемся?\"\n");
        this_thread::sleep_for(chrono::milliseconds(1500));

        Screen::displayText("\n1. \"- В город Эмердейл, там меня ждут дела.\"");
        this_thread::sleep_for(chrono::milliseconds(500));
        Screen::displayText("2. \"- Просто иду, куда дорога занесет.\"");
        this_thread::sleep_for(chrono::milliseconds(500));

        cout << "\nВаш ответ: ";

        int destinationChoice;
        cin >> destinationChoice;

        switch (destinationChoice)
        {
        case 1:
            cout << "\nСтарик: ";
            this_thread::sleep_for(chrono::milliseconds(500));
            Screen::displayCharacterByCharacter("\"- Отличный выбор! Эмердейл - великолепный город. Давайте вместе отправимся туда.\"\n");
            this_thread::sleep_for(chrono::milliseconds(1500));
            break;
        case 2:
            cout << "\nСтарик: ";
            this_thread::sleep_for(chrono::milliseconds(500));
            Screen::displayCharacterByCharacter("\"- Дорога часто приносит сюрпризы. Давайте в путь! Я отправляюсь в Эмердейл.\"\n");
            this_thread::sleep_for(chrono::milliseconds(1500));
            break;
        default:
            break;
        }

        Screen::displayText("\nВаше путешествие начинается. Всю поездку вы общаетесь со стариком, и дорога пролетает незаметно.");
        this_thread::sleep_for(chrono::milliseconds(1500));
        Screen::displayText("\nВы приобрели немного опыта.");
        this_thread::sleep_for(chrono::milliseconds(1000));
        Screen::displayText("\n(Добавлено +20 опыта)");
        this_thread::sleep_for(chrono::milliseconds(1000));
        Screen::displayText("\n");

        // Увеличение опыта персонажа
        character.setExperience(character.getExperience() + 20);
        break;

    case 2:
        cout << "\nСтарик: ";
        this_thread::sleep_for(chrono::milliseconds(500));
        Screen::displayCharacterByCharacter("\"- Понимаю, каждый выбирает свой путь. Надеюсь, встретимся вновь.\"\n");
        this_thread::sleep_for(chrono::milliseconds(1500));

        Screen::displayText("\nСтарик махнул вам на прощание, и вы отправились в путь одни.");
        this_thread::sleep_for(chrono::milliseconds(1500));
        Screen::displayText("\nВы решили идти пешком, укрепляя свою выносливость и получая дополнительный опыт.");
        this_thread::sleep_for(chrono::milliseconds(1000));
        Screen::displayText("\n(Добавлено +50 опыта. Потеряно -20 выносливости)");
        this_thread::sleep_for(chrono::milliseconds(1000));
        Screen::displayText("\n");

        // Увеличение опыта и уменьшение выносливости персонажа
        character.setExperience(character.getExperience() + 50);
        character.setStamina(character.getStamina() - 20);
        break;

    default:
        break;
    }
}

// Обучение бою
void combatTraining(Character& character)
{
    // Продолжение после исследования города Эмердейл
    Screen::displayText("\nПосле тщательного исследования города Эмердейл, " + character.getName() + " решил двинуться дальше по своим делам.\n");
    this_thread::sleep_for(chrono::milliseconds(1500));

    Screen::displayText("Герой заскочил в таверну, насладился беседой с гостеприимным трактирщиком, встретил лично воеводу города,\nвзял на себя обязанность пообщаться с местными жителями и, наконец, заглянул в ткацкую мастерскую.");
    this_thread::sleep_for(chrono::milliseconds(1500));

    // Внезапно, воевода Стелсвин подходит к герою.
    cout << "\nКапитан Стелсвин: ";
    this_thread::sleep_for(chrono::milliseconds(500));
    Screen::displayCharacterByCharacter("\"- " + character.getName() + ", я видел, как ты исследовал наш город. У меня есть предложение для тебя.\"\n");
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\nКапитан Стелсвин: ";
    this_thread::sleep_for(chrono::milliseconds(500));
    Screen::displayCharacterByCharacter("\"- Мы ищем сильных воинов, способных защитить нашу страну Семи Клинков. Я хочу предложить тебе тренировку.\"\n");
    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\nКапитан Стелсвин решительно продолжает: ";
    this_thread::sleep_for(chrono::milliseconds(500));
    Screen::displayCharacterByCharacter("\"- Это будет тренировочный бой, в котором ты сможешь продемонстрировать свои навыки. Что скажешь?\"\n");
    this_thread::sleep_for(chrono::milliseconds(1500));

    // Пользователь делает выбор
    cout << "\n1. Принять предложение и приступить к тренировке."
        << "\n2. Отказаться и продолжить свое путешествие."
        << "\n\nВаш выбор: ";

    int trainingChoice;
    cin >> trainingChoice;

    switch (trainingChoice)
    {
    case 1:

        cout << "\nКапитан Стелсвин: ";
        this_thread::sleep_for(chrono::milliseconds(500));
        Screen::displayCharacterByCharacter("\"- Отлично! Давай начнем тренировку. Пойдем на тренировочную площадку.\"\n");
        this_thread::sleep_for(chrono::milliseconds(1500));
        break;

    case 2:

        cout << "\nКапитан Стелсвин: ";
        this_thread::sleep_for(chrono::milliseconds(500));
        Screen::displayCharacterByCharacter("\"- Но я вижу в тебе потенциал. Даже если ты не хочешь, я проведу тренировочный бой, чтобы помочь тебе развить свои навыки.\"\n");
        this_thread::sleep_for(chrono::milliseconds(1500));
        break;

    default:
        break;
    }
}

// Функция для создания оружия и магии в зависимости от класса
pair<Weapon*, Magic*> createEquipment(string& className)
{
    Weapon* defaultWeapon = new Weapon("Старый меч", 10, 3);       // Оружие по умолчанию
    Magic* defaultMagic = new Magic("Простое заклинание", 15, 5);  // Магия по умолчанию

    if (className == "Воин") {
        return make_pair(new Weapon("Меч Воина", 20, 8), new Magic("Силовой удар", 12, 20));
    }
    else if (className == "Маг") {
        return make_pair(new Weapon("Посох Мага", 15, 5), new Magic("Огненная вспышка", 25, 10));
    }
    else if (className == "Вор") {
        return make_pair(new Weapon("Кинжал Вора", 18, 6), new Magic("Теневой удар", 15, 15));
    }
    else if (className == "Бродяга") {
        return make_pair(new Weapon("Старый Кастет", 15, 3), new Magic("Меткая атака", 10, 18));
    }
    else if (className == "Жрец") {
        return make_pair(new Weapon("Святой Жезл", 17, 7), new Magic("Исцеление", 20, 12));
    }
    else if (className == "Рыцарь") {
        return make_pair(new Weapon("Меч Рыцаря", 22, 10), new Magic("Благословение щита", 10, 20));
    }
    else {
        // По умолчанию возвращаем стандартное оружие и магию
        return make_pair(defaultWeapon, defaultMagic);
    }
}

// Функция для создания главного героя
Character createMainCharacter()
{
    // Вводим имя героя
    cout << "\nРассказчик: ";
    this_thread::sleep_for(chrono::milliseconds(500));
    Screen::displayCharacterByCharacter("\"- Помнишь ли ты свое имя?\"\n");

    cout << "\nГерой: ";
    this_thread::sleep_for(chrono::milliseconds(500));
    Screen::displayCharacterByCharacter("- Меня зовут ");

    string name;
    cin >> name;

    cout << "\nРассказчик: ";
    this_thread::sleep_for(chrono::milliseconds(500));
    Screen::displayCharacterByCharacter("\"- Твое имя звучит великолепно, " + name + ". Но чего-то не хватает....\"\n");

    // Вектор прилагательных для имени
    vector<string> adjectives = { "Драконорожденный", "Громовержец", "Сияющий", "Неустрашимый", "Магистр", "Повелитель огня", "Стальной", "Теневладыка", "Сокрушитель", "Бесстрашный" };

    // Выбираем случайное прилагательное
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % adjectives.size();
    string randomAdjective = adjectives[randomIndex];

    // Добавляем прилагательное к имени героя
    name = name + " " + randomAdjective;

    cout << "\nРассказчик: ";
    this_thread::sleep_for(chrono::milliseconds(500));
    Screen::displayCharacterByCharacter("\" - Как насчёт - " + name + "?\"\n");

    // Выбираем класс
    vector<string> classes = { "Воин", "Маг", "Вор", "Бродяга", "Жрец", "Рыцарь" };
    cout << "\nРассказчик: ";
    this_thread::sleep_for(chrono::milliseconds(500));
    Screen::displayCharacterByCharacter("\"- Теперь скажи мне, в чём твоё призвание?\"\n\n");
    
    // Выводим таблицу с характеристиками классов
    cout << "+----+---------------+---------------+---------------+---------------+----------------------------------------+--------------------------------------------------+" << endl;
    Sleep(100);
    cout << "| #  |    Класс      |   Здоровье    | Выносливость  |     Мана      |                 Оружие                 |                      Магия                       |" << endl;
    Sleep(100);
    cout << "+----+---------------+---------------+---------------+---------------+----------------------------------------+--------------------------------------------------+" << endl;

    for (int i = 0; i < classes.size(); ++i) {
        // Получаем характеристики класса
        string className = classes[i];
        auto equipment = createEquipment(className);
        Weapon* weapon = equipment.first;
        Magic* magic = equipment.second;

        // Выводим информацию в таблице
        cout << "| " << setw(1) << i + 1 << "  |" << setw(15) << left << className;

        // Выводим характеристики в зависимости от класса
        if (className == "Воин") {
            cout << "|" << setw(15) << left << 110 << "|";
            cout << setw(15) << left << 120 << "|";
            cout << setw(15) << left << 80 << "|";
        }
        else if (className == "Маг") {
            cout << "|" << setw(15) << left << 80 << "|";
            cout << setw(15) << left << 80 << "|";
            cout << setw(15) << left << 150 << "|";
        }
        else if (className == "Вор") {
            cout << "|" << setw(15) << left << 90 << "|";
            cout << setw(15) << left << 90 << "|";
            cout << setw(15) << left << 110 << "|";
        }
        else if (className == "Бродяга") {
            cout << "|" << setw(15) << left << 110 << "|";
            cout << setw(15) << left << 110 << "|";
            cout << setw(15) << left << 110 << "|";
        }
        else if (className == "Жрец") {
            cout << "|" << setw(15) << left << 110 << "|";
            cout << setw(15) << left << 90 << "|";
            cout << setw(15) << left << 110 << "|";
        }
        else if (className == "Рыцарь") {
            cout << "|" << setw(15) << left << 140 << "|";
            cout << setw(15) << left << 100 << "|";
            cout << setw(15) << left << 100 << "|";
        }

        // Выводим информацию об оружии и магии
        cout << setw(15) << left << weapon->getName() << " (dmg: " << setw(2) << weapon->getDamage() << ", stm: -" << setw(2) << weapon->getCost() << setw(6) << ")" << "|";
        cout << setw(25) << left << magic->getName() << " (dmg: " << setw(2) << magic->getDamage() << ", mana: -" << setw(2) << magic->getCost() << setw(5) << ")" << "|" << endl;
    }

    // Закрываем таблицу
    cout << "+----+---------------+---------------+---------------+---------------+----------------------------------------+--------------------------------------------------+" << endl;

    int choice;
    cout << "\nВаш выбор: ";
    cin >> choice;

    // Проверка корректности ввода
    while (choice < 1 || choice > classes.size()) {
        cout << "\nРассказчик: ";
        this_thread::sleep_for(chrono::milliseconds(500));
        Screen::displayCharacterByCharacter("\"- Ты что-то путаешь, мой дорогой. Попробуй выбрать снова: \"");
        cin >> choice;
    }

    // Получаем название выбранного класса
    string className = classes[choice - 1];

    // Устанавливаем параметры в конструкторе
    Weapon* defaultWeapon = nullptr;
    Magic* defaultMagic = nullptr;

    // Создаем героя с базовыми параметрами в зависимости от класса
    Character mainCharacter(name, 100, 50, 50, defaultWeapon, defaultMagic, className);

    // Получаем указатели на оружие и магию в зависимости от класса и устанавливаем их герою
    auto equipment = createEquipment(className);
    mainCharacter.setWeapon(equipment.first);
    mainCharacter.setMagic(equipment.second);

    if (className == "Воин") {
        mainCharacter.setHealth(110);
        mainCharacter.setStamina(120);
        mainCharacter.setMana(80);
    }
    else if (className == "Маг") {
        mainCharacter.setHealth(80);
        mainCharacter.setStamina(80);
        mainCharacter.setMana(150);
    }
    else if (className == "Вор") {
        mainCharacter.setHealth(90);
        mainCharacter.setStamina(90);
        mainCharacter.setMana(110);
    }
    else if (className == "Бродяга") {
        mainCharacter.setHealth(110);
        mainCharacter.setStamina(110);
        mainCharacter.setMana(110);
    }
    else if (className == "Жрец") {
        mainCharacter.setHealth(110);
        mainCharacter.setStamina(90);
        mainCharacter.setMana(110);
    }
    else if (className == "Рыцарь") {
        mainCharacter.setHealth(140);
        mainCharacter.setStamina(100);
        mainCharacter.setMana(100);
    }

    // Выводим информацию о герое
    cout << "\n\t~~Приветствуйте нового героя~~\n" << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "Имя: " << mainCharacter.getName() << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "Класс: " << mainCharacter.getClassType() << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "Уровень: " << mainCharacter.getLevel() << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "Здоровье: " << mainCharacter.getHealth() << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "Мана: " << mainCharacter.getMana() << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "Выносливость: " << mainCharacter.getStamina() << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "Оружие: " << mainCharacter.getWeapon()->getName() << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "Магия: " << mainCharacter.getMagic()->getName() << endl;
    this_thread::sleep_for(chrono::milliseconds(100));

    return mainCharacter;
}

// Заполнить г.Эмердейл неигровыми персонажами
void createEmerdealNPC(Location emerdeal, Character character)
{
    // Трактирщик
    vector<string> innkeeperPhrases = {
        "\"- Добро пожаловать в 'Золотую Лиру', " + character.getName() + "! Что привело вас сегодня в наш прекрасный трактир?\"",
        "\"- Если вы хотите узнать больше о нашем городе, поговорите с Воеводой Стелсвином. Он знает много интересного.\"",
        "\"- Здесь всегда рады новым гостям. В 'Золотой Лире' вы найдете не только отличные напитки, но и приятное общество.\"",
        "\"- Расскажите мне о своих приключениях, и я расскажу вам старинные легенды этого места.\"",
        "\"- Необычайные события происходят вокруг. Будьте готовы к встречам, которые могут изменить вашу судьбу.\""
    };
    NPC innkeeper(
        "Трактирщик Гастин",
        "Хозяин таверны 'Золотая Лира'. Гастин - приветливый хозяин, умеющий рассказывать интересные истории.\n"
        "В его таверне всегда теплая атмосфера и отличный выбор напитков. Здесь можно встретить путешественников и местных жителей.",
        innkeeperPhrases
    );
    emerdeal.addInteractiveObject(&innkeeper);

    // Воевода
    vector<string> wardenPhrases = {
        "\"- Добро пожаловать в Эмердейл, " + character.getName() + ".Я - Капитан Стелсвин, воевода города.Если у вас есть вопросы,\nобращайся ко мне, я готов помочь.Наш город всегда открыт для новых героев.\"",
        "\"- Когда вы закончите свои дела в городе, не забудьте вернуться ко мне. Может быть, у меня будет для вас задание.\"",
        "\"- В Эмердейле каждый герой находит свой путь. Мы гордимся своими жителями и всегда готовы приветствовать новых обитателей.\"",
        "\"- За городом много опасностей, но и много возможностей. Исследуйте мир, и, может быть, вы станете частью наших легенд.\"",
        "\"- Наш город богат не только историей, но и торговлей. Посетите рынок, чтобы найти необходимые вам вещи.\""
    };
    NPC warden(
        "Капитан Стелсвин",
        "Воевода Эмердейла. Капитан Стелсвин - опытный лидер, посвятивщий свою жизнь защите города.\n"
        "Его решительность и мудрость сделали его уважаемым лидером, который присматривает за безопасностью города.",
        wardenPhrases
    );
    emerdeal.addInteractiveObject(&warden);

    // Еще один житель города
    vector<string> citizenPhrases = {
        "\"- Приветствую вас, " + character.getName() + "! Если у вас есть вопросы или нужна информация, обращайтесь. В Эмердейле всегда рады новым знакомствам.\"",
        "\"- Здесь так много интересных мест. Если вы решите исследовать город, обратите внимание на нашу ткацкую мастерскую. Там создают удивительные вещи.\"",
        "\"- Недавно в лесу возле города появилась странная пещера. Говорят, что внутри она полна загадок и сокровищ. Может быть, вам стоит проверить?\"",
        "\"- Если вы заблудитесь в городе, обратитесь к стражам. Они всегда готовы помочь и указать верное направление.\"",
        "\"- В Эмердейле много тайн. Если у вас есть смелость и жажда приключений, вам точно не будет скучно.\""
    };
    NPC citizen(
        "Эльза Белль",
        "Местная жительница. Эльза - добрая и отзывчивая женщина.\n"
        "Она знает много интересных историй о городе и его жителях.",
        citizenPhrases
    );
    emerdeal.addInteractiveObject(&citizen);
}
