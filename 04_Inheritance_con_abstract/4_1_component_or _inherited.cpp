#include<iostream>
#include<string>
#include<math.h>

using namespace std;

class point{
public :
    float x,y;

    point(){
        x = 0.00;
        y = 0.00;
    }

    point(float _x, float _y){
        x = _x;
        y = _y;
    }
};

class triangle{
public :
    point p1;
    point p2;
    point p3;

    float get_area(){
        return 0.5 * abs((p1.x * (p2.y - p3.y))+(p2.x * (p3.y - p1.y))+(p3.x * (p1.y - p2.y)));
    }
};

class triangular_prism{
public :
    triangle base;
    float edge_length;

    float get_volume(){
        return base.get_area() * edge_length;
    }

    float get_surface_area(){
        return 0;
    }
};

class point3d : public point{
public :
    float z;

    point3d() : point(){
        z = 0;
    }

    point3d(float _x, float _y, float _z) : point(_x,_y){
        z = _z;
    }
};

class tetrahedron{
public :
    point3d p,q,r,s;

    float get_volume(){
        float p_volume =    ((s.x-p.x)*(((q.y-p.y)*(r.z-p.z))-((q.z-p.z)*(r.y-p.y)))) + 
                            ((s.y-p.y)*(((q.z-p.z)*(r.x-p.x))-((q.x-p.x)*(r.z-p.z)))) + 
                            ((s.z-p.z)*(((q.x-p.x)*(r.y-p.y))-((q.y-p.y)*(r.x-p.x))));
        return p_volume / 6;
    }
};

int main(){
    
    triangle t1;
    t1.p1.x = 0; t1.p1.y = 5;
    t1.p2.x = 0; t1.p2.y = 0;
    t1.p3.x = 5; t1.p3.y = 0;

    //cout << t1.get_area() << " sq.unit" << endl;

    triangular_prism p1;
    p1.base = t1;
    p1.edge_length = 20;

    //cout << p1.get_volume() << " cubic unit" << endl;

    point3d a(0,0,0) ,b(5,0,0) ,c(0,6,0) ,d(0,0,7);
    tetrahedron tthd1;
    tthd1.p = a;
    tthd1.q = b;
    tthd1.r = c;
    tthd1.s = d;

    cout << tthd1.get_volume() << " cubic unit" << endl;


    point a1(0,0);
    point a2(0,5);
    point a3;
    a3.x = 5; a3.y = 0;

    return 0;
}