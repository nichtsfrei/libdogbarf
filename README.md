# libdogbarfcal

This calculator is biased: it is without crop and has some simplifications.

It assumes 80% animal; 20% herbal.

Of those 80% animal it assumes:
- * 0.5 scallop
- * 0.2 rumen
- * 0.15 insides
- * 0.15 raw bones and meat.

Of those 20% herbal: 
- * 0.7 vegetables
- * 0.3 fruits.

Fat within meat varies from 5% - 25% percent the amount of fat needs to be
at least 15% for a dog. The rest will be enhanced via additional fat
(e.g. coconut oil).

This calculator assumes a flat average of 8% fat within the meat. 

The amount of food is:
- 2-4% adult animals
- 4-10% if in growth or lactating.

While growing the tendency is higher on large dogs than on small dogs:

| Dog Size | Age            | Multiplier |
| -------- | -------------- | ---------- |
| small    | 9 - 16 weeks   | 0.051      |
| small    | 17 - 24 weeks  | 0.045      |
| small    | 24 - 38 weeks  | 0.038      |
| small    | 7-10 months    | 0.032      |
| small    | 10-14 months   | 0.03       |
| medium   | 9 - 16 weeks   | 0.054      |
| medium   | 17 - 24 weeks  | 0.048      |
| medium   | 24 - 38 weeks  | 0.042      |
| medium   | 8 - 12 months  | 0.036      |
| medium   | 13 - 18 months | 0.03       |
| large    | 9 - 16 weeks   | 0.06       |
| large    | 17 - 24 weeks  | 0.054      |
| large    | 24 - 38 weeks  | 0.048      |
| large    | 9 - 16 months  | 0.042      |
| large    | 16 - 24 months | 0.036      |

However on adult dogs that changes:

| Dog size | Multiplier |
| -------- | ---------- |
| small    | 0.03       |
| medium   | 0.03       |
| large    | 0.02       |

Additional this calculator adds extra multiplier based on activity levels:

| Activity in hours | Multiplier |
| ----------------- | ---------- |
| 1h                | 1.0        |
| 2-3h              | 1.25       |
| 3-4h              | 1.5        |
| 4-5h              | 1.75       |
| 5-6h              | 2.0        |
| > 6h              | 2.5        |

When the dog is neutered or old the multiplier gets reduced by 10% (multiplier 0.9).

Supplement calculation of this calculator is simplified as well. 

For algae powder we assume:
- 29.0 µg per kg when puppy
- 12.7 µg per kg when adult

Therefore this calculator concludes a step wise setting per age group:

- 9 - 16 weeks 29.0 µg per kg
- 17 - 27 weeks: 29.0 * 0.8 ~ 23.2
- < 7 months: 29.0 * 0.7 ~ 20.3
- < 10 months: 29 * 0.6 ~ 17.4
- < 1 year: 29 * 0.5 ~ 14.5
- above that 12.7µg per kg

Although various calculator assume more based on food and energy
consumption we stick with that assuming a higher doses due to measurements
mistakes and mood swings within a household.

For Cod liver oil it assumes:
- a flat 0.00000463 * food portion

For Omega 3 Oil it assumes:
- a flat 0.0000093 * food portion.

## How to build

To build the project you can run:

```
cmake -Bbuild -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_EXPORT_PACKAGE_REGISTRY=1
cmake --build build
cd example
cmake -Bbuild -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_EXPORT_PACKAGE_REGISTRY=1
cmake --build build
```

## Contribution

Although this calculator is build for my personal needs contribution is highly welcome but not defined. 

So, go ahead change things and create a pr.
