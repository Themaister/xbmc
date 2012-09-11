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

#include "GameClientFactory.h"
#include "addons/AddonManager.h"
#include "utils/URIUtils.h"

using namespace ADDON;

GameClientPtr CGameClientFactory::CreateGameClient(const CFileItem& file)
{
  AddonPtr addon;

  CStdString strExtension;
  URIUtils::GetExtension(file.GetPath(), strExtension);
  strExtension.ToLower();
  strExtension.TrimLeft('.');
  
  if (strExtension.IsEmpty())
    throw CGameClientUnknown();
  
  // Also zip
  if (strExtension == "smc" || strExtension == "sfc" || strExtension == "fig" ||
      strExtension == "gd3" || strExtension == "gd7" || strExtension == "dx2" ||
      strExtension == "bsx" || strExtension == "swc")
  {
    if (!CAddonMgr::Get().GetAddon("gameclient.snes9x.next", addon, ADDON_GAMEDLL))
      throw CGameClientUnknown();
    return boost::dynamic_pointer_cast<CGameClient>(addon);
  }
  
  // Also: bin, elf, mb (MultiBoot)
  if (strExtension == "agb" || strExtension == "gba" || strExtension == "gb" ||
      strExtension == "gbc" || strExtension == "cgb" || strExtension == "sgb")
  {
    if (!CAddonMgr::Get().GetAddon("gameclient.gambatte", addon, ADDON_GAMEDLL))
      throw CGameClientUnknown();
    return boost::dynamic_pointer_cast<CGameClient>(addon);
  }

  throw CGameClientUnknown();
}
