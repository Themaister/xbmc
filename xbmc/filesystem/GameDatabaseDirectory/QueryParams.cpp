/*
 *      Copyright (C) 2005-2012 Team XBMC
 *      http://www.xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "QueryParams.h"

using namespace XFILE::GAMEDATABASEDIRECTORY;

CQueryParams::CQueryParams()
{
  m_idGame = -1;
  m_idGenre = -1;
  m_idCollection = -1;
  m_idPlatform = -1;
  m_idPublisher = -1;
  m_year = -1;
}

void CQueryParams::SetQueryParam(NODE_TYPE NodeType, const CStdString& strNodeName)
{
  long idDb=atol(strNodeName.c_str());

  switch (NodeType)
  {
    /*
  case NODE_TYPE_OVERVIEW:
    m_idContent = idDb;
    break;
    */
  case NODE_TYPE_GENRE:
    m_idGenre = idDb;
    break;
    /*
  case NODE_TYPE_COUNTRY:
    m_idCountry = idDb;
    break;
  case NODE_TYPE_YEAR:
    m_idYear = idDb;
    break;
  case NODE_TYPE_ACTOR:
    m_idActor = idDb;
    break;
  case NODE_TYPE_DIRECTOR:
    m_idDirector = idDb;
    break;
  case NODE_TYPE_TITLE_MOVIES:
  case NODE_TYPE_RECENTLY_ADDED_MOVIES:
    m_idMovie = idDb;
    break;
  case NODE_TYPE_TITLE_TVSHOWS:
    m_idShow = idDb;
    break;
  case NODE_TYPE_SEASONS:
    m_idSeason = idDb;
    break;
  case NODE_TYPE_EPISODES:
  case NODE_TYPE_RECENTLY_ADDED_EPISODES:
    m_idEpisode = idDb;
    break;
  case NODE_TYPE_STUDIO:
    m_idStudio = idDb;
    break;
  case NODE_TYPE_TITLE_MUSICVIDEOS:
  case NODE_TYPE_RECENTLY_ADDED_MUSICVIDEOS:
    m_idMVideo = idDb;
    break;
  case NODE_TYPE_MUSICVIDEOS_ALBUM:
    m_idAlbum = idDb;
    break;
  case NODE_TYPE_SETS:
    m_idSet = idDb;
    break;
  case NODE_TYPE_TAGS:
    m_idTag = idDb;
    break;
    */
  default:
    break;
  }
}
