#include <iostream>
using namespace std;
struct specialization
{
    string s1, s2, s3, s4, s5, s6;
    string st1, st2, st3, st4, st5, st6 = "";
};
void disply_menu();
void Hospital_System();
int Choose();
void Add_new_patient(struct specialization *);
void display_all_patients(struct specialization *);
void Get_next_patient(struct specialization*);
int main()
{
    Hospital_System();
}
void  Hospital_System()             // main function of  Hospital_System project
{
    int quit = 0, c = 0;
    struct  specialization spe[20];
    do
    {
        c = 0;
        disply_menu();
        do
        {
            switch (Choose())
            {
            case 1:
                Add_new_patient(spe);                   // function 1 of Add new ptient 
                c = 0;
                break;
            case 2:
                display_all_patients(spe);              // function 2 of display all patients
                c = 0;
                break;
            case 3:
                Get_next_patient(spe);                  // function 3 of Get next patient to Doctor
                c = 0;
                break;
            case 4:
                quit++;                                 // function 4 of Exit progect
                c = 0;
                break;
            default:                                    // Error in Enter number of operation in Rang      
                cout << "Out of Rang !!! \nPlease Enter number of operation from rang ( 1 to 4 ) :\n";
                c = 10;
            }

        } while (c > 0);

    } while (quit == 0);
}
void disply_menu()
{
    cout << "Enter Your Choice :\n";
    cout << "1) Add new patient    Enetr ----> 1\n";
    cout << "2) print all patients Enetr ----> 2\n";
    cout << "3) Get next patient   Enetr ----> 3\n";
    cout << "4) Exit program       Enetr ----> 4\n\n";
}
int Choose()
{
    int num = 0;
    cout << "Please Enter number of operation : ";
    cin >> num;
    cout << "\n\n";
    return num;
}
void Add_new_patient(struct specialization *spe)
{
    int sep1,c1=0,c2=0,statis;
    string s;
    cout << "Please Enter data of new patient :\n";
    while (true)
    {
        cout << "Enter Specialization of patient (1 to 20) : ";
        cin >> sep1;
        if (sep1>=1&&sep1<=20)
            break;
        else
        {
            cout << "\n\nOut of Rang !!!.. \n\n";
        }
    }
    cout << "Enter Name of patient                     : ";
    cin >> s;
    while (true)
    {
        cout << "Enter statis of patient(0_1)              : ";
        cin >> statis;
        cout << "\n\n";
        if (statis == 0 || statis == 1)
            break;
        else
        {
            cout << "Out of Rang !!!.. \n\n";
        }
    }

    if (statis == 0)
    {
        if (spe[sep1 - 1].s1 == "")
        {
            spe[sep1 - 1].s1 = s;
            spe[sep1 - 1].st1 = "regular";
        }
        else if (spe[sep1 - 1].s2 == "")
        {
            spe[sep1 - 1].s2 = s;
            spe[sep1 - 1].st2 = "regular";
        }
        else if (spe[sep1 - 1].s3 == "")
        {
            spe[sep1 - 1].s3 = s;
            spe[sep1 - 1].st3 = "regular";
        }
        else if (spe[sep1 - 1].s4 == "")
        {
            spe[sep1 - 1].s4 = s;
            spe[sep1 - 1].st4 = "regular";
        }
        else if (spe[sep1 - 1].s5 == "")
        {
            spe[sep1 - 1].s5 = s;
            spe[sep1 - 1].st5 = "regular";
        }
        else
        {
            cout << "sorry we can't add more patient for this specialization\n\n";
        }
    }
    else
    {
        if (spe[sep1 - 1].s5 != "")
        {
          cout << "sorry we can't add more patient for this specialization\n\n";
        }
        else
        {
            spe[sep1 - 1].s5 = spe[sep1 - 1].s4;
            spe[sep1 - 1].st5 = spe[sep1 - 1].st4;
            spe[sep1 - 1].s4 = spe[sep1 - 1].s3;
            spe[sep1 - 1].st4 = spe[sep1 - 1].st3;
            spe[sep1 - 1].s3 = spe[sep1 - 1].s2;
            spe[sep1 - 1].st3 = spe[sep1 - 1].st2;
            spe[sep1 - 1].s2 = spe[sep1 - 1].s1;
            spe[sep1 - 1].st2 = spe[sep1 - 1].st1;
            spe[sep1 - 1].s1 =s;
            spe[sep1 - 1].st1 = "urgent";
        }
    }
}
void display_all_patients(struct specialization *spe)
{
    int c = 0,c1=0;
    for (int i = 0; i < 20; i++)
    {
         c = 0;
         if (spe[i].s1 != "")
         {
             c++;
         }
         if (spe[i].s2 != "")
         {
             c++;
         }
         if (spe[i].s3 != "")
         {
             c++;
         }
         if (spe[i].s4 != "")
         {
             c++;
         }
         if (spe[i].s5 != "")
         {
             c++;
         }

         if (c > 0)
         {

             cout << "There are " << c << " patient in specialization :" << i + 1 << endl;
              if (c == 1)
              {
                 cout << spe[i].s1 << " " << spe[i].st1 << endl;
              }
              else if (c == 2)
              {
                  cout << spe[i].s1 << " " << spe[i].st1 << endl;
                  cout << spe[i].s2 << " " << spe[i].st2 << endl;
              }
              else if (c == 3)
              {
                  cout << spe[i].s1 << " " << spe[i].st1 << endl;
                  cout << spe[i].s2 << " " << spe[i].st2 << endl;
                  cout << spe[i].s3 << " " << spe[i].st3 << endl;
              }
              else if (c == 4)
              {
                  cout << spe[i].s1 << " " << spe[i].st1 << endl;
                  cout << spe[i].s2 << " " << spe[i].st2 << endl;
                  cout << spe[i].s3 << " " << spe[i].st3 << endl;
                  cout << spe[i].s4 << " " << spe[i].st4 << endl;
              }
              else if (c == 5)
              {
                  cout << spe[i].s1 << " " << spe[i].st1 << endl;
                  cout << spe[i].s2 << " " << spe[i].st2 << endl;
                  cout << spe[i].s3 << " " << spe[i].st3 << endl;
                  cout << spe[i].s4 << " " << spe[i].st4 << endl;
                  cout << spe[i].s5 << " " << spe[i].st5 << endl;
              }

              cout << endl;
         }
         else
         {
             c1++;
         }
    }
    if (c1 == 20)
    {
        cout << "\nNo patients at the moment  in any specialization  for print them \n\n";
    }
}
void Get_next_patient(struct specialization* spe)
{
    int num_spe=0;
    cout << "Enetr specialization : ";
    cin >> num_spe;
    if (spe[num_spe - 1].s1 == "")
    {
        cout << "No patients at the moment in specialization : " << num_spe << "\nHave rest . Doctor\n\n ";
    }
    else
    {
        cout << spe[num_spe - 1].s1 << " please go with the Doctor\n\n";
        spe[num_spe - 1].s1 = spe[num_spe - 1].s2;
        spe[num_spe - 1].st1 = spe[num_spe - 1].st2;

        spe[num_spe - 1].s2 = spe[num_spe - 1].s3;
        spe[num_spe - 1].st2 = spe[num_spe - 1].st3;
        
        spe[num_spe - 1].s3 = spe[num_spe - 1].s4;
        spe[num_spe - 1].st3 = spe[num_spe - 1].st4;
        
        spe[num_spe - 1].s4 = spe[num_spe - 1].s5;
        spe[num_spe - 1].st4 = spe[num_spe - 1].st5;
        
        spe[num_spe - 1].s5 = spe[num_spe - 1].s6;
        spe[num_spe - 1].st5 = spe[num_spe - 1].st6;

    }
}