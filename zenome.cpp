/*  WARNING:  This code deals with datafiles and is incomplete.
Might freak you out with unwanted file creation and deletion. Run On Your Own Risk */


#include <fstream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <iostream>
#include <cstdlib>

typedef char str [80];
int i,j,indicator=0;

using namespace std;

void getch() {
    char x;
    cin >> x;
}

void strrev(char a[]) {
    for (size_t i = 0; i < strlen(a)/2; i++) {
        char t = a[i];
        a[i] = a[strlen(a)-1-i];
        a[strlen(a)-1-i] = t;
    }
}

///////// greetings<>   //////////
class ui{
    str c;
public:void ccurtain();
        void load();
        void rcurtain();
	void p2050();
};
char bar(int k){
    if(k%2==0)
    return '/';
    else
    return '|';
}


/////// curtain about column   ////////////


void ui::ccurtain(){
    cout << "Hi" << std::endl;
}

/////    curtain along rows /////

void ui::rcurtain(){
    cout << "    (c)ARCHIT DWIVEDI (c)ARCHIT DWIVEDI (c)ARCHIT DWIVEDI (c)ARCHIT DWIVEDI\n" ;
}

/////    curtain along rows /////


/////   2050   //////////

void ui::p2050(){
    str k[14];
    strcpy(k[0],"\n\n\n\n\n\n");

    strcpy(k[1],"                         """"WELCOME TO THE FUTURE"""""
);
    strcpy(k[2],"  ");
    strcpy(k[3],"////  ||||||||||||||  ||||||||||||||  ||||||||||||||  ||||||||||||||   \\\\\\\\");
    strcpy(k[4],"\\\\\\\\               |  |            |  |               |            |   ////"
);
    strcpy(k[5],"////               |  |            |  |               |            |   \\\\\\\\"
);
    strcpy(k[6],"\\\\\\\\               |  |            |  |               |            |   ////"
);
    strcpy(k[7],"////               |  |            |  |               |            |   \\\\\\\\"
);
    strcpy(k[8],"\\\\\\\\  ||||||||||||||  |            |  ||||||||||||||  |            |   ////"
);
    strcpy(k[9],"////  |               |            |               |  |            |   \\\\\\\\"
);
    strcpy(k[10],"\\\\\\\\  |               |            |               |  |            |   ////"
);
    strcpy(k[11],"////  |               |            |               |  |            |   \\\\\\\\"
);
    strcpy(k[12],"\\\\\\\\  ||||||||||||||  ||||||||||||||  ||||||||||||||  ||||||||||||||   ////"
);
    strcpy(k[13],"      (c) 2016 ARCHIT DWIVEDI//ARCDWI. ALL RIGHTS RESERVED");
    cout<<k[0];
    for(int i=1;i<=13;i++){
	puts(k[i]);
    }
}

void greet(){

    ui o;
    o.rcurtain();
    getch();
    system("clear");
    o.p2050();
    getch();
    o.ccurtain();
    getch();
}

///////// greetings</>   /////


//   CLASS OF MEMBERS OF ZENOME   //
class zenome{
public:str named;
      str uk;
      str namet;
      str tc;
      zenome(){
           strcpy(namet,"TABLE");
           strcpy(named,"DAT BASE");
           strcpy(tc,"Table Content");
      }
      void altertc(str a);
      void alternt(str a);
      int getdb(str a);
      int gettc(str a);
      int gett(str a);
      void alternd(str a);
 };

//   CLASS OF MEMBERS OF ZENOME</>   //
int verify(str);
void order(str a,zenome &k);

