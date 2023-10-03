#ifndef LAB1_DATETIME_H
#define LAB1_DATETIME_H

#include <iostream>
#include <cstdlib>
#include <ctime>

class DateTime
{
public:
    
    DateTime(int year, int month, int day, int hour, int minute, int second)
    {
        std::tm timeData{};
        timeData.tm_year = year - 1900;
        timeData.tm_mon = month - 1;
        timeData.tm_mday = day;
        timeData.tm_hour = hour - 1;
        timeData.tm_min = minute;
        timeData.tm_sec = second;

        if (std::mktime(&timeData) == -1)
        {
            std::cout << "INVALID DATE AND TIME\n";
        }
        else
        {
            m_time = mktime(&timeData);
        }
    }

    bool isValid(std::tm timeData)
    {
        return (timeData.tm_year >= 0 && timeData.tm_mon < 12 && timeData.tm_mday > 0 && timeData.tm_mday <= getDaysInMonth(timeData.tm_year + 1900, timeData.tm_mon + 1) && timeData.tm_hour >= 0 && timeData.tm_hour < 24 && timeData.tm_min >= 0 && timeData.tm_min < 60 && timeData.tm_sec >= 0 && timeData.tm_sec < 60);
    }

    void increaseBySeconds(int seconds)
    {
        m_time += seconds;
    }

    void increaseByMinutes(int minutes)
    {
        m_time += minutes * 60;
    }

    void increaseByHours(int hours)
    {
        m_time += hours * 3600;
    }

    void increaseByDays(int days)
    {
        m_time += days * 86400;
    }

    void increaseByMonths(int months)
    {
        std::tm timeData = *std::localtime(&m_time);

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

        timeData.tm_mon = month - 1;
        timeData.tm_year = year - 1900;

        if (isValid(timeData))
        {
            m_time = mktime(&timeData);
        }

    }

    void increaseByYears(int years)
    {
        std::tm timeData = *std::localtime(&m_time);
        
        int year = timeData.tm_year + years + 1900;
        if (year < 1900)
        {
            year = 1900;
        }

        timeData.tm_year = year - 1900;
        if (isValid(timeData))
        {
            m_time = mktime(&timeData);
        }
    }

    void increaseBy(int years, int months, int days, int hours, int minutes, int seconds)
    {
        increaseBySeconds(seconds);
        increaseByMinutes(minutes);
        increaseByHours(hours);
        increaseByDays(days);
        increaseByMonths(months);
        increaseByYears(years);
    }

    void decreaseBySeconds(int seconds)
    {
        increaseBySeconds(-seconds);
    }

    void decreaseByMinutes(int minutes)
    {
        increaseByMinutes(-minutes);
    }

    void decreaseByHours(int hours)
    {
        increaseByHours(-hours);
    }

    void decreaseByDays(int days)
    {
        increaseByDays(-days);
    }

    void decreaseByMonths(int months)
    {
        increaseByMonths(-months);
    }

    void decreaseByYears(int years)
    {
        increaseByYears(-years);
    }

    void decreaseBy(int years, int months, int days, int hours, int minutes, int seconds)
    {
        increaseBy(-years, -months, -days, -hours, -minutes, -seconds);
    }

    long long int secondsDifference(DateTime& other)
    {
        return abs(m_time - other.getTime());
    }

    long long int minutesDifference(DateTime& other)
    {
        return abs(secondsDifference(other) / 60);
    }

    long long int hoursDifference(DateTime& other)
    {
        return abs(secondsDifference(other) / 3600);
    }

    long int daysDifference(DateTime& other)
    {
        return abs(secondsDifference(other) / 86400);
    }

    int monthsDifference(DateTime& other)
    {   
        std::tm fromDate = other.getTimeStructure();
        std::tm toDate = getTimeStructure();

        if (other.getTime() > getTime())
        {
            fromDate = getTimeStructure();
            toDate = other.getTimeStructure();
        }
        
        int difference = (toDate.tm_year - fromDate.tm_year) * 12 + (toDate.tm_mon - fromDate.tm_mon);
        
        if (toDate.tm_mday < fromDate.tm_mday)
        {
            difference -= 1;
        }
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

    int yearsDifference(DateTime& other)
    {
        return monthsDifference(other) / 12;
    }


    int getDayOfWeek()
    {
        std::tm time = getTimeStructure();
        return time.tm_wday;
    }

    std::time_t getTime()
    {
        return m_time;
    }

    std::string getTimeFormatted()
    {
        return std::ctime(&m_time);
    }

    std::tm getTimeStructure()
    {
        return *std::localtime(&m_time); 
    }

private:
    std::time_t m_time;
    inline static const int DAYS_IN_MONTHS_NONLEAP[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int getDaysInMonth(int year, int month)
    {   
        if (yearIsLeap(year) && month == 2)
        {
            return 29;
        }

        return DAYS_IN_MONTHS_NONLEAP[month - 1];
    }

    bool yearIsLeap(int year)
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};

#endif