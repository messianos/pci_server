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
'2012-05-05',
'username1',
'bc547750b92797f955b36112cc9bdd5cddf7d0862151d03a167ada8995aa24a9ad24610b36a68bc02da24141ee51670aea13ed6469099a4453f335cb239db5da'
);
CALL sign_up_user(
'1994-05-06',
'username2@domain.com',
'Mike',
'F',
'Perez',
'MDQ',
'2012-05-07',
'username2',
'92a891f888e79d1c2e8b82663c0f37cc6d61466c508ec62b8132588afe354712b20bb75429aa20aa3ab7cfcc58836c734306b43efd368080a2250831bf7f363f'
);
CALL sign_up_user(
'1996-08-08',
'username3@domain.com',
'John',
'F',
'Perez',
'NYC',
'2012-08-07',
'username3',
'2a64d6563d9729493f91bf5b143365c0a7bec4025e1fb0ae67e307a0c3bed1c28cfb259fc6be768ab0a962b1e2c9527c5f21a1090a9b9b2d956487eb97ad4209'
);
CALL sign_up_user(
'1998-07-05',
'username4@domain.com',
'Jose',
'M',
'Smith',
'BB',
'2012-07-03',
'username4',
'11961811bd4e11f23648afbd2d5c251d2784827147f1731be010adaf0ab38ae18e5567c6fd1bee50a4cd35fb544b3c594e7d677efa7ca01c2a2cb47f8fb12b17'
);
CALL sign_up_user(
'1998-02-02',
'username5@domain.com',
'Jose',
'M',
'Garcia',
'MDQ',
'2012-07-09',
'username5',
'39c6f5329e959b2af0deb0f8dacbcdf5418204f46baed50388f62b047c9223c66ff470031ecd653a49f6eff6fa876811e46f0c269390a8bf61f4f983729e1083'
);
CALL sign_up_user(
'1998-04-06',
'username6@domain.com',
'Mike',
'F',
'Perez',
'CABA',
'2012-07-05',
'username6',
'011324228a766d0d06e56bd4c61fa8bffa4bc1dd01eb6892f906ef93cb9ba3f4a4243fe40f3e54314115bf0c0eac80bc630ed4dccf7ba6f22b12d9261cca7daa'
);
CALL sign_up_user(
'1992-06-03',
'username7@domain.com',
'Jose',
'F',
'Smith',
'NYC',
'2012-03-08',
'username7',
'a7d785790aecb79a4a3bcd5197301ae76897f83a2424a9b84160ed12a5def47f66d5a88ce5e6032be7e0e91b912d92e1b64f97b1d13a5096eec097470dee7764'
);
CALL sign_up_user(
'1996-01-07',
'username8@domain.com',
'John',
'M',
'Doe',
'NYC',
'2012-09-03',
'username8',
'219aab6b2cf738d9f370e197ce0151be42ae6095e0d72fa49592865c9d2dde5d2fa72e908ac374cba55426e6d0ed39324fd6de1d5da2641cc7f4491f5edd931f'
);
CALL sign_up_user(
'1998-06-02',
'username9@domain.com',
'John',
'M',
'Perez',
'BB',
'2012-02-08',
'username9',
'26e261e3003a175c800a2c48f96972793676e8ab464d0e73da50b1c8d359ed4bac5ee660bfe3ee9a9362ad42ca3c9aa793ab4f707b163dfea4d89b64fae0a0b9'
);
CALL sign_up_user(
'1998-09-09',
'username10@domain.com',
'Juan',
'M',
'Doe',
'CABA',
'2012-08-01',
'username10',
'2ce5f635d25b791d37a92c99f0af6df02a68fa695b74f90685e7d93ed3f5a61a715168541954b4c2feec9fd39fcc4df74fef1b9211e12ca96dc03efba2e6a31e'
);

