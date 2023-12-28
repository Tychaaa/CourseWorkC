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
    Screen::displayCharacterByCharacter("\nВы находитесь в " + name + ".\n" + description + "\n");
    //Screen::displayText("\nВы находитесь в " + name + ".\n" + description);
    this_thread::sleep_for(chrono::milliseconds(1000));

    while (true) {
        // Выводим информацию о доступных объектах
        Screen::displayText("\n\t~~Доступные объекты для взаимодействия~~\n");
        this_thread::sleep_for(chrono::milliseconds(500));

        for (size_t i = 0; i < objects.size(); ++i) {
            Screen::displayText(to_string(i + 1) + ". " + objects[i]->getName());
            this_thread::sleep_for(chrono::milliseconds(300));
        }

        // Вариант "закончить взаимодействие"
        Screen::displayText("0. Закончить взаимодействие");
        this_thread::sleep_for(chrono::milliseconds(700));

        cout << "\nВаш выбор: ";

        // Ждем ввода от пользователя и обрабатываем
        char userInput = Input::getUserInput();

        // Преобразуем char в int и вычитаем '0', чтобы получить индекс объекта
        int selectedObjectIndex = userInput - '0' - 1;

        if (selectedObjectIndex == -1) {
            // Пользователь выбрал "закончить взаимодействие"
            break;
        }

        if (selectedObjectIndex >= 0 && selectedObjectIndex < static_cast<int>(objects.size())) {
            // Выводим варианты действий для выбранного объекта
            vector<Action> objectActions = objects[selectedObjectIndex]->getAvailableActions();
            this_thread::sleep_for(chrono::milliseconds(300));
            Screen::displayText("\n\t~~\"" + objects[selectedObjectIndex]->getName() + "\"~~\n");
            this_thread::sleep_for(chrono::milliseconds(100));

            for (size_t i = 0; i < objectActions.size(); ++i) {
                Screen::displayText(to_string(i + 1) + ". " + objectActions[i].getDescription());
                this_thread::sleep_for(chrono::milliseconds(500));
            }

            cout << "\nВаш выбор: ";

            // Ждем второй ввод от пользователя и обрабатываем
            char userActionInput = Input::getUserInput();

            // Преобразуем char в int и вычитаем '0', чтобы получить индекс действия
            int selectedActionIndex = userActionInput - '0' - 1;

            if (selectedActionIndex >= 0 && selectedActionIndex < static_cast<int>(objectActions.size())) {
                // Выполняем выбранное действие
                Action& selectedAction = objectActions[selectedActionIndex];
                objects[selectedObjectIndex]->performAction(selectedAction);
            }
            else {
                Screen::displayText("Неверный выбор действия.");
            }
        }
        else {
            Screen::displayText("Неверный выбор объекта.");
        }
    }
}

// Метод для добавления интерактивных объектов
void Location::addInteractiveObject(InteractiveObject* object)
{
    objects.push_back(object);
}
