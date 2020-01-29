# Hanoi-Towers


Oyunun Amacı  
Başlangıçta 3 tane direk var ve birinci direkteki tüm diskler küçükten büyüğe doğru sıralanmış durumdadır. Oyunun amacı birinci direkteki diskleri başka direğe kurallara uygun ve minimum hareket sayısıyla taşımaktır. Disk sayısı arttıkça minimum hamle sayısı da artar. Oyunun belli kuralları vardır.
1- Her defasında sadece bir disk taşınmalıdır.
2- Herhangi bir disk kendinden küçük diskin üstüne konulamaz.
Oyunun minimum adım sayısının formülü => 2^n-1 (n disk sayısı olmak üzere) olarak gösterilmektedir.

Stack Veri Yapısı
Sadece tek yönden hareketi olan diziye Stack(yığıt) denir. Stack veri yapısında ilk giren veri en son çıkar.(First in Last out) Stack veri yapısının belli komutları vardır.
Push () : Yığıta eleman ekleme
Pop () : Yığıttan eleman çekme
isEmpty () : Yığıtın boş olup olmadığını kontrol eder.
Top () : Yığıtın en tepesindeki bilgiyi alır ancak yığıttan çıkartmaz sadece okur.

Programın Amacı
C++ dilinde uygun bir veri yapısı(stack) kullanarak, efektif bir biçimde Hanoi Kulelerinin en az hamle sayısında çözümünü bulmak.
Neden Stack Veri Yapısı?
Oyunun kurallarından, sadece en üstteki elemanı kullanabildiğimiz için buna en uygun veri yapısı stacktir. (Last in First out)

