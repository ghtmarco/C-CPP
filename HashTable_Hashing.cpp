#include<stdio.h>
#include<string.h>

struct data{
	char key[51];
	int step;
	
	char nim[11];
	char nama[51];
	int tinggi;
	float berat;
};

void hashFirstChar(struct data h[51], char x[51]){
	int hashkey = x[0] - 97;
	int step = 1;
	
	while(strcmp(h[hashkey].key, "") != 0){
		printf ("can't add to %d, taken by %s\n", hashkey, h[hashkey].key);
		hashkey = (hashkey + 1) % 26;
		
		step ++;
//		hashkey = hashkey + 1*1;
//		hashkey = hashkey + 2*2;
		getchar();
	}
	h[hashkey].step = step;
	strcpy(h[hashkey].key, x);
}

void cetak(struct data h[26]){
	int i;
	printf("Index | Key | Step \n");
	for(i = 0; i < 26; i++){
		printf("%5d | %s | %d \n", i, h[i].key, h[i].step);
	}
}

int main(){
	char x[51];
	struct data h[26] = {};
	int index = 0;
	
	do{
		cetak(h);
		printf ("(ketik exit untuk keluar)\n");
		printf ("Masukkan Key String = ");
		scanf("%s", x);
		
		hashFirstChar(h, x);
		strcpy(h[index].key, x);
	}while(strcmp(x, "exit") != 0);
	
	return 0;
}