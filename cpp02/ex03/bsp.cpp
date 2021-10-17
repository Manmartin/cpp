#include "Point.hpp"


/*
** Explanation
** v1 = AB = (v1.x, v1.y, 0) = (B.x - A.x, B.y - A.y, 0)
** v2 = AP = (v2.x, v2.y, 0) = (P.x - A.x, P.y - A.y, 0)
** v1 X v2 = (0, 0, v1.x*v2.y - v1.y*v2.x)
*/
float static  get_direction(Point P, Point A, Point B) {
    return (B.getX().toFloat() - A.getX().toFloat()) * (P.getY().toFloat() - A.getY().toFloat()) -
    (B.getY().toFloat() - A.getY().toFloat()) * (P.getX().toFloat() - A.getX().toFloat());
}

bool    bsp( Point const a, Point const b, Point const c, Point const point) {
    float   direction1, direction2, direction3;

    direction1 = get_direction(point, a, b);
    direction2 = get_direction(point, b, c);
    direction3 = get_direction(point, c, a);
    return  ((direction1 > 0 && direction2 > 0 && direction3 > 0) || (direction1 < 0 && direction2 < 0 && direction3 < 0) ? true : false );
}
