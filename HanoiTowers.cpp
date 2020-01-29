#include <stdio.h>
#define SIZE 4 // Kaç disk için oynanmasını istiyorsanız SIZE değerini o kadar girin. 
int adim = 0;
struct stack {
	int veri[SIZE];
	int sayac;
}
a[3]; // üç direk
int pop(stack* d) {
	d->sayac--;
	return d->veri[d->sayac];
}
void push(stack* d, int veri) {
	d->veri[d->sayac] = veri;
	d->sayac++;
	//printf("push %d", veri);
}
int top(stack* d) {
	return d->veri[d->sayac - 1];
}
int ilkdisk() {             // Oyunun çözümü iki adımdan oluşur.Sürekli bu iki adım birbirini takip eder.
	for (int i = 0; i < 3; i++) // Birinci adım birinci diski doğru hareket ettirmek.
		if (top(&a[i]) == 1) // Burada birinci adımın fonksiyonunu yazdık.
			return i;
}
int enkucukdisk() {
	int ekdisk = 100; //Oyunun çözümünün ikinci adımının fonksiyonudur.
	int ekdirek = 0; //Amaç birinci diskten sonraki en küçük diski doğru oynatmaktır.
	for (int i = 0; i < 3; i++)
		if (top(&a[i]) < ekdisk && top(&a[i]) > 1 && a[i].sayac != 0)
		{
			ekdisk = top(&a[i]);
			ekdirek = i;
		}
	return ekdirek;
}

int oyunkontrol(stack* direk1, stack* direk2) {
	if (direk2->sayac <= 0) //Oyunun kurallarından büyük disk küçük diskin üstüne gelmemeli
		return 1; //kontolü burada yapıldı.
	if (top(direk1) < top(direk2))
		return 1;
	return 0;
}
int oyunbittimi() {
	if (a[0].sayac <= 0 && a[1].sayac == SIZE) // Birinci direğin boş olup tüm disklerin farklı bir direkte doğru bir şekilde olmasını
		return 1; // kontrol eder.
	if (a[0].sayac <= 0 && a[2].sayac == SIZE)
		return 1;
	return 0;
}
void print() {
	printf("step %d \n", adim);
	for (int i = 0; i < 3; i++) {
		printf("pole %d --->    ", i + 1);

		for (int j = 0; j < a[i].sayac; j++) {
			printf("%d \t", a[i].veri[j]);

		}
		printf("\n");



	}
}
void oyna(stack* kimden, stack* kime) { // Tüm kurallar kontrol edildikten sonra diski oynattığımız fonksiyondur.
	push(kime, pop(kimden));
	adim++;
	print();
}

int main() {

	for (int i = 0; i < 3; i++) // Direklerin(stack) sayaçlarını sıfırladık.
		a[i].sayac = 0;
	for (int i = SIZE; i > 0; i--) // Oynamak istediğimiz disk sayısı kadar birinci direğe(stack) eleman ekliyoruz.
		push(&a[0], i);
	print();
	while (!oyunbittimi()) { // Oyun bitmediyse diskleri hareket ettirmeye devam eder.
		int kimden = ilkdisk();
		int kime = kimden;
		while (!oyunkontrol(&a[kimden], &a[kime])) { // Oynatacağımız diski kurallara uygun direğe taşıma işlemi.
			kime++; // Bu while oyunumuzun birinci adımını kullanır.
			if (kime > 2)
				kime = 0;
		}
		printf("------------------------------------------------------------------- \n");
		printf("from %d to %d \n", kimden + 1, kime + 1);
		oyna(&a[kimden], &a[kime]); // Kurallara uygun direği bulduğumuzda diski hareket ettiriyoruz.
		if (oyunbittimi())
			break;
		kimden = enkucukdisk();
		kime = kimden;
		while (!oyunkontrol(&a[kimden], &a[kime])) { //Bu while oyunumuzun ikinci adımını kullanır.
			kime++;
			if (kime > 2)
				kime = 0;
		}
		printf("------------------------------------------------------------------- \n");
		printf("from %d to %d \n", kimden + 1, kime + 1);
		oyna(&a[kimden], &a[kime]);  // Kurallara uygun direği bulduğumuzda diski hareket ettiriyoruz.
	}
	printf("------------------------------------------------------------------- \n");
	printf("Game Over Thank You For Playing \n");
}