#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void profileadmin();
void profileUser();
void registrasiuser();
void menulogin();
void loginuser();
// void menuUser();
// Definisi struktur untuk kendaraan
struct Kendaraan {
    char jenis[50];
    float harga;
    char jenisService[50];
};
// Definisi struktur untuk pesanan user
struct Pesanan {
    char username[50];
    char jenisKendaraan[50];
    char jenisService[50];
    float totalPembayaran;
    char progress[50];
};

int main() {
    int pilihan;

    do {
        // Menampilkan menu
        printf("Menu:\n");
        printf("1. Admin\n");
        printf("2. User\n");
        printf("3. Keluar\n");
        printf("Pilih menu (1-3): ");
        scanf("%d", &pilihan);getchar();

        // Menggunakan switch case untuk menangani pilihan
        switch (pilihan) {
            case 1:
                printf("Anda memilih menu Admin.\n\n");
                profileadmin();
                break;
            case 2:
                printf("Anda memilih menu User.\n");
                profileUser();
                break;
            case 3:
                printf("Program selesai \n");;
                break;
            default:
                printf("Pilihan tidak ada. Silakan pilih lagi.\n");
        }

    } while (pilihan != 3);  // Loop terus menerus hingga pengguna memilih Keluar (3)

    return 0;
}

void profileadmin(){

    char username[50], password[50];
    int statuslogin = 0; 
    do {
        printf("Silahkan masukkan username dan password\n\n");
        printf("Username : "); gets(username);

        printf("Password : "); gets(password);

        // Memeriksa apakah username dan password admin sesuai
        if (strcmp(username, "ADMIN") == 0 && strcmp(password, "admin123") == 0) {
            printf("Login admin berhasil!\n");
           //void menu_admin();
            statuslogin = 1;  
        } else {
            printf("Login gagal. Username atau password salah. Silakan coba lagi.\n");
        }
    } while (statuslogin != 1);
}

void profileUser(){
    int Pilihmenu;
    printf("Menu User:\n");
    printf("1. Registrasi\n");
    printf("2. Login\n");
    printf("Pilih menu (1-2): ");
    scanf("%d", &Pilihmenu);

    switch(Pilihmenu){
        case 1:
        registrasiuser();
        break;

        case 2:
        loginuser();
        break;
        
    }

}

void registrasiuser() {
    char username[50], password[50], nama[50], email[50], noTelepon[15];

    printf("Silahkan Registrasi User\n\n");
    printf("Username : ");
    scanf("%s", username);

    printf("Password : ");
    scanf("%s", password);

    printf("Nama Lengkap : ");
    scanf("%s", nama);

    printf("Email : ");
    scanf("%s", email);

    printf("No Telepon : ");
    scanf("%s", noTelepon);

    // Menyimpan data ke dalam file sekuensial
    FILE *file = fopen("userdata.dat", "wb");
    if (file != NULL) {
        fprintf(file, "%s %s %s %s %s\n", username, password, nama, email, noTelepon);
        fclose(file);
        printf("Registrasi berhasil!\n");
        loginuser();
    } else {
        printf("Error: Tidak dapat membuka file untuk penyimpanan data.\n");
    }
}

void menulogin() {
    int pilihanlogin;

    printf("\nMENU\n");
    printf("\n1. Login");
    printf("\n2. Lupa Password");
    printf("\nPilih menu : "); scanf("%d", &pilihanlogin);

    switch(pilihanlogin){
        case 1:
        loginuser();
        break;

        case 2:
        // lupapassword();
        break;
    }
}
void loginuser() {
    char username[50], password[50];
    char fileUsername[50], filePassword[50], fileNama[50], fileEmail[50], fileNoTelepon[15];
    int attempt = 3;

    for (attempt; attempt > 0; attempt--) {
        printf("\nSilahkan Login User\n\n");
        printf("Username : ");
        scanf("%s", &username);

        printf("Password : ");
        scanf("%s", &password);

        FILE *file = fopen("userdata.txt", "rb");
        if (file != NULL) {
            while (fscanf(file, "%s %s %s %s %s", fileUsername, filePassword, fileNama, fileEmail, fileNoTelepon) != EOF) {
                if (strcmp(username, fileUsername) == 0 && strcmp(password, filePassword) == 0) {
                    printf("\nSelamat login berhasil\n");
                    fclose(file);
                    // menuUser();
                    return;
                }
            }
            fclose(file);
        } else {
            printf("Error: Tidak dapat membaca file data user.\n");
            return;
        }

        printf("Username atau password salah. Sisa percobaan: %d\n", attempt-1);

        int choice;
        printf("Pilihan:\n");
        printf("1. Coba lagi\n");
        printf("2. Lupa Password\n");
        printf("Pilih (1-2): ");
        scanf("%d", &choice);

        if (choice == 2) {
            // lupaPassword();
            return;
        }
    }

    printf("Anda telah melebihi batas percobaan. Login dibatalkan.\n");
}

