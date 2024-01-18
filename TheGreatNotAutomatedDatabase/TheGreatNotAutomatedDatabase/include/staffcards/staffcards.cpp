#include <staffcards/staffcards.hpp>

// class StaffCard

StaffCard::StaffCard()
{
    dateOfBirth = new struct tm;
    dateOfCommencement = new struct tm;
}

StaffCard::StaffCard(std::string fullName_, struct tm *dateOfBirth_, int ageNow_, struct tm *dateOfCommencement_,
                     int yearsOfEmployment_, std::string position_, int workExperience_, float salary_)
    : fullName(fullName_), ageNow(ageNow_), yearsOfEmployment(yearsOfEmployment_), position(position_),
      workExperience(workExperience_), salary(salary_)
{
    dateOfBirth = new struct tm;
    *dateOfBirth = *dateOfBirth_;

    dateOfCommencement = new struct tm;
    *dateOfCommencement = *dateOfCommencement_;
};

StaffCard::StaffCard(std::string fullName_, int dateOfBirthDay, int dateOfBirthMonth, int dateOfBirthYear, int ageNow_,
                     int dateOfCommencementDay, int dateOfCommencementMonth, int dateOfCommencementYear,
                     int yearsOfEmployment_, std::string position_, int workExperience_, float salary_)
    : fullName(fullName_), ageNow(ageNow_), yearsOfEmployment(yearsOfEmployment_), position(position_),
      workExperience(workExperience_), salary(salary_)
{
    dateOfBirth = new struct tm;
    dateOfBirth->tm_sec = 0;                       // ������� �� ������ ������ - [0,60]
    dateOfBirth->tm_min = 0;                       // ������ �� ������ ���� - [0,59]
    dateOfBirth->tm_hour = 0;                      // ���� �� �������� - [0,23]
    dateOfBirth->tm_mday = dateOfBirthDay;         // ���� ������ - [1,31]
    dateOfBirth->tm_mon = dateOfBirthMonth - 1;    // ������ ����� ������ - [0,11]
    dateOfBirth->tm_year = dateOfBirthYear - 1900; // ���� � 1900
    dateOfBirth->tm_wday = 0;                      // ��� � ����������� - [0,6]
    dateOfBirth->tm_yday = 0;                      // ��� � ������� ������ - [0,365]
    dateOfBirth->tm_isdst = -1;                    // ������� ������� �������
                                // ������������� ��������, ���� ���������� � ������ ������� ����������/����������

    dateOfCommencement = new struct tm;
    dateOfCommencement->tm_sec = 0;                              // ������� �� ������ ������ - [0,60]
    dateOfCommencement->tm_min = 0;                              // ������ �� ������ ���� - [0,59]
    dateOfCommencement->tm_hour = 0;                             // ���� �� �������� - [0,23]
    dateOfCommencement->tm_mday = dateOfCommencementDay;         // ���� ������ - [1,31]
    dateOfCommencement->tm_mon = dateOfCommencementMonth - 1;    // ������ ����� ������ - [0,11]
    dateOfCommencement->tm_year = dateOfCommencementYear - 1900; // ���� � 1900
    dateOfCommencement->tm_wday = 0;                             // ��� � ����������� - [0,6]
    dateOfCommencement->tm_yday = 0;                             // ��� � ������� ������ - [0,365]
    dateOfCommencement->tm_isdst = -1;                           // ������� ������� �������
                                       // ������������� ��������, ���� ���������� � ������ ������� ����������/����������
}

StaffCard::~StaffCard()
{
    delete dateOfBirth;
    delete dateOfCommencement;
}

int StaffCard::setFullName(std::string fullName_)
{
    fullName = fullName_;

    return (0);
}

std::string StaffCard::getFullName()
{
    return (fullName);
}

int StaffCard::setDateOfBirth(struct tm *dateOfBirth_)
{
    *dateOfBirth = *dateOfBirth_;

    return (0);
}

struct tm *StaffCard::getDateOfBirth()
{
    return (dateOfBirth);
}

int StaffCard::setAgeNow(int ageNow_)
{
    ageNow = ageNow_;

    return (0);
}

int StaffCard::getAgeNow()
{
    return (ageNow);
}

int StaffCard::setDateOfCommencement(struct tm *dateOfCommencement_)
{
    *dateOfCommencement = *dateOfCommencement_;

    return (0);
}

struct tm *StaffCard::getDateOfCommencement()
{
    return (dateOfCommencement);
}

int StaffCard::setYearsOfEmployment(int yearsOfEmployment_)
{
    yearsOfEmployment = yearsOfEmployment_;

    return (0);
}

int StaffCard::getYearsOfEmployment()
{
    return (yearsOfEmployment);
}

int StaffCard::setPosition(std::string position_)
{
    position = position_;

    return (0);
}

std::string StaffCard::getPosition()
{
    return (position);
}

int StaffCard::setWorkExperience(int workExperience_)
{
    workExperience = workExperience_;

    return (0);
}

int StaffCard::getWorkExperience()
{
    return (workExperience);
}

int StaffCard::setSalary(float salary_)
{
    salary = salary_;

    return (0);
}