//    ------------------->COMMAND LINES   //
int syn(str a){
    int l=strlen(a);
    if(a[l-1]=='?' && a[l-2]=='?'){
	return 1;
    }
    else
    return 0;
}
void writinge(zenome k){
    fstream y("temp.dat",ios::binary);
    fstream g("datum.dat",ios::binary);
    zenome a;
    while(g.read((char *)&a,sizeof(a))){
	if(!strcmp(k.uk,a.uk))
	continue;
	else{
	    y.write((char *)&a,sizeof(a));
	}
    }
    y.write((char *)&k,sizeof(k));
    y.close();g.close();
    remove("datum.dat");
    rename("temp.dat","datum.dat");
}
void writingn(zenome k){
    fstream g("datum.dat",ios::out|ios::binary);
    g.write((char *)&k,sizeof(k));
    g.close();
}
void getcom(str a,str com){
    int l=strlen(a);
   int k=0;
    for(i=0;i<l;i++){
    	com[k++]=a[i];
    	if(a[i+1]=='['||a[i+1]==';'){
    	    break;
    	}
    }
    com[k]='\0';
}
int zenome::gett(str a){
    int l=strlen(a);
    int k=0;
    strcpy(namet,"");
    for(i=1;i<l;i++){
    	if(a[i-1]=='<'){
    	    for(j=i;a[j]!='>';j++){
    		namet[k++]=a[j];
    	    }
    	    break;
    	}
    }
    namet[k]='\0';
    int r=strlen(namet);
    if(namet[r-1]=='?'&&namet[r-2]=='?'){
        return 0;
    }
    else
    return 1;
}
void putinformation(zenome k){
    cout<<endl<<"Your U-Key:: ";puts(k.uk);cout<<endl;
    cout<<endl<<"From:: ";puts(k.named);cout<<endl;
    cout<<endl<<"Of:: ";puts(k.namet);cout<<endl;
    cout<<endl<<"For:: ";puts(k.tc);cout<<endl;
    getch();
}
int zenome::gettc(str a){
    int l=strlen(a);
    int k=0;
    strcpy(tc,"");
    for(i=1;i<l;i++){
	if(a[i-1]=='|'){
	    for(j=i;a[j]!='|';j++){
		tc[k++]=a[j];
	    }
	    break;
	}
    }
    tc[k]='\0';
    int r=strlen(tc);
    if(tc[r-1]=='?'&&tc[r-2]=='?'){
        return 0;
    }
    else
    return 1;
}
int zenome::getdb(str a){
    int l=strlen(a);
   int k=0;
    strcpy(named,"");
    for(i=1;i<l;i++){
	if(a[i-1]=='['){
	    for(j=i;a[j]!=']';j++){
		named[k++]=a[j];
	    }
	    break;
	}
    }
    named[k]='\0';
    int r=strlen(named);
    if(named[r-1]=='?'&&named[r-2]=='?'){
        return 0;
    }
    else
    return 1;
}
void writingfaltchunk(zenome k,str old){
    fstream y("temp.dat",ios::binary);
    fstream g("datum.dat",ios::binary);
    zenome a;
    while(g.read((char *)&a,sizeof(a))){
	if(!strcmp(old,a.uk))
	continue;
	else{
	    y.write((char *)&a,sizeof(a));
	}
    }
    y.write((char *)&k,sizeof(k));
    y.close();g.close();
    remove("datum.dat");
    rename("temp.dat","datum.dat");
}

