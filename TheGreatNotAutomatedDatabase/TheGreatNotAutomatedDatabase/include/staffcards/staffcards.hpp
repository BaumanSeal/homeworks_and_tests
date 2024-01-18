#pragma once

#include <ctime>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

using json = nlohmann::json;

class StaffCard
{
    std::string fullName;                // 1. ФИО
    struct tm *dateOfBirth{NULL};        // 2. Дата рождения
    int ageNow{0};                       // 3. Возраст сейчас
    struct tm *dateOfCommencement{NULL}; // 4. Дата начала работы
    int yearsOfEmployment{0};            // 5. Сколько лет работает
    std::string position;                // 6. Должность
    int workExperience{0};               // 7. Опыт работы
    float salary{0};                     // 8. Заработная плата

  public:
    StaffCard();
    StaffCard(std::string fullName_, struct tm *dateOfBirth_, int ageNow_, struct tm *dateOfCommencement_,
              int yearsOfEmployment_, std::string position_, int workExperience_, float salary_);
    StaffCard(std::string fullName_, int dateOfBirthDay, int dateOfBirthMonth, int dateOfBirthYear, int ageNow_,
              int dateOfCommencementDay, int dateOfCommencementMonth, int dateOfCommencementYear,
              int yearsOfEmployment_, std::string position_, int workExperience_, float salary_);
    ~StaffCard();

    int setFullName(std::string fullName_);
    std::string getFullName();

    int setDateOfBirth(struct tm *dateOfBirth_);
    struct tm *getDateOfBirth();

    int setAgeNow(int ageNow_);
    int getAgeNow();

    int setDateOfCommencement(struct tm *dateOfCommencement_);
    struct tm *getDateOfCommencement();

    int setYearsOfEmployment(int yearsOfEmployment_);
    int getYearsOfEmployment();

    int setPosition(std::string position_);
    std::string getPosition();

    int setWorkExperience(int workExperience_);
    int getWorkExperience();

    int setSalary(float salary_);
    float getSalary();
};

std::ostream &operator<<(std::ostream &strm, class StaffCard *staffCard);

class StaffCards
{

    std::vector<class StaffCard *> staffCard;

  public:
    StaffCards();

    std::vector<class StaffCard *> getCards();

    int saveCards();
    int loadCards();
    int deleteCards();

    int pushCard(std::string fullName_, struct tm *dateOfBirth_, int ageNow_, struct tm *dateOfCommencement_,
                 int yearsOfEmployment_, std::string position_, int workExperience_, float salary_);
    int setCard(int index, std::string fullName_, std::string dateOfBirth_, int ageNow_,
                std::string dateOfCommencement_, int yearsOfEmployment_, std::string position_, int workExperience_,
                float salary_);
    int showCard(std::ostream &stream, int index);
    int eraseCard(int index);
};

std::ostream &operator<<(std::ostream &strm, class StaffCards *staffCards);
