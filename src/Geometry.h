#ifndef Geometry_h
#define Geometry_h


struct __Color
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
    
    __Color ()
    :r(0), g(0), b(0), a(0)
    {}
    
    __Color (unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a)
    :r(_r), g(_g), b(_b), a(_a)
    {}
    
    inline bool operator == (const __Color &color) const
    {
        return color.r == r && color.b == b && color.g == g && color.a == a; //IsNear(r, color.r) && IsNear(g, color.g) && IsNear(b, color.b) && IsNear(a, color.a);
    }
    
} typedef Color;



struct __GSize2D {
    float width;
    float height;
    
    __GSize2D() :width(0), height(0) {}
    __GSize2D(float _w, float _h) :width(_w), height(_h) {}
    
    float getW() const {return width;}
    float getH() const {return height;}
    
    void setW(float value) {width = value;}
    void setH(float value) {height = value;}
};

typedef struct __GSize2D GSize2D;

#endif
