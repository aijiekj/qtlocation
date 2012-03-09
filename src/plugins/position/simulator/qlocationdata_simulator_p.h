/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtLocation module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QGEOPOSITIONINFODATA_SIMULATOR_P_H
#define QGEOPOSITIONINFODATA_SIMULATOR_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtCore/QMetaType>
#include <QtCore/QDateTime>
#include <QtCore/QList>

QT_BEGIN_HEADER
QT_BEGIN_NAMESPACE

struct QGeoPositionInfoData
{
    QGeoPositionInfoData();

    // Coordinate information
    double latitude;
    double longitude;
    double altitude;

    // Attributes
    // ### transmit whether attributes are set or not
    qreal direction;
    qreal groundSpeed;
    qreal verticalSpeed;
    qreal magneticVariation;
    qreal horizontalAccuracy;
    qreal verticalAccuracy;

    // DateTime info
    QDateTime dateTime;

    int minimumInterval;
    bool enabled;
};

struct QGeoSatelliteInfoData
{
    struct SatelliteInfo
    {
        SatelliteInfo();

        // This enum duplicates the SatelliteSystem enum defined in qgeosatelliteinfo.h, which cannot be
        // included as this file must compile with Qt4 (it is used by Qt Simulator)
        enum SatelliteSystem
        {
            Undefined = 0x00,
            GPS = 0x01,
            GLONASS = 0x02
        };

        qreal azimuth;
        qreal elevation;
        int signalStrength;
        bool inUse;
        SatelliteSystem satelliteSystem;
        int satelliteIdentifier;
    };

    QList<SatelliteInfo> satellites;
};

void qt_registerLocationTypes();

QT_END_NAMESPACE

Q_DECLARE_METATYPE(QGeoPositionInfoData)
Q_DECLARE_METATYPE(QGeoSatelliteInfoData)
Q_DECLARE_METATYPE(QGeoSatelliteInfoData::SatelliteInfo)

QT_END_HEADER

#endif // QGEOPOSITIONINFODATA_SIMULATOR_P_H