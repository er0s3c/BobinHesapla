#include <iostream>
#include <cmath>
#include <cstdlib> // system fonksiyonu için gerekli

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

void bobinUzunluguHesapla() {
    double ozkutle, kalinlik, agirlik, genislik;
    double uzunluk;

    // Kullanıcıdan gerekli bilgileri alma
    cout << "Bobin özkütle (gr/cm^3): ";
    cin >> ozkutle;

    cout << "Bobin kalınlığı (mm): ";
    cin >> kalinlik;

    cout << "Bobin ağırlığı (kg): ";
    cin >> agirlik;

    cout << "Bobin genişliği (mm): ";
    cin >> genislik;

    // Bobin uzunluğunu hesaplama
    uzunluk = (agirlik * 1000000) / (ozkutle * genislik * kalinlik);

    // Sonucu ekrana yazdırma
    cout << "Bobin uzunluğu: " << uzunluk << " mm" << endl;

    // Konsolu temizle
    //system("clear"); // Linux/MacOS için
    //system("cls"); // Windows için
}

void dilimAgirligiHesapla() {
    double bobin_agirligi, bobin_genisligi, dilim_genisligi, sonuc;

    // Kullanıcıdan gerekli bilgileri alma
    cout << "Bobin Ağırlığı (kg): ";
    cin >> bobin_agirligi;

    cout << "Bobin Genişliği (mm): ";
    cin >> bobin_genisligi;

    cout << "Dilim Genişliği (mm): ";
    cin >> dilim_genisligi;

    // Dilim ağırlığını hesaplama
    sonuc = bobin_agirligi * (dilim_genisligi / bobin_genisligi);

    // Sonucu ekrana yazdırma
    cout << "Sonuç: " << sonuc << endl;

    // Konsolu temizle
    //system("clear"); // Linux/MacOS için
    // system("cls"); // Windows için
}

void paketYuksekligiHesapla() {
    double ozkutle, paketAgirligi, levhaBoyu, levhaGenisligi, paketYuksekligi;

    // Kullanıcıdan gerekli bilgileri alma
    cout << "Özkütleyi giriniz (gr/cm^3): ";
    cin >> ozkutle;
    cout << "Paket ağırlığını giriniz (kg): ";
    cin >> paketAgirligi;
    cout << "Levha boyunu giriniz (mm): ";
    cin >> levhaBoyu;
    cout << "Levha genişliğini giriniz (mm): ";
    cin >> levhaGenisligi;

    // Birimlerin dönüştürülmesi
    ozkutle *= 1000;   // gr/cm^3'ü kg/m^3'e dönüştürmek için
    levhaBoyu *= 0.001;       // mm'yi m'ye dönüştürmek için
    levhaGenisligi *= 0.001;  // mm'yi m'ye dönüştürmek için

    // Paket yüksekliğinin hesaplanması (metre cinsinden)
    paketYuksekligi = paketAgirligi / (ozkutle * levhaBoyu * levhaGenisligi);
    paketYuksekligi *= 1000;  // mm cinsine dönüştürme

    // Sonucun yazdırılması
    cout << "Paket yüksekliği: " << paketYuksekligi << " mm" << endl;

    // Konsolu temizle
   // system("clear"); // Linux/MacOS için
    // system("cls"); // Windows için
}

void ruloUzunluk(){

    double ruloYaricap, bobinYaricap, malzemeKalinligi;
    double ruloUzunlugu;

    // Kullanıcıdan girişleri al
    cout << "Rulo yarıçapını (mm) giriniz: ";
    cin >> ruloYaricap;

    cout << "Bobinin yarıçapını (mm) giriniz: ";
    cin >> bobinYaricap;

    cout << "Malzeme kalınlığını (mm) giriniz: ";
    cin >> malzemeKalinligi;

    // Rulo uzunluğunu hesapla
    double ruloYariCapKare = pow(ruloYaricap, 2);
    double bobinYariCapKare = pow(bobinYaricap, 2);
    double malzemeYariCapKare = pow(malzemeKalinligi / 2, 2);

    // Sarım sayısını hesapla
    double sarimSayisi = (ruloYaricap - bobinYaricap) / malzemeKalinligi;

    ruloUzunlugu = (M_PI * (pow(ruloYaricap, 2) - pow(bobinYaricap, 2))) / malzemeKalinligi;

    // Sonucu ekrana yazdır
    cout << "Rulo uzunluğu: " << ruloUzunlugu << " mm" << endl;
    cout << "Sarım Sayısı:" << sarimSayisi << " tur" << endl;
}

void malzemeKalinligi() {

    // Kullanıcıdan giriş al
    double ruloRadius, bobinRadius, ruloUzunlugu;
    cout << "Rulo yarıçapını (mm) girin: ";
    cin >> ruloRadius;
    cout << "Bobin yarıçapını (mm) girin: ";
    cin >> bobinRadius;
    cout << "Rulo uzunluğunu (mm) girin: ";
    cin >> ruloUzunlugu;

    // Malzeme kalınlığını hesapla
    double malzemeKalınlığı = (M_PI * (pow(ruloRadius, 2) - pow(bobinRadius, 2))) / ruloUzunlugu;

    // Sonucu yazdır
    cout << "Malzeme Kalınlığı (mm): " << malzemeKalınlığı << endl;

}

int main() {
    setlocale(LC_ALL, "Turkish");

    char secim;

    do {
        cout << "Lütfen yapmak istediğiniz işlemi seçin:" << endl;
        cout << "1. Bobin Uzunluğunu Hesapla" << endl;
        cout << "2. Dilim Ağırlığını Hesapla" << endl;
        cout << "3. Paket Yüksekliğini Hesapla" << endl;
        cout << "4. Rulo Uzunluğunu Hesapla" << endl;
        cout << "5. Malzeme Kalınlığını Hesapla" << endl;
        cout << "Q. Çıkış" << endl;
        cout << "Seçiminiz: ";
        cin >> secim;

        switch (secim) {
        case '1':
            bobinUzunluguHesapla();
            break;
        case '2':
            dilimAgirligiHesapla();
            break;
        case '3':
            paketYuksekligiHesapla();
            break;
            
        case '4':
            ruloUzunluk();
            break;
        case '5':
            malzemeKalinligi();
            break;
        case 'Q':
        case 'q':
            cout << "Programdan çıkılıyor..." << endl;
            break;
        default:
            cout << "Geçersiz seçim. Lütfen tekrar deneyin." << endl;
        }

    } while (secim != 'Q' && secim != 'q');

    return 0;
}
