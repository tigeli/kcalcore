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


#ifndef SYNDICATION_MAPPERRSS2IMPL_H
#define SYNDICATION_MAPPERRSS2IMPL_H

#include "feedrss2impl.h"

#include <rss2/document.h>
#include <specificdocument.h>
#include <feed.h>
#include <mapper.h>



namespace Syndication {

/** @internal */
class RSS2Mapper : public Mapper<Feed>
{
    boost::shared_ptr<Feed> map(SpecificDocumentPtr doc) const
    {
        return boost::shared_ptr<Feed>(new FeedRSS2Impl(boost::static_pointer_cast<RSS2::Document>(doc)));
    }
};

} // namespace Syndication

#endif // SYNDICATION_MAPPERRSS2IMPL_H
