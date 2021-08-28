#include <simple_dog_barf.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SEPERATOR                                                              \
	for (i = 0; i < 196; i++)                                              \
		printf("_");                                                   \
	printf("\n");


static char *number_to_day_string(unsigned int i) {
	switch (i) {
		case 0:
			return "monday";
		case 1:
			return "tuesday";
		case 2:
			return "wednesday";
		case 3:
			return "thursday";
		case 4:
			return "friday";
		case 5:
			return "saturday";
		case 6:
			return "sunday";
		default:
			return "unknown";
	}
}

int main()
{
	int i, j, already_mixed_meat = 1;
	struct bcd_dog dog;
	struct bcd_algae_powder algae;
	struct bcd_recommendation *recommendation;
	struct bcd_animal_recommendation *meat;
	struct bcd_herbal_recommendation *herbal;
	struct bcd_supplement_recommendation *supplement;
	enum bcd_weight_unit animal_total_unit;
	struct bcd_portions *portions;
	float animal_total = 0;

	dog.age = bcd_birthdate_to_days(2020, 11, 8);
	dog.age_unit = bcd_day;
	dog.weight = 19.6;
	dog.weight_unit = bcd_kilo_gram;
	dog.is_nautered = 0;
	dog.is_old = 0;
	dog.activity_level_in_hours = 2;
	dog.size = bcd_dog_medium;
	algae.jod = 631;
	algae.jod_weight_unit = bcd_milli_gram;
	algae.per = 1;
	algae.per_unit = bcd_kilo_gram;
	recommendation = calculate_recommendation(&dog, &algae);
	


	if ((portions = bcd_food_plan(1, bcd_week, 2, recommendation)) ==
	    NULL) {
		fprintf(stderr, "%s: unable to prepare food plan\n", __func__);
	}
	float plan_days =
	    bcd_span_unit_to(portions->span, portions->span_unit, bcd_day);
	for (i = 0; i < plan_days; i++)
		printf("%-27s|", number_to_day_string(i));
	printf("\n");
	SEPERATOR;
	struct bcd_animal_recommendation *ar;
	struct bcd_herbal_recommendation *hr;
	struct bcd_supplement_recommendation *sr;
	struct bcd_recommendation *pr;
	int al, hl, sl, k;
	al = portions->recommendations->recommendations[0].animal->len;
	hl = portions->recommendations->recommendations[0].herbal->len;
	sl = portions->recommendations->recommendations[0].supplements->len;
	for (k = 0; k < portions->portions; k++) {
		if (already_mixed_meat == 0) {
			for (j = 0; j < al; j++) {
				for (i = k; i < portions->recommendations->len;
				     i += portions->portions) {
					pr = &portions->recommendations
						  ->recommendations[i];
					bcd_recommendation_human_readable_units(
					    pr);
					ar = &pr->animal->recommendations[j];
					printf("%-16s: %-6.2f%-2s %c",
					       bcd_animal_type_string(ar->type),
					       ar->amount,
					       bcd_weight_unit_string(
						   ar->weight_unit),
					       '|');
				}
				printf("\n");
			}
		} else {
			for (i = k; i < portions->recommendations->len;
			     i += portions->portions) {

				pr = &portions->recommendations
					  ->recommendations[i];
				bcd_animal_total(pr->animal,
						 &animal_total,
						 &animal_total_unit);
				printf(
				    "%-16s: %-6.2f%-2s %c",
				    "total meat",
				    animal_total,
				    bcd_weight_unit_string(animal_total_unit),
				    '|');
			}
			printf("\n");
		}

		for (j = 0; j < hl; j++) {
			for (i = k; i < portions->recommendations->len;
			     i += portions->portions) {
				pr = &portions->recommendations
					  ->recommendations[i];
				bcd_recommendation_human_readable_units(pr);
				hr = &pr->herbal->recommendations[j];
				printf("%-16s: %-6.2f%-2s %c",
				       bcd_herbal_type_string(hr->type),
				       hr->amount,
				       bcd_weight_unit_string(hr->weight_unit),
				       '|');
			}
			printf("\n");
		}
		for (j = 0; j < sl; j++) {
			for (i = k; i < portions->recommendations->len;
			     i += portions->portions) {
				pr = &portions->recommendations
					  ->recommendations[i];
				bcd_recommendation_human_readable_units(pr);
				if (j < pr->supplements->len) {
					sr = &pr->supplements
						  ->recommendations[j];
					printf("%-16s: %-6.2f%-2s %c",
					       bcd_supplement_type_string(
						   sr->type),
					       sr->amount,
					       bcd_weight_unit_string(
						   sr->weight_unit),
					       '|');
				}
			}
			printf("\n");
		}
		SEPERATOR;
	}
	if (bcd_recommendation_for_span(1, bcd_week, recommendation) < 0) {
		fprintf(stderr,
			"%s: failed to enhance recommendations to 1 week\n",
			__func__);
	}
	printf("\n\nThe consumption per %d %s is :\n",
	       recommendation->span,
	       bcd_span_unit_string(recommendation->span_unit));
	bcd_recommendation_human_readable_units(recommendation);
	for (i = 0; i < recommendation->animal->len; i++) {
		meat = &recommendation->animal->recommendations[i];
		printf("- %s: %.2f%s\n",
		       bcd_animal_type_string(meat->type),
		       meat->amount,
		       bcd_weight_unit_string(meat->weight_unit));
	}
	for (i = 0; i < recommendation->herbal->len; i++) {
		herbal = &recommendation->herbal->recommendations[i];
		printf("- %s: %.2f%s\n",
		       bcd_herbal_type_string(herbal->type),
		       herbal->amount,
		       bcd_weight_unit_string(herbal->weight_unit));
	}
	bcd_destroy_recommendation(&recommendation);
	bcd_destroy_portions(&portions);

	return 0;
}

