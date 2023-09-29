#include <iostream>
#include <map>
class DateTime
{
public:
    DateTime() : m_year{1}, m_month{1}, m_day{1}, m_hour{0}, m_minute{0}, m_second{0} {}

    DateTime(int year, int month, int day, int hour, int minute, int second)
    {
        setYear(year);
        setMonth(month);
        setDay(day);
        setHour(hour);
        setMinute(minute);
        setSecond(secon);
    }

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

    void increaseByMonths(int months)
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

    void increaseBy(int years, int months, int days, int hours, int minutes, int seconds)
    {
        increaseByYears(years);
        increaseByMonths(months);
        increaseByDays(days);
        increaseByHours(hours);
        increaseByMinutes(minutes);
        increaseBySeconds(seconds);
    }

    void decreaseByYears(int years)
    {
        if (years > 0)
        {
            m_year -= years;
        }
        else
        {
            std::cout << "INVALID YEARS INPUT\n";
        }
    }

    void decreaseByMonths(int months)
    {
        if (months > 0)
        {
            m_month -= months;
            validateMonth();
        }
        else
        {
            std::cout << "INVALID MONTHS INPUT\n";
        }
    }

    void decreaseByDays(int days)
    {
        if (days > 0)
        {
            m_day -= days;
            validateDay();
        }
        else
        {
            std::cout << "INVALID DAYS INPUT\n"
        }
    }

    void decreaseByHours(int hours)
    {
        if (hours > 0)
        {
            m_hour -= hours;
            validateHour();
        }
        else
        {
            std::cout <<"INVALID HOURS INPUT\n";
        }
    }

    void decreaseByMinutes(int minutes)
    {
        if (minutes > 0)
        {
            m_minute -= minutes;
            validateMinute();
        }
        else
        {
            std::cout << "INVALID MINUTES INPUT\n";
        }
    }

    void decreaseBySeconds(int seconds)
    {
        if (second > 0)
        {
            m_second -= seconds;
            validateSecond();
        }
        else
        {
            std::cout << "INVALID SECONDS INPUT\n";
        }
    }

    void decreaseBy(int years, int months, int days, int hours, int minutes, int seconds)
    {
        decreaseByYears(years);
        decreaseByMonths(months);
        decreaseByDays(days);
        decreaseByHours(hours);
        decreaseByMinutes(minutes);
        decreaseBySeconds(seconds);
    }

    DateTime& operator=(const DateTime& other) const
    {
        if (this != other)
        {
            this->m_year = other.getYear();
            this->m_month = other.getMonth();
            this->m_day = other.getDay();
            this->m_hour = other.getHour();
            this->m_minute = other.getMinute();
            this->m_second = other.getSecond();
        }
        return *this
    }

    DateTime& operator+(const DateTime& other) const
    {
        increaseBy(other.getYear(), other.getMonth(), other.getDay(), other.getHour(), other.getMinute(), other.getSecond());
        return *this;
    }

    DateTime& operator-(const DateTime& other) const
    {
        decreaseBy(other.getYear(), other.getMonth(), other.getDay(), other.getHour(), other.getMinute(), other.getSecond());
        return *this;
    }

    // ЗНАХОДЖЕННЯ РІЗНИЦІ В ЧАСІ

    int yearsDifference(DateTime& other)
    {
        return m_year - other.getYear();
    }

    int monthsDifference(DateTime& other)
    {
        return m_month - other.getMonth();
    }
    
    int daysDifference(DateTime& other)
    {
        return m_day - other.getDay();
    }
    
    int hoursDifference(DateTime& other)
    {
        return m_hour - other.getHour();
    }

    int minutesDifference(DateTime& other)
    {
        return m_minute - other.getMinute();
    }

    int secondsDifference(DateTime& other)
    {
        return m_second - other.getSecond();
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
    const std::map<int, int> DAYS_IN_MONTHS_NONLEAP = {{1, 31}, {2, 28}, {3, 31},{4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};
    const std::map<int, int> DAYS_IN_MONTHS_LEAP = {{1, 31}, {2, 29}, {3, 31},{4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};

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
        else if (m_minute < 0)
        {
            m_minute = 0;
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
        else if (m_hour < 0)
        {
            m_hour = 0;
        }
    }

    void validateDay()
    {
        if (yearIsLeap())
        {
            std::map<int, int> daysInMonths = DAYS_IN_MONTHS_LEAP;
        }
        else
        {
            std::map<int, int> daysInMonths = DAYS_IN_MONTHS_NONLEAP;
        }

        while (m_day > daysInMonths[m_month])
        {
            m_day -= daysInMonths[m_month];
            ++m_month;
            validateMonth();
        }

        if (m_day < 1)
        {
            m_day = 1;
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
        else if (m_month < 1)
        {
            m_month = 1;
        }
    }

    void validateYear()
    {
        if (m_year < 1)
        {
            m_year = 1;
        }
    }
}