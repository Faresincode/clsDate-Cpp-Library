# 📅 clsDate-Cpp-Library

A lightweight and powerful **C++ date library** for creating, validating, comparing, formatting, and manipulating dates with ease.

------------------------------------------------------------
## ✨ Features

| Category        | What You Can Do |
|-----------------|-----------------|
| **Create Dates** | From system time (today), from `day/month/year`, from string (e.g. "26/08/2025"), or from day-order in year |
| **Validation**   | Check if a date is valid, detect leap years |
| **Comparison**   | Compare two dates (before, equal, after) |
| **Date Math**    | Add or subtract days, weeks, months, years, decades, centuries, millennia |
| **Utilities**    | Day of week, weekend & business day checks, start/end of week/month/year, days difference, vacation days |
| **Formatting**   | Convert date ↔ string, use custom formats, short names for months/days |
| **Calendars**    | Print month or year calendars in the console |


------------------------------------------------------------
## 📝 Example
```cpp
#include "clsDate.h"
#include <iostream>
using namespace std;

int main() {
    clsDate today;             // Current system date
    clsDate custom(26, 8, 2025);

    cout << "Today: "   << today.DateToString(today)   << endl;
    cout << "Custom: "  << custom.DateToString(custom) << endl;

    custom.IncreaseDateByOneMonth();
    cout << "After +1 month: " << custom.DateToString(custom) << endl;

    if (today.IsWeekEnd())
        cout << "Today is weekend!" << endl;
    else
        cout << "Today is a business day." << endl;

    custom.PrintMonthCalendar();
    return 0;
}
```

------------------------------------------------------------
## 📂 Project Structure
```
clsDate-Cpp-Library/
│── clsDate.h   # Main library header
│── README.md   # Project documentation
│── main.cpp    # Example usage
```

------------------------------------------------------------
## 🤝 Contributing
Pull requests are welcome.  
For major changes, please open an issue first to discuss what you’d like to change.

------------------------------------------------------------
## 📜 License
Licensed under the MIT License.
