#include "colorspaces.h"

using namespace std;

ColorSpaces::ColorSpaces(QImage *image)
{
    im = image;
}


void ColorSpaces::RGBSpace(float red, float green, float blue)
{
        if(red>0)
        {
            for(int y = 0;y<im->height(); y++)                     //mniejsze od wysokosci obrazu
            {
                green = (y*255)/im->height();                    // dzielic przez height i *255 na nic nie rzutowac w reszcie to samo
                for(int x = 0;x<im->width();x++)
                {
                    blue = (x*255)/im->width();                 //dzielic przez width i * 255 na nic nie rzutowac w reszcie to samo
                    drawPixel(Pixel(x,y, qRgb(red,green,blue)));
                }
            }
        }
        else if(green>0)
        {
            for(int y = 0;y<im->height(); y++)                     //mniejsze od wysokosci obrazu
            {
                red = (y*255)/im->height();                    // dzielic przez height i *255 na nic nie rzutowac w reszcie to samo
                for(int x = 0;x<im->width();x++)
                {
                    blue = (x*255)/im->width();                 //dzielic przez width i * 255 na nic nie rzutowac w reszcie to samo
                    drawPixel(Pixel(x,y, qRgb(red,green,blue)));
                }
            }
        }
        else if(blue>0)
        {

            for(int y = 0;y<im->height(); y++)                     //mniejsze od wysokosci obrazu
            {
                red = (y*255)/im->height();                    // dzielic przez height i *255 na nic nie rzutowac w reszcie to samo
                for(int x = 0;x<im->width();x++)
                {
                    green = (x*255)/im->width();                 //dzielic przez width i * 255 na nic nie rzutowac w reszcie to samo
                    drawPixel(Pixel(x,y, qRgb(red,green,blue)));
                }
            }
        }
}

