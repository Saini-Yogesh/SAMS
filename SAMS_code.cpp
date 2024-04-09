#include <bits/stdc++.h>
using namespace std;
class Show
{
public:
    string dateAndTime;
    string title; // Title of Show
    int audinarySeatAvailable;
    int balconySeatAvailable;
    int audinarySeatAvailableForVIP;
    int balconySeatAvailableForVIP;
    int priceAudinarySeat;
    int priceBalconySeat;
    int sales;

    string GetTitle()
    {
        return this->title;
    }
    void SetTitle(string tit)
    {
        this->title = tit;
    }
    int getPriceAudinarySeat()
    {
        return this->priceAudinarySeat;
    }
    void setPriceAudinarySeat(int p)
    {
        this->priceAudinarySeat = p;
    }
    int getPriceBalconySeat()
    {
        return this->priceBalconySeat;
    }
    void setPriceBalconySeat(int p)
    {
        this->priceBalconySeat = p;
    }
    string getDateandTime()
    {
        return this->dateAndTime;
    }
    void setDateandTime()
    {
        time_t tm = time(0);
        this->dateAndTime = ctime(&tm);
    }
    int getAudinarySeatAvailable()
    {
        return this->audinarySeatAvailable;
    }
    void setAudinarySeatAvailable(int s)
    {
        this->audinarySeatAvailable = s;
    }
    int getBalconySeatAvailable()
    {
        return this->balconySeatAvailable;
    }
    void setBalconySeatAvailable(int s)
    {
        this->balconySeatAvailable = s;
    }
    int getAudinarySeatForVIP()
    {
        return this->audinarySeatAvailableForVIP;
    }
    void setAudinarySeatForVip(int s)
    {
        this->audinarySeatAvailableForVIP = s;
    }
    int getBalconySeatForVIP()
    {
        return this->balconySeatAvailableForVIP;
    }
    void setBalconySeatForVIP(int s)
    {
        this->balconySeatAvailableForVIP = s;
    }
    int getSales()
    {
        return this->sales;
    }
    void setSales(int s)
    {
        this->sales = s;
    }
};
class Transaction
{
public:
    string dateOfBooking;
    static long long int id; // Base Transaction Id for us(start from here)
    int id_n;                // Actual Transaction Id(id for Customer)
    string ShowName;         // Show Name of the Movie/Event
    string BySalesPerson;    // Sales Person Name
    int price;               // Price of the ticket

    string getDateOfBooking()
    {
        return this->dateOfBooking;
    }
    void setDateOfBooking()
    {
        time_t tm = time(0);
        this->dateOfBooking = ctime(&tm);
    }
    long long int getId()
    {
        return this->id_n;
    }
    void setId()
    {
        this->id_n = id; // Assign available id to current transaction
        id++;            // After set the id increase the id for next transaction.
    }
    string getShowName()
    {
        return this->ShowName;
    }
    void setShowName(string nm)
    {
        this->ShowName = nm;
    }
    string getSalesPerson()
    {
        return this->BySalesPerson;
    }
    void setSalesPerson(string nm)
    {
        this->BySalesPerson = nm;
    }
    int getPrice()
    {
        return this->price;
    }
    void setPrice(int p)
    {
        this->price = p;
    }
    void PrintTicket()
    {
        cout << "Id                       : " << getId() << endl;
        cout << "Show Name                : " << getShowName() << endl;
        cout << "Booked by Sales Person   : " << getSalesPerson() << endl;
        cout << "Price Paid               : " << getPrice() << endl;
        cout << endl;
    }
};
long long int Transaction::id = 1001; // Base Transaction Id For all Newly Transaction
class SalesPerson
{
public:
    string name;
    string email;
    long long int mobileNumber;
    string address;
    long long int id;
    string password;
    map<int, Transaction> trans; // record Transaction Done by Self
    string getName()
    {
        return this->name;
    }
    void setName(string s)
    {
        this->name = s;
    }
    long long int getmobileNumber()
    {
        return this->mobileNumber;
    }
    void setmobileNumber(long long int n)
    {
        this->mobileNumber = n;
    }
    string getEmail()
    {
        return this->email;
    }
    void setEmail(string e)
    {
        this->email = e;
    }
    string getAddress()
    {
        return this->address;
    }
    void setAddress(string a)
    {
        this->address = a;
    }
    long long int getId()
    {
        return this->id;
    }
    void SetId(long long int id)
    {
        this->id = id;
    }
    string getUserName()
    {
        return this->name;
    }
    void setUserName()
    {
        string usname;
        cout << "Enter new user name : ";
        cin >> usname;
        this->name = usname;
    }
    string getPassWord()
    {
        return this->password;
    }
    void setPassword()
    {
        cout << "Enter new Password : " << endl;
        string Pas;
        cin >> Pas;
        this->password = Pas;
    }

