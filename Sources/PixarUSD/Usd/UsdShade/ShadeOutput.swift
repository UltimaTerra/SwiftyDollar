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

public typealias UsdShadeOutput = Pixar.UsdShadeOutput

public extension UsdShade
{
  typealias Output = UsdShadeOutput
}

public extension UsdShade.Output
{
  @discardableResult
  func connectTo(source: UsdShade.ConnectableAPI,
                 at name: Tf.Token,
                 from sourceType: UsdShade.AttributeType = UsdShade.AttributeType.Output,
                 type: Sdf.ValueTypeName = Sdf.ValueTypeName()) -> Bool
  {
    ConnectToSource(source, name, sourceType, type)
  }

  @discardableResult
  func connectTo(source: UsdShade.ConnectableAPI,
                 at name: UsdShade.Tokens,
                 from sourceType: UsdShade.AttributeType = UsdShade.AttributeType.Output,
                 type: Sdf.ValueTypeName = Sdf.ValueTypeName()) -> Bool
  {
    ConnectToSource(source, name.getToken(), sourceType, type)
  }

  @discardableResult
  func connectTo(source: UsdShade.ConnectableAPI,
                 at name: String,
                 from sourceType: UsdShade.AttributeType = UsdShade.AttributeType.Output,
                 type: Sdf.ValueTypeName = Sdf.ValueTypeName()) -> Bool
  {
    ConnectToSource(source, Tf.Token(name), sourceType, type)
  }
}