void ColorSpaces::HSVSpace(int hue,int saturation, int value){
    float R,G,B, S,V,C,X,alfa;
    for(int y = 0;y<im->height();y++)                //mniejsze od wysokosci obrazu
    {
        for(int x = 0;x<im->width();x++)
        {
            if(hue>0) //odcień
            {

             S = (float)x/(im->width()-1);           //Oblicza wartość nasycenia (S) na podstawie pozycji piksela w poziomie (x) i szerokości obrazu.
             V = (float)y/(im->height()-1);          //Oblicza wartość jasności (V) na podstawie pozycji piksela w pionie (y) i wysokości obrazu.
             C = S*V;                               //Oblicza wartość chrominancji (C) na podstawie wartości nasycenia (S) i jasności
                                                    //Chrominacja odnosi się do procesu dodawania koloru do obrazu lub sygnału wideo w celu wzbogacenia jego jakości wizualnej.
             alfa = hue/60.0f;                      //Przelicza wartość odcienia (hue) na przedział od 0 do 6, reprezentujący sześć sektorów w okręgu barw (od 0 do 60 stopni).
             X = C * (1-fabs(fmod(alfa,2.0f)-1));   //Wartość X jest wykorzystywana później do obliczenia składowych koloru (R, G i B) w zależności od sektora barwnego, w którym znajduje się alfa.
                                                    //Wartość pomocnicza X jest istotna, ponieważ umożliwia precyzyjne obliczenie składowych koloru na podstawie odcienia i nasycenia (lub innych właściwości barwnych).
            }
            if(saturation>0)//nasycenie
            {

             S = (float)saturation/255;                 //Przeskalowuje wartość nasycenia (saturation) z zakresu od 0 do 255 na zakres od 0 do 1.
             V = (float)y / (im->height()-1);            //Oblicza wartość jasności (V) na podstawie pozycji piksela w pionie (y) i wysokości obrazu.
             C = S*V;
             alfa = ((float)x / (im->width()-1))*6;      //Przelicza wartość odcienia (alfa) na przedział od 0 do 6, reprezentujący sześć sektorów w okręgu barw.
             X = C * (1-fabs(fmod(alfa,2.0f)-1));
                                                        //fabs - zwraca wartość bezwzględną (wartość bez znaku) liczby zmiennoprzecinkowej.
                                                        //fmod - zwraca resztę z dzielenia dwóch liczb zmiennoprzecinkowych.
            }
            if(value>0) //jasność
            {
             S = (float)y/(im->height()-1);              //Oblicza wartość nasycenia (S) na podstawie pozycji piksela w pionie (y) i wysokości obrazu.
             V = (float)value/255;                      //Przeskalowuje wartość jasności (value) z zakresu od 0 do 255 na zakres od 0 do 1.
             C = S*V;
             alfa = ((float)x / (im->width()-1))*6;
             X = C * (1-fabs(fmod(alfa,2.0f)-1));
            }

            if(alfa >=0 && alfa <=1)
            {
             R = V;
             G = X + V - C;
             B = V - C;
            }
            else if(alfa >=1 && alfa <=2)
            {
             R = X+V-C;
             G = V;
             B = V - C;
            }
            else if(alfa >=2 && alfa <=3)
            {
             R = V-C;
             G = V;
             B = X + V - C;
            }
            else if(alfa >=3 && alfa <=4)
            {
             R = V-C;
             G = X + V - C;
             B = V;
            }
            else if(alfa >=4 && alfa <=5)
            {
             R = X+V-C;
             G = V - C;
             B = V;
            }
            else
            {
             R = V;
             G = V - C;
             B = X + V - C;
            }
            //QColor hsvColor;
            //hsvColor.setHsv(C, S, V);
            //drawPixel(Pixel(x,y, hsvColor.Rgb));
            drawPixel(x,y,qRgb(R*255,G*255,B*255));      //mnożone przez 255 w celu przeskalowania ich z zakresu od 0 do 1
                                                    //(wartości zmiennoprzecinkowe) do zakresu od 0 do 255 (wartości całkowite) chodzi o intensywność koloru.
        }

    }
}
/*
void ColorSpaces::HSVSpace(int hue,int saturation, int value){
    float alfa, X;
    if(hue>0){
        cout<<"hue: "<<hue<<endl;
        for(int y = 0;y<im->height();y++)                //mniejsze od wysokosci obrazu
        {
            for(int x = 0;x<im->width();x++)
            {
                saturation = (float)x/(im->width()-1);           //Oblicza wartość nasycenia (S) na podstawie pozycji piksela w poziomie (x) i szerokości obrazu.
                value = (float)y/(im->height()-1);          //Oblicza wartość jasności (V) na podstawie pozycji piksela w pionie (y) i wysokości obrazu.
                hue = saturation*value;                               //Oblicza wartość chrominancji (C) na podstawie wartości nasycenia (S) i jasności
                                               //Chrominacja odnosi się do procesu dodawania koloru do obrazu lub sygnału wideo w celu wzbogacenia jego jakości wizualnej.
                alfa = hue/60.0f;                      //Przelicza wartość odcienia (hue) na przedział od 0 do 6, reprezentujący sześć sektorów w okręgu barw (od 0 do 60 stopni).
                X = hue * (1-fabs(fmod(alfa,2.0f)-1));   //Wartość X jest wykorzystywana później do obliczenia składowych koloru (R, G i B) w zależności od sektora barwnego, w którym znajduje się alfa.
                QColor hsvColor;
                hsvColor.setHsv(hue, saturation, value);
                drawPixel(Pixel(x,y, hsvColor.Rgb));

            }                                   //Wartość pomocnicza X jest istotna, ponieważ umożliwia precyzyjne obliczenie składowych koloru na podstawie odcienia i nasycenia (lub innych właściwości barwnych).

        }
    }
    else if(saturation>0)
    {
        for(int y = 0;y<im->height();y++)                //mniejsze od wysokosci obrazu
        {
            for(int x = 0;x<im->width();x++)
            {
                saturation = (float)saturation/255;                 //Przeskalowuje wartość nasycenia (saturation) z zakresu od 0 do 255 na zakres od 0 do 1.
                value = (float)y / (im->height()-1);            //Oblicza wartość jasności (V) na podstawie pozycji piksela w pionie (y) i wysokości obrazu.
                hue = saturation*value;
                alfa = ((float)x / (im->width()-1))*6;      //Przelicza wartość odcienia (alfa) na przedział od 0 do 6, reprezentujący sześć sektorów w okręgu barw.
                X = hue * (1-fabs(fmod(alfa,2.0f)-1));
                                                   //fabs - zwraca wartość bezwzględną (wartość bez znaku) liczby zmiennoprzecinkowej.
                QColor hsvColor;
                hsvColor.setHsv(hue, saturation, value);
                drawPixel(Pixel(x,y, hsvColor.Rgb));

            }                                   //fmod - zwraca resztę z dzielenia dwóch liczb zmiennoprzecinkowych.
        }
    }
    else if(value>0)
    {
        for(int y = 0;y<im->height();y++)                //mniejsze od wysokosci obrazu
        {
            for(int x = 0;x<im->width();x++)
            {
                saturation = (float)y/(im->height()-1);              //Oblicza wartość nasycenia (S) na podstawie pozycji piksela w pionie (y) i wysokości obrazu.
                value = (float)value/255;                      //Przeskalowuje wartość jasności (value) z zakresu od 0 do 255 na zakres od 0 do 1.
                hue = saturation*value;
                alfa = ((float)x / (im->width()-1))*6;
                X = hue * (1-fabs(fmod(alfa,2.0f)-1));

                QColor hsvColor;
                hsvColor.setHsv(hue, saturation, value);
                drawPixel(Pixel(x,y, hsvColor.Rgb));
            }
        }
    }
}
*/