void altchnk(str a,zenome &k){
    int l=strlen(a);
    int ki=0;
    int tempind=0;
    str temporary;
    for(i=0;i<l-1;i++){
    	if(tempind==1){
    	    temporary[ki++]=a[i];
    	    if(a[i+1]==';')
    	    break;
    	}
    	if(a[i]==';'){
    	    tempind=1;
    	}
    }
    int p=i;
    temporary[ki]='\0';
    ki=0;
    str temp2;
    strcpy(temp2,k.uk);
    strcpy(k.uk,"");
    if(!strcmp(temporary,temp2)){
    	for(i=l-4;i>=0;i--){
    	    if(a[i-1]!=';'){
    		k.uk[ki++]=a[i];
    	    }
    	}
    	k.uk[ki]='\0';
    	strrev(k.uk);
    	if(verify(k.uk)!=0){
    	    cout<<endl<<"       ENTER UNIQUE KEY"<<endl;
            str reentering;
            cin.getline(reentering, 80);
            altchnk(reentering,k);
    	}
        writingfaltchunk(k,temp2);
    }
    else if(strcmp(temporary,temp2)){
	cout<<endl<<"          INCORRECT KEY ENTERED... Re-Enter"<<endl;
    str reentering;
    cin.getline(reentering, 80);
    altchnk(reentering,k);
    }
    else{
        cout<<"U-Key Change:: CHECK"<<endl;
    }
    writinge(k);
}
void zenome::altertc(str a){
    gettc(a);
    cout<<endl<<"CHECK"<<endl;
}
void zenome::alternt(str a){
    str old;
    strcpy(old,namet);
    gett(a);
    cout<<endl<<"CHECK:: from '";
    puts(old);cout<<"' to '";
    puts(namet);cout<<"'"<<endl;
}
void zenome::alternd(str a){
    str old;
    strcpy(old,named);
    getdb(a);
    cout<<endl<<"CHECK:: from '";
    puts(old);cout<<"' to '";
    puts(named);cout<<"'"<<endl;
}
void definenew(zenome &k){
    strcpy(k.uk,"");
    cin.getline(k.uk, 80);
    if(verify(k.uk)){
	cout<<"The KEY you've entered is already been feeded by someone else!!"<<endl;
	cout<<"Re-ENTER::::"<<endl;
	definenew(k);
    }
    else{
	writingn(k);
	cout<<"Now You are Allowed to Access to your account\nPress any key to continue..."<<endl<<endl;
	getch();
	// cout<<"ENTER THE COMMAND"<<endl;
	// cout<<"arcdwi << ";
	// str command2;
	// cin.getline(command2, 80);
	// indicator=1;
	// order(command2,k);
    }
}
int verify(str a){
    zenome k;
    int t=0;
    fstream g("datum.dat",ios::in|ios::binary);
    while(g.read((char *)&k,sizeof(k))){
	if(!strcmp(k.uk,a)){
	    t++;
	}
    }
    g.close();
    return t;
}
int checksymb(str g,char a,int p){
    int t=0;
    for(i=0;i<p;i++){
        if(g[i]==a){
            t=1;
            break;
        }
    }
    if(t==1){
        return 1;
    }
    else{
        return 0;
    }
}


//int indicator=0;
void order(str a,zenome &k){
    str com;
    strcpy(com,"");
    getcom(a,com);
    //cout<<"togetcom"<<endl;getch();
    //puts(com);
    str sector;
    if(!syn(a)){
	indicator=1;
	cout<<endl<<"       -> ";
	str commandcont;
	cin.getline(commandcont, 80);
	strcat(a,commandcont);
	order(a,k);
    }
    else if(indicator==0){
    cout<<endl<<"arcdwi << ";
    }
    if(!strcmp(a,"gotta go")){
	indicator=0;
	cout<<"^^ THANK YOU FOR TRUSTING ME THROUGH 'arcdwi >>'";getch();
	exit(0);
    }
    else if(!strcmp(com,"make")){
        zenome just;
        just=k;
        str comcopy;
        strcpy(comcopy,a);
        if(just.gett(comcopy)*just.gettc(comcopy)*just.getdb(comcopy)){
            if(checksymb(com,'[',strlen(com))){
                k.getdb(a);
            }
            if(checksymb(com,'<',strlen(com))){
                k.gett(a);
            }
            if(checksymb(com,'|',strlen(com))){
                k.gettc(a);
            }
            writinge(k);
            indicator=0;
            strcpy(sector,"");
            cout<<endl<<"arcdwi << ";
            cin.getline(sector, 80);
            order(sector,k);
        }
        else{
            cout<<"          I Think You've went Wrong Somewhere...!!"<<endl;
            strcpy(sector,"");
            cout<<endl<<"arcdwi << ";
            cin.getline(sector, 80);
            order(sector,k);
        }
    }
    else if(!strcmp(com,"putinfo")){
        indicator=0;
        putinformation(k);
        strcpy(sector,"");
        cout<<endl<<"arcdwi << ";
        cin.getline(sector, 80);
        order(sector,k);
    }
    else if(!strcmp(com,"key from ")){
	altchnk(a,k);
	strcpy(sector,"");
	cout<<endl<<"arcdwi << ";
	cin.getline(sector, 80);
	order(sector,k);
    }
    else if(!strcmp(a,"screen saf kar")||!strcmp(a,"clear screen")){
	indicator=0;
	system("clear");
	strcpy(sector,"");
	cout<<endl<<"arcdwi << ";
	cin.getline(sector, 80);
	order(sector,k);
    }
    else if(!strcmp(a,"archit! show your grace")||!strcmp(a,"help")){
	indicator=0;
	fstream kom("zcommand.txt",ios::in);
	cout<<endl<<endl;
	while(!kom.eof()){
	    strcpy(sector,"");
	    kom.getline(sector,80);
	    puts(sector);
	}
    kom.close();
	strcpy(sector,"");
	cout<<endl<<"arcdwi << ";
	cin.getline(sector, 80);
	order(sector,k);
    }
    else
    {
	indicator=0;
	cout << "ERROR:: Abe kam se kam target to karo!!\nType 'archit! show your grace\?\?' to get list of command lines \n";
	cout<<endl<<"arcdwi << ";
	cin.getline(sector, 80);
	order(sector,k);
    }
}


