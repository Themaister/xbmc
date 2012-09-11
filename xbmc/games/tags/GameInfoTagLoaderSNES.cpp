/*
 *      Copyright (C) 2012 Team XBMC
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
 *  along with XBMC; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#include "GameInfoTagLoaderSNES.h"
#include "SnesTag.h"
#include "utils/log.h"

using namespace GAME_INFO;

bool CGameInfoTagLoaderSNES::Load(const CStdString& strFileName, CGameInfoTag& tag)
{
  CLog::Log(LOGDEBUG, "CGameInfoTagLoaderSNES: loading SNES tag information for file: %s", strFileName.c_str());

  try
  {
    // Retrieve the Flac Tag info from strFileName and put it in tag
    CSnesTag myTag;
    if (myTag.Read(strFileName))
      myTag.GetGameInfoTag(tag);
    return tag.Loaded();
  }
  catch (...)
  {
    CLog::Log(LOGERROR, "CGameInfoTagLoaderSNES: exception in file %s", strFileName.c_str());
  }

  tag.SetLoaded(false);
  return false;
}
