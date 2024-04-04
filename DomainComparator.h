#pragma once
template<class Domain, typename T>
class DomainComparator {
public:
	DomainComparator(T(Domain::* getter)()) : getter(getter) {}

	bool operator()( Domain& lhs, Domain& rhs) {
		return (lhs.*getter)() < (rhs.*getter)();
	}

private:
	T(Domain::* getter)();
};

