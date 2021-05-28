#ifndef HOLLEYVARIABLESV6_H
#define HOLLEYVARIABLESV6_H

    Q_PROPERTY(float RTC                    READ RTC                NOTIFY onHolleyDataChanged) const float& RTC()                  {unsigned int i = 0; registerFilter(i); return m_data[i];}

#endif // HOLLEYVARIABLESV6_H
