#pragma once


#include <iostream>
#include <string>
#include "date.h"
#include <memory>


using namespace std;

enum class LogicalOperation
{
    And,
    Or,
};

enum class Comparison
{
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

class Node
{
public:

    virtual bool Evaluate(const Date& date_,
        const string& event_) const = 0;

private:

};

class EmptyNode : public Node
{
public:
    bool Evaluate(const Date& date_, const string& event_) const override;
};

class LogicalOperationNode : public Node
{
public:
    LogicalOperationNode(const LogicalOperation& logical_operation,
        const shared_ptr<const Node>& lhs, const shared_ptr<const Node>& rhs);

    bool Evaluate(const Date& date_, const string& event_) const override;

private:
    LogicalOperation operation;
    shared_ptr<const Node> left, right;
};

class DateComparisonNode : public Node
{
public:
    DateComparisonNode(const Comparison& comparator_, const Date& date_);

    bool Evaluate(const Date& date_, const string& event_) const override;

private:
    const Comparison comparator;
    const Date this_date;
};

class EventComparisonNode : public Node
{
public:
    EventComparisonNode(const Comparison& comparator_, const string& event_);

    bool Evaluate(const Date& date_, const string& event_) const override;

private:
    const Comparison comparator;
    const string this_event;
};