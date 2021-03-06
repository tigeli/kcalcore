/*
    Copyright (c) 2007 Volker Krause <vkrause@kde.org>

    KNode code:
    Copyright (c) 1999-2005 the KNode authors. // krazy:exclude=copyright

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

#include "legacydecrypt.h"

#include <KStringHandler>

using namespace MailTransport;

QString Legacy::decryptKMail( const QString &data )
{
  return KStringHandler::obscure( data );
}

QString Legacy::decryptKNode( const QString &data )
{
  uint i, val, len = data.length();
  QString result;

  for ( i = 0; i < len; ++i ) {
    val = data[i].toLatin1();
    val -= ' ';
    val = ( 255 - ' ' ) - val;
    result += QLatin1Char( (char)( val + ' ' ) );
  }

  return result;
}
