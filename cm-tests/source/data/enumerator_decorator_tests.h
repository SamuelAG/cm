#ifndef ENUMERATORDECORATOR_TESTS_H
#define ENUMERATORDECORATOR_TESTS_H


#include "data/enumerator_decorator.h"
#include "test_suite.h"

#include <QtTest>
#include <map>

namespace cm {
namespace data {

class EnumeratorDecoratorTests : public TestSuite {

    Q_OBJECT

public:
    EnumeratorDecoratorTests();

private slots:
    void constructor_givenNoParameters_setsDefaultProperties();
    void constructor_givenParameters_setsProperties();
    void setValue_givenNewValue_updatesValueAndEmitsSignal();
    void setValue_givenSameValue_takesNoAction();
    void jsonValue_whenDefaultValue_returnsJson();
    void jsonValue_whenValueSet_returnsJson();
    void update_whenPresentInJson_updatesValue();
    void update_whenNotPresentInJson_updatesValueToDefault();

private:
    enum TestEnum {
        UNKNOWN = 0,
        VALUE_1,
        VALUE_2,
        VALUE_3
    };

    const std::map<int, QString> descriptionMapper {
        {static_cast<int>(TestEnum::UNKNOWN), ""},
        {static_cast<int>(TestEnum::VALUE_1), "Value 1"},
        {static_cast<int>(TestEnum::VALUE_2), "Value 2"},
        {static_cast<int>(TestEnum::VALUE_3), "Value 3"}
    };
};

}}


#endif // ENUMERATORDECORATOR_TESTS_H
