#ifndef FACTORY_CODEC_SISO_HPP_
#define FACTORY_CODEC_SISO_HPP_

#include <string>

#include "Module/Codec/Codec_SISO.hpp"
#include "Module/CRC/CRC.hpp"

#include "Codec.hpp"

namespace aff3ct
{
namespace factory
{
extern const std::string Codec_SISO_name;
extern const std::string Codec_SISO_prefix;
struct Codec_SISO : Codec
{
	class parameters : virtual public Codec::parameters
	{
	public:
		// ------------------------------------------------------------------------------------------------- PARAMETERS
		// empty

		// ---------------------------------------------------------------------------------------------------- METHODS
		explicit parameters(const std::string &p = Codec_SISO_prefix);
		virtual ~parameters() = default;
		// The following line is commented to prevent Visual C++ to incorrectly report ambiguity when covariance is
		// used with virtual inheritance.
		// See more about this MSVC bug:
		// - https://stackoverflow.com/questions/6933061/c-ambiguous-inheritance-error-in-vs-2010
		// - https://connect.microsoft.com/VisualStudio/feedback/details/590625/visual-c-incorrectly-reports-ambiguity-when-covariance-is-used-with-virtual-inheritance
		// - https://docs.microsoft.com/fr-fr/cpp/error-messages/compiler-errors-1/compiler-error-c2250
//		virtual Codec_SISO::parameters* clone() const = 0;

		// builder
		template <typename B = int, typename Q = float>
		module::Codec_SISO<B,Q>* build(module::CRC<B>* crc = nullptr) const;

	protected:
		parameters(const std::string &n, const std::string &p);
	};

	template <typename B = int, typename Q = float>
	static module::Codec_SISO<B,Q>* build(const parameters &params, module::CRC<B> *crc = nullptr);
};
}
}

#endif /* FACTORY_CODEC_SISO_HPP_ */
