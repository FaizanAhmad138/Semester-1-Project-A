#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct pharmacy{
    string medicines;
    string expiryDates;
    string usernameOfReviews;
    string reviews;
     int indices;
    double quantities;
    double medicinePrice;
};
int validationOfInput(int input, int n, string menutype);
bool medicineNameValidation(string medicine);
double priceValidation(string a);
double stringToDouble(string a);
bool isdouble(string a);
string nameofmedicine(string medicine, string word);
void initialize(pharmacy fazi[], int size, string variableForinitialize);
int searchForMedicine(string del,pharmacy fazi[], int size);
void searchMenuForAdmin();
void printMedicineByprice(pharmacy fazi[], int size, double low, double high, int &count);
int *searchByPrice(pharmacy fazi[], int size, double low, double high, int &count);
int countForpricesearchindex(pharmacy fazi[], double size, double low, double high, int &count);
void initializeintteger(pharmacy fazi[], int size, double assign);
int discountcheck(int discount);
void printByName(int index, pharmacy fazi[], int size, int cass);
void updateMenu();
void medicinInventory(pharmacy fazi[], int size);
bool dateCheck(string date);
string expiryDate(string date);
int countfornv(pharmacy fazi[], int size);
void searchByDate(pharmacy fazi[], int size, string date);
void contactmenu();
void instagramlink();
void whatsapplink();
string reviewsValidation(string a);
bool stringAlphabetscheck(string a);
void printReviews(pharmacy fazi[], int size);
void enterReviews(pharmacy fazi[], int size);
void reviewMenu();
void printPurchaseList(pharmacy fazi[], int size);
void initial(pharmacy fazi[], int size, int assign);
// char* cnicNum( char a);
bool cnicValid(char *cnic);
string getCurrentDate();
bool saveData(pharmacy fazi[], int size);
bool saveReviews(pharmacy fazi[], int size);
// this function prints the pharmacy logo
bool loadData(pharmacy fazi[], int size);
bool loadReview(pharmacy fazi[], int size);
void printPharmacy()
{

    cout << "\t\t██████╗ ██╗  ██╗ █████╗ ██████╗ ███╗   ███╗ █████╗  ██████╗██╗   ██╗\n";
    cout << "\t\t██╔══██╗██║  ██║██╔══██╗██╔══██╗████╗ ████║██╔══██╗██╔════╝╚██╗ ██╔╝\n";
    cout << "\t\t██████╔╝███████║███████║██████╔╝██╔████╔██║███████║██║      ╚████╔╝ \n";
    cout << "\t\t██╔═══╝ ██╔══██║██╔══██║██╔══██╗██║╚██╔╝██║██╔══██║██║       ╚██╔╝  \n";
    cout << "\t\t██║     ██║  ██║██║  ██║██║  ██║██║ ╚═╝ ██║██║  ██║╚██████╗   ██║    \n\n\n";
}
// this function is used for colours
void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
// Displaying the first page with role options
void firstPage()
{
    cout << "\t\t1. Admin" << endl;
    // cout << "\t\t. Cashier" << endl;
    cout << "\t\t2. Customer" << endl;
    cout << "\t\t0. Exit" << endl;
}
// this function prints the cashier menu options

// this function prints the admin menu options
void adminMenu()
{

    cout << "\t\t\tAdmin Features:" << endl;
    cout << "\t\t1. Add New Medicine" << endl;
    cout << "\t\t2. Update Medicine Information" << endl;
    cout << "\t\t3. Delete Medicine" << endl;
    cout << "\t\t4. View Medicine Inventory" << endl;
    cout << "\t\t5. Search for Medicine" << endl;


    cout << "\t\t6. View Reviews" << endl;
    cout << "\t\t7. Set Discount Rates" << endl;
    cout << "\t\t0. Log Out" << endl;
}
// this function prints the customer menu options
void customerMenu()
{
    cout << "\t\t\tCustomer Features:" << endl;
    cout << "\t\t1. View Available Medicines" << endl;
    cout << "\t\t2. Search for Medicine" << endl;
  
    cout << "\t\t3. View Discounts " << endl;
    cout << "\t\t4. Place Order" << endl;
    cout << "\t\t5. View Reviews" << endl;
    cout << "\t\t6. Contact us" << endl;
   
    cout << "\t\t0. Log Out" << endl;
}

