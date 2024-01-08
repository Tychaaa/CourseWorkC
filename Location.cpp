#include "Location.h"

// Конструктор
Location::Location() : name(""), description("") {}

// Конструктор с параметрами 1
Location::Location(const string& n, const string& desc) : name(n), description(desc) {}

// Конструктор с параметрами 2
Location::Location(const string& n, const string& desc, const vector<InteractiveObject*>& objs) : name(n), description(desc), objects(objs) {}

// Деструктор
Location::~Location() {}

// Метод, вызываемый при входе в локацию
void Location::onEnter()
{
    // Выводим текущую локацию и её описание
    Screen::displayCharacterByCharacter("\nВы находитесь в " + name + ".\n" + description + "\n");
    this_thread::sleep_for(chrono::milliseconds(1000));

    // Основной цикл, реализующий взаимодействие с объектами
    while (true) 
    {
        // Выводим информацию о доступных объектах
        Screen::displayText("\n\t~~Доступные объекты для взаимодействия~~\n");
        this_thread::sleep_for(chrono::milliseconds(500));

        // Выводим имена NPC, доступных для взаимодействия
        for (size_t i = 0; i < objects.size(); ++i) 
        {
            Screen::displayText(to_string(i + 1) + ". " + objects[i]->getName());
            this_thread::sleep_for(chrono::milliseconds(300));
        }

        // Вариант "закончить взаимодействие"
        Screen::displayText("0. Закончить взаимодействие");
        this_thread::sleep_for(chrono::milliseconds(700));

        int selectedObjectIndex;
        cout << "\nВаш выбор: ";
        // Проверка наличия ошибок ввода и ввода букв
        while (!(cin >> selectedObjectIndex) || (selectedObjectIndex < 0 || selectedObjectIndex > static_cast<int>(objects.size())))
        {
            // Очистка буфера ввода
            cin.clear();
            // Игнорирование оставшихся символов в буфере ввода
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // Выводим сообщение об ошибке и просим ввести ответ заново
            Screen::displayDialog("Рассказчик", "Неверный выбор. Пожалуйста, введите корректный номер.");
            cout << "\nВаш выбор: ";
        }

        // Пользователь выбрал "закончить взаимодействие"
        if (selectedObjectIndex == 0) {
            break;
        }

        // Выводим варианты действий для выбранного объекта
        vector<Action> objectActions = objects[selectedObjectIndex - 1]->getAvailableActions();
        this_thread::sleep_for(chrono::milliseconds(300));

        Screen::displayText("\n\t~~\"" + objects[selectedObjectIndex - 1]->getName() + "\"~~\n");
        this_thread::sleep_for(chrono::milliseconds(100));

        for (size_t i = 0; i < objectActions.size(); ++i) {
            Screen::displayText(to_string(i + 1) + ". " + objectActions[i].getDescription());
            this_thread::sleep_for(chrono::milliseconds(500));
        }

        int selectedActionIndex;
        cout << "\nВаш выбор: ";
        // Проверка наличия ошибок ввода и ввода букв
        while (!(cin >> selectedActionIndex) || (selectedActionIndex < 0 || selectedActionIndex > static_cast<int>(objectActions.size())))
        {
            // Очистка буфера ввода
            cin.clear();
            // Игнорирование оставшихся символов в буфере ввода
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // Выводим сообщение об ошибке и просим ввести ответ заново
            Screen::displayDialog("Рассказчик", "Неверный выбор. Пожалуйста, введите корректный номер.");
            cout << "\nВаш выбор: ";
        }

        // Выполняем выбранное действие
        Action& selectedAction = objectActions[selectedActionIndex - 1];
        objects[selectedObjectIndex - 1]->performAction(selectedAction);
    }
}

// Метод для добавления интерактивных объектов
void Location::addInteractiveObject(InteractiveObject* object)
{
    objects.push_back(object);
}
