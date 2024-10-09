#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Döndürme Fonksiyonu
void dondurme(int parca[3][3]) {
    int temp[3][3];

    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp[i][j] = parca[j][i];
        }
    }


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            parca[i][j] = temp[i][2 - j];
        }
    }
}
//Yerleştirme Fonksiyonu
void yerlestir(int tahta[30][30],int x,int N,int oran){
    int i;
    switch (oran) {
        case 1:
            while (x+2>N) {
                printf("Lutfen x'i tekrar giriniz. Sectiginiz kisma sekil yerlestirilemez.");
                scanf("%d",&x);
            }
            i=0;
            while (tahta[i][x-1]!=1 && tahta[i][x]!=1 && tahta[i][x+1]!=1 && i<N) {
                i++;
            }
            if(i<N){
                tahta[i-1][x-1]=1;
                tahta[i-1][x]=1;
                tahta[i-1][x+1]=1;
            }
            else{
                tahta[N-1][x-1]=1;
                tahta[N-1][x]=1;
                tahta[N-1][x+1]=1;
            }
            break;
            
        case 2:
            while (x+1>N) {
                printf("Lutfen x'i tekrar giriniz. Sectiginiz kisma sekil yerlestirilemez.");
                scanf("%d",&x);
            }
            i=0;
            while (tahta[i][x-1]!=1 && tahta[i][x]!=1 && i<N) {
                i++;
            }
            if(i<N){
                tahta[i-1][x-1]=1;
                tahta[i-1][x]=1;
                tahta[i-2][x-1]=1;
                tahta[i-2][x]=1;
            }
            else{
                tahta[N-1][x-1]=1;
                tahta[N-1][x]=1;
                tahta[N-2][x-1]=1;
                tahta[N-2][x]=1;
            }
            break;
        
        case 3:
            while (x>N) {
                printf("Lutfen x'i tekrar giriniz. Sectiginiz kisma sekil yerlestirilemez.");
                scanf("%d",&x);
            }
            i=0;
            while (tahta[i][x-1]!=1 && i<N) {
                i++;
            }
            if(i<N){
                tahta[i-1][x-1]=1;
                tahta[i-2][x-1]=1;
            }
            else{
                tahta[N-1][x-1]=1;
                tahta[N-2][x-1]=1;
            }
            
            break;
        
        case 4:
            while (x>N){
                printf("Lutfen x'i tekrar giriniz. Sectiginiz kisma sekil yerlestirilemez.");
                scanf("%d",&x);
            }
            i=0;
            while (tahta[i][x-1]!=1 && i<N) {
                i++;
            }
            if(i<N){
                tahta[i-1][x-1]=1;
            }
            else{
                tahta[N-1][x-1]=1;
            }
    
            break;
        
        case 5:
            while (x+1>N){
                printf("Lutfen x'i tekrar giriniz. Sectiginiz kisma sekil yerlestirilemez.");
                scanf("%d",&x);
            }
            i=0;
            while (tahta[i][x-1]!=1 && tahta[i][x]!=1 && i<N) {
                i++;
            }
            if(i<N){
                tahta[i-1][x-1]=1;
                tahta[i-1][x]=1;
                tahta[i-2][x-1]=1;
                tahta[i-3][x-1]=1;
            }
            else{
                tahta[N-1][x-1]=1;
                tahta[N-1][x]=1;
                tahta[N-2][x-1]=1;
                tahta[N-3][x-1]=1;
            }
            
            break;
            
        case 6:
            while (x>N){
                printf("Lutfen x'i tekrar giriniz. Sectiginiz kisma sekil yerlestirilemez.");
                scanf("%d",&x);
            }
            i=0;
            while (tahta[i][x-1]!=1 && i<N) {
                i++;
            }
            if(i<N){
                tahta[i-1][x-1]=1;
                tahta[i-2][x-1]=1;
                tahta[i-3][x-1]=1;
            }
            else{
                tahta[N-1][x-1]=1;
                tahta[N-2][x-1]=1;
                tahta[N-3][x-1]=1;
            }
            break;
        case 7:
            while (x+1>N) {
                printf("Lutfen x'i tekrar giriniz. Sectiginiz kisma sekil yerlestirilemez.");
                scanf("%d",&x);
            }
            i=0;
            while (tahta[i][x-1]!=1 && tahta[i][x]!=1 && i<N) {
                i++;
            }
            if(i<N){
                tahta[i-1][x-1]=1;
                tahta[i-1][x-2]=1;
                tahta[i-2][x-2]=1;
                tahta[i-2][x-3]=1;
            }
            else{
                tahta[N-1][x-1]=1;
                tahta[N-1][x-2]=1;
                tahta[N-2][x-2]=1;
                tahta[N-2][x-3]=1;
            }

            break;
    }
}

// Hat Kırma Fonksiyonu
void hatKir(int tahta[30][30], int N,int* score) {
    for (int i = 0; i < N; i++) {
        int j = 0;
        while (tahta[i][j] == 1 && j < N) {
            j++;
        }
        if (j >= N) {
            // Hat kırma işlemi
            for (int k = i; k > 0; k--) {
                for (int l = 0; l < N; l++) {
                    tahta[k][l] = tahta[k - 1][l];
                }
            }
            (*score)++;
        }
    }
}

