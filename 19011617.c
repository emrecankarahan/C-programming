#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h> 
int main(){
	int menusecimi,cikma,bitirmekontrolu=1,satir,sutun,i,j,sekil,koordinat,k,puan=0,toplam,l; 
	printf("MENU\nOyuna Baslamak icin: '1'\nNasil Oynandigini ogrenmek icin:'2'\nOyundan cikmak icin:'0'\ntuslayiniz:");
	scanf("%d",&menusecimi);
	int yon;
	if(menusecimi==2){
	printf("1)Oyuncu tarafindan genisligi ve uzunlugu girilen bir oyun tahtasi olustururur.\n2)Rastgele verilen sekiller oyuncu tarafindan sutun numarasi belirlenerek 'EN SOL ALT UCU' baz alinarak asagi kaydirilarak yerlestiririr.(Bos olan koordinatlar '0'ile dolu olanlar '1' ile sembollenmistir.)\nEger bir satir tamamen dolmus ise (111...) O satir kaybolur ve ustundeki satirlar birer asagiya kayar.\n3)Yerlestirilen her sekil icindeki '1' sayisina gore, kaybolan her satir sutun sayisina gore puanlanir.\n4)Ayrica oyuncu istedigi takdirde sekilin yonunu saat yonune gore 90 derecelik aci yapacak sekilde donderebilir.\nIyi eglenceler.");
	printf("\nOyunu oynamak icin '1', cikmak icin '0' tuslayiniz:");
	scanf("%d",&menusecimi);
	}	
	while(menusecimi!=1 && menusecimi!=0 ){
		printf("Yanlis tuslama yaptiniz. Lutfen tekrar giriniz:");
		scanf("%d",&menusecimi);
		}
	if(menusecimi==1){
		printf("Oyuna basladiniz iyi eglenceler :)\n");
		printf("Satir sayisini giriniz:");
		scanf("%d",&satir);
		printf("Sutun sayisini giriniz:");
		scanf("%d",&sutun);
		int oyuntahtasi[satir][sutun];
		for(i=0;i<satir;i++){
			for(j=0;j<sutun;j++){
			oyuntahtasi[i][j]=0;
			}
		}
		for(i=0;i<satir;i++){
			for(j=0;j<sutun;j++){
			printf("%d",oyuntahtasi[i][j]);
			}
		printf("\n");
	 	}
	while(bitirmekontrolu!=0){
		srand(time(NULL)); 
	 	sekil=rand()%6;
		if(sekil==0){
			printf("Sekliniz:'1' Yerlestirmek istediginiz sutun numarasini giriniz:");
			scanf("%d",&koordinat);
			while(koordinat>sutun || koordinat<=0){
			printf("Yanlis tuslama yaptiniz. Lutfen 1 ile %d arasinda bir sayi giriniz:",sutun);
			scanf("%d",&koordinat);	
			}
			k=0;
			while(oyuntahtasi[k][koordinat-1]==0 && k<satir){
			k++;	
			}
			if(k==0){
			bitirmekontrolu=0;
			}
			else{
			oyuntahtasi[k-1][koordinat-1]=1; 
			puan=puan+1;
			}
		}
		else if(sekil==1){
			printf("Sekliniz:\n'11\n 11'Yerlestirmek istediginiz sutun numarasini giriniz (EN SOL):");
			scanf("%d",&koordinat);
			while(koordinat>(sutun-1) || koordinat<=0){
			printf("Yanlis tuslama yaptiniz. Lutfen 1 ile %d arasinda bir sayi giriniz:",sutun-1);
			scanf("%d",&koordinat);	
			}
			k=0;
			while(oyuntahtasi[k][koordinat-1]==0 && k<satir && oyuntahtasi[k][koordinat]==0 ){
			k++;
			}
			if(k==0 || k==1){
			bitirmekontrolu=0;
			}
			else{
				oyuntahtasi[k-1][koordinat-1]=1; 
				oyuntahtasi[k-1][koordinat]=1;
				oyuntahtasi[k-2][koordinat-1]=1; 
				oyuntahtasi[k-2][koordinat]=1; 
				puan=puan+4;
			}
		}	
		else if(sekil==2){
		printf("Sekliniz: '11' Dondurmek istiyorsaniz '1', istemiyorsaniz '0' tuslayiniz:");
		scanf("%d",&yon);
		while(yon!=1 && yon!=0){
		printf("Yanlis tuslama yaptiniz. Lutfen dondurmek istiyorsaniz '1', istemiyorsaniz '0' tuslayiniz:");
		scanf("%d",&yon);
		} 
		if(yon==1){
		printf("Yeni sekliniz:\n'1\n 1'Yerlestirmek istediginiz sutun numarasini giriniz:");
		scanf("%d",&koordinat);
		while(koordinat>sutun || koordinat<=0){
		printf("Yanlis tuslama yaptiniz. Lutfen 1 ile %d arasinda bir sayi giriniz:",sutun);
		scanf("%d",&koordinat);	
		}
		k=0;
		while(oyuntahtasi[k][koordinat-1]==0 && k<satir){
			k++;
		}
		if(k==1 || k==0){
			bitirmekontrolu=0;
		}
		else{
			oyuntahtasi[k-1][koordinat-1]=1; 
			oyuntahtasi[k-2][koordinat-1]=1; 
				puan=puan+2;
		}
		}
		else if(yon==0){
		printf("Sekliniz: '11' Yerlestirmek istediginiz sutun numarasini giriniz(EN SOL):");
		scanf("%d",&koordinat);
		while(koordinat>(sutun-1) || koordinat<=0){
			printf("Yanlis tuslama yaptiniz. Lutfen 1 ile %d arasinda bir sayi giriniz:",sutun-1);
			scanf("%d",&koordinat);	
			}
		k=0;
		while(oyuntahtasi[k][koordinat-1]==0 && k<satir && oyuntahtasi[k][koordinat]==0){
		k++;
		}
		if(k==0){
			bitirmekontrolu=0;
		}
		else{
			oyuntahtasi[k-1][koordinat-1]=1; 
			oyuntahtasi[k-1][koordinat]=1; 
			puan=puan+2;
		}
		}
		}
		else if(sekil==3){
		printf("Sekliniz: '111' Dondurmek istiyorsaniz '1', istemiyorsaniz '0' tuslayiniz:");
		scanf("%d",&yon);
		while(yon!=1 && yon!=0){
		printf("Yanlis tuslama yaptiniz. Lutfen dondurmek istiyorsaniz '1', istemiyorsaniz '0' tuslayiniz:");
		scanf("%d",&yon);
		} 
		if(yon==1){
		printf("Sekliniz:\n'1\n 1\n 1' Yerlestirmek istediginiz sutun numarasini giriniz:");
		scanf("%d",&koordinat);
		while(koordinat>sutun || koordinat<=0){
			printf("Yanlis tuslama yaptiniz. Lutfen 1 ile %d arasinda bir sayi giriniz:",sutun);
			scanf("%d",&koordinat);	
			}
		k=0;
		while(oyuntahtasi[k][koordinat-1]==0 && k<satir){
		k++;
		}
		if(k==0 || k==1 || k==2){
		bitirmekontrolu=0;	
		}
		else{
			oyuntahtasi[k-1][koordinat-1]=1; 
			oyuntahtasi[k-2][koordinat-1]=1; 
			oyuntahtasi[k-3][koordinat-1]=1; 
			puan=puan+3;
		}
		}
		else if(yon==0){
			printf("Sekliniz: '111' Yerlestirmek istediginiz sutun numarasini giriniz(EN SOL):");
		scanf("%d",&koordinat);
		while(koordinat>(sutun-2) || koordinat<=0){
			printf("Yanlis tuslama yaptiniz. Lutfen 1 ile %d arasinda bir sayi giriniz:",sutun-2);
			scanf("%d",&koordinat);	
			}
		k=0;
		while(oyuntahtasi[k][koordinat-1]==0 && k<satir && oyuntahtasi[k][koordinat]==0 && oyuntahtasi[k][koordinat+1]==0){
		k++;
		}
		if(k==0){
			bitirmekontrolu=0;
		}
		else{
			oyuntahtasi[k-1][koordinat-1]=1; 
			oyuntahtasi[k-1][koordinat]=1; 
			oyuntahtasi[k-1][koordinat+1]=1; 
			puan=puan+3;
		}
		}	
		}
		else if(sekil==4){
		printf("Sekliniz:\n'11\n11' Dondurmek istiyorsaniz '1', istemiyorsaniz '0' tuslayiniz:");
		scanf("%d",&yon);
		while(yon!=1 && yon!=0){
		printf("Yanlis tuslama yaptiniz. Lutfen dondurmek istiyorsaniz '1', istemiyorsaniz '0' tuslayiniz:");
		scanf("%d",&yon);
		} 
		if(yon==0){
		printf("Sekliniz:\n'11\n11' Yerlestirmek istediginiz sutun numarasini giriniz(EN SOL):");
		scanf("%d",&koordinat);
		while(koordinat>(sutun-2) || koordinat<=0){
			printf("Yanlis tuslama yaptiniz. Lutfen 1 ile %d arasinda bir sayi giriniz:",sutun-2);
			scanf("%d",&koordinat);	
			}
		k=1;
		while(k<satir && oyuntahtasi[0][koordinat-1]==0 && oyuntahtasi[0][koordinat]==0 && oyuntahtasi[k][koordinat-1]==0 && oyuntahtasi[k][koordinat]==0 && oyuntahtasi[k-1][koordinat+1]==0){
		k++;
		}
		if(k==1){
		bitirmekontrolu=0;
		}
		else{
		oyuntahtasi[k-1][koordinat-1]=1;
		oyuntahtasi[k-1][koordinat]=1;
		oyuntahtasi[k-2][koordinat]=1;
		oyuntahtasi[k-2][koordinat+1]=1;
		puan=puan+4;
		}
		}	
		else if(yon==1){
		printf("Sekliniz:\n'1\n 11\n  1' Yerlestirmek istediginiz sutun numarasini giriniz(EN SOL):");
		scanf("%d",&koordinat);
		while(koordinat>(sutun-1) || koordinat<=0){
			printf("Yanlis tuslama yaptiniz. Lutfen 1 ile %d arasinda bir sayi giriniz:",sutun-1);
			scanf("%d",&koordinat);	
			}	
		k=1;
		while(oyuntahtasi[k-1][koordinat-1]==0 && oyuntahtasi[k][koordinat]==0 && oyuntahtasi[0][koordinat]==0 && k<satir){
		k++;
		}
		if(k==1 || k==2 ){
		bitirmekontrolu=0;
		}
		else{
		oyuntahtasi[k-1][koordinat]=1;
		oyuntahtasi[k-2][koordinat-1]=1;
		oyuntahtasi[k-2][koordinat]=1;
		oyuntahtasi[k-3][koordinat-1]=1;
		puan=puan+4;
		}
		}
		
		}
		if(sekil==5){
		printf("Sekliniz:\n'1\n 1\n 11' 90 derece dondurmek icin '90'; 180 derece icin '180'; 270 derece icin '270', istemiyorsaniz '0' tuslayiniz:");
		scanf("%d",&yon);
		while(yon!=90 && yon!=180 && yon!=270 && yon!=0){
		printf("Yanlis tuslama yaptiniz. Lutfen tekrar giriniz:");
		scanf("%d",&yon);
		}
		if(yon==90){
		printf("Sekliniz:\n'111\n 1'Yerlestirmek istediginiz sutun numarasini giriniz(EN SOL) :");
		scanf("%d",&koordinat);
		while(koordinat>(sutun-2) || koordinat<=0){
			printf("Yanlis tuslama yaptiniz. Lutfen 1 ile %d arasinda bir sayi giriniz:",sutun-2);
			scanf("%d",&koordinat);	
			}
		k=1;
		while(oyuntahtasi[k][koordinat-1]==0 && oyuntahtasi[k-1][koordinat]==0 && k<satir && oyuntahtasi[k-1][koordinat+1]==0 && oyuntahtasi[0][koordinat-1]==0 ){
		k++;
		}
		if(k==1){
		bitirmekontrolu=0;
		}
		else{
		oyuntahtasi[k-1][koordinat-1]=1;
		oyuntahtasi[k-2][koordinat-1]=1;
		oyuntahtasi[k-2][koordinat]=1;
		oyuntahtasi[k-2][koordinat+1]=1;
		puan=puan+4;
		}
		}
		else if(yon==180){
		printf("Sekliniz:\n'11\n  1\n  1' Yerlestirmek istediginiz sutun numarasini giriniz(EN SOL):");
		scanf("%d",&koordinat);
		while(koordinat>(sutun-1) || koordinat<=0){
			printf("Yanlis tuslama yaptiniz. Lutfen 1 ile %d arasinda bir sayi giriniz:",sutun-1);
			scanf("%d",&koordinat);	
			}
		k=2;
		while(oyuntahtasi[k-2][koordinat-1]==0 && oyuntahtasi[k][koordinat]==0 && k<satir && oyuntahtasi[0][koordinat]==0 && oyuntahtasi[1][koordinat]==0 ){
		k++;
		}
		if(k==2){
		bitirmekontrolu=0;
		}
		else{
		oyuntahtasi[k-1][koordinat]=1;
		oyuntahtasi[k-2][koordinat]=1;
		oyuntahtasi[k-3][koordinat]=1;
		oyuntahtasi[k-3][koordinat-1]=1;
		puan=puan+4;
		}
		}
		else if(yon==270){
		printf("Sekliniz:\n'  1\n 111' Yerlestirmek istediginiz sutun numarasini giriniz(EN SOL):");	
		scanf("%d",&koordinat);
		while(koordinat>(sutun-2) || koordinat<=0){
			printf("Yanlis tuslama yaptiniz. Lutfen 1 ile %d arasinda bir sayi giriniz:",sutun-2);
			scanf("%d",&koordinat);	
			}
		k=0;
		while(oyuntahtasi[k][koordinat-1]==0 && oyuntahtasi[k][koordinat]==0 && oyuntahtasi[k][koordinat+1]==0 && k<satir){
		k++;
		}
		if(k==0 ||k==1){
		bitirmekontrolu=0;
		}
		else{
		oyuntahtasi[k-1][koordinat-1]=1;
		oyuntahtasi[k-1][koordinat]=1;
		oyuntahtasi[k-1][koordinat+1]=1;
		oyuntahtasi[k-2][koordinat+1]=1;
		puan=puan+4;	
		}
		}
		else if(yon==0){
		printf("Sekliniz:\n'1\n 1\n 11' Yerlestirmek istediginiz sutun numarasini giriniz(EN SOL):");	
		scanf("%d",&koordinat);
		while(koordinat>(sutun-1) || koordinat<=0){
			printf("Yanlis tuslama yaptiniz. Lutfen 1 ile %d arasinda bir sayi giriniz:",sutun-1);
			scanf("%d",&koordinat);	
			}
		k=0;
		while(oyuntahtasi[k][koordinat-1]==0 && oyuntahtasi[k][koordinat]==0 && k<satir){
			k++;
		}	
		if(k==0 || k==1 ||k==2){
		bitirmekontrolu=0;
		}
		else{
		oyuntahtasi[k-1][koordinat-1]=1;
		oyuntahtasi[k-1][koordinat]=1;
		oyuntahtasi[k-2][koordinat-1]=1;
		oyuntahtasi[k-3][koordinat-1]=1;
		puan=puan+4;		
		}
		}
		}
		for(i=satir-1;i>=0;i--){
			toplam=0;
			for(j=0;j<sutun;j++){
				toplam=toplam+oyuntahtasi[i][j];
			}
			if(toplam==sutun){
				for(k=i-1;k>=0;k--){
					for(l=0;l<sutun;l++){
						oyuntahtasi[k+1][l]=oyuntahtasi[k][l];
					}
				}
				for(l=0;l<sutun;l++){
					oyuntahtasi[0][l]=0;
			}
			puan=puan+sutun;
			i++;			
			}
		}
		if(bitirmekontrolu==1){
		for(i=0;i<satir;i++){
		for(j=0;j<sutun;j++){
		printf("%d",oyuntahtasi[i][j]);
		}
		printf("\n");
	 	}
	 }
	printf("Cikmak icin '0', devam etmek icin '1' tuslayiniz:");
	scanf("%d",&cikma);
	while(cikma!=0 && cikma!=1){
	printf("Yanlis tuslama yaptiniz. Lutfen tekrar giriniz:");
	scanf("%d",&cikma);
	}
	if(cikma==0){
	bitirmekontrolu=0;
	}
	}
	printf("Oyununuz bitmistir.Puaniniz:%d",puan);
}
	
	else if(menusecimi==0){
	printf("Oyundan ciktiniz. Yine bekleriz. :)");
	}
}
