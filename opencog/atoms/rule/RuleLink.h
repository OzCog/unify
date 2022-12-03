/*
 * opencog/atoms/rule/RuleLink.h
 *
 * Copyright (C) 2015 Linas Vepstas
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License v3 as
 * published by the Free Software Foundation and including the exceptions
 * at http://opencog.org/wiki/Licenses
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program; if not, write to:
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef _OPENCOG_RULE_LINK_H
#define _OPENCOG_RULE_LINK_H

#include <opencog/atoms/base/Link.h>
#include <opencog/atoms/unify_types/atom_types.h>

namespace opencog
{
/** \addtogroup grp_atomspace
 *  @{
 */

/// The RuleLink performs unification with rewriting,
///
class RuleLink : public Link
{
public:
	RuleLink(const HandleSeq&&, Type = RULE_LINK);
	RuleLink(const RuleLink&) = delete;
	RuleLink& operator=(const RuleLink&) = delete;

	virtual bool is_executable(void) const { return true; }

	// Return a pointer to the results
	virtual ValuePtr execute(AtomSpace*, bool);

	static Handle factory(const Handle&);
};

LINK_PTR_DECL(RuleLink)
#define createRuleLink CREATE_DECL(RuleLink)

/** @}*/
}

extern "C" {
void opencog_unify_atoms_init(void);
};

#endif // _OPENCOG_RULE_LINK_H
