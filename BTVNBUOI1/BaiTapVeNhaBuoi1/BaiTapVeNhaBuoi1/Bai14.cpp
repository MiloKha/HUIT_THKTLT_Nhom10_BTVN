#include <stdio.h>

#define MAX_YEARS 10

typedef struct {
    int year;
    int age;
    int months;
    int minYear;
    int maxYear;
} RetirementRule;

RetirementRule rulesMale[MAX_YEARS] = {
    {2021, 60, 3, 1961, 1961},
    {2021, 55, 4, 1966, 1966},
    {2022, 60, 6, 1961, 1962},
    {2022, 55, 8, 1966, 1967},
    {2023, 60, 9, 1962, 1963},
    {2024, 61, 0, 1963, 1963},
    {2025, 61, 3, 1964, 1964},
    {2026, 61, 6, 1964, 1965},
    {2027, 61, 9, 1965, 1966},
    {2028, 62, 0, 1966, 9999}
};

RetirementRule rulesFemale[MAX_YEARS] = {
    {2021, 55, 4, 1966, 1966},
    {2022, 55, 8, 1966, 1967},
    {2023, 56, 0, 1967, 1967},
    {2024, 56, 4, 1968, 1968},
    {2025, 56, 8, 1968, 1969},
    {2026, 57, 0, 1969, 1969},
    {2027, 57, 4, 1970, 1970},
    {2028, 57, 8, 1970, 1971},
    {2029, 58, 0, 1971, 1971},
    {2030, 58, 4, 1972, 1972}
};

int findRetirementRule(int year, int birthYear, RetirementRule rules[], int size) {
    for (int i = 0; i < size; i++) {
        if (year >= rules[i].year && birthYear >= rules[i].minYear && birthYear <= rules[i].maxYear) {
            return i;
        }
    }
    return -1;
}

int main() {
    int year, birthYear;
    char gender;
    int ruleIndex;

    printf("Nhap nam hien tai: ");
    scanf("%d", &year);

    printf("Nhap nam sinh: ");
    scanf("%d", &birthYear);

    printf("Nhap gioi tinh (n: nam, n: nu): ");
    scanf(" %c", &gender);

    if (gender == 'n') {
        ruleIndex = findRetirementRule(year, birthYear, rulesMale, MAX_YEARS);
        if (ruleIndex != -1) {
            printf("Lao dong nam sinh nam %d se nghi huu vao nam %d, tuoi %d, %d thang\n",
                birthYear, rulesMale[ruleIndex].year, rulesMale[ruleIndex].age, rulesMale[ruleIndex].months);
        }
        else {
            printf("Khong co quy dinh nghi huu cho nam sinh va nam hien tai nay.\n");
        }
    }
    else if (gender == 'n') {
        ruleIndex = findRetirementRule(year, birthYear, rulesFemale, MAX_YEARS);
        if (ruleIndex != -1) {
            printf("Lao dong nu sinh nam %d se nghi huu vao nam %d, tuoi %d, %d thang\n",
                birthYear, rulesFemale[ruleIndex].year, rulesFemale[ruleIndex].age, rulesFemale[ruleIndex].months);
        }
        else {
            printf("Khong co quy dinh nghi huu cho nam sinh va nam hien tai nay.\n");
        }
    }
    else {
        printf("Gioi tinh khong hop le.\n");
    }

    return 0;
}
