# Municipal Financial Management System (MFMS)

## PAP521S – Programming in Practice

**Project:** Project A – Municipal Financial Management System  
**Programming Language:** ANSI C (C99)  
**Development Environment:** Visual Studio Code + GCC  
**Version Control:** Git and GitHub  
**Institution:** Namibia University of Science and Technology (NUST)

---

## 1. Group Members

|  Student Name  | St.Number |                              Main Contribution                               |
|----------------|-----------|------------------------------------------------------------------------------|
|  Jone Sampanha | 223029912 | Main menu, Budget Management, modularisation, input validation, documentation|
| Elroy Noariseb | 224067559 | Employee Management, Supplier Management, Asset Management and Reports       |
---

## 2. Project Description

The Municipal Financial Management System (MFMS) is a console-based application developed in the C programming language for managing basic municipal administrative and financial information.

The system was developed as Project A for PAP521S – Programming in Practice. Its purpose is to demonstrate the practical application of programming concepts covered during the first part of the course.

The project uses concepts including:

- Variables and data types
- Input and output
- Arithmetic, relational and logical operators
- Decision-making
- Loops
- Arrays
- Character arrays and strings
- Functions
- Function parameters and return values
- Searching
- Multi-file programming
- Header files
- Input validation
- Git and GitHub collaboration

The program is divided into separate modules instead of placing all functionality inside one large `main()` function.

---

## 3. System Features

The MFMS contains five main functional modules together with a shared input-validation module.

### 3.1 Municipality Information

When the program starts, the user enters:

- Municipality name
- Mayor name
- Population

The information is validated and displayed before the main menu is opened.

---

### 3.2 Employee Management

The Employee Management module allows the user to:

- Add an employee
- Display all employees
- Search for an employee by ID
- Store employee name and department
- Store basic salary
- Store housing allowance
- Store transport allowance
- Calculate gross salary
- Prevent duplicate employee IDs
- Prevent negative salary and allowance values

Gross salary is calculated as:

```text
Gross Salary = Basic Salary + Housing Allowance + Transport Allowance
```

The system can store a maximum of **50 employees**.

The employee module also provides information used by the Reports module, including:

- Total number of employees
- Average gross salary
- Highest gross salary
- Lowest gross salary

---

### 3.3 Budget Management

The Budget Management module allows the user to:

- Add a departmental budget
- Store the department name
- Enter an allocated budget
- Enter expenditure
- Calculate the remaining budget
- Determine whether the department is within or over budget
- Display all departmental budget records

Remaining budget is calculated as:

```text
Remaining Budget = Allocated Budget - Expenditure
```

If expenditure is less than or equal to the allocated budget, the department is displayed as:

```text
WITHIN BUDGET
```

If expenditure exceeds the allocated budget, the department is displayed as:

```text
OVER BUDGET
```

The system can store a maximum of **10 department budget records**.

The module also supplies report information including:

- Total allocated budget
- Total expenditure
- Number of departments over budget

---

### 3.4 Supplier Management

The Supplier Management module allows the user to:

- Add suppliers
- Display suppliers
- Search for a supplier by name
- Store supplier ID
- Store supplier name
- Store email address
- Store telephone number
- Store town/location
- Prevent duplicate supplier IDs

Supplier names are searched using the C string function:

```c
strcmp()
```

The program also uses:

```c
strlen()
```

to display the length of supplier names.

The system can store a maximum of **20 suppliers**.

---

### 3.5 Asset Management

The Asset Management module provides a basic municipal asset register.

The user can:

- Add an asset
- Display all assets
- Search for an asset by ID
- Store asset ID
- Store asset name
- Store asset type
- Store purchase value
- Store department
- Store asset condition
- Prevent duplicate asset IDs
- Prevent negative purchase values

The system can store a maximum of **30 assets**.

---

### 3.6 Reports

The Reports module provides four types of reports.

#### Employee Report

Displays:

- Total employees
- Average gross salary
- Highest gross salary
- Lowest gross salary

#### Budget Report

Displays:

- Total allocated budget
- Total expenditure
- Remaining municipal budget
- Number of departments over budget

#### Supplier Report

Displays:

- Total registered suppliers
- Supplier information

#### Asset Report

Displays:

- Total registered assets
- Asset information

---

### 3.7 Input Validation

A shared input-validation module is used throughout the MFMS.

The module contains reusable functions that validate user input.

```c
readInt()
readNonNegativeDouble()
readText()
clearExtraInput()
```

The validation system helps prevent:

- Invalid menu choices
- Letters being entered where numbers are required
- Numbers outside an allowed range
- Negative salaries
- Negative allowances
- Negative budgets
- Negative expenditure
- Negative asset values
- Empty text fields
- Input that exceeds the available character-array size

`fgets()` is used for text input so that names containing spaces, such as municipality names and employee names, can be entered correctly.

---

## 4. Project Structure

```text
MFMS-Project-A/
│
├── main.c
│
├── employees.c
├── employees.h
│
├── budget.c
├── budget.h
│
├── suppliers.c
├── suppliers.h
│
├── assets.c
├── assets.h
│
├── reports.c
├── reports.h
│
├── input.c
├── input.h
│
├── README.md
└── .gitignore
```

### File Responsibilities

