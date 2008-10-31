/*
    This file is part of KDE.

    Copyright (c) 2008 Stephen Kelly <steveire@gmail.com>

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



#include "abstractmarkupbuilder.h"
#include <kdebug.h>


/**
    @brief Creates MediaWiki markup from a QTextDocument
*/
class MediaWikiMarkupBuilder : public AbstractMarkupBuilder
{
public:

    /**
Creates a new MediaWikiMarkupBuilder
    */
    MediaWikiMarkupBuilder();
    virtual ~MediaWikiMarkupBuilder();

    virtual void beginStrong();
    virtual void endStrong();
    virtual void beginEmph();
    virtual void endEmph();
    virtual void beginUnderline();
    virtual void endUnderline();
    virtual void beginStrikeout();
    virtual void endStrikeout();

    virtual void endParagraph();
    virtual void addNewline();

    virtual void beginAnchor(const QString &href, const QString &name);
    virtual void endAnchor();

    virtual void beginHeader1();
    virtual void beginHeader2();
    virtual void beginHeader3();
    virtual void beginHeader4();
    virtual void beginHeader5();
    virtual void beginHeader6();

    virtual void endHeader1();
    virtual void endHeader2();
    virtual void endHeader3();
    virtual void endHeader4();
    virtual void endHeader5();
    virtual void endHeader6();

    virtual void beginList(QTextListFormat::Style type);



    virtual void endList();


    virtual void beginListItem();
    virtual void endListItem();


    virtual void appendLiteralText(const QString &text);

    const QString escape(const QString &s);

    virtual QString& getResult();

private:
    QList<QTextListFormat::Style> currentListItemStyles;

    QString m_text;
};

