#include "stringdecorator_tests.h"
#include <data/entity.h>

namespace cm {
namespace data {

static StringDecoratorTests instance;

StringDecoratorTests::StringDecoratorTests()
    : TestSuite("StringDecoratorTests") {}

void StringDecoratorTests::constructor_givenNoParameters_setsDefaultProperties() {
    StringDecorator decorator;
    QCOMPARE(decorator.parentEntity(), nullptr);
    QCOMPARE(decorator.key(), QString("SomeItemKey"));
    QCOMPARE(decorator.label(), QString(""));
    QCOMPARE(decorator.value(), QString(""));
}

void StringDecoratorTests::constructor_givenParameters_setsProperties() {

    Entity parentEntity;
    StringDecorator decorator(&parentEntity, "Test Key", "Test Label", QString("Test Value"));

    QCOMPARE(decorator.parentEntity(), &parentEntity);
    QCOMPARE(decorator.key(), QString("Test Key"));
    QCOMPARE(decorator.label(), QString("Test Label"));
    QCOMPARE(decorator.value(), QString("Test Value"));
}

void StringDecoratorTests::setValue_givenNewValue_updatesValueAndEmitsSignal()
{
    StringDecorator decorator;
    QSignalSpy valueChangedSpy(&decorator,
                               &StringDecorator::valueChanged);
    QCOMPARE(decorator.value(), "");
    decorator.setValue("99");
    QCOMPARE(decorator.value(), "99");
    QCOMPARE(valueChangedSpy.count(), 1);
}

void StringDecoratorTests::setValue_givenSameValue_takesNoAction() {

    StringDecorator decorator;
    QSignalSpy valueChangedSpy(&decorator, &StringDecorator::valueChanged);
    QCOMPARE(decorator.value(), QString(""));
    decorator.setValue(QString("Test Value"));
    QCOMPARE(decorator.value(), QString("Test Value"));
    QCOMPARE(valueChangedSpy.count(), 1);
}

void StringDecoratorTests::jsonValue_whenDefaultValue_returnsJson() {

    StringDecorator decorator(nullptr, "Test Key", "Test Label", QString("Test Value"));
    QSignalSpy valueChangedSpy(&decorator, &StringDecorator::valueChanged);
    QCOMPARE(decorator.value(), QString("Test Value"));
    decorator.setValue(QString("Test Value"));
    QCOMPARE(decorator.value(), QString("Test Value"));
    QCOMPARE(valueChangedSpy.count(), 0);
}

void StringDecoratorTests::jsonValue_whenValueSet_returnsJson() {
    StringDecorator decorator;
    QCOMPARE(decorator.jsonValue(), QJsonValue(""));
}

void StringDecoratorTests::update_whenPresentInJson_updatesValue() {
    StringDecorator decorator;
    decorator.setValue(QString("Test Value"));
    QCOMPARE(decorator.jsonValue(), QJsonValue(QString("Test Value")));
}

void StringDecoratorTests::update_whenNotPresentInJson_updatesValueToDefault() {

    StringDecorator decorator(nullptr, "Test Key", "Test Label", QString("Test Value"));
    QSignalSpy valueChangedSpy(&decorator, &StringDecorator::valueChanged);
    QCOMPARE(decorator.value(), QString("Test Value"));
    QJsonObject jsonObject;
    jsonObject.insert("Key 1", "Value 1");
    jsonObject.insert("Test Key", QString("New Test Value"));
    jsonObject.insert("Key 3", 3);
    decorator.update(jsonObject);
    QCOMPARE(decorator.value(), QString("New Test Value"));
    QCOMPARE(valueChangedSpy.count(), 1);
}

}}
