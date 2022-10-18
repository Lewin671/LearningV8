#include <iostream>
#include "gtest/gtest.h"
#include "common/v8_test_fixture.h"
#include "v8.h"

using namespace v8;

class MaybeTest : public V8TestFixture {
};

TEST_F(MaybeTest, Maybe) {
    const HandleScope handle_scope(isolate_);
    Local<FunctionTemplate> constructor = Local<FunctionTemplate>();
    Local<ObjectTemplate> ot = ObjectTemplate::New(isolate_, constructor);

    // Add a property that all instanced created from this object template will
    // have. (Set is member function of class Template):
    const char *prop_name = "prop_name";
    const char *prop_value = "prop_value";
    Local<Name> name = String::NewFromUtf8(isolate_, prop_name, NewStringType::kNormal).ToLocalChecked();
    Local<Data> value = String::NewFromUtf8(isolate_, prop_value, NewStringType::kNormal).ToLocalChecked();
    ot->Set(name, value, PropertyAttribute::None);

    Handle<Context> context = Context::New(isolate_, nullptr, ot);
    Local<Object> instance1 = ot->NewInstance(context).ToLocalChecked();

    // Verify that the property we added exist in the instance we created:
    Local<Value> const &localValue = instance1->Get(context, name).ToLocalChecked();
    v8::String::Utf8Value str(isolate_, localValue);
    ASSERT_STREQ(*str, prop_value);
}

