// generate algorithm example
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <fstream>
#include <string>

using namespace std;
// function generator:
int RandomNumber () {
    return (rand()%100); 
}

template <typename A>
vector<A> input (int tam){
    vector<A> myvector (tam);
    generate (myvector.begin(), myvector.end(), RandomNumber);
    return myvector;
}

template <typename C>
float DisEu(vector<C> vec1, vector<C> vec2, int tam){
    int temp=0;
    for(int i=0; i<tam;i++){
        temp += pow(vec1[i]-vec2[i],2);
    }
    return sqrt(temp);
}

template <typename B>
void output(vector <float> vecdist,int tam, int it, string nom ){
    map<float, float> fin;
    for (int i = 0; i < it; i++){
            if (fin.find(vecdist[i]) == fin.end()) 
                fin[vecdist[i]] = 1;
            else 
                fin[vecdist[i]]++;
        }
    ofstream file;

    
    file.open(nom + ".csv");
    file << "Distancias,Cantidad de repeticiones"<<endl;
    for (auto& its : fin){
            file << its.first << "," << its.second << endl;
        }
    file.close();
}
vector<float> llenarvec(int it,int tam, vector<int> vec1){
	vector <float> vecdist;
	for(int i=0;i<it;i++){
		vector<int> vec2 = input<int>(tam);
		vecdist.push_back(DisEu<int>(vec1,vec2,tam));
	}
	sort(vecdist.begin(), vecdist.end(), greater<float>());
	return vecdist;
}

void iniciar(int tam,int it, string nom){
    vector<int> vecx (tam);
	vector<float> vecdist;
    vecx = input<int>(tam);//vector 1
	vecdist = llenarvec (it,tam,vecx);
	output<int>(vecdist, tam, it,nom);
}


int main () {
    srand ( unsigned ( time(0) ) );
    iniciar(10,10000,"10 x 10000");
    iniciar(20,10000,"20 x 10000");
    iniciar(20,10000,"30 x 10000");
    iniciar(30,10000,"40 x 10000");
    iniciar(40,10000,"50 x 10000");
    
    iniciar(10,20000,"10 x 20000");
    iniciar(20,20000,"20 x 20000");
    iniciar(30,20000,"30 x 20000");
    iniciar(40,20000,"40 x 20000");
    iniciar(50,20000,"50 x 20000");

    iniciar(10,30000,"10 x 30000");
    iniciar(20,30000,"20 x 30000");
    iniciar(30,30000,"30 x 30000");
    iniciar(40,30000,"40 x 30000");
    iniciar(50,30000,"50 x 30000");
    
    iniciar(10,40000,"10 x 40000");
    iniciar(20,40000,"20 x 40000");
    iniciar(30,40000,"30 x 40000");
    iniciar(40,40000,"40 x 40000");
    iniciar(50,40000,"50 x 40000");
    
    iniciar(10,50000,"10 x 50000");
    iniciar(20,50000,"20 x 50000");
    iniciar(30,50000,"30 x 50000");
    iniciar(40,50000,"40 x 50000");
    iniciar(50,50000,"50 x 50000");
   
  return 0;
}