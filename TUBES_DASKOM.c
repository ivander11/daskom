#include <stdio.h>
#include <string.h>

void profileadmin();
void profileUser();
void registrasiuser();
void menulogin();
void loginuser();
// void menuUser();

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
void loginuser(){
    char username[50], password[50];
    char fileUsername[50], filePassword[50], fileNama[50], fileEmail[50], fileNoTelepon[15];
    int loginSuccess = 0, attempt = 2;


    printf("Silahkan Login User\n\n");
    printf("Username : ");
    scanf("%s", &username);

    printf("Password : ");
    scanf("%s", password);

    // Membaca data dari file sekuensial
    FILE *file = fopen("userdata.dat", "rb");
    if (file != NULL) {
        while (fscanf(file, "%s %s %s %s %s", fileUsername, filePassword, fileNama, fileEmail, fileNoTelepon) != EOF) {
            // Memeriksa apakah username dan password user sesuai
            if (strcmp(username, fileUsername) == 0 && strcmp(password, filePassword) == 0) {
                loginSuccess = 1;
                printf("\nSelamat login berhasil\n");
                // menuUser();
                break;
            }else {
                printf("Username atau password salah.");
            }
        }
        fclose(file);
    }else {
        printf("Error: Tidak dapat membaca file data user.\n");
    }
}