**`main.c`**  
Contains the main program, captures municipality information, displays the main menu and directs the user to the appropriate module.

**`employees.c` / `employees.h`**  
Contain Employee Management functions and employee-related report calculations.

**`budget.c` / `budget.h`**  
Contain Budget Management functions and municipal budget calculations.

**`suppliers.c` / `suppliers.h`**  
Contain Supplier Management and supplier search functionality.

**`assets.c` / `assets.h`**  
Contain Asset Management and asset search functionality.

**`reports.c` / `reports.h`**  
Contain the employee, budget, supplier and asset reporting functions.

**`input.c` / `input.h`**  
Contain reusable input and validation functions used by the other modules.

**`.gitignore`**  
Prevents generated executable files from being included in the Git repository.

---

## 5. Main Program Navigation

The main menu contains:

```text
========================================
MUNICIPAL FINANCIAL MANAGEMENT SYSTEM
========================================
1. Employee Management
2. Budget Management
3. Supplier Management
4. Asset Management
5. Reports
6. Exit
```

A `do...while` loop keeps the program running until the user selects **6 – Exit**.

A `switch` statement directs the user to the selected module.

---

## 6. Compilation Instructions

### Requirements

The computer must have:

- GCC compiler
- Terminal/Command Prompt
- Git, if the repository will be cloned
- Visual Studio Code is recommended but not required

Verify GCC using:

```bash
gcc --version
```

### Compile the Project

Open a terminal inside the project folder and run:

```bash
gcc main.c employees.c budget.c suppliers.c assets.c reports.c input.c -o mfms
```

If compilation succeeds, an executable named `mfms` or `mfms.exe` will be generated.

---

## 7. Running the System

### Windows PowerShell

```powershell
.\mfms.exe
```

### Windows Command Prompt

```cmd
mfms.exe
```

### Linux

```bash
./mfms
```

---

## 8. Example Program Flow

```text
Start Program
      |
      v
Enter Municipality Information
      |
      v
Display Main Menu
      |
      +--> Employee Management
      |
      +--> Budget Management
      |
      +--> Supplier Management
      |
      +--> Asset Management
      |
      +--> Reports
      |
      +--> Exit
```

Each management module contains its own submenu and returns to the main menu when the user finishes working with that module.

---

## 9. Programming Concepts Demonstrated

### Variables and Data Types

The project uses:

- `int`
- `double`
- `char` arrays

### Arrays

Arrays are used to store multiple:

- Employees
- Department budgets
- Suppliers
- Assets

### Loops

Loops are used for:

- Menu repetition
- Searching records
- Displaying records
- Calculating report values

### Conditions

`if`, `else` and `switch` are used for:

- Input decisions
- Budget status
- Duplicate ID detection
- Searching
- Menu navigation
- Validation

### Strings

Character arrays are used to store text.

String-processing functions include:

```c
strlen()
strcmp()
strchr()
strcspn()
```

### Functions

The application is divided into reusable functions such as:

```c
employeeManagement()
addEmployee()
displayEmployees()
searchEmployee()
calculateSalary()

budgetManagement()
addDepartmentBudget()
displayBudgets()

supplierManagement()
addSupplier()
displaySuppliers()
searchSupplier()

assetManagement()
addAsset()
displayAssets()
searchAsset()

reportsManagement()
employeeReport()
budgetReport()
supplierReport()
assetReport()

readInt()
readNonNegativeDouble()
readText()
```

---

## 10. Data Storage

Project A stores records in arrays while the program is running.

The current version does **not** permanently save information after the application is closed.

Permanent file storage can be introduced in a later version of the MFMS using C file-handling techniques.

---

## 11. Git and GitHub Collaboration

Git and GitHub were used to maintain the project's development history.

The repository contains identifiable commits representing different stages of development, including:

- Initial project setup
- Municipality and mayor input
- Main menu development
- Employee Management
- Budget Management
- Multi-file restructuring
- Supplier Management
- Asset Management
- Reports
- Input validation and integration
- Documentation and final cleanup

### Verified Contributions

**Jone A. S. Sampanha – 223029912**

Contributed to:

- Initial MFMS setup
- Municipality input
- Main-menu development
- Budget Management
- Multi-file project restructuring
- Input-validation integration
- Final integration
- README documentation and cleanup

**Elroy Noariseb – 224067559**

Contributed to:

- Mayor input
- Basic MFMS setup
- Employee Management
- Supplier Management
- Asset Management
- Reports module

---

## 12. Repository

**GitHub Repository:**

https://github.com/Jone-Sampanha-223029912/MFMS-Project-A

---

## 13. Limitations

The current Project A version has several intentional limitations:

- Information is stored only while the program is running.
- Arrays have fixed maximum sizes.
- Supplier searching requires an exact supplier-name match.
- No graphical user interface is provided.
- No database is used.

These limitations are suitable for the foundation stage of the project and can be improved in later versions.

---

## 14. Conclusion

The Municipal Financial Management System demonstrates how fundamental C programming concepts can be combined to develop a structured application that solves a realistic municipal-management problem.

The project integrates input, processing, storage, searching, calculations, reports and output while using separate program modules and reusable functions.

The final system provides a strong foundation for future development and extension of the MFMS.