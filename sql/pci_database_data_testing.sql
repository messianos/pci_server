USE pci_database;

DELETE IGNORE FROM problem_solutions;
DELETE IGNORE FROM Clarification;
DELETE IGNORE FROM Problem;
DELETE IGNORE FROM Solution;
DELETE IGNORE FROM User;

CALL sign_up_user(
'1995-07-09',
'username1@domain.com',
'John',
'M',
'Garcia',
'NYC',
'bc547750b92797f955b36112cc9bdd5cddf7d0862151d03a167ada8995aa24a9ad24610b36a68bc02da24141ee51670aea13ed6469099a4453f335cb239db5da',
'2012-05-05',
'username1'
);
CALL sign_up_user(
'1994-05-06',
'username2@domain.com',
'Mike',
'F',
'Perez',
'MDQ',
'92a891f888e79d1c2e8b82663c0f37cc6d61466c508ec62b8132588afe354712b20bb75429aa20aa3ab7cfcc58836c734306b43efd368080a2250831bf7f363f',
'2012-05-07',
'username2'
);
CALL sign_up_user(
'1996-08-08',
'username3@domain.com',
'John',
'F',
'Perez',
'NYC',
'2a64d6563d9729493f91bf5b143365c0a7bec4025e1fb0ae67e307a0c3bed1c28cfb259fc6be768ab0a962b1e2c9527c5f21a1090a9b9b2d956487eb97ad4209',
'2012-08-07',
'username3'
);
CALL sign_up_user(
'1998-07-05',
'username4@domain.com',
'Jose',
'M',
'Smith',
'BB',
'11961811bd4e11f23648afbd2d5c251d2784827147f1731be010adaf0ab38ae18e5567c6fd1bee50a4cd35fb544b3c594e7d677efa7ca01c2a2cb47f8fb12b17',
'2012-07-03',
'username4'
);
CALL sign_up_user(
'1998-02-02',
'username5@domain.com',
'Jose',
'M',
'Garcia',
'MDQ',
'39c6f5329e959b2af0deb0f8dacbcdf5418204f46baed50388f62b047c9223c66ff470031ecd653a49f6eff6fa876811e46f0c269390a8bf61f4f983729e1083',
'2012-07-09',
'username5'
);
CALL sign_up_user(
'1998-04-06',
'username6@domain.com',
'Mike',
'F',
'Perez',
'CABA',
'011324228a766d0d06e56bd4c61fa8bffa4bc1dd01eb6892f906ef93cb9ba3f4a4243fe40f3e54314115bf0c0eac80bc630ed4dccf7ba6f22b12d9261cca7daa',
'2012-07-05',
'username6'
);
CALL sign_up_user(
'1992-06-03',
'username7@domain.com',
'Jose',
'F',
'Smith',
'NYC',
'a7d785790aecb79a4a3bcd5197301ae76897f83a2424a9b84160ed12a5def47f66d5a88ce5e6032be7e0e91b912d92e1b64f97b1d13a5096eec097470dee7764',
'2012-03-08',
'username7'
);
CALL sign_up_user(
'1996-01-07',
'username8@domain.com',
'John',
'M',
'Doe',
'NYC',
'219aab6b2cf738d9f370e197ce0151be42ae6095e0d72fa49592865c9d2dde5d2fa72e908ac374cba55426e6d0ed39324fd6de1d5da2641cc7f4491f5edd931f',
'2012-09-03',
'username8'
);
CALL sign_up_user(
'1998-06-02',
'username9@domain.com',
'John',
'M',
'Perez',
'BB',
'26e261e3003a175c800a2c48f96972793676e8ab464d0e73da50b1c8d359ed4bac5ee660bfe3ee9a9362ad42ca3c9aa793ab4f707b163dfea4d89b64fae0a0b9',
'2012-02-08',
'username9'
);
CALL sign_up_user(
'1998-09-09',
'username10@domain.com',
'Juan',
'M',
'Doe',
'CABA',
'2ce5f635d25b791d37a92c99f0af6df02a68fa695b74f90685e7d93ed3f5a61a715168541954b4c2feec9fd39fcc4df74fef1b9211e12ca96dc03efba2e6a31e',
'2012-08-01',
'username10'
);