int main(){
    int tahta[30][30];
    int parca[3][3];
    srand(time(NULL));
    int oran;
    int i,j,N,x,flag=0,score=0,highestScore=0;
    char dondur = 'H',devam = 'H',secim='0';


    printf("Merhaba Tetris Oynuna Hos Geldiniz!\n");
    do {
           printf("**** MENU ****\n");
           printf("1. Oyuna Giris\n");
           printf("2. En Yuksek Skoru Goruntule\n");
           printf("3. Oyundan Cikis\n");
           printf("Seciminizi yapiniz (1-3): ");
           scanf(" %c", &secim);
        
    switch (secim) {
        case '1':
            score = 0;
            flag = 0;
            //Rastgele Oyun Tahtası Oluşturma.
            printf("Lutfen oyun tahta boyutu giriniz:\n");
            scanf("%d",&N);
            for (i = 3; i < N; i++)
            {
               for (j = 0; j < N; j++)
                {
                tahta[i][j]=rand()%2;
                }
            }
            for (i=0; i<4; i++) {
                for (j=0; j<N; j++) {
                tahta[i][j]=0;
                }
            }
            
    
        do {
        printf("Oyun Tahtasi\n");
            //Tahta Yazdırma
            for (i = 0; i < N; i++)
            {
                printf("|");
                for (j=0; j<N; j++) {
                    if(tahta[i][j]==1){
                        printf("%2d",tahta[i][j]);
                    }
                    else{
                        printf("  ");
                    }
                } printf("|");
               printf("\n");
            }
            
        // Parçayı Initialize Etme
        for ( i = 0; i < 3; i++)
        {
          for ( j = 0; j < 3; j++)
          {
             parca[i][j]=-1;
          }
          
        }
        oran = rand()%6+1;
        //Rastgele Parça oluşturma.
        switch (oran)
        {
        case 1:
          for (i = 0; i <3; i++)
          {
           parca[0][i]=1;
          }
          
            break;
        
        case 2:
            for (i = 0; i < 2; i++)
            {
              for (j = 0; j< 2; j++)
              {
                 parca[i][j]=1;
              }
              
            }
            break;

        case 3:
            for ( i = 0; i < 2; i++)
            {
                parca[i][0]=1;
            }
            
            break;

        case 4:
            parca[0][0]=1;
            break;
        case 5:
            for ( i = 0; i < 3; i++)
            {
                parca[i][0]=1;
            }
            parca[2][1]=1;
            break;

        case 6:
             for ( i = 0; i < 3; i++)
            {
                parca[i][0]=1;
            }
            break;
            case 7:
                for (i=0; i<2; i++) {
                    for (j=0; j<3; j++) {
                        parca[i][j]=1;
                    }
                }
                parca[0][0]=-1;
                parca[1][2]=-1;
                break;
        }
       
       //Sahip olduğumuz parça:
       printf("sekil:\n");
       for (i = 0; i < 3; i++)
       {
           j=0;
         while (parca[i][j]!=-1 && j<3)
         {
            printf("X");
            j++;
         }
         printf("\n");
       }
        
        
        //Kullanıcı Döndürmek İstiyorsa Döndürme İşlemi:
        printf("Sekli dondurmek icin 'E'. Dondurmek istemiyorsaniz herhangi bir tusa basiniz!\n");
        scanf(" %c",&dondur);
        if (dondur == 'E')
        {
            dondurme(parca);

            // Döndürülmüş parça:
            printf("Dondurulmus Parca:\n");
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    if (parca[i][j] != -1)
                    {
                        printf("X");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }
        
        // Kullanıcıdan yerleştirilecek koordinat alma
        do {
            printf("Sekli hangi X(1-%d) koordinatina yerlestirmek istediginizi giriniz\n",N);
            scanf("%d",&x);
        } while (x<1 || x > N);
        
       

        yerlestir(tahta,x,N,oran);
        
        //Yerleştirme İşleminden Sonra Tahta Yazdırma
        printf("Yerlestirme Isleminden Sonra Oyun Tahtasi:\n");
        for (i = 0; i < N; i++)
        {
            printf("|");
            for (j=0; j<N; j++) {
                if(tahta[i][j]==1){
                    printf("%2d",tahta[i][j]);
                }
                else{
                    printf("  ");
                }
            } printf("|");
           printf("\n");
        }
        
        //Kırma İşlemi Gerekli mi? Kontrol:
        for (i=0; i<N; i++) {
            j=x;
            while (tahta[i][j]==1 && j<N ) {
                j++;
            }
            if(j>=N){
                flag=1;
            }
        }
        // Gerekliyse Kırma İşlemi Gerçekleştir:
        if(flag==1){
            hatKir(tahta, N,&score);
        }
        
        // Oyun tahtasının en üst satırında 1 var mı kontrolü
            for (j = 0; j < N; j++) {
              if (tahta[0][j] == 1) {
                 printf("Oyun tahtasinin en ust satirinda parca bulunuyor. Oyun sona erdi!\n");
                 return 0;
                    }
                }
            
        printf("Oyuna devam etmek istiyor musunuz? (E/H): ");
        scanf(" %c", &devam);
        if (devam != 'E' && devam != 'e') {
            printf("Oyun bitti. Iyi oyundu!\n");
            return 0;
        }
        // Display score at the end of each turn
        printf("Skorunuz: %d\n", score);
        printf("En Yuksek Skor: %d\n", highestScore);
     
            } while (devam == 'E' || devam == 'e');
        if (score > highestScore) {
            highestScore = score;
            }
        break;
        case '2':
            // Display the highest score
            printf("En Yuksek Skor: %d\n", highestScore);
            break;
            
        case '3':
            printf("Oyundan cikiliyor. Iyi oyunlar!\n");
            break;

        default:
            printf("Gecersiz secim. Lutfen tekrar deneyiniz.\n");
            break;
        }

    } while (secim != '3');
        

    return 0;
}
