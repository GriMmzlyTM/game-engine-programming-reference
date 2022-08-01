
#include <list>

struct Shape {
    virtual void Draw()=0;
    virtual ~Shape() = default;
};

struct Circle       : public Shape {
    void Draw() override {}
};
struct Rectangle    : public Shape {
    void Draw() override {}
};
struct Triangle     : public Shape {
    void Draw() override {}
};

void DrawShapesBad(std::list<Shape*>& shapes) {
    auto pShape(shapes.begin());
    auto pEnd(shapes.end());

    for (; pShape != pEnd; ++pShape) {
        switch(typeid(*pShape)) {
            case typeid(Circle) :
                (dynamic_cast<Circle*>(*pShape))->Draw();
                break;
            case typeid(Rectangle):
                (dynamic_cast<Rectangle*>(*pShape))->Draw();
                break;
            case typeid(Triangle):
                (dynamic_cast<Triangle*>(*pShape))->Draw();
                break;
        }
    }
}

void DrawShapesGood(std::list<Shape*>& shapes) {
    auto pShape(shapes.begin());
    auto pEnd(shapes.end());

    for(; pShape != pEnd; ++pShape) {
        (*pShape)->Draw();
    }
}