//This file is part of Bertini 2.
//
//special_number.hpp is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//special_number.hpp is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with special_number.hpp.  If not, see <http://www.gnu.org/licenses/>.
//
// Copyright(C) 2015, 2016 by Bertini2 Development Team
//
// See <http://www.gnu.org/licenses/> for a copy of the license, 
// as well as COPYING.  Bertini2 is provided with permitted 
// additional terms in the b2/licenses/ directory.

// individual authors of this file include:
//  James Collins
//  West Texas A&M University
//  Spring, Summer 2015
//
// Daniel Brake
// University of Notre Dame
//
//  Created by Collins, James B. on 4/30/15.
//
//
// special_number.hpp:  Declares the class SpecialNumber.

/**
\file special_number.hpp

\brief Provides the special numbers \f$\pi\f$, \f$e\f$, 1, 2, 0, as Nodes

*/

#ifndef BERTINI_FUNCTION_TREE_SPECIAL_NUMBER_HPP
#define BERTINI_FUNCTION_TREE_SPECIAL_NUMBER_HPP


#include "bertini2/function_tree/symbols/symbol.hpp"

#include "bertini2/function_tree/operators/arithmetic.hpp"
#include "bertini2/function_tree/operators/trig.hpp"

#include <cmath>



namespace bertini {
namespace node{
	using ::acos;
	using ::exp;

	
	namespace special_number{

		/**
		\brief The number \f$\pi\f$.

		The number \f$\pi\f$.  Gets its own class because it is such an important number.
		*/
		class Pi : public virtual NamedSymbol
		{
		public:
			Pi() : NamedSymbol("pi")
			{}

			virtual ~Pi() = default;


			void Reset() const override
			{
				Node::ResetStoredValues();
			}


			/**
			 Differentiates a number.  Should this return the special number Zero?
			 */
			std::shared_ptr<Node> Differentiate() const override
			{
				return std::make_shared<Integer>(0);
			}

			/**
			Compute the degree with respect to a single variable.

			For transcendental functions, the degree is 0 if the argument is constant, otherwise it's undefined, and we return -1.
			*/
			int Degree(std::shared_ptr<Variable> const& v = nullptr) const override
			{
				return 0;
			}


			int Degree(VariableGroup const& vars) const override
			{
				return 0;
			}

			std::vector<int> MultiDegree(VariableGroup const& vars) const override
			{
				return std::vector<int>(vars.size(), 0);
			}


			void Homogenize(VariableGroup const& vars, std::shared_ptr<Variable> const& homvar) override
			{
				
			}

			bool IsHomogeneous(std::shared_ptr<Variable> const& v = nullptr) const override
			{
				return true;
			}
			
			/**
			Check for homogeneity, with respect to a variable group.
			*/
			bool IsHomogeneous(VariableGroup const& vars) const override
			{
				return true;
			}


			/**
			 Change the precision of this variable-precision tree node.
			 
			 \param prec the number of digits to change precision to.
			 */
			virtual void precision(unsigned int prec) const override
			{
				auto& val_pair = std::get< std::pair<mpfr,bool> >(current_value_);
				val_pair.first.precision(prec);
			}



			
		private:
			// Return value of constant
			dbl FreshEval_d(std::shared_ptr<Variable> const& diff_variable) const override
			{
				return acos(-1.0);
			}
			
			void FreshEval_d(dbl& evaluation_value, std::shared_ptr<Variable> const& diff_variable) const override
			{
				evaluation_value = acos(-1.0);
			}


			mpfr FreshEval_mp(std::shared_ptr<Variable> const& diff_variable) const override
			{
				return mpfr(mpfr_float(acos(mpfr_float(-1))));
			}
			
			void FreshEval_mp(mpfr& evaluation_value, std::shared_ptr<Variable> const& diff_variable) const override
			{
				evaluation_value = mpfr(mpfr_float(acos(mpfr_float(-1))));
			}


			friend class boost::serialization::access;

			template <typename Archive>
			void serialize(Archive& ar, const unsigned version) {
				ar & boost::serialization::base_object<NamedSymbol>(*this);
			}
		};



		/**
		\brief The number \f$e\f$.

		The number \f$e\f$.  Gets its own class because it is such an important number.
		*/
		class E : public virtual NamedSymbol
		{
		public:
			E() : NamedSymbol("e")
			{}

			virtual ~E() = default;


			void Reset() const override
			{
				Node::ResetStoredValues();
			}

			/**
			 Differentiates a number.  Should this return the special number Zero?
			 */
			std::shared_ptr<Node> Differentiate() const override
			{
				return std::make_shared<Integer>(0);
			}

			/**
			Compute the degree with respect to a single variable.

			For transcendental functions, the degree is 0 if the argument is constant, otherwise it's undefined, and we return -1.
			*/
			int Degree(std::shared_ptr<Variable> const& v = nullptr) const override
			{
				return 0;
			}


			int Degree(VariableGroup const& vars) const override
			{
				return 0;
			}

			std::vector<int> MultiDegree(VariableGroup const& vars) const override
			{
				return std::vector<int>(vars.size(), 0);
			}


			void Homogenize(VariableGroup const& vars, std::shared_ptr<Variable> const& homvar) override
			{
				
			}

			bool IsHomogeneous(std::shared_ptr<Variable> const& v = nullptr) const override
			{
				return true;
			}
			
			/**
			Check for homogeneity, with respect to a variable group.
			*/
			bool IsHomogeneous(VariableGroup const& vars) const override
			{
				return true;
			}

			/**
			 Change the precision of this variable-precision tree node.
			 
			 \param prec the number of digits to change precision to.
			 */
			virtual void precision(unsigned int prec) const override
			{
				auto& val_pair = std::get< std::pair<mpfr,bool> >(current_value_);
				val_pair.first.precision(prec);
			}

		private:
			// Return value of constant
			dbl FreshEval_d(std::shared_ptr<Variable> const& diff_variable) const override
			{
				return dbl(exp(1.0f),0.0);
			}
			
			void FreshEval_d(dbl& evaluation_value, std::shared_ptr<Variable> const& diff_variable) const override
			{
				evaluation_value = dbl(exp(1.0f),0.0);
			}


			mpfr FreshEval_mp(std::shared_ptr<Variable> const& diff_variable) const override
			{
				return mpfr(mpfr_float(exp(mpfr_float(1))));
			}
			
			void FreshEval_mp(mpfr& evaluation_value, std::shared_ptr<Variable> const& diff_variable) const override
			{
				evaluation_value = mpfr(mpfr_float(exp(mpfr_float(1))));
			}


			friend class boost::serialization::access;

			template <typename Archive>
			void serialize(Archive& ar, const unsigned version) {
				ar & boost::serialization::base_object<NamedSymbol>(*this);
			}

		};

	} // re: special_number namespace


	/**
	Construct a shared pointer to \f$\pi\f$.
	*/
	std::shared_ptr<Node> Pi();

	/**
	Construct a shared pointer to \f$e\f$.
	*/
	std::shared_ptr<Node> E();

	/**
	Construct a shared pointer to \f$i\f$.
	*/
	std::shared_ptr<Node> I();

	/**
	Construct a shared pointer to \f$2\f$.
	*/
	std::shared_ptr<Node> Two();

	/**
	Construct a shared pointer to \f$1\f$.
	*/
	std::shared_ptr<Node> One();

	/**
	Construct a shared pointer to \f$0\f$.
	*/
	std::shared_ptr<Node> Zero();


} // re: namespace node
} // re: namespace bertini
	
#endif





