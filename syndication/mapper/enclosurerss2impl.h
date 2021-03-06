/*
 * This file is part of the syndication library
 *
 * Copyright (C) 2006 Frank Osterfeld <osterfeld@kde.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#ifndef SYNDICATION_MAPPER_ENCLOSURERSS2IMPL_H
#define SYNDICATION_MAPPER_ENCLOSURERSS2IMPL_H

#include <enclosure.h>
#include <rss2/enclosure.h>
#include <rss2/item.h>

namespace Syndication {
    
class EnclosureRSS2Impl;
typedef boost::shared_ptr<EnclosureRSS2Impl> EnclosureRSS2ImplPtr;

/**
 *
 * @internal
 * @author Frank Osterfeld
 */
class EnclosureRSS2Impl : public Syndication::Enclosure
{
    public:

        explicit EnclosureRSS2Impl(const Syndication::RSS2::Item& item,
                          const Syndication::RSS2::Enclosure& enc);
        
        bool isNull() const;
        
        QString url() const;
        
        QString title() const;
        
        QString type() const;
        
        uint length() const;

        uint duration() const;
        
    private:
        Syndication::RSS2::Item m_item;
        Syndication::RSS2::Enclosure m_enclosure;
};
    
} // namespace Syndication

#endif // SYNDICATION_MAPPER_ENCLOSURERSS2IMPL_H
