#include "node.h"

bool EmptyNode::Evaluate(const Date& date_, const string& event_) const
{
    return true;
}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation& operation,
	const shared_ptr<const Node>& lhs, const shared_ptr<const Node>& rhs) :
	operation(operation), left(lhs), right(rhs) {}


bool LogicalOperationNode::Evaluate(const Date& date_, const string& event_) const
{
	if (operation == LogicalOperation::Or)
	{
		return left->Evaluate(date_, event_) || right->Evaluate(date_, event_);
	}

	return left->Evaluate(date_, event_) && right->Evaluate(date_, event_);
}

DateComparisonNode::DateComparisonNode(const Comparison& comparator_,
	const Date& date_) : comparator(comparator_), this_date(date_) {}


bool DateComparisonNode::Evaluate(const Date& date_, const string& event_) const
{
	if (comparator == Comparison::Equal)
		return date_ == this_date;

	if (comparator == Comparison::Greater)
		return date_ > this_date;

	if (comparator == Comparison::GreaterOrEqual)
		return date_ >= this_date;

	if (comparator == Comparison::Less)
		return date_ < this_date;

	if (comparator == Comparison::LessOrEqual)
		return date_ <= this_date;

	return date_ != this_date;
}

EventComparisonNode::EventComparisonNode(const Comparison& comparator_,
	const string& event_) : comparator(comparator_), this_event(event_) {}


bool EventComparisonNode::Evaluate(const Date& date_, const string& event_) const
{
	if (comparator == Comparison::Equal)
		return event_ == this_event;

	if (comparator == Comparison::Greater)
		return event_ > this_event;

	if (comparator == Comparison::GreaterOrEqual)
		return event_ >= this_event;

	if (comparator == Comparison::Less)
		return event_ < this_event;

	if (comparator == Comparison::LessOrEqual)
		return event_ <= this_event;

	return event_ != this_event;
}