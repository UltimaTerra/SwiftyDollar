/* ----------------------------------------------------------------
 * :: :  M  E  T  A  V  E  R  S  E  :                            ::
 * ----------------------------------------------------------------
 * Licensed under the terms set forth in the LICENSE.txt file, this
 * file is available at https://openusd.org/license.
 *
 *                                        Copyright (C) 2016 Pixar.
 *         Copyright (C) 2024 Wabi Foundation. All Rights Reserved.
 * ----------------------------------------------------------------
 *  . x x x . o o o . x x x . : : : .    o  x  o    . : : : .
 * ---------------------------------------------------------------- */

import UsdShade

public typealias UsdShadeMaterial = Pixar.UsdShadeMaterial

public extension UsdShade
{
  typealias Material = UsdShadeMaterial
}

public extension UsdShade.Material
{
  @discardableResult
  static func define(_ stage: Usd.StageRefPtr, path: Sdf.Path) -> UsdShade.Material
  {
    UsdShade.Material.Define(stage.pointee.getPtr(), path)
  }

  @discardableResult
  static func define(_ stage: Usd.StageRefPtr, path: String) -> UsdShade.Material
  {
    UsdShade.Material.define(stage, path: .init(path))
  }

  @discardableResult
  func createSurfaceOutput(renderContext: Tf.Token) -> UsdShade.Output
  {
    CreateSurfaceOutput(renderContext)
  }

  @discardableResult
  func createSurfaceOutput(renderContext: UsdShade.Tokens = .universalRenderContext) -> UsdShade.Output
  {
    createSurfaceOutput(renderContext: renderContext.getToken())
  }
}
