#include <stdio.h>



int main() {
    // Inisialisasi PIN awal
    int pin = 9876;
    // Inisialisasi saldo awal
    float balance = 1000000;
    // Inisialisasi variabel-variabel lain yang dibutuhkan
    int choice, login_attempt = 0;
    int transfer_account_number;
    float transfer_amount, top_up_dana, top_up_gopay,
top_up_shope_pay,top_up_pln,
 withdrawal_amount;
 	char nomor_token[50];

    // Loop while untuk mengulang login hingga maksimal 3 kali percobaan
    while (login_attempt < 3) {
        // Meminta pengguna memasukkan PIN
        int input_pin;
        printf("SELAMAT DATANG DI BANK MASYARAKAT SEJAHTERA");
        
        printf("\nHALLO RAKYAT, APA KABAR?");
        
        printf("\nMasukkan PIN Anda: ");
        scanf("%d", &input_pin);
        
        
        // Jika PIN benar, tampilkan menu opsi
        if (input_pin == pin) {
            printf("\nLogin successful!\n");
            while (1) {
                printf("\nATM Menu\n");
                printf("1. Check Balance\n");
                printf("2. Deposit\n");
                printf("3. Withdraw\n");
                printf("4. Transfer\n");
                printf("5. Top Up\n");
                printf("6. Logout\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                
                // Switch case untuk setiap opsi pada menu
                switch (choice) {
                    case 1:
                        printf("Your current balance is: %.2f\n", balance);
                        break;
                    case 2:
                        printf("Enter amount to deposit: ");
                        float deposit_amount;
                        scanf("%f", &deposit_amount);
                        balance -= deposit_amount;
                        printf("Deposit berhasil. Sisa Saldo anda: %.2f\n", balance);
                        break;
                    case 3:
                        printf("Enter amount to withdraw: ");
                        scanf("%f", &withdrawal_amount);
                        if (withdrawal_amount > balance) {
                            printf("Insufficient funds.\n");
                        } else {
                            balance -= withdrawal_amount;
                            printf("Withdrawal successful. Sisa Saldo Anda : %.2f\n", balance);
                        }
                        break;
                    case 4:
                        printf("Masukkan Nomor Rekening Tujuan: ");
                        scanf("%d", &transfer_account_number);
                        printf("Masukkan Jumlah Transfer : ");
                        scanf("%f", &transfer_amount);
                        if (transfer_amount > balance) {
                            printf("Insufficient funds.\n");
                        } else {
                            balance -= transfer_amount;
                            printf("Transfer berhasil. Sisa Saldo anda: %.2f\n", balance);
                        }
                        break;
                    case 5:
                        printf("Top up menu\n");
                        printf("1. Top up Dana\n");
                        printf("2. Top up Gopay\n");
                        printf("3. Top up shope pay\n");
                        printf("4. Top up PLN\n");
                        printf("Enter your choice: ");
                        int top_up_choice;
                        scanf("%d", &top_up_choice);
                        switch (top_up_choice) {
                            case 1:
                                printf("Masukkan Jumlah top up: ");
                                scanf("%f", &top_up_dana);
                                printf("masukkan nomor DANA anda :");
                                scanf("%s", &nomor_token);
                                printf("Masukkan PIN Anda : ");
                                scanf("%d", &pin);
                                printf("TopUp berhasil. Sisa Saldo anda: %.2f\n", balance + top_up_dana);
                                break;
                            case 2:
                                printf("Masukkan Nomor Anda : ");
                                scanf("%f", &top_up_gopay);
                                printf("Masukkan jumlah TopUp :");
                                scanf("%s", &nomor_token);
                                printf("Masukkan PIN ANda : ");
                                scanf("%d", &pin);
                                printf("TopUp berhasil. Sisa Saldo anda: %.2f", balance -= top_up_gopay);
                                break;
                            case 3:
                                 printf("Masukkan Jumlah top up: ");
                                 scanf("%f", &top_up_shope_pay);
                                 printf("masukkan nomor shoppepay anda :");
                                 scanf("%s",nomor_token);
                                
                                printf("Masukkan PIN Anda : ");
                                scanf("%d", &pin);
                                printf("TopUp berhasil. Sisa Saldo anda: %.2f", balance -= top_up_shope_pay);
                                printf("TopUp berhasil. Sisa Saldo anda : %.2f\n", balance);
                                 break;
                            case 4:
                                printf("Masukkan Jumlah TopUp : ");
                                scanf("%f", &top_up_pln);
                                printf("masukkan nomor token :");
                                scanf("%s", &nomor_token);
                                printf("Masukkan PIN Anda : ");
                                scanf("%d", &pin);
                                printf("TopUp berhasil. Sisa Saldo anda : %.2f", balance -= top_up_pln);
                                break;
                            default:
                                printf("Invalid option.\n");
                                break;
                        }
                        break;
                    case 6:
                        // Keluar dari menu dan kembali ke menu login
                        printf("Logout successful.\n");
                        login_attempt = 3;
                        break;
                    default:
                        printf("Invalid option.\n");
                        break;
                }
            }
        } else {
            // Jika PIN salah, tampilkan pesan error dan tingkatkan jumlah percobaan
            printf("Invalid PIN. Please try again.\n");
            login_attempt++;
        }
    }
    // Jika sudah 3 kali percobaan login dan masih gagal, keluar dari program
    if (login_attempt == 3) {
        printf("Too many failed attempts. ATM locked.\n");
    }
    return 0;
    
    	
}