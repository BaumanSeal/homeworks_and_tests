#include <Windows.h>
#include <iostream>
#include <staffcards/staffcards.hpp>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    class StaffCards *staffCards = new class StaffCards;

    bool done = false;
    int typeOfOperation;

    string fullName;                  // 1. ФИО
    struct tm dateOfBirth = {};       // 2. Дата рождения
    int ageNow;                       // 3. Возраст сейчас
    struct tm dateOfCommencemen = {}; // 4. Дата начала работы
    int yearsOfEmployment;            // 5. Сколько лет работает
    string position;                  // 6. Должность
    int workExperience;               // 7. Опыт работы
    float salary;                     // 8. Заработная плата

    int day, month, year;

    int index;

    cout << "Добро пожаловать в мою прекрасную программу!\n";

    do
    {
        cout << "Что вы хотите сделать?\n"
                "0. Выйти из программы\n"
                "1. Сохранить данные\n"
                "2. Загрузить данные\n"
                "3. Отобразить данные\n"
                "4. Удалить данные\n"
                "5. Добавить запись\n"
                "6. Изменить запись\n"
                "7. Отобразить запись\n"
                "8. Удалить запись"
             << endl;

        cin >> typeOfOperation;

        switch (typeOfOperation)
        {
        case 0:
            cout << "Ждем вас снова!" << endl;
            done = true;
            break;
        case 1:
            cout << "Сохраняем данные" << endl;
            staffCards->saveCards();
            cout << "Сохранение успешно" << endl;
            break;
        case 2:
            cout << "Загружаем данные" << endl;
            staffCards->loadCards();
            cout << "Загрузка успешна" << endl;
            break;
        case 3:
            cout << "Список карт:\n" << staffCards << endl;
            break;
        case 5:
            cout << "Введите ФИО:" << endl;
            cin >> fullName;

            cout << "Введите дату рождения:\n"
                    "Введите день:"
                 << endl;
            cin >> day;
            dateOfBirth.tm_mday = day;
            cout << "Введите месяц(числом):" << endl;
            cin >> month;
            dateOfBirth.tm_mon = month - 1;
            cout << "Введите год:" << endl;
            cin >> year;
            dateOfBirth.tm_year = year - 1900;

            cout << "Введите возраст:" << endl;
            cin >> ageNow;

            cout << "Введите дату начала работы:\n"
                    "Введите день:"
                 << endl;
            cin >> day;
            dateOfCommencemen.tm_mday = day;
            cout << "Введите месяц(числом):" << endl;
            cin >> month;
            dateOfCommencemen.tm_mon = month - 1;
            cout << "Введите год:" << endl;
            cin >> year;
            dateOfCommencemen.tm_year = year - 1900;

            cout << "Введите сколько лет работает:" << endl;
            cin >> yearsOfEmployment;

            cout << "Введите должность:" << endl;
            cin >> position;

            cout << "Введите опыт работы:" << endl;
            cin >> workExperience;

            cout << "Введите заработную плату:" << endl;
            cin >> salary;

            staffCards->pushCard(fullName, &dateOfBirth, ageNow, &dateOfCommencemen, yearsOfEmployment, position,
                                 workExperience, salary);
            break;
        case 7:
            cout << "Какую запись вы хотите отобразить?" << endl;
            cin >> index;
            cout << "Отображаю запись под номером " << index << " :\n";
            staffCards->showCard(cout, index);
            cout << endl;
            break;
        case 8:
            cout << "Какую запись вы хотите удалить?(нумерация начинается с нуля)" << endl;
            cin >> index;
            staffCards->eraseCard(index);
            break;
        default:
            cout << "Введено не верное знаение, попроуйте еще раз" << endl;
            break;
        }

    } while (!done);

    return (0);
}
