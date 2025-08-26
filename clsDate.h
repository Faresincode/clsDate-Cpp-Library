#pragma once
#pragma warning( disable : 4996 )
#include<iostream>
#include<string>
#include<ctime>
#include<vector>

using namespace std;


class clsDate 
{

private:

	short _Day;
	short _Month;
	short _Year;

public:

	//====================== clsDate constructors =================================

	clsDate()
	{
		clsDate::CurrentDate();

	}
	clsDate(string FullDate)
	{
		clsDate::stringToDate(FullDate);
	}
	clsDate(short Day, short Month, short Year)
	{
		this->_Day = Day;
		this->_Month = Month;
		this->_Year = Year;
	}
	clsDate(short NumberOfDays, short Year)
	{
		clsDate::DateFromDayOrderInYear(NumberOfDays, Year);
	}
	void Print() 
	{

		cout << DateToString(*this) << endl;

	}

	//====================== property functions=================================
	void setDay(short Day)
	{
		this->_Day = Day;
	}
	void setMonth(short Month)
	{
		this->_Month = Month;
	}
	void setYear(short Year)
	{
		this->_Year = Year;
	}
	short getDay()
	{
		return this->_Day;
	}
	short getMonth()
	{
		return this->_Month;
	}
	short getYear()
	{
		return this->_Year;
	}

	__declspec(property(get = getDay, put = setDay))short Day;
	__declspec(property(get = getMonth, put = setMonth))short Month;
	__declspec(property(get = getYear, put = setYear))short Year;

	//====================== boolian date functions=================================
	static bool IsLeapYear(short Year)
	{
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}
	bool IsLeapYear()
	{
		return clsDate::IsLeapYear(this->_Year);
	}
	
	static bool IsValidDate(short Day, short Month, short Year)
	{

		if (Month < 1 || Month > 12)
			return false;

		if (Day < 1 || Day > NumberOfDaysInAMonth(Month, Year))
			return false;

		// If valid, store into the private Date struct
		return true;
	}
	