// Function to get password securely
void getPassword(string &password)
{
    char ch;
    while (true)
    {
        ch = _getch(); // get a character without echoing it to the console

        if (ch == 13)
        { // Enter key is pressed
            break;
        }
        else if (ch == 8)
        { // Backspace key is pressed
            if (password.length() > 0)
            {
                password = password.substr(0, password.length() - 1);
                cout << "\b \b"; // erase last character
            }
        }
        else
        {
            password += ch;
            cout << "*"; // display an asterisk for each character
        }
    }
    cout << endl; // Move to the next line after password input
}
int checkempty(pharmacy fazi[], int size, string variableForEmpty)
{
    string empty = variableForEmpty;
    for (int i = 0; i < size; i++)
    {
        if (fazi[i].medicines == empty)
        {
            return i;
        }
    }
    return -1;
}
// this is main function.....
int main()
{

    const int size = 10;
    int index = -1;
    int choiceInput = -1;
    int searchinput = -1;
    string searchMedicine = "";
    string medicine = "";
    string deleteMedicine = "";
    string medicines[size];
    string expiryDates[size];
    string usernameOfReviews[size];
    string reviews[size];
     int indices[size];
     pharmacy fazi[size];
    double quantities[size];
    string username, password;
    string medicineUpdate = "";
    string date = "";
    
   
    int discountedPrice = 0;
    char ch = 'y';
    int input = -1, low = 0, high = 0, i = 0;
    int quantity = 0, j = 0;
    int count = 0, sum = 0;
    int reviewinput = 0;
    int discount = 0;
    int loginUserType = -10;
    string price = "";
    double medicinePrice[size] = {-1};
    int totalPrice = 0;
    string CNIC_DatePurchase[2][10];
    char cnic[14];
    string soldMedicine[size];
    int quantity_price[2][10];
    string CNICS[10];
    int soldamounts[10];

    //cals of funtion to initialize rrays

    system("chcp 65001");
    initialize(fazi, size, "nv");
    initialize(fazi, size, "nv");
    initialize(fazi, size, "nv");
    initialize(fazi, size, "nv");
    initializeintteger(fazi, size, -1);
    initializeintteger(fazi, size, -1);
    initial(fazi, size, -1);


    //call of file hanling fucntio to load data in arrays from file

    loadReview(fazi, size);
    loadData(fazi, size);
    srand(time(0));

    do
    {
        system("cls");


        printPharmacy();
        firstPage();

        cout << endl
             << endl
             << "Enter your choice : ";
        cin >> input;
        // input=floor(input);
        input = validationOfInput(input, 2, "first");
    
    
        switch (input)
        {
    
        case 1:
            system("cls");
            printPharmacy();
            cout << endl
                 << endl;
            cout << "Enter Username: ";
            cin.ignore(100, '\n');
            getline(cin, username);

            cout << "Enter Password: ";
            password = "";
            getPassword(password);
            if (username == "faizan" && password == "fazi1430")
            {
                loginUserType = 1; // for admin login
            }
            else
            {
                loginUserType = -1; // for invalid
            }
            break;

    
        case 2:
            loginUserType = 2; // for customer
            break;
    
        case 0:
            system("cls");
            printPharmacy();
            cout << endl
                 << endl;
            setColor(14);
            cout << endl
                 << "THANK YOU FOR USING THIS SYSTEM!!...";
            break;
    
    
        default:
            cout << endl
                 << endl;
            setColor(12);
            cout << "INVALID CHOICE!!";
            break;
        }
    
    
    
        if (loginUserType == 1)
    
    
        {
            do
            {
                system("cls");
                printPharmacy();
                cout << endl
                     << endl;
                adminMenu();
                cout << endl
                     << endl
                     << "Enter your choice : ";
                cin >> input;
                input = floor(input);
                validationOfInput(input, 7, "admin");

    
                switch (input)
    
                {
                case 1:
    
    
                    system("cls");
                    printPharmacy();
    
                    setColor(11);
    
                    cout << "\t\tADD NEW MEDICINE....." << endl
                         << endl;
                    index = checkempty(fazi, size, "nv");
    
                    setColor(7);
                    if (index != -1)
    
                    {
                        cout << "Enter the name Of Medicine : ";
    
                        cin.ignore(100, '\n');
    
                        getline(cin, medicine);
                        fazi[index].medicines = nameofmedicine(medicine, "Medicine");


                        cout << "\nEnter the price of medicine : ";

                        // cin.ignore(100,'\n');

                        cin >> price;

                        fazi[index].medicinePrice = priceValidation(price);


                        cout << "\nEnter the Expiry date of the medicine (DD-MM-YYYY): ";

                        getline(cin, date);


                        fazi[index].expiryDates = expiryDate(date);
                        setColor(14);

                        cout << endl
                             << "Medicine Added Successfully !!...";
                        cout << endl
                             << "\t\tPress any key to continue ......";

                        _getch();
                        setColor(7);
                    }

                    else

                    {

                        setColor(12);

                        cout << "\nInventory is full!!!";

                        setColor(14);

                        cout << "\n\t\tPress any key to continue ......";

                        _getch();

                        setColor(7);
                    }
                    break;
                case 2:
                    system("cls");

                    printPharmacy();

                    cout << "\t\t2. Update Medicine Information" << endl;

                    cout << "Enter the medicine name you want to update : ";

                    cin.ignore();

                    getline(cin, medicineUpdate);

                    index = searchForMedicine(medicineUpdate, fazi, size);

                    printByName(index,fazi, size, 2);

                    if (index != -1)
                    {
                        updateMenu();
                        cout << endl
                             << endl
                             << "Enter your choice : ";
                        cin >> searchinput;
                        searchinput = validationOfInput(searchinput, 3, "update");

                        if (searchinput == 1)
                        {
                            cout << "\n\t\tEnter the new medicine name : ";

                            cin.ignore();

                            getline(cin, medicine);

                            fazi[index].medicines = nameofmedicine(medicine, "Medicine");

                            setColor(14);

                            cout << endl

                                 << "Medicine Name Changed Successfully !!...";
                            cout << endl
                                 << "\t\tPress any key to continue ......";

                            _getch();

                            setColor(7);
                        }

                        else if (searchinput == 2)
                        {
                            cout << "\n\t\tEnter the new price of medicine : ";

                            cin.ignore();


                            getline(cin, price);

                            fazi[index].medicinePrice = priceValidation(price);

                            setColor(14);

                            cout << endl

                                 << "Medicine Price Changed Successfully !!...";

                            cout << endl
                                 << "\t\tPress any key to continue ......";

                            _getch();

                            setColor(7);
                        }

                        else if (searchinput == 3)
                        {

                            cout << "\n\t\tEnter the new Expiry date of the medicine (DD-MM-YYYY): ";

                            cin.ignore();

                            getline(cin, date);


                            fazi[index].expiryDates = expiryDate(date);

                            setColor(14);

                            cout << endl

                                 << "Medicine Expiry Date Changed Successfully !!...";

                            cout << endl

                                 << "\t\tPress any key to continue ......";

                            _getch();
                            setColor(7);
                        }
                    }

                    break;
                case 3:


                    system("cls");

                    printPharmacy();

                    setColor(11);

                    cout << "\t\tDELETE MEDICINE....." << endl

                         << endl;

                    setColor(7);

                    cout << "Enter the name Of Medicine you want to delete : ";

                    cin.ignore();

                    getline(cin, deleteMedicine);

                    index = searchForMedicine(deleteMedicine,fazi, size);

                    if (index != -1)
                    {
                        setColor(14);
                        medicines[index] = "nv";
                        medicinePrice[index] = -1;
                        expiryDates[index] = "nv";
                        cout << endl
                             << endl
                             << "\tMedicine deleted successfully..." << endl
                             << endl;
                        cout << endl
                             << "\t\tPress any key to continue ......";
                        _getch();
                        setColor(7);
                    }
                    else
                    {
                        setColor(12);
                        cout << "\nMedicine not exists!!!";
                        setColor(14);
                        cout << "\n\t\tPress any key to continue ......";
                        _getch();
                        setColor(7);
                    }
                    break;
                case 4:
                    system("cls");
                    printPharmacy();
                    cout << "\n\t\t Medicine Inventory" << endl;
                    medicinInventory(fazi, size);
                    setColor(14);
                    cout << "\n\t\tPress any key to continue ......";
                    _getch();
                    setColor(7);
                    break;
                case 5:
                    system("cls");
                    printPharmacy();
                    searchMenuForAdmin();
                    cout << endl
                         << endl
                         << "Enter your choice : ";
                    cin >> searchinput;
                    searchinput = validationOfInput(searchinput, 3, "search");
                    if (searchinput == 1)
                    {
                        system("cls");
                        printPharmacy();
                        // medicinInventory(medicines, size, medicinePrice, expiryDates);
                        cout << "\n\nEnter the name Of Medicine you want to search : ";
                        cin.ignore();
                        getline(cin, searchMedicine);
                        index = searchForMedicine(searchMedicine, fazi, size);
                        printByName(index, fazi, size,  5);
                    }
                    else if (searchinput == 2)
                    {
                        system("cls");
                        printPharmacy();
                        cout << "Enter the lower price : ";

                        cin >> low;

                        cout << "Enter the high price  : ";

                        cin >> high;

                        if (high < low)
                        {
                            int temp = high;

                            high = low;
                            low = temp;

                        }

                        printMedicineByprice(fazi, size, low, high, count);

                    }

                    else if (searchinput == 3)

                    {

                        system("cls");

                        printPharmacy();
                        cout << "Enter the date Of Expiry you want to search (DD-MM-YYYY): ";
                        cin.ignore();
                        getline(cin, date);

                        searchByDate(fazi, size, date);

                    }

                    break;

                case 6:

                    system("cls");
                    printPharmacy();
                    cout << "\t\t Reviews" << endl;

                    printReviews(fazi,  size);

                    setColor(14);

                    cout << "\n\t\tPress any key to continue ......";
                    _getch();
                    setColor(7);
                    break;
                case 7:
                    system("cls");
                    printPharmacy();
                    cout << "\t\t Set Discount Rates...." << endl;
                    cout << "\nEnter the dicount percentage you want to set : %";
                    cin >> discount;
                    discount = discountcheck(discount);
                    setColor(14);
                    cout << "\n\t\t Discount set successfuly" << endl;



                    cout << "\n\t\tPress any key to continue ......";
                    _getch();
                    setColor(7);

                    break;
                }


            } while (input != 0);

            loginUserType = -10;

            input = -1; // this statment is to make sure that do not exit from outer loop

        }

        else if (loginUserType == 2)
        {


            do
            {
                system("cls");
                printPharmacy();

                cout << endl
                     << endl;

                customerMenu();
                cout << endl
                     << endl
                     << "Enter your choice : ";
                cin >> input;
                // input = floor(input);

                validationOfInput(input, 6, "customer");

                switch (input)
                {
                case 1:
                    system("cls");
                    printPharmacy();
                    cout << endl
                         << endl;
                    cout << "\t\t  Available Medicines" << endl;
                    medicinInventory(fazi, size);
                    setColor(14);
                    cout << "\n\t\tPress any key to continue ......";
                    _getch();
                    setColor(7);
                    break;

                case 2:


                    system("cls");

                    printPharmacy();

                    cout << "\n\t\t Check Medicine Price.." << endl

                         << endl;

                    cout << "Enter the name Of Medicine you want to search : ";

                    cin.ignore();

                    getline(cin, searchMedicine);

                    index = searchForMedicine(searchMedicine,fazi, size);


                    printByName(index, fazi, size, 5);

                    break;

                case 3:

                    system("cls");

                    printPharmacy();

                    cout << endl

                         << endl;

                    cout << "\t\tDiscount Board !" << endl;

                    setColor(11);

                    cout << "\n\tToday discount offer  is : % " << discount;

                    setColor(14);

                    cout << "\n\t\tPress any key to continue ......";

                    _getch();

                    setColor(7);

                    break;
                case 4:
                    system("cls");
                    printPharmacy();
                    cout << endl
                         << endl;
                    // cout << "Enter Your CNIC Number : ";
                    // cin.getline(cnic,14);
                    // while(!cnicValid(cnic)){
                    //     cin.clear();
                    //     setColor(12);
                    //     cout<<"\nwrong input!!Enter like this(3420114975787)."<<endl;
                    //     setColor(7);
                    //     cout<<"Enter CNIC Number : ";
                    //         cin.getline(cnic,14);
                    // }
                    // CNIC_DatePurchase[0][j] = cnic;
                    medicinInventory(fazi, size);
                    cout << "\n\n\t\t Order " << endl;
                    cout << "maximum order you can placed are 10 at once ....";
                    do
                    {
                        cout << "\nEnter the medicine name you want to purchase : ";
                        cin.ignore();
                        getline(cin, searchMedicine);
                        index = searchForMedicine(searchMedicine, fazi, size);

                        if (index != -1)
                        {

                            cout << "\nQuantity should be less than 5!!" << endl;
                            cout << "Enter the quantity : ";
                            cin >> quantity;
                            while (!(cin && quantity > 0 && quantity <= 5))
                            {
                                cin.clear();
                                setColor(12);
                                cout << "Wrong input!! Enter again !!";
                                setColor(7);
                                cout << "\nQuantity should be less than 5!!" << endl;
                                cout << "Enter the quantity : ";
                                cin >> quantity;
                            }
                            // quantity_price[0][j] = quantity;
                            // quantity_price[1][j] = medicinePrice[index] * quantity;

                            setColor(14);
                            cout << "Any other key will result in submission of order!!!";
                            setColor(7);
                            totalPrice += fazi[index].medicinePrice * quantity;

                            fazi[i].quantities = quantity;
                            fazi[i].indices = index;

                            i++;
                            cout << "For more order enter Y : ";
                            cin >> ch;
                        }
                        else
                        {
                            setColor(12);
                            cout << "\n\tMedicine not exists !";

                            setColor(14);

                            cout << "\n\t\tPress any key to continue ......";
                            _getch();
                            setColor(7);
                            break;
                        }
                    } while ((ch == 'Y' || ch == 'y') && i < 10);
                    if (i != 0)
                    {
                        // CNIC_DatePurchase[1][j] = getCurrentDate();
                        printPurchaseList(fazi, size);
                        discountedPrice = (discount * totalPrice) / 100;
                        totalPrice = totalPrice - (totalPrice * discount) / 100;
                        cout << "\n\t\tDiscount : " << discountedPrice;
                        cout << "\n\t\t\tTotal Price : " << totalPrice;
                        // cout << "\n\tDate of purchase : "<< CNIC_DatePurchase[1][j];
                        // soldamounts[j] = totalPrice;
                        totalPrice = 0;
                        discountedPrice = 0;
                        cout << "\nYou will recieve your medicine soon.!";
                        setColor(14);
                        cout << "\n\t\tPress any key to continue ......";
                        _getch();
                        j++;
                        setColor(7);
                    }

                    break;
                case 5:
                    system("cls");
                    printPharmacy();
                    cout << endl
                         << endl;
                    cout << "\t\t  Reviews" << endl;
                    printReviews(fazi, size);

                    reviewMenu();
                    cout << endl
                         << endl
                         << "Enter your choice : ";
                    cin >> reviewinput;
                    reviewinput = validationOfInput(reviewinput, 1, "review");

                    if (reviewinput == 1)
                    {
                        enterReviews(fazi, size);
                        setColor(14);
                        cout << "\n\t\t Review Added successfuly" << endl;
                        cout << "\n\t\tPress any key to continue ......";
                        _getch();
                        setColor(7);
                    }
                    else
                    {
                        setColor(14);
                        cout << "\n\t\tPress any key to continue ......";
                        _getch();
                        setColor(7);
                    }
                    break;
                case 6:
                    system("cls");
                    printPharmacy();
                    contactmenu();
                    cout << endl
                         << endl
                         << "Enter your choice : ";
                    cin >> choiceInput;
                    choiceInput = validationOfInput(choiceInput, 2, "update");
                    if (choiceInput == 1)
                    {
                        whatsapplink();
                        setColor(14);
                        cout << "\n\t\tPress any key to continue ......";
                        _getch();
                        setColor(7);
                    }
                    
                    else if (choiceInput == 2)
                    {
                        instagramlink();

                        setColor(14);
                        cout << "\n\t\tPress any key to continue ......";
                        _getch();
                        setColor(7);
                    }
                    
                    else
                    {
                        setColor(14);
                        cout << "\n\t\tPress any key to continue ......";

                        _getch();

                        setColor(7);

                    }

                    break;

                default:

                    cout << "ivalid!!";

                    break;

                }
            } while (input != 0);

            loginUserType = -10;

            input = -1; // this statment is to make sure that do not exit from outer loop
        }

        else if (loginUserType == -1)
        {
            setColor(12);
            cout << "INVALID CREDENTIALS!!";
            setColor(14);

            cout << endl

                 << "\t\tPress any key to continue ......";

            _getch();

            setColor(7);

        }

    } while (input != 0);




    saveData(fazi, size);
    saveReviews(fazi, size);
    return 0;
}
// this fucntio is used for intger input validaton


