/**
 ** This file is part of the uConfig project.
 ** Copyright 2018 Robotips sebastien.caux@robotips.fr.
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program. If not, see <http://www.gnu.org/licenses/>.
 **/

#ifndef PINITEM_H
#define PINITEM_H

#include "kicad_global.h"

#include <QGraphicsItem>

#include "model/pin.h"

#include "kicadfont.h"

class KICAD_EXPORT PinItem : public QGraphicsItem
{
public:
    PinItem(Pin *pin);
    ~PinItem();

    enum { Type = UserType + 1 };
    int type() const {return Type;}

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    QPainterPath shape() const;

    QPointF base();

    Pin *pin() const;
    void setPin(Pin *pin);

    bool showElectricalType() const;
    void setShowElectricalType(bool showElectricalType);

    void updateData();

private:
    Pin *_pin;

    KicadFont *_fontPad;
    QRectF _rectPad;
    QRectF _brectPad;

    KicadFont *_fontName;
    QRectF _rectName;
    QRectF _brectName;

    KicadFont *_fontType;
    QRectF _rectType;
    QRectF _brectType;

    bool _showElectricalType;
};

#endif // PINITEM_H
