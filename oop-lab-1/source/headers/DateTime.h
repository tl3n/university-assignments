#ifndef LAB1_DATETIME_H
#define LAB1_DATETIME_H

#include <iostream>
#include <cstdlib>
#include <ctime>

class DateTime
{
public:
    // Стандартний конструктор, який ініціалізує m_time поточними датою та часом системи
    DateTime()
    {
        time(&m_time);
    }

    // Конструктор, який ініціалізує m_time заданими юзером датою та часом
    DateTime(int year, int month, int day, int hour, int minute, int second)
    {
        std::tm timeData{};
        timeData.tm_year = year - 1900;
        timeData.tm_mon = month - 1;
        timeData.tm_mday = day;
        timeData.tm_hour = hour - 1;
        timeData.tm_min = minute;
        timeData.tm_sec = second;

        // Перевіряємо введену дату та час на валідність. Якщо все добре - заносимо дані до m_time
        if (std::mktime(&timeData) == -1)
        {
            std::cout << "INVALID DATE AND TIME\n";
        }
        else
        {
            m_time = mktime(&timeData);
        }
    }

    // Перевірка дати та часу на валідність за допомогою обмежень структури std::tm
    bool isValid(std::tm timeData)
    {
        return (timeData.tm_year >= 0 && timeData.tm_mon < 12 && timeData.tm_mday > 0 && timeData.tm_mday <= getDaysInMonth(timeData.tm_year + 1900, timeData.tm_mon + 1) && timeData.tm_hour >= 0 && timeData.tm_hour < 24 && timeData.tm_min >= 0 && timeData.tm_min < 60 && timeData.tm_sec >= 0 && timeData.tm_sec < 60);
    }

    // Додавання секунд до загального часу m_time
    void increaseBySeconds(int seconds)
    {
        m_time += seconds;
    }

    // Додавання хвилин до загального часу m_time
    void increaseByMinutes(int minutes)
    {
        m_time += minutes * 60; // 60 - кількість секунд у хвилині
    }

    // Додавання годин до загального часу m_time
    void increaseByHours(int hours)
    {
        m_time += hours * 3600; // 3600 - кількість секунд у годині
    }

    // Додавання днів до загального часу m_time
    void increaseByDays(int days)
    {
        m_time += days * 86400; // 86400 - кількість секунд у добі
    }

    // Додавання місяців до загального часу m_time 
    void increaseByMonths(int months)
    {   
        // Через різну кількість днів у кожному місяці важко виконати додавання просто до m_time
        // Тому конвертуємо загальний час m_time до структури std::tm
        std::tm timeData = *std::localtime(&m_time); 

        // Додаємо місяці до структури, валідуємо місяць та рік
        int month = timeData.tm_mon + 1 + months;
        int year = timeData.tm_year + 1900;

        while (month > 12)
        {
            month -= 12;
            ++year;
        }

        while (month < 1)
        {
            month += 12;
            --year;
        }

        // Форматуємо місяць та рік. Якщо наша структура валідна - конвертуємо її в загальний час m_time
        timeData.tm_mon = month - 1;
        timeData.tm_year = year - 1900;

        if (isValid(timeData))
        {
            m_time = mktime(&timeData);
        }

    }

    // Додавання років до загального часу m_time
    void increaseByYears(int years)
    {   
        // Через високосні роки важко додати кількість років напряму до m_time
        // Тому конвертуємо загальний час m_time до структури std::tm
        std::tm timeData = *std::localtime(&m_time);
        
        // Додаємо роки, валідуємо
        int year = timeData.tm_year + years + 1900;
        if (year < 1900)
        {
            year = 1900;
        }

        // Форматуємо роки, якщо наша структура валідна - конвертуємо її до загального часу m_time
        timeData.tm_year = year - 1900;
        if (isValid(timeData))
        {
            m_time = mktime(&timeData);
        }
    }

    // Додавання заданих юзером одиниць
    void increaseBy(int years, int months, int days, int hours, int minutes, int seconds)
    {
        increaseBySeconds(seconds);
        increaseByMinutes(minutes);
        increaseByHours(hours);
        increaseByDays(days);
        increaseByMonths(months);
        increaseByYears(years);
    }

    // Віднімання секунд від загального часу m_time.
    void decreaseBySeconds(int seconds)
    {
        increaseBySeconds(-seconds); // Використовуємо відповідний метод додавання з негативним аргументом
    }

    // Віднімання хвилин від загального часу m_time
    void decreaseByMinutes(int minutes)
    {
        increaseByMinutes(-minutes); // Використовуємо відповідний метод додавання з негативним аргументом
    }