int validationOfInput(int input, int n, string menutype)
{
    while (!(cin && input >= 0 && input <= n))
    {
        system("cls");

        cin.clear();
        cin.ignore(100, '\n');
        printPharmacy();
        if (menutype == "first")
            firstPage();
        else if (menutype == "customer")
        {
            customerMenu();
        }
        else if (menutype == "admin")
        {
            adminMenu();
        }
        else if (menutype == "search")
        {
            searchMenuForAdmin();
        }
        else if (menutype == "update")
        {
            updateMenu();
        }
        else if (menutype == "contact")
        {
            contactmenu();
        }
        else if (menutype == "review")
        {

            reviewMenu();
        }
        setColor(12);
        cout << "\nWrong input choose only between 0 and " << n << "!!" << endl
             << endl;
        setColor(7);
        cout << endl
             << endl
             << "Enter your choice : ";
        cin >> input;
        // input=floor(input);
    }
    return input;
}




bool medicineNameValidation(string medicine)
{
    // Check if the string is empty
    if (medicine.empty())
    {
        return false;
    }

    // Check for leading or trailing invalid characters
    if (medicine[0] == ' ' || medicine[0] == '-' ||
        medicine[medicine.length() - 1] == ' ' || medicine[medicine.length() - 1] == '-')
    {
        return false;
    }

    // Validate each character
    for (int i = 0; i < medicine.length(); i++)
    {
        char c = medicine[i];

        // Check for invalid characters
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
              (c >= '0' && c <= '9') || c == ' ' || c == '-'))
        {
            return false;
        }

        // Check for consecutive spaces or hyphens
        if ((c == ' ' || c == '-') && i < medicine.length() - 1)
        {
            if (medicine[i + 1] == ' ' || medicine[i + 1] == '-')
            {
                return false;
            }
        }
    }

    return true;
}




