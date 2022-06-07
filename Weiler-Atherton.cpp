#include <iostream>
#include <cstring>
using namespace std;

struct tocka {
	char ime[3];
	double x;
	double y;
	int lokacija; // 0 outside ; 1 intersection ; 2 inside	
};
int main(){	
	tocka prozor[8]={{"X",8,14,0},{"Y",20,14,0},{"Z",20,2,0},
					 {"W",8,2,0},{"S4",8,4,1},{"S3",8,7,1},
					 {"S2",8,8.5,1},{"S1",8,12.56,1}};
					 
	tocka poligon[10]={{"A",3,12,0},{"S1",8,12.56,1},{"B",12,13,2},
					   {"C",14,10,2},{"S2",8,8.5,1},{"D",6,8,0},
					   {"S3",8,7,1},{"E",14,4,2},{"S4",8,4,1},
					   {"F",3,4,0}};
	tocka rjesenje[5][10];
	int brrjesenja=0;
	int brupisa=0;
	int duljina[5];
	
	for(int i=0;i<9;i++){
		if(poligon[i].lokacija == 0 && poligon[i+1].lokacija == 1 
		   && poligon[i+2].lokacija == 2){
			strcpy(rjesenje[brrjesenja][brupisa].ime,poligon[i+1].ime);
			rjesenje[brrjesenja][brupisa].lokacija =1;
			rjesenje[brrjesenja][brupisa].x = poligon[i+1].x;
			rjesenje[brrjesenja][brupisa].y = poligon[i+1].y;
		
			i=i+2;
			brupisa++;
			while(poligon[i].lokacija == 2){
				strcpy(rjesenje[brrjesenja][brupisa].ime,poligon[i].ime);
				rjesenje[brrjesenja][brupisa].lokacija =2;
				rjesenje[brrjesenja][brupisa].x = poligon[i].x;
				rjesenje[brrjesenja][brupisa].y = poligon[i].y;
				brupisa++;
				i++;
			}
			strcpy(rjesenje[brrjesenja][brupisa].ime,poligon[i].ime);
			rjesenje[brrjesenja][brupisa].lokacija =1;
			rjesenje[brrjesenja][brupisa].x = poligon[i].x;
			rjesenje[brrjesenja][brupisa].y = poligon[i].y;
			
			duljina[brrjesenja]=brupisa+1;
			brrjesenja++;				
			brupisa=0;			
		}
	}
	for (int i=0;i<brrjesenja;i++){
		cout<<i+1<<". RJESENJE: "<<endl;
		for(int j=0;j<duljina[i];j++){
			cout<<"Ime: "<<rjesenje[i][j].ime<<endl;
			cout<<"X"<<j<<": "<<rjesenje[i][j].x<<endl;
			cout<<"Y"<<j<<": "<<rjesenje[i][j].y<<endl;
			cout<<"----------------"<<endl;
		}
		cout<<endl;
	}
	return 0;
}