CALL insert_problem(
'Problem 1 content',
'2013-03-08 06:06:06',
'username6',
'Problem 1 description',
'50a2c242c2a98441f084347617e2d7d7e6',
FALSE
);
CALL insert_problem(
'Problem 2 content',
'2013-03-04 05:03:04',
'username10',
'Problem 2 description',
'50df83144a56b04f52914fb7dc43c203e4',
FALSE
);
CALL insert_problem(
'Problem 3 content',
'2013-06-08 02:07:08',
'username10',
'Problem 3 description',
'500c80413e5c3741cc9c95e491e6466fd1',
FALSE
);
CALL insert_problem(
'Problem 4 content',
'2013-03-09 04:08:06',
'username5',
'Problem 4 description',
'50f983e8977e514e558cdf6abd7e8ff55d',
FALSE
);
CALL insert_problem(
'Problem 5 content',
'2013-07-07 03:04:02',
'username7',
'Problem 5 description',
'5006477c034bab466b85f0ccccef5d43d8',
TRUE
);
CALL insert_problem(
'Problem 6 content',
'2013-01-01 04:01:09',
'username2',
'Problem 6 description',
'502d1a2e7452d6480e86e9f6a3bcabd0b0',
FALSE
);
CALL insert_problem(
'Problem 7 content',
'2013-04-09 07:07:04',
'username8',
'Problem 7 description',
'50149e83c5d7f044acabb94f52ec45647b',
TRUE
);
CALL insert_problem(
'Problem 8 content',
'2013-03-03 02:05:07',
'username9',
'Problem 8 description',
'508005e05893a240168003cfdfd222bf8b',
FALSE
);
CALL insert_problem(
'Problem 9 content',
'2013-07-05 05:06:06',
'username7',
'Problem 9 description',
'509caa6d85072d467184594d09ae708ae0',
TRUE
);
CALL insert_problem(
'Problem 10 content',
'2013-01-02 01:03:05',
'username1',
'Problem 10 description',
'50a853dfb6fb544adc9da817686af42891',
FALSE
);
CALL insert_problem(
'Problem 11 content',
'2013-02-03 04:07:02',
'username8',
'Problem 11 description',
'5057fa93c90bc54d6192d42ac6a3ba1d79',
FALSE
);
CALL insert_problem(
'Problem 12 content',
'2013-06-08 07:02:03',
'username1',
'Problem 12 description',
'504b2767e0701f4c6493958ba152e03e7f',
TRUE
);
CALL insert_problem(
'Problem 13 content',
'2013-09-01 08:06:07',
'username6',
'Problem 13 description',
'50f7d4ead99b5a46d8afb38b609bad2cd5',
FALSE
);
CALL insert_problem(
'Problem 14 content',
'2013-08-08 01:07:06',
'username7',
'Problem 14 description',
'50b7a79e547f9c4b20b854473c98aaa797',
TRUE
);
CALL insert_problem(
'Problem 15 content',
'2013-08-07 01:03:08',
'username10',
'Problem 15 description',
'5071741639a7b24ee28e67f1013a53b38e',
FALSE
);
CALL insert_problem(
'Problem 16 content',
'2013-09-01 09:08:07',
'username4',
'Problem 16 description',
'508d01faf0db404ba28779854bdd3eb539',
FALSE
);
CALL insert_problem(
'Problem 17 content',
'2013-05-01 06:09:06',
'username8',
'Problem 17 description',
'5045a43cbe92a94457b1cc574a8fbeaa26',
TRUE
);
CALL insert_problem(
'Problem 18 content',
'2013-01-07 01:05:04',
'username10',
'Problem 18 description',
'50b45e6eb074584f348016cb9259e24bf1',
TRUE
);
CALL insert_problem(
'Problem 19 content',
'2013-03-04 04:03:08',
'username8',
'Problem 19 description',
'5017b7cecb164741fa9e6d914dce8cf6dc',
FALSE
);
CALL insert_problem(
'Problem 20 content',
'2013-08-08 08:01:01',
'username10',
'Problem 20 description',
'50363b35908edc4bd5bdd643b2633797bd',
FALSE
);
CALL insert_problem(
'Problem 21 content',
'2013-05-02 02:08:08',
'username2',
'Problem 21 description',
'507a684d685f614d28b9e1813756dfb3b1',
TRUE
);
CALL insert_problem(
'Problem 22 content',
'2013-03-08 09:09:07',
'username6',
'Problem 22 description',
'50f99655abb4404950a53e24a8c590ba38',
FALSE
);
CALL insert_problem(
'Problem 23 content',
'2013-08-08 09:08:03',
'username2',
'Problem 23 description',
'50595f68cee8194db0908d981a3b243d09',
FALSE
);
CALL insert_problem(
'Problem 24 content',
'2013-09-09 01:09:09',
'username6',
'Problem 24 description',
'5068b3560fe9a44b7cbef46cbcc487a701',
FALSE
);
CALL insert_problem(
'Problem 25 content',
'2013-01-04 08:02:08',
'username7',
'Problem 25 description',
'501df0ed40d007406e8b9cb73aa2438ef1',
TRUE
);
CALL insert_problem(
'Problem 26 content',
'2013-04-01 04:05:03',
'username3',
'Problem 26 description',
'50ef251b3fe60d41de92598998b428318c',
TRUE
);
CALL insert_problem(
'Problem 27 content',
'2013-04-06 02:07:04',
'username7',
'Problem 27 description',
'50c425d10ac4bd4126ba6b85fd931d9d80',
FALSE
);
CALL insert_problem(
'Problem 28 content',
'2013-07-08 04:08:09',
'username2',
'Problem 28 description',
'500bcce74bc1a2415198efe478970aa0d4',
FALSE
);
CALL insert_problem(
'Problem 29 content',
'2013-03-01 08:03:05',
'username4',
'Problem 29 description',
'5089a2775d0e7848bf86967e1ea9e4133c',
FALSE
);
CALL insert_problem(
'Problem 30 content',
'2013-08-03 06:04:03',
'username6',
'Problem 30 description',
'5028bff88c89d946818366bea7ecf99587',
FALSE
);

