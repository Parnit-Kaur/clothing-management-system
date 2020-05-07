#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>

using namespace std;

ofstream fout;
ifstream fin;
fstream file; 
        
class clothesinfo
{
        private:
            int q;
                long long price;
            char size[50];
                char name[50],colour[50];
        public:
                void add();
            void viewallclothes();
            void find(char *);
            void cut(char *);
            void update(char *);
        
}cloth;

void clothesinfo::add()
{
        cout<<"               Enter the details of the clothing you want to add:\n\n";
        cout<<"               Name: ";          
        cin>>name;
        cout<<"\n               Size(XS/S/M/L/XL/XXL): ";
        cin>>size;
        cout<<"\n               Colour: ";
        cin>>colour;
        cout<<"\n               Quantity: ";
        cin>>q;
        cout<<"\n               Price(in rupees): ";
        cin>>price;
        fout.write((char*)this,sizeof(*this));
        cout<<"\n               Clothing Added Successfully!";
        fout.close();
}

void clothesinfo::viewallclothes()
{
        fin.read((char*)&cloth,sizeof(cloth));
        while(!fin.eof())
        {
        
                cout<<"\n   "<<name;
                int k=strlen(name);
                int n=k-5;
            for (int i=0;i<22-n;i++)
            {
                cout<<" ";
            }
                cout<<size;
                k=strlen(size);
            n=k-5; 
                for (int i=0;i<18-n;i++)
            {
                cout<<" ";
            }
                cout<<colour;
                k=strlen(colour);
            n=k-5;
                for (int i=0;i<21-n;i++)
            {
                cout<<" ";
            }
                cout<<q;
                int j=0;
                while(q>0)
                {
                        int r=q%10;
                        j++;
                        q=q/10;
                        }
                        if(j>3)
            {   n=j-5;    }
            else
            {   n=5-j;   }
                for (int i=0;i<27-n;i++)
            {
                cout<<" ";
            }
                cout<<price;
                
                fin.read((char*)&cloth,sizeof(cloth));
                }
        fin.close();
}

void clothesinfo::find(char *t)
{
        cout<<"\n\n        Details of the clothing that you searched for:\n\n";
    int counter=0;
    fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
                if(!strcmp(t,name))
            {
                counter++;
                cout<<"        Name:"<<name<<"            Size:"<<size<<"            Colour:";             
                                cout<<colour<<"            Quantity:"<<q<<"            Price(in rupees):"<<price<<endl;
                        }           
            fin.read((char*)this,sizeof(*this));
            }
            if(counter==0)
            {
                cout<<"        Record not found!";
                }
        fin.close();
}

void clothesinfo::cut(char *t)
{
        int counter=0;
        fout.open("NEWCLOTH.dat",ios::out);
    fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
                if(strcmp(t,name))
            {
                fout.write((char*)this,sizeof(*this));
                        }
                        else
                        {
                                counter++;
                        }           
            fin.read((char*)this,sizeof(*this));
            }
            if(counter==0)
            {
                cout<<"\n        Record not found!";
                }
                else
                    cout<<"\n        Clothing Successfuly Removed!";
        fin.close();
        fout.close();
        remove("CLOTH.dat");
        rename("NEWCLOTH.dat","CLOTH.dat");
}

void clothesinfo::update(char *t)
{
        cout<<"        Change the details of clothing:\n\n";
        int counter=0;
    file.read((char*)this,sizeof(*this));
        while(!file.eof())
        {
                if(!strcmp(t,name))
            {
                counter++;
                cout<<"        Name:";
                cin>>name;
                cout<<"        Size(XS/S/M/L/XL/XXL):";
                                cin>>size;
                                cout<<"        Colour:";
                                cin>>colour;
                                cout<<"        Quantity:";
                                cin>>q;
                                cout<<"        Price:";
                                cin>>price;
                file.seekp(file.tellp()-sizeof(*this));
                file.write((char*)this,sizeof(*this));
                        }           
            file.read((char*)this,sizeof(*this));
            }
            if(counter==0)
            {
                cout<<"        Record not found!";
                }
                else
                    cout<<"\n        Clothing Successfuly Updated!";    
        file.close();
}

