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
 *       Copyright (C) 2023 Wabi Foundation. All Rights Reserved.
 * --------------------------------------------------------------
 *  . x x x . o o o . x x x . : : : .    o  x  o    . : : : .
 * -------------------------------------------------------------- */

import UsdGeom

public typealias UsdGeomXform = Pixar.UsdGeomXform

public extension Pixar.UsdGeom
{
  typealias Xform = UsdGeomXform
}

public extension Pixar.UsdGeom.Xform
{
  @discardableResult
  static func define(_ stage: inout StageRefPtr, path: Pixar.Sdf.Path) -> Pixar.UsdGeom.Xform
  {
    Pixar.UsdGeom.Xform.Define(stage.pointee.getPtr(), path)
  }

  @discardableResult
  static func define(_ stage: inout StageRefPtr, path: String) -> Pixar.UsdGeom.Xform
  {
    Pixar.UsdGeom.Xform.define(&stage, path: .init(path))
  }

  func addTranslateOp(precision: UsdGeomXformOp.Precision = .double,
                      suffix: Pixar.TfToken = Pixar.TfToken(),
                      invert: Bool = false) -> UsdGeomXformOp
  {
    AddTranslateOp(precision, suffix, invert)
  }

  func addScaleOp(precision: UsdGeomXformOp.Precision = .float,
                  suffix: Pixar.TfToken = Pixar.TfToken(),
                  invert: Bool = false) -> UsdGeomXformOp
  {
    AddScaleOp(precision, suffix, invert)
  }

  func addRotateXOp(precision: UsdGeomXformOp.Precision = .float,
                    suffix: Pixar.TfToken = Pixar.TfToken(),
                    invert: Bool = false) -> UsdGeomXformOp
  {
    AddRotateXOp(precision, suffix, invert)
  }

  func addRotateYOp(precision: UsdGeomXformOp.Precision = .float,
                    suffix: Pixar.TfToken = Pixar.TfToken(),
                    invert: Bool = false) -> UsdGeomXformOp
  {
    AddRotateYOp(precision, suffix, invert)
  }

  func addRotateZOp(precision: UsdGeomXformOp.Precision = .float,
                    suffix: Pixar.TfToken = Pixar.TfToken(),
                    invert: Bool = false) -> UsdGeomXformOp
  {
    AddRotateZOp(precision, suffix, invert)
  }
}
