#pragma once
#include <iostream>
#include "clsDate.h";
using namespace std;

class clsPeriod
{

public:

	clsDate StartDate;
	clsDate EndDate;
	
	clsPeriod(clsDate StartDate,clsDate EndDate)
	{
		this->StartDate = StartDate;
		this->EndDate = EndDate;
	}

	static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
	{
		return (clsDate::Compare2Dates(Period2.EndDate, Period1.StartDate) == clsDate::enDateCompare::Before || clsDate::Compare2Dates(Period2.StartDate, Period1.EndDate) == clsDate::enDateCompare::After) ? false : true;
	}
	bool IsOverlapPeriods(clsPeriod Period2)
	{
		return clsPeriod::IsOverlapPeriods(*this, Period2);
	}

	static bool IsDateWithInPeriod(clsDate DateToCheck, clsPeriod Period)
	{
		return !(clsDate::Compare2Dates(DateToCheck, Period.StartDate) == clsDate::enDateCompare::Before || clsDate::Compare2Dates(DateToCheck, Period.EndDate) == clsDate::enDateCompare::After);
	}
	bool IsDateWithInPeriod(clsDate DateToCheck)
	{
		return clsPeriod::IsDateWithInPeriod(DateToCheck, *this);
	}

	static int PeriodLengthDays(clsPeriod Period, bool IncludeEndDate = false)
	{
		return clsDate::DifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDate);
	}
	int PeriodLengthDays(bool IncludeEndDate = false)
	{
		return clsPeriod::PeriodLengthDays(*this, IncludeEndDate);
	}

	int CountOverLapDays(clsPeriod Period1, clsPeriod Period2)
	{

		if (!IsOverlapPeriods(Period1, Period2))
			return 0;
		int Period1Length = PeriodLengthDays(Period1, true);
		int Period2Length = PeriodLengthDays(Period2, true);
		int OverLapDays = 0;
		if (Period1Length < Period2Length)
		{
			while (clsDate::IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
			{
				if (IsDateWithInPeriod(Period1.StartDate, Period2))
					OverLapDays++;
				Period1.StartDate = clsDate::AddOneDay(Period1.StartDate);
			}
		}
		else
		{
			while (clsDate::IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
			{
				if (IsDateWithInPeriod(Period2.StartDate, Period1))
					OverLapDays++;
				Period2.StartDate = clsDate::AddOneDay(Period2.StartDate);
			}
		}

		return OverLapDays;
	}

	void Print()
	{
		cout << "\nPeriod Start: ";
		StartDate.Print();

		cout << "\nPeriod End: ";
		EndDate.Print();


	}



};