int main()
{
main:
        system("cls");
        cout<<"\n                                   WELCOME TO CLOTHING MANAGEMENT SYSTEM\n";
        cout<<"                                   =====================================\n";
        cout<<"                                          By-KHUSHI PASSI(CO19334)\n";
        cout<<"                                             NAVJOT KAUR(CO19343)\n";
        cout<<"                                             PARNIT KAUR(CO19344)";
        cout<<"\n\n\n";
        cout<<"                 1.View All Clothes\n\n";
        cout<<"                 2.Add Clothing\n\n";
        cout<<"                 3.Edit Clothing\n\n";
        cout<<"                 4.Remove Clothing\n\n";
        cout<<"                 5.Find Clothing\n\n";
        cout<<"                 6.Exit\n\n";
        cout<<"                 Please Enter Required Option: ";
        int c;
        cin>>c;
        switch(c)
        {
                case 1:
                        system("cls");
                        cout<<"\n                                                   ALL CLOTHES\n";
                        cout<<"                                                   ===========";
                        cout<<"\n\n\n\n";
                        fin.open("CLOTH.dat",ios::in);
                        if(!fin)
            {
                cout<<"\n\nFile Not Found!!!";
            }
            else
            {
                    cout<<"   Name";
                    cout<<"                      Size";
                    cout<<"                    Colour";
                    cout<<"                  Quantity";
                    cout<<"              Price(in rupees)\n";
                                cout<<"  ------------------------------------------------------";
                                cout<<"-----------------------------------------------------------";
        
                cloth.viewallclothes();
                        }
                        getch();
                        goto main;
                        break;
add:            
                case 2:
                        system("cls");
                        char m;
                        cout<<"\n                                            ADD CLOTHING\n";
                        cout<<"                                            ============";
                        cout<<"\n\n\n\n";
                    fout.open("CLOTH.dat",ios::app);
                    cloth.add();
                    getch();
                    cout<<"          Do you want to add more clothing?(y/n)";
                    cin>>m;
                    if((m=='Y')||(m=='y'))
                    {
                        goto add;
                        }
                        goto main;
                        break;
edit:                   
                case 3:
                        char b[50],z;
                        system("cls");
                        cout<<"\n                                            EDIT CLOTHING\n";
                        cout<<"                                            =============";
                        cout<<"\n\n\n\n";
                        cout<<"        Name of the clothing you want to edit:";
                        cin>>b;
                        cout<<"\n\n";
                        file.open("CLOTH.dat",ios::in|ios::out|ios::ate);
                        file.seekg(0);
                        if(!file)
            {
                cout<<"\n\nFile Not Found!!!";
                goto main;
            }
            else
            {
                cloth.update(b);
                        }
                        getch();
                    cout<<"          Do you want to delete more clothing?(y/n)";
                    cin>>z;
                    if((z=='Y')||(z=='y'))
                    {
                        goto edit;
                        }
                        goto main;
                        break;
                        
remove:                 
                case 4:
                        char namme[50],l;
                        system("cls");
                        cout<<"\n                                            REMOVE CLOTHING\n";
                        cout<<"                                            ===============";
                        cout<<"\n\n\n\n";
                        cout<<"        Name of the clothing you want to remove:";
                        cin>>namme;
                        fin.open("CLOTH.dat");
                        if(!fin)
            {
                cout<<"\n\nFile Not Found!!!";
                goto main;
            }
            else
            {
                cloth.cut(namme);
                        }
                        getch();
                        cout<<"          Do you want to remove more clothing?(y/n)";
                    cin>>l;
                    if((l=='Y')||(l=='y'))
                    {
                        goto remove;
                        }
                        goto main;
                        break;
find:                   
                case 5:
                        char namee[50],r;
                        system("cls");
                        cout<<"\n                                            FIND CLOTHING\n";
                        cout<<"                                            ============";
                        cout<<"\n\n\n\n";
                        cout<<"        Name of the clothing you want to find:";
                        cin>>namee;
                        fin.open("CLOTH.dat");
                        if(!fin)
            {
                cout<<"\n\nFile Not Found!!!";
                goto main;
            }
            else
            {
                cloth.find(namee);
                        }
                        getch();
                        cout<<"\n        Do you want to find more clothing?(y/n)";
                    cin>>r;
                    if((r=='Y')||(r=='y'))
                    {
                        goto find;
                        }
                        goto main;
                        break;
exit:                   
                case 6:
                        system("cls");
            cout<<"\n\n\n           Are You Sure, You Want To EXIT (y/n)?";
            char yn;
            cin>>yn;
            if((yn=='Y')||(yn=='y'))
            {
                system("cls");
                cout<<"\n\n\n\n\n\n\n\n                     ";
                            cout<<"******************************* THANKS *******************************";
                getch();
                exit(0);
            }
            else if((yn=='N')||(yn=='n'))
                goto main;
            else
            {
               cout<<"Please Enter Correctly,try again(y/n)";
               goto exit;
            }
            
                default:
                        cout<<"\n\n           Wrong Choice....Please Retry!!!";
                        getch();
                        goto main;
        }       
}

