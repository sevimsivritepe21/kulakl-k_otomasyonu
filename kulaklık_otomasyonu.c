#include <stdio.h>
#include <stdlib.h>

typedef struct kulaklikBilgi
{
    char hModel[40] ;
    int hModelYili ;
    char hRenk[15] ;
    int hId ;
    int hFiyat ;
}Bilgi ;


typedef struct kulaklikAna
{
    char hCins[30] ;
    int hAdet;
    int aID ;

    Bilgi *bilgi_adres ;
    Bilgi *Bbilgi_adres ;
}Ana ;


Bilgi *bilgi_adres ;
Ana *ana_adres ;
Ana *Aana_adres ;

int i,j,temp=0 ;
int sayi ,toplamSayi=0 ;


Ana *kEkleme()
{

    if (toplamSayi==0)
    {
        printf("Kac kulaklik tipi gireceksiniz: ");
        scanf("%d",&sayi) ;
        ana_adres= (Ana*) malloc(sayi * sizeof(Ana)) ;

        for(i=0;i<sayi;i++)
        {
            printf("%d. turu yazin:",i+1) ;
            scanf("%s", (ana_adres+i) -> hCins ) ;

            printf("ID:") ;
            scanf("%d", &(ana_adres+i) -> aID ) ;
            //turun ID'si eklenme sirasina gore deger alir
            //silme fonksiyonunu anca bu sekilde yazabildim


            printf("Ture ait gireceginiz kulaklik sayisi:");
            scanf("%d", &(ana_adres+i) -> hAdet) ;

            ((ana_adres+i)->bilgi_adres) = (Bilgi*) malloc((ana_adres+i) -> hAdet * sizeof(Bilgi)) ;
            for(j=0 ;j < (ana_adres+i) -> hAdet ;j++)
            {
                printf("Ayni ID girmemeye ozen gosterin.\n");

                printf("Kulakligin ID'sini girin:");
                scanf("%d", &((ana_adres+i) -> bilgi_adres+j) -> hId);

                printf("Kulakligin modelini girin:");
                scanf("%s", ((ana_adres+i)->bilgi_adres+j)->hModel);

                printf("Kulakligin model yilini girin:");
                scanf("%d", &((ana_adres+i)->bilgi_adres+j)->hModelYili);

                printf("Kulakligin rengini girin:");
                scanf("%s", ((ana_adres+i)->bilgi_adres+j)->hRenk);

                printf("Kulakligin fiyatini girin:");
                scanf("%d", &((ana_adres+i) -> bilgi_adres+j) -> hFiyat);

            }
            printf("\n");
        }
        toplamSayi += sayi ;
    }
    else
    {
        printf("Kac kulaklik tipi gireceksiniz: ");
        scanf("%d",&sayi) ;
        toplamSayi += sayi ;
        ana_adres= (Ana*) realloc(ana_adres, sayi * toplamSayi *sizeof(Ana)) ;

        for(i=toplamSayi-sayi;i<toplamSayi;i++)
        {
            printf("%d. turu yazin:",i+1) ;
            scanf("%s", (ana_adres+i) -> hCins ) ;

            printf("ID:") ;
            scanf("%d", &(ana_adres+i+1) -> aID ) ;

            printf("Ture ait gireceginiz kulaklik sayisi:");
            scanf("%d", &(ana_adres+i) -> hAdet) ;

            ((ana_adres+i)->bilgi_adres) = (Bilgi*) malloc((ana_adres+i) -> hAdet * sizeof(Bilgi));

            for(j=0 ;j < (ana_adres+i) -> hAdet ;j++)
            {
                printf("-Ayni ID girmemeye ozen gosterin.\n");

                printf("Kulakligin ID'sini girin:");
                scanf("%d", &((ana_adres+i)->bilgi_adres+j)->hId);

                printf("Kulakligin modelini girin:");
                scanf("%s", ((ana_adres+i)->bilgi_adres+j)->hModel);

                printf("Kulakligin model yilini girin:");
                scanf("%d", &((ana_adres+i)->bilgi_adres+j)->hModelYili);

                printf("Kulakligin rengini girin:");
                scanf("%s", ((ana_adres+i)->bilgi_adres+j)->hRenk);

                printf("Kulakligin fiyatini girin:");
                scanf("%d", &((ana_adres+i)->bilgi_adres+j)->hFiyat);

            }
            printf("\n");
        }

    }

    return ana_adres ;
}

void kListeleme(Ana *ana_adres)
{
    for(i=0;i<toplamSayi;i++)
    {
        printf("-------------------------------------------------------\n");
        printf("Kulaklik turu: %s\n",(ana_adres+i) -> hCins);
        printf("ID:%d\n",(ana_adres+i) -> aID);
        printf("Bu kulaklik turunun sayisi: %d\n",(ana_adres+i) -> hAdet);
        for(j=0;j<(ana_adres+i) -> hAdet;j++)
        {
            printf("Kulakligin ID bilgisi:%d\n",((ana_adres+i)->bilgi_adres+j) -> hId);
            printf("Kulakligin model bilgisi:%s\n",((ana_adres+i)->bilgi_adres+j) ->hModel);
            printf("Kulakligin model yili bilgisi:%d\n",((ana_adres+i)->bilgi_adres+j) ->hModelYili);
            printf("Kulakligin renk bilgisi:%s\n",((ana_adres+i)->bilgi_adres+j) ->hRenk);
            printf("Kulakligin fiyat bilgisi:%d TL\n",((ana_adres+i)->bilgi_adres+j) ->hFiyat);
        }
        printf("-------------------------------------------------------\n");
    }
}

