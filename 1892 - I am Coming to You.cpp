#include <bits/stdc++.h>

using namespace std;

typedef struct{
    int x, y;
}punto;

int direccion(punto i, punto j, punto k){
    return ( ((j.x - i.x)*(k.y - i.y)) - ((k.x - i.x)*(j.y - i.y)) );
}

double longitud(punto p1, punto p2){
    return sqrt((pow((abs(p2.x - p1.x)),2) + pow((abs(p2.y - p1.y)),2)));
}

bool interseccion(punto i, punto j, punto k){
    if(((min(j.x, k.x) <= i.x) && (max(j.x, k.x) >= i.x)) && ((min(j.y, k.y) <= i.y) && (max(j.y, k.y) >= i.y)))
        return true;
    return false;
}

bool lineIntersection(punto p1, punto p2, punto p3, punto p4){
    int d1, d2, d3, d4;
    d1 = direccion(p3, p4, p1);
    d2 = direccion(p3, p4, p2);
    d3 = direccion(p1, p2, p3);
    d4 = direccion(p1, p2, p4);
    if( ((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)) )
        return true;
    if(d1 == 0 && interseccion(p3, p4, p1))
        return true;
    if(d2 == 0 && interseccion(p3, p4, p2))
        return true;
    if(d3 == 0 && interseccion(p1, p2, p3))
        return true;
    if(d4 == 0 && interseccion(p1, p2, p4))
        return true;
    return false;
}

int main(){
    punto p1, p2, p3, p4;
    int caso = 1;

    while(scanf("%d %d %d %d",&p1.x,&p1.y,&p2.x,&p2.y)){
        if(p1.x == 0 && p1.y == 0 && p2.x == 0 && p2.y == 0){break;}
        scanf("%d %d %d %d",&p3.x,&p3.y,&p4.x,&p4.y);
        if(lineIntersection(p1, p2, p3, p4)){
            printf("Case %d: %.3lf\n",caso++,min(longitud(p1, p3) + longitud(p3, p2), longitud(p1, p4) + longitud(p4, p2))/2.0);
        }else{
            printf("Case %d: %.3lf\n",caso++,longitud(p1, p2)/2.0);
        }
    }
    return 0;
}
