from sys import stdin
from functools import reduce

# Подсчёт занятых мест в автобусе
def busweight(bus):
  if bus == []:
    return 0
  else:
    return reduce(lambda x,y: x+y, bus)

# Подсчёт людей на остановке
def busstopweight(busstop):
  if busstop == []:
    return 0
  else:
    return reduce(lambda x,y: x+y, busstop)

# Посадка людей в автобус с остановки
def busload(bus, buscapacity, busstop):
  destination = 0
  while busweight(bus) < buscapacity and busstopweight(busstop) != 0:
    if busstop[destination] != 0:
      bus.insert(destination, bus[destination]+1)
      del bus[destination+1]
      busstop.insert(destination, busstop[destination]-1)
      del busstop[destination+1]
    destination = destination + 1
    if destination == len(busstop):
      destination = 0
  return [bus, busstop]

# Прогон автобуса по маршруту
# busroute - маршрут
# buscapacity - количество мест в автобусе
# iters - количество поездок автобуса по маршруту
def testbus(busroute, buscapacity, iters):
  carriedpeople = 0
  for i in range(0, iters):
    bus = [0]*len(busroute[0])
    for j in range(0, len(busroute)):
      tmp = busload(bus, buscapacity, busroute[j])
      bus = tmp[0]
      busroute[j] = tmp[1]
      carriedpeople += bus[0]
      del bus[0]
  return carriedpeople

# Вычисление оптимального количества автобусов на маршруте
# busroute - маршрут автобуса
# buscapacity - вместимость автобуса
# busoutgo - дневные затраты на один автобус
# ticketprice - стоимость одного билета
# routetime - продолжительность поездки автобуса по всему маршруту
def howmuchbuses(busroute, buscapacity, busoutgo, ticketprice, routetime):
  expandedroute = list(map(lambda lst: list(map(lambda x: x*1440, lst)),
  busroute))
  totaltrips = round(1440/routetime)
  buscount = 1
  totalpeople = reduce(lambda x,y: x+y, list(map(lambda lst: reduce(lambda x,y: 
  	x+y, lst), expandedroute)))
  while True:
    tmp = list(map(lambda lst: list(map(lambda x: x*1440, lst)), busroute))
    carriedpeople = testbus(tmp, buscapacity*buscount, totaltrips)
    profit = carriedpeople*ticketprice-busoutgo*buscount
    print("Bus count: ", buscount)
    print("Carried people: ", carriedpeople, ", total people: ", totalpeople)
    print("Profit: ", profit)
    buscount += 1
    if profit < 0 or carriedpeople == totalpeople:
      break

howmuchbuses([[10, 20], [3]], 60, 20000, 25, 15)
