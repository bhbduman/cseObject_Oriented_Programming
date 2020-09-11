#include<iostream>
#include"GTUVEC.h"
#include"GTUVEC.cpp"
#include "GTUSet.h"
#include "GTUSet.cpp"
#include "GTUIT.h"
#include "GTUIT.cpp"
#include"GTUContainer.cpp"
#include <exception>
bool ifmod3equal2(int i){
    return ((i%3)==2);
}
void multiply2(int k){
     cout<<" "<<2*k;
}
//using namespace std;
using namespace BHB;
int  main(){
    /*my global functions are in the gtu container cpp also i have a deleter function for shared ptrs*/
   cout<<"_____________________________TEST FOR SET AND ITERATORCLASSES__________________________________\n";
    GTUSet<char> set1;
    cout<<"GTUSet default constructor has called it allocate a place but still the size is 0\n";
    GTUSet<int> set2;
    GTUSet<int> set3;
    GTUSet<int> set6;

    cout<<"insert function for set2\n";
    set2.insert(3);
    set2.insert(2);
    set2.insert(5);
    set2.insert(7);
    set2.insert(8);
    set2.insert(9);
    for (int i = 0; i < set2.size(); i++)
        cout<<*(set2.getadr().get()+i)<<endl;   
    cout<<"empty function for set2\n"<<
    set2.empty()<<endl;
    cout<<"size function for set2\n"<<
    set2.size()<<endl;
    cout<<"max_size function for set2 \n"<<
    set2.max_size()<<endl;
    cout<<"erase functio for begin +2 set2\n";
    set2.erase(set2.begin()+2);
    for (int i = 0; i < set2.size(); i++)
        cout<<*(set2.getadr().get()+i)<<endl;
    cout<<"clear function for set2\n";
    set2.clear();
    cout<<"empty function for set2\n"<<
    set2.empty()<<endl;
    cout<<"inserted some elements to set3\n";

    set3.insert(1344);
    set3.insert(134);
    set3.insert(545);
    set3.insert(32);
    set3.insert(22);
    for (int i = 0; i < set3.size(); i++)
        cout<<*(set3.getadr().get()+i)<<endl;   

    GTUIterator<int> test(set3.getadr());
    cout<<"testing iterator first "<<*test<<endl;
    test++;
    test++;
    cout<<"testing iteratorincrement operator twice first++ "<<*test<<endl;
    test--;
    cout<<"testing iteratorincrement operator once first-- "<<*test<<endl;
    GTUSet<int> set4(set3);
    cout<<"COPy constructor has called for set4 from set3 and the set4 is printed;\n";
    for (int i = 0; i < set4.size(); i++)
        cout<<*(set4.getadr().get()+i)<<endl;  
    GTUIterator<int> test4(set4.getadr());
    test4++;
    test4++;    
    test4--;    
    if(test4==test)
        cout<<"i create an iterator for set4 which is copied of the set3 and if they are equal it enters the if statement\n";         
    cout<<"i have already used + and - operator when i use the erase function to determine address of that you want to erase\n";
    if(test4!=++test)
        cout<<"i create an iterator for set4 which is copied of the ++set3 and if they are not equal it enters the if statement\n";             
    cout<<"I have already used * operator to print iterators value\n";
    cout<<"ASSSAIGMENT operator for set 4 to set6\n";
    set6=set4;
    for (int i = 0; i < set6.size(); i++)
        cout<<*(set6.getadr().get()+i)<<endl; 
    
    
    cout<<"__________________________________________TEST FOR THE VECTOR CLASS_________________________\n";
    cout<<"I didnt test all functions with vector too because some functions of vector classes like set class\n";
    GTUVector<int> vector1;
    GTUVector<int> vector2;
    GTUVector<int> vector3;
    GTUVector<char> vector4;
    GTUVector<char> vector5;

    cout<<"insert function for vector1\n";
    vector1.insert(1);
    vector1.insert(2);
    vector1.insert(3);
    vector1.insert(4);
    
    for (int i = 0; i < vector1.size(); i++)
    {
        cout<<vector1[i]<<" by using [] operaror \n";
    }
    cout<<"assaigment operator for vector1 to vector3 and printing vector3\n";
    vector3=vector1;
    for (int i = 0; i < vector3.size(); i++)
    {
        cout<<vector3[i]<<" by using [] operaror \n";
    }
    cout<<"empty function for vector1 "<<vector1.empty()<<endl; 
    cout<<"size function for vector1 "<<vector1.size()<<endl;
    cout<<"max_size function for vector1  "<< vector1.max_size()<<endl;
    cout<<"erase functio for begin +2 vector1\n";
    vector1.erase(vector1.begin()+2);
    for (int i = 0; i < vector1.size(); i++)
    {
        cout<<vector1[i]<<" by using [] operaror \n";
    }
    cout<<"clear function for vector1\n";
    vector1.clear();
    cout<<"empty function for vector1 "<<vector1.empty()<<endl;;

    cout<<"------------------TEST OF GLOBAL FUNCTIONS--------------------\n";
    cout<<"FOR find function\n";
    GTUIterator<int> findie;
    findie=find(set3.begin(),set3.end(),134);
    cout<<"i create an iterator and then send 134 to my find function afterthat when i print the value of iterator i get "<<*(findie.getadr().get())<<endl;
    
    cout<<"FOR find_if function\n";
    GTUIterator<int>findie2;
    findie2=find_if(set4.begin(),set4.end(),ifmod3equal2);
    cout<<"i create a function which takes mod3 and if it equalsto 2 it returns and set4 the value of iterators address is "<<*findie2<<endl;
    cout<<"FOR for_each function\n";
        for (int i = 0; i < set4.size(); i++)
            cout<<*(set4.getadr().get()+i)<<endl;  
    cout<<"I create a new function which showsthe multiply by two\n";        
        for_each(set4.begin(),set4.end(),multiply2);


cout<<"\nEXCEPTION TEST\n";

try{
    cout<<"I inserterted more than once the A character\n";
    set1.insert('A');
    set1.insert('L');
    set1.insert('I');
    set1.insert('A');
    set1.insert('A');
    set1.insert('S');
    set1.insert('D');
    //cout<<vector4[1324]<<endl;
 }
 catch(const bad_pafram & excep)
 {
     excep.geterror();

 }   
 return 0;   
 
 /*   
    it2=it;
    it2++;
    it2++;
    it2++;
    a.erase(a.end());
   // cerr<<a.erase()<<"SSSSSSSSS"<<endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<endl;
    }

   // cerr<<a.empty()<<"SSSSSSSSS"<<endl;
    //cerr<<a.size()<<"SSSSSSSSS"<<endl;
        

    
    */
}    
