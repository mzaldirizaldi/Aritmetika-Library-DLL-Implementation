from ctypes import *

lib = CDLL(r"D:\PU Docs\Intenrship September - December 2022\Magang SAS Rizaldi\Minggu ke-1 September\9 September 2022\aritmetika python dll\aritmetika.dll")


dargs = c_double, c_double
dres = c_double
iargs = c_int, c_int
ires = c_int

lib.tambah.argtypes = dargs
lib.tambah.restype = dres
lib.kurang.argtypes = dargs
lib.kurang.restype = dres
lib.kali.argtypes = dargs
lib.kali.restype = dres
lib.bagi.argtypes = dargs
lib.bagi.restype = dres
lib.bagi_integer.argtypes = iargs
lib.bagi_integer.restype = ires
lib.sisabagi.argtypes = iargs
lib.sisabagi.restype = ires

a = 10.25; b = 0.25; c = 20; d = 3

print(a, " + ", b, " = ", lib.tambah(a, b))
print(a, " - ", b, " = ", lib.kurang(a, b))
print(a, " * ", b, " = ", lib.kali(a, b))
print(a, " / ", b, " = ", lib.bagi(a, b))
print(c, " / ", d, " = ", lib.bagi_integer(c, d))
print(c, " % ", d, " = ", lib.sisabagi(c, d))