/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcApproval.h"
#include "ifcpp/IFC4/include/IfcDefinitionSelect.h"
#include "ifcpp/IFC4/include/IfcGloballyUniqueId.h"
#include "ifcpp/IFC4/include/IfcLabel.h"
#include "ifcpp/IFC4/include/IfcOwnerHistory.h"
#include "ifcpp/IFC4/include/IfcRelAssociatesApproval.h"
#include "ifcpp/IFC4/include/IfcText.h"

// ENTITY IfcRelAssociatesApproval 
IfcRelAssociatesApproval::IfcRelAssociatesApproval() {}
IfcRelAssociatesApproval::IfcRelAssociatesApproval( int id ) { m_entity_id = id; }
IfcRelAssociatesApproval::~IfcRelAssociatesApproval() {}
shared_ptr<BuildingObject> IfcRelAssociatesApproval::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcRelAssociatesApproval> copy_self( new IfcRelAssociatesApproval() );
	if( m_GlobalId )
	{
		if( options.create_new_IfcGloballyUniqueId ) { copy_self->m_GlobalId = shared_ptr<IfcGloballyUniqueId>(new IfcGloballyUniqueId( createBase64Uuid<wchar_t>().data() ) ); }
		else { copy_self->m_GlobalId = dynamic_pointer_cast<IfcGloballyUniqueId>( m_GlobalId->getDeepCopy(options) ); }
	}
	if( m_OwnerHistory )
	{
		if( options.shallow_copy_IfcOwnerHistory ) { copy_self->m_OwnerHistory = m_OwnerHistory; }
		else { copy_self->m_OwnerHistory = dynamic_pointer_cast<IfcOwnerHistory>( m_OwnerHistory->getDeepCopy(options) ); }
	}
	if( m_Name ) { copy_self->m_Name = dynamic_pointer_cast<IfcLabel>( m_Name->getDeepCopy(options) ); }
	if( m_Description ) { copy_self->m_Description = dynamic_pointer_cast<IfcText>( m_Description->getDeepCopy(options) ); }
	for( size_t ii=0; ii<m_RelatedObjects.size(); ++ii )
	{
		auto item_ii = m_RelatedObjects[ii];
		if( item_ii )
		{
			copy_self->m_RelatedObjects.push_back( dynamic_pointer_cast<IfcDefinitionSelect>(item_ii->getDeepCopy(options) ) );
		}
	}
	if( m_RelatingApproval ) { copy_self->m_RelatingApproval = dynamic_pointer_cast<IfcApproval>( m_RelatingApproval->getDeepCopy(options) ); }
	return copy_self;
}
void IfcRelAssociatesApproval::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_entity_id << "= IFCRELASSOCIATESAPPROVAL" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_entity_id; } else { stream << "$"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	stream << "(";
	for( size_t ii = 0; ii < m_RelatedObjects.size(); ++ii )
	{
		if( ii > 0 )
		{
			stream << ",";
		}
		const shared_ptr<IfcDefinitionSelect>& type_object = m_RelatedObjects[ii];
		if( type_object )
		{
			type_object->getStepParameter( stream, true );
		}
		else
		{
			stream << "$";
		}
	}
	stream << ")";
	stream << ",";
	if( m_RelatingApproval ) { stream << "#" << m_RelatingApproval->m_entity_id; } else { stream << "$"; }
	stream << ");";
}
void IfcRelAssociatesApproval::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_entity_id; }
const std::wstring IfcRelAssociatesApproval::toString() const { return L"IfcRelAssociatesApproval"; }
void IfcRelAssociatesApproval::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<BuildingEntity> >& map )
{
	const size_t num_args = args.size();
	if( num_args != 6 ){ std::stringstream err; err << "Wrong parameter count for entity IfcRelAssociatesApproval, expecting 6, having " << num_args << ". Entity ID: " << m_entity_id << std::endl; throw BuildingException( err.str().c_str() ); }
	m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0], map );
	readEntityReference( args[1], m_OwnerHistory, map );
	m_Name = IfcLabel::createObjectFromSTEP( args[2], map );
	m_Description = IfcText::createObjectFromSTEP( args[3], map );
	readSelectList( args[4], m_RelatedObjects, map );
	readEntityReference( args[5], m_RelatingApproval, map );
}
void IfcRelAssociatesApproval::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes )
{
	IfcRelAssociates::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "RelatingApproval", m_RelatingApproval ) );
}
void IfcRelAssociatesApproval::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse )
{
	IfcRelAssociates::getAttributesInverse( vec_attributes_inverse );
}
void IfcRelAssociatesApproval::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcRelAssociates::setInverseCounterparts( ptr_self_entity );
	shared_ptr<IfcRelAssociatesApproval> ptr_self = dynamic_pointer_cast<IfcRelAssociatesApproval>( ptr_self_entity );
	if( !ptr_self ) { throw BuildingException( "IfcRelAssociatesApproval::setInverseCounterparts: type mismatch" ); }
	if( m_RelatingApproval )
	{
		m_RelatingApproval->m_ApprovedObjects_inverse.push_back( ptr_self );
	}
}
void IfcRelAssociatesApproval::unlinkFromInverseCounterparts()
{
	IfcRelAssociates::unlinkFromInverseCounterparts();
	if( m_RelatingApproval )
	{
		std::vector<weak_ptr<IfcRelAssociatesApproval> >& ApprovedObjects_inverse = m_RelatingApproval->m_ApprovedObjects_inverse;
		for( auto it_ApprovedObjects_inverse = ApprovedObjects_inverse.begin(); it_ApprovedObjects_inverse != ApprovedObjects_inverse.end(); )
		{
			weak_ptr<IfcRelAssociatesApproval> self_candidate_weak = *it_ApprovedObjects_inverse;
			if( self_candidate_weak.expired() )
			{
				++it_ApprovedObjects_inverse;
				continue;
			}
			shared_ptr<IfcRelAssociatesApproval> self_candidate( *it_ApprovedObjects_inverse );
			if( self_candidate.get() == this )
			{
				it_ApprovedObjects_inverse= ApprovedObjects_inverse.erase( it_ApprovedObjects_inverse );
			}
			else
			{
				++it_ApprovedObjects_inverse;
			}
		}
	}
}
