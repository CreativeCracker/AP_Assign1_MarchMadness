#include <iostream>
#include <fstream>
#include <string>
#include <tr1/unordered_map>

using namespace std;
using namespace std::tr1;

typedef unordered_map <string, string> mer_map;

mer_map *map(const char *file, mer_map *exp){
	cout<<endl<<endl<<endl;
	ifstream f;
	f.open(file);
	string omit;
	getline(f,omit, '\n');

	while(f.good()){
		string key, value;
            //try to read key, if there is none, break
            if (!getline(f, key, ',')) break;
            //read value
            getline(f, value, '\n');
	    
            (*exp)[key] = value;
            cout << key << ":" << value << endl;
	}
	
	f.close();
	return exp;
}

int main(int argc, char *argv[]){

	if(argc<2){
		cout<<"Usage: ./madness [args]"<<endl;
		return -1;
	}

	
	mer_map  mymap,mymap2,mymap3,mymap4;
	
	map("teams.csv", &mymap);
	map("seasons.csv", &mymap2);
	map("tourney_results.csv", &mymap3);
	map("regular_season_results.csv", &mymap4);


	
	cout <<mymap.len()<< endl;
	cout <<mymap2.size()<< endl;
	cout <<mymap3.size()<< endl;
	cout <<mymap4.size()<< endl;


	return 0;
}