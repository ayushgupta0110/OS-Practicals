#include<iostream>
#include<sys/stat.h>

using namespace std;

int main(int argc, char **argv)
{
	int i;
	struct stat s;
	if(argc<2)
	{
		cout<<"\n File name missing! Kindly enter File name \n";
		exit(0);
	}
	for(int i=1;i<argc;i++)
	{
		cout<<"\nFile:"<<argv[i]<<"\n";
		if(stat(argv[i],&s)<0)
			cout<<" Error in obtaining stats \n";
		else
		{
			cout<<"Owner UID :";
			cout<<s.st_uid<<"\n";
			
			cout<<"Group ID :";
			cout<<s.st_gid<<"\n";
			
			cout<<"File Mode :";
			cout<<s.st_mode<<"\n";
			
			cout<<"File size :";
			cout<<s.st_size<<"\n";
			
            		cout<<"Permissions: ";
			
		     //for OWNER
		    cout<<((s.st_mode & S_IRUSR)?"r":"-");
		    cout<<((s.st_mode & S_IWUSR)?"w":"-");
		    cout<<((s.st_mode & S_IXUSR)?"x ":"- ");
		    
		    //for (GROUP
		    cout<<((s.st_mode & S_IRGRP)?"r":"-");
		    cout<<((s.st_mode & S_IWGRP)?"w":"-");
		    cout<<((s.st_mode & S_IXGRP)?"x ":"- ");
		        

		    //for OTHERS
		    cout<<((s.st_mode & S_IROTH)?"r":"-");
		    cout<<((s.st_mode & S_IWOTH)?"w":"-");               
		    cout<<((s.st_mode & S_IXOTH)?"x":"-");
		    cout<<endl;

				
		     //ctime converts linux seconds timestamp to Human Understandable time.
		    cout<<"Last Access Time: "<<ctime(&s.st_atime);
		    cout<<"Last Modification Time: "<<ctime(&s.st_mtime);
		    cout<<"Last Status Change: "<<ctime(&s.st_ctime);
		    cout<<"FileSize(Blockwise):"<<s.st_blksize<<"\n";
			
        	}
	}
	return 0;
}
