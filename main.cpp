#include <iostream>
#include <fstream>
#include<string>
#include <iomanip>
#include <bits/stdc++.h> 
#include <string.h>
#include <stdlib.h>
#include <cstdlib> 
#include <stdio.h> 
using namespace std;

//split function
vector<string> split(string str, char delimiter) {
  vector<string> internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;
 
  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }
 
  return internal;
}


int main()
{
	

		// input variables
		string xc;
		string myArray= "\n";
	const int sizearray3 = 500 , sizearray2 = 1000, sizearray1 = 2000;
	string row[sizearray1];
 	string csv[sizearray1];
 	// used To save the filter of "TCP packets only"
 	string filter1[sizearray1];
 	// used To save the filter of "Certain Source IP address"
 	string filter2[sizearray1];
	int i=0, j=0 , y=0, z=2, zz=0 , n=0 ,nn=0;
	int m=0 , cc=0, cc2=0, cc3=0;
	// arrays for comparing, can be replaced with user input
	string protocol1[1]={"TCP"};
	
	string protocol2[1]={"192.168.1.13"};	
//string protocol2[1]={"192.168.1.4"};
/// seq=1 values needed for filtering and spliting
int size = 200;
 string inputt= "Seq=1 ";
  int index = 0, in1=0 , in2=0;
  string seq1[sizearray2];
  string seq1_filter[sizearray2];
  string xc1;
  int se1=0, k1=0;
  string seq1_f[sizearray2];
  	
  string dest_add1[sizearray2];
  	string dest_add0[sizearray2];
  	int in33=0, in3=0 ,i33=0, i3=0;
  	
	int time1=1;
	string Time1_filter[sizearray2];
	string xt1;
	string Time1[sizearray2];
	int	kt0=0;
	
	int fl=2;
	double time_array[sizearray3];
	int st1=0;
	
	int po=2;
	string S_port[sizearray3];
	int op=0;

	int TS1=12, tv1=0;
	string TS1_f[sizearray3];
	
	int y1=0, y11=0;
	string TSV1_filter[sizearray3];
	string TSV1_f[sizearray3];
	string tc1;
	
	int cl1=1,stl1=0;
	long double	TSVAL_SEQ1[sizearray3];
 /// seq=0 values needed for filtering and spliting
	string inputt0= "Seq=0 ";
  int index0 = 0;
  int in11=0, in22=0;
	string seq0[sizearray2];
  string seq0_filter[sizearray2];
  string xc2;
  int se2=0, k2=0;
  string seq2_f[sizearray2];
  
    int time0=1;
	string Time0_filter[sizearray2];
	string xt0;
	string Time0[sizearray2];
	int	kt1=0;
	
     int fl0=2;
	double time0_array[sizearray3];
	int st0=0; 	
	
	int po1=2;
	string S0_port[sizearray3];
	int op0=0;
	
	int TS0=14, tv0=0;
	string TS0_f[sizearray3];
	
	int y0=0, y00=0;
	string TSV0_filter[sizearray3];
	string TSV0_f[sizearray3];
	string tc0;
	
	
int cl0=1,stl0=0;
long double	TSVAL_SEQ0[sizearray3];


	
	
	long double TSVAL_Diff_PC1[sizearray3];
	double TIME_Diff_PC1[sizearray3];
	
	long double TSVAL_Diff_PC2[sizearray3];
	double TIME_Diff_PC2[sizearray3];
	
	
	
	int comp1=0, comp2=0 , comp0=0, com0=0;	
  //------------------------------------------------------------------------------------------------------------//



	ifstream input("C:\\Users\\Haneen\\Desktop\\Final\\PC1.csv");


		if (input.is_open())
		{
			while (!input.eof() && i < 50000 )
			{

				getline(input, row[i]);
				//cout << row[i] << endl;
				xc = row[0];
			
				 	vector<string> col = split(xc, ',');
				 	
					for(int x = 0; x < col.size(); x++){
					
					 //cout << col[x] << endl;
					 csv[j]=col[x];
					 j++;
					}
   						 
				
			}

			input.close();

		}

		else { cout << "error uploading" << endl; }
		
		// I used j-2 one for j++ and one for CSV header
	cout<<"Total number of packets in file = "<< (j-2)/7<<endl<<endl;
	
	//--------------------------------------------------------------------------------//

	
	

	
	// Filter one to only filter TCP packets
	while(y<j)
	{
	//cout<<csv[y]<<endl;
	
	if (csv[y]==protocol1[0])
	{ //cout<< endl<<"yes it is TCP packet "<<endl;
	cc++;
		// to save the whole row data before y=4 the protocol column
		for(int l=4;l>0; l--)
		{
			filter1[n]=csv[y-l];
			//cout<<filter1[n]<<endl;
		n++;
		}
		// to save the whole row data after y=4 the protocol column
		for(int w=0; w<3;w++)
		{
			filter1[n]=csv[y+w];
			//cout<<filter1[n]<<endl;
		n++;
		}
	}	
	y++;
	}
	cout<<"Total number of TCP packets in file = "<< cc<<endl<<endl;
	
	
	//while(m<n)
	//	{
	
	//	cout<<filter1[m]<<endl;
	//	m++;
	//	}
	 
	 
	 // filter2 to only filter the Packets from a certain Ip address , here we assume ip address = 192.168.1.13
	while(z<n)
	{
	
	if (filter1[z]==protocol2[0])
	{ 
		cc2++;
	
		// to save the whole row data before z=2 the protocol column
		for(int l=2;l>0; l--)
		{ 
			filter2[nn]=filter1[z-l];
		//	cout<<filter2[nn]<<endl;
		nn++;
		}
		// to save the whole row data after z=2 the protocol column
		for(int w=0; w<5;w++)
		{
			filter2[nn]=filter1[z+w];
			//cout<<filter2[nn]<<endl;
		nn++;
		}
	
		}
		z=z+7;
	
	} 
	
	cout<<endl<<endl<<"Total number of packets for a certain ip address is  = "<<cc2<<endl<<endl;
	
cout<<"-------------------------------------------------------------"<<endl;

	cout<<"-------------------------------------------------------------"<<endl;
	
	
		//-------------------------------------------------------------------------//	
	

	/// filter Seq=1 and save it to  "seq1" Array


    while (index < size)
    {
        size_t pos = filter2[index].find(inputt); // inputt= "Seq=1 ";
        if (pos != string::npos)
        {
            //cout << filter2[index] << endl;
            in2=index-5;
            seq1[in1]=filter2[in2];
          //cout<<"time is      "<<seq1[in1]<<endl;
			in1++;
            seq1[in1]=filter2[index];
             //cout<<"info is      "<<seq1[in1]<<endl;
            in1++;
            in3=index-3;
            dest_add1[in33]=filter2[in3];
            
            in33++;
            }
              
        index++;
    }
    
	/// filter Seq=0 and save it to  "seq0" Array
	
	
    while (index0 < size)
    {
        size_t pos = filter2[index0].find(inputt0); // inputt0= "Seq=0 ";
        if (pos != string::npos)
        {
            //cout << filter2[index] << endl;
            in22=index0-5;
            seq0[in11]=filter2[in22];
           //cout<<"time is      "<<seq0[in11]<<endl;
			in11++;
            seq0[in11]=filter2[index0];
            //cout<<"info is      "<<seq0[in11]<<endl;
             in11++;
            
            i3=index0-3;
            dest_add0[i33]=filter2[i3];
            
            //cout<<dest_add0[i33]<<endl;
            i33++;
            }
       
        index0++;
    }
	
	//--------------------------------------------------------------------------------------//
	
//	Split seq=1 based on space and save values in array called seq1_f
	while (se1<index){
	
					xc1=seq1[se1];
					//cout<<"xc is"<<xc1<<endl;
					vector<string> seq1_filter = split(xc1,' '); // delimiter as space
				 	
					for(int x = 0; x < seq1_filter.size(); x++){
					
					  seq1_f[k1]=seq1_filter[x];
				
					 k1++;
					 
				}
	
	se1++;
	}
		
	
	/// array to split time based on : delimater
		while (time1<se1){
	
					xt1=seq1_f[time1];
				//	cout<<seq1_f[time1] <<endl;
				vector<string> Time1_filter = split(xt1,':'); 
				 	
					for(int x = 0; x < Time1_filter.size(); x++){
										 
					  Time1[kt0]=Time1_filter[x];
					kt0++;
					
					}
				
	time1=time1+14;
	
	}
	
	
// convert string to long double (time) and save it in array called time_array
while(fl<time1){
    string Numbers= Time1[fl];
    //cout<< "Time 1 is"<<Time1[fl]<<endl; 
    long double value = strtold(Numbers.c_str(), NULL);
        time_array[st1]=value;
        st1++;
        fl=fl+3;
    }
       
     
	
	// save the source port in an array called S_port
	
	while(po<se1){
		
		S_port[op]=seq1_f[po];
		//cout<<S_port[op]<<endl;
		op++;
		po=po+14;
	}
	
// extraxt TSVAL then save it in an array called TS1_f 
	
	while(TS1<se1){
		
		TS1_f[tv1]=seq1_f[TS1];
		//cout<<TS1_f[tv1]<<endl;
		tv1++;
		TS1=TS1+14;
	}
	
	
	
	// split TSVAL=12355 by delimiter as equal=  and save it in TSV1_f
	
		while (y1<TS1){
	
					tc1=TS1_f[y1];
					
					vector<string> TSV1_filter = split(tc1,'='); // delimiter as space
				 	
					for(int x = 0; x < TSV1_filter.size(); x++){
					
					  TSV1_f[y11]=TSV1_filter[x];
				
					 y11++;
					 
				}
	
	y1++;
	}
	
	
	
	
	



	// convert TSVAL string long double value TSVAL
	
	while(cl1<y1){
    string val1= TSV1_f[cl1];
    
    long double temp_val1 = strtold(val1.c_str(), NULL);
        TSVAL_SEQ1[stl1]=temp_val1;
      //  cout<< setprecision(15)<<time0_array[st0]<<endl;
        stl1++;
        cl1=cl1+2;
    } 	
	

	//-------------------------------------------------------------------------------------------------------------------------------------------//

		 
	
//	Split seq=0 based on space and save values in array called  seq2_f

	while (se2<index0){
	
					xc2=seq0[se2];
					
					vector<string> seq2_filter = split(xc2,' '); // delimiter as space
				 	
					for(int x = 0; x < seq2_filter.size(); x++){
					
					 seq2_f[k2]=seq2_filter[x];
					 //cout<<seq2_f[k2]<<endl;
					 k2++;
					}
	
	se2++;
	}
	 
	 
	 
	 /// array to split time based on : delimater and save it in Time0 array
		while (time0<se2){
	
					xt0=seq2_f[time0];
				//	cout<<seq1_f[time1] <<endl;
				vector<string> Time0_filter = split(xt0,':'); 
				 	
					for(int x = 0; x < Time0_filter.size(); x++){
										 
					  Time0[kt1]=Time0_filter[x];
					  //cout<<Time0[kt1]<<endl;
					kt1++;
					
					}
				
	time0=time0+16;
	
	}
	
	 
	 
	 // convert string to long double (time) and save it in array called time0_array
	while(fl0<time0){
    string Numbers0= Time1[fl0];
    //cout<< "Time 1 is"<<Time1[fl0]<<endl; 
    long double value0 = strtold(Numbers0.c_str(), NULL);
        time0_array[st0]=value0;
      //  cout<< setprecision(15)<<time0_array[st0]<<endl;
        st0++;
        fl0=fl0+3;
    } 	
	 


	// extraxt then save the source port in an array called S0_port
	
	while(po1<se2){
		
		S0_port[op0]=seq2_f[po1];
		//cout<<S0_port[op0]<<endl;
		op0++;
		po1=po1+16;
	}
	
	
	// extraxt TSVAL then save it in an array called TS0_f 
	
	while(TS0<se2){
		
		TS0_f[tv0]=seq2_f[TS0];
		//cout<<TS0_f[tv0]<<endl;
		tv0++;
		TS0=TS0+16;
	}
	
	// split TSVAL=12355 by delimiter as equal  and save it in TSV0_f
	
		while (y0<TS0){
	
					tc0=TS0_f[y0];
					
					vector<string> TSV0_filter = split(tc0,'='); // delimiter as space
				 	
					for(int x = 0; x < TSV0_filter.size(); x++){
					
					  TSV0_f[y00]=TSV0_filter[x];
				
					 y00++;
					 
				}
	
	y0++;
	}
	
	// convert TSVAL string into integer TSVAL
	
	while(cl0<y0){
    string val0= TSV0_f[cl0];
   
    long double temp_val0 = strtold(val0.c_str(), NULL);
        TSVAL_SEQ0[stl0]=temp_val0;
     
        stl0++;
        cl0=cl0+2;
    } 	
	
	
	
	
	
	
	
	while(comp1<250){
	comp2=0;
	while(comp2<250)
	{
		if((S_port[comp1]==S0_port[comp2]&&(S0_port[comp2]!="")&&(dest_add1[comp1]==dest_add0[comp2])))
	{
		//cout<<"	They are equal  "<< S_port[comp1] << " and    "<<S0_port[comp2]<<"    dest address  "<<dest_add1[comp1]<< "   AND "<< dest_add0[comp2]<<endl;
		
	
			
		TSVAL_Diff_PC1[comp0]=TSVAL_SEQ1[comp1]-TSVAL_SEQ0[comp2];
		TIME_Diff_PC1[comp0]=time_array[comp1]-time0_array[comp2];
		//cout<<"TSVAL      "<<setprecision(20)<<TSVAL_Diff_PC1[comp0]<< endl;
		//cout<<"TIME      "<<setprecision(20)<<TIME_Diff_PC1[comp0]<< endl;
		
		comp0++;
			
		comp2++;
	}
		else{
			
			comp2++;
		}
	}
	
	comp1++;
	}
	
	//-------------------------------------------------------------------------------//
	//SCALE TSVAL_difference and Time_Difference
	int W=0;
	long double F[sizearray3];
	
	while(W<=comp0)
	{
	
		long double A=TSVAL_Diff_PC1[W];
	if (A>=10)
		{TSVAL_Diff_PC1[W]=(A/10);
		}
		if (TSVAL_Diff_PC1[W]>=100)
		{TSVAL_Diff_PC1[W]=A/1000;
		}	
F[W]=TIME_Diff_PC1[W]-A;

long double B=F[W];
if((B>3||B<-2)&&F[W]!=0)
	{ 
		TSVAL_Diff_PC1[W]=(TSVAL_Diff_PC1[W])/10;	
		F[W]=TIME_Diff_PC1[W]-TSVAL_Diff_PC1[W];
	}
	
	while(F[W]>10||F[W]<=-10&&F[W]!=0)
	{ 		F[W]=(TIME_Diff_PC1[W]-TSVAL_Diff_PC1[W])/10;
		
	}
	if(F[W]>2||F[W]<=-2&&F[W]!=0)
	{ 		F[W]=(TIME_Diff_PC1[W]-TSVAL_Diff_PC1[W])/10;
		
	}
	
	W++;
	
}
	
	
	
	

	for(int iu=0;iu<comp0;iu++){

	cout<<setprecision(20)<<F[iu]<< endl;}
	

	
	

	system("pause");
	return 0;
	
	
	
}