CALL insert_solution(
'501df0ed40d007406e8b9cb73aa2438ef1',
'Solution 1 content',
'2013-01-09 04:02:05',
'username3',
'Solution 1 description',
'53d8e97970e4d14c6cafd0a8cbf1c24a19',
TRUE
);
CALL insert_solution(
'50595f68cee8194db0908d981a3b243d09',
'Solution 2 content',
'2013-08-03 07:03:09',
'username4',
'Solution 2 description',
'534606588cfb0c45b18eacbbd4321a80ac',
TRUE
);
CALL insert_solution(
'50f983e8977e514e558cdf6abd7e8ff55d',
'Solution 3 content',
'2013-09-07 03:07:09',
'username8',
'Solution 3 description',
'53e35b19104821466f919ba9e6a6d7c917',
TRUE
);
CALL insert_solution(
'502d1a2e7452d6480e86e9f6a3bcabd0b0',
'Solution 4 content',
'2013-01-09 03:04:03',
'username8',
'Solution 4 description',
'531ac846538b6041f5857ba75fa818f519',
TRUE
);
CALL insert_solution(
'502d1a2e7452d6480e86e9f6a3bcabd0b0',
'Solution 5 content',
'2013-08-03 02:01:02',
'username9',
'Solution 5 description',
'53f24a3feae8b54fe1a54d90b5bd231741',
FALSE
);
CALL insert_solution(
'50df83144a56b04f52914fb7dc43c203e4',
'Solution 6 content',
'2013-03-01 08:01:03',
'username6',
'Solution 6 description',
'53ca4729d4fc8e42c48b48311e07fb595d',
TRUE
);
CALL insert_solution(
'509caa6d85072d467184594d09ae708ae0',
'Solution 7 content',
'2013-04-07 06:07:01',
'username6',
'Solution 7 description',
'53eebdafe0ca03458ab6077bb6610a5d9a',
FALSE
);
CALL insert_solution(
'50f983e8977e514e558cdf6abd7e8ff55d',
'Solution 8 content',
'2013-07-05 03:05:07',
'username4',
'Solution 8 description',
'539a3d0721702d450db36fa8eea1d6a70d',
FALSE
);
CALL insert_solution(
'50c425d10ac4bd4126ba6b85fd931d9d80',
'Solution 9 content',
'2013-02-06 02:09:01',
'username7',
'Solution 9 description',
'535a659b29fe394123b20a96f8fec1f145',
FALSE
);
CALL insert_solution(
'500bcce74bc1a2415198efe478970aa0d4',
'Solution 10 content',
'2013-03-04 02:01:01',
'username6',
'Solution 10 description',
'53b44dba190a9243a4b9500556cdeaba50',
TRUE
);
CALL insert_solution(
'5017b7cecb164741fa9e6d914dce8cf6dc',
'Solution 11 content',
'2013-08-02 06:07:01',
'username2',
'Solution 11 description',
'53f14af805e75443838adace381435fe97',
TRUE
);
CALL insert_solution(
'5071741639a7b24ee28e67f1013a53b38e',
'Solution 12 content',
'2013-04-02 01:06:05',
'username3',
'Solution 12 description',
'530d9c9d4375ec4e9da31fe706056d5fd1',
TRUE
);
CALL insert_solution(
'5057fa93c90bc54d6192d42ac6a3ba1d79',
'Solution 13 content',
'2013-02-04 07:09:03',
'username5',
'Solution 13 description',
'536fa2249d405f4160a5a3eee51594a8ca',
FALSE
);
CALL insert_solution(
'50f7d4ead99b5a46d8afb38b609bad2cd5',
'Solution 14 content',
'2013-01-07 04:06:07',
'username5',
'Solution 14 description',
'53e764f7a2bc4e4082ae3d19eb6e8764ee',
TRUE
);
CALL insert_solution(
'50f983e8977e514e558cdf6abd7e8ff55d',
'Solution 15 content',
'2013-02-05 03:04:06',
'username3',
'Solution 15 description',
'537739cd7c9a80482d92970655559be1f8',
TRUE
);
CALL insert_solution(
'50f983e8977e514e558cdf6abd7e8ff55d',
'Solution 16 content',
'2013-02-03 05:08:09',
'username3',
'Solution 16 description',
'5399a23206df60477fb46df548ea1ca3f7',
TRUE
);
CALL insert_solution(
'508d01faf0db404ba28779854bdd3eb539',
'Solution 17 content',
'2013-08-01 07:09:01',
'username7',
'Solution 17 description',
'53dd2f4baa7f4645d4947992901a3a4fbe',
FALSE
);
CALL insert_solution(
'5089a2775d0e7848bf86967e1ea9e4133c',
'Solution 18 content',
'2013-03-06 02:02:06',
'username10',
'Solution 18 description',
'531cb2f2e4c39c4de7a4a6af4664f62dd5',
TRUE
);
CALL insert_solution(
'50c425d10ac4bd4126ba6b85fd931d9d80',
'Solution 19 content',
'2013-07-07 04:04:08',
'username9',
'Solution 19 description',
'534e9d41ee99fe43d4886f47e0438e29e7',
FALSE
);
CALL insert_solution(
'50149e83c5d7f044acabb94f52ec45647b',
'Solution 20 content',
'2013-07-09 07:06:07',
'username10',
'Solution 20 description',
'530be382886c90478baaf064949206f280',
TRUE
);
CALL insert_solution(
'50a2c242c2a98441f084347617e2d7d7e6',
'Solution 21 content',
'2013-07-04 05:08:08',
'username9',
'Solution 21 description',
'532d06b6bd041e4ce48da57a17eb9069d3',
FALSE
);
CALL insert_solution(
'50f983e8977e514e558cdf6abd7e8ff55d',
'Solution 22 content',
'2013-01-09 04:05:06',
'username8',
'Solution 22 description',
'531fdbec7dfe964da483603a575f9dc191',
FALSE
);
CALL insert_solution(
'50b7a79e547f9c4b20b854473c98aaa797',
'Solution 23 content',
'2013-08-09 06:09:02',
'username6',
'Solution 23 description',
'5352d9c911546a43b28678cf863c3d358d',
TRUE
);
CALL insert_solution(
'50363b35908edc4bd5bdd643b2633797bd',
'Solution 24 content',
'2013-07-04 04:08:09',
'username8',
'Solution 24 description',
'5390e7330d1efb4ae1a2a80241d4e7ca91',
TRUE
);
CALL insert_solution(
'504b2767e0701f4c6493958ba152e03e7f',
'Solution 25 content',
'2013-09-09 06:04:05',
'username2',
'Solution 25 description',
'5323fd26051c2a4a0fa7307f5bfb24290e',
FALSE
);
CALL insert_solution(
'502d1a2e7452d6480e86e9f6a3bcabd0b0',
'Solution 26 content',
'2013-02-05 02:04:05',
'username2',
'Solution 26 description',
'531efb446f4a0a46e1b458ba50babc2836',
FALSE
);
CALL insert_solution(
'50595f68cee8194db0908d981a3b243d09',
'Solution 27 content',
'2013-08-02 08:04:04',
'username9',
'Solution 27 description',
'53b1a9d3f23ae34d8fb01941d31ea9075f',
FALSE
);
CALL insert_solution(
'50363b35908edc4bd5bdd643b2633797bd',
'Solution 28 content',
'2013-05-05 07:08:07',
'username8',
'Solution 28 description',
'53ce0a3035a4844fa1ab8ff84a96aa6514',
FALSE
);
CALL insert_solution(
'500bcce74bc1a2415198efe478970aa0d4',
'Solution 29 content',
'2013-08-04 07:09:07',
'username1',
'Solution 29 description',
'5353106676a06c4b3ea1090bb404718776',
TRUE
);
CALL insert_solution(
'50f99655abb4404950a53e24a8c590ba38',
'Solution 30 content',
'2013-04-08 03:08:08',
'username4',
'Solution 30 description',
'536b89f29ae4e146b69b5b4cd1a228d377',
TRUE
);
CALL insert_solution(
'5045a43cbe92a94457b1cc574a8fbeaa26',
'Solution 31 content',
'2013-04-01 07:05:05',
'username10',
'Solution 31 description',
'5390384e408f354d1da542c82ecbea7221',
FALSE
);
CALL insert_solution(
'50a2c242c2a98441f084347617e2d7d7e6',
'Solution 32 content',
'2013-06-03 03:01:09',
'username9',
'Solution 32 description',
'53061b054824e54141b1ebe534efc2883f',
TRUE
);
CALL insert_solution(
'50f99655abb4404950a53e24a8c590ba38',
'Solution 33 content',
'2013-06-03 05:02:07',
'username1',
'Solution 33 description',
'53789c8ba86aed46daae84c67887e96e67',
FALSE
);
CALL insert_solution(
'5068b3560fe9a44b7cbef46cbcc487a701',
'Solution 34 content',
'2013-07-08 01:06:07',
'username8',
'Solution 34 description',
'53dd16cd983af044d7811266efb78f853a',
FALSE
);
CALL insert_solution(
'50149e83c5d7f044acabb94f52ec45647b',
'Solution 35 content',
'2013-09-01 01:08:09',
'username9',
'Solution 35 description',
'53355b319e7546491fb7f0b3308ee39671',
FALSE
);
CALL insert_solution(
'509caa6d85072d467184594d09ae708ae0',
'Solution 36 content',
'2013-07-07 06:02:04',
'username7',
'Solution 36 description',
'531d2b0f29735244fbb82c56da1a130932',
FALSE
);
CALL insert_solution(
'50595f68cee8194db0908d981a3b243d09',
'Solution 37 content',
'2013-04-09 04:03:05',
'username7',
'Solution 37 description',
'5388e00011d68f4470bbb91eb43d920f05',
TRUE
);
CALL insert_solution(
'508005e05893a240168003cfdfd222bf8b',
'Solution 38 content',
'2013-06-06 07:02:09',
'username6',
'Solution 38 description',
'53c6049bda650d49bc806332a9fe044073',
TRUE
);
CALL insert_solution(
'502d1a2e7452d6480e86e9f6a3bcabd0b0',
'Solution 39 content',
'2013-06-05 03:05:08',
'username4',
'Solution 39 description',
'53b2b9dca466bc4afeb9e7039ec4505931',
TRUE
);
CALL insert_solution(
'500bcce74bc1a2415198efe478970aa0d4',
'Solution 40 content',
'2013-06-08 07:05:02',
'username6',
'Solution 40 description',
'53abe3a808257b4a61a9a5a4dd77d8bc5e',
FALSE
);
CALL insert_solution(
'50b7a79e547f9c4b20b854473c98aaa797',
'Solution 41 content',
'2013-06-06 07:02:05',
'username5',
'Solution 41 description',
'5319484a808a1841068e9ea73b20e88d0e',
FALSE
);
CALL insert_solution(
'5006477c034bab466b85f0ccccef5d43d8',
'Solution 42 content',
'2013-09-01 09:09:07',
'username2',
'Solution 42 description',
'53a7f3662da11e40e989259155c7783de0',
TRUE
);
CALL insert_solution(
'50595f68cee8194db0908d981a3b243d09',
'Solution 43 content',
'2013-06-02 07:05:05',
'username3',
'Solution 43 description',
'53a01487c8427e4f9293c2af11e293643d',
FALSE
);
CALL insert_solution(
'500bcce74bc1a2415198efe478970aa0d4',
'Solution 44 content',
'2013-07-01 04:06:07',
'username5',
'Solution 44 description',
'531176a6564d794bb891aa73ee3cf7e939',
TRUE
);
CALL insert_solution(
'50b7a79e547f9c4b20b854473c98aaa797',
'Solution 45 content',
'2013-03-06 06:06:02',
'username9',
'Solution 45 description',
'53b313bc161ff446d1a1180a4a86e19b69',
FALSE
);
CALL insert_solution(
'507a684d685f614d28b9e1813756dfb3b1',
'Solution 46 content',
'2013-01-06 08:09:07',
'username3',
'Solution 46 description',
'53a14683e38e1f4c99a9acce33524fb2e2',
FALSE
);
CALL insert_solution(
'50df83144a56b04f52914fb7dc43c203e4',
'Solution 47 content',
'2013-05-09 06:05:06',
'username3',
'Solution 47 description',
'538c171b67b3e640b88c0a7fe51c3aafb6',
TRUE
);
CALL insert_solution(
'50c425d10ac4bd4126ba6b85fd931d9d80',
'Solution 48 content',
'2013-08-04 01:07:07',
'username5',
'Solution 48 description',
'5360533a762dde4eef8cb33f413752d34a',
TRUE
);
CALL insert_solution(
'508d01faf0db404ba28779854bdd3eb539',
'Solution 49 content',
'2013-06-06 03:08:04',
'username7',
'Solution 49 description',
'5311b850ad7dca4b20af3a0309019d1cb8',
TRUE
);
CALL insert_solution(
'50c425d10ac4bd4126ba6b85fd931d9d80',
'Solution 50 content',
'2013-09-08 06:01:08',
'username5',
'Solution 50 description',
'5373de77548fd44b92bf27365ffe6d8aff',
TRUE
);

