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

import Foundation
import Plug
import Rainbow

public extension Bundle
{
  static let pxr = Bundle.main.resourcePath!

  /**
   * Where ``Pixar.Ar`` application bundle resources are located. */
  static let ar = Bundle(path: "\(pxr)/SwiftUSD_Ar.bundle")

  /**
   * Where ``Pixar.Sdf`` application bundle resources are located. */
  static let sdf = Bundle(path: "\(pxr)/SwiftUSD_Sdf.bundle")

  /**
   * Where ``Pixar.Usd`` application bundle resources are located. */
  static let usd = Bundle(path: "\(pxr)/SwiftUSD_Usd.bundle")

  /**
   * Where ``Pixar.Ndr`` application bundle resources are located. */
  static let ndr = Bundle(path: "\(pxr)/SwiftUSD_Ndr.bundle")

  /**
   * Where ``Pixar.UsdGeom`` application bundle resources are located. */
  static let usdGeom = Bundle(path: "\(pxr)/SwiftUSD_UsdGeom.bundle")

  /**
   * Where ``Pixar.UsdShade`` application bundle resources are located. */
  static let usdShade = Bundle(path: "\(pxr)/SwiftUSD_UsdShade.bundle")

  /**
   * Where ``Pixar.UsdShaders`` application bundle resources are located. */
  static let usdShaders = Bundle(path: "\(pxr)/SwiftUSD_UsdShaders.bundle")

  /**
   * Where ``Pixar.UsdLux`` application bundle resources are located. */
  static let usdLux = Bundle(path: "\(pxr)/SwiftUSD_UsdLux.bundle")

  /**
   * Where ``Pixar.Tf`` python bundle resources are located. */
  static let pyTf = Bundle(path: "\(pxr)/SwiftUSD_PyTf.bundle")

  /**
   * Where ``Pixar.Plug`` python bundle resources are located. */
  static let pyPlug = Bundle(path: "\(pxr)/SwiftUSD_PyPlug.bundle")

  /**
   * Where ``Pixar.Trace`` python bundle resources are located. */
  static let pyTrace = Bundle(path: "\(pxr)/SwiftUSD_PyTrace.bundle")

  /**
   * Where ``Pixar.Work`` python bundle resources are located. */
  static let pyWork = Bundle(path: "\(pxr)/SwiftUSD_PyWork.bundle")

  /**
   * Where ``Pixar.Gf`` python bundle resources are located. */
  static let pyGf = Bundle(path: "\(pxr)/SwiftUSD_PyGf.bundle")

  /**
   * Where ``Pixar.Vt`` python bundle resources are located. */
  static let pyVt = Bundle(path: "\(pxr)/SwiftUSD_PyVt.bundle")

  /**
   * Where ``Pixar.Ar`` python bundle resources are located. */
  static let pyAr = Bundle(path: "\(pxr)/SwiftUSD_PyAr.bundle")

  /**
   * Where ``Pixar.Kind`` python bundle resources are located. */
  static let pyKind = Bundle(path: "\(pxr)/SwiftUSD_PyKind.bundle")

  /**
   * Where ``Pixar.Sdf`` python bundle resources are located. */
  static let pySdf = Bundle(path: "\(pxr)/SwiftUSD_PySdf.bundle")

  /**
   * Where ``Pixar.Pcp`` python bundle resources are located. */
  static let pyPcp = Bundle(path: "\(pxr)/SwiftUSD_PyPcp.bundle")

  /**
   * Where ``Pixar.Usd`` python bundle resources are located. */
  static let pyUsd = Bundle(path: "\(pxr)/SwiftUSD_PyUsd.bundle")

  /**
   * Where ``Pixar.Ndr`` python bundle resources are located. */
  static let pyNdr = Bundle(path: "\(pxr)/SwiftUSD_PyNdr.bundle")

  /**
   * Where ``Pixar.Sdr`` python bundle resources are located. */
  static let pySdr = Bundle(path: "\(pxr)/SwiftUSD_PySdr.bundle")

  /**
   * Where ``Pixar.UsdGeom`` python bundle resources are located. */
  static let pyUsdGeom = Bundle(path: "\(pxr)/SwiftUSD_PyUsdGeom.bundle")

  /**
   * Where ``Pixar.UsdShade`` python bundle resources are located. */
  static let pyUsdShade = Bundle(path: "\(pxr)/SwiftUSD_PyUsdShade.bundle")

  /**
   * Where ``Pixar.UsdShaders`` application bundle resources are located. */
  static let pyUsdShaders = Bundle(path: "\(pxr)/SwiftUSD_PyUsdShaders.bundle")

  /**
   * Where ``Pixar.UsdLux`` application bundle resources are located. */
  static let pyUsdLux = Bundle(path: "\(pxr)/SwiftUSD_PyUsdLux.bundle")
}

