#include <stdio.h>
#include "my_array_library.h"
#include <math.h>


//********Görkem*********

void bastir(struct ucak a) {
	printf("\n") ;	
	printf("Ucagin hareket halindeki sabit hizi %d dir\n",a.hiz) ;
	printf("Ucagin konumunun kuzey-guney koordinati %d dir\n",a.ykordinati) ;
	printf("Ucagin konumunun dogu-bati koordinati %d dir\n",a.xkordinati) ;
	printf("Ucagin konumunun yerden yuksekligi %d dir\n",a.zkordinati) ;
}


struct ucak degeral(struct ucak bilgi) {

	printf("\n\nUcak hakkindaki bilgileri giriniz: \n");
	printf("\n") ;
	printf("Ucagin hareket halindeki hizini giriniz: ") ;
	scanf("%d",&bilgi.hiz) ;
	printf("Ucagin konumunun kuzey-guney koordinatini giriniz: ") ;
	scanf("%d",&bilgi.ykordinati) ;
	printf("Ucagin konumunun dogu-bati koordinatini giriniz: ") ;	
	scanf("%d",&bilgi.xkordinati);
	printf("Ucagin konumunun yuksekligini giriniz: ") ;	
	scanf("%d",&bilgi.zkordinati);
	
	return bilgi;
}


void bastir2(struct hedef c) {
	printf("\n") ;
	printf("Vurulacak hedefin konumunun kuzey-guney koordinati %d dir\n",c.ykordinati) ;
	printf("Vurulacak hedefin konumunun dogu-bati koordinati %d dir\n",c.xkordinati) ;
	printf("Vurulacak hedefin konumunun yuksekligi %d dir\n",c.zkordinati) ;
	printf  ("Hedefe %d tane bomba atilacak." , c.fuzesayisi );
}


struct hedef degeral2(struct hedef bilgiler) {

	printf("\n\nVurulacak hedef hakkindaki bilgileri giriniz:\n");
	printf("\n") ;
	printf("Vurulacak hedefin konumunun kuzey-guney koordinatini giriniz: ") ;
	scanf("%d",&bilgiler.ykordinati) ;
	printf("Vurulacak hedefin konumunun dogu-bati koordinatini giriniz: ") ;	
	scanf("%d",&bilgiler.xkordinati);
	printf("Vurulacak hedefin konumunun yuksekligini giriniz: ");
	scanf ("%d" , &bilgiler.zkordinati);
	printf ("Hedefe birakilacak bomba sayisini giriniz: ");
	scanf ("%d" , &bilgiler.fuzesayisi);



	return bilgiler;
}
//************Reyhan*************

	//savas ucaklari ortalama 15.000 metreden ucar.
void hesap(struct ucak bilgi, struct hedef bilgiler){
	float sure;
	float duserkenakinanyol;
	sure = sqrt(((bilgi.zkordinati-bilgiler.zkordinati)*2)/9.8);

	printf("\n\nUcak fuzeyi biraktikta sonra hedefin vurulma  suresi %.3f sn dir.\n" , sure);
	
	
}

void yol(struct ucak bilgi,struct hedef bilgiler) {
	
	float islem,islem1,sure ;
	sure = sqrt(((bilgi.zkordinati-bilgiler.zkordinati)*2)/9.8);
	
	islem=sqrt(pow((bilgiler.xkordinati-bilgi.xkordinati),2)+pow((bilgi.ykordinati-bilgiler.ykordinati),2));
	printf("\n\nUcak hedefle ayni kordinatlara gelene kadarki aldigi yol %.3f km dir.\n",islem) ;
	
	islem1=sure*(bilgi.hiz) ;
	
   printf("\n Ucak fuzeyi biraktiktan sonra fuze hedefi vuruna kadar ucagin aldigi yol %.2f km dir.\n",islem1) ;
}
 
 
 //***********


