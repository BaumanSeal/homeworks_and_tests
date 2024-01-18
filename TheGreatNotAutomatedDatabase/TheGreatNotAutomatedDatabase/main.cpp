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

    string fullName;                  // 1. ���
    struct tm dateOfBirth = {};       // 2. ���� ��������
    int ageNow;                       // 3. ������� ������
    struct tm dateOfCommencemen = {}; // 4. ���� ������ ������
    int yearsOfEmployment;            // 5. ������� ��� ��������
    string position;                  // 6. ���������
    int workExperience;               // 7. ���� ������
    float salary;                     // 8. ���������� �����

    int day, month, year;

    int index;

    cout << "����� ���������� � ��� ���������� ���������!\n";

    do
    {
        cout << "��� �� ������ �������?\n"
                "0. ����� �� ���������\n"
                "1. ��������� ������\n"
                "2. ��������� ������\n"
                "3. ���������� ������\n"
                "4. ������� ������\n"
                "5. �������� ������\n"
                "6. �������� ������\n"
                "7. ���������� ������\n"
                "8. ������� ������"
             << endl;

        cin >> typeOfOperation;

        switch (typeOfOperation)
        {
        case 0:
            cout << "���� ��� �����!" << endl;
            done = true;
            break;
        case 1:
            cout << "��������� ������" << endl;
            staffCards->saveCards();
            cout << "���������� �������" << endl;
            break;
        case 2:
            cout << "��������� ������" << endl;
            staffCards->loadCards();
            cout << "�������� �������" << endl;
            break;
        case 3:
            cout << "������ ����:\n" << staffCards << endl;
            break;
        case 5:
            cout << "������� ���:" << endl;
            cin >> fullName;

            cout << "������� ���� ��������:\n"
                    "������� ����:"
                 << endl;
            cin >> day;
            dateOfBirth.tm_mday = day;
            cout << "������� �����(������):" << endl;
            cin >> month;
            dateOfBirth.tm_mon = month - 1;
            cout << "������� ���:" << endl;
            cin >> year;
            dateOfBirth.tm_year = year - 1900;

            cout << "������� �������:" << endl;
            cin >> ageNow;

            cout << "������� ���� ������ ������:\n"
                    "������� ����:"
                 << endl;
            cin >> day;
            dateOfCommencemen.tm_mday = day;
            cout << "������� �����(������):" << endl;
            cin >> month;
            dateOfCommencemen.tm_mon = month - 1;
            cout << "������� ���:" << endl;
            cin >> year;
            dateOfCommencemen.tm_year = year - 1900;

            cout << "������� ������� ��� ��������:" << endl;
            cin >> yearsOfEmployment;

            cout << "������� ���������:" << endl;
            cin >> position;

            cout << "������� ���� ������:" << endl;
            cin >> workExperience;

            cout << "������� ���������� �����:" << endl;
            cin >> salary;

            staffCards->pushCard(fullName, &dateOfBirth, ageNow, &dateOfCommencemen, yearsOfEmployment, position,
                                 workExperience, salary);
            break;
        case 7:
            cout << "����� ������ �� ������ ����������?" << endl;
            cin >> index;
            cout << "��������� ������ ��� ������� " << index << " :\n";
            staffCards->showCard(cout, index);
            cout << endl;
            break;
        case 8:
            cout << "����� ������ �� ������ �������?(��������� ���������� � ����)" << endl;
            cin >> index;
            staffCards->eraseCard(index);
            break;
        default:
            cout << "������� �� ������ �������, ��������� ��� ���" << endl;
            break;
        }

    } while (!done);

    return (0);
}
