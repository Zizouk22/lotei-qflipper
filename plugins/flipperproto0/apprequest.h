#pragma once

#include "mainrequest.h"

// App.StartRequest -- launches an application on the Flipper by name (a built-in
// like "Sub-GHz"/"NFC" or a .fap path), with optional args. Mirrors the storage
// requests: the name/args char* fields point at member QByteArrays kept alive for
// the lifetime of the request object (encode() is called before it's destroyed).
class AppStartRequest : public MainRequest
{
public:
    AppStartRequest(uint32_t id, const QByteArray &name, const QByteArray &args);

private:
    QByteArray m_name;
    QByteArray m_args;
};
