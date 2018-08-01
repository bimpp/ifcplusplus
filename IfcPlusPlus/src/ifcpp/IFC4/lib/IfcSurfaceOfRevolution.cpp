/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcAxis1Placement.h"
#include "ifcpp/IFC4/include/IfcAxis2Placement3D.h"
#include "ifcpp/IFC4/include/IfcPresentationLayerAssignment.h"
#include "ifcpp/IFC4/include/IfcProfileDef.h"
#include "ifcpp/IFC4/include/IfcStyledItem.h"
#include "ifcpp/IFC4/include/IfcSurfaceOfRevolution.h"

// ENTITY IfcSurfaceOfRevolution 
IfcSurfaceOfRevolution::IfcSurfaceOfRevolution() {}
IfcSurfaceOfRevolution::IfcSurfaceOfRevolution( int id ) { m_entity_id = id; }
IfcSurfaceOfRevolution::~IfcSurfaceOfRevolution() {}
shared_ptr<BuildingObject> IfcSurfaceOfRevolution::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcSurfaceOfRevolution> copy_self( new IfcSurfaceOfRevolution() );
	if( m_SweptCurve )
	{
		if( options.shallow_copy_IfcProfileDef ) { copy_self->m_SweptCurve = m_SweptCurve; }
		else { copy_self->m_SweptCurve = dynamic_pointer_cast<IfcProfileDef>( m_SweptCurve->getDeepCopy(options) ); }
	}
	if( m_Position ) { copy_self->m_Position = dynamic_pointer_cast<IfcAxis2Placement3D>( m_Position->getDeepCopy(options) ); }
	if( m_AxisPosition ) { copy_self->m_AxisPosition = dynamic_pointer_cast<IfcAxis1Placement>( m_AxisPosition->getDeepCopy(options) ); }
	return copy_self;
}
void IfcSurfaceOfRevolution::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_entity_id << "= IFCSURFACEOFREVOLUTION" << "(";
	if( m_SweptCurve ) { stream << "#" << m_SweptCurve->m_entity_id; } else { stream << "$"; }
	stream << ",";
	if( m_Position ) { stream << "#" << m_Position->m_entity_id; } else { stream << "$"; }
	stream << ",";
	if( m_AxisPosition ) { stream << "#" << m_AxisPosition->m_entity_id; } else { stream << "$"; }
	stream << ");";
}
void IfcSurfaceOfRevolution::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_entity_id; }
const std::wstring IfcSurfaceOfRevolution::toString() const { return L"IfcSurfaceOfRevolution"; }
void IfcSurfaceOfRevolution::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<BuildingEntity> >& map )
{
	const size_t num_args = args.size();
	if( num_args != 3 ){ std::stringstream err; err << "Wrong parameter count for entity IfcSurfaceOfRevolution, expecting 3, having " << num_args << ". Entity ID: " << m_entity_id << std::endl; throw BuildingException( err.str().c_str() ); }
	readEntityReference( args[0], m_SweptCurve, map );
	readEntityReference( args[1], m_Position, map );
	readEntityReference( args[2], m_AxisPosition, map );
}
void IfcSurfaceOfRevolution::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes )
{
	IfcSweptSurface::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "AxisPosition", m_AxisPosition ) );
}
void IfcSurfaceOfRevolution::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse )
{
	IfcSweptSurface::getAttributesInverse( vec_attributes_inverse );
}
void IfcSurfaceOfRevolution::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcSweptSurface::setInverseCounterparts( ptr_self_entity );
}
void IfcSurfaceOfRevolution::unlinkFromInverseCounterparts()
{
	IfcSweptSurface::unlinkFromInverseCounterparts();
}
