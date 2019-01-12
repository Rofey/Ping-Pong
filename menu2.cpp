class menu{
	public:
		virtual int execution()=0;
		virtual void option2() = 0;
		virtual int option3() = 0;
};

class console:public menu{
	private:
		char choice;
	public:
		console()
		{
		}
		
		int menu_lauch()
		{
			
				system("tput clear");
			cout<<setw(30)<<"WELCOME TO THE MENU :"<<endl<<endl;
			for(int i=0;i<150000000;++i)
			{}
				
				cout<<left<<setw(30)<<"1 TO START PLAYING :"<<endl<<endl;
				for(int i=0;i<150000000;++i)
			{
		}
				cout<<setw(30)<<"2 TO VIEW YOUR PREVIOUS RECORDS  :"<<endl<<endl;
				for(int i=0;i<150000000;++i)
			{}
			
				cout<<setw(30)<<"3 TO EXIT FROM MENU :"<<endl<<endl;
				
				choice=getchar();

				if(choice=='1'||choice=='2'||choice==3)
				{
					return choice;
				}
				else {
					cout << "\n\nInvalid Option!\n\n";
					menu_lauch();
				}
		}
		
		int option1()
		{
			system("tput clear");		//unistd library
			//HERE YOU WILL CALL YOUR FUNCTION AFTER INCLUDING THE HEADER FILE:
			return 1;
			//YOUR SCORE OF THE FIRST GAME :
			/*SAVE IT IN THIS VARIABLE*///	DUMMY SCORE TO TEST FILLING;
		}
		void option2()
		{
			system("tput clear");
			static int counter=0;
			string line;
			fstream file("score.txt",ios::in);
			cout<<left<<setw(40)<<"YOUR SCORES WERE KEPT AS RECORDS "<<endl;
			cout<<left<<setw(40)<<"FOLLOWING ARE YOUR SCORES :"<<endl<<endl;
			cout<<setw(40)<<"S.NO"<<setw(50)<<"SCORES"<<endl<<endl;
			while(getline(file,line))
			{
				cout<<setw(40)<<++counter<<setw(50)<<line<<endl;
			}
			file.close();
			
		}
		int option3()
		{
			system("tput clear");	
			cout<<endl<<setw(20)<<"THANKING YOU FOR PLAYING THE GAME PLS SUPPORT OUR WORK AT GITHUB.COM "<<endl;
			cout<<endl<<setw(20)<<"MANY MANY HAPPY RETURNS OF THE DAY "<<endl;
			cout<<endl<<setw(50)<<"PROJECT MEMBERS :"<<endl<<setw(50)<<"          RAFAY BIN MARIF"<<"\n          MUBASHIR AHMED "<<endl<<setw(50)<<"          ZUBAIR ASLAM"<<endl;
			system("pause");
			//return 0;
		}
		int execution()
		{
			choice=menu_lauch();

			while(1)
			{
			
			if(choice=='1')
			{
				int a = option1();
				return 1;
				//system("pause");
			}
			else if(choice=='2')
			{
				return 2;
				//system("pause");
			}
			else if(choice=='3')
			{
				return 3;
				break;
			}
		}
		}
	
};