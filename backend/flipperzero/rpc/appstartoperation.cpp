#include "appstartoperation.h"

#include "protobufplugininterface.h"

using namespace Flipper;
using namespace Zero;

AppStartOperation::AppStartOperation(uint32_t id, const QByteArray &name, const QByteArray &args, QObject *parent):
    AbstractProtobufOperation(id, parent),
    m_name(name),
    m_args(args)
{}

const QString AppStartOperation::description() const
{
    return QStringLiteral("App Start @%1").arg(QString::fromUtf8(m_name));
}

const QByteArray AppStartOperation::encodeRequest(ProtobufPluginInterface *encoder)
{
    return encoder->appStart(id(), m_name, m_args);
}