public extension Pixar
{
  struct Bundle
  {
    let fileManager = FileManager.default

    public static let shared = Pixar.Bundle()

    private init()
    {}

    public enum BundleKind
    {
      case resources
    }

    public func setup(_ kind: BundleKind)
    {
      switch kind
      {
        case .resources:
          resourcesInit()
      }
    }

    private func resourcesInit()
    {
      /* ?. Toggle app bundling help in console. */
      var showHelp = false

      /* 1. find all resource paths (ex. Usd/Contents/Resources) */
      let resources = BundleFramework.allCases.compactMap(\.resourcePath)

      /* 2. fill a std.vector of std.string plugin paths. */
      var plugPaths = Pixar.PlugRegistry.PlugPathsVector()
      _ = resources.map
      { path in

        /* Check for the existence of usd plugins, if they do not exist, we install them automatically. */
        if !fileManager.fileExists(atPath: path.replacingOccurrences(of: "/Contents/Resources", with: "") + "/Contents/Resources", isDirectory: nil),
           !path.contains(".app")
        {
          /* Tell user what we are doing. */
          showHelp = true

          /* Automatically install the plugin. */
          let installedPlug = installPlug(at: path)

          #if DEBUG_PIXAR_BUNDLE
            Msg.logger.log(level: .info, "Adding usd resource -> \(shortenedPath(from: installedPlug).trailing)")
          #endif /* DEBUG_PIXAR_BUNDLE */

          plugPaths.push_back(std.string(installedPlug))
        }
        else
        {
          #if DEBUG_PIXAR_BUNDLE
            Msg.logger.log(level: .info, "Adding usd resource -> \(shortenedPath(from: path).trailing)")
          #endif /* DEBUG_PIXAR_BUNDLE */

          plugPaths.push_back(std.string(path))
        }
      }

      if showHelp
      {
        showBundleHelp(
          with: resources.map { shortenedPath(from: $0).trailing },
          searched: shortenedPath(from: resources.first ?? "").leading
        )
        showHelp = false
      }

      /* 3. registers all plugins discovered in any plugPaths. */
      Pixar.PlugRegistry.GetInstance().RegisterPlugins(plugPaths)
    }
  }
}

public enum BundleFramework: CaseIterable
{
  case ar
  case sdf
  case usd
  case ndr
  case usdGeom
  case usdShade
  case usdShaders
  case usdLux

  public var resourcePath: String?
  {
    switch self
    {
      case .ar: Bundle.ar?.resourcePath
      case .sdf: Bundle.sdf?.resourcePath
      case .usd: Bundle.usd?.resourcePath
      case .ndr: Bundle.ndr?.resourcePath
      case .usdGeom: Bundle.usdGeom?.resourcePath
      case .usdShade: Bundle.usdShade?.resourcePath
      case .usdShaders: Bundle.usdShaders?.resourcePath
      case .usdLux: Bundle.usdLux?.resourcePath
    }
  }
}

public enum BundlePython: CaseIterable
{
  case pyTf
  case pyPlug
  case pyTrace
  case pyWork
  case pyGf
  case pyVt
  case pyAr
  case pyKind
  case pySdf
  case pyPcp
  case pyUsd
  case pyNdr
  case pySdr
  case pyUsdGeom
  case pyUsdShade
  case pyUsdShaders
  case pyUsdLux

  public var resourcePath: String?
  {
    switch self
    {
      case .pyTf: Bundle.pyTf?.resourcePath
      case .pyPlug: Bundle.pyPlug?.resourcePath
      case .pyTrace: Bundle.pyTrace?.resourcePath
      case .pyWork: Bundle.pyWork?.resourcePath
      case .pyGf: Bundle.pyGf?.resourcePath
      case .pyVt: Bundle.pyVt?.resourcePath
      case .pyAr: Bundle.pyAr?.resourcePath
      case .pyKind: Bundle.pyKind?.resourcePath
      case .pySdf: Bundle.pySdf?.resourcePath
      case .pyPcp: Bundle.pyPcp?.resourcePath
      case .pyUsd: Bundle.pyUsd?.resourcePath
      case .pyNdr: Bundle.pyNdr?.resourcePath
      case .pySdr: Bundle.pySdr?.resourcePath
      case .pyUsdGeom: Bundle.pyUsdGeom?.resourcePath
      case .pyUsdShade: Bundle.pyUsdShade?.resourcePath
      case .pyUsdShaders: Bundle.pyUsdShaders?.resourcePath
      case .pyUsdLux: Bundle.pyUsdLux?.resourcePath
    }
  }
}

