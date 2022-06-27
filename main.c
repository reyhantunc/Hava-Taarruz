#include <stdio.h>
#include <stdlib.h>
#include "my_array_library.h"



int main(int argc, char *argv[]) {
	
	int temp,i;
	printf ("\nMuhendisler tararfindan olustulan kullanmakta oldugunuz program ile pilot tarafinfan \ngirilen veriler ile bombanin birakilmasi gereken koordinatlar hesaplanmistir.");
	printf ("\n\nUcagin koordinatlarini girerken ulke sinirlarinin 26-45 Dogu ve 36-42 Guney odugunu unutmayiniz.!!\n");
	struct filo filo1 ;

	filo1=degeral4 (filo1);	
	ucak_onceligi();
	pilot_onceligi();
	struct ucak ucak1;
	ucak1=degeral(ucak1) ;
    bastir(ucak1) ;		
//----------------------------------------
    
   	struct hedef hedef1;
	temp = hedefsayisi();
	if (temp ==1){
		hedef1=degeral2(hedef1) ;
		bastir2(hedef1);
		hesap(ucak1, hedef1);
		yol(ucak1,hedef1) ;
    	yakit(ucak1,hedef1) ;
    	yakit_ikmali(ucak1, hedef1);
    	motor_sicakligi(ucak1,hedef1);
    	kordinatbulma(ucak1,hedef1) ;
    	fuzebirak(hedef1);
	}
	else{
		printf("Toplam %d hedef için bilgi alýnacak.",temp);
		for(i=0;i<temp;i++){
			hedef1=degeral2(hedef1) ;
			bastir2(hedef1);
			hesap(ucak1, hedef1);
			yol(ucak1,hedef1) ;
    		yakit(ucak1,hedef1) ;
    		yakit_ikmali(ucak1, hedef1);
    		motor_sicakligi(ucak1,hedef1);
    		kordinatbulma(ucak1,hedef1) ;
    		fuzebirak(hedef1);
		}
	}		
	
	
	struct ucakbilgileri ucakbilgileri1;
	   
    degeral3(&ucakbilgileri1) ;
    goster3(&ucakbilgileri1) ;
	degerlendirme(&ucakbilgileri1) ;
	




	return 0;
}

