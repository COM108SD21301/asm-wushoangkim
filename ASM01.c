#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Hàm tính UCLN
int ucln(int a, int b) {
    a = abs(a); b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Hàm tính BCNN
int bcnn(int a, int b) {
    return (abs(a) * abs(b)) / ucln(a, b);
}

// Xóa buffer đầu vào
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// XÓA SẠCH HOÀN TOÀN MÀN HÌNH + SCROLLBACK (100% trên Codespaces)
void clearScreen() {
    printf("\033[2J\033[3J\033[H");
    fflush(stdout);
}

// In lại menu (để không phải copy-paste nhiều lần)
void printMenu() {
    clearScreen();
    printf("\n         MENU \n");
    printf("_____________________\n");
    printf("1. Kiểm tra số nguyên/số thực\n");
    printf("2. Tìm UCLN và BCNN của 2 số\n");
    printf("3. Tính tiền quán Karaoke\n");
    printf("4. Tính tiền điện\n");
    printf("5. Vay tiền ngân hàng\n");
    printf("6. Coming soon...\n");
    printf("0. Thoát chương trình\n");
    printf("_____________________\n");
}

int main() {
    int luaChon;

    // Hiển thị menu lần đầu
    printMenu();

    do {
        printf("Mời bạn nhập lựa chọn: ");
        scanf("%d", &luaChon);
        clearInputBuffer();

        switch (luaChon) {
            case 1: {
                clearScreen();
                int tiepTuc;
                do {
                    float x;
                    printf("\n--- Kiểm tra số ---\n");
                    printf("Mời bạn nhập số x: ");
                    scanf("%f", &x);
                    clearInputBuffer();

                    if (x == (int)x) {
                        int n = (int)x;
                        printf("%.0f là số nguyên\n", x);

                        if (n >= 0) {
                            int can = (int)sqrt(n);
                            if (can * can == n)
                                printf("%.0f là số chính phương\n", x);
                        }

                        if (n < 2) {
                            printf("%.0f không phải số nguyên tố\n", x);
                        } else {
                            int laNT = 1;
                            for (int i = 2; i <= sqrt(n); i++) {
                                if (n % i == 0) { laNT = 0; break; }
                            }
                            printf(laNT ? "%.0f là số nguyên tố\n" : "%.0f không phải số nguyên tố\n", x);
                        }
                    } else {
                        printf("%.2f là số thực\n", x);
                    }

                    printf("\nBạn có muốn kiểm tra số khác? (1: Có / 0: Không): ");
                    scanf("%d", &tiepTuc);
                    clearInputBuffer();
                    if (tiepTuc == 1) clearScreen();
                } while (tiepTuc == 1);
                printMenu();
                break;
            }

            case 2: {
                clearScreen();
                int tiepTuc;
                do {
                    int a, b;
                    printf("\n--- Tính UCLN và BCNN ---\n");
                    printf("Nhập số thứ nhất: "); scanf("%d", &a);
                    printf("Nhập số thứ hai: "); scanf("%d", &b);

                    int u = ucln(a, b);
                    int bcn = bcnn(a, b);
                    printf("UCLN của %d và %d = %d\n", a, b, u);
                    printf("BCNN của %d và %d = %d\n", a, b, bcn);

                    printf("\nBạn có muốn tính cặp số khác? (1: Có / 0: Không): ");
                    scanf("%d", &tiepTuc);
                    clearInputBuffer();
                    if (tiepTuc == 1) clearScreen();
                } while (tiepTuc == 1);
                printMenu();
                break;
            }

            case 3: {
                clearScreen();
                int tiepTuc;
                do {
                    int gioBatDau, gioKetThuc;
                    printf("\n--- Tính tiền Karaoke ---\n");
                    printf("Nhập giờ bắt đầu (0-23): ");
                    scanf("%d", &gioBatDau);
                    printf("Nhập giờ kết thúc (0-23): ");
                    scanf("%d", &gioKetThuc);

                    if (gioBatDau < 0 || gioBatDau > 23 || gioKetThuc < 0 || gioKetThuc > 23 || gioKetThuc <= gioBatDau) {
                        printf("Giờ không hợp lệ!\n");
                    } else {
                        int soGio = gioKetThuc - gioBatDau;
                        float donGia = (gioBatDau >= 14 && gioBatDau <= 17) ? 45000 : 30000;
                        float tongTien = soGio * donGia;
                        if (soGio >= 3) {
                            tongTien *= 0.7;
                            printf("Được giảm 30%% vì hát >= 3 giờ!\n");
                        }
                        printf("Tổng tiền Karaoke: %.0f VND\n", tongTien);
                    }

                    printf("\nBạn có muốn tính lại? (1: Có / 0: Không): ");
                    scanf("%d", &tiepTuc);
                    clearInputBuffer();
                    if (tiepTuc == 1) clearScreen();
                } while (tiepTuc == 1);
                printMenu();
                break;
            }

            case 4: {
                clearScreen();
                int tiepTuc;
                do {
                    int soKW;
                    printf("\n--- Tính tiền điện ---\n");
                    printf("Nhập số kWh tiêu thụ: ");
                    scanf("%d", &soKW);

                    float tien = 0;
                    if (soKW <= 50) tien = soKW * 1678;
                    else if (soKW <= 100) tien = 50*1678 + (soKW-50)*1734;
                    else if (soKW <= 200) tien = 50*1678 + 50*1734 + (soKW-100)*2014;
                    else if (soKW <= 300) tien = 50*1678 + 50*1734 + 100*2014 + (soKW-200)*2536;
                    else tien = 50*1678 + 50*1734 + 100*2014 + 100*2536 + (soKW-300)*2834;

                    printf("Tiền điện phải trả: %.0f VND\n", tien);

                    printf("\nBạn có muốn tính lại? (1: Có / 0: Không): ");
                    scanf("%d", &tiepTuc);
                    clearInputBuffer();
                    if (tiepTuc == 1) clearScreen();
                } while (tiepTuc == 1);
                printMenu();
                break;
            }

            case 5: {
                clearScreen();
                int tiepTuc;
                do {
                    float tienVay, laiSuatNam;
                    int soThang;
                    printf("\n--- Tính tiền vay ngân hàng ---\n");
                    printf("Nhập số tiền vay (triệu đồng): ");
                    scanf("%f", &tienVay);
                    printf("Nhập lãi suất năm (%%): ");
                    scanf("%f", &laiSuatNam);
                    printf("Nhập số tháng vay: ");
                    scanf("%d", &soThang);

                    float laiSuatThang = laiSuatNam / 12 / 100;
                    float tongLai = tienVay * laiSuatThang * soThang;
                    float tongTra = tienVay + tongLai;

                    printf("Tổng tiền lãi: %.2f triệu\n", tongLai);
                    printf("Tổng tiền phải trả: %.2f triệu VND\n", tongTra);

                    printf("\nBạn có muốn tính khoản vay khác? (1: Có / 0: Không): ");
                    scanf("%d", &tiepTuc);
                    clearInputBuffer();
                    if (tiepTuc == 1) clearScreen();
                } while (tiepTuc == 1);
                printMenu();
                break;
            }

            case 6: {
                clearScreen();
                printf("Chức năng đang được phát triển...\n");
                printf("\nNhấn Enter để quay lại menu...");
                clearInputBuffer();
                getchar();
                printMenu();
                break;
            }

            case 0: {
                clearScreen();
                printf("Cảm ơn bạn đã sử dụng chương trình!\n");
                return 0;
            }

            default: {
                clearScreen();
                printf("Lựa chọn không hợp lệ! Vui lòng chọn lại.\n\n");
                printf("Nhấn Enter để tiếp tục...");
                clearInputBuffer();
                getchar();
                printMenu();
                break;
            }
        }
    } while (1);

    return 0;
}