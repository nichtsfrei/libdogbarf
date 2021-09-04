#ifndef __BARFCAL_H
#define __BARFCAL_H

#define ANIMAL_PERCENTAGE 0.8
#define HERBAL_PERCENTAGE 0.2
/*
 * This calculater is biased: it is without crop and has some simplifications.
 *
 * It assumes 80% animal; 20% herbal.
 *
 * Of those 80% animal it assumes:
 * - * 0.5 scallop ( * 0.15-0.25 fat);
 * - * 0.2 rumen;
 * - * 0.15 insides
 * - * 0.15 raw bones and and meat.
 *
 * Of those 20% herbal: * 0.7 vegetables; * 0.3 fruits.
 *
 * Fat within meat varies from 5% - 25% percent the amount of fat needs to be
 * at least 15% for a dog. The rest will be enhanced via additional fat
 * (e.g. coconut oil).
 *
 * This calculator assumes an average of 8% fat within the meat. 
 *
 * The amount of food is:
 * - 2-4% adult animals
 * - 4-10% if in growth or lactating.
 *
 * While growing the tendency is higher on large dogs than on small dogs:
 *
 * 9 - 16 weeks small: 0.051, medium: 0.054, large: 0.06
 * 17 - 24 weeks small: 0.045, medium: 0.048, large: 0.054
 * 24 - 38 weeks: small: 0.038 , medium: 0.042 , large: 0.048
 *
 * small 7-10 months: 0.032
 * medium 8 - 12 months: 0.036
 * large 9 - 16 months: 0.042
 *
 * small 10-14 months: 0.03
 * medium 13 - 18 months: 0.03
 * large 16 - 24 months: 0.036
 *
 * When adult: small rather 0.03, medium: 0.03, large: 0.02 as base.
 *
 * Extra factor:
 * - 1 activity < 2h
 * - 2-3h activity 1.25
 * - 3-4h activity 1.5
 * - 4-5h activity 1.75
 * - 5-6h activity 2.0
 * > 6h activity 2.5
 * nautered or old 0.9
 *
 * Supplement calculation:
 * algae powder:
 *	we assume:
 *	- 29.0 µg per kg when puppy and 12.7 µg per kg when adult
 *	- therefore we conclude step wise setting per age group:
 *		- 9 - 16 weeks 29.0 µg per kg
 *		- 17 - 27 weeks: 29.0 * 0.8 ~ 23.2
 *		- < 7 months: 29.0 * 0.7 ~ 20.3
 *		- < 10 months: 29 * 0.6 ~ 17.4
 *		- < 1 year: 29 * 0.5 ~ 14.5
 *		- above that 12.7µg per kg
 *
 *	Although various calulator assume more based on food and energy
 *  consumption we stick with that assuming a higher dosis due to measurements
 *  mistakes and mood swings within a household.
 *
 * Cod liver oild:
 * We assume 0.00000463 * food portion
 *
 * Omega 3 Oil:
 * We assume 0.0000093 * food portion.
 *
 */

#define BCD_ANIMAL                                                             \
	X(bcd_animal_scallop, 0.5, "scallop")                                  \
	X(bcd_animal_rumen, 0.2, "rumen")                                      \
	X(bcd_animal_insides, 0.15, "insides")                                 \
	X(bcd_animal_bones, 0.15, "raw meaty bones")

#define BCD_HERBAL                                                             \
	X(bcd_herbal_vegetables, 0.8, "vegetables")                            \
	X(bcd_herbal_fruits, 0.2, "fruits")

#define BCD_EXTRA_MULTIFICATION_FACTOR                                         \
	X(bcd_emf_low, 1.0, "low activity")                                    \
	X(bcd_emf_low_middle, 1.25, "low_middle activity")                     \
	X(bcd_emf_middle, 1.5, "middle activity")                              \
	X(bcd_emf_middle_high, 1.75, "middle_high activity")                   \
	X(bcd_emf_high, 2.0, "high activity")                                  \
	X(bcd_emf_very_high, 2.5, "very_high activity")                        \
	X(bcd_emf_old, 0.9, "old")                                             \
	X(bcd_emf_nautered, 0.9, "nautered")

#define BCD_SUPPLEMENT                                                         \
	X(bcd_supplement_unset, 0.0, "ignored")                                \
	X(bcd_supplement_algae_powder, 0.00000463, "algae powder")             \
	X(bcd_supplement_cod_liver_oil, 0.00000463, "cod liver oil")           \
	X(bcd_supplement_fat, 0.15, "fat")                                     \
	X(bcd_supplement_oil, 0.0000093, "oil with omega 3")

#define BCD_SPAN_UNIT                                                          \
	X(bcd_day, "day")                                                      \
	X(bcd_week, "week")                                                    \
	X(bcd_month, "month")                                                  \
	X(bcd_year, "year")

// define in liter as well
#define BCD_WEIGHT_UNIT                                                        \
	X(bcd_micro_gram, "μg")                                                \
	X(bcd_milli_gram, "mg")                                                \
	X(bcd_gram, "g")                                                       \
	X(bcd_kilo_gram, "kg")                                                 \
	X(bcd_micro_liter, "μl")                                               \
	X(bcd_milli_liter, "ml")                                               \
	X(bcd_liter, "l")                                                      \
	X(bcd_kilo_liter, "kl")

