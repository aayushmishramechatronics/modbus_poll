```
pip install pymodbus
```

from pymodbus.server import StartTcpServer #for starting the tcp/ip server
from pymodbus.datastore import (
    ModbusSequentialDataBlock,
    ModbusSlaveContext,
    ModbusServerContext,
)

#holding registers (40001 onwards)
store = ModbusSlaveContext(
    hr=ModbusSequentialDataBlock(0, [100, 200, 300, 400, 500])
)

context = ModbusServerContext(slaves=store, single=True)
print("starting modbus TCP server on port 5020...")
StartTcpServer(
    context=context,
    address=("0.0.0.0", 5020)
)
