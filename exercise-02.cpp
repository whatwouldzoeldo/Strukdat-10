/*
Nama        : Muhammad ZUlfikar Ali
NPM         : 140810180064
Kelas       : B
Deskripse   : Queue menggunakan linked list
Tahun       : 2019
*/

#include <iostream>
using namespace std;

const int maxElement=5;

struct node{
	char info;
	node *next;
};
struct queue{
	node *head;
	node *tail;
};

void createQ(queue &Q);
void createNode(node* &newNode);
void insertLast(queue &Q, node* &newNode);
void deleteFirst(queue &Q);
void print(queue Q);

int main(){
	queue Q;
	node *p;
	int banyak,pil;
	char loop;
	createQ(Q);
	do{
		cout<<"Masukan Banyak Data (MAX "<<maxElement<<"): ";
		cin>>banyak;
	}while(banyak>maxElement);
	cout<<"Masukkan Data : "<<endl;
	for(int i=0; i<banyak; i++){
		createNode(p);
		insertLast(Q,p);
	}
	do{
		system("CLS");
		cout<<"1. Tambah Antrian\n2. Hapus Antrian\n3. Print Antrian"<<endl;
		do{
			cin>>pil;
		}while(pil<1 && pil>3);
		switch(pil){
			case 1:
				if(banyak<5){
					cout<<"Masukkan Data : ";
					createNode(p);
					insertLast(Q,p);
					banyak++;
				}else{
					cout<<"Antrian Penuh";
				}
				break;
			case 2:
				deleteFirst(Q);
				if(banyak>0){
					banyak--;
				}
				break;
			case 3:
				print(Q);
				break;
		}cout<<endl<<"Kembali ke menu? (Y/N) ";
		do{
			cin>>loop;
		}while(loop!='Y' && loop!='y' && loop!='N' && loop!='n');
	}while(loop=='Y' || loop=='y');
	if(loop=='N' || loop=='n'){
		cout<<endl;
	}
}

void createQ(queue &Q){
	Q.head=NULL;
	Q.tail=NULL;
}
void createNode(node* &newNode){
	newNode=new node;
	cin>>newNode->info;
	newNode->next=NULL;
}
void insertLast(queue &Q, node* &newNode){
	if(Q.head==NULL){
		Q.head=newNode;
		Q.tail=newNode;
	}else{
		Q.tail->next=newNode;
		Q.tail=newNode;
	}
}
void deleteFirst(queue &Q){
	if(Q.head==NULL){
		cout<<"Antrian Kosong."<<endl;
	}else{
		node *delNode;
		delNode=Q.head;
		Q.head=Q.head->next;
		delNode->next=NULL;
	}
	cout<<"Antrian berhasil dihapus"<<endl;
}
void print(queue Q){
	if(Q.head==NULL){
		cout<<"Antrian Kosong."<<endl;
	}else{
		node *travNode=Q.head;
		cout<<endl<<"Q = [";
		while(travNode!=NULL){
			cout<<travNode->info;
			if(travNode->next!=NULL){
				cout<<", ";
			}
			travNode=travNode->next;
		}
		cout<<"]"<<endl;
	}
}
