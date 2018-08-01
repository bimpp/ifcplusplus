/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcGloballyUniqueId.h"
#include "ifcpp/IFC4/include/IfcGroup.h"
#include "ifcpp/IFC4/include/IfcLabel.h"
#include "ifcpp/IFC4/include/IfcObjectDefinition.h"
#include "ifcpp/IFC4/include/IfcObjectTypeEnum.h"
#include "ifcpp/IFC4/include/IfcOwnerHistory.h"
#include "ifcpp/IFC4/include/IfcRelAssignsToGroup.h"
#include "ifcpp/IFC4/include/IfcText.h"

// ENTITY IfcRelAssignsToGroup 
IfcRelAssignsToGroup::IfcRelAssignsToGroup() {}
IfcRelAssignsToGroup::IfcRelAssignsToGroup( int id ) { m_entity_id = id; }
IfcRelAssignsToGroup::~IfcRelAssignsToGroup() {}
shared_ptr<BuildingObject> IfcRelAssignsToGroup::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcRelAssignsToGroup> copy_self( new IfcRelAssignsToGroup() );
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
			copy_self->m_RelatedObjects.push_back( dynamic_pointer_cast<IfcObjectDefinition>(item_ii->getDeepCopy(options) ) );
		}
	}
	if( m_RelatedObjectsType ) { copy_self->m_RelatedObjectsType = dynamic_pointer_cast<IfcObjectTypeEnum>( m_RelatedObjectsType->getDeepCopy(options) ); }
	if( m_RelatingGroup ) { copy_self->m_RelatingGroup = dynamic_pointer_cast<IfcGroup>( m_RelatingGroup->getDeepCopy(options) ); }
	return copy_self;
}
void IfcRelAssignsToGroup::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_entity_id << "= IFCRELASSIGNSTOGROUP" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_entity_id; } else { stream << "$"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	writeEntityList( stream, m_RelatedObjects );
	stream << ",";
	if( m_RelatedObjectsType ) { m_RelatedObjectsType->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_RelatingGroup ) { stream << "#" << m_RelatingGroup->m_entity_id; } else { stream << "$"; }
	stream << ");";
}
void IfcRelAssignsToGroup::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_entity_id; }
const std::wstring IfcRelAssignsToGroup::toString() const { return L"IfcRelAssignsToGroup"; }
void IfcRelAssignsToGroup::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<BuildingEntity> >& map )
{
	const size_t num_args = args.size();
	if( num_args != 7 ){ std::stringstream err; err << "Wrong parameter count for entity IfcRelAssignsToGroup, expecting 7, having " << num_args << ". Entity ID: " << m_entity_id << std::endl; throw BuildingException( err.str().c_str() ); }
	m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0], map );
	readEntityReference( args[1], m_OwnerHistory, map );
	m_Name = IfcLabel::createObjectFromSTEP( args[2], map );
	m_Description = IfcText::createObjectFromSTEP( args[3], map );
	readEntityReferenceList( args[4], m_RelatedObjects, map );
	m_RelatedObjectsType = IfcObjectTypeEnum::createObjectFromSTEP( args[5], map );
	readEntityReference( args[6], m_RelatingGroup, map );
}
void IfcRelAssignsToGroup::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes )
{
	IfcRelAssigns::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "RelatingGroup", m_RelatingGroup ) );
}
void IfcRelAssignsToGroup::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse )
{
	IfcRelAssigns::getAttributesInverse( vec_attributes_inverse );
}
void IfcRelAssignsToGroup::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcRelAssigns::setInverseCounterparts( ptr_self_entity );
	shared_ptr<IfcRelAssignsToGroup> ptr_self = dynamic_pointer_cast<IfcRelAssignsToGroup>( ptr_self_entity );
	if( !ptr_self ) { throw BuildingException( "IfcRelAssignsToGroup::setInverseCounterparts: type mismatch" ); }
	if( m_RelatingGroup )
	{
		m_RelatingGroup->m_IsGroupedBy_inverse.push_back( ptr_self );
	}
}
void IfcRelAssignsToGroup::unlinkFromInverseCounterparts()
{
	IfcRelAssigns::unlinkFromInverseCounterparts();
	if( m_RelatingGroup )
	{
		std::vector<weak_ptr<IfcRelAssignsToGroup> >& IsGroupedBy_inverse = m_RelatingGroup->m_IsGroupedBy_inverse;
		for( auto it_IsGroupedBy_inverse = IsGroupedBy_inverse.begin(); it_IsGroupedBy_inverse != IsGroupedBy_inverse.end(); )
		{
			weak_ptr<IfcRelAssignsToGroup> self_candidate_weak = *it_IsGroupedBy_inverse;
			if( self_candidate_weak.expired() )
			{
				++it_IsGroupedBy_inverse;
				continue;
			}
			shared_ptr<IfcRelAssignsToGroup> self_candidate( *it_IsGroupedBy_inverse );
			if( self_candidate.get() == this )
			{
				it_IsGroupedBy_inverse= IsGroupedBy_inverse.erase( it_IsGroupedBy_inverse );
			}
			else
			{
				++it_IsGroupedBy_inverse;
			}
		}
	}
}