void yakit(struct ucak bilgi,struct hedef bilgiler) {
	
	float islem,i,islem1,sure ;
	sure = sqrt(((bilgi.zkordinati-bilgiler.zkordinati)*2)/9.8);
	printf("\n\nSavas ucaginin kilometre basina kac litre yakit yaktigini giriniz=");
	scanf("%f",&i) ;
	 
	islem=(sqrt(pow((bilgiler.xkordinati-bilgi.xkordinati),2)+pow((bilgi.ykordinati-bilgiler.ykordinati),2))*i) ;
	
	printf("\n\nUcak hedefle ayni kordinatlara gelene kadarki yakilan yakit %.2f litre dir.\n\n",islem) ;
	
	islem1=sure*(bilgi.hiz)*i ;
	
	printf("\n Ucak fuzeyi biraktiktan sonra fuze hedefi vuruna kadar ucagin yaktigi yakit %.2f litre dir.\n\n",islem1) ;

}

//**********Reyhan**********

void kordinatbulma (struct ucak bilgi, struct hedef bilgiler){
	
	
	float sure,egim , xtealinacak, ydealinacak, yataydaalinacakyol, fark;
	float zfark, yfark, xfark;	
	sure = sqrt(((bilgi.zkordinati-bilgiler.zkordinati)*2)/9.8);
	float duserkenakinanyol, fuzeninyatayyolu, fuzeninyolu;
	zfark = abs(bilgiler.zkordinati-bilgi.zkordinati);
	yfark = abs(bilgiler.ykordinati-bilgi.ykordinati);
	xfark = abs(bilgiler.xkordinati-bilgi.xkordinati);

	fuzeninyatayyolu = sqrt(abs((xfark*xfark)- (yfark*yfark)));
	fuzeninyolu = sqrt(abs((fuzeninyatayyolu*fuzeninyatayyolu)- (zfark*zfark)));
	egim = xfark/yfark;
	
	yataydaalinacakyol = sure*bilgi.hiz;
	fark = sqrt(abs((xfark*xfark) - (yfark*yfark)));
	xtealinacak = (fark/xfark)/yataydaalinacakyol;
	ydealinacak = (fark/yfark)/yataydaalinacakyol;
	if (bilgi.zkordinati>=bilgiler.zkordinati){

	
	printf ("\nFuzenin birakilacagi koordinatlar = \nDogu-Bati(x)\tKuzey-Guney(y)\n");
	if (bilgiler.xkordinati>bilgi.xkordinati && bilgiler.ykordinati>bilgi.ykordinati)
	printf ("%f \t\t%f" ,bilgiler.xkordinati+xtealinacak, bilgiler.ykordinati+ydealinacak);
	else if (bilgiler.xkordinati>bilgi.xkordinati && bilgiler.ykordinati<bilgi.ykordinati)
	printf ("%f \t\t%f" , bilgiler.xkordinati+xtealinacak,bilgiler.ykordinati-ydealinacak);
	else if (bilgiler.xkordinati<bilgi.xkordinati && bilgiler.ykordinati>bilgi.ykordinati)
	printf ("%f \t\t%f" ,bilgiler.xkordinati-xtealinacak, bilgiler.ykordinati+ydealinacak);	
	else if (bilgiler.xkordinati<bilgi.xkordinati && bilgiler.ykordinati<bilgi.ykordinati)
	printf ("%f \t\t%f" , bilgiler.xkordinati-xtealinacak , bilgiler.ykordinati-ydealinacak);
}

	else 
	printf ("\n\nHedef, savas ucagindan yukarida bulunmakta! Yerden ateslemeli sistem kulanin!");	

}


void fuzebirak (struct hedef bilgiler){
	int i;
	printf ("\n\n\n");
	for (i = 0 ; i<bilgiler.fuzesayisi ; i++){
		printf ("\n%d. fuze birakildi" , i+1);
	}
}

//***********Görkem********


