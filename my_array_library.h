#ifndef my_array_library_h_
#define my_array_library_h_

//*******Görkem********

struct ucak {
	
	int ykordinati  ;
	int hiz ;
	int xkordinati ;
	int zkordinati;

};


struct hedef {
	
	int ykordinati  ;
	int xkordinati ;
	int zkordinati ;
	int fuzesayisi;
};



struct ucakbilgileri {
	
	 float depo ;
	 int uretimyili;
	 float kilometre;
	 

};


//*******Reyhan******

struct filo {
	int ussecim;
	int filosecim;
};


void bastir(struct ucak a) ;
struct ucak degeral(struct ucak bilgi) ;
void bastir2(struct hedef c) ;
struct hedef degeral2(struct hedef bilgiler) ;
void hesap (struct ucak bilgi, struct hedef bilgiler);
void yol(struct ucak bilgi,struct hedef bilgiler) ;
void yakit(struct ucak bilgi,struct hedef bilgiler) ;
void pilot_onceligi();
void kordinatbulma (struct ucak bilgi, struct hedef bilgiler);
void motor_sicakligi(struct ucak bilgi,struct hedef bilgiler);
void fuzebirak (struct hedef bilgiler);
void ucak_onceligi();
void degeral3(struct ucakbilgileri *p);
void goster3(struct ucakbilgileri *p);
void degerlendirme(struct ucakbilgileri *p);
int hedefsayisi();
void yakit_ikmali(struct ucak bilgi,struct hedef bilgiler);
struct filo degeral4 (struct filo x );
#endif




