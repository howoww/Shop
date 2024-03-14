#include "AuthorizationService.h"


bool AuthorizationService::registerUser(User user)
{
	user.setIsAdmin(true);
	if (!_model.ContainsLogin(user.getLogin()))
	{
		_model.addItem(user);
		return true;
	}
	else
		return false;
}

User* AuthorizationService::authorizeUser(std::string login, std::string password)
{
	return  _model.getUserForAuth(login, password);
}

