/*
    Copyright (c) 2009 Bertjan Broeksema <b.broeksema@kdemail.net>

    This library is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This library is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to the
    Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
    02110-1301, USA.
*/

#ifndef MBOX_H
#define MBOX_H

#include <QtCore/QString>

#include "mbox_export.h"

class MBOX_EXPORT MBox
{
  public:
    MBox(const QString &mboxFile = QString());
    
    ~MBox();
    
    /**
     * Checks if the file exists and if it can be opened for read/write.
     * TODO: Add some heuristics to see if it is actually a mbox file.
     */
    bool isValid(QString &errorMsg) const;
 
  private:
    class Private;
    Private *d;
};

#endif // MBOX_H