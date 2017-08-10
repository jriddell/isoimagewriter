/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright 2017  KDE neon <email>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License or (at your option) version 3 or any later version
 * accepted by the membership of KDE e.V. (or its successor approved
 * by the membership of KDE e.V.), which shall act as a proxy
 * defined in Section 14 of version 3 of the license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef VERIFYISOWORKER_H
#define VERIFYISOWORKER_H

#include <QObject>
#include <QThread>

enum Distro { Neon, Kubuntu, Arch };

/**
 * @todo write docs
 */
class VerifyISOWorker : public QThread
{
    Q_OBJECT

public:
    /**
     * Default constructor
     */
    VerifyISOWorker(QString filename, Distro distro);
    bool getResult();
    QString getErrorMessage();
    void doVerificationNeon();
    void doVerificationKubuntu();
    bool isResultReady();
    void run();

private:
    bool m_result;
    QString m_error;
    QString m_filename;
    bool m_resultReady;
    Distro m_distro;
};

#endif // VERIFYISOWORKER_H
