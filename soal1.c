/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 4 (Dynamic Structures)
 *   Hari dan Tanggal    : Selasa, 5 Mei 2026
 *   Nama (NIM)          : Maria Vanessa Soritan (13224078)
 *   Nama File           : soal1.c
 *   Deskripsi           : Membuat sistem validasi segel mantra dengan aturan sebagai berikut:
 *  1. Karakter yang valid hanya huruf kecil dan () [] {}
 *  2. huruf diabaikan
 *  3. kurung harus berpasangan dan tertutup dengan urutan benar
 *  4. Kalau ada karakter penutup tidak punya pasangan, string tidak valid
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

int main() {
    char str[MAX];
    char stack[MAX];
    int count = -1;
    bool valid = true;
    
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';
    
    for (int i = 0; i < strlen(str); i++) {
        char kurung = str[i];
        if (kurung == '(' || kurung == '[' || kurung == '{') {
            stack[++count] = kurung;
        }
        else if (kurung == ')') {
            if (count == -1 || stack[count--] != '(') 
            valid = false;
        }
        else if (kurung == ']') {
            if (count == -1 || stack[count--] != '[') 
            valid = false;
        }
        else if (kurung == '}') {
            if (count == -1 || stack[count--] != '{') 
            valid = false;
        }
        if (!valid) break;
    }
    
    if (valid && count != -1) {
        valid = false;
    }
    
    if (valid) {
        printf("VALID\n");
    } else {
        printf("INVALID\n");
    }
    
    return 0;
}
