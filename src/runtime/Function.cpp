#include "Function.h"

Function::Function(const Function& f) : name(f.name), parameters(f.parameters) {
	this->body = f.body;  // Ϊ body ָ�봴���µ� ASTNode ���󸱱�
	this->callback = f.callback;  // Ϊ callback ָ�봴���µ� FunctionCallBack ���󸱱�
}
Function::Function(String name, List<String> parameters, ASTNode* body, FunctionCallBack* callback) {
	this->name = name;
	this->parameters = parameters;
	this->body = body;
	this->callback = callback;
}
String Function::getName() {
	return name;
}
List<String> Function::getParameters() {
	return parameters;
}
ASTNode* Function::getBody() {
	return body;
}
Object Function::call(List<Object> arguments, Interpreter* interpreter) {
	Scope* functionScope = new Scope(interpreter->getScope());
	for (int i = 0; i < parameters.size();i++) {
		Object obj = parameters[i];
		functionScope->defineVariable(std::any_cast<String>(obj), new Variable(std::any_cast<String>(obj), "unknown", arguments[i]));
	}
	if (callback != nullptr) return callback->execute(arguments);
	return interpreter->evaluate(body);
}
Object Function::execute(List<Object> arguments) {
	return callback->execute(arguments);
}
