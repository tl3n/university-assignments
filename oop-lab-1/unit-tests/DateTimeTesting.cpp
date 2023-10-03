TEST_CASE("testing increase and decrease")
{
    DateTime dt(2023, 10, 3, 12, 30, 0);

    dt.increaseBySeconds(10);
    CHECK(dt.getTimeFormatted() == "Tue Oct 03 12:30:10 2023\n");
        
    dt.increaseByMinutes(5);
    CHECK(dt.getTimeFormatted() == "Tue Oct 03 12:35:10 2023\n");
        
    dt.increaseByHours(2);
    CHECK(dt.getTimeFormatted() == "Tue Oct 03 14:35:10 2023\n");
        
    dt.increaseByDays(7);
    CHECK(dt.getTimeFormatted() == "Tue Oct 10 14:35:10 2023\n");
        
    dt.increaseByMonths(2);
    CHECK(dt.getTimeFormatted() == "Sun Dec 10 13:35:10 2023\n");
        
    dt.increaseByYears(1);
    CHECK(dt.getTimeFormatted() == "Tue Dec 10 13:35:10 2024\n");
    
    dt.decreaseBySeconds(20);
    CHECK(dt.getTimeFormatted() == "Tue Dec 10 13:34:50 2024\n");
        
    dt.decreaseByMinutes(15);
    CHECK(dt.getTimeFormatted() == "Tue Dec 10 13:19:50 2024\n");
        
    dt.decreaseByHours(1);
    CHECK(dt.getTimeFormatted() == "Tue Dec 10 12:19:50 2024\n");
        
    dt.decreaseByDays(5);
    CHECK(dt.getTimeFormatted() == "Thu Dec 05 12:19:50 2024\n");
        
    dt.decreaseByMonths(2);
    CHECK(dt.getTimeFormatted() == "Sat Oct 05 13:19:50 2024\n");
        
    dt.decreaseByYears(2);
    CHECK(dt.getTimeFormatted() == "Wed Oct 05 13:19:50 2022\n");
}

TEST_CASE("testing monthDifference()")
{
    DateTime dt1(2023, 10, 3, 12, 30, 0);
    DateTime dt2(2022, 8, 15, 10, 0, 0);
    DateTime dt3(2023, 11, 1, 14, 0, 0);
    
    CHECK(dt1.monthsDifference(dt2) == 13); 
    CHECK(dt2.monthsDifference(dt1) == 13); 
    CHECK(dt1.monthsDifference(dt3) == 0);   
    CHECK(dt3.monthsDifference(dt1) == 0);  
    
    DateTime dt4(2023, 10, 15, 12, 0, 0);
    DateTime dt5(2023, 10, 15, 15, 0, 0);
    CHECK(dt4.monthsDifference(dt5) == 0);   
    CHECK(dt5.monthsDifference(dt4) == 0);   
    
    DateTime dt6(2023, 9, 15, 12, 0, 0);
    DateTime dt7(2023, 11, 15, 15, 0, 0);
    CHECK(dt6.monthsDifference(dt7) == 2);   
    CHECK(dt7.monthsDifference(dt6) == 2);  
    
    DateTime dt8(2022, 10, 15, 12, 0, 0);
    DateTime dt9(2024, 10, 15, 15, 0, 0);
    CHECK(dt8.monthsDifference(dt9) == 24);  
    CHECK(dt9.monthsDifference(dt8) == 24); 
}