void kBulma()
{
    int idAramasi ;
    printf("Goruntulemek istediginiz kulakligin ID bilgisini giriniz:");
    scanf("%d",&idAramasi) ;

    for(i=0;i<toplamSayi;i++)
    {
        for(j=0; j<(ana_adres+i)-> hAdet; j++)
        {
            if(((ana_adres+i)->bilgi_adres+j) -> hId == idAramasi)
            {
                printf("Kulaklik turu: %s\n",(ana_adres+i) -> hCins);
                printf("Bu kulaklik turunun sayisi: %d\n",(ana_adres+i) -> hAdet);
                printf("Tur ID'si:%d\n",(ana_adres+i) -> aID);

                printf("Kulakligin ID bilgisi:%d\n",((ana_adres+i)->bilgi_adres+j) -> hId);
                printf("Kulakligin model bilgisi:%s\n",((ana_adres+i)->bilgi_adres+j) ->hModel);
                printf("Kulakligin model yili bilgisi:%d\n",((ana_adres+i)->bilgi_adres+j) ->hModelYili);
                printf("Kulakligin renk bilgisi:%s\n",((ana_adres+i)->bilgi_adres+j) ->hRenk);
                printf("Kulakligin fiyat bilgisi:%d TL\n",((ana_adres+i)->bilgi_adres+j) ->hFiyat);
                break ;
            }
            else
            {
                printf("Aradiginiz ID sistemde bulunmamakta.ID girme ekranina yonlendiriliyorsunuz...\n");
                return ;
            }
        }
    }
}

void kOnerme()
{
    int secimT,secimE,secim5 ;
    secimekrani :
    printf("Hangi tur kulaklik onerilmesini istersiniz?\n1-Kulak ici kablolu\n2-Kulak ici bluetooth\n3-Kulak ustu kablolu\n4-kulak ustu bluetooth\n->");
    scanf("%d",&secimT) ;
        switch(secimT)
        {
           case 1:
           {
                printf("Marka:JBL\nModel:C100SIUBLK\nModel Yili:2019\nRenk:Siyah\nFiyat:217 TL\n");
                printf("Aldiginiz oneriyi eklemek istiyorsaniz 1'i tuslayin. -> ");
                scanf("%d",&secimE);
                if(secimE==1)
                    kEkleme();
                else
                    break ;

           }
           case 2:
           {
                printf("Marka:Soundpeats\nModel:Air3\nModel Yili:2020\nRenk:Beyaz\nFiyat:649 TL\n");
                printf("Aldiginiz oneriyi eklemek istiyorsaniz 1'i tuslayin. -> ");
                scanf("%d",&secimE);
                if(secimE==1)
                    kEkleme() ;
                else
                    break ;

           }
           case 3:
           {
                printf("Marka:SENNHEISER\nModel:HD 400S\nModel Yili:2020\nRenk:Siyah\nFiyat:1.299 TL\n");
                printf("Aldiginiz oneriyi eklemek istiyorsaniz 1'i tuslayin. -> ");
                scanf("%d",&secimE);
                if(secimE==1)
                    kEkleme() ;
                else
                    break ;
           }
           case 4:
           {
                printf("Marka:Marshall\nModel:Major IV\nModel Yili:2021\nRenk:Siyah\nFiyat:1.408 TL\n");
                printf("Aldiginiz oneriyi eklemek istiyorsaniz 1'i tuslayin. -> ");
                scanf("%d",&secimE);
                if(secimE==1)
                    kEkleme() ;
                else
                    break ;
           }
           default:
           {
               printf("Gecersiz secim.Secim ekranina yonlendiriliyorsunuz...");
               goto secimekrani ;
           }

        }
}


void kGuncelleme(Ana *ana_adres,int sayi)
{
    int hAdet ,x,y;
    printf("Guncellemek istediginiz kulaklik turunun ID'sini girin:");
    scanf("%d",&x) ;

    for(i=0;i<sayi;i++)
    {
        if(x==(ana_adres+i) -> aID)
        {
            printf("Guncellemek istediginiz kulakligin ID bilgisi:");
            scanf("%d",&y);
            for(j=0;j<hAdet;j++)
            {
                if(y==(((ana_adres+i)->bilgi_adres+j)->hId))
                {
                printf("%d ID'li kulakligi guncelliyorsunuz.\n",y);

                printf("Kulakligin guncel modelini girin:");
                scanf("%s", ((ana_adres+i)->bilgi_adres+j)->hModel);

                printf("Kulakligin guncel model yilini girin:");
                scanf("%d", &((ana_adres+i)->bilgi_adres+j)->hModelYili);

                printf("Kulakligin guncel rengini girin:");
                scanf("%s", ((ana_adres+i)->bilgi_adres+j)->hRenk);

                printf("Kulakligin guncel fiyatini girin:");
                scanf("%d", &((ana_adres+i) -> bilgi_adres+j) -> hFiyat);
                }
            }
        }
    }
}



