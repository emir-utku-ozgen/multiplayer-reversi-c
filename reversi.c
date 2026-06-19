#include <stdio.h>
#define max_size 100

//bütün program için tahta dizisi ve size değişkeni tanımlanır
char board[max_size][max_size];
int size;


//oyun tahtası oluşturulur ve ortaya K taşı konularak oyun başlar.
void tahta_olustur(int size){
    int i,j;
    for (i=0; i<size; i++) {
        for (j=0; j<size; j++) {
            board[i][j]='.';
        }
    }
    board[size/2][size/2]='K';
    
}
//oyun tahtası yazdırılır
void tahta_yazdir(int size){
    printf(" ");
    int i,j;
    for (i=0; i<size; i++) {
        printf("%2d",i);
    }
    printf("\n");
    for (i=0; i<size; i++) {
        printf("%d ",i);
        for (j=0; j<size; j++) {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
    
}
int gecerli_hamle(int x,int y,char renk){
    int i,new_x,new_y;
    int yon_x[]={-1,-1,-1,0,0,1,1,1};// yön kontrolü için dizi tanımlanır.
    int yon_y[]={-1,0,1,-1,1,-1,0,1};
    
    
    //kullanıcıdan alınan koordinatların kurallara uygun olup olmadığı kontrol edilir.
    if (x<0 || x>=size || y<0 || y>=size || board[x][y]!='.') {
        return 0;
    }
    //alınan koordinatın yanında taş oluğ olmadığı kontrol edilir.
    for (i=0; i<8; i++) {
        new_x=x+yon_x[i];
        new_y=y+yon_y[i];
        if (new_x>=0 && new_x<size && new_y>=0 && new_y<size && board[new_x][new_y]!='.') {
            return 1;
        }
    }
    return 0;
    
    
    
}




void hamle_yap(int x, int y, char renk){
    int yon_x[] = {-1, -1, -1, 0, 0, 1, 1, 1};// yön kontrolü için dizi tanımlanır.
    int yon_y[] = {-1, 0, 1, -1, 1, -1, 0, 1};// yön kontrolü için dizi tanımlanır.

    board[x][y] = renk;  // tahtada oyuncunun taşını yerleştirilir.

    for (int i = 0; i < 8; i++) {
        int new_x = x + yon_x[i];
        int new_y = y + yon_y[i];

        
        
        //taş koyulduktan sonra aynı renkteki taşların arasında farklı renkte taş var mı kontrol edilir.
    while (new_x >= 0 && new_x < size && new_y >= 0 && new_y < size && board[new_x][new_y] != '.' && board[new_x][new_y] != renk) {
            new_x += yon_x[i];
            new_y += yon_y[i];
        }

        // aradaki taşların renk dönüşümü yapılır.
        if (new_x >= 0 && new_x < size && new_y >= 0 && new_y < size && board[new_x][new_y] == renk) {
            int d_x = x + yon_x[i];
            int d_y = y + yon_y[i];
            while (d_x != new_x || d_y != new_y) {
                board[d_x][d_y] = renk;
                d_x += yon_x[i];
                d_y += yon_y[i];
            }
        }
    }
}

int oyun_Bitti_mi(int size){
    int i,j;
    for (i=0; i<size; i++) {
        for (j=0; j<size; j++) {
            
            //tahtada boş yer kalıp kalmadığını kontrol edilir.
            if (board[i][j]=='.') {
                return 0;
            }
        }
    }
    return 1;
}
void skor_hesapla(int size) {
    int i, j, kırmızı = 0, sarı = 0, mavi = 0;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            //tahtada gezilerek K taşı varsa kırmızı değeri arttılır.
            if (board[i][j] == 'K') {
                kırmızı++;
            }
            //tahtada gezilerek S taşı varsa sarı değeri arttılır.
            else if (board[i][j] == 'S') {
                sarı++;
            }
            //tahtada gezilerek M taşı varsa mavi değeri arttılır.
            else if (board[i][j] == 'M') {
                mavi++;
            }
        }
    }
    printf("Kırmızı: %d, Sarı: %d, Mavi: %d\n", kırmızı, sarı, mavi);
    // Taş sayıları karşılaştırılarak en yüksek puanlı kullanıcıyı bulur.
    if (kırmızı>sarı && kırmızı >mavi) {
        printf("Oyunu kazanan 1.oyuncu");
    }else if (sarı>kırmızı && sarı>mavi){
        printf("Oyunu kazanan 2. oyuncu");
    }
    else if (mavi>kırmızı && mavi>sarı){
        printf("Oyunu kazanan 3.oyuncu");
    }
    else{
        printf("Oyun berabere bitti");
    }
}
int main(void){
    // kullanıcıdan tahta boyutu alınır
    printf("Lütfen tahta boyutunu minimum 3 maksimim 23 olacak şekilde giriniz:\n");
    scanf("%d",&size);
    while (size < 3 || size > 23) {
           printf("Lütfen tahta boyutunu minimum 3 maksimum 23 olacak şekilde giriniz:\n");
           scanf("%d", &size);
       }
   
    //tahta oluşturulup yazdırılır
    tahta_olustur(size);
    tahta_yazdir(size);
    printf("İlk hamle otomatik olarak yapılmıştır\n");
    
    //kullanıcılar ve kullanıcıdan alınacak koordinat değişkenleri tanımlanır
    char renk[]={'S','M','K'};
    int oyuncu=0,x,y;
    
    
    //oyun bitmediği sürece kullanıcıdan x ve y koordinatları alınır eğer alınan koordinatlar geçerliyse hamle yapılır ve taş dönüşümü olucaksa taş dönüşümü gerçekleştirilir ve sıra sıradaki oyuncuya geçer.
    
    
    
    while (!oyun_Bitti_mi(size)) {
        printf("Sıra %c oyuncusunda hamlenizi satır ve sütün şeklinde yazınız",renk[oyuncu]);
        scanf("%d %d",&x,&y);
        if (gecerli_hamle(x, y, renk[oyuncu])) {
            hamle_yap(x, y, renk[oyuncu]);
            tahta_yazdir(size);
            oyuncu=(oyuncu+1)%3;
        }else{
            printf("geçersiz hamle lütfen geçerli bir hamle yapınız:\n");
        }
       
        
        
}
    //oyun bittiğinde en son andaki tahta yazdırılır ve kullanıcıların puanları hesaplanır ve kazanan belirlenir.
    
            tahta_yazdir(size);
            printf("oyun bitti\n");
            skor_hesapla(size);
    
    
    
    
    
    
    
    return 0;
}