// Fungsi menu admin
void menuAdmin() {
    int adminChoice;

    do {
        printf("\n========== MENU ADMIN ==========\n");
        printf("1. Tambah Kendaraan\n");
        printf("2. Lihat Data User/Pelanggan\n");
        printf("3. Lihat Progress Kendaraan\n");
        printf("4. Ubah Progress Cucian User\n");
        printf("5. Kembali ke Menu Utama\n");
        printf("Pilih menu: ");
        scanf("%d", &adminChoice);

        switch (adminChoice) {
            case 1:
                // Implementasi tambah kendaraan di sini
                tambahKendaraan();
                break;

            case 2:
                // Implementasi lihat data user/pelanggan di sini
                lihatDataUser();
                break;

            case 3:
                // Implementasi lihat progress kendaraan di sini
                lihatProgressKendaraan();
                break;

            case 4:
                // Implementasi ubah progress cucian user di sini
                UbahProgress();
                break;

            case 5:
                printf("Kembali ke Menu Utama.\n");
                break;

            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }

    } while (adminChoice != 5);
}

// Fungsi untuk menambahkan kendaraan
void tambahKendaraan() {
    FILE *fileKendaraan = fopen("kendaraan.dat", "a");
    struct Kendaraan newKendaraan;

    printf("Masukkan jenis kendaraan: ");
    scanf("%s", newKendaraan.jenis);
    printf("Masukkan harga: ");
    scanf("%f", &newKendaraan.harga);
    printf("Masukkan jenis service: ");
    scanf("%s", newKendaraan.jenisService);

    fwrite(&newKendaraan, sizeof(struct Kendaraan), 1, fileKendaraan);

    fclose(fileKendaraan);
}

// Fungsi untuk melihat data user/pelanggan
void lihatDataUser() {
    FILE *fileUser = fopen("user.dat", "r");
    struct Pesanan readUser;

    printf("\n========== DATA USER/PELANGGAN ==========\n");
    printf("%-20s %-15s %-20s %-20s %-20s\n", "Username", "Jenis Kendaraan", "Jenis Service", "Total Pembayaran", "Progress");

    while (fread(&readUser, sizeof(struct Pesanan), 1, fileUser) == 1) {
        printf("%-20s %-15s %-20s %-20.2f %-20s\n", readUser.username, readUser.jenisKendaraan, readUser.jenisService, readUser.totalPembayaran, readUser.progress);
    }

    fclose(fileUser);
}

// Fungsi untuk melihat  kendaraan
void lihatProgressKendaraan() {
    FILE *fileKendaraan = fopen("kendaraan.dat", "r");
    struct Kendaraan readKendaraan;

    printf("\n========== Progress Cucian KENDARAAN ==========\n");
    printf("%-20s %-10s %-20s\n", "Jenis Kendaraan", "Harga", "Jenis Service");

    while (fread(&readKendaraan, sizeof(struct Kendaraan), 1, fileKendaraan) == 1) {
        printf("%-20s %-10.2f %-20s\n", readKendaraan.jenis, readKendaraan.harga, readKendaraan.jenisService);
    }

    fclose(fileKendaraan);
}

// Fungsi untuk mengubah progress cucian user
void UbahProgress() {
    FILE *fileUser = fopen("user.dat", "r+");
    struct Pesanan readUser;

    char targetUsername[50];

    printf("Masukkan username user yang ingin diubah progress: ");
    scanf("%s", targetUsername);

    int found = 0;

    while (fread(&readUser, sizeof(struct Pesanan), 1, fileUser) == 1) {
        if (strcmp(readUser.username, targetUsername) == 0) {
            found = 1;

            printf("Progress Cucian saat ini: %s\n", readUser.progress);

            // Ubah progress
            printf("Masukkan progress baru: ");
            scanf("%s", readUser.progress);

            fseek(fileUser, sizeof(struct Pesanan), SEEK_CUR);
            fwrite(&readUser, sizeof(struct Pesanan), 1, fileUser);

            printf("Progress Cucian berhasil diubah.\n");
            break;
        }
    }

    if (!found) {
        printf("User dengan username %s tidak ditemukan.\n", targetUsername);
    }

    fclose(fileUser);
}

// ...

int main() {
    int choice;

    while (1) {
        printf("\n========== APLIKASI D'WASH ==========\n");
        printf("1. Login Admin\n");
        printf("2. Lihat Data User/Pelanggan\n");
        printf("3. Tambah Kategori Kendaraan\n");
        printf("4. Lihat Data Kendaraan\n");
        printf("5. Kembali ke Menu Utama\n");
        printf("Pilih menu: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (loginAdmin()) {
                    menuAdmin();
                } else {
                    printf("Login admin gagal.\n");
                }
                break;

            case 2:
                lihatDataUser();
                break;

            case 3:
                tambahKendaraan();
                break;

            case 4:
                lihatProgressKendaraan();
                break;

            case 5:
                printf("Terima kasih! Program selesai.\n");
                exit(0);

            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }

    return 0;
}
