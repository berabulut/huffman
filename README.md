# Sistem Programlama Proje Ödevi

Aşağıdaki gibi bir .kilit dosyası okur.

```
{
  "abc": "0",
  "cde": "10",
  "efg": "110",
}
```

Örnek metinde key'ler varsa karşısındaki kodu encripted dosyasına sıralı bir şekilde yazar.

Şifreli metini de çözer.

#### Örnek

**ornek_metin** :
	
	cde efg abc abc efg abc 


*$ kripto -e ornek_metin encripted*

**encripted** :

	10 110 0 0 110 0 

*$ kripto -d encripted decripted*

**decripted** :

	cde efg abc abc efg abc

### Üyeler

- Hüseyin Bera Bulut : Proje sorumlusu
- Mert Erdoğan Apa : JSON formatında kilit dosyasını okuma 
- Ertuğrul Sırma : Şifreleme ve şifre çözme işlemleri
- Muhammed Mustafa Çelik : Deployment sorumlusu

### Proje Yapılış Aşamaları:
Derleme sürecimizde prototip bir makefile üretip,ürettiğimiz makefile 
ile işimize başladık,proje yöneticimiz olan Hüseyin Bulut ile 
projedeki diğer üyemiz olan Mert Apa bir araya gelip kilit dosya okuma
işlemlerimizi hallettikten sonra Ertuğrul Sırma ile encode decode işlemimizi yaptık.Sonrasında Mustafa Çelik adlı üyemiz prototip makefile'ımızı öğretmenimizin istediği gibi bir makefile'a güncelledi.

### Nasıl Çalıştırılır

- make: projeyi derler ve kripto isimli çalıştırılabilir dosyayı oluşturur.
	+ clean: derleme esnasında oluşan tüm dosyaları siler(*.o, kripto, vb)
	+ cleanall: derleme sırasında olşan dosyaların yanı sıra (.kilit, encripted, decripted,
	ornek_metin, *txt isimli dosyalar var ise hepsini siler.)
	+ run: clean ile temizler make ile derler ve iki komutuda (-e,- d) sırasıyla çalıştırarak
	(ornek_metin ) encripted ve decripted dosyaları üretir. (bu tam bir ödev içindir tam olmayan
	ödev yapabildiği yere kadar bu görevi gerçekleştirir).


```
$ kripto -e ornek_metin encripted
$ kripto -d encripted   decripted
```