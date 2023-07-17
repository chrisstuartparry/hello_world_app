//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "HelloWorldAppTestApp.h"
#include "HelloWorldAppApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
HelloWorldAppTestApp::validParams()
{
  InputParameters params = HelloWorldAppApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

HelloWorldAppTestApp::HelloWorldAppTestApp(InputParameters parameters) : MooseApp(parameters)
{
  HelloWorldAppTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

HelloWorldAppTestApp::~HelloWorldAppTestApp() {}

void
HelloWorldAppTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  HelloWorldAppApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"HelloWorldAppTestApp"});
    Registry::registerActionsTo(af, {"HelloWorldAppTestApp"});
  }
}

void
HelloWorldAppTestApp::registerApps()
{
  registerApp(HelloWorldAppApp);
  registerApp(HelloWorldAppTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
HelloWorldAppTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  HelloWorldAppTestApp::registerAll(f, af, s);
}
extern "C" void
HelloWorldAppTestApp__registerApps()
{
  HelloWorldAppTestApp::registerApps();
}
