#include "delivery.h"

Box::Box(float l, float b, float h, float w)
{
    this->length = l;
    this->breadth = b;
    this->height = h;
    this->weight = w;
}

Box::Box(float l, float w) : Box(l, l, l, w){};

Box::Box(Box &box)
{
    this->length = box.length;
    this->breadth = box.breadth;
    this->height = box.height;
    this->weight = box.weight;
}

void Box::setLength(float len)
{
    this->length = len;
}

void Box::setBreadth(float len)
{
    this->breadth = len;
}

void Box::setHeight(float len)
{
    this->height = len;
}

void Box::setHeight(float w)
{
    this->weight = w;
}

float Box::calcVolume()
{
    return this->breadth * this->height * this->height;
}

float Box::calcDensity()
{
    return this->weight / (this->breadth * this->height * this->height);
}

bool Box::operator==(Box &box)
{
    if (this->length == box.length && this->breadth == box.breadth && this->height == box.height && this->weight == box.weight)
        return true;
    return false;
}

Package::Package(float l, float b, float h, float w)
{
    Box newBox = Box(l, b, h, w);
    this->box = newBox;
}

Package::Package(float l, float w)
{
    Box newBox = Box(l, w);
    this->box = newBox;
}

Package::Package(Box &box)
{
    this->box = box;
}

bool Package::operator==(Package &package)
{
    if (this->box == package.box)
        return true;
    return false;
}

void Package::updateNext(Package &pkg)
{
    this->nextPackage=&pkg;
}

void Package::updatePrevious(Package &pkg)
{
    this->previousPackage = &pkg;
}

Truckload::Truckload(Box &box)
{
    head = new Package(box);
}

Truckload *Truckload::insertBegin(Box &box)
{   
    Package newPkg = Package(box);
    Package* temp = this->head;
    newPkg.updateNext(*temp);
    this->head = &newPkg;
    return this;
}

Truckload *Truckload::insertEnd(Box &box)
{
    return nullptr;
}

Truckload *Truckload::sortedInsertbyLength(Box &box)
{
    return nullptr;
}

Truckload *Truckload::sortedInsertbyBreadth(Box &box)
{
    return nullptr;
}

Truckload *Truckload::sortedInsertbyHeight(Box &box)
{
    return nullptr;
}

Truckload *Truckload::sortedInsertbyVolume(Box &box)
{
    return nullptr;
}

Truckload *Truckload::sortByLength()
{
    return nullptr;
}

Truckload *Truckload::printPackages()
{
    Package *currPkg = this->head;
    
    return nullptr;
}
