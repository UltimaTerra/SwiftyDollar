//
// Copyright 2016 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
#include "UsdGeom/tokens.h"

PXR_NAMESPACE_OPEN_SCOPE

UsdGeomTokensType::UsdGeomTokensType() :
    accelerations("accelerations", TfToken::Immortal),
    all("all", TfToken::Immortal),
    angularVelocities("angularVelocities", TfToken::Immortal),
    axis("axis", TfToken::Immortal),
    basis("basis", TfToken::Immortal),
    bezier("bezier", TfToken::Immortal),
    bilinear("bilinear", TfToken::Immortal),
    boundaries("boundaries", TfToken::Immortal),
    bounds("bounds", TfToken::Immortal),
    box("box", TfToken::Immortal),
    bspline("bspline", TfToken::Immortal),
    cards("cards", TfToken::Immortal),
    catmullClark("catmullClark", TfToken::Immortal),
    catmullRom("catmullRom", TfToken::Immortal),
    clippingPlanes("clippingPlanes", TfToken::Immortal),
    clippingRange("clippingRange", TfToken::Immortal),
    closed("closed", TfToken::Immortal),
    constant("constant", TfToken::Immortal),
    cornerIndices("cornerIndices", TfToken::Immortal),
    cornerSharpnesses("cornerSharpnesses", TfToken::Immortal),
    cornersOnly("cornersOnly", TfToken::Immortal),
    cornersPlus1("cornersPlus1", TfToken::Immortal),
    cornersPlus2("cornersPlus2", TfToken::Immortal),
    creaseIndices("creaseIndices", TfToken::Immortal),
    creaseLengths("creaseLengths", TfToken::Immortal),
    creaseSharpnesses("creaseSharpnesses", TfToken::Immortal),
    cross("cross", TfToken::Immortal),
    cubic("cubic", TfToken::Immortal),
    curveVertexCounts("curveVertexCounts", TfToken::Immortal),
    default_("default", TfToken::Immortal),
    doubleSided("doubleSided", TfToken::Immortal),
    edgeAndCorner("edgeAndCorner", TfToken::Immortal),
    edgeOnly("edgeOnly", TfToken::Immortal),
    elementSize("elementSize", TfToken::Immortal),
    elementType("elementType", TfToken::Immortal),
    exposure("exposure", TfToken::Immortal),
    extent("extent", TfToken::Immortal),
    extentsHint("extentsHint", TfToken::Immortal),
    face("face", TfToken::Immortal),
    faceVarying("faceVarying", TfToken::Immortal),
    faceVaryingLinearInterpolation("faceVaryingLinearInterpolation", TfToken::Immortal),
    faceVertexCounts("faceVertexCounts", TfToken::Immortal),
    faceVertexIndices("faceVertexIndices", TfToken::Immortal),
    familyName("familyName", TfToken::Immortal),
    focalLength("focalLength", TfToken::Immortal),
    focusDistance("focusDistance", TfToken::Immortal),
    fromTexture("fromTexture", TfToken::Immortal),
    fStop("fStop", TfToken::Immortal),
    guide("guide", TfToken::Immortal),
    guideVisibility("guideVisibility", TfToken::Immortal),
    height("height", TfToken::Immortal),
    hermite("hermite", TfToken::Immortal),
    holeIndices("holeIndices", TfToken::Immortal),
    horizontalAperture("horizontalAperture", TfToken::Immortal),
    horizontalApertureOffset("horizontalApertureOffset", TfToken::Immortal),
    ids("ids", TfToken::Immortal),
    inactiveIds("inactiveIds", TfToken::Immortal),
    indices("indices", TfToken::Immortal),
    inherited("inherited", TfToken::Immortal),
    interpolateBoundary("interpolateBoundary", TfToken::Immortal),
    interpolation("interpolation", TfToken::Immortal),
    invisible("invisible", TfToken::Immortal),
    invisibleIds("invisibleIds", TfToken::Immortal),
    knots("knots", TfToken::Immortal),
    left("left", TfToken::Immortal),
    leftHanded("leftHanded", TfToken::Immortal),
    length("length", TfToken::Immortal),
    linear("linear", TfToken::Immortal),
    loop("loop", TfToken::Immortal),
    metersPerUnit("metersPerUnit", TfToken::Immortal),
    modelApplyDrawMode("model:applyDrawMode", TfToken::Immortal),
    modelCardGeometry("model:cardGeometry", TfToken::Immortal),
    modelCardTextureXNeg("model:cardTextureXNeg", TfToken::Immortal),
    modelCardTextureXPos("model:cardTextureXPos", TfToken::Immortal),
    modelCardTextureYNeg("model:cardTextureYNeg", TfToken::Immortal),
    modelCardTextureYPos("model:cardTextureYPos", TfToken::Immortal),
    modelCardTextureZNeg("model:cardTextureZNeg", TfToken::Immortal),
    modelCardTextureZPos("model:cardTextureZPos", TfToken::Immortal),
    modelDrawMode("model:drawMode", TfToken::Immortal),
    modelDrawModeColor("model:drawModeColor", TfToken::Immortal),
    mono("mono", TfToken::Immortal),
    motionBlurScale("motion:blurScale", TfToken::Immortal),
    motionNonlinearSampleCount("motion:nonlinearSampleCount", TfToken::Immortal),
    motionVelocityScale("motion:velocityScale", TfToken::Immortal),
    none("none", TfToken::Immortal),
    nonOverlapping("nonOverlapping", TfToken::Immortal),
    nonperiodic("nonperiodic", TfToken::Immortal),
    normals("normals", TfToken::Immortal),
    open("open", TfToken::Immortal),
    order("order", TfToken::Immortal),
    orientation("orientation", TfToken::Immortal),
    orientations("orientations", TfToken::Immortal),
    origin("origin", TfToken::Immortal),
    orthographic("orthographic", TfToken::Immortal),
    partition("partition", TfToken::Immortal),
    periodic("periodic", TfToken::Immortal),
    perspective("perspective", TfToken::Immortal),
    pinned("pinned", TfToken::Immortal),
    pivot("pivot", TfToken::Immortal),
    points("points", TfToken::Immortal),
    pointWeights("pointWeights", TfToken::Immortal),
    positions("positions", TfToken::Immortal),
    power("power", TfToken::Immortal),
    primvarsDisplayColor("primvars:displayColor", TfToken::Immortal),
    primvarsDisplayOpacity("primvars:displayOpacity", TfToken::Immortal),
    projection("projection", TfToken::Immortal),
    protoIndices("protoIndices", TfToken::Immortal),
    prototypes("prototypes", TfToken::Immortal),
    proxy("proxy", TfToken::Immortal),
    proxyPrim("proxyPrim", TfToken::Immortal),
    proxyVisibility("proxyVisibility", TfToken::Immortal),
    purpose("purpose", TfToken::Immortal),
    radius("radius", TfToken::Immortal),
    ranges("ranges", TfToken::Immortal),
    render("render", TfToken::Immortal),
    renderVisibility("renderVisibility", TfToken::Immortal),
    right("right", TfToken::Immortal),
    rightHanded("rightHanded", TfToken::Immortal),
    scales("scales", TfToken::Immortal),
    shutterClose("shutter:close", TfToken::Immortal),
    shutterOpen("shutter:open", TfToken::Immortal),
    size("size", TfToken::Immortal),
    smooth("smooth", TfToken::Immortal),
    stereoRole("stereoRole", TfToken::Immortal),
    subdivisionScheme("subdivisionScheme", TfToken::Immortal),
    tangents("tangents", TfToken::Immortal),
    triangleSubdivisionRule("triangleSubdivisionRule", TfToken::Immortal),
    trimCurveCounts("trimCurve:counts", TfToken::Immortal),
    trimCurveKnots("trimCurve:knots", TfToken::Immortal),
    trimCurveOrders("trimCurve:orders", TfToken::Immortal),
    trimCurvePoints("trimCurve:points", TfToken::Immortal),
    trimCurveRanges("trimCurve:ranges", TfToken::Immortal),
    trimCurveVertexCounts("trimCurve:vertexCounts", TfToken::Immortal),
    type("type", TfToken::Immortal),
    uForm("uForm", TfToken::Immortal),
    uKnots("uKnots", TfToken::Immortal),
    unauthoredValuesIndex("unauthoredValuesIndex", TfToken::Immortal),
    uniform("uniform", TfToken::Immortal),
    unrestricted("unrestricted", TfToken::Immortal),
    uOrder("uOrder", TfToken::Immortal),
    upAxis("upAxis", TfToken::Immortal),
    uRange("uRange", TfToken::Immortal),
    uVertexCount("uVertexCount", TfToken::Immortal),
    varying("varying", TfToken::Immortal),
    velocities("velocities", TfToken::Immortal),
    vertex("vertex", TfToken::Immortal),
    verticalAperture("verticalAperture", TfToken::Immortal),
    verticalApertureOffset("verticalApertureOffset", TfToken::Immortal),
    vForm("vForm", TfToken::Immortal),
    visibility("visibility", TfToken::Immortal),
    visible("visible", TfToken::Immortal),
    vKnots("vKnots", TfToken::Immortal),
    vOrder("vOrder", TfToken::Immortal),
    vRange("vRange", TfToken::Immortal),
    vVertexCount("vVertexCount", TfToken::Immortal),
    width("width", TfToken::Immortal),
    widths("widths", TfToken::Immortal),
    wrap("wrap", TfToken::Immortal),
    x("X", TfToken::Immortal),
    xformOpOrder("xformOpOrder", TfToken::Immortal),
    y("Y", TfToken::Immortal),
    z("Z", TfToken::Immortal),
    BasisCurves("BasisCurves", TfToken::Immortal),
    Boundable("Boundable", TfToken::Immortal),
    Camera("Camera", TfToken::Immortal),
    Capsule("Capsule", TfToken::Immortal),
    Cone("Cone", TfToken::Immortal),
    Cube("Cube", TfToken::Immortal),
    Curves("Curves", TfToken::Immortal),
    Cylinder("Cylinder", TfToken::Immortal),
    GeomModelAPI("GeomModelAPI", TfToken::Immortal),
    GeomSubset("GeomSubset", TfToken::Immortal),
    Gprim("Gprim", TfToken::Immortal),
    HermiteCurves("HermiteCurves", TfToken::Immortal),
    Imageable("Imageable", TfToken::Immortal),
    Mesh("Mesh", TfToken::Immortal),
    MotionAPI("MotionAPI", TfToken::Immortal),
    NurbsCurves("NurbsCurves", TfToken::Immortal),
    NurbsPatch("NurbsPatch", TfToken::Immortal),
    Plane("Plane", TfToken::Immortal),
    PointBased("PointBased", TfToken::Immortal),
    PointInstancer("PointInstancer", TfToken::Immortal),
    Points("Points", TfToken::Immortal),
    PrimvarsAPI("PrimvarsAPI", TfToken::Immortal),
    Scope("Scope", TfToken::Immortal),
    Sphere("Sphere", TfToken::Immortal),
    VisibilityAPI("VisibilityAPI", TfToken::Immortal),
    Xform("Xform", TfToken::Immortal),
    Xformable("Xformable", TfToken::Immortal),
    XformCommonAPI("XformCommonAPI", TfToken::Immortal),
    allTokens({
        accelerations,
        all,
        angularVelocities,
        axis,
        basis,
        bezier,
        bilinear,
        boundaries,
        bounds,
        box,
        bspline,
        cards,
        catmullClark,
        catmullRom,
        clippingPlanes,
        clippingRange,
        closed,
        constant,
        cornerIndices,
        cornerSharpnesses,
        cornersOnly,
        cornersPlus1,
        cornersPlus2,
        creaseIndices,
        creaseLengths,
        creaseSharpnesses,
        cross,
        cubic,
        curveVertexCounts,
        default_,
        doubleSided,
        edgeAndCorner,
        edgeOnly,
        elementSize,
        elementType,
        exposure,
        extent,
        extentsHint,
        face,
        faceVarying,
        faceVaryingLinearInterpolation,
        faceVertexCounts,
        faceVertexIndices,
        familyName,
        focalLength,
        focusDistance,
        fromTexture,
        fStop,
        guide,
        guideVisibility,
        height,
        hermite,
        holeIndices,
        horizontalAperture,
        horizontalApertureOffset,
        ids,
        inactiveIds,
        indices,
        inherited,
        interpolateBoundary,
        interpolation,
        invisible,
        invisibleIds,
        knots,
        left,
        leftHanded,
        length,
        linear,
        loop,
        metersPerUnit,
        modelApplyDrawMode,
        modelCardGeometry,
        modelCardTextureXNeg,
        modelCardTextureXPos,
        modelCardTextureYNeg,
        modelCardTextureYPos,
        modelCardTextureZNeg,
        modelCardTextureZPos,
        modelDrawMode,
        modelDrawModeColor,
        mono,
        motionBlurScale,
        motionNonlinearSampleCount,
        motionVelocityScale,
        none,
        nonOverlapping,
        nonperiodic,
        normals,
        open,
        order,
        orientation,
        orientations,
        origin,
        orthographic,
        partition,
        periodic,
        perspective,
        pinned,
        pivot,
        points,
        pointWeights,
        positions,
        power,
        primvarsDisplayColor,
        primvarsDisplayOpacity,
        projection,
        protoIndices,
        prototypes,
        proxy,
        proxyPrim,
        proxyVisibility,
        purpose,
        radius,
        ranges,
        render,
        renderVisibility,
        right,
        rightHanded,
        scales,
        shutterClose,
        shutterOpen,
        size,
        smooth,
        stereoRole,
        subdivisionScheme,
        tangents,
        triangleSubdivisionRule,
        trimCurveCounts,
        trimCurveKnots,
        trimCurveOrders,
        trimCurvePoints,
        trimCurveRanges,
        trimCurveVertexCounts,
        type,
        uForm,
        uKnots,
        unauthoredValuesIndex,
        uniform,
        unrestricted,
        uOrder,
        upAxis,
        uRange,
        uVertexCount,
        varying,
        velocities,
        vertex,
        verticalAperture,
        verticalApertureOffset,
        vForm,
        visibility,
        visible,
        vKnots,
        vOrder,
        vRange,
        vVertexCount,
        width,
        widths,
        wrap,
        x,
        xformOpOrder,
        y,
        z,
        BasisCurves,
        Boundable,
        Camera,
        Capsule,
        Cone,
        Cube,
        Curves,
        Cylinder,
        GeomModelAPI,
        GeomSubset,
        Gprim,
        HermiteCurves,
        Imageable,
        Mesh,
        MotionAPI,
        NurbsCurves,
        NurbsPatch,
        Plane,
        PointBased,
        PointInstancer,
        Points,
        PrimvarsAPI,
        Scope,
        Sphere,
        VisibilityAPI,
        Xform,
        Xformable,
        XformCommonAPI
    })
{
}

TfStaticData<UsdGeomTokensType> UsdGeomTokens;

PXR_NAMESPACE_CLOSE_SCOPE