    // Віднімання годин від загального часу m_time
    void decreaseByHours(int hours) 
    {
        increaseByHours(-hours); // Використовуємо відповідний метод додавання з негативним аргументом
    }

    // Віднімання днів від загального часу m_time
    void decreaseByDays(int days)
    {
        increaseByDays(-days); // Використовуємо відповідний метод додавання з негативним аргументом
    }

    // Віднімання місяців від загального часу m_time
    void decreaseByMonths(int months)
    {
        increaseByMonths(-months); // Використовуємо відповідний метод додавання з негативним аргументом
    }

    // Віднімання років від загального часу m_time
    void decreaseByYears(int years)
    {
        increaseByYears(-years); // Використовуємо відповідний метод додавання з негативним аргументом
    }

    // Віднімання заданих юзером одиниць від загального часу m_time
    void decreaseBy(int years, int months, int days, int hours, int minutes, int seconds)
    {
        increaseBy(-years, -months, -days, -hours, -minutes, -seconds); // Використовуємо відповідний метод додавання з негативними аргументами
    }

    // Різниця в секундах між двома одиницями часу
    long long int secondsDifference(DateTime& other)
    {
        return abs(m_time - other.getTime());
    }

    // Різниця в хвилинах між двома одиницями часу
    long long int minutesDifference(DateTime& other)
    {
        return secondsDifference(other) / 60; // 60 - кількість секунд у хвилині
    }

    // Різниця в годинах між двома одиницями часу
    long long int hoursDifference(DateTime& other)
    {
        return secondsDifference(other) / 3600; // 3600 - кількість секунд у годині
    }

    // Різниця в добах між двома одиницями часу
    long int daysDifference(DateTime& other)
    {
        return secondsDifference(other) / 86400;// 86400 - кількість секунд у добі
    }

    // Різниця в місяцях між двома одиницями часу
    int monthsDifference(DateTime& other)
    {   
        // Через різну кількість днів у кожному місяці, важко порахувати різницю напряму
        // Тому використовуємо структуру std::tm

        // Для вірності обчислень знаходимо менший час і позначаємо, що лічба починається ВІД нього
        std::tm fromDate = other.getTimeStructure();
        std::tm toDate = getTimeStructure();

        if (other.getTime() > getTime())
        {
            fromDate = getTimeStructure();
            toDate = other.getTimeStructure();
        }
        
        // Ініціалізуємо difference різницею в роках між датами (переведеною в місяці) + різницею в місяцях
        int difference = (toDate.tm_year - fromDate.tm_year) * 12 + (toDate.tm_mon - fromDate.tm_mon);
        
        // Якщо день дати ДО якої ми прямуємо, менший за день дати ВІД якої ми прямуємо, то останній місяць пройдений не повністю
        // Тому віднімаємо від difference 1 місяць
        if (toDate.tm_mday < fromDate.tm_mday)
        {
            difference -= 1;
        }
        // Якщо дні рівні, порівнюємо час ДО днів
        else if (toDate.tm_mday == fromDate.tm_mday)
        {
            int toTime = toDate.tm_hour * 3600 + toDate.tm_min * 60 + toDate.tm_sec;
            int fromTime = fromDate.tm_hour * 3600 + fromDate.tm_min * 60 + fromDate.tm_sec;

            if (toTime < fromTime)
            {
                difference -= 1;
            }
        }

        return difference;
    }

    // Різниця в годинах між двома одиницями часу
    int yearsDifference(DateTime& other)
    {
        return monthsDifference(other) / 12; // 12 - кількість місяців у році
    }

    // Дізнатися день тижня
    int getDayOfWeek()
    {
        // Для облегшення обичслень, використовуємо структуру std::tm
        std::tm time = getTimeStructure();
        return time.tm_wday;
    }

    // Геттер загального часу m_time
    std::time_t getTime()
    {
        return m_time;
    }

    // Геттер форматованого загального часу m_time
    std::string getTimeFormatted()
    {
        return std::ctime(&m_time);
    }

    // Геттер загального часу m_time у вигляді структури std::tm
    std::tm getTimeStructure()
    {
        return *std::localtime(&m_time); 
    }

private:
    // Загальний час
    std::time_t m_time;

    // Кількість днів у невисокосному році
    inline static const int DAYS_IN_MONTHS_NONLEAP[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Отримання кількості днів у заданому місяці
    int getDaysInMonth(int year, int month)
    {   
        // Повернути 29, якщо рік високосний і заданий місяць - лютий
        if (yearIsLeap(year) && month == 2)
        {
            return 29;
        }

        return DAYS_IN_MONTHS_NONLEAP[month - 1];
    }

    // Перевірка року на високосність
    bool yearIsLeap(int year)
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};

#endif