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

#include "GameInfoTagLoaderGameboy.h"
#include "GameboyTag.h"
#include "GBATag.h"
#include "utils/log.h"
#include "utils/URIUtils.h"

using namespace GAME_INFO;

bool CGameInfoTagLoaderGameboy::Load(const CStdString& strFileName, CGameInfoTag& tag)
{
  CLog::Log(LOGDEBUG, "CGameInfoTagLoaderGameboy: loading GameBoy tag information for file: %s", strFileName.c_str());

  try
  {
    CStdString strExtension;
    URIUtils::GetExtension(strFileName, strExtension);
    strExtension.ToLower();
    strExtension.TrimLeft('.');

    // Determine the cartridge type by file extension. File extension data is
    // from the VBA-M project.
    if (strExtension == "agb" || strExtension == "gba" || strExtension == "bin" ||
        strExtension == "elf" || strExtension == "mb" /* (MultiBoot) */ )
    {
      CGBATag myTag;
      if (myTag.Read(strFileName))
        myTag.GetGameInfoTag(tag);
    }
    else if (strExtension == "gb"  || strExtension == "gbc" || strExtension == "cgb" ||
             strExtension == "sgb" || strExtension == "dmg")
    {
      CGameboyTag myTag;
      if (myTag.Read(strFileName))
        myTag.GetGameInfoTag(tag);
    }
    return tag.Loaded();
  }
  catch (...)
  {
    CLog::Log(LOGERROR, "CGameInfoTagLoaderGameboy: exception in file %s", strFileName.c_str());
  }

  tag.SetLoaded(false);
  return false;
}
