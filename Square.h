struct Square;

Shape *Square__to_shape(Square *square);

Square *Square__from_shape(Shape *shape);

Square *Square__create(int x, int y, int width, int height);

void Square__destroy(Square *square);

int Square__x(Square *self);

int Square__y(Square *self);

int Square__width(Square *self);

int Square__height(Square *self);