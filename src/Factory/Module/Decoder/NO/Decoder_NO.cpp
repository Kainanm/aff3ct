#include <sstream>

#include "Tools/Exception/exception.hpp"

#include "Module/Decoder/NO/Decoder_NO.hpp"

#include "Decoder_NO.hpp"

using namespace aff3ct;
using namespace aff3ct::factory;

const std::string aff3ct::factory::Decoder_NO::name   = "Decoder NO";
const std::string aff3ct::factory::Decoder_NO::prefix = "dec";

template <typename B, typename Q>
module::Decoder_SISO_SIHO<B,Q>* Decoder_NO::parameters
::build() const
{
	if (this->type == "NONE" && this->implem == "HARD_DECISION") return new module::Decoder_NO<B,Q>(this->K, this->n_frames);

	throw tools::cannot_allocate(__FILE__, __LINE__, __func__);
}

template <typename B, typename Q>
module::Decoder_SISO_SIHO<B,Q>* Decoder_NO
::build(const parameters &params)
{
	return params.template build<B,Q>();
}

void Decoder_NO
::build_args(arg_map &req_args, arg_map &opt_args, const std::string p)
{
	Decoder::build_args(req_args, opt_args, p);

	opt_args[{p+"-type", "D"}].push_back("NONE");
	opt_args[{p+"-implem"   }].push_back("HARD_DECISION");
}

void Decoder_NO
::store_args(const arg_val_map &vals, parameters &params, const std::string p)
{
	params.type   = "NONE";
	params.implem = "HARD_DECISION";

	Decoder::store_args(vals, params, p);
}

void Decoder_NO
::make_header(params_list& head_dec, const parameters& params, const bool full)
{
	Decoder::make_header(head_dec, params, full);
}

// ==================================================================================== explicit template instantiation
#include "Tools/types.h"
#ifdef MULTI_PREC
template aff3ct::module::Decoder_SISO_SIHO<B_8 ,Q_8 >* aff3ct::factory::Decoder_NO::parameters::build<B_8 ,Q_8 >() const;
template aff3ct::module::Decoder_SISO_SIHO<B_16,Q_16>* aff3ct::factory::Decoder_NO::parameters::build<B_16,Q_16>() const;
template aff3ct::module::Decoder_SISO_SIHO<B_32,Q_32>* aff3ct::factory::Decoder_NO::parameters::build<B_32,Q_32>() const;
template aff3ct::module::Decoder_SISO_SIHO<B_64,Q_64>* aff3ct::factory::Decoder_NO::parameters::build<B_64,Q_64>() const;
template aff3ct::module::Decoder_SISO_SIHO<B_8 ,Q_8 >* aff3ct::factory::Decoder_NO::build<B_8 ,Q_8 >(const aff3ct::factory::Decoder_NO::parameters&);
template aff3ct::module::Decoder_SISO_SIHO<B_16,Q_16>* aff3ct::factory::Decoder_NO::build<B_16,Q_16>(const aff3ct::factory::Decoder_NO::parameters&);
template aff3ct::module::Decoder_SISO_SIHO<B_32,Q_32>* aff3ct::factory::Decoder_NO::build<B_32,Q_32>(const aff3ct::factory::Decoder_NO::parameters&);
template aff3ct::module::Decoder_SISO_SIHO<B_64,Q_64>* aff3ct::factory::Decoder_NO::build<B_64,Q_64>(const aff3ct::factory::Decoder_NO::parameters&);
#else
template aff3ct::module::Decoder_SISO_SIHO<B,Q>* aff3ct::factory::Decoder_NO::parameters::build<B,Q>() const;
template aff3ct::module::Decoder_SISO_SIHO<B,Q>* aff3ct::factory::Decoder_NO::build<B,Q>(const aff3ct::factory::Decoder_NO::parameters&);
#endif
// ==================================================================================== explicit template instantiation