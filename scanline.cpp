#include "scanline.h"

ScanLine::ScanLine(QImage *image)
{
    Sketch::im=image;
    CurveCreator::im = image;
}

void ScanLine::drawCurves(){
//    cout<<"ScanLine drawCurves"<<endl;
}

ScanLine* ScanLine::drawScanLine(QRgb colorRGB)
{

    //return this;
    hidePoints(actionPoints);

    QVector<int> x; // Wektor przechowujący współrzędne x
    int p1, p2; // Indeksy punktów

    if (actionPoints.size() < 3)
        return NULL; // Jeśli mniej niż 2 punkty na linii, zakończ funkcję

    int yMax = actionPoints[0]->pos.y(); // Największa wartość y
    int yMin = actionPoints[0]->pos.y(); // Najmniejsza wartość y

    // Znajdź największą i najmniejszą wartość y na linii
    for (int i = 0; i < (int)actionPoints.size(); i++)
    {
        if (actionPoints[i]->pos.y() > yMax)
            yMax = actionPoints[i]->pos.y();
        if (actionPoints[i]->pos.y() < yMin)
            yMin = actionPoints[i]->pos.y();
    }

    for (int y = yMin; y <= yMax; y++)
    {
        for (int i = 0; i <(int)actionPoints.size(); i++)
        {
            p1 = i;
            p2 = (i + 1) % actionPoints.size(); // Zapewnienie działania dla ostatniego punktu

            // Upewnij się, że p1 ma mniejszą wartość y niż p2
            if (actionPoints[p1]->pos.y() > actionPoints[p2]->pos.y())
                std::swap(p1, p2);

            // Jeśli y mieści się pomiędzy wartościami  p1 i p2 oraz wartości  p1 i p2 są różne
            if (y >= actionPoints[p1]->pos.y() && y < actionPoints[p2]->pos.y() && actionPoints[p1]->pos.y() != actionPoints[p2]->pos.y())
            {
                // Oblicz współrzędną x "twierdzenie z prezentacji"
                int xValue = actionPoints[p1]->pos.x() + (y - actionPoints[p1]->pos.y()) * (actionPoints[p2]->pos.x() - actionPoints[p1]->pos.x()) / (actionPoints[p2]->pos.y() - actionPoints[p1]->pos.y());
                x.push_back(xValue);
            }
        }

        std::sort(x.begin(), x.end()); // Posortuj współrzędne x

        // Narysuj odcinki poziome między parami współrzędnych x
        for (int i = 0; i < x.size() - 1; i += 2)
        {
            drawLine(x[i], y, x[i + 1], y, colorRGB);
            //drawLine(x[i], y, x[i + 1], y, colorRGB);
        }

        x.clear(); // Wyczyść wektor x
    }


    return this;
}

