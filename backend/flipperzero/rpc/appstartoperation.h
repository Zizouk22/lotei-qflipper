#pragma once

#include "abstractprotobufoperation.h"

namespace Flipper {
namespace Zero {

// Launches an app on the Flipper via App.StartRequest. The device replies with an
// empty OK (or an error), so the default AbstractProtobufOperation completion path
// applies -- no special response handling needed.
class AppStartOperation : public AbstractProtobufOperation
{
    Q_OBJECT

public:
    AppStartOperation(uint32_t id, const QByteArray &name, const QByteArray &args, QObject *parent = nullptr);

    const QString description() const override;
    const QByteArray encodeRequest(ProtobufPluginInterface *encoder) override;

private:
    QByteArray m_name;
    QByteArray m_args;
};

}
}