CALL insert_problem(
'Problem 1 content',
'2013-03-08 06:06:06',
'username6',
'Problem 1 description',
'504cf28395e7b948bf8887ee08ca791a1e',
FALSE
);
CALL insert_problem(
'Problem 2 content',
'2013-03-04 05:03:04',
'username10',
'Problem 2 description',
'50b5740ae39af846839e7929c3720ac9a6',
FALSE
);
CALL insert_problem(
'Problem 3 content',
'2013-06-08 02:07:08',
'username10',
'Problem 3 description',
'50c9b039a6ab874615bf4b66159b8dcba7',
FALSE
);
CALL insert_problem(
'Problem 4 content',
'2013-03-09 04:08:06',
'username5',
'Problem 4 description',
'50e309e9a00f2445c6a58d9bd1f3c23295',
FALSE
);
CALL insert_problem(
'Problem 5 content',
'2013-07-07 03:04:02',
'username7',
'Problem 5 description',
'50b8e974e9552d467fa83c9122cc0869af',
TRUE
);
CALL insert_problem(
'Problem 6 content',
'2013-01-01 04:01:09',
'username2',
'Problem 6 description',
'5074c0a2f7ecc74737992261014d3336ca',
FALSE
);
CALL insert_problem(
'Problem 7 content',
'2013-04-09 07:07:04',
'username8',
'Problem 7 description',
'50b8a925e280044b85832bbdfe9dd05846',
TRUE
);
CALL insert_problem(
'Problem 8 content',
'2013-03-03 02:05:07',
'username9',
'Problem 8 description',
'50d5e249eb9a1e4d33bd30feeaa574c4ad',
FALSE
);
CALL insert_problem(
'Problem 9 content',
'2013-07-05 05:06:06',
'username7',
'Problem 9 description',
'507f49bd2f90a64efd99efbde52bae5a71',
TRUE
);
CALL insert_problem(
'Problem 10 content',
'2013-01-02 01:03:05',
'username1',
'Problem 10 description',
'50090e16bef18542b3a8c11e5426554d46',
FALSE
);
CALL insert_problem(
'Problem 11 content',
'2013-02-03 04:07:02',
'username8',
'Problem 11 description',
'507bf5f0a3a747444b8ae72e2c9359ad80',
FALSE
);
CALL insert_problem(
'Problem 12 content',
'2013-06-08 07:02:03',
'username1',
'Problem 12 description',
'50be7fbdebb556456a8801bd957bfd750f',
TRUE
);
CALL insert_problem(
'Problem 13 content',
'2013-09-01 08:06:07',
'username6',
'Problem 13 description',
'50050630da404840059a25aebab550ac78',
FALSE
);
CALL insert_problem(
'Problem 14 content',
'2013-08-08 01:07:06',
'username7',
'Problem 14 description',
'50df40797af4a64aaeb6b0bdd48d6ae004',
TRUE
);
CALL insert_problem(
'Problem 15 content',
'2013-08-07 01:03:08',
'username10',
'Problem 15 description',
'5098fda307ad1d4fd4901ffc63235db33c',
FALSE
);
CALL insert_problem(
'Problem 16 content',
'2013-09-01 09:08:07',
'username4',
'Problem 16 description',
'50e238bf3c827748ffbd36b8b0d24e447c',
FALSE
);
CALL insert_problem(
'Problem 17 content',
'2013-05-01 06:09:06',
'username8',
'Problem 17 description',
'50252f776cf7914a049fe37ba41674214b',
TRUE
);
CALL insert_problem(
'Problem 18 content',
'2013-01-07 01:05:04',
'username10',
'Problem 18 description',
'50967913c05aea4e7dad54c9d1fb014326',
TRUE
);
CALL insert_problem(
'Problem 19 content',
'2013-03-04 04:03:08',
'username8',
'Problem 19 description',
'500bb11be701604f598061441b6a96b204',
FALSE
);
CALL insert_problem(
'Problem 20 content',
'2013-08-08 08:01:01',
'username10',
'Problem 20 description',
'50e66fb8ab0a6f473f8fcf628f05076517',
FALSE
);
CALL insert_problem(
'Problem 21 content',
'2013-05-02 02:08:08',
'username2',
'Problem 21 description',
'50db426f031ce0490e9c1305c26294d230',
TRUE
);
CALL insert_problem(
'Problem 22 content',
'2013-03-08 09:09:07',
'username6',
'Problem 22 description',
'50bdd7a351232045679b9b603c16300439',
FALSE
);
CALL insert_problem(
'Problem 23 content',
'2013-08-08 09:08:03',
'username2',
'Problem 23 description',
'508176952d42af41a08d9e58a362f3f1ec',
FALSE
);
CALL insert_problem(
'Problem 24 content',
'2013-09-09 01:09:09',
'username6',
'Problem 24 description',
'501d32237a8c7b4f359d38b4df287a6109',
FALSE
);
CALL insert_problem(
'Problem 25 content',
'2013-01-04 08:02:08',
'username7',
'Problem 25 description',
'50791ea70e24d5412989e43a4c5102487d',
TRUE
);
CALL insert_problem(
'Problem 26 content',
'2013-04-01 04:05:03',
'username3',
'Problem 26 description',
'5059014ec5593848718000dd4200ec8394',
TRUE
);
CALL insert_problem(
'Problem 27 content',
'2013-04-06 02:07:04',
'username7',
'Problem 27 description',
'50d8a0f197b8de4965a792333ae019b52c',
FALSE
);
CALL insert_problem(
'Problem 28 content',
'2013-07-08 04:08:09',
'username2',
'Problem 28 description',
'508cfe706c998e4d79b16b0987d46f9bc3',
FALSE
);
CALL insert_problem(
'Problem 29 content',
'2013-03-01 08:03:05',
'username4',
'Problem 29 description',
'502f9aae96f36542f89ca3e17112efdb9c',
FALSE
);
CALL insert_problem(
'Problem 30 content',
'2013-08-03 06:04:03',
'username6',
'Problem 30 description',
'5040cc5fad2223401f9f9d40029401583b',
FALSE
);

