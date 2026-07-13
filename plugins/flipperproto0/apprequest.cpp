#include "apprequest.h"

AppStartRequest::AppStartRequest(uint32_t id, const QByteArray &name, const QByteArray &args):
    MainRequest(id, PB_Main_app_start_request_tag),
    m_name(name),
    m_args(args)
{
    m_message.content.app_start_request.name = m_name.data();
    m_message.content.app_start_request.args = m_args.isEmpty() ? nullptr : m_args.data();
}
