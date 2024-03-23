#include "AuthorizationService.h"


AuthorizationService::AuthorizationService(UserRepository& userRepository): _model(userRepository)
{
}

bool AuthorizationService::registerUser(User user)
{
	user.setIsAdmin(false);
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

