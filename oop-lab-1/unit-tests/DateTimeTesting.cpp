#include "doctest.h"

TEST_CASE("testing setters")
{
    DateTime date;

    SUBCASE("year")
    {
        date.setYear(2023);
        date.setYear(0);
        date.setYear(-4);

        REQUIRE(date.getYear() == 2023);
    }

    SUBCASE("month")
    {
        date.setMonth(2);
        date.setMonth(0);
        date.setMonth(13);

        REQUIRE(date.getMonth() == 2);
    }

    SUBCASE("day, nonleap year")
    {
        date.setYear(2023);
        date.setMonth(2);

        date.setDay(28);
        date.setDay(0);
        date.setDay(29);

        REQUIRE(date.getDay() == 28);
    }

    SUBCASE("day, leap year")
    {
        date.setYear(2024);
        date.setMonth(2);

        date.setDay(29);

        REQUIRE(date.getDay() == 29);
    }

    SUBCASE("hour")
    {
        date.setHour(18);
        date.setHour(-1);
        date.setHour(24);

        REQUIRE(date.getHour() == 18);
    }

    SUBCASE("minute")
    {
        date.setMinute(20);
        date.setMinute(-1);
        date.setMinute(60);

        REQUIRE(date.getMinute() == 20);
    }

    SUBCASE("second")
    {
        date.setSecond(52);
        date.setSecond(-1);
        date.setSecond(60);

        REQUIRE(date.getSecond() == 52);
    }
}

TEST_CASE("testing increase")
{
    DateTime date(2023, 1, 1, 0, 0, 0);

    SUBCASE("by seconds")
    {
        date.increaseBySeconds(61);
        REQUIRE(date.getSecond() == 1);
        REQUIRE(date.getMinute() == 1);
    }

    SUBCASE("by minutes")
    {
        date.increaseByMinutes(61);
        REQUIRE(date.getMinute() == 1);
        REQUIRE(date.getHour() == 1);
    }

    SUBCASE("by hours")
    {
        date.increaseByHours(25);
        REQUIRE(date.getHour() == 1);
        REQUIRE(date.getDay() == 2);
    }

    SUBCASE("by days, nonleap year")
    {
        date.setMonth(2);
        date.increaseByDays(29);
        REQUIRE(date.getDay() == 2);
        REQUIRE(date.getMonth() == 3);
    }

    SUBCASE("by days, leap year")
    {
        date.setYear(2024);
        date.setMonth(2);
        date.increaseByDays(29);
        REQUIRE(date.getDay() == 1);
        REQUIRE(date.getMonth() == 3);
    }

    SUBCASE("by months")
    {
        date.increaseByMonths(12);
        REQUIRE(date.getMonth() == 1);
        REQUIRE(date.getYear() == 2024);
    }
}

// достатньо одного кейсу, бо він задіває всі цікаві випадки
TEST_CASE("testing decrease validation")
{
    DateTime date(2023, 1, 1, 0, 0, 0);

    date.decreaseBySeconds(1);
    REQUIRE(date.getSecond() == 59);
    REQUIRE(date.getMinute() == 59);
    REQUIRE(date.getHour() == 23);
    REQUIRE(date.getDay() == 31);
    REQUIRE(date.getMonth() == 12);
    REQUIRE(date.getYear() == 2022);
}

TEST_CASE("testing difference")
{
    DateTime date(2023, 1, 1, 0, 0, 0);
    DateTime other(2022, 12, 31, 23, 59, 59);

    SUBCASE("years")
    {
        int difference = date.yearsDifference(other);
        REQUIRE(difference == 1);
    }

    /*SUBCASE("months")
    {
        int difference = date.monthDifference(other);
        REQUIRE(difference == )
    }*/
}