void degeral3(struct ucakbilgileri *p) {
	
	
	    printf("\n\nucagin ozellikleri hakkindaki bilgileri giriniz:\n");
	    printf("\n") ;
	    
	    printf("ucagin depo haznesinin kac litre oldugunu giriniz=") ;
	    scanf("%f",&p->depo) ;
	    printf("ucagin uretim yilini giriniz giriniz=") ;
	    scanf("%d",&p->uretimyili) ;
	    printf("ucagin kac km de oldugunu giriniz=") ;
	    scanf("%f",&p->kilometre) ;

}


void goster3(struct ucakbilgileri *p) {
	
	printf("\n") ;
	printf("ucagin depo haznesi= %.2f litre dir\n",p->depo) ;
	printf("ucagin uretim yili= %d dir\n",p->uretimyili) ;
	printf("ucagin kilometresi= %.2f km dir\n",p->kilometre) ;
}


void degerlendirme(struct ucakbilgileri *p) {
	
	printf("\n") ;
	if(p->kilometre >= 100000|| p->uretimyili >= 2012 ) {
	printf("\nmotorun 6 ayda bir ayrintili genel bakimi yapilmasi lazim!!\n") ;
	}
	
	else {
		printf("\nayrintili bakima gerek yok.yillik bakim yeterli.\n");
	}
	
	if (p->depo >700 ) {
		
		printf("\nucagin depo haznesi cok genis.Her yil kesinlikle hazne degismeli.!\n") ;
	} 
	
	else {
		
		printf("ucagin depo haznesinin 2 yilda bir degismesi yeterlidir.\n") ;
	}
	
	
}


