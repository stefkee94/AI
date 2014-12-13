#include "Cow.h"
#include <qdir.h>

Cow::Cow()
{
	img_link = QDir::currentPath().append("/Resources/lemmling_Cartoon_cow.png");
	behavior = new CowChasingState(std::shared_ptr<BaseUnit>(this));
}

Cow::~Cow()
{

}

void Cow::SetVertex(std::shared_ptr<Vertex> p_vertex)
{
	vertex = p_vertex;
}

std::shared_ptr<Vertex> Cow::GetVertex()
{
	return vertex;
}

QString Cow::GetImageLink()
{
	return img_link;
}

std::vector<std::shared_ptr<Vertex>> Cow::Move()
{
	// Send behavior to state
	behavior->CheckState();
	return behavior->Move();
}

void Cow::Update(Controller* controller)
{
	behavior->Update(controller);
}

std::string Cow::GetAction()
{
	return behavior->GetAction();
}

EnumState Cow::GetState()
{
	return currentState;
}

void Cow::SetPil(bool contains_pill)
{
	pill = contains_pill;
}

bool Cow::GetPil()
{
	return pill;
}
