/*
    Copyright (c) 2009 Tobias Koenig <tokoe@kde.org>

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

#ifndef AKONADI_ENTITYRIGHTSFILTERMODEL_H
#define AKONADI_ENTITYRIGHTSFILTERMODEL_H

#include "akonadi_export.h"
#include "entitytreemodel.h"

#include "krecursivefilterproxymodel.h"

namespace Akonadi {

class EntityRightsFilterModelPrivate;

/**
 * @short A proxy model that filters entities by access rights.
 *
 * This class can be used on top of an EntityTreeModel to exclude entities by access type 
 * or to include only certain entities with special access rights.
 *
 * @code
 *
 * using namespace Akonadi;
 *
 * EntityTreeModel *model = new EntityTreeModel( this );
 *
 * EntityRightsFilterModel *filter = new EntityRightsFilterModel();
 * filter->setAccessRights( Collection::CanCreateItem | Collection::CanCreateCollection );
 * filter->setSourceModel( model );
 *
 * EntityTreeView *view = new EntityTreeView( this );
 * view->setModel( filter );
 *
 * @endcode
 *
 * @li For collections the access rights are checked against the collections own rights.
 * @li For items the access rights are checked against the item's parent collection rights.
 *
 * @author Tobias Koenig <tokoe@kde.org>
 * @since 4.4
 */
class EntityRightsFilterModel : public KRecursiveFilterProxyModel
{
  Q_OBJECT

  public:
    /**
     * Creates a new entity rights filter model.
     *
     * @param parent The parent object.
     */
    explicit EntityRightsFilterModel( QObject *parent = 0 );

    /**
     * Destroys the entity rights filter model.
     */
    virtual ~EntityRightsFilterModel();

    /**
     * Sets the access @p rights the entities shall be filtered
     * against. If no rights are set explicitly, Collection::AllRights
     * is assumed.
     */
    void setAccessRights( Collection::Rights rights );

    /**
     * Returns the access rights that are used for filtering.
     */
     Collection::Rights accessRights() const;

    /**
     * @reimplemented
     */
    virtual Qt::ItemFlags flags( const QModelIndex &index ) const;

  protected:
    virtual bool acceptRow( int sourceRow, const QModelIndex &sourceParent ) const;

  private:
    //@cond PRIVATE
    Q_DECLARE_PRIVATE( EntityRightsFilterModel )
    EntityRightsFilterModelPrivate * const d_ptr;
    //@endcond
};

}

#endif