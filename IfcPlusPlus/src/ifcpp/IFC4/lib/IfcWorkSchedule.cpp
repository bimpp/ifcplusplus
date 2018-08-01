/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcDateTime.h"
#include "ifcpp/IFC4/include/IfcDuration.h"
#include "ifcpp/IFC4/include/IfcGloballyUniqueId.h"
#include "ifcpp/IFC4/include/IfcIdentifier.h"
#include "ifcpp/IFC4/include/IfcLabel.h"
#include "ifcpp/IFC4/include/IfcOwnerHistory.h"
#include "ifcpp/IFC4/include/IfcPerson.h"
#include "ifcpp/IFC4/include/IfcRelAggregates.h"
#include "ifcpp/IFC4/include/IfcRelAssigns.h"
#include "ifcpp/IFC4/include/IfcRelAssignsToControl.h"
#include "ifcpp/IFC4/include/IfcRelAssociates.h"
#include "ifcpp/IFC4/include/IfcRelDeclares.h"
#include "ifcpp/IFC4/include/IfcRelDefinesByObject.h"
#include "ifcpp/IFC4/include/IfcRelDefinesByProperties.h"
#include "ifcpp/IFC4/include/IfcRelDefinesByType.h"
#include "ifcpp/IFC4/include/IfcRelNests.h"
#include "ifcpp/IFC4/include/IfcText.h"
#include "ifcpp/IFC4/include/IfcWorkSchedule.h"
#include "ifcpp/IFC4/include/IfcWorkScheduleTypeEnum.h"

// ENTITY IfcWorkSchedule 
IfcWorkSchedule::IfcWorkSchedule() {}
IfcWorkSchedule::IfcWorkSchedule( int id ) { m_entity_id = id; }
IfcWorkSchedule::~IfcWorkSchedule() {}
shared_ptr<BuildingObject> IfcWorkSchedule::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcWorkSchedule> copy_self( new IfcWorkSchedule() );
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
	if( m_ObjectType ) { copy_self->m_ObjectType = dynamic_pointer_cast<IfcLabel>( m_ObjectType->getDeepCopy(options) ); }
	if( m_Identification ) { copy_self->m_Identification = dynamic_pointer_cast<IfcIdentifier>( m_Identification->getDeepCopy(options) ); }
	if( m_CreationDate ) { copy_self->m_CreationDate = dynamic_pointer_cast<IfcDateTime>( m_CreationDate->getDeepCopy(options) ); }
	for( size_t ii=0; ii<m_Creators.size(); ++ii )
	{
		auto item_ii = m_Creators[ii];
		if( item_ii )
		{
			copy_self->m_Creators.push_back( dynamic_pointer_cast<IfcPerson>(item_ii->getDeepCopy(options) ) );
		}
	}
	if( m_Purpose ) { copy_self->m_Purpose = dynamic_pointer_cast<IfcLabel>( m_Purpose->getDeepCopy(options) ); }
	if( m_Duration ) { copy_self->m_Duration = dynamic_pointer_cast<IfcDuration>( m_Duration->getDeepCopy(options) ); }
	if( m_TotalFloat ) { copy_self->m_TotalFloat = dynamic_pointer_cast<IfcDuration>( m_TotalFloat->getDeepCopy(options) ); }
	if( m_StartTime ) { copy_self->m_StartTime = dynamic_pointer_cast<IfcDateTime>( m_StartTime->getDeepCopy(options) ); }
	if( m_FinishTime ) { copy_self->m_FinishTime = dynamic_pointer_cast<IfcDateTime>( m_FinishTime->getDeepCopy(options) ); }
	if( m_PredefinedType ) { copy_self->m_PredefinedType = dynamic_pointer_cast<IfcWorkScheduleTypeEnum>( m_PredefinedType->getDeepCopy(options) ); }
	return copy_self;
}
void IfcWorkSchedule::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_entity_id << "= IFCWORKSCHEDULE" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_entity_id; } else { stream << "$"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_ObjectType ) { m_ObjectType->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Identification ) { m_Identification->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_CreationDate ) { m_CreationDate->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	writeEntityList( stream, m_Creators );
	stream << ",";
	if( m_Purpose ) { m_Purpose->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Duration ) { m_Duration->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_TotalFloat ) { m_TotalFloat->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_StartTime ) { m_StartTime->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_FinishTime ) { m_FinishTime->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_PredefinedType ) { m_PredefinedType->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IfcWorkSchedule::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_entity_id; }
const std::wstring IfcWorkSchedule::toString() const { return L"IfcWorkSchedule"; }
void IfcWorkSchedule::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<BuildingEntity> >& map )
{
	const size_t num_args = args.size();
	if( num_args != 14 ){ std::stringstream err; err << "Wrong parameter count for entity IfcWorkSchedule, expecting 14, having " << num_args << ". Entity ID: " << m_entity_id << std::endl; throw BuildingException( err.str().c_str() ); }
	m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0], map );
	readEntityReference( args[1], m_OwnerHistory, map );
	m_Name = IfcLabel::createObjectFromSTEP( args[2], map );
	m_Description = IfcText::createObjectFromSTEP( args[3], map );
	m_ObjectType = IfcLabel::createObjectFromSTEP( args[4], map );
	m_Identification = IfcIdentifier::createObjectFromSTEP( args[5], map );
	m_CreationDate = IfcDateTime::createObjectFromSTEP( args[6], map );
	readEntityReferenceList( args[7], m_Creators, map );
	m_Purpose = IfcLabel::createObjectFromSTEP( args[8], map );
	m_Duration = IfcDuration::createObjectFromSTEP( args[9], map );
	m_TotalFloat = IfcDuration::createObjectFromSTEP( args[10], map );
	m_StartTime = IfcDateTime::createObjectFromSTEP( args[11], map );
	m_FinishTime = IfcDateTime::createObjectFromSTEP( args[12], map );
	m_PredefinedType = IfcWorkScheduleTypeEnum::createObjectFromSTEP( args[13], map );
}
void IfcWorkSchedule::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes )
{
	IfcWorkControl::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "PredefinedType", m_PredefinedType ) );
}
void IfcWorkSchedule::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse )
{
	IfcWorkControl::getAttributesInverse( vec_attributes_inverse );
}
void IfcWorkSchedule::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcWorkControl::setInverseCounterparts( ptr_self_entity );
}
void IfcWorkSchedule::unlinkFromInverseCounterparts()
{
	IfcWorkControl::unlinkFromInverseCounterparts();
}
