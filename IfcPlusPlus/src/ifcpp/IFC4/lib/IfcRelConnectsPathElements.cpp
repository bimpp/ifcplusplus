/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcConnectionGeometry.h"
#include "ifcpp/IFC4/include/IfcConnectionTypeEnum.h"
#include "ifcpp/IFC4/include/IfcElement.h"
#include "ifcpp/IFC4/include/IfcGloballyUniqueId.h"
#include "ifcpp/IFC4/include/IfcInteger.h"
#include "ifcpp/IFC4/include/IfcLabel.h"
#include "ifcpp/IFC4/include/IfcOwnerHistory.h"
#include "ifcpp/IFC4/include/IfcRelConnectsPathElements.h"
#include "ifcpp/IFC4/include/IfcText.h"

// ENTITY IfcRelConnectsPathElements 
IfcRelConnectsPathElements::IfcRelConnectsPathElements() {}
IfcRelConnectsPathElements::IfcRelConnectsPathElements( int id ) { m_entity_id = id; }
IfcRelConnectsPathElements::~IfcRelConnectsPathElements() {}
shared_ptr<BuildingObject> IfcRelConnectsPathElements::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcRelConnectsPathElements> copy_self( new IfcRelConnectsPathElements() );
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
	if( m_ConnectionGeometry ) { copy_self->m_ConnectionGeometry = dynamic_pointer_cast<IfcConnectionGeometry>( m_ConnectionGeometry->getDeepCopy(options) ); }
	if( m_RelatingElement ) { copy_self->m_RelatingElement = dynamic_pointer_cast<IfcElement>( m_RelatingElement->getDeepCopy(options) ); }
	if( m_RelatedElement ) { copy_self->m_RelatedElement = dynamic_pointer_cast<IfcElement>( m_RelatedElement->getDeepCopy(options) ); }
	for( size_t ii=0; ii<m_RelatingPriorities.size(); ++ii )
	{
		auto item_ii = m_RelatingPriorities[ii];
		if( item_ii )
		{
			copy_self->m_RelatingPriorities.push_back( dynamic_pointer_cast<IfcInteger>(item_ii->getDeepCopy(options) ) );
		}
	}
	for( size_t ii=0; ii<m_RelatedPriorities.size(); ++ii )
	{
		auto item_ii = m_RelatedPriorities[ii];
		if( item_ii )
		{
			copy_self->m_RelatedPriorities.push_back( dynamic_pointer_cast<IfcInteger>(item_ii->getDeepCopy(options) ) );
		}
	}
	if( m_RelatedConnectionType ) { copy_self->m_RelatedConnectionType = dynamic_pointer_cast<IfcConnectionTypeEnum>( m_RelatedConnectionType->getDeepCopy(options) ); }
	if( m_RelatingConnectionType ) { copy_self->m_RelatingConnectionType = dynamic_pointer_cast<IfcConnectionTypeEnum>( m_RelatingConnectionType->getDeepCopy(options) ); }
	return copy_self;
}
void IfcRelConnectsPathElements::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_entity_id << "= IFCRELCONNECTSPATHELEMENTS" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_entity_id; } else { stream << "$"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_ConnectionGeometry ) { stream << "#" << m_ConnectionGeometry->m_entity_id; } else { stream << "$"; }
	stream << ",";
	if( m_RelatingElement ) { stream << "#" << m_RelatingElement->m_entity_id; } else { stream << "$"; }
	stream << ",";
	if( m_RelatedElement ) { stream << "#" << m_RelatedElement->m_entity_id; } else { stream << "$"; }
	stream << ",";
	writeNumericTypeList( stream, m_RelatingPriorities );
	stream << ",";
	writeNumericTypeList( stream, m_RelatedPriorities );
	stream << ",";
	if( m_RelatedConnectionType ) { m_RelatedConnectionType->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_RelatingConnectionType ) { m_RelatingConnectionType->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IfcRelConnectsPathElements::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_entity_id; }
const std::wstring IfcRelConnectsPathElements::toString() const { return L"IfcRelConnectsPathElements"; }
void IfcRelConnectsPathElements::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<BuildingEntity> >& map )
{
	const size_t num_args = args.size();
	if( num_args != 11 ){ std::stringstream err; err << "Wrong parameter count for entity IfcRelConnectsPathElements, expecting 11, having " << num_args << ". Entity ID: " << m_entity_id << std::endl; throw BuildingException( err.str().c_str() ); }
	m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0], map );
	readEntityReference( args[1], m_OwnerHistory, map );
	m_Name = IfcLabel::createObjectFromSTEP( args[2], map );
	m_Description = IfcText::createObjectFromSTEP( args[3], map );
	readEntityReference( args[4], m_ConnectionGeometry, map );
	readEntityReference( args[5], m_RelatingElement, map );
	readEntityReference( args[6], m_RelatedElement, map );
	readTypeOfIntegerList( args[7], m_RelatingPriorities );
	readTypeOfIntegerList( args[8], m_RelatedPriorities );
	m_RelatedConnectionType = IfcConnectionTypeEnum::createObjectFromSTEP( args[9], map );
	m_RelatingConnectionType = IfcConnectionTypeEnum::createObjectFromSTEP( args[10], map );
}
void IfcRelConnectsPathElements::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes )
{
	IfcRelConnectsElements::getAttributes( vec_attributes );
	if( m_RelatingPriorities.size() > 0 )
	{
		shared_ptr<AttributeObjectVector> RelatingPriorities_vec_object( new AttributeObjectVector() );
		std::copy( m_RelatingPriorities.begin(), m_RelatingPriorities.end(), std::back_inserter( RelatingPriorities_vec_object->m_vec ) );
		vec_attributes.push_back( std::make_pair( "RelatingPriorities", RelatingPriorities_vec_object ) );
	}
	if( m_RelatedPriorities.size() > 0 )
	{
		shared_ptr<AttributeObjectVector> RelatedPriorities_vec_object( new AttributeObjectVector() );
		std::copy( m_RelatedPriorities.begin(), m_RelatedPriorities.end(), std::back_inserter( RelatedPriorities_vec_object->m_vec ) );
		vec_attributes.push_back( std::make_pair( "RelatedPriorities", RelatedPriorities_vec_object ) );
	}
	vec_attributes.push_back( std::make_pair( "RelatedConnectionType", m_RelatedConnectionType ) );
	vec_attributes.push_back( std::make_pair( "RelatingConnectionType", m_RelatingConnectionType ) );
}
void IfcRelConnectsPathElements::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse )
{
	IfcRelConnectsElements::getAttributesInverse( vec_attributes_inverse );
}
void IfcRelConnectsPathElements::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcRelConnectsElements::setInverseCounterparts( ptr_self_entity );
}
void IfcRelConnectsPathElements::unlinkFromInverseCounterparts()
{
	IfcRelConnectsElements::unlinkFromInverseCounterparts();
}
