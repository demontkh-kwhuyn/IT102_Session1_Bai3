#include <stdio.h>

int main() {
    int order_id;
    int subtotal;
    float distance_km;
    int booking_hour;
    int is_store_open;
    int inventory_qty;

    printf("Nhap ma don hang: ");
    scanf("%d", &order_id);

    printf("Nhap gia tri tien mon an (VND): ");
    scanf("%d", &subtotal);

    printf("Nhap khoang cach giao hang (km): ");
    scanf("%f", &distance_km);

    printf("Nhap gio dat hang (0-23): ");
    scanf("%d", &booking_hour);

    printf("Nhap trang thai quan mo cua (1: Mo, 0: Dong): ");
    scanf("%d", &is_store_open);

    printf("Nhap so luong ton kho: ");
    scanf("%d", &inventory_qty);

    int base_fee = 15000;

    int is_peak_hour = ((booking_hour >= 11 && booking_hour <= 13) || (booking_hour >= 18 && booking_hour <= 20));
    int surcharge = 10000 * is_peak_hour;

    int is_freeship_eligible = (subtotal >= 100000);
    int discount = 15000 * is_freeship_eligible;

    int is_valid_order = (is_store_open == 1) && 
                         (inventory_qty > 0) && 
                         (distance_km > 0.0f && distance_km <= 15.0f) && 
                         (booking_hour >= 0 && booking_hour <= 23) && 
                         (subtotal > 0);

    float final_delivery_fee = (base_fee + surcharge - discount) * is_valid_order;
    float total_payment = (subtotal + final_delivery_fee) * is_valid_order;

    printf("\n==================================================\n");
    printf("         SHOPEEFOOD ORDER RECEIPT REPORT          \n");
    printf("==================================================\n");
    printf("Mã đơn hàng        : %d\n", order_id);
    printf("Tiền món ăn        : %d VND\n", subtotal);
    printf("Khoảng cách giao   : %.1f km\n", distance_km);
    printf("Giờ đặt hàng       : %d:00\n", booking_hour);
    printf("Giờ cao điểm       : %s (%d)\n", (is_peak_hour == 1 ? "Có" : "Không"), is_peak_hour);
    printf("Trạng thái quán    : %s (%d)\n", (is_store_open == 1 ? "Mở cửa" : "Đóng cửa"), is_store_open);
    printf("Tồn kho            : %d\n", inventory_qty);
    printf("--------------------------------------------------\n");
    printf("Phí giao cơ bản    : %d VND\n", base_fee);
    printf("Phụ phí cao điểm   : %d VND\n", surcharge);
    printf("Giảm giá freeship  : %d VND\n", discount);
    printf("Phí giao thực tế   : %.2f VND\n", final_delivery_fee);
    printf("--------------------------------------------------\n");
    printf("Trạng thái hợp lệ  : %d (1: HỢP LỆ / 0: TỪ CHỐI)\n", is_valid_order);
    printf("TỔNG TIỀN THANH TOÁN: %.2f VND\n", total_payment);
    printf("==================================================\n");

    return 0;
}