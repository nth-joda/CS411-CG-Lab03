#include "Tugiac.h"
#include "Painter.h"
TuGiac::TuGiac()
{
}

void TuGiac::fillColor(int x, int y, int colr_id)
{
	if (colr_id == mauDo_id) {
		BoundaryFill(x, y, mauDo, mauVien);
	}
	else if (colr_id == mauVang_id) {
		BoundaryFill(x, y, mauVang, mauVien);
	}
	else if (colr_id == mauXanh_id) {
		BoundaryFill(x, y, mauXanh, mauVien);
	}
}

HinhChuNhat::HinhChuNhat(Point c, Point btmRight)
{
	this->center = c;
	this->end = btmRight;
	this->start.setCoor(2 * c.getX() - end.getX(), 2 * c.getY() - end.getY());
}

void HinhChuNhat::draw()
{
	setLibColor();
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(this->start.getX(), this->start.getY());
	glVertex2f(this->end.getX(), this->start.getY());

	glVertex2f(this->end.getX(), this->start.getY());
	glVertex2f(this->end.getX(), this->end.getY());

	glVertex2f(this->end.getX(), this->end.getY());
	glVertex2f(this->start.getX(), this->end.getY());
	
	glVertex2f(this->start.getX(), this->end.getY());
	glVertex2f(this->start.getX(), this->start.getY());

	glEnd();
	if (this->fill > 0)
		fillColor(this->center.getX(), this->center.getY(), fill);
}


string HinhChuNhat::getType()
{
	return "Hinh Chu Nhat";
}

Point HinhChuNhat::getCenter()
{
	return this->center;
}


HinhVuong::HinhVuong(Point c, Point btmRight)
{
	this->center = c;
	this->end = btmRight;
	this->start.setCoor((end.getX() - center.getX()) * cos(180 * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(180 * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(180 * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(180 * 3.1415 / 180) + center.getY());

}

void HinhVuong::draw()
{
	setLibColor();
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(this->end.getX(), this->end.getY());
	int alpha = 90;
	glVertex2f((end.getX() - center.getX())* cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	

	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	alpha = 180;
	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());

	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	alpha = 270;
	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());

	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());
	alpha = 360;
	glVertex2f((end.getX() - center.getX()) * cos(alpha * 3.1415 / 180) - ((end.getY() - center.getY()) * sin(alpha * 3.1415 / 180)) + center.getX(), ((end.getX() - center.getX()) * sin(alpha * 3.1415 / 180)) + (end.getY() - center.getY()) * cos(alpha * 3.1415 / 180) + center.getY());

	glEnd();
	if (this->fill > 0)
		fillColor(this->center.getX(), this->center.getY(), fill);
}

string HinhVuong::getType()
{
	return "Hinh Vuong";
}

Point HinhVuong::getCenter()
{
	return this->center;
}