    int bookTicket(int a, Show &s)
    {
        if (a == 1)
        {
            int st = s.getAudinarySeatAvailable(); // Get Current Audinary seats
            if (st)
            {
                s.setAudinarySeatAvailable(st - 1);   // Decreace the number of seats by 1
                int sl = s.getSales();                // get current Sales
                s.setSales(sl + 1);                   // Set  New sales as 1+ old sales
                Transaction t;                        // Make a new Transaction
                t.setId();                            // Set Transaction id
                t.setSalesPerson(this->name);         // Set the Sales person's name
                t.setDateOfBooking();                 // set date of booking
                t.setShowName(s.GetTitle());          // set show name
                t.setPrice(s.getPriceAudinarySeat()); // set Price of Respactive seat
                trans[t.getId()] = t;                 // add the Transaction in sales person's Transaction
                return t.getId();                     // retutn the id for make it Transaction id
            }
            else
            {
                cout << "Not Available" << endl; // if there is no Audinary Seats
                return 0;
            }
        }
        else
        {
            int st = s.getBalconySeatAvailable(); // Get Current Balcony seats
            if (st)
            {
                s.setBalconySeatAvailable(st - 1);   // Decreace the number of seats by 1
                int sl = s.getSales();               // get current Sales
                s.setSales(sl + 1);                  // Set  New sales as 1+ old sales
                Transaction t;                       // Make a new Transaction
                t.setId();                           // Set Transaction id
                t.setSalesPerson(this->name);        // set the Sales person's Name to be same as
                t.setDateOfBooking();                // set date of booking
                t.setShowName(s.GetTitle());         // set show name
                t.setPrice(s.getPriceBalconySeat()); // set price of Respactive seat
                trans[t.getId()] = t;                // add the Transaction in sales person's Transaction
                return t.getId();                    // retutn the id for make it Transaction id
            }
            else
            {
                cout << "Not Available" << endl; // if there is no Balcony Seats
                return 0;
            }
        }
        return 0;
    }
    void cancellation(int TransId, Show &s, int typeOfSeat)
    {
        int st;              // Variable for store Current Seats
        if (typeOfSeat == 1) // for Audinary Seat
        {
            st = s.getAudinarySeatAvailable();  // get Current Audinary Seats
            s.setAudinarySeatAvailable(st + 1); // increase the Current Audinary Seats by one
            int sales = s.getSales();           // Get Current Sales
            s.setSales(sales - 1);              // dercrease the Sales by one
            trans.erase(TransId);               // erase this Transaction id
        }
        else // for Balcony Seat
        {
            st = s.getBalconySeatAvailable();  // get Current Balcony Seats
            s.setBalconySeatAvailable(st + 1); // increase the Current Balcony Seats by one
            int sales = s.getSales();          // Get Current Sales
            s.setSales(sales - 1);             // dercrease the Sales by one
            trans.erase(TransId);              // erase this Transaction id
        }
    }
    void TransactionDone() // Transaction Done By Self
    {
        for (auto d : trans) // Intrate For All Transaction
        {
            d.second.PrintTicket(); // Call For Print Tickets on Each Transaction
        }
    }
    void Ticket(int Trans_id)
    {
        trans[Trans_id].PrintTicket(); // Call For Print Ticket on Perticuler(Trans_id) Transaction
    }
};
class ShowManager
{
public:
    static long long int id;

