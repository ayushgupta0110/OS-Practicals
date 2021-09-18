#include<iostream>
#include<fstream>
using namespace std;

string my_getline(ifstream& fin,string str)
{
    str="";
    char ch;
    fin.read((char*) &ch,sizeof(ch));
    while(ch!='\n' && fin)
    {
        str = str + ch;
        fin.read((char*) &ch,sizeof(ch));
    }
return str;
}

int main()
{
    ifstream fin;
    ofstream fout;
    string input_file,output_file;
    start:
    cout<<"\n Enter the file name for reading: ";
    cin>>input_file;
    fin.open(input_file,ios::in);
    if(!fin)
    {
        cout<<" Error! Can't open file, Please try again..."<<endl;
        goto start;
    }
    cout<<"\n Enter the file name for writing: ";
    cin>>output_file;
    fout.open(output_file,ios::out);
    cout<<"Reading file... "<<endl;
    cout<<"--- Contents of file ---\n"<<endl;
    
    string str;
    while(fin)
    {
        str=my_getline(fin,str);
        cout<<str<<endl;
        fout<<str<<endl;
    }
    cout<<"\n\n File copied successfully..."<<endl;
    fin.close();
return 0;
}
