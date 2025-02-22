/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"
#include "JSTestNode.h"

#include "ExceptionCode.h"
#include "JSDOMBinding.h"
#include "TestNode.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

/* Hash table */

static const HashTableValue JSTestNodeTableValues[] =
{
    { "constructor", DontEnum | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestNodeConstructor), (intptr_t)0, NoIntrinsic },
    { 0, 0, 0, 0, NoIntrinsic }
};

static const HashTable JSTestNodeTable = { 2, 1, JSTestNodeTableValues, 0 };
/* Hash table for constructor */

static const HashTableValue JSTestNodeConstructorTableValues[] =
{
    { 0, 0, 0, 0, NoIntrinsic }
};

static const HashTable JSTestNodeConstructorTable = { 1, 0, JSTestNodeConstructorTableValues, 0 };
EncodedJSValue JSC_HOST_CALL JSTestNodeConstructor::constructJSTestNode(ExecState* exec)
{
    JSTestNodeConstructor* castedThis = jsCast<JSTestNodeConstructor*>(exec->callee());
    RefPtr<TestNode> object = TestNode::create();
    return JSValue::encode(asObject(toJS(exec, castedThis->globalObject(), object.get())));
}

const ClassInfo JSTestNodeConstructor::s_info = { "TestNodeConstructor", &Base::s_info, &JSTestNodeConstructorTable, 0, CREATE_METHOD_TABLE(JSTestNodeConstructor) };

JSTestNodeConstructor::JSTestNodeConstructor(Structure* structure, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(structure, globalObject)
{
}

void JSTestNodeConstructor::finishCreation(ExecState* exec, JSDOMGlobalObject* globalObject)
{
    Base::finishCreation(exec->vm());
    ASSERT(inherits(info()));
    putDirect(exec->vm(), exec->propertyNames().prototype, JSTestNodePrototype::self(exec, globalObject), DontDelete | ReadOnly);
    putDirect(exec->vm(), exec->propertyNames().length, jsNumber(0), ReadOnly | DontDelete | DontEnum);
}

bool JSTestNodeConstructor::getOwnPropertySlot(JSObject* object, ExecState* exec, PropertyName propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSTestNodeConstructor, JSDOMWrapper>(exec, &JSTestNodeConstructorTable, jsCast<JSTestNodeConstructor*>(object), propertyName, slot);
}

ConstructType JSTestNodeConstructor::getConstructData(JSCell*, ConstructData& constructData)
{
    constructData.native.function = constructJSTestNode;
    return ConstructTypeHost;
}

/* Hash table for prototype */

static const HashTableValue JSTestNodePrototypeTableValues[] =
{
    { 0, 0, 0, 0, NoIntrinsic }
};

static const HashTable JSTestNodePrototypeTable = { 1, 0, JSTestNodePrototypeTableValues, 0 };
const ClassInfo JSTestNodePrototype::s_info = { "TestNodePrototype", &Base::s_info, &JSTestNodePrototypeTable, 0, CREATE_METHOD_TABLE(JSTestNodePrototype) };

JSObject* JSTestNodePrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSTestNode>(exec, globalObject);
}

const ClassInfo JSTestNode::s_info = { "TestNode", &Base::s_info, &JSTestNodeTable, 0 , CREATE_METHOD_TABLE(JSTestNode) };

JSTestNode::JSTestNode(Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<TestNode> impl)
    : JSNode(structure, globalObject, impl)
{
}

void JSTestNode::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(info()));
}

JSObject* JSTestNode::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return JSTestNodePrototype::create(exec->vm(), globalObject, JSTestNodePrototype::createStructure(exec->vm(), globalObject, JSNodePrototype::self(exec, globalObject)));
}

bool JSTestNode::getOwnPropertySlot(JSObject* object, ExecState* exec, PropertyName propertyName, PropertySlot& slot)
{
    JSTestNode* thisObject = jsCast<JSTestNode*>(object);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    return getStaticValueSlot<JSTestNode, Base>(exec, &JSTestNodeTable, thisObject, propertyName, slot);
}

JSValue jsTestNodeConstructor(ExecState* exec, JSValue slotBase, PropertyName)
{
    JSTestNode* domObject = jsCast<JSTestNode*>(asObject(slotBase));
    return JSTestNode::getConstructor(exec, domObject->globalObject());
}

JSValue JSTestNode::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestNodeConstructor>(exec, jsCast<JSDOMGlobalObject*>(globalObject));
}

void JSTestNode::visitChildren(JSCell* cell, SlotVisitor& visitor)
{
    JSTestNode* thisObject = jsCast<JSTestNode*>(cell);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    COMPILE_ASSERT(StructureFlags & OverridesVisitChildren, OverridesVisitChildrenWithoutSettingFlag);
    ASSERT(thisObject->structure()->typeInfo().overridesVisitChildren());
    Base::visitChildren(thisObject, visitor);
    thisObject->impl()->visitJSEventListeners(visitor);
}


}