CALL insert_solution(
'50791ea70e24d5412989e43a4c5102487d',
'Solution 1 content',
'2013-01-09 04:02:05',
'username3',
'Solution 1 description',
'53ff7e53a80e694ef787df2f5733d464f4',
TRUE
);
CALL insert_solution(
'508176952d42af41a08d9e58a362f3f1ec',
'Solution 2 content',
'2013-08-03 07:03:09',
'username4',
'Solution 2 description',
'537abca51bfbfa41e0a3ed474c12b84f4e',
TRUE
);
CALL insert_solution(
'50e309e9a00f2445c6a58d9bd1f3c23295',
'Solution 3 content',
'2013-09-07 03:07:09',
'username8',
'Solution 3 description',
'53e8ead19fd2bb45638055042ff7b5ae2d',
TRUE
);
CALL insert_solution(
'5074c0a2f7ecc74737992261014d3336ca',
'Solution 4 content',
'2013-01-09 03:04:03',
'username8',
'Solution 4 description',
'533516bc5d15d247f38c77987b0bdcca10',
TRUE
);
CALL insert_solution(
'5074c0a2f7ecc74737992261014d3336ca',
'Solution 5 content',
'2013-08-03 02:01:02',
'username9',
'Solution 5 description',
'539e344b442e64493796fa6303db0d90ec',
FALSE
);
CALL insert_solution(
'50b5740ae39af846839e7929c3720ac9a6',
'Solution 6 content',
'2013-03-01 08:01:03',
'username6',
'Solution 6 description',
'53ed64af1d4382407fa488fcd88cf29bd5',
TRUE
);
CALL insert_solution(
'507f49bd2f90a64efd99efbde52bae5a71',
'Solution 7 content',
'2013-04-07 06:07:01',
'username6',
'Solution 7 description',
'530df5e9a4fd924a97bcd3e2ae260c978e',
FALSE
);
CALL insert_solution(
'50e309e9a00f2445c6a58d9bd1f3c23295',
'Solution 8 content',
'2013-07-05 03:05:07',
'username4',
'Solution 8 description',
'534685bc32ed9f44beacffd77d6a4e0e01',
FALSE
);
CALL insert_solution(
'50d8a0f197b8de4965a792333ae019b52c',
'Solution 9 content',
'2013-02-06 02:09:01',
'username7',
'Solution 9 description',
'53e8d0c0827f5242c0a1031c3ae1217dc0',
FALSE
);
CALL insert_solution(
'508cfe706c998e4d79b16b0987d46f9bc3',
'Solution 10 content',
'2013-03-04 02:01:01',
'username6',
'Solution 10 description',
'53c6ac2480d0b44b0d99b8ea9223162cfd',
TRUE
);
CALL insert_solution(
'500bb11be701604f598061441b6a96b204',
'Solution 11 content',
'2013-08-02 06:07:01',
'username2',
'Solution 11 description',
'53e9551caedad745999a91ee9ad118ac66',
TRUE
);
CALL insert_solution(
'5098fda307ad1d4fd4901ffc63235db33c',
'Solution 12 content',
'2013-04-02 01:06:05',
'username3',
'Solution 12 description',
'53ff6413c9715d47cba8a07cb7929d8c5a',
TRUE
);
CALL insert_solution(
'507bf5f0a3a747444b8ae72e2c9359ad80',
'Solution 13 content',
'2013-02-04 07:09:03',
'username5',
'Solution 13 description',
'536a2a00558fa7437c84a8244452e58432',
FALSE
);
CALL insert_solution(
'50050630da404840059a25aebab550ac78',
'Solution 14 content',
'2013-01-07 04:06:07',
'username5',
'Solution 14 description',
'53897ba524ca8a4929ad4a1069050c7c11',
TRUE
);
CALL insert_solution(
'50e309e9a00f2445c6a58d9bd1f3c23295',
'Solution 15 content',
'2013-02-05 03:04:06',
'username3',
'Solution 15 description',
'538a5f99deb245407186c018ef84ea37b7',
TRUE
);
CALL insert_solution(
'50e309e9a00f2445c6a58d9bd1f3c23295',
'Solution 16 content',
'2013-02-03 05:08:09',
'username3',
'Solution 16 description',
'5382860703bd4b40e7bc2d7bb65b7e7eeb',
TRUE
);
CALL insert_solution(
'50e238bf3c827748ffbd36b8b0d24e447c',
'Solution 17 content',
'2013-08-01 07:09:01',
'username7',
'Solution 17 description',
'53b5937e55ac1b45618698de49f8def16b',
FALSE
);
CALL insert_solution(
'502f9aae96f36542f89ca3e17112efdb9c',
'Solution 18 content',
'2013-03-06 02:02:06',
'username10',
'Solution 18 description',
'5395a9202a10354cbea8efe79f260240f6',
TRUE
);
CALL insert_solution(
'50d8a0f197b8de4965a792333ae019b52c',
'Solution 19 content',
'2013-07-07 04:04:08',
'username9',
'Solution 19 description',
'53e9154b776cd9415b9524effa83467367',
FALSE
);
CALL insert_solution(
'50b8a925e280044b85832bbdfe9dd05846',
'Solution 20 content',
'2013-07-09 07:06:07',
'username10',
'Solution 20 description',
'53f3741e9efedc458c93537bcb904e1fe1',
TRUE
);
CALL insert_solution(
'504cf28395e7b948bf8887ee08ca791a1e',
'Solution 21 content',
'2013-07-04 05:08:08',
'username9',
'Solution 21 description',
'53f3d99519fd5f4ef5b4fce34ed938eece',
FALSE
);
CALL insert_solution(
'50e309e9a00f2445c6a58d9bd1f3c23295',
'Solution 22 content',
'2013-01-09 04:05:06',
'username8',
'Solution 22 description',
'53bb43411204cd4faeb609114fa5c8f4ff',
FALSE
);
CALL insert_solution(
'50df40797af4a64aaeb6b0bdd48d6ae004',
'Solution 23 content',
'2013-08-09 06:09:02',
'username6',
'Solution 23 description',
'5385509e6a640e464c9f798c4cd9a116df',
TRUE
);
CALL insert_solution(
'50e66fb8ab0a6f473f8fcf628f05076517',
'Solution 24 content',
'2013-07-04 04:08:09',
'username8',
'Solution 24 description',
'53289e3b56d45343fa8b6947f7b278d9a9',
TRUE
);
CALL insert_solution(
'50be7fbdebb556456a8801bd957bfd750f',
'Solution 25 content',
'2013-09-09 06:04:05',
'username2',
'Solution 25 description',
'5324efb59d6cb0451ea89872ef556175fd',
FALSE
);
CALL insert_solution(
'5074c0a2f7ecc74737992261014d3336ca',
'Solution 26 content',
'2013-02-05 02:04:05',
'username2',
'Solution 26 description',
'531e040ce1c68e4e2f9379a2e0e0e24d3c',
FALSE
);
CALL insert_solution(
'508176952d42af41a08d9e58a362f3f1ec',
'Solution 27 content',
'2013-08-02 08:04:04',
'username9',
'Solution 27 description',
'537b511b1aad1741218ed4d4e5f8caa438',
FALSE
);
CALL insert_solution(
'50e66fb8ab0a6f473f8fcf628f05076517',
'Solution 28 content',
'2013-05-05 07:08:07',
'username8',
'Solution 28 description',
'534e2fe8acd71a448fa05a1f893761505e',
FALSE
);
CALL insert_solution(
'508cfe706c998e4d79b16b0987d46f9bc3',
'Solution 29 content',
'2013-08-04 07:09:07',
'username1',
'Solution 29 description',
'53616bba532c0f49bdb295d4e9e07942d0',
TRUE
);
CALL insert_solution(
'50bdd7a351232045679b9b603c16300439',
'Solution 30 content',
'2013-04-08 03:08:08',
'username4',
'Solution 30 description',
'5315d1a31f9c204dde8d5b2b5a8e58694b',
TRUE
);
CALL insert_solution(
'50252f776cf7914a049fe37ba41674214b',
'Solution 31 content',
'2013-04-01 07:05:05',
'username10',
'Solution 31 description',
'53bf6da7b7b8394fdf91c0b6b4fc3937e3',
FALSE
);
CALL insert_solution(
'504cf28395e7b948bf8887ee08ca791a1e',
'Solution 32 content',
'2013-06-03 03:01:09',
'username9',
'Solution 32 description',
'53fa3af9e661f246ae86a357110ec86ba2',
TRUE
);
CALL insert_solution(
'50bdd7a351232045679b9b603c16300439',
'Solution 33 content',
'2013-06-03 05:02:07',
'username1',
'Solution 33 description',
'53152884f3b38541b39d41b4d63d93eab3',
FALSE
);
CALL insert_solution(
'501d32237a8c7b4f359d38b4df287a6109',
'Solution 34 content',
'2013-07-08 01:06:07',
'username8',
'Solution 34 description',
'53776eaaf9c5f34db98df9369ab1dbe314',
FALSE
);
CALL insert_solution(
'50b8a925e280044b85832bbdfe9dd05846',
'Solution 35 content',
'2013-09-01 01:08:09',
'username9',
'Solution 35 description',
'53daa670fb469a453ba491f3f98a4eb512',
FALSE
);
CALL insert_solution(
'507f49bd2f90a64efd99efbde52bae5a71',
'Solution 36 content',
'2013-07-07 06:02:04',
'username7',
'Solution 36 description',
'5366ef62696e804b54a7cbc037c666ad76',
FALSE
);
CALL insert_solution(
'508176952d42af41a08d9e58a362f3f1ec',
'Solution 37 content',
'2013-04-09 04:03:05',
'username7',
'Solution 37 description',
'5399a2e93dd23144a8b547c6739fd59612',
TRUE
);
CALL insert_solution(
'50d5e249eb9a1e4d33bd30feeaa574c4ad',
'Solution 38 content',
'2013-06-06 07:02:09',
'username6',
'Solution 38 description',
'53c11c847cfe8a4e68a724b9ac6bfdd2e1',
TRUE
);
CALL insert_solution(
'5074c0a2f7ecc74737992261014d3336ca',
'Solution 39 content',
'2013-06-05 03:05:08',
'username4',
'Solution 39 description',
'536f240c6c48e249aab42420bc12424265',
TRUE
);
CALL insert_solution(
'508cfe706c998e4d79b16b0987d46f9bc3',
'Solution 40 content',
'2013-06-08 07:05:02',
'username6',
'Solution 40 description',
'5383ea0888b2944f699db310b7728a8d76',
FALSE
);
CALL insert_solution(
'50df40797af4a64aaeb6b0bdd48d6ae004',
'Solution 41 content',
'2013-06-06 07:02:05',
'username5',
'Solution 41 description',
'538d890f21dc72487984cb75860ba2802a',
FALSE
);
CALL insert_solution(
'50b8e974e9552d467fa83c9122cc0869af',
'Solution 42 content',
'2013-09-01 09:09:07',
'username2',
'Solution 42 description',
'5327994623671d46139362aaaaae8fc31d',
TRUE
);
CALL insert_solution(
'508176952d42af41a08d9e58a362f3f1ec',
'Solution 43 content',
'2013-06-02 07:05:05',
'username3',
'Solution 43 description',
'533591de30a8f5446eb997f8f7dd0839cf',
FALSE
);
CALL insert_solution(
'508cfe706c998e4d79b16b0987d46f9bc3',
'Solution 44 content',
'2013-07-01 04:06:07',
'username5',
'Solution 44 description',
'53adb3a16b4de24fdd86a193c883eed87c',
TRUE
);
CALL insert_solution(
'50df40797af4a64aaeb6b0bdd48d6ae004',
'Solution 45 content',
'2013-03-06 06:06:02',
'username9',
'Solution 45 description',
'537bf09530c9d943d78b14aa4b2dcc13ad',
FALSE
);
CALL insert_solution(
'50db426f031ce0490e9c1305c26294d230',
'Solution 46 content',
'2013-01-06 08:09:07',
'username3',
'Solution 46 description',
'536d8f05dd31f0427da7795718d4ab26fa',
FALSE
);
CALL insert_solution(
'50b5740ae39af846839e7929c3720ac9a6',
'Solution 47 content',
'2013-05-09 06:05:06',
'username3',
'Solution 47 description',
'53c01d1721d5704c3196f45344a91e42ae',
TRUE
);
CALL insert_solution(
'50d8a0f197b8de4965a792333ae019b52c',
'Solution 48 content',
'2013-08-04 01:07:07',
'username5',
'Solution 48 description',
'53da72b3939a6e49eb82a30b4971a750e3',
TRUE
);
CALL insert_solution(
'50e238bf3c827748ffbd36b8b0d24e447c',
'Solution 49 content',
'2013-06-06 03:08:04',
'username7',
'Solution 49 description',
'538c2c78f0017a4e00852abfa8d7863ec1',
TRUE
);
CALL insert_solution(
'50d8a0f197b8de4965a792333ae019b52c',
'Solution 50 content',
'2013-09-08 06:01:08',
'username5',
'Solution 50 description',
'5383935be16c2f4349861816dbfc2bdaf4',
TRUE
);

