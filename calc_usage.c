typedef struct usage {
  int start_time;
  int usageWh;
} usage;

typedef struct price {
  int start_time;
  int priceEars;
} price;

int calc_usage(usage *usages, int usages_count, price *prices, int prices_count) {
  int result = 0;

  int i = 0;
  int j = 0;
  while (i < usages_count) {
    while ((j < prices_count-1) && (prices[j+1].start_time <= usages[i].start_time)) {
      j = j + 1;
    }
      result = result + usages[i].usageWh * prices[j].priceEars;
      i = i + 1;
  }

  return result;
}
