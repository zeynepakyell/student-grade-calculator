#include <stdio.h>
#include <string.h>

#define MAX_OGRENCI 50

typedef struct {
    char ad[50];
    int numara;
    float notlar[5];
    float ortalama;
} Ogrenci;

float ortalama_hesapla(float notlar[], int n) {
    float toplam = 0;
    for (int i = 0; i < n; i++)
        toplam += notlar[i];
    return toplam / n;
}

const char* harf_notu(float ort) {
    if (ort >= 90) return "AA";
    if (ort >= 80) return "BA";
    if (ort >= 70) return "BB";
    if (ort >= 60) return "CB";
    if (ort >= 50) return "CC";
    return "FF";
}

int main() {
    Ogrenci ogrenciler[MAX_OGRENCI];
    int sayi = 3;

    // Örnek veri
    strcpy(ogrenciler[0].ad, "Ahmet Yılmaz");
    ogrenciler[0].numara = 2021001;
    float n0[] = {85, 90, 78, 92, 88};
    memcpy(ogrenciler[0].notlar, n0, sizeof(n0));

    strcpy(ogrenciler[1].ad, "Zeynep Kaya");
    ogrenciler[1].numara = 2021002;
    float n1[] = {70, 65, 72, 68, 75};
    memcpy(ogrenciler[1].notlar, n1, sizeof(n1));

    strcpy(ogrenciler[2].ad, "Murat Demir");
    ogrenciler[2].numara = 2021003;
    float n2[] = {45, 55, 50, 48, 52};
    memcpy(ogrenciler[2].notlar, n2, sizeof(n2));

    printf("%-20s %-10s %-10s %-5s\n",
           "Ad Soyad", "Numara", "Ortalama", "Harf");
    printf("%-20s %-10s %-10s %-5s\n",
           "--------", "-------", "--------", "----");

    for (int i = 0; i < sayi; i++) {
        ogrenciler[i].ortalama =
            ortalama_hesapla(ogrenciler[i].notlar, 5);
        printf("%-20s %-10d %-10.2f %-5s\n",
               ogrenciler[i].ad,
               ogrenciler[i].numara,
               ogrenciler[i].ortalama,
               harf_notu(ogrenciler[i].ortalama));
    }

    return 0;
}
