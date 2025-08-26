# clsDate-Cpp-Library
clsDate.h is a C++ date library class that makes it easy to create, validate, compare, and format dates. It supports date arithmetic (add/subtract days, months, years), leap year checks, business day/weekend logic, and even printing full calendars.

# clsDate-Cpp-Library

A powerful and easy-to-use C++ library for handling dates with rich functionality.

## 🚀 Features
- **Date Creation & Initialization**
  - From system time (current date)
  - From string (e.g. "26/08/2025")
  - From day order in year
  - From day/month/year directly
- **Validation**
  - Check if a date is valid
  - Leap year detection
- **Comparison**
  - Check if two dates are equal, before, or after
  - Enum-based comparison (Before, Equal, After)
- **Date Arithmetic**
  - Increase/Decrease by days, weeks, months, years
  - Handle decades, centuries, and millennia
  - Add/subtract X days, months, years easily
- **Utilities**
  - Day of week calculation
  - Detect weekends, weekdays, and business days
  - Check start/end of week, month, or year
  - Calculate difference in days between two dates
  - Calculate vacation days excluding weekends
- **Formatting & Conversion**
  - Convert date to string in different formats
  - Parse string to date
  - Short names for days and months
- **Calendars**
  - Print month calendar to console
  - Print full year calendar
- **Misc**
  - Support for replacing words in formatted date strings
  - Flexible static and instance methods

## 📂 Project Structure
```
clsDate-Cpp-Library/
│── clsDate.h   # Main date library class
│── README.md   # Project documentation
│── main.cpp    # Example usage (optional)
```

## 📝 Example Usage
```cpp
#include "clsDate.h"
#include <iostream>
using namespace std;

int main() {
    clsDate today; // Current system date
    clsDate custom(26, 8, 2025);

    cout << "Today: " << today.DateToString(today) << endl;
    cout << "Custom: " << custom.DateToString(custom) << endl;

    custom.IncreaseDateByOneMonth();
    cout << "After one month: " << custom.DateToString(custom) << endl;

    if (today.IsWeekEnd()) 
        cout << "Today is weekend!" << endl;
    else 
        cout << "Today is a business day." << endl;

    custom.PrintMonthCalendar();
    custom.PrintYearCalendar();

    return 0;
}
```

## 🤝 Contributing
Contributions, issues, and feature requests are welcome!  
Feel free to fork this repo and submit pull requests.

## 📜 License
This project is licensed under the MIT License.


