#ifndef __HPYTHON_CONNECTOR_H__
#define __HPYTHON_CONNECTOR_H__

void register_hPyFramework();
namespace hPyFramework
{
void pyRegister() { ::register_hPyFramework(); }
}

#endif