    void getSalesPersonsList(map<int, SalesPerson> &mp) // Paas the list of Sales Person's by reference
    {
        for (auto data : mp) // Itrating for each Sales Person's
        {
            cout << "Name           : " << data.second.name << endl;         // Print Name of Sales man
            cout << "Email          : " << data.second.email << endl;        // Print mail of Sales man
            cout << "MobileNumber   : " << data.second.mobileNumber << endl; // Print the Mobile NUmber of Sales man
            cout << "Address        : " << data.second.address << endl;      // Print the Address of Sales man
            cout << "Id             : " << data.second.id << endl;           // Print the Id of Sales man
            cout << endl;
        }
    }
    void getShowList(vector<Show> &v) // Paas the list of Shows by reference
    {
        for (auto data : v) // Itrating for each Show
        {
            cout << endl;
            cout << "Title                 : " << data.GetTitle() << endl;                 // Print the title of Show
            cout << "Audinary Seats        : " << data.getAudinarySeatAvailable() << endl; // Print Audinary seats available in that show
            cout << "Balcony seats         : " << data.getBalconySeatAvailable() << endl;  // Print Available Balcony Seats
            cout << "Audinary VIP seats    : " << data.getAudinarySeatForVIP() << endl;    // Print Audinary VIP Seats
            cout << "Balcony VIP seats     : " << data.getBalconySeatForVIP() << endl;     // Print Number of VIP Balcony Seats
            cout << "Audinary Seat Price   : " << data.getPriceAudinarySeat() << endl;     // Print Audinary Seat Price
            cout << "Balcony Seat Price    : " << data.getPriceBalconySeat() << endl;      // Print Balcony Seat price
        }
        cout << endl;
    }
    void setSalesPerson(map<int, SalesPerson> &mp) // Paas the list of Sales Person's by reference for Adding New Sales Person
    {
        string name, email, add; // Types of Data to be Entered
        long long int mobile;    // Type of Data to be Entered
        SalesPerson sp;          // making a new object of class SalesPerson for new Sales Person
        cout << "Enter name of Sales Person            : ";
        cin >> name;
        cout << endl;
        cout << "Enter email of Sales Person           : ";
        cin >> email;
        cout << endl;
        cout << "Enter Mobile Number of Sales Person   : ";
        cin >> mobile;
        cout << endl;
        cout << "Enter address of Sales Person         : ";
        cin >> add;
        cout << endl;
        cout << " SUCCESSFULLY ADDED " << endl;
        sp.setName(name);           // Set name of Sales Person
        sp.setAddress(add);         // Set address of Sales Person
        sp.setEmail(email);         // Set mail of Sales Person
        sp.SetId(id);               // Set ID of Sales Person
        sp.setmobileNumber(mobile); // Set mobile number of Sales Person
        mp[id] = sp;                // Adding Sales Person in the given List
        id++;                       // increase the base id of Sales Person's
    }
    void setShowList(vector<Show> &v) // Paas the list of Shows by reference for Adding New Show
    {
        Show new_show;                                    // making a new object of class Show for new Show
        string title;                                     // Title of Show
        int Aud, Bal, AudVIP, BalVIP, PriceAud, PriceBal; // Types of Seats
        cout << "Enter Title of The Show                      : ";
        cin >> title;
        cout << endl;
        cout << "Enter Number of Gernal Audinary Seats        : ";
        cin >> Aud;
        cout << endl;
        cout << "Enter Number of Gernal balcony Seats         : ";
        cin >> Bal;
        cout << endl;
        cout << "Enter Number of VIP Audinary Seats           : ";
        cin >> AudVIP;
        cout << endl;
        cout << "Enter Number of VIP Balcony Seats            : ";
        cin >> BalVIP;
        cout << endl;
        cout << "Enter Price for Audinary Seat for the show   : ";
        cin >> PriceAud;
        cout << endl;
        cout << "Enter Price for Balcony Seat for the show    : ";
        cin >> PriceBal;
        cout << endl;
        cout << " SUCCESSFULLY ADDED " << endl;
        new_show.SetTitle(title);                // Set the title of new show
        new_show.setAudinarySeatAvailable(Aud);  // set the number of Audinary Seats
        new_show.setBalconySeatAvailable(Bal);   // Set the number of Balcony Seats
        new_show.setAudinarySeatForVip(AudVIP);  // Set the number of VIP Audinary Seats
        new_show.setBalconySeatForVIP(BalVIP);   // Set the number of VIP Balcony Se
        new_show.setSales(0);                    // Set Sales to zero as no one has booked yet
        new_show.setPriceAudinarySeat(PriceAud); // Set the price of Audinary Seats
        new_show.setPriceBalconySeat(PriceBal);  // Set the price of Balcony Seats
        new_show.setDateandTime();               // Set Date and Time
        v.push_back(new_show);                   // Adding the new show in list of shows
    }
    void FireSalesPerson(long long int id, map<int, SalesPerson> &MP) // Paas the list of Sales Person's by reference for Fire Sales Person
    {
        MP.erase(id); // Erase the id of sales person from list
    }
    void AllTransactions(map<int, SalesPerson> &mp) // Paas the list of Sales Person's by reference for Check All Transaction
    {
        for (auto data : mp) // Itrate for each Sales Person's Account
        {
            data.second.TransactionDone(); // Call to Sales Person for print All Transaction
        }
    }
};
long long int ShowManager::id = 7893; // Base Id for all Newly added Sales Person's
class Data
{
public:
    int id;   // id of Sales Person
    int T_Id; // Transaction Id of Customer
    int ind;  // Serial Number of Show From The Show List
    int st;   // seat type
};
int main()
{

    cout << "*****************************************************************************" << endl;
    cout << "                   STUDENT AUDITORIUM MANAGEMENT SYSTEM                      " << endl;
    cout << "*****************************************************************************" << endl
         << endl;

    ShowManager s;                // Show Manager
    vector<Show> ShowList;        // Shows List
    map<int, SalesPerson> SPList; // Sales Persones List
    map<string, Data> users;      // User Log In System
    int a;                        // Choice Taking From User
    while (true)
    {
        cout << "--------------------------------HOME PAGE--------------------------------------" << endl
             << endl;
        cout << "Input As:" << endl;
        cout << 1 << ". Show Manager" << endl;
        cout << 2 << ". Sales Person" << endl;
        cout << 3 << ". Spectator" << endl;
        cout << 4 << ". Exit" << endl
             << endl;

        cout << "Enter your role (1/ 2/ 3/ 4): ";
        cin >> a;
        if (a == 4) // Exit from Portal
        {
            cout << endl
                 << "Quiting...." << endl;
            break;
        }
        else if (a > 4) // invalid Choice
        {
            cout << endl
                 << "Enter your Choice again" << endl;
            continue;
        }
        else // Loading To enter the Portal
        {
            cout << endl
                 << "loading ..." << endl;
        }
        if (a == 1)
        {
            while (true)
            {
                cout << endl
                     << "--------------------SHOW MANAGER PORTAL------------------------------" << endl
                     << endl;
                int b;
                cout << 1 << ". Get Sales Person List" << endl;
                cout << 2 << ". Add new Sales Person" << endl;
                cout << 3 << ". Fire Sales Person" << endl;
                cout << 4 << ". Get Show List" << endl;
                cout << 5 << ". Add new Show" << endl;
                cout << 6 << ". All transactions Till Now" << endl;
                cout << 7 << ". Log Out" << endl
                     << endl;
                cout << "Enter your choice : ";
                cin >> b; // Taking your choice
                cout << endl;

                if (b == 1) // For gatting Sales Person's list
                {
                    s.getSalesPersonsList(SPList); // Call For gatting Sales Person's list
                }
                else if (b == 2) // For adding new Sales Person's
                {
                    s.setSalesPerson(SPList); // Call For adding new Sales Person's
                }
                else if (b == 3) // For fire the sales person from the system
                {
                    cout << endl;
                    cout << "Enter Sales Persones id : ";
                    int Enter_Sales_Persones_id;
                    cin >> Enter_Sales_Persones_id;
                    cout << endl;
                    s.FireSalesPerson(Enter_Sales_Persones_id, SPList); // Call For fire the sales person
                    cout << "Sales Person is Fired............." << endl;
                    cout << endl;
                }
                else if (b == 4) // For gatting Show List
                {
                    s.getShowList(ShowList); // Call For gatting Show List
                }
                else if (b == 5) // For Add new Show
                {
                    s.setShowList(ShowList); // Call For Add new Show
                }
                else if (b == 6) // For Check All Transactions Till Now
                {
                    s.AllTransactions(SPList); // Call For Check All Transactions Till Now
                }
                else if (b == 7) // Logout Option
                {
                    break; // Exit From the Manager Portal
                }
                else // Invalid Option
                {
                    cout << "Invalid Option! Please try again." << endl;
                    break; // if you enter any other number then it will go to the main Page
                }
            }
        }
        else if (a == 2)
        {
            cout << endl
                 << "----------------------SALES PERSON PORTAL---------------------------" << endl
                 << endl;
            int id;
            cout << "Enter your id for login : ";
            cin >> id;
            cout << endl;
            if (SPList.find(id) == SPList.end()) // Checking Id from the Sales Person's list
            {
                cout << "Invalid id" << endl; // Sales Person does not Exist
            }
            else
            {
                cout << "logging in...." << endl;
                while (true)
                {
                    int c;
                    cout << 1 << ". Set new User Name" << endl;
                    cout << 2 << ". Set new Password" << endl;
                    cout << 3 << ". Transactions done" << endl;
                    cout << 4 << ". Log Out" << endl
                         << endl;
                    cout << "Enter Your Choice : ";
                    cin >> c; // Taking your choice
                    cout << endl;
                    if (c == 1) // For Set new User Name
                    {
                        SPList[id].setUserName(); // Call For Set New UserName
                    }
                    else if (c == 2) // For Set new Password
                    {
                        SPList[id].setPassword(); // Call For Set New Password
                    }
                    else if (c == 3) // For Transactions done By Self
                    {
                        SPList[id].TransactionDone(); // Call For Check All Trasnsication Done By Self
                    }
                    else // Invalid or Logout Option
                    {
                        break; // Invalid Option or Logout
                    }
                }
            }
        }
        else if (a == 3)
        {
            cout << endl
                 << "------------------------SPECTATOR PORTAL-------------------------------" << endl
                 << endl;
            cout << "Enter Username : ";
            string userName;
            cin >> userName; // Taking UserName From User
            cout << endl;
            if (users.find(userName) == users.end()) // checking User Exist in the DataBase
            {
                Data dt;
                dt.T_Id = -1;         // If Not Exist Then Set T_Id As -1 Menas No Transication Till Now
                users[userName] = dt; // Enter The New User in Data base With T_Id=-1
            }
            cout << "Enter Password : ";
            string Password;
            cin >> Password; // Taking Password From User
            cout << endl
                 << "logging in ..." << endl;
            cout << endl;
            while (true)
            {
                int d;
                cout << 1 << ". Show My bookings" << endl;
                cout << 2 << ". check shows" << endl;
                cout << 3 << ". book show" << endl;
                cout << 4 << ". cancell ticket" << endl;
                cout << 5 << ". Log out" << endl
                     << endl;
                cout << "Enter Your Choice : ";
                cin >> d; // Taking your choice
                cout << endl;
                if (d == 1) // For check Your Bookings
                {
                    int tid = users[userName].T_Id; // Gatting T_id Of User
                    if (tid == -1)                  // If  User Haven't any transaction till now then
                    {
                        cout << "--------------------------------------------------------" << endl;
                        cout << "|                You have No booking !!!               |" << endl;
                        cout << "--------------------------------------------------------" << endl;
                        cout << endl;
                    }
                    else
                    {
                        int id = users[userName].id;    // Gatting Id of Booked Show
                        int tid = users[userName].T_Id; // Gatting T_Id of booked Show
                        SalesPerson sw = SPList[id];    // Gatting SalesPerson Id From Our DataBase
                        sw.Ticket(tid);                 // Call to Sales Person For Printing Tickets Of user
                    }
                }
                else if (d == 2) // For Checking Show Schedules
                {
                    for (int i = 0; i < ShowList.size(); i++) // Itrate for eaxh Show
                    {
                        Show so = ShowList[i];                   // Gatting Show
                        string title = so.GetTitle();            // Gatting title of Show
                        string time = so.getDateandTime();       // Gatting Date And Time of Show
                        int Aud = so.getAudinarySeatAvailable(); // Gatting Available Audinary Seats
                        int Bal = so.getBalconySeatAvailable();  // Gatting  Available Balcony Seats
                        int pa = so.getPriceAudinarySeat();      // Gatting Price Of Each Audinary Seat
                        int pb = so.getPriceBalconySeat();       // Gatting Price Of Each Balcony Seat
                        cout << endl;
                        cout << "Show Number              : " << i + 1 << endl; // Print Show Number
                        cout << "Title                    : " << title << endl; // Print Title of Show
                        cout << "Audinary Seats Available : " << Aud << endl;   // Print Audinary Seats Available
                        cout << "Balcony Seats Available  : " << Bal << endl;   // Print Available Balcony Seats
                        cout << "Price Audinary Seat      : " << pa << endl;    // Print Price Of Each Audinary Seat
                        cout << "Price Balcony Seat       : " << pb << endl     // Print Price Of Each Balcony Seat
                             << endl;
                    }
                }
                else if (d == 3) // For Book Show
                {
                    if (ShowList.size() == 0) // Checking Show Availability
                    {
                        cout << "No Shows available" << endl; // No Show Available
                    }
                    else
                    {
                        cout << "Choose Show from the list : ";
                        int ind;                           // Chose the index of Show From the List
                        cin >> ind;                        // Taking index as input
                        int sz = SPList.size();            // gatting Size of SaleSPerson List
                        int id = rand() % (sz) + 7893;     // Gatting raandom Sales Person's Id
                        int st;                            // Seat Type
                        cout << 1 << ". Audinary" << endl; // type of seat
                        cout << 2 << ". Balcony" << endl;  // type of seat
                        cout << "Choose seat type : ";     // Choosing The Type of seat
                        cin >> st;                         // Taking input for type of seat
                        cout << endl;
                        int T_Id = SPList[id].bookTicket(st, ShowList[ind - 1]); // booking ticket by calling function of SalesPerson and Gattign T_id
                        if (T_Id)                                                // If we get a valid T_id
                        {
                            users[userName].T_Id = T_Id;   // Set the T_Id in DataBase for User
                            users[userName].id = id;       // Set the id of SalesPersonin DataBase for keep Tracking individual Sales
                            users[userName].st = st;       // Set the seat type of user
                            users[userName].ind = ind - 1; // Set the index of show for user
                            cout << "Booking........." << endl;
                            cout << "--------------------------------------------------------" << endl;
                            cout << "|         Congrats!!!! Booking Confirmed.               |" << endl;
                            cout << "--------------------------------------------------------" << endl
                                 << endl;
                            cout << "Your Ticket" << endl;
                            SPList[id].Ticket(T_Id); // Print the Booked Ticket
                        }
                        else // if seat is not avilable then it will ask to choose another one
                        {
                            cout << "Sorry !! the service you are looking for is not available currently." << endl;
                        }
                    }
                }
                else if (d == 4) // Cancel Ticket
                {
                    int tid = users[userName].T_Id; // Gatting T_Id Of User
                    if (tid == -1)                  // -1 means you have No booking
                    {
                        cout << "--------------------------------------------------------" << endl;
                        cout << "|                You have No booking !!!               |" << endl;
                        cout << "--------------------------------------------------------" << endl;
                        cout << endl;
                    }
                    else
                    {
                        Show sw = ShowList[users[userName].ind]; // get Show Type
                        int idu = users[userName].id;            // get id of Sales Person
                        int stp = users[userName].st;            // get seat type of Sales Person
                        SPList[idu].cancellation(tid, sw, stp);  // cancaling the Ticket
                        users[userName].T_Id = -1;               // set the Transication Id = -1 means No Booking!
                        cout << " Cancelling ......" << endl;
                        cout << "Cancelled" << endl;
                        cout << "we will initiate the refund process within 24 hrs acoording to our refund policy." << endl;
                    }
                }
                else if (d == 5) // For Logout
                {
                    break; // Logout From Spectator  Portal
                }
                else // incase of Invalid Option
                {
                    cout << endl
                         << "Invalid Option! Please Enter Again." << endl;
                }
            }
        }
    }
}