	static bool IsValidDate(clsDate Date)
	{

		if (Date._Day < 1 || Date._Day>31)
			return false;
		if (Date._Month < 1 || Date._Month>12)
			return false;
		if (Date._Day == 2)
		{
			if (clsDate::IsLeapYear(Date._Year))
			{
				if (Date._Day > 29)
					return false;
			}
			else
			{
				if (Date._Day > 28)
					return false;
			}
		}
		short DaysInMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);
		if (Date._Day > DaysInMonth)
			return false;
		return true;
	}
	bool IsValidDate()
	{
		return clsDate::IsValidDate(*this);
	}
	
	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year == Date2._Year) ? ((Date1._Month == Date2._Month) ? ((Date1._Day == Date2._Day) ? true : false) : false) : false;
	}
	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year < Date2._Year) ? true : ((Date1._Year == Date2._Year) ? (Date1._Month < Date2._Month ? true : (Date1._Month == Date2._Month ? Date1._Day < Date2._Day : false)) : false);
	}
	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
	}
	
	static bool IsLastDayInMonth(clsDate Date)
	{
		return (Date._Day == NumberOfDaysInAMonth(Date._Month, Date._Year));
	}
	bool IsLastDayInMonth()
	{
		return clsDate::IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}
	bool IsLastMonthInYear()
	{
		return clsDate::IsLastMonthInYear(this->_Year);
	}
	
	static bool IsFirstMonthInYear(short Month)
	{
		return (Month == 1);
	}
	bool IsFirstMonthInYear()
	{
		return clsDate::IsFirstMonthInYear(this->_Month) ;
	}

	static bool IsFirstDayInMonth(clsDate Date)
	{
		return (Date._Day == 1);
	}
	bool IsFirstDayInMonth()
	{
		return clsDate::IsFirstDayInMonth(*this);
	}

	static bool IsEndOfWeek(clsDate Date)
	{
		return DayOfWeekOrder(Date) == 6;
	}
	bool IsEndOfWeek()
	{
		return clsDate::IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(clsDate Date)
	{
		//Weekends are Fri and Sat
		short DayIndex = DayOfWeekOrder(Date);
		return (DayIndex == 5 || DayIndex == 6);
	}
	bool IsWeekEnd()
	{
		return clsDate::IsWeekEnd(*this);
	}

	static bool IsBusinessDay(clsDate Date)
	{
		//Weekends are Sun,Mon,Tue,Wed and Thur


		//short DayIndex = DayOfWeekOrder(Date._Day, Date._Month, Date._Year);
		//return  (DayIndex >= 5 && DayIndex <= 4);


	   //shorter method is to invert the IsWeekEnd: this will save updating code.
		return !IsWeekEnd(Date);

	}
	bool IsBusinessDay()
	{
		return clsDate::IsBusinessDay(*this);
	}
	//==============================================================================
	static short NumberOfDaysInAMonth(short Month, short Year)
	{
		if (Month < 1 || Month>12)
			return 0;
		int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) :days[Month - 1];
	}
	short NumberOfDaysInAMonth()
	{
		return this->_Month=clsDate::NumberOfDaysInAMonth(this->_Month, this->_Year);
	}

	static short DaysInYear(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}
	short DaysInYear()
	{
		return clsDate::DaysInYear(this->_Year);
	}

	static short HoursInYear(short Year)
	{
		return DaysInYear(Year) * 24;
	}
	short HoursInYear()
	{
		return clsDate::HoursInYear(this->_Year);
	}

	static int MinutesInYear(short Year)
	{
		return HoursInYear(Year) * 60;
	}
	int MinutesInYear()
	{
		return clsDate::MinutesInYear(this->_Year);
	}

	static int SecondsInYear(short Year)
	{
		return MinutesInYear(Year) * 60;
	}
	int SecondsInYear()
	{
		return SecondsInYear(this->_Year);
	}

	static short DaysFromBeginningOfYear(short Day, short Month, short Year)
	{
		short TotalDays = 0;
		for (int i = 1; i <= Month - 1; i++)
		{
			TotalDays += NumberOfDaysInAMonth(i, Year);
		}
		return 	TotalDays += Day;
;
	}

	static short DaysUntilTheEndOfWeek(clsDate Date)
	{
		return 6 - DayOfWeekOrder(Date);
	}
	short DaysUntilTheEndOfWeek()
	{
		return clsDate::DaysUntilTheEndOfWeek(*this);
	}

	static short DaysUntilTheEndOfMonth(clsDate Date1)
	{
		clsDate EndOfMontDate;
		EndOfMontDate._Day = NumberOfDaysInAMonth(Date1._Month, Date1._Year);
		EndOfMontDate._Month = Date1._Month;
		EndOfMontDate._Year = Date1._Year;
		return DifferenceInDays(Date1, EndOfMontDate, true);
	}
	short DaysUntilTheEndOfMonth()
	{
		return clsDate::DaysUntilTheEndOfMonth(*this);
	}
	
	static short DaysUntilTheEndOfYear(clsDate Date1)
	{
		clsDate EndOfYearDate;
		EndOfYearDate._Day = 31;
		EndOfYearDate._Month = 12;
		EndOfYearDate._Year = Date1._Year;
		return DifferenceInDays(Date1, EndOfYearDate, true);
	}
	short DaysUntilTheEndOfYear()
	{
		return clsDate::DaysUntilTheEndOfYear(*this);
	}
	
	static short DayOfWeekOrder(short Day, short Month, short Year)
	{
		short a, y, m;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;
		// Gregorian:
		//0:sun, 1:Mon, 2:Tue...etc
		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	static short DayOfWeekOrder(clsDate Date)
	{
		return DayOfWeekOrder(Date._Day, Date._Month, Date._Year);
	}
	short DayOfWeekOrder()
	{
		return clsDate::DayOfWeekOrder(*this);
	}	

	static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
	{

		short WeekEndCounter = 0;

		//in case the data  is weekend keep adding one day util you reach business day
		//we get rid of all weekends before the first business day
		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		//here we increase the vacation dates to add all weekends to it.

		for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
		{

			if (IsWeekEnd(DateFrom))
				WeekEndCounter++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		//in case the return date is week end keep adding one day util you reach business day
		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return DateFrom;
	}
	void CalculateVacationReturnDate(short VacationDays)
	{
		*this = clsDate::CalculateVacationReturnDate(*this, VacationDays);
	}

	static clsDate DateFromDayOrderInYear(short DateOrderInYear, short Year)
	{

		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;
		clsDate Date;
		Date._Year = Year;
		Date._Month = 1;
		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date._Month, Year);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date._Month++;
			}
			else
			{
				Date._Day = RemainingDays;
				break;
			}
		}
		return Date;
	}
	static int DifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		int Days = 0;
		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1=IncreaseDateByOneDay(Date1);
		}
		return IncludeEndDay ? ++Days : Days;
	}
	//========================================================================

	void CurrentDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		this->_Year = now->tm_year + 1900;
		this->_Month = now->tm_mon + 1;
		this->_Day = now->tm_mday;
	}
	short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		short DaysCount = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				DaysCount++;
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}
		return DaysCount;
	}
	enum enDateCompare { Before = -1, Equal = 0, After = 1 };
	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;
		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;

		return enDateCompare::After;
	}

	//====================== increase date functions =================================
	static clsDate IncreaseDateByOneDay(clsDate Date)
	{
	
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date._Month))
			{
				Date._Month = 1;
				Date._Day = 1;
				Date._Year++;
			}
			else
			{
				Date._Day = 1;
				Date._Month++;
			}
		}
		else
		{
			Date._Day++;
		}

		return Date;
	
	}
	void IncreaseDateByOneDay()
	{
		*this=clsDate::IncreaseDateByOneDay(*this);
	}

	static clsDate IncreaseDateByOneWeek(clsDate Date)
	{
		for (int i = 1; i <= 7; i++)
		{
			Date=IncreaseDateByOneDay(Date);
		}
		return Date;
	}
	void IncreaseDateByOneWeek()
	{
		*this = clsDate::IncreaseDateByOneWeek(*this);
	}

	static clsDate IncreaseDateByXWeeks(short Weeks, clsDate Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date=IncreaseDateByOneWeek(Date);
		}
		return Date;
	}
	void IncreaseDateByXWeeks(short Weeks)
	{
		*this = clsDate::IncreaseDateByXWeeks(Weeks,*this);
	}

	static clsDate IncreaseDateByOneMonth(clsDate Date)
	{
		if (Date._Month == 12)
		{
			Date._Month = 1;
			Date._Year++;
		}
		else
		{
			Date._Month++;
		}
		//last check day in date should not exceed max days in the current month
			// example if date is 31/1/2022 increasing one month should not be 31 / 2 / 2022, it should
			// be 28/2/2022
		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);
		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}
	void IncreaseDateByOneMonth()
	{
		*this = clsDate::IncreaseDateByOneMonth(*this);
	}

	static clsDate IncreaseDateByXDays(short Days, clsDate Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date=IncreaseDateByOneDay(Date);
		}
		return Date;
	}
	void IncreaseDateByXDays(short Days)
	{
		*this = clsDate::IncreaseDateByXDays(Days,*this);
	}

	static  clsDate IncreaseDateByXMonths(short Months, clsDate Date)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date=IncreaseDateByOneMonth(Date);
		}
		return Date;
	}
	void  IncreaseDateByXMonths(short Months)
	{
		*this = clsDate::IncreaseDateByXMonths(Months, *this);
	}

	static clsDate IncreaseDateByOneYear(clsDate Date)
	{
		Date._Year++;
		return Date;
	}
	void IncreaseDateByOneYear()
	{
		*this=clsDate::IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByXYears(short Years, clsDate Date)
	{
		for (short i = 1; i <= Years; i++)
		{
			Date=IncreaseDateByOneYear(Date);
		}
		return Date;
	}
	void IncreaseDateByXYears(short Years)
	{
		*this = clsDate::IncreaseDateByXYears(Years, *this);
	}

	static short IncreaseDateByXYearsFaster(short Years, clsDate Date)
	{
		return Date._Year += Years;
	}
	void IncreaseDateByXYearsFaster(short Years)
	{
		this->_Year= clsDate::IncreaseDateByXYearsFaster(Years, *this);
	}

	static short IncreaseDateByOneDecade(clsDate Date)
	{
		//Period of 10 years
		return Date._Year += 10;
	}
	void IncreaseDateByOneDecade()
	{
		this->_Year = clsDate::IncreaseDateByOneDecade(*this);
	}

	static clsDate  IncreaseDateByXDecades(short Decade, clsDate Date)
	{
		for (short i = 1; i <= Decade * 10; i++)
		{
			Date =IncreaseDateByOneYear(Date);
		}
		return Date;
	}
	void IncreaseDateByXDecades(short Decade)
	{
		*this = clsDate::IncreaseDateByXDecades(Decade, *this);
	}

	static  short IncreaseDateByXDecadesFaster(short Decade, clsDate Date)
	{
		return Date._Year += Decade * 10;
	}
	void IncreaseDateByXDecadesFaster(short Decade)
	{
		this->_Year = clsDate::IncreaseDateByXDecadesFaster(Decade, *this);
	}

	static short IncreaseDateByOneCentury(clsDate Date)
	{
		//Period of 100 years
		return Date._Year += 100;
	}
	void IncreaseDateByOneCentury()
	{
		this->_Year = clsDate::IncreaseDateByOneCentury(*this);
	}

	static short IncreaseDateByOneMillennium(clsDate Date)
	{
		//Period of 1000 years
		return Date._Year += 1000;
	}
	void IncreaseDateByOneMillennium()
	{
		this->_Year = IncreaseDateByOneMillennium(*this);
	}

	static clsDate AddDaysToDate(short Days, clsDate Date)
	{
		Date._Day = Days + DaysFromBeginningOfYear(Date._Day, Date._Month, Date._Year);
		short MonthDays = 0;
		Date._Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date._Month, Date._Year);
			if (Date._Day > MonthDays)
			{
				Date._Day -= MonthDays;
				Date._Month++;
				if (Date._Month > 12)
				{
					Date._Month = 1;
					Date._Year++;
				}
			}
			else
			{
				break;
			}
		}
		return Date;
	}
	void AddDaysToDate(short Days)
	{
		*this = clsDate::AddDaysToDate(Days, *this);
	}


	//====================== decrease date functions =================================
	static clsDate DecreaseDateByOneDay(clsDate Date)
	{
		if (Date._Day == 1)
		{
			if (Date._Month == 1)
			{
				Date._Month = 12;
				Date._Day = 31;
				Date._Year--;
			}
			else
			{
				Date._Month--;
				Date._Day = NumberOfDaysInAMonth(Date._Month,
					Date._Year);
			}
		}
		else
		{
			Date._Day--;
		}
		return Date;
	}
	void DecreaseDateByOneDay()
	{
		*this = clsDate::DecreaseDateByOneDay(*this);
	}
	
	static clsDate DecreaseDateByXDays(short Days, clsDate Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	void DecreaseDateByXDays(short Days)
	{
		*this = DecreaseDateByXDays(Days,*this);
	}

	static clsDate DecreaseDateByOneWeek(clsDate Date)
	{
		for (int i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	void DecreaseDateByOneWeek()
	{
		*this = clsDate::DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(short Weeks, clsDate Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}
	void  DecreaseDateByXWeeks(short Weeks)
	{
		*this = clsDate::DecreaseDateByXWeeks(Weeks,*this);
	}

	static clsDate DecreaseDateByOneMonth(clsDate Date)
	{
		if (Date._Month == 1)
		{
			Date._Month = 12;
			Date._Year--;
		}
		else
			Date._Month--;
		//last check day in date should not exceed max days in thecurrent month
			// example if date is 31/3/2022 decreasing one month should notbe 31 / 2 / 2022, it should
			// be 28/2/2022
		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);
		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}
	void DecreaseDateByOneMonth()
	{
		*this = clsDate::DecreaseDateByOneMonth(*this);
	}
	
	static clsDate DecreaseDateByXMonths(short Months, clsDate Date)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}
	void  DecreaseDateByXMonths(short Months)
	{
		*this = DecreaseDateByXMonths(Months, *this);
	}

	static short DecreaseDateByOneYear(clsDate Date)
	{
		return Date._Year--;
	}
	void DecreaseDateByOneYear()
	{
		this->_Year = clsDate::DecreaseDateByOneYear(*this);
	}

	static short DecreaseDateByXYears(short Years, clsDate Date)
	{
		for (short i = 1; i <= Years; i++)
		{
			Date._Year = DecreaseDateByOneYear(Date);
		}
		return Date._Year;
	}
	void DecreaseDateByXYears(short Years)
	{
		this->_Year = clsDate::DecreaseDateByXYears(Years, *this);
	}

	static short DecreaseDateByXYearsFaster(short Years, clsDate Date)
	{
		return Date._Year -= Years;
	}
	void DecreaseDateByXYearsFaster(short Years)
	{
		this->_Year = clsDate::DecreaseDateByXYearsFaster(Years, *this);
	}

	static short DecreaseDateByOneDecade(clsDate Date)
	{
		//Period of 10 years
		return  Date._Year -= 10;
	}
	void DecreaseDateByOneDecade()
	{
		this->_Year = DecreaseDateByOneDecade(*this);
	}

	static short DecreaseDateByXDecades(short Decade, clsDate Date)
	{
		for (short i = 1; i <= Decade * 10; i++)
		{
			Date._Year = DecreaseDateByOneYear(Date);
		}
		return Date._Year;
	}
	void DecreaseDateByXDecades(short Decade)
	{
		this->_Year = clsDate::DecreaseDateByXDecades(Decade, *this);
	}

	static short DecreaseDateByXDecadesFaster(short Decade, clsDate Date)
	{
		return 	Date._Year -= Decade * 10;
;
	}
	void  DecreaseDateByXDecadesFaster(short Decades)
	{
		this->_Year = clsDate::DecreaseDateByXDecadesFaster(Decades, *this);
	}

	static short DecreaseDateByOneCentury(clsDate Date)
	{
		//Period of 100 years
		return 	Date._Year -= 100;
	}
	void DecreaseDateByOneCentury()
	{
		this->_Year = clsDate::DecreaseDateByOneCentury(*this);
	}

	static short DecreaseDateByOneMillennium(clsDate Date)
	{
		//Period of 1000 years
		return 	Date._Year -= 1000;
	}
	void DecreaseDateByOneMillennium()
	{
		this->_Year = clsDate::DecreaseDateByOneMillennium(*this);
	}


	//==============================================================================

	static vector<string>Split(string S1, string Delimiter)
	{
		vector <string> vWords;
		string word;
		short Position = 0;
		while ((Position = S1.find(Delimiter)) != std::string::npos)
		{
			word = S1.substr(0, Position);
			if (word != "")
			{
				vWords.push_back(word);
			}
			S1.erase(0, Position + Delimiter.length());

		}
		if (S1 != "")
		{
			vWords.push_back(S1);
		}

		return vWords;
	}
	string DayShortName(short DayOfWeekOrder)
	{
		if (DayOfWeekOrder < 0 || DayOfWeekOrder>6)
			return "";
		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arrDayNames[DayOfWeekOrder];
	}

	static string MonthShortName(short MonthNumber)
	{
		if (MonthNumber < 0 || MonthNumber>12)
			return "";
		string Months[12] =
		{
			"Jan", "Feb", "Mar",
			"Apr", "May", "Jun",
			"Jul", "Aug", "Sep",
			"Oct", "Nov", "Dec"
		};
		return (Months[MonthNumber - 1]);
	}
	string MonthShortName()
	{
		return MonthShortName(this->_Month);
	}
	
	static void PrintMonthCalendar(short Month, short Year)
	{
		short NumberOfDays, current, i;
		// Index of the day from 0 to 6
		current = DayOfWeekOrder(1, Month, Year);
		NumberOfDays = NumberOfDaysInAMonth(Month, Year);
		// Print the current month name
		printf("\n _______________%s_______________\n\n", MonthShortName(Month).c_str());
		// Print the columns
		printf("\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
		// Print appropriate spaces
		for (i = 0; i < current; i++)
			printf("     ");
		for (short j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);
			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}
		printf("\n _________________________________\n");
	}
	void PrintMonthCalendar()
	{
		PrintMonthCalendar(this->_Month, this->_Year);
	}

	static void PrintYearCalendar(short Year)
	{
		printf("\n _________________________________\n");
		printf("\n\t Calender %d -\t\n", Year);
		printf("\n _________________________________\n");

		for (short i = 1; i <= 12; i++)
			PrintMonthCalendar(i, Year);
		cout << endl;


	}
	void PrintYearCalendar()
	{
		PrintYearCalendar(this->_Year);
	}

	void stringToDate(string DateString)
	{
		vector <string> vWords;
		vWords = Split(DateString, "/");
		this->_Day = stoi(vWords[0]);
		this->_Month = stoi(vWords[1]);
		this->_Year = stoi(vWords[2]);
	}
	string DateToString(clsDate Date) 
	{
		return to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
	}
	string ReplaceWordInString(string S1, string StringToReplace, string sReplaceTo)
	{
		short pos = S1.find(StringToReplace);
		while (pos != std::string::npos)
		{
			S1 = S1.replace(pos, StringToReplace.length(), sReplaceTo);
			pos = S1.find(StringToReplace);
			//find next    
		}
		return S1;
	}
	string FormatDate(clsDate Date, string DateFormat = "dd/mm/yyyy")
	{
		string FormattedDateString = "";
		FormattedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date._Day));
		FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date._Month));
		FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date._Year));
		return  FormattedDateString;
	}

};