#define BCD_DOG_SIZE                                                           \
	X(bcd_dog_small, "small")                                              \
	X(bcd_dog_medium, "medium")                                            \
	X(bcd_dog_large, "large")

enum bcd_animal_type {
#define X(a, b, c) a,
	BCD_ANIMAL
#undef X
};

enum bcd_weight_unit {
#define X(a, b) a,
	BCD_WEIGHT_UNIT
#undef X
};

enum bcd_dog_size {
#define X(a, b) a,
	BCD_DOG_SIZE
#undef X
};

enum bcd_span_unit {
#define X(a, b) a,
	BCD_SPAN_UNIT
#undef X
};
enum bcd_herbal_type {
#define X(a, b, c) a,
	BCD_HERBAL
#undef X
};

enum bcd_supplement_type {
#define X(a, b, c) a,
	BCD_SUPPLEMENT
#undef X
};

enum bcd_extra_multification_factor {
#define X(a, b, c) a,
	BCD_EXTRA_MULTIFICATION_FACTOR
#undef X
};

struct bcd_animal_recommendation {
	enum bcd_animal_type type;
	enum bcd_weight_unit weight_unit;
	float amount;
};

struct bcd_animal_recommendations {
	unsigned int len;
	unsigned int cap;
	struct bcd_animal_recommendation *recommendations;
};

struct bcd_herbal_recommendation {
	enum bcd_herbal_type type;
	enum bcd_weight_unit weight_unit;
	float amount;
};

struct bcd_herbal_recommendations {
	unsigned int len;
	unsigned int cap;
	struct bcd_herbal_recommendation *recommendations;
};

struct bcd_supplement_recommendation {
	enum bcd_supplement_type type;
	enum bcd_weight_unit weight_unit;
	float amount;
};

struct bcd_supplement_recommendations {
	unsigned int len;
	unsigned int cap;
	struct bcd_supplement_recommendation *recommendations;
};

struct bcd_recommendation {
	unsigned int span;
	enum bcd_span_unit span_unit;
	struct bcd_supplement_recommendations *supplements;
	struct bcd_animal_recommendations *animal;
	struct bcd_herbal_recommendations *herbal;
};

struct bcd_recommendations {
	unsigned int len;
	unsigned int cap;
	struct bcd_recommendation *recommendations;
};

struct bcd_dog {
	enum bcd_dog_size size;
	unsigned int age;
	enum bcd_span_unit age_unit;
	float weight;
	enum bcd_weight_unit weight_unit;
	unsigned int activity_level_in_hours;
	int is_nautered;
	int is_old;
};

struct bcd_algae_powder {
	unsigned int jod;
	unsigned int per;
	enum bcd_weight_unit jod_weight_unit;
	enum bcd_weight_unit per_unit;
};

float bcd_animal_type_severity(enum bcd_animal_type);

char *bcd_animal_type_string(enum bcd_animal_type);

char *bcd_weight_unit_string(enum bcd_weight_unit);

char *bcd_span_unit_string(enum bcd_span_unit);

float bcd_herbal_type_severity(enum bcd_herbal_type);

char *bcd_herbal_type_string(enum bcd_herbal_type);

float bcd_supplement_type_severity(enum bcd_supplement_type);

char *bcd_supplement_type_string(enum bcd_supplement_type);

float bcd_extra_multification_factor_severity(
    enum bcd_extra_multification_factor);

char *
    bcd_extra_multification_factor_string(enum bcd_extra_multification_factor);

float bcd_dog_size_severity(enum bcd_dog_size);

char *bcd_dog_size_string(enum bcd_dog_size);

float bcd_calculate_factor(const struct bcd_dog *dog);

int bcd_animal_total(const struct bcd_animal_recommendations *animal,
		     float *total,
		     enum bcd_weight_unit *total_unit);

struct bcd_recommendation *
calculate_recommendation(const struct bcd_dog *dog,
			 const struct bcd_algae_powder *algae_powder);

int bcd_recommendation_for_span(unsigned int span,
				enum bcd_span_unit span_unit,
				struct bcd_recommendation *recommendation);

int bcd_recommendation_human_readable_units(
    struct bcd_recommendation *recommendation);

struct bcd_portions {
	unsigned int span;
	enum bcd_span_unit span_unit;
	unsigned int portions;
	enum bcd_span_unit portions_per;
	struct bcd_recommendations *recommendations;
};

struct bcd_portions *bcd_food_plan(unsigned int span,
				   enum bcd_span_unit span_unit,
				   unsigned int portions_per_day,
				   const struct bcd_recommendation *base);

float bcd_span_unit_to(float value,
		       enum bcd_span_unit from,
		       enum bcd_span_unit to);
unsigned int bcd_birthdate_to_days(const int year,
				   const unsigned int month,
				   const unsigned int day);
void bcd_destroy_recommendation(struct bcd_recommendation **recommendation);
void bcd_destroy_portions(struct bcd_portions **portions);
#endif
