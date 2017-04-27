#include "Date.h"
#include <iostream>
#include <iomanip>

using namespace std;

Date::Date()								// default constructor (no parameters) set default date ( 1/01/1970 )
{
	setDefaultDate();
}

Date::Date(int m, int d, int y)				// constructor with month day year parameters
{
	setDate(m, d, y);
}

void	Date::setDate(int mm, int dd, int yyyy)
{
	month	= mm;
	day		= dd;
	year	= yyyy;

	if (!validDate())						// call for setDefaultDate() if result is not fully-valid date
		setDefaultDate();
}

void	Date::setDefaultDate()				// set month day year values to default date ( 1/01/1970)
{
	month	= 1;
	day		= 1;
	year	= 1970;
}

int		Date::getMonth()	const			// return current month value
{
	return month;
}

int		Date::getDay()		const			// return current day   value
{
	return day;
}

int		Date::getYear()		const			// return current 4-digit year value
{
	return year;
}

void	Date::displayDate()	const
{
	cout << setw(2) << month << "/" << setw(2) << day << "/" << setw(4) << year << endl;
}

bool	Date::validMonth()	const			// check for valid month range
{
	bool validMonth = false;

	if (month >= 1 && month <= 12)
		validMonth = true;

	return validMonth;
}

bool	Date::validDay()	const			// check for valid day range
{
	bool validDay;

	if ((month == 4 || month == 6 || month == 9 || month == 11) && (day >= 1 && day <= 30))
		validDay = true;
	else if ((month == 2) && (day >= 1 && day <= 28))
		validDay = true;
	else if ((month == 1 || month == 3 || month == 5 || month == 7 ||
			  month == 8 || month == 10 || month == 12) && (day >= 1 && day <= 31))
		validDay = true;
	else if (month == 2 && year % 4 == 0 && (day >= 1 && day <= 29))
    {
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				validDay = true;
			else
				validDay = false;
		}
		else
			validDay = true;
	}
	else
		validDay = false;

	return validDay;
}

bool	Date::validYear()					// check for valid year  value (must be >= zero)
{
	bool validYear;

	if (year >= 0 && year < 10000)
	{

		if (year <= 30 && year > 0)
		{
			year += 2000;
			return validYear = true;
		}

		if (year >= 31 && year <= 99)
		{
			year += 1900;
			return validYear = true;
		}

		return validYear = true;
	}
	else
		return validYear = false;
}

bool	Date::validDate()					// check for valid month, day, and year
{
	bool validDate;

	if (validMonth() == true && validDay() == true && validYear() == true)
		validDate = true;
	else
		validDate = false;

	return validDate;
}