string nameofmedicine(string medicine, string word)
{
    bool valid = medicineNameValidation(medicine);
    while (!valid)
    {
        setColor(12);
        cout << "Wrong input!! Enter name again" << endl
             << endl;
        setColor(7);
        cout << "Enter the " << word << " name  : ";
        // cin.ignore();
        getline(cin, medicine);
        valid = medicineNameValidation(medicine);
    }
    return medicine;
}


bool isdouble(string a)
{
    int dotcount = 0;
    bool isnum = true;
    // Check for empty input
    if (a.empty())
    {
        return false;
    }
    if (a[0] == '.' && a[a.length() - 1] == '.')
    {
        return false;
    }
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '.')
        {
            dotcount++;
        }
        else if (!(a[i] >= '0' && a[i] <= '9'))
        {
            return false; // Invalid character
        }
    }

    // If there's more than one dot, it's not a valid double
    return dotcount <= 1;
}



double stringToDouble(string a)
{
    double result = 0.0;
    double fraction = 0.1;
    bool isdecimal = false;
    for (int i = 0; i < a.length(); i++)
    {
        char c = a[i];
        if (c >= '0' && c <= '9')
        {
            if (isdecimal)
            {
                result += (c - '0') * fraction;
                fraction /= 10;
            }

            else
            {
                result = result * 10 + (c - '0');
            }
        }
        else if (c == '.')
        {
            isdecimal = true;
        }
    }
    return result;
}




