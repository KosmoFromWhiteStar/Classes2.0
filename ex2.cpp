#include <iostream>
#include <cmath>

class Figure
{
    // coordinate of centre
    int x, y;
    std::string color;
public:
    Figure(){
        x = 0;
        y = 0;
        color = "uncolor";
    };
public:
    void inicilizate(int in_X, int in_Y, std::string* in_color)
    {
        if(in_X < 0 || in_Y < 0)
        {
            std::cout << "invalid num" << std::endl;
        }
        x = in_X;
        y = in_Y;
        color = *in_color;
    }
    void info()
    {
        std::cout << "X: " << this->x << " Y: " << this->y << std::endl;
        std::cout << "Color: " << this->color << std::endl;
    }
};

class Tryangel : public Figure
{
private:

    double length = 0.0f;
public:
    Tryangel(double in_length, std::string answer) : length(in_length)
    {
        if(in_length < 0)
        {
            std::cout << "Err" << std::endl;
            length = 0.0f;
        }
        this->inicilizate(0, 0, &answer);
    }

    double square(){
        return (this->length * this->length * std::sqrt(3) / 4);
    }
    void const rec_()
    {
        double heigth = (std::sqrt(3)/2*length) + 0.1f;
        std::cout << "Rec x: " << length+0.1f << " y: " << heigth << std::endl;
        std::cout << "Sq: " << heigth*(length+0.1f) << std::endl;
    }

};

class Square : public Figure
{
    double width;
public:
    Square(double in_width, int in_X, int in_Y, std::string in_color) : width(in_width)
    {
        if(in_width < 0)
        {
            std::cout << "err" << std::endl;
            width = 0.0f;
        }
        this->inicilizate(in_X, in_Y, &in_color);
    }

    double sq_sq()
    {
        return width*width;
    }
    void const rec_()
    {
        std::cout << "Rec y and x: " << width+0.1f << std::endl;
        std::cout << "sq: " << (width+0.1f) * (width+0.1f) << std::endl;
    }
};

class Round : public Figure
{
    double radius;
public:
    Round(double in_rad,int in_X, int in_Y, std::string in_color) : radius(in_rad)
    {
        this->inicilizate(in_X, in_Y, &in_color);
    }
    double sq_round()
    {
        return std::atan(1)*4*radius;
    }
    void const rec_()
    {
        double  width = (2*radius);
        std::cout << "Line length: " << width << std::endl;
        std::cout << "square: ";
        std::cout << width * width;
    }

};

class Rectangle: public Figure
{
    double width, length;
public:
    Rectangle(double in_L, double in_W, int in_X, int in_Y, std::string in_Color)
    :width(in_W), length(in_L)
    {
        this->inicilizate(in_X, in_Y, &in_Color);
    }
    double sq_rect()
    {
        return width*length;
    }

    void rec_() const
    {
        std::cout << "Rec x: " << width+0.1f << " y: " << length+0.1f << std::endl;
        std::cout << "Sq: " << (width+0.1f)*(length+0.1f) << std::endl;
    }
};

int main()
{
    std::cout << "Figure: ";
    std::string comm;
    std::cin >> comm;
    if(comm == "Square"){
            Square* sq = new Square(2.3, 0,0,"Green");
            sq->info();
            std::cout << "Sqare sq: " << sq->sq_sq() << std::endl;
            sq->rec_();
            delete sq;
        }
    if(comm == "Tryangle")
    {
        Tryangel* tr = new Tryangel(2.3, "Blue");
        tr->info();
        std::cout << "Triangle sq: " << tr->square() << std::endl;
        tr->rec_();
        delete tr;
    }
    if(comm == "Round")
    {
        Round* rd = new Round(2.0f, 0, 0,"Green");
        rd->info();
        std::cout << "Round sq: " << rd->sq_round() << std::endl;
        rd->rec_();
        delete rd;
    }
    if(comm == "Rectangle")
    {
        Rectangle* rc = new Rectangle(5.0f, 2.5f, 0, 0, "ping");
        rc->info();
        std::cout << "sq: " << rc->sq_rect() << std::endl;
        rc->rec_();
        delete rc;
    }
}
