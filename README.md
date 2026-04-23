RFC 9213 Uyumlu Modüler API Gateway İstek Zamanlayıcısı

Bu proje, HTTP isteklerinin önceliklerine göre sıralanmasını sağlayan Min-Heap tabanlı bir Priority Queue sistemidir. RFC 9213 standardına uygun olarak gelen isteklerin priority değerleri parse edilerek işlenir ve en yüksek öncelikli istekler önce çalıştırılır.

Sistem C dili ile modüler bir yapıda geliştirilmiştir ve aşağıdaki bileşenlerden oluşur:
- Parser (RFC 9213 priority parsing)
- Min-Heap Priority Queue (O(log n) insert / extract)
- Scheduler (istek yönetimi)
- Main (test ve çalıştırma katmanı)

Proje, gerçek dünya API Gateway mantığını simüle ederek yüksek trafikli sistemlerde istek önceliklendirme problemini çözmeyi amaçlamaktadır.

Özellikler:
- Min-Heap tabanlı priority scheduling
- RFC 9213 uyumlu request parsing
- Dinamik bellek yönetimi (malloc, realloc, free)
- Modüler C mimarisi (.h / .c ayrımı)
- O(log n) verimli işlem yapısı

Kullanılan Teknolojiler:
- C (GCC Compiler)
- Data Structures (Min-Heap)
- Dynamic Memory Management

Derleme:
gcc main.c heap.c parser.c scheduler.c -o app

Çalıştırma:
./app