int unkfound(str unk){
    zenome k;
    fstream g("datum.dat",ios::binary|ios::in);
    while(g.read((char *)&k,sizeof(k))){
        int t = g.tellg() - sizeof(k);
        g.seekg(t);
    	g.read((char *)&k,sizeof(k));
    	if(!strcmp(k.uk,unk)){
    	    return 1;
    	}
    	else
    	break;
    }
    g.close();
    return 0;
}
zenome getobj(str unk){
    zenome k;
    ifstream g("datum.dat", ios::binary|ios::in);
    while(g.read((char *)&k,sizeof(k))){
        // g.seekg(g.tellg()-sizeof(k));
    	// g.read((char *)&k,sizeof(k));
    	if(!strcmp(k.uk,unk)){
    	    g.seekg(g.tellg()-sizeof(k));
    	    break;
    	}
    }
    g.close();
    return k;
}



//    ------------------->COMMAND LINES</>   //
////// main()   /////
int main(){
    greet();
    str a;
    yeser:
    system("clear");
    cout<<setw(40)<<"ENTER YOUR KEY-"<<endl<<endl;
    str unk;
    zenome k;
    cin.getline(unk, 80);
    if(unkfound(unk)){
        //zenome mainobj;
        //mainobj=getobj(unk);
        cout<<"                           ENTER THE COMMAND"<<endl;
        cout<<"arcdwi << ";
        strcpy(a,"");
        cin.getline(a, 80);
	    indicator=1;
        zenome x = getobj(unk);
        order(a, x);
    }
    else if(!strcmp(unk,"neser")){
        system("clear");
        cout<<"ENTER FEW LETTERS WHICH CAN BE REMEMBERED BY YOU NOT ONLY FOR A SHORT TERM"<<endl;
        definenew(k);
        system("clear");
        cout<<"ENTER THE COMMAND"<<endl;
    	cout<<"arcdwi << ";
    	str command2;
    	cin.getline(command2, 80);
    	indicator=1;
    	order(command2,k);
    }
    else{
        cout<<"NO MATCH FOUND!! Are you a newcomer\nType 'neser' else 'yeser'"<<endl<<endl;
        cout<<"arcdwi << ";
        str newcomer;
        cin.getline(newcomer, 80);
        if(!strcmp(newcomer,"neser")){
            system("clear");
            cout<<"ENTER FEW LETTERS WHICH CAN BE REMEMBERED BY YOU NOT ONLY FOR A SHORT TERM"<<endl;
            definenew(k);
            cout<<"ENTER THE COMMAND"<<endl<<endl;
        	cout<<"arcdwi << ";
        	str command2;
        	cin.getline(command2, 80);
        	indicator=1;
        	order(command2,k);
        }
        else if(!strcmp(newcomer,"yeser")){
            goto yeser;
        }
    }
    return 0;
}
