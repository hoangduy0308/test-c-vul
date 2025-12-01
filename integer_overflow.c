#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void vulnerable_function(size_t num_elements) {
    // Giả sử mỗi phần tử kích thước 4 bytes (ví dụ: int)
    size_t element_size = sizeof(int);
    
    // LỖ HỔNG: Integer Overflow
    // Nếu num_elements đủ lớn, phép nhân này sẽ bị tràn số (wrap around)
    // Ví dụ: Trên hệ thống 32-bit, nếu num_elements = (2^32 / 4) + 1
    // Kết quả sẽ là 4 bytes thay vì kích thước thực tế rất lớn.
    size_t total_size = num_elements * element_size;

    printf("Yêu cầu cấp phát: %zu phần tử\n", num_elements);
    printf("Kích thước tính toán (có thể bị tràn): %zu bytes\n", total_size);

    // Cấp phát bộ nhớ dựa trên kích thước đã bị tràn (nhỏ hơn thực tế)
    int *buffer = (int *)malloc(total_size);
    
    if (buffer == NULL) {
        printf("Không thể cấp phát bộ nhớ!\n");
        return;
    }

    // Ghi dữ liệu vào buffer
    // Vòng lặp chạy theo num_elements (số lượng lớn)
    // Nhưng buffer chỉ được cấp phát total_size (kích thước nhỏ do tràn)
    // -> Gây ra Heap Buffer Overflow
    printf("Bắt đầu ghi dữ liệu...\n");
    for (size_t i = 0; i < num_elements; i++) {
        // Dòng này sẽ crash chương trình khi i vượt quá kích thước thật của buffer
        buffer[i] = 0x41414141; 
    }

    printf("Đã ghi xong (nếu bạn thấy dòng này thì không bị crash).\n");
    free(buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Sử dụng: %s <số lượng phần tử>\n", argv[0]);
        
        // Demo giá trị gây tràn
        // SIZE_MAX là giá trị lớn nhất của size_t.
        // Để gây tràn: (SIZE_MAX / 4) + 2
        size_t overflow_trigger = (SIZE_MAX / sizeof(int)) + 2;
        
        printf("\nĐang chạy demo với giá trị gây tràn Integer Overflow...\n");
        printf("Giá trị đầu vào: %zu\n", overflow_trigger);
        vulnerable_function(overflow_trigger);
    } else {
        // Chuyển đổi tham số dòng lệnh thành số
        size_t num = strtoull(argv[1], NULL, 10);
        vulnerable_function(num);
    }

    return 0;
}
