#include <iostream>
#include <map>
class DateTime
{
public:
    bool yearIsLeap()
    {
        return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
    }

// АРИФМЕТИКА ЧАСУ
    void increaseByYears(int years)
    {
        if (years > 0)
        {
            m_year += years;
        }
        else
        {
            std::cout << "INVALID YEARS INPUT\n";
        }
    }

    void increasyByMonths(int months)
    {
        if (months > 0)
        {
            m_month += months;
            validateMonth();
        }
        else
        {
            std::cout << "INVALID MONTHS INPUT\n";
        }
    }

    void increaseByDays(int days)
    {
        if (days > 0)
        {
            m_day += days;
            validateDay();
        }
        else
        {
            std::cout << "INVALID DAYS INPUT\n"
        }
    }

    void increaseByHours(int hours)
    {
        if (hours > 0)
        {
            m_hour += hours;
            validateHour();
        }
        else
        {
            std::cout <<"INVALID HOURS INPUT\n";
        }
    }

    void increaseByMinutes(int minutes)
    {
        if (minutes > 0)
        {
            m_minute += minutes;
            validateMinute();
        }
        else
        {
            std::cout << "INVALID MINUTES INPUT\n";
        }
    }

    void increaseBySeconds(int seconds)
    {
        if (second > 0)
        {
            m_second += seconds;
            validateSecond();
        }
        else
        {
            std::cout << "INVALID SECONDS INPUT\n";
        }
    }

    // СЕТТЕРИ

    void setYear(int year)
    {
        if (year > 0)
        {
            m_year = year;
        }
        else
        {
            std::cout << "INVALID YEAR INPUT\n";
        }
    }

    void setMonth(int month)
    {
        if (month >= 1 && month <= 13)
        {
            m_month = month;
        }
        else
        {
            std::cout << "INVALID MONTH INPUT\n";
        }
    }

    void setDay(int day)
    {
        if (day > 0 && day <= DAYS_IN_MONTHS[m_month])
        {
            m_day = day;
        }
        else
        {
            std::cout << "INVALID DAY INPUT\n";
        }
    }

    void setHour (int hour)
    {
        if (hour >= 0 && hour < 24)
        {
            m_hour = hour;
        }
        else
        {
            std::cout << "INVALID HOUR INPUT\n";
        }
    }

    void setMinute(int minute)
    {
        if (minute >= 0 && minute < 60)
        {
            m_minute = minute;
        }
        else
        {
            std::cout << "INVALID MINUTE INPUT\n";
        }
    }

    void setSecond(int second)
    {
        if (second >= 0 && second < 60)
        {
            m_second = second;
        }
        else
        {
            std::cout << "INVALID SECOND INPUT\n";
        }
    }

    // ГЕТТЕРИ
    int getYear()
    {
        return m_year;
    }

    int getMonth()
    {
        return m_month;
    }

    int getDay()
    {
        return m_day;
    }

    int getHour()
    {
        return m_hour;
    }

    int getMinute()
    {
        return m_minute;
    }

    int getSecond()
    {
        return m_second;
    }

private:
    const std::map<int, int> DAYS_IN_MONTHS = {{1, 31}, {2, 28}, {3, 31},{4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};

    int m_year{};
    int m_month{};
    int m_day{};
    int m_hour{};
    int m_minute{};
    int m_second{};

    void validateSecond()
    {
        if (m_second >= 60)
        {
            int minutes = m_second / 60;
            m_minute += minutes;

            m_second %= 60;
        }
        else if (m_second < 0)
        {
            m_second = 0;
        }
        
    }
    void validateMinute()
    {
        if (m_minute >= 60)
        {
            int hours = m_minute / 60;
            m_hour += hours;

            m_minute %= 60;
        }
    }
    void validateHour()
    {
        if (m_hour >= 24)
        {
            int days = m_hour / 24;
            m_day += days;

            m_hour %= 24;
        }
    }

    void validateDay()
    {
        while (m_day > DAYS_IN_MONTHS[m_month])
        {
            m_day -= DAYS_IN_MONTHS[m_month];
            ++m_month;
            validateMonth();
        }
    }

    void validateMonth()
    {
        if (m_month > 12)
        {
            int years = m_month / 12;
            m_year += years;

            m_month %= 12;
        }
    }

}