Ana *kSilme(Ana *ana_adres,int sayi)
{
    int a, hAdet ;
    Ana *bilgi_adres ;

    printf("Silinecek turun ID'si:");
    scanf("%d",&a);

    for(i=0;i<sayi;i++)
    {
        if(a ==((ana_adres+i)->aID))
        {
            hAdet=0;
            (ana_adres+i) -> hAdet = hAdet ;
            (ana_adres+i) -> Bbilgi_adres = (Bilgi*) malloc (sizeof(Bilgi)*hAdet) ;

            (ana_adres+i) ->bilgi_adres = (ana_adres+i) -> Bbilgi_adres ;
            for(j=a;j<sayi;j++)
            {
                *(ana_adres+(j-1)) = *(ana_adres+j) ;
            }
            sayi-- ;
            Aana_adres = (Ana*) malloc (sizeof(Ana)*sayi) ;
            for(j=0;j<sayi;j++)
            {
                *(Aana_adres+j)=*(ana_adres+j) ;
            }
            ana_adres=Aana_adres ;

        }
    }
    return sayi ;
}



int menu(int secim)
{
    printf("*^*^*^Kulaklik Sihirbazina Hosgeldiniz*^*^*^\n");
    printf("1- Kulaklik Ekleme\n");
    printf("2- Kulaklik Listeleme\n");
    printf("3- Kulaklik Silme\n");
    printf("4- Kulaklik Guncelleme\n");
    printf("5- Kulaklik Bulma\n");
    printf("6- Kulaklik Onerme\n");
    printf("7- Sihirbazdan Cikis\n");
    printf("Seciminiz => ");
    scanf("%d",&secim) ;
    return secim ;
}



int main()
{

    while(temp<=0)
    {
        int secim = menu(secim) ;
        int secimS ;
        switch(secim)
        {
             case 1:
                {
                //printf("ekleme\n");
                kEkleme() ;
                printf("Tekrar secim yapmak isterseniz 1'i tuslayin.\n->");
                scanf("%d",&secimS);
                if(secimS==1)
                {
                    temp=0;
                    break ;
                }
                else
                {
                    temp=1;
                    printf("Sihirbaz kapatildi.Tekrar bekleriz.");
                    break ;
                }
                }


                case 2:
                {
                //printf("listeleme\n");
                kListeleme(ana_adres) ;
                printf("Tekrar secim yapmak isterseniz 1'i tuslayin.\n->");
                scanf("%d",&secimS);
                if(secimS==1)
                {
                    temp=0;
                    break ;
                }
                else
                {
                    temp=1;
                    printf("Sihirbaz kapatildi.Tekrar bekleriz.");
                    break ;
                }
                }


                case 3:
                {
                //printf("silme\n");
                kSilme(ana_adres,sayi) ;
                printf("Tekrar secim yapmak isterseniz 1'i tuslayin.\n->");
                scanf("%d",&secimS);
                if(secimS==1)
                {
                    temp=0;
                    break ;
                }
                else
                {
                    temp=1;
                    printf("Sihirbaz kapatildi.Tekrar bekleriz.");
                    break ;
                }
                }


                case 4:
                {
                //printf("guncelleme\n");
                kGuncelleme(ana_adres,sayi) ;
                printf("Tekrar secim yapmak isterseniz 1'i tuslayin.\n->");
                scanf("%d",&secimS);
                if(secimS==1)
                {
                    temp=0;
                    break ;
                }
                else
                {
                    temp=1;
                    printf("Sihirbaz kapatildi.Tekrar bekleriz.");
                    break ;
                }
                }



                case 5:
                {
                //printf("bulma\n");
                kBulma() ;
                printf("Tekrar secim yapmak isterseniz 1'i tuslayin.\n->");
                scanf("%d",&secimS);
                if(secimS==1)
                {
                    temp=0;
                    break ;
                }
                else
                {
                    temp=1;
                    printf("Sihirbaz kapatildi.Tekrar bekleriz.");
                    break ;
                }
                }


                case 6:
                {
                //printf("onerme\n");
                kOnerme() ;
                printf("Tekrar secim yapmak isterseniz 1'i tuslayin.\n->");
                scanf("%d",&secimS);
                if(secimS==1)
                {
                    temp=0;
                    break ;
                }
                else
                {
                    temp=1;
                    printf("Sihirbaz kapatildi.Tekrar bekleriz.");
                    break ;
                }
                }

                case 7:
                    {
                        printf("Sihirbaz kapatildi.Tekrar bekleriz.");
                        temp = 1 ;
                        break ;
                    }

                default :
                {
                    printf("Gecersiz tercih.");
                    break ;
                }

    return 0;
        }
    }
}
