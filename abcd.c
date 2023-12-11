

#include <stdio.h>
#include<string.h>

void profileadmin();
void profileuser();
void registrasiuser();
void loginuser();

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
                // profileuser();
                break;
            case 3:
                printf("Program selesai \n");
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
void profileuser(){
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
        
    }

}