double priceValidation(string a)
{
    bool flag = isdouble(a);
    while (!flag)
    {
        setColor(12);
        cout << "Wrong input!! Enter price again" << endl
             << endl;
        setColor(7);
        cout << "\nEnter the price of medicine : ";
        // cin.ignore();
        cin >> a;
        flag = isdouble(a);
    }
    return stringToDouble(a);
}


void initialize(pharmacy fazi[], int size, string variableForinitialize)
{
    string ini = variableForinitialize;
    for (int i = 0; i < size; i++)
    {
        fazi[i].medicines = ini;
    }
}



void initializeintteger(pharmacy fazi[], int size, double assign)
{
    double ini = assign;
    for (int i = 0; i < size; i++)
    {
        fazi[i].medicinePrice = ini;
    }
}




int searchForMedicine(string del, pharmacy fazi[], int size)
{

    for (int i = 0; i < size; i++)
    {
        if (del ==fazi[i].medicines)
        {
            return i;
        }
    }
    return -1;
}



void searchMenuForAdmin()
{
    cout << "\t\t1. Search by name : " << endl;
    cout << "\t\t2. Search by price : " << endl;
    cout << "\t\t3. Search by Expiry date : " << endl;
}




void countForpricesearchindex(pharmacy fazi[], int size, double low, double high, int &count)
{
    count = 0;
    for (int i = 0; i < size; i++)
    {
        if (fazi[i].medicinePrice >= low && fazi[i].medicinePrice <= high)
        {
            count++;
        }
    }
}