CALL insert_clarification(
'501d32237a8c7b4f359d38b4df287a6109',
'username10',
'434c556b7f72be4d2bbff43dd1dd88188c',
'Clarification 1 question'
);
CALL insert_clarification(
'5366ef62696e804b54a7cbc037c666ad76',
'username3',
'432f8980dd18514836b34f6b0bdc669a27',
'Clarification 2 question'
);
CALL insert_clarification(
'53adb3a16b4de24fdd86a193c883eed87c',
'username1',
'4354ccae466f80438e8c0dfe1c32b84596',
'Clarification 3 question'
);
CALL insert_clarification(
'53c6ac2480d0b44b0d99b8ea9223162cfd',
'username2',
'43ea4e62d9d304468794151b2145cdeba9',
'Clarification 4 question'
);
CALL insert_clarification(
'538a5f99deb245407186c018ef84ea37b7',
'username6',
'43e924a4977fe848948640447b1570aa1a',
'Clarification 5 question'
);
CALL insert_clarification(
'50e238bf3c827748ffbd36b8b0d24e447c',
'username8',
'431e7ee9bcd2524506b80bdfca141b9815',
'Clarification 6 question'
);
CALL insert_clarification(
'53776eaaf9c5f34db98df9369ab1dbe314',
'username9',
'43316f205427474f469bb78385f46a19dd',
'Clarification 7 question'
);
CALL insert_clarification(
'53ed64af1d4382407fa488fcd88cf29bd5',
'username6',
'4341619431d73c4ba59d1dffe8619552c9',
'Clarification 8 question'
);
CALL insert_clarification(
'53e9154b776cd9415b9524effa83467367',
'username7',
'43b26bf9841d574e98971abd297769bab8',
'Clarification 9 question'
);
CALL insert_clarification(
'50e309e9a00f2445c6a58d9bd1f3c23295',
'username4',
'43329c8c17affa437481c503c1150453c9',
'Clarification 10 question'
);