void ucak_onceligi(){
	int array[30];
	int sayi;
	int temp=array[0];
	int i;
	
printf("Filodaki ucak sayisini giriniz : ");
scanf("%d",&sayi);
for(i=0;i<sayi;i++){
	printf("%d . ucagin ulasacagi maximum hizi girin : ",i+1);
	scanf("%d",&array[i]);	
}	
for(i=0;i<sayi;i++){
	
	if(array[i]>temp){
		temp=array[i];
	}
	
	else{
		temp=temp;
	}
	
    
}
	
	 printf("karargahtaki en hizli ve bu operasyon icin en uygun ucak %d hiza ulasan ucaktir\n\n",temp);
	
	
}
void motor_sicakligi(struct ucak bilgi,struct hedef bilgiler) {
	
	float islem,i,isi ,k;
	printf("\nJet motorlarinin 250 C dereceye kadar sicakliga ulasmasi normal kabul edilir\n Fakat 250 C dereceden sonra soðutucu fan sistemi devreye girer\n");
	printf(" jet motorlari ulastiklari hiza gore yaktiklari yakit miktari degisir");
	islem=sqrt(pow((bilgiler.xkordinati-bilgi.xkordinati),2)+pow((bilgi.ykordinati-bilgiler.ykordinati),2)) ;
	printf("\nmotorun suan ki isisini giriniz\n");
	scanf("%f",&isi);
	// araya && koymadan calismadi 
	if(0<bilgi.hiz&&bilgi.hiz<=400){ printf("\nkm basina 0.10 derece artar");  
	i=islem*0.10 ; 
	k=i+isi;
	printf("\nmotorun isisi %.2f artacak ve %.2f olacak",i,k);}
	else if(400<bilgi.hiz&&bilgi.hiz<=800){ printf("\nkm basina 0.30 derece artar");  
	i=islem*0.30; 
	k=i+isi;
	printf("\nmotorun isisi %.2f artacak ve %.2f olacak",i,k);}
	else if(800<bilgi.hiz&&bilgi.hiz<=1200){ printf("\nkm basina 0.45 derece artar");  
	i=islem*0.45; 
	k=i+isi;
	printf("\nmotorun isisi %.2f artacak ve %.2f olacak",i,k);}
	else if(1200<bilgi.hiz&&bilgi.hiz<=1600){ printf("\nkm basina 0.55 derece artar");  
	i=islem*0.55; 
	k=i+isi;
	printf("\nmotorun isisi %.2f artacak ve %.2f olacak",i,k);}
	
	else if(1600<bilgi.hiz&&bilgi.hiz<=2000){ printf("\nkm basina 0.60 derece artar");  
	i=islem*0.60; 
	k=i+isi;
	printf("\nmotorun isisi %.2f artacak ve %.2f olacak",i,k);}
	else if(2000<bilgi.hiz&&bilgi.hiz<=2400){ printf("\nkm basina 0.70 derece artar");  
	i=islem*0.70; 
	k=i+isi;
	printf("\nmotorun isisi %.2f artacak ve %.2f olacak",i,k);}
	else if(2400<bilgi.hiz&&bilgi.hiz<=2800){ printf("\nkm basina 0.80 derece artar");  
	i=islem*0.80; 
	k=i+isi;
	printf("\nmotorun isisi %.2f artacak ve %.2f olacak",i,k);}
	else{
	 printf("\nkm basina 1 derece artar");  
	i=islem*1; 
	k=i+isi;
	printf("\nmotorun isisi %.2f artacak ve %.2f olacak",i,k);}}
	
	
	void pilot_onceligi(){
		
	float array1[30];
	float array2[30];
	float array3[30];
	int sayi;
	int temp;

	 temp=array3[0];
	
	int i;
	
printf(" karargahdaki pilot sayisini giriniz");
scanf("%d",&sayi);
for(i=0;i<sayi;i++){
	printf("%d . pilotun katildigi basarili operasyon sayisini giriniz",i+1);
	scanf("%d",&array1[i]);	
}
 	printf("\n");
for(i=0;i<sayi;i++){
	printf("%d . pilotun katildigi basarisiz operasyon sayisini giriniz",i+1);
	scanf("%d",&array2[i]);	
}
printf("\n");
for(i=0;i<sayi;i++){
	
	array3[i]=array1[i]/(array1[i]+array2[i]);
	
}
printf("\n");
for(i=0;i<sayi;i++){
	
	printf("%d. pilotun basari orani %.2f dir\n",i+1,array3[i]);
}

for(i=0;i<sayi;i++){
	
	if(array3[i]>temp){
		temp=array3[i];
	}
	
	else{
		temp=temp;
	}
	
    
}

	
  printf("karargahta gorevli ve bu operasyon icin en uygun kisi %.2f barsari derecesine sahip pilottur\n\n",temp);
}

//*******Reyhan********

int hedefsayisi(){
	
	int hedef;
	printf("Hedef sayisini giriniz: ");
	scanf("%d",&hedef);
	return hedef;
}

//***********

void yakit_ikmali(struct ucak bilgi,struct hedef bilgiler){
	
	int answer;
	float islem,zaman ;
	int rastgele;
	printf("Yakit ikmali yapmak istermisiniz(Evet=1/Hayir=0): ");
	scanf("%d",&answer);
	if(answer == 1){
	
		islem=sqrt(pow((bilgiler.xkordinati-bilgi.xkordinati),2)+pow((bilgi.ykordinati-bilgiler.ykordinati),2));
		printf("\nKarargah ile olan uzakligini: %.3f km",islem);
		rastgele = rand();
		printf("\nYakit ikmali için gelen ucagin hizi: %d",rastgele);
		zaman = rastgele/islem;
		printf("\nYakit ikmali icin %d kadar beklemelisiniz.",zaman);
		
	}

}
	//*************Reyhan*************