int *searchByPrice(pharmacy fazi[], int size, double low, double high, int &count)
{

    count = 0;
    countForpricesearchindex(fazi, size, low, high, count);

    int *priceindex = new int[count];
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (fazi[i].medicinePrice >= low && fazi[i].medicinePrice <= high)
        {
            priceindex[index++] = i;
        }
    }
    return priceindex;
}



void printMedicineByprice(pharmacy fazi[], int size, double low, double high, int &count)
{

    int *priceindex = searchByPrice(fazi, size, low, high, count);
    setColor(14);
    if (count != 0)
    {
        cout << endl
             << setw(20) << "MEDICINE" << setw(15) << "PRICE" << endl
             << endl;
        cout << "____________________________________________________________________" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << setw(20) << fazi[priceindex[i]].medicines << setw(15) << fazi[priceindex[i]].medicinePrice<< endl;
            cout << "____________________________________________________________________" << endl;
        }
        setColor(14);
        cout << "\n\t\tPress any key to continue ......";
        _getch();
        setColor(7);
    }
    else
    {
        setColor(12);
        cout << endl
             << "MEdicine in this range do not exists..." << endl;
        setColor(14);
        cout << "\n\t\tPress any key to continue ......";
        _getch();
        setColor(7);
    }
}




int discountcheck(int discount)
{

    while (!cin && (discount < 100 && discount >= 0))
    {
        cin.clear();
        cin.ignore(100, '\n');
        setColor(12);
        cout << "This is not valid!!Enter again" << endl
             << endl;
        setColor(7);
        cout << "Enter the dicount percentage you want to set : %";
        cin >> discount;
    }
    return discount;
}



void printByName(int index, pharmacy fazi[], int size, int cass)
{
    if (index != -1)
    {
        cout << endl;
        cout << "MEDICINE : " << fazi[index].medicines << endl;
        cout << "PRICE    : " << fazi[index].medicinePrice << endl;
        cout << "EXPIRY DATE : " << fazi[index].expiryDates << endl;
        if (cass == 5)
        {
            setColor(14);
            cout << "\n\t\tPress any key to continue ......";
            _getch();
            setColor(7);
        }
    }
    else
    {
        setColor(12);
        cout << "\nMedicine not exists!!!";
        setColor(14);
        cout << "\n\t\tPress any key to continue ......";
        _getch();
        setColor(7);
    }
}



void updateMenu()
{
    cout << "\n\t\t 1. Change medicine name : ";
    cout << "\n\t\t 2. Change medicine price : ";
    cout << "\n\t\t 3. Change medicine expiry date : ";
}


int countfornv(pharmacy fazi[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (fazi[i].medicines != "nv")
            count++;
    }
    return count;
}



void medicinInventory(pharmacy fazi[], int size)
{
    int count = countfornv(fazi, size);
    if (count > 0)
    {
        setColor(14);

        cout << endl
             << setw(20) << "MEDICINE" << setw(15) << "PRICE" << setw(15) << "Expiry Date" << endl
             << endl;
        cout << "____________________________________________________________________" << endl;
        for (int i = 0; i < size; i++)
        {
            if (fazi[i].medicines != "nv")
                cout << setw(20) << fazi[i].medicines << setw(15) << fazi[i].medicinePrice << setw(15) << fazi[i].expiryDates << endl;
        }
    }
    else
    {
        setColor(12);
        cout << "\n\tInventory is empty!!!";
        setColor(7);
    }
}


