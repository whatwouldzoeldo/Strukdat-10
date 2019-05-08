/*
Nama        : Muhammad ZUlfikar Ali
NPM         : 140810180064
Kelas       : B
Deskripse   : Circular Queue
Tahun       : 2019
*/

#include <iostream>
using namespace std;

const int maxElm = 5;

struct Queue {
    char isi[maxElm];
    int head;
    int tail;
};

void createQueue (Queue& Q) {
    Q.head=-1;
    Q.tail=-1;
}

void insertQueue (Queue& Q) {
    if (Q.tail==-1) {
        Q.head++;
        Q.tail++;
        cin>>Q.isi[Q.head];
    }
    else {
        if (Q.tail<maxElm-1) {
            Q.tail++;
            cin>>Q.isi[Q.tail];
        }
        else {
            if(Q.head==0) {
                cout<<"Antrian sudah penuh"<<endl;
            }
            else {
                Q.tail=0;
                cin>>Q.isi[Q.tail];
            }
        }

    }
}

void deleteQueue (Queue& Q) {
    if (Q.tail==-1) {
        cout<<"Antrian kosong, tidak ada yang perlu dihapus"<<endl;
    }
    else if (Q.head==Q.tail) {
        Q.head=-1;
        Q.tail=-1;
    }
    else {
        if (Q.head<maxElm-1) {
            Q.head++;
        }
        else {
            Q.head=0;
        }
        cout<<"Antrian berhasil dihapus"<<endl;
    }
}

void cetakQueue (Queue Q) {
    if (Q.head==-1) {
        cout<<"Antrian kosong"<<endl;
    }
    else {
        int i=Q.head;
        cout<<endl<<"Antrian = [";
        if (Q.head>Q.tail) {
            while (i<maxElm) {
                cout<<Q.isi[i];
                if (i!=Q.tail) {
                    cout<<", ";
                }
                i++;
            }
            i=0;
            while (i<=Q.tail) {
                cout<<Q.isi[i];
                if (i!=Q.tail) {
                    cout<<", ";
                }
                i++;
            }
        }
        else {
            while (i<=Q.tail) {
                cout<<Q.isi[i];
                if (i!=Q.tail) {
                    cout<<", ";
                }
                i++;
            }
        }
        cout<<"]"<<endl;
    }
}

int main () {
    Queue Q;
    int pil,banyak;
    char loop;

    createQueue(Q);

	do{
		cout<<"Masukan Banyak Data (MAX "<<maxElm<<"): ";
		cin>>banyak;
	}
	while(banyak>maxElm);
	cout<<"Masukkan Data : "<<endl;
	for(int i=0; i<banyak; i++){
		insertQueue(Q);
	}
	do{
		system("CLS");
		cout<<"1. Tambahkan Antrian"<<endl<<"2. Kurangi Antrian"<<endl
		<<"3. Print Antrian"<<endl;
		do{
			cin>>pil;
		}
		while(pil>3 || pil<1);
		switch(pil){
			case 1:
				if(Q.head!=0){
					cout<<"Masukkan Data : "<<endl;
				}
				insertQueue(Q);
				break;
			case 2:
				deleteQueue(Q);
				break;
			case 3:
				cetakQueue(Q);
				break;
		}
		cout<<endl<<"Kembali ke menu? (Y/N) ";
		do{
			cin>>loop;
		}
		while(loop!='Y' && loop!='y' && loop!='N' && loop!='n');
	}
	while(loop=='Y' || loop=='y');
	if(loop=='N' || loop=='n'){
		cout<<endl;
	}
}