float StaffCard::getSalary()
{
    return (salary);
}

std::ostream &operator<<(std::ostream &stream, class StaffCard *staffCard)
{
    stream << "���: " << staffCard->getFullName() << '\n';
    stream << "���� ��������: "
           << "����: " << staffCard->getDateOfBirth()->tm_mday << " �����: " << staffCard->getDateOfBirth()->tm_mon + 1
           << " ���: " << staffCard->getDateOfBirth()->tm_year + 1900 << '\n';
    stream << "������� ������" << staffCard->getAgeNow();
    stream << "���� ������ ������: "
           << "����: " << staffCard->getDateOfCommencement()->tm_mday
           << " �����: " << staffCard->getDateOfCommencement()->tm_mon + 1
           << " ���: " << staffCard->getDateOfCommencement()->tm_year + 1900 << '\n';
    stream << "��� ��������: " << staffCard->getYearsOfEmployment() << '\n';
    stream << "���������: " << staffCard->getPosition() << '\n';
    stream << "���� ������: " << staffCard->getWorkExperience() << '\n';
    stream << "���������� �����: " << staffCard->getSalary();

    return stream;
}

// class StaffCards

StaffCards::StaffCards(){};

std::vector<class StaffCard *> StaffCards::getCards()
{
    return (staffCard);
}

int StaffCards::saveCards()
{
    int i;
    std::string index;

    std::ofstream saveFile("data/data.json");
    json data;

    data["total"] = staffCard.size();

    for (i = 0; i < data["total"]; i++)
    {
        index = std::to_string(i);
        data[index]["fullName"] = staffCard[i]->getFullName();
        data[index]["dateOfBirth"]["day"] = staffCard[i]->getDateOfBirth()->tm_mday;
        data[index]["dateOfBirth"]["month"] = staffCard[i]->getDateOfBirth()->tm_mon + 1;
        data[index]["dateOfBirth"]["year"] = staffCard[i]->getDateOfBirth()->tm_year + 1900;
        data[index]["ageNow"] = staffCard[i]->getAgeNow();
        data[index]["dateOfCommencement"]["day"] = staffCard[i]->getDateOfCommencement()->tm_mday;
        data[index]["dateOfCommencement"]["month"] = staffCard[i]->getDateOfCommencement()->tm_mon + 1;
        data[index]["dateOfCommencement"]["year"] = staffCard[i]->getDateOfCommencement()->tm_year + 1900;
        data[index]["earsOfEmployment"] = staffCard[i]->getYearsOfEmployment();
        data[index]["position"] = staffCard[i]->getPosition();
        data[index]["workExperience"] = staffCard[i]->getWorkExperience();
        data[index]["salary"] = staffCard[i]->getSalary();
    }
    saveFile << data;

    return (0);
}

int StaffCards::loadCards()
{
    int i;
    std::string index;
    class StaffCard *sc;

    std::ifstream loadFile("data/data.json");
    json data = json::parse(loadFile);

    staffCard.clear();

    for (i = 0; i < data["total"]; i++)
    {
        index = std::to_string(i);

        sc = new class StaffCard((std::string)data[index]["fullName"], (int)data[index]["dateOfBirth"]["day"],
                                 (int)data[index]["dateOfBirth"]["month"], (int)data[index]["dateOfBirth"]["year"],
                                 (int)data[index]["ageNow"], (int)data[index]["dateOfCommencement"]["day"],
                                 (int)data[index]["dateOfCommencement"]["month"],
                                 (int)data[index]["dateOfCommencement"]["year"], (int)data[index]["earsOfEmployment"],
                                 (std::string)data[index]["position"], (int)data[index]["workExperience"],
                                 (float)data[index]["salary"]);
        staffCard.push_back(sc);
    }

    return (0);
}

int StaffCards::deleteCards()
{
    return (0);
};

int StaffCards::pushCard(std::string fullName_, struct tm *dateOfBirth_, int ageNow_, struct tm *dateOfCommencement_,
                         int yearsOfEmployment_, std::string position_, int workExperience_, float salary_)
{
    class StaffCard *sc = new class StaffCard(fullName_, dateOfBirth_, ageNow_, dateOfCommencement_, yearsOfEmployment_,
                                              position_, workExperience_, salary_);
    staffCard.push_back(sc);

    return (0);
}

int StaffCards::setCard(int index, std::string fullName_, std::string dateOfBirth_, int ageNow_,
                        std::string dateOfCommencement_, int yearsOfEmployment_, std::string position_,
                        int workExperience_, float salary_)
{
    return (0);
}

int StaffCards::showCard(std::ostream &stream, int index)
{
    stream << staffCard[index];

    return (0);
}

int StaffCards::eraseCard(int index)
{
    delete staffCard[index];
    staffCard.erase(staffCard.begin() + index);

    return (0);
}

std::ostream &operator<<(std::ostream &stream, class StaffCards *staffCards)
{
    int i;

    std::vector<class StaffCard *> staffCard = staffCards->getCards();

    for (i = 0; i < staffCard.size(); i++)
        stream << i << ". " << staffCard[i]->getFullName() << '\n';

    return (stream);
}
