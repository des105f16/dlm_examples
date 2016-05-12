typedef struct usage {
  int start_time;
  int usage_in_Wh;
} usage;

typedef struct price {
  int start_time;
  int price_in_cents;
} price;

usage* get_latest_usage();
price* get_latest_prices();
void send_to_consumer(int bill);
void send_to_electrical_company(int bill);

int calculate_bill() {
  int usage_count = 100;
  int prices_count = 100;
  usage *latest_usage = get_latest_usage();
  price *latest_prices = get_latest_prices();
  int result = 0;

  int i = 0;
  int j = 0;
  while (i < usage_count) {
    while ((j < prices_count-1) && (latest_prices[j+1].start_time <= latest_usage[i].start_time)) {
      j = j + 1;
    }
    result = result + latest_usage[i].usage_in_Wh * latest_prices[j].price_in_cents;
    i = i + 1;
  }
  return result;
}

int main(int argc, char **argv) {
  int bill = calculate_bill();
  send_to_consumer(bill);
  send_to_electrical_company(bill);
}
