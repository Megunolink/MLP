#pragma once
#include "MegunoLinkProtocol.h"

class Table : public MegunoLinkProtocol
{
public:
  Table(Print& rDestination = Serial);
  Table(const char* Channel, Print& rDestination = Serial);
  Table(const __FlashStringHelper* Channel, Print& rDestination = Serial);

  template<typename TRowName, typename TValue>
  void SendData(TRowName RowName, TValue Value)
  {
    SendHeader();
    SendPairs(RowName, Value);
    SendDataTail();
  }

  template<typename TRowName, typename TValue, typename... Args>
  void SendData(TRowName RowName, TValue Value, Args... args)
  {
    SendHeader();
    SendPairs(RowName, Value, args...);
    SendDataTail();
  }

  template<typename TRowName, typename TValue, typename TDescription>
  void SendData(TRowName RowName, TValue Value, TDescription Description)
  {
    SendHeader();
    SendPairs(RowName, Value);
    m_rDestination.print('|');
    m_rDestination.print(Description);
    SendDataTail();
  }

  template<typename TRowName>
  void SendData(TRowName RowName, float Value, int DecimalPlaces)
  {
    SendFloatData(RowName, Value, DecimalPlaces);
  }

  template<typename TRowName, typename TDescription>
  void SendData(TRowName RowName, float Value, int DecimalPlaces, TDescription Description)
  {
    SendFloatData(RowName, Value, DecimalPlaces, Description);
  }

  template<typename TRowName>
  void SendFloatData(TRowName RowName, float Value, int DecimalPlaces)
  {
    SendHeader();
    SendPairs(RowName, Value, DecimalPlaces);
    SendDataTail();
  }

  template<typename TRowName, typename TDescription>
  void SendFloatData(TRowName RowName, float Value, int DecimalPlaces, TDescription Description)
  {
    SendHeader();
    SendPairs(RowName, Value, DecimalPlaces);
    m_rDestination.print('|');
    m_rDestination.print(Description);
    SendDataTail();
  }

  template<typename TRowName>
  void SendData(TRowName RowName, double Value, int DecimalPlaces)
  {
    SendDoubleData(RowName, Value, DecimalPlaces);
  }

  template<typename TRowName, typename TDescription>
  void SendData(TRowName RowName, double Value, int DecimalPlaces, TDescription Description)
  {
    SendDoubleData(RowName, Value, DecimalPlaces, Description);
  }

  template<typename TRowName>
  void SendDoubleData(TRowName RowName, double Value, int DecimalPlaces)
  {
    SendHeader();
    SendPairs(RowName, Value, DecimalPlaces);
    SendDataTail();
  }

  template<typename TRowName, typename TDescription>
  void SendDoubleData(TRowName RowName, double Value, int DecimalPlaces, TDescription Description)
  {
    SendHeader();
    SendPairs(RowName, Value, DecimalPlaces);
    m_rDestination.print('|');
    m_rDestination.print(Description);
    SendDataTail();
  }

  template<typename TRowName>
  void ShowCurrentTime(TRowName RowName)
  {
    SendHeader();
    SendPairs(RowName, SpecialParameters::CurrentTime);
    SendDataTail();
  }

  template<typename TRowName, typename TDescription>
  void SetDescription(TRowName RowName, TDescription Description)
  {
    SendDataHeader(F("D"));
    m_rDestination.print(RowName);
    m_rDestination.print('|');
    m_rDestination.print(Description);
    SendDataTail();
  }

  void ClearAllRows();

  template<typename TRowName>
  void ClearRow(TRowName RowName)
  {
    SendDataHeader(F("CLR"));
    m_rDestination.print(RowName);
    SendDataTail();
  }

  template<typename TRowName>
  void GetData(TRowName RowName)
  {
    SendDataHeader(F("G"));
    m_rDestination.print(RowName);
    SendDataTail();
  }

private:

  void SendHeader()
  {
    SendDataHeader(F("S"), false);
  }

  template<typename TRowName>
  void SendPairs(TRowName RowName, float Value, int DecimalPlaces)
  {
    m_rDestination.print('|');
    m_rDestination.print(RowName);
    m_rDestination.print('|');
    m_rDestination.print(Value, DecimalPlaces);
  }

  template<typename TRowName>
  void SendPairs(TRowName RowName, double Value, int DecimalPlaces)
  {
    m_rDestination.print('|');
    m_rDestination.print(RowName);
    m_rDestination.print('|');
    m_rDestination.print(Value, DecimalPlaces);
  }

  template<typename TRowName, typename TValue>
  void SendPairs(TRowName RowName, TValue Value)
  {
    m_rDestination.print('|');
    m_rDestination.print(RowName);
    m_rDestination.print('|');
    m_rDestination.print(Value);
  }

  template<typename TRowName>
  void SendPairs(TRowName RowName, SpecialParameters Value)
  {
    m_rDestination.print('|');
    m_rDestination.print(RowName);
    m_rDestination.print('|');
    SendValue(Value);
  }

  template<typename TRowName, typename TValue, typename... Args>
  void SendPairs(TRowName RowName, TValue Value, Args... args)
  {
    SendPairs(RowName, Value);
    SendPairs(args...);
  }


};

