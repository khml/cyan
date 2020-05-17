//
// Created by KHML on 2020/04/14.
//

#include <iostream>

#include <cyan/cyan.hpp>

cyan::Function createGreeting(cyan::Module& module)
{
    cyan::Type voidType("void");
    const cyan::Type& strType = cyan::types::stringType();
    cyan::Variable str("str", cyan::Literal("hello"));
    cyan::Function greeting("greeting", voidType, str);
    greeting << cyan::xpr(str).cout().endl();

    module << greeting;
    return greeting;
}

cyan::Function createSumming(cyan::Module& module)
{
    // create summing function
    const cyan::Type& intType = cyan::types::intType();
    cyan::Function summing("summing", intType);
    summing << cyan::Variable("a", cyan::Literal(0)) << cyan::Variable("b", cyan::Literal(0));

    cyan::Variable summingResult("sumResult", intType);
    cyan::Expression sumExpr(summingResult);
    sumExpr.assign(summing.args()[0]).add(summing.args()[1]);
    summing << sumExpr;
    summing().createRetValue(summingResult);

    module << summing;
    return summing;
}

cyan::CodeBlock createCalc(cyan::Function& summing)
{
    const cyan::Type& intType = cyan::types::intType();
    cyan::CodeBlock code;

    cyan::Variable sumResult("sumResult", intType);
    cyan::Variable subResult("subResult", intType);
    cyan::Variable mulResult("mulResult", intType);
    cyan::Variable divResult("divResult", intType);
    cyan::Variable modResult("modResult", intType);
    cyan::Literal one(1);

    cyan::Arguments ones;
    ones << one << one;
    code << cyan::createCallee(summing.name, ones, sumResult);

    cyan::Variables args;
    args << sumResult << sumResult;
    code.createCallee(summing, args, sumResult);

    code.createSub(one, one, subResult);
    code.createMul(one, one, mulResult);
    code.createDiv(one, one, divResult);
    code.createMod(one, one, modResult);

    cyan::Variable finResult("final", intType);
    code << xpr(finResult).assign(xpr(mulResult).add(divResult));

    code << cyan::xpr(sumResult).cout().endl();

    return code;
}

cyan::StructBlock createStruct(cyan::Module& module)
{
    cyan::Variables members;
    members << cyan::Variable("id", cyan::types::intType()) << cyan::Variable("age", cyan::types::intType());

    cyan::StructBlock block("Person", members);
    block << cyan::Variable("name", cyan::types::stringType());

    module << block;
    return block;
}

cyan::Variable createStructValue(cyan::StructBlock& structBlock, cyan::Function& main)
{
    cyan::Aggregate aggregate(structBlock);
    aggregate << cyan::Literal(0) << cyan::Literal(10) << cyan::Literal("Adam");
    cyan::Variable person("person", aggregate);
    main().declareVariable(person);
    return person;
}

cyan::EnumBlock createEnum(cyan::Module& module)
{
    cyan::NameSpace blue("blue");
    cyan::NameSpace order("order");
    cyan::EnumBlock orderEnum("Order");
    orderEnum << "first" << "second" << "third" << "forth";
    order << orderEnum;
    blue << order;
    module << blue;
    return orderEnum;
}

void createIfControl(const cyan::Variable& person, cyan::Function& main)
{
    cyan::IfControl control;
    cyan::CodeBlock ifBlock;
    cyan::CodeBlock elseIfBlock;
    cyan::CodeBlock elseBlock;

    cyan::Expression cond1(person);
    cyan::Expression cond2(person);
    cond1.dot("id").equal(cyan::Literal(0));
    cond2.dot("id").graterThan(cyan::Literal(0));

    ifBlock << cyan::xpr(cyan::Literal("Hello")).cout().endl();
    elseIfBlock << cyan::xpr(cyan::Literal("World")).cout().endl();
    elseBlock << cyan::xpr(cyan::Literal("!")).cout().endl();

    control.if_(cond1, ifBlock);
    control.elseIf_(cond2, elseIfBlock);
    control.else_(elseBlock);

    main << control;
}

void createWhileControl(cyan::Function& main)
{
    cyan::Variable idx("idx", cyan::Literal(0));
    main().declareVariable(idx);

    cyan::WhileControl whileCtrl(cyan::xpr(idx).lesserThan(cyan::Literal(10)));
    whileCtrl << cyan::xpr(idx).cout().endl();
    whileCtrl << cyan::xpr(idx).postIncrement();
    main << whileCtrl;

    cyan::DoWhileControl doCtrl(cyan::xpr(idx).lesserThan(cyan::Literal(10)));
    doCtrl() = whileCtrl();
    main << doCtrl;
}

void createNestedBlock(cyan::Function& main)
{
    cyan::CodeBlock block;
    cyan::Variable str("nested", cyan::Literal("Nested!"));
    block << str;
    block << cyan::xpr(str).cout().endl();
    main << block;
}

void createForBlock(cyan::Function& main)
{
    cyan::Variable idx("i", cyan::Literal(0));
    cyan::ForControl control(cyan::xpr(idx), cyan::xpr(idx).lesserThan(cyan::Literal(5)),
        cyan::xpr(idx).postIncrement());
    control << cyan::xpr(idx).cout().endl();
    main << control;
}

void createGreetingCallee(cyan::Module& module, cyan::Function& mainFunc)
{
    auto greeting = createGreeting(module);
    cyan::Arguments greetingArg;

    cyan::Literal helloConst(cyan::types::stringType(), "hello world");
    cyan::Variable helloVar("hello", helloConst);

    greetingArg.includeValue(helloConst);
    mainFunc().createCallee(greeting, greetingArg);

    mainFunc().declareVariable(helloVar);
    greetingArg.clear() << helloVar;
    mainFunc << cyan::createCallee(greeting.name, greetingArg);
}

void createStdErrOut(cyan::Function& main)
{
    cyan::Literal first(cyan::Type("blue::order::Order"), "blue::order::first");
    main << cyan::xpr(first).cerr().endl();
}

void createMainFunc(cyan::Module& module)
{
    // create main function
    const cyan::Type& intType = cyan::types::intType();
    cyan::Function mainFunc("main", intType);

    createGreetingCallee(module, mainFunc);

    auto personStruct = createStruct(module);
    auto person = createStructValue(personStruct, mainFunc);

    createIfControl(person, mainFunc);
    createWhileControl(mainFunc);
    createNestedBlock(mainFunc);
    createForBlock(mainFunc);

    createStdErrOut(mainFunc);

    auto summing = createSumming(module);
    mainFunc() + createCalc(summing);

    // return 0
    cyan::Literal zero(0);
    mainFunc << cyan::xpr(cyan::Literal(0)).ret();

    // resister main function to module
    module << mainFunc;
}

int main()
{
    cyan::Module module("main");
    module.include2c("iostream");
    module.include2h("string");

    auto orderEnum = createEnum(module);
    createMainFunc(module);

    auto& builder = cyan::Builder::instance();

    if (!builder.dump(module))
        std::cerr << "File Save Error" << std::endl;

    builder.build("main");

    return 0;
}