CALL insert_clarification(
'5068b3560fe9a44b7cbef46cbcc487a701',
'username10',
'43aefb6722708c40c1982d4d85f3210e1d',
'Clarification 1 question'
);
CALL insert_clarification(
'531d2b0f29735244fbb82c56da1a130932',
'username3',
'43f9d3c08e4c7e497b8765d55349409457',
'Clarification 2 question'
);
CALL insert_clarification(
'531176a6564d794bb891aa73ee3cf7e939',
'username1',
'4332b4f6e55a974b06a9be1df23ef475d3',
'Clarification 3 question'
);
CALL insert_clarification(
'53b44dba190a9243a4b9500556cdeaba50',
'username2',
'434640dd6602a24d2c9a5ef84d0f8008cb',
'Clarification 4 question'
);
CALL insert_clarification(
'537739cd7c9a80482d92970655559be1f8',
'username6',
'4336adf252b3c74926b329430436276d1d',
'Clarification 5 question'
);
CALL insert_clarification(
'508d01faf0db404ba28779854bdd3eb539',
'username8',
'4307c2eb9ba5cd4abda6d30fec62d7f3ea',
'Clarification 6 question'
);
CALL insert_clarification(
'53dd16cd983af044d7811266efb78f853a',
'username9',
'43707d3481c30747e18294e68bc35404c4',
'Clarification 7 question'
);
CALL insert_clarification(
'53ca4729d4fc8e42c48b48311e07fb595d',
'username6',
'434cca3b98bbea47aba646bb06269b2168',
'Clarification 8 question'
);
CALL insert_clarification(
'534e9d41ee99fe43d4886f47e0438e29e7',
'username7',
'437418208c64b248fc8a0751dc5c72aa27',
'Clarification 9 question'
);
CALL insert_clarification(
'50f983e8977e514e558cdf6abd7e8ff55d',
'username4',
'4353ac5cdd19fe4371b521a06afa3d03a1',
'Clarification 10 question'
);