public extension Pixar.Bundle
{
  private func installPlug(at path: String) -> String
  {
    func strip(_ path: String) -> String
    {
      path.replacingOccurrences(of: "/Contents/Resources", with: "")
    }

    let dest = strip(path) + "/Contents/Resources"
    let srcEnum = fileManager.enumerator(atPath: path)

    do
    {
      if fileManager.fileExists(atPath: strip(path) + "/Contents", isDirectory: nil)
      {
        try fileManager.removeItem(atPath: strip(path) + "/Contents")
      }

      try fileManager.createDirectory(atPath: dest, withIntermediateDirectories: true)

      while let file = srcEnum?.nextObject() as? String
      {
        let sourceFile = path.appending("/\(file)")
        let destFile = dest.appending("/\(file)")

        if sourceFile.contains("Contents")
        {
          continue
        }

        #if DEBUG_PIXAR_BUNDLE
          Msg.logger.log(level: .info, "Moving resource: \(sourceFile) -> \(destFile)")
        #endif /* DEBUG_PIXAR_BUNDLE */

        try fileManager.moveItem(atPath: sourceFile,
                                 toPath: destFile)
      }
    }
    catch
    {
      Msg.logger.log(level: .error, "Could not move usd resource from \(path) to \(dest): \(error.localizedDescription)")
    }

    return dest
  }
}

private extension Pixar.Bundle
{
  struct ShortPath
  {
    var leading: String
    var trailing: String
  }

  /**
   * Shorten a plug's long path up to its bundle dir by
   * returning the shortened path part of the string as
   * a struct with leading and trailing parts. Only for
   * console logs to keep them short and readable.
   */
  func shortenedPath(from string: String) -> ShortPath
  {
    #if os(macOS) || os(visionOS) || os(iOS) || os(tvOS) || os(watchOS)
      /** xcode build directories are capitalized, swiftpm builds are not. */
      let isXcodeBuild = string.contains("Build")

      #if DEBUG
        let shortenTo = isXcodeBuild ? "Debug/" : "debug/"
      #else
        let shortenTo = isXcodeBuild ? "Release/" : "release/"
      #endif
    #else
      #if DEBUG
        let shortenTo = "debug/"
      #else
        let shortenTo = "release/"
      #endif
    #endif

    if let theRange = string.range(of: shortenTo, options: .backwards)
    {
      return ShortPath(leading: String(string[..<theRange.lowerBound]) + shortenTo,
                       trailing: String(string[theRange.upperBound...]))
    }
    else
    {
      return ShortPath(leading: string, trailing: string)
    }
  }
}

private extension Pixar.Bundle
{
  func showBundleHelp(with missing: [String], searched: String)
  {
    Msg.logger.log(level: .warning, """

      \("MISSING USD RESOURCES".magenta) ------------------------------------------------------------------

      \("We searched for resources in the following location:".lightBlue)
      \("*".yellow)  \(searched.magenta)

      \("And the following resources were not found:".lightBlue)
      \(missing.map { "\("*".yellow)  \($0.magenta)" }.joined(separator: "\n"))

      ----------------------------------------------------------------------------------------

      Plugins are not installed and will be installed for you, however, you should bundle the
      application bundle appropriately with \("https://swiftbundler.dev".cyan) instead of the \("swift run".yellow)
      command, this is because \("swift run".yellow) is not meant to run bundled applications, it is best
      suited for command line utilities that do not require application resources or graphical
      user interfaces.

      ----------------------------------------------------------------------------------------

      The recommended method of running your app is to add swift bundler to the swift package
      by adding the following code to your package \("dependencies".yellow) array:

      \("dependencies: [".green)
      \("  .package(url: \"https://github.com/furby-tm/swift-bundler\", from: \"2.0.9\")".green)
      \("]".green)

      ----------------------------------------------------------------------------------------

      Then, instead of running \("swift run".yellow), use swift bundler's package plugin command:

      \("$".red) \("swift".yellow) package \("--disable-sandbox".lightWhite) plugin bundler run \("-p".lightWhite) \("macOS".magenta) \("MyApp".yellow)

      \("NOTE:".magenta) Ensure that you replace \("MyApp".yellow) to the name of your executable target,
      and change the platform (\("-p".lightWhite) \("macOS".magenta)) depending on the intended platform.

      The following platforms are currently supported:
      \("*".yellow) \("linux".magenta)
      \("*".yellow) \("macOS".magenta)
      \("*".yellow) \("visionOS".magenta) or \("visionOSSimulator".magenta)
      \("*".yellow) \("iOS".magenta) or \("iOSSimulator".magenta)

      When running on \("visionOSSimulator".magenta) or \("iOSSimulator".magenta), the simulator will automatically
      launch with an instance of your bundled app running within it.

      ----------------------------------------------------------------------------------------
      """)
  }
}
