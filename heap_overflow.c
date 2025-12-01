#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vulnerable_function(char *input) {
    char *heap_buffer;
    
    // Cấp phát 10 bytes trên heap
    heap_buffer = (char *)malloc(10 * sizeof(char));
    
    if (heap_buffer == NULL) {
        printf("Không thể cấp phát bộ nhớ\n");
        return;
    }

    // LỖ HỔNG: Sao chép input vào buffer mà không kiểm tra độ dài.
    // Nếu input dài hơn 9 ký tự (cộng thêm null terminator), 
    // nó sẽ ghi đè lên vùng nhớ liền kề trên heap.
    strcpy(heap_buffer, input);

    printf("Nội dung buffer: %s\n", heap_buffer);

    // Giải phóng bộ nhớ
    free(heap_buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Sử dụng: %s <chuỗi ký tự>\n", argv[0]);
        printf("Ví dụ để gây lỗi: %s AAAAAAAAAAAAAAAAAAAAAA\n", argv[0]);
        
        // Chạy demo nếu không có tham số
        printf("\nĐang chạy demo với chuỗi dài gây tràn bộ đệm...\n");
        char *long_string = "Chuoi_nay_dai_hon_10_bytes_rat_nhieu";
        vulnerable_function(long_string);
    } else {
        vulnerable_function(argv[1]);
    }

    return 0;
}
