# 📅 clsDate-Cpp-Library

A lightweight and powerful **C++ date library** for creating, validating, comparing, formatting, and manipulating dates with ease.

------------------------------------------------------------
## ✨ Features Overview

| Category        | Features                                                                 |
|-----------------|--------------------------------------------------------------------------|
| **Creation**    | - From system time (today) <br> - From day/month/year <br> - From string <br> - From day order in year |
| **Validation**  | - Valid date check <br> - Leap year detection                            |
| **Comparison**  | - Equal, before, after <br> - Enum-based comparison (Before, Equal, After) |
| **Date Math**   | - Add/Subtract days, weeks, months, years <br> - Support for decades, centuries, millennia |
| **Utilities**   | - Day of week calculation <br> - Weekend & business day detection <br> - Start/end of week, month, year <br> - Days difference between two dates <br> - Calculate vacation days (skip weekends) |
| **Formatting**  | - Date → string <br> - String → date <br> - Custom formats (dd/mm/yyyy etc.) <br> - Short names for days & months |
| **Calendars**   | - Print month calendar <br> - Print year calendar                        |

------------------------------------------------------------
## 🚀 Quick Start

Clone the repo:
```bash
git clone https://github.com/<your-username>/clsDate-Cpp-Library.git
cd clsDate-Cpp-Library
```

Include the header in your project:
```cpp
#include "clsDate.h"
```

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
