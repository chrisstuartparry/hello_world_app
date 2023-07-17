#include "HelloWorldAppApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
HelloWorldAppApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

HelloWorldAppApp::HelloWorldAppApp(InputParameters parameters) : MooseApp(parameters)
{
  HelloWorldAppApp::registerAll(_factory, _action_factory, _syntax);
}

HelloWorldAppApp::~HelloWorldAppApp() {}

void 
HelloWorldAppApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<HelloWorldAppApp>(f, af, s);
  Registry::registerObjectsTo(f, {"HelloWorldAppApp"});
  Registry::registerActionsTo(af, {"HelloWorldAppApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
HelloWorldAppApp::registerApps()
{
  registerApp(HelloWorldAppApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
HelloWorldAppApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  HelloWorldAppApp::registerAll(f, af, s);
}
extern "C" void
HelloWorldAppApp__registerApps()
{
  HelloWorldAppApp::registerApps();
}
