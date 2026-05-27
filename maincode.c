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
    for (int i = 0; i < n; i++) {
        toplam += notlar[i];
    }
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
    int ogrenci_sayisi;

    printf("Kac ogrenci gireceksiniz? (Maksimum %d): ", MAX_OGRENCI);
    scanf("%d", &ogrenci_sayisi);
    
    while (getchar() != '\n'); 

    for (int i = 0; i < ogrenci_sayisi; i++) {
        printf("\n--- %d. Ogrenci Bilgileri ---\n", i + 1);
        
        printf("Ad Soyad: ");
        // fgets kullanarak boşluklu isimleri de (örn: Ahmet Yılmaz) güvenle alabiliyoruz
        fgets(ogrenciler[i].ad, sizeof(ogrenciler[i].ad), stdin);
        // fgets'in sonuna eklediği yeni satır (\n) karakterini temizliyoruz
        ogrenciler[i].ad[strcspn(ogrenciler[i].ad, "\n")] = 0;

        printf("Numara: ");
        scanf("%d", &ogrenciler[i].numara);

        printf("5 adet notu aralarında bosluk birakarak giriniz: ");
        for (int j = 0; j < 5; j++) {
            scanf("%f", &ogrenciler[i].notlar[j]);
        }
        
        while (getchar() != '\n'); 
        ogrenciler[i].ortalama = ortalama_hesapla(ogrenciler[i].notlar, 5);
    }
    printf("\n%-20s %-10s %-10s %-5s\n", "Ad Soyad", "Numara", "Ortalama", "Harf");
    printf("%-20s %-10s %-10s %-5s\n", "--------", "------", "--------", "----");

    for (int i = 0; i < ogrenci_sayisi; i++) {
        printf("%-20s %-10d %-10.2f %-5s\n",
               ogrenciler[i].ad,
               ogrenciler[i].numara,
               ogrenciler[i].ortalama,
               harf_notu(ogrenciler[i].ortalama));
    }
    FILE *dosya = fopen("ogrenciler.txt", "w");
    
    if (dosya == NULL) {
        printf("\nHata: Dosya olusturulamadi!\n");
        return 1;
    }

    // Dosyanın içine başlıkları yazdırıyoruz
    fprintf(dosya, "%-20s %-10s %-10s %-5s\n", "Ad Soyad", "Numara", "Ortalama", "Harf");
    fprintf(dosya, "%-20s %-10s %-10s %-5s\n", "--------", "------", "--------", "----");

    // Öğrenci verilerini döngüyle dosyanın içine satır satır basıyoruz
    for (int i = 0; i < ogrenci_sayisi; i++) {
        fprintf(dosya, "%-20s %-10d %-10.2f %-5s\n",
                ogrenciler[i].ad,
                ogrenciler[i].numara,
                ogrenciler[i].ortalama,
                harf_notu(ogrenciler[i].ortalama));
    }
    FILE *dosya = fopen("ogrenciler.txt", "w");
    
    if (dosya == NULL) {
        printf("\nHata: Dosya olusturulamadi!\n");
        return 1;
    }

    // Dosyanın içine başlıkları yazdırıyoruz
    fprintf(dosya, "%-20s %-10s %-10s %-5s\n", "Ad Soyad", "Numara", "Ortalama", "Harf");
    fprintf(dosya, "%-20s %-10s %-10s %-5s\n", "--------", "------", "--------", "----");

    // Öğrenci verilerini döngüyle dosyanın içine satır satır basıyoruz
    for (int i = 0; i < ogrenci_sayisi; i++) {
        fprintf(dosya, "%-20s %-10d %-10.2f %-5s\n",
                ogrenciler[i].ad,
                ogrenciler[i].numara,
                ogrenciler[i].ortalama,
                harf_notu(ogrenciler[i].ortalama));
    }

    FILE *dosya = fopen("ogrenciler.txt", "w");
    
    if (dosya == NULL) {
        printf("\nHata: Dosya olusturulamadi!\n");
        return 1;
    }

    fprintf(dosya, "%-20s %-10s %-10s %-5s\n", "Ad Soyad", "Numara", "Ortalama", "Harf");
    fprintf(dosya, "%-20s %-10s %-10s %-5s\n", "--------", "------", "--------", "----");

    for (int i = 0; i < ogrenci_sayisi; i++) {
        fprintf(dosya, "%-20s %-10d %-10.2f %-5s\n",
                ogrenciler[i].ad,
                ogrenciler[i].numara,
                ogrenciler[i].ortalama,
                harf_notu(ogrenciler[i].ortalama));
    }
    
    fclose(dosya); 
    printf("\nVeriler 'ogrenciler.txt' dosyasina basariyla kaydedildi!\n");

    return 0;
    
    return 0;
}