bool dateCheck(string date)
{

    if (date.length() != 10)
    {
        return false;
    }
    if (!(date[0] >= '0' && date[0] <= '9' && date[date.length() - 1] >= '1' && date[date.length() - 1] <= '9'))
    {
        return false;
    }
    if (!(date[0] >= '0' && date[0] <= '3' && date[1] >= '0' && date[1] <= '9'))
    {
        return false;
    }
    if ((date[0] == '0' && date[1] == '0') || (date[0] == '3' && date[1] > 1))
    {
        return false;
    }
    if (date[2] != '-')
    {
        return false;
    }
    if (!((date[3] >= '0' && date[3] <= '1' && date[4] >= '0' && date[4] <= '9')))
    {
        return false;
    }
    if ((date[3] == '0' && date[4] == '0'))
    {
        return false;
    }
    if ((date[3] == '1' && date[4] > '2'))
    {
        return false;
    }
    if ((date[5] != '-'))
    {
        return false;
    }
    if (!(date[6] == '2' && date[7] == '0' && date[8] >= '2' && date[8] <= '9' && date[9] >= '0' && date[9] <= '9'))
    {
        return false;

    }


    return true;
}




string expiryDate(string date)
{
    while (!dateCheck(date))
    {
        cin.clear();
        // cin.ignore(100,'\n');
        setColor(12);
        cout << "This is not valid!!Enter again like (26-04-2024)" << endl
             << endl;
        setColor(7);
        cout << "Enter the Expiry date of the medicine (DD-MM-YYYY): ";
        getline(cin, date);
    }
    return date;
}



void searchByDate(pharmacy fazi[], int size, string date)
{
    int count = countfornv(fazi, size);
    cout << endl
         << setw(20) << "MEDICINE" << setw(15) << "PRICE" << setw(15) << "ExpiryDates" << endl
         << endl;
    if (count > 0)
    {
        int dateprint = 0;
        for (int i = 0; i < size; i++)
        {
            if (fazi[i].expiryDates == date)
            {
                cout << endl
                     << setw(20) << fazi[i].medicines << setw(15) << fazi[i].medicinePrice << setw(15) << fazi[i].expiryDates << endl;
                dateprint++;
            }
        }
        if (dateprint > 0)
        {
            setColor(14);
            cout << "\n\t\tPress any key to continue ......";
            _getch();
            setColor(7);
        }
        else
        {
            setColor(14);
            cout << endl
                 << endl
                 << "NO Medicnine found for this date!!";
            cout << "\n\t\tPress any key to continue ......";
            _getch();
            setColor(7);
        }
    }
    else
    {
        setColor(12);
        cout << "\nInventory is empty!!!";
        setColor(14);
        cout << "\n\t\tPress any key to continue ......";
        _getch();
        setColor(7);
    }
}



void contactmenu()
{
    cout << endl
         << endl;
    setColor(11);
    cout << "\t\t  Contact Information" << endl;
    setColor(14);
    cout << "\n\t\tWhatsapp Number = 03064005529";
    cout << "\n\t\tinstagram profile = _fazi_popo";
    setColor(11);
    cout << "\n\n\t If you want to direct contact then chose between the following....";
    setColor(7);
    cout << "\n\t1. Contact on whatsapp ";
    cout << "\n\t2. Contact on instagram ";
    cout << "\n\t0. logout" << endl;
}



void whatsapplink()
{
    string whatsapp_link = "https://wa.me/923064005529?text=Hello%2C%20I%20am%20interested%20in%20your%20services";

    cout << "Click or copy the link to contact us on WhatsApp:\n";
    cout << whatsapp_link << endl;

    // Open the link directly in the default browser
    cout << "Opening WhatsApp in your browser..." << endl;
    string command = "start " + whatsapp_link; // For Windows
    system(command.c_str());
}



void instagramlink()
{
    // The Instagram profile URL
    string instagram_link = "https://instagram.com/_fazi_popo";

    cout << "Opening Instagram profile in your default browser..." << endl;

    // Command to open the link in the default web browser
    string command = "start " + instagram_link; // For Windows
    system(command.c_str());
}


void reviewMenu()
{
    cout << "\n\n\tDo you want to give your review?";
    cout << "\n\t1. Enter Review ";
    cout << "\n\t0. Exit";
}



void printReviews(pharmacy fazi[], int size)
{
    int reviewcount = 0;
    for (int i = 0; i < size; i++)
    {
        if (fazi[i].usernameOfReviews != "nv")
        {
            setColor(11);

            cout << "\n\n"
                 << "Name : " << fazi[i].usernameOfReviews;
            setColor(7);
            cout << "\nReview : " << fazi[i].reviews;
            reviewcount++;
        }
    }
    if (reviewcount == 0)
    {
        setColor(12);
        cout << "\n\tNo Reviews yet!!!";
        setColor(7);
    }
}


void enterReviews(pharmacy fazi[], int size)
{
    int index = checkempty(fazi, size, "nv");

    if (index == -1)
    {
        index = rand() % 10;
    }
    cout << "Enter your name : ";
    cin.ignore();
    getline(cin, fazi[index].usernameOfReviews);
    fazi[index].usernameOfReviews = nameofmedicine(fazi[index].usernameOfReviews, "");

    cout << endl
         << "Give review of atleast 5 letters....";
    cout << "\n\tEnter the reviews : ";

    cin.ignore();
    getline(cin, fazi[index].reviews);
    fazi[index].reviews = reviewsValidation(fazi[index].reviews);
}



