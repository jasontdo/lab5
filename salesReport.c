#include <stdio.h>
#include <string.h>

void printMonthlySales(char months[12][10], float sales[12]) {
    printf("Monthly sales report for 2024:\n");
    printf("Month    \tSales\n");
    for (int i=0; i < 12; i++) {
        printf("%-10s\t$%.2f\n", months[i], sales[i]);
    }
}

void minSales(char months[12][10], float sales[12]) {
    printf("\nSales Summary:\n");
    float min_value = sales[0];
    int numMin = 0;
    for (int i=0; i < 12; i++) {
        if (sales[i] < min_value) {
            min_value = sales[i];
            numMin = i;
        }
    }
    printf("Minimum sales: $%.2f  ", min_value);
    printf("(%s)\n", months[numMin]);
}

void maxSales(char months[12][10], float sales[12]) {
    float max_value = sales[0];
    int numMax = 0;
    for (int i=0; i < 12; i++) {
        if (sales[i] > max_value) {
            max_value = sales[i];
            numMax = i;
        }
    }
    printf("Maximum sales: $%.2f  ", max_value);
    printf("(%s)\n", months[numMax]);
}

void averageSales(float sales[12]) {
    float avgNum = 0;
    for (int i=0; i < 12; i++) {
        avgNum = (avgNum + sales[i]);
    }
    avgNum = avgNum/12;
    printf("Average Sales: $%.2f\n", avgNum);
}

void sixMonthReport(char months[12][10], float sales[12]) {
    printf("\nSix-Month Moving Average Report:\n");
    for (int i=0; i < 7; i++) {
        float totalSales = 0;
        for (int j=i; j < i + 6; j++) {
            totalSales += sales[j];
        }
        float avgSales = totalSales/6;
        printf("%-7s - %-10s $%.2f\n", months[i], months[i+5], avgSales);
    }
}

void sortSales(char months[12][10], float sales[12]) {
    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month\t  Sales\n");
    char tempMonths[12][10];
    float tempSales[12];
    // copy values and months to temp arrays
    for (int i=0; i < 12; i++) {
        strcpy(tempMonths[i], months[i]);
        tempSales[i] = sales[i];
    }

    // Bubble sort from greatest to least
    for (int i=0; i < 11; i++){
        for (int j=0; j < 11 - i; j++) {
            if (tempSales[j] < tempSales[j+1]) {
                float temp = tempSales[j];
                tempSales[j] = tempSales[j+1];
                tempSales[j+1] = temp;
                // temporary stores month to swap
                char tMonth[10];
                strcpy(tMonth, tempMonths[j]);
                strcpy(tempMonths[j], tempMonths[j+1]);
                strcpy(tempMonths[j+1], tMonth);

            }
        }
    }

    for (int j=0; j < 12; j++) {
        printf("%-10s$%-10.2f\n", tempMonths[j], tempSales[j]);
    }
}

int main(){
    char months[12][10] = {"January","Febuary","March","April","May","June","July","August","September","October","November","December"};
    float sales[12];

    char filename[100];
    printf("Enter file name: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    for (int i=0; i < 12; i++) {
        if (fscanf(file, "%f", &sales[i]) != 1) {
            fclose(file);
            return 1;
        }
    }

    printMonthlySales(months, sales);
    minSales(months, sales);
    maxSales(months, sales);
    averageSales(sales);
    sixMonthReport(months, sales);
    sortSales(months, sales);
    return 0;
}