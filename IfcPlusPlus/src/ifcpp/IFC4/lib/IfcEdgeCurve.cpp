/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcBoolean.h"
#include "ifcpp/IFC4/include/IfcCurve.h"
#include "ifcpp/IFC4/include/IfcEdgeCurve.h"
#include "ifcpp/IFC4/include/IfcPresentationLayerAssignment.h"
#include "ifcpp/IFC4/include/IfcStyledItem.h"
#include "ifcpp/IFC4/include/IfcVertex.h"

// ENTITY IfcEdgeCurve 
IfcEdgeCurve::IfcEdgeCurve() {}
IfcEdgeCurve::IfcEdgeCurve( int id ) { m_entity_id = id; }
IfcEdgeCurve::~IfcEdgeCurve() {}
shared_ptr<BuildingObject> IfcEdgeCurve::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcEdgeCurve> copy_self( new IfcEdgeCurve() );
	if( m_EdgeStart ) { copy_self->m_EdgeStart = dynamic_pointer_cast<IfcVertex>( m_EdgeStart->getDeepCopy(options) ); }
	if( m_EdgeEnd ) { copy_self->m_EdgeEnd = dynamic_pointer_cast<IfcVertex>( m_EdgeEnd->getDeepCopy(options) ); }
	if( m_EdgeGeometry ) { copy_self->m_EdgeGeometry = dynamic_pointer_cast<IfcCurve>( m_EdgeGeometry->getDeepCopy(options) ); }
	if( m_SameSense ) { copy_self->m_SameSense = dynamic_pointer_cast<IfcBoolean>( m_SameSense->getDeepCopy(options) ); }
	return copy_self;
}
void IfcEdgeCurve::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_entity_id << "= IFCEDGECURVE" << "(";
	if( m_EdgeStart ) { stream << "#" << m_EdgeStart->m_entity_id; } else { stream << "$"; }
	stream << ",";
	if( m_EdgeEnd ) { stream << "#" << m_EdgeEnd->m_entity_id; } else { stream << "$"; }
	stream << ",";
	if( m_EdgeGeometry ) { stream << "#" << m_EdgeGeometry->m_entity_id; } else { stream << "$"; }
	stream << ",";
	if( m_SameSense ) { m_SameSense->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IfcEdgeCurve::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_entity_id; }
const std::wstring IfcEdgeCurve::toString() const { return L"IfcEdgeCurve"; }
void IfcEdgeCurve::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<BuildingEntity> >& map )
{
	const size_t num_args = args.size();
	if( num_args != 4 ){ std::stringstream err; err << "Wrong parameter count for entity IfcEdgeCurve, expecting 4, having " << num_args << ". Entity ID: " << m_entity_id << std::endl; throw BuildingException( err.str().c_str() ); }
	readEntityReference( args[0], m_EdgeStart, map );
	readEntityReference( args[1], m_EdgeEnd, map );
	readEntityReference( args[2], m_EdgeGeometry, map );
	m_SameSense = IfcBoolean::createObjectFromSTEP( args[3], map );
}
void IfcEdgeCurve::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes )
{
	IfcEdge::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "EdgeGeometry", m_EdgeGeometry ) );
	vec_attributes.push_back( std::make_pair( "SameSense", m_SameSense ) );
}
void IfcEdgeCurve::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse )
{
	IfcEdge::getAttributesInverse( vec_attributes_inverse );
}
void IfcEdgeCurve::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcEdge::setInverseCounterparts( ptr_self_entity );
}
void IfcEdgeCurve::unlinkFromInverseCounterparts()
{
	IfcEdge::unlinkFromInverseCounterparts();
}
