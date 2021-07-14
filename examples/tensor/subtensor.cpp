#include <boost/numeric/ublas/tensor.hpp>

using namespace boost::numeric::ublas;

int main() {
	{
		const auto ts = tensor_dynamic<>();
		auto sts = make_subtensor(ts);
		auto sts_sts = make_subtensor(sts);
		auto sts_sts_sts = make_subtensor(sts_sts);
		static_assert(std::is_same_v<decltype(sts_sts_sts)::pointer, decltype(ts)::pointer>);
		static_assert(std::is_same_v<decltype(sts_sts_sts)::pointer, decltype(sts_sts)::pointer>);
	}
	{
		const auto ts = tensor_dynamic<>();
		auto sts = make_subtensor(ts);
		auto sts_sts = make_subtensor(sts);
		auto sts_sts_sts = make_subtensor(sts_sts);
		static_assert(std::is_same_v<decltype(sts_sts_sts)::parent_type, decltype(ts)::parent_type>);
		static_assert(std::is_same_v<decltype(sts_sts_sts)::parent_type, decltype(sts)::parent_type>);
	}
}
