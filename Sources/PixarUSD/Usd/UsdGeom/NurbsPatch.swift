/* --------------------------------------------------------------
 * :: :  M  E  T  A  V  E  R  S  E  :                          ::
 * --------------------------------------------------------------
 * This program is free software; you can redistribute it, and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. Check out
 * the GNU General Public License for more details.
 *
 * You should have received a copy for this software license, the
 * GNU General Public License along with this program; or, if not
 * write to the Free Software Foundation, Inc., to the address of
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 *       Copyright (C) 2024 Wabi Foundation. All Rights Reserved.
 * --------------------------------------------------------------
 *  . x x x . o o o . x x x . : : : .    o  x  o    . : : : .
 * -------------------------------------------------------------- */

import UsdGeom

public typealias UsdGeomNurbsPatch = Pixar.UsdGeomNurbsPatch

public extension Pixar.UsdGeom
{
  typealias NurbsPatch = UsdGeomNurbsPatch
}

public extension Pixar.UsdGeom.NurbsPatch
{
  @discardableResult
  static func define(_ stage: Pixar.Usd.StageRefPtr, path: Pixar.Sdf.Path) -> Pixar.UsdGeom.NurbsPatch
  {
    Pixar.UsdGeom.NurbsPatch.Define(stage.pointee.getPtr(), path)
  }

  @discardableResult
  static func define(_ stage: Pixar.Usd.StageRefPtr, path: String) -> Pixar.UsdGeom.NurbsPatch
  {
    Pixar.UsdGeom.NurbsPatch.define(stage, path: .init(path))
  }
}
