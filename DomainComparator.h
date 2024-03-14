#pragma once
template<class IDomain, typename T>
class DomainComparator {
public:
	DomainComparator(T(IDomain::* getter)()) : getter(getter) {}

	bool operator()( IDomain& lhs, IDomain& rhs) {
		return (lhs.*getter)() < (rhs.*getter)();
	}

private:
	T(IDomain::* getter)();
};

