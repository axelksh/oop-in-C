struct Shape;

struct ShapeType;

ShapeType *ShapeType__create(
	int buffer_size,
	const char* (*name) (Shape *self),
	int (*sides) (Shape *self),
	void (*destroy) (Shape *shape));

Shape *Shape__create(ShapeType *type);

ShapeType Shape_type(Shape *self);

const char* (*name) (Shape *self);

int (*sides) (Shape *self);

void (*destroy) (Shape *shape);

void* Shape__buffer(Shape* self);