bool stringAlphabetscheck(string a)
{
    if (a.empty())
        return false;
    if (a.length() < 5)
        return false;
    bool alphabets = false;
    for (int i = 0; i < a.length(); i++)
    {
        if (!(a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
            alphabets = true;
        else if (a[i] != ' ' && a[i] != '-')
            return false;
    }
    return alphabets;
}


string reviewsValidation(string a)
{
    while (!stringAlphabetscheck(a))
    {
        cin.clear();
        setColor(12);
        cout << "This is not valid!!Enter review again...." << endl
             << endl;
        setColor(7);
        cout << "Enter the reviews : ";
        getline(cin, a);
    }
    return a;
}




void printPurchaseList(pharmacy fazi[],  int size)
{
    setColor(14);
    system("cls");
    printPharmacy();

    cout << endl
         << setw(20) << "MEDICINE" << setw(15) << "PRICE OF ONE" << setw(15) << "Quantity" << setw(15) << "Price" << endl
         << endl;
    cout << "___________________________________________________________________________________" << endl;
    for (int i = 0; i < size; i++)
    {
        if (fazi[i].indices != -1 && fazi[i].quantities != -1)
            cout << setw(20) << fazi[fazi[i].indices].medicines << setw(15) << fazi[fazi[i].indices].medicinePrice << setw(15) << fazi[i].quantities << setw(15) << fazi[i].quantities * fazi[fazi[i].indices].medicinePrice << endl;
        fazi[i].indices = -1;
        fazi[i].quantities = -1;
    }
    cout << "___________________________________________________________________________________" << endl;
}



void initial(pharmacy fazi[], int size, int assign)
{
    double ini = assign;
    for (int i = 0; i < size; i++)
    {
        fazi[i].medicinePrice = ini;
    }
}



bool cnicValid(char *cnic)
{
    if (cnic[0] == '\0')
    {

        return false;
    }
    if (!(cnic[0] >= '1' && cnic[0] <= '5'))
    {
        return false;
    }
    for (int i = 0; cnic[i] != '\0'; i++)
    {
        if (!(cnic[i] >= '0' && cnic[i] <= '9'))
            return false;
    }
    if (strlen(cnic) != 13)
        return false;
    return true;
}



bool saveData(pharmacy fazi[], int size)
{
    ofstream fout;
    fout.open("pharmacy.txt");
    if (!fout)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (fazi[i].medicines != "nv")
            {
                fout << fazi[i].medicines << "," << fazi[i].medicinePrice << "," << fazi[i].expiryDates << endl;
            }
        }
    }
    fout.close();
    return true;
}



bool saveReviews(pharmacy fazi[], int size)
{
    ofstream fout;
    fout.open("user.txt");
    if (!fout)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (fazi[i].usernameOfReviews != "nv")
            {
                fout << fazi[i].usernameOfReviews << "," << fazi[i].reviews << endl;
            }
        }
    }
    fout.close();
    return true;
}


bool loadData(pharmacy fazi[], int size)
{
    ifstream fin;
    int i = 0;
    fin.open("pharmacy.txt");
    if (!fin)
    {
        return false;
    }
    else
    {
        while (i < size && !fin.eof())
        {
            getline(fin, fazi[i].medicines, ',');
            fin >> fazi[i].medicinePrice;
            fin.get();
            getline(fin, fazi[i].expiryDates);
            fin.ignore();
            i++;
        }
    }
    fin.close();
    return true;
}


bool loadReview(pharmacy fazi[], int size)
{
    // Create an input file stream object to read from the file
    ifstream fin;
    int i = 0;

    // Open the file named "user.txt"
    
    fin.open("user.txt");
    if (!fin)
    {
        return false;
    }
    else
    {
        // Loop to read data from the file until the end of the file is reached

        while (!fin.eof())
        {

             // Read the username from the file up to a comma and store it in the arra
            getline(fin, fazi[i].usernameOfReviews, ',');
            getline(fin, fazi[i].reviews);
            fin.ignore();
            i++;
        }
    }
    fin.close();
    return true;
}

// char* cnicNum(char a[]){

//     return a;
// }
// Function to get the current date
// string getCurrentDate() {
//     time_t now = time(0);              // Get the current time
//     tm* localTime = localtime(&now);   // Convert to local time

//     // Extract day, month, asnd year
//     int day = localTime->tm_mday;
//     int month = localTime->tm_mon + 1; // tm_mon is 0-based
//     int year = localTime->tm_year + 1900;

//     // Format the date as DD/MM/YYYY
//     string date = to_string(day) + "/" + to_string(month) + "/" + to_string(year);

//     return date; // Return the formatted date string
// }
// void priceCalculation(string name,string medicine[],int size,double prices[],int quantity,int index){

//     int price = 0;
//     price += prices[index] * quantity;

// }
// bool isInteger(string a) {
//     // Check for empty input
//     if (a.empty()) {
//         return false;
//     }

//     // Check if the string starts with a digit
//     for (int i = 0; i < a.length(); i++) {
//         if (!(a[i] >= '0' && a[i] <= '9')) {
//             return false; // Invalid character
//         }
//     }

//     return true;  // Valid integer
// }
// int stringToInteger(string a){
//     bool integerFlag = isInteger(a);

// }