struct filo degeral4 (struct filo x ){	
	printf ("\n\n\n\nNot : Turkiye'de 10 adet ana jet ussu vardir.\nSeciminizi 1-10 arasinda yapiniz.");
	printf ("\n\nUcagin kalkacagi jet ussunu seciniz : ");
	scanf ("%d" , &x.ussecim);
	if (x.ussecim == 1){
		printf ("1. Jet ussu Eskisehir'de bulunmaktadir.");
		printf ("\nFilo seciniz.\nNot : Eskisehir'de 111. ve 112. Filolar bulunmaktadir.\n");
		scanf ("%d" , &x.filosecim);
		if (x.filosecim == 111){
			printf ("111. Panter Filo'ya ait F-4 Phantom ucagini kaldiracagiz");
		}
		else if (x.filosecim == 112){
			printf ("112. Seytan Filo'ya ait F-4 Phantom ucagini kaldiracagiz");
		}
		else {
			printf ("\nBoyle bir filo bulunmamaktadir.");
		}
	}
		else if (x.ussecim == 2){
		printf ("2. Jet ussu Izmir'de bulunmaktadir.");
		printf ("\nFilo seciniz.\nNot : Izmir'de 121. 122. ve 123. Filolar bulunmaktadir.\n");
		scanf ("%d" , &x.filosecim);
		if (x.filosecim == 121){
			printf ("121. Ari Filo'ya ait ucak T-38 Talon egitim ucagidir.\nBombaardiman icin gorevlendirilemez.");
		}
		else if (x.filosecim == 122){
			printf ("122. Akrep Filo'ya ait ucak T-37 egitim ucagidir.\nBombaardiman icin gorevlendirilemez.");
		}
		else if (x.filosecim == 123){
			printf ("123. Palaz Filo'ya ait ucak SF260D egitim ucagidir.\nBombaardiman icin gorevlendirilemez.");
		}
		else {
			printf ("\nBoyle bir filo bulunmamaktadir.");
		}
	}
		else if (x.ussecim == 3){
		printf ("3. Jet ussu Konya'da bulunmaktadir.");
		printf ("\nFilo seciniz.\nNot : Eskisehir'de 131. 132. 133 ve 134. Filolar bulunmaktadir.\n");
		scanf ("%d" , &x.filosecim);
		if (x.filosecim == 131){
			printf ("131. Ejder Filo'ya ucak B-737 AEW&C Erken Hava Uyari ve Kontrol ucagidir.\nBombaardiman icin gorevlendirilemez. ");
		}
		else if (x.filosecim == 132){
			printf ("132. Hancer Filo'ya ait F-4 Phantom ucagini kaldiracagiz");
		}
		else if (x.filosecim == 133){
			printf ("133. Pence Filo'ya ait F-5 ucagini kaldiracagiz");
		}
		else if (x.filosecim == 134){
			printf ("134. Turk Yildizlari Akrotim Filo'ya ait NF-5 ucagidir.\nBombaardiman icin gorevlendirilemez.");
		}
		else {
			printf ("\nBoyle bir filo bulunmamaktadir.");
		}
	}
	
		else if (x.ussecim == 4){
		printf ("4. Jet ussu Ankara'da bulunmaktadir.");
		printf ("\nFilo seciniz.\nNot : Ankara'da 141. 142. ve 143. Filolar bulunmaktadir.\n");
		scanf ("%d" , &x.filosecim);
		if (x.filosecim == 141){
			printf ("141. Kurt Filo'ya ait F- 16 ucagini kaldiracagiz");
		}
		else if (x.filosecim == 142){
			printf ("142. Ceylan Filo'ya ait F-16 ucagini kaldiracagiz");
		}
		else if (x.filosecim == 112){
			printf ("112. Once Filo'ya ait F-16 ucagini kaldiracagiz");
		}
		else {
			printf ("\nBoyle bir filo bulunmamaktadir.");
		}
	}
	
		else if (x.ussecim == 5){
		printf ("5. Jet ussu Amasya/Merzifon'da bulunmaktadir.");
		printf ("\nFilo seciniz.\nNot : Amasya/Merzifon'da 151. ve 152. Filolar bulunmaktadir.\n");
		scanf ("%d" , &x.filosecim);
		if (x.filosecim == 151){
			printf ("151. Tunç Filo'ya ait F-16 ucagini kaldiracagiz");
		}
		else if (x.filosecim == 152){
			printf ("152. Akinci Filo'ya ait F-16 ucagini kaldiracagiz");
		}
		else {
			printf ("\nBoyle bir filo bulunmamaktadir.");
		}
	}
	
		else if (x.ussecim == 6){
		printf ("6. Jet ussu Balikesir/Bandirma'da bulunmaktadir.");
		printf ("\nFilo seciniz.\nNot : Balikesir/Bandirma'da 161. ve 162. Filolar bulunmaktadir.\n");
		scanf ("%d" , &x.filosecim);
		if (x.filosecim == 161){
			printf ("161. Yarasa Filo'ya ait F-16 ucagini kaldiracagiz");
		}
		else if (x.filosecim == 162){
			printf ("162. Zipkin Filo'ya ait F-16 ucagini kaldiracagiz");
		}
		else {
			printf ("\nBoyle bir filo bulunmamaktadir.");
		}
	}
	
		else if (x.ussecim == 7){
		printf ("7 . Jet ussu Malatya'da bulunmaktadir.");
		printf ("\nFilo seciniz.\nNot : Malatya'da 171. 172. ve 173. Filolar bulunmaktadir.\n");
		scanf ("%d" , &x.filosecim);
		if (x.filosecim == 171){
			printf ("171. Korsan Filo'ya ait F-4 ucagini kaldiracagiz");
		}
		else if (x.filosecim == 172){
			printf ("172. Sahin Filo'ya ait F-4 ucagini kaldiracagiz");
		}
		else if (x.filosecim == 173){
			printf ("173. Safak Filo'ya ait F-4 ucagini kaldiracagiz");
		}		
		else {
			printf ("\nBoyle bir filo bulunmamaktadir.");
		}
	}
	
		else if (x.ussecim == 8){
		printf ("8. Jet ussu Diyarbakir'da bulunmaktadir.");
		printf ("\nFilo seciniz.\nNot : Diyarbakir'da 181. ve 182. Filolar bulunmaktadir.\n");
		scanf ("%d" , &x.filosecim);
		if (x.filosecim == 181){
			printf ("181. Pars Filo'ya ait F-16 ucagini kaldiracagiz");
		}
		else if (x.filosecim == 182){
			printf ("182. Atmaca Filo'ya ait F-16 ucagini kaldiracagiz");
		}
		else {
			printf ("\nBoyle bir filo bulunmamaktadir.");
		}
	}
	
		else if (x.ussecim == 9){
		printf ("9. Jet ussu Balikesir'de bulunmaktadir.");
		printf ("\nFilo seciniz.\nNot : Balikesir'de 191. ve 192. Filolar bulunmaktadir.\n");
		scanf ("%d" , &x.filosecim);
		if (x.filosecim == 191){
			printf ("191. Kobra Filo'ya ait F-16 ucagini kaldiracagiz");
		}
		else if (x.filosecim == 192){
			printf ("192. Kaplan Filo'ya ait F-16 ucagini kaldiracagiz");
		}
		else {
			printf ("\nBoyle bir filo bulunmamaktadir.");
		}
	}
		else if (x.ussecim == 10){
		printf ("10. Jet ussu Adana'da bulunmaktadir.");
		printf ("\nFilo seciniz.\nNot : Adana'da 101. Filo bulunmaktadir.\n");
		scanf ("%d" , &x.filosecim);
		if (x.filosecim == 191){
			printf ("101. Asena Filo'ya ait KC-135R Yakit ikmal ucagidir.\nBombaardiman icin gorevlendirilemez.");
		}
		else {
			printf ("\nBoyle bir filo bulunmamaktadir.");
		}
	}
}
	

		


