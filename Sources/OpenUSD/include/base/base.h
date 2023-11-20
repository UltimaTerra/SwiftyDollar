#ifndef OPENUSD_BASE_H
#define OPENUSD_BASE_H

// vt
#include <Base/vt/api.h>
#include <Base/vt/array.h>
#include <Base/vt/arrayPyBuffer.h>
#include <Base/vt/dictionary.h>
#include <Base/vt/functions.h>
#include <Base/vt/hash.h>
#include <Base/vt/pch.h>
#include <Base/vt/pyOperators.h>
#include <Base/vt/streamOut.h>
#include <Base/vt/traits.h>
#include <Base/vt/typeHeaders.h>
#include <Base/vt/types.h>
#include <Base/vt/value.h>
#include <Base/vt/valueFromPython.h>
#include <Base/vt/visitValue.h>
#include <Base/vt/wrapArray.h>

// trace
#include <Base/trace/aggregateNode.h>
#include <Base/trace/aggregateTree.h>
#include <Base/trace/aggregateTreeBuilder.h>
#include <Base/trace/api.h>
#include <Base/trace/category.h>
#include <Base/trace/collection.h>
#include <Base/trace/collectionNotice.h>
#include <Base/trace/collector.h>
#include <Base/trace/concurrentList.h>
#include <Base/trace/counterAccumulator.h>
#include <Base/trace/dataBuffer.h>
#include <Base/trace/dynamicKey.h>
#include <Base/trace/event.h>
#include <Base/trace/eventContainer.h>
#include <Base/trace/eventData.h>
#include <Base/trace/eventList.h>
#include <Base/trace/eventNode.h>
#include <Base/trace/eventTree.h>
#include <Base/trace/eventTreeBuilder.h>
#include <Base/trace/jsonSerialization.h>
#include <Base/trace/key.h>
#include <Base/trace/pch.h>
#include <Base/trace/reporter.h>
#include <Base/trace/reporterBase.h>
#include <Base/trace/reporterDataSourceBase.h>
#include <Base/trace/reporterDataSourceCollection.h>
#include <Base/trace/reporterDataSourceCollector.h>
#include <Base/trace/serialization.h>
#include <Base/trace/staticKeyData.h>
#include <Base/trace/stringHash.h>
#include <Base/trace/threads.h>
#include <Base/trace/trace.h>

// work
#include <Base/work/api.h>
#include <Base/work/detachedTask.h>
#include <Base/work/dispatcher.h>
#include <Base/work/loops.h>
#include <Base/work/pch.h>
#include <Base/work/reduce.h>
#include <Base/work/singularTask.h>
#include <Base/work/threadLimits.h>
#include <Base/work/utils.h>
#include <Base/work/withScopedParallelism.h>

// plug
#include <Base/plug/api.h>
#include <Base/plug/debugCodes.h>
#include <Base/plug/info.h>
#include <Base/plug/interfaceFactory.h>
#include <Base/plug/notice.h>
#include <Base/plug/pch.h>
#include <Base/plug/plugin.h>
#include <Base/plug/registry.h>
#include <Base/plug/staticInterface.h>
#include <Base/plug/testPlugBase.h>
#include <Base/plug/thisPlugin.h>

#endif /* OPENUSD_BASE_H */
