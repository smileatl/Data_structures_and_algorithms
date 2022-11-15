#include <stdio.h>

typedef struct Complex {
	float realpart;
	float imagepart;
} Complex;

Complex assign(float real, float image) {
	Complex c;
	c.realpart = real;
	c.imagepart = image;
	return c;
}

float getReal(Complex c) {
	return c.realpart;
}

float getImage(Complex c) {
	return c.imagepart;
}

Complex add(Complex c1, Complex c2) {
	Complex sum;
	sum.realpart = c1.realpart + c2.realpart;
	sum.imagepart = c1.imagepart + c2.imagepart;
	return sum;
}

Complex difference(Complex c1, Complex c2) {
	Complex sum;
	sum.realpart = c1.realpart + c2.realpart;
	sum.imagepart = c1.imagepart + c2.imagepart;
	return sum;
}

int main() {
	Complex c1, c2, c3, c4;
	c1 = assign(1.0, 2.0);
	c2 = assign(3.0, 5.0);
	c3 = add(c1, c2);
	printf("c1与c2的和为：%.2f+%.2f\n", c3.realpart, c3.imagepart);
}