#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <stdlib.h>    
#include <time.h>      
#include <random>
#include<cstdlib>


using namespace std;


string fill()
{

int random = 1 + rand() % 10;
int ic = random;
string s = "Ms=";


	for ( int i=0; i <  ic; ++i)
	{
		s.append("Message|" );
	}

return s;
}

int counter_message(string s)
{
	int counter=0 ;

	string str;
	str=s;

	size_t pos=0;
	while (true)
	{
		pos= str.find("Message",pos + 1);
	
		if(pos == std::string::npos )
		{
	
			counter++;
			break;
		}
		else	
		{	
			counter++;
		}
	
	}
	counter--;

	return counter;

}
 
 
int main(int argc,char *argv[])
{
 printf("Number of devices: %s\n",argv[1]);
 //
 int nd=atoi(argv[1]);
 if (nd < 0) nd=1;

 srand((unsigned) time(NULL));
   
 
    map<int, string> traffic;
 
  for (int ii= 0; ii != nd; ++ii) {
    
    string ones=fill();
    traffic.insert(std::make_pair(ii, ones));
 
   } 
    
  
    map<int, string>::iterator itr;
    cout << "\nThe devices after monitoring are : \n";
    cout << "Messages[n]\tID\tELEMENT\n";
    string outs;

    int im = 0;
  
    for (itr = traffic.begin(); itr != traffic.end(); ++itr) {
        
      outs = std::to_string(im);
        cout << '\t' << outs << '\t' << itr->first << '\t' << itr->second << '\n';
        
         im = im + counter_message(itr->second);     
    }
    cout << "and messages at all were : " << std::to_string(im) << '\n';

}

