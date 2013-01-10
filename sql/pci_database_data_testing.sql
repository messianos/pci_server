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
'username1',
'bc547750b92797f955b36112cc9bdd5cddf7d0862151d03a167ada8995aa24a9ad24610b36a68bc02da24141ee51670aea13ed6469099a4453f335cb239db5da'
);
CALL sign_up_user(
'1991-05-05',
'username2@domain.com',
'Juan',
'M',
'Doe',
'BB',
'username2',
'92a891f888e79d1c2e8b82663c0f37cc6d61466c508ec62b8132588afe354712b20bb75429aa20aa3ab7cfcc58836c734306b43efd368080a2250831bf7f363f'
);
CALL sign_up_user(
'1999-07-03',
'username3@domain.com',
'John',
'M',
'Perez',
'MDQ',
'username3',
'2a64d6563d9729493f91bf5b143365c0a7bec4025e1fb0ae67e307a0c3bed1c28cfb259fc6be768ab0a962b1e2c9527c5f21a1090a9b9b2d956487eb97ad4209'
);
CALL sign_up_user(
'1992-08-03',
'username4@domain.com',
'John',
'M',
'Doe',
'NYC',
'username4',
'11961811bd4e11f23648afbd2d5c251d2784827147f1731be010adaf0ab38ae18e5567c6fd1bee50a4cd35fb544b3c594e7d677efa7ca01c2a2cb47f8fb12b17'
);
CALL sign_up_user(
'1998-07-07',
'username5@domain.com',
'John',
'M',
'Doe',
'NYC',
'username5',
'39c6f5329e959b2af0deb0f8dacbcdf5418204f46baed50388f62b047c9223c66ff470031ecd653a49f6eff6fa876811e46f0c269390a8bf61f4f983729e1083'
);
CALL sign_up_user(
'1993-02-07',
'username6@domain.com',
'John',
'M',
'Perez',
'CABA',
'username6',
'011324228a766d0d06e56bd4c61fa8bffa4bc1dd01eb6892f906ef93cb9ba3f4a4243fe40f3e54314115bf0c0eac80bc630ed4dccf7ba6f22b12d9261cca7daa'
);
CALL sign_up_user(
'1999-09-04',
'username7@domain.com',
'John',
'M',
'Smith',
'BB',
'username7',
'a7d785790aecb79a4a3bcd5197301ae76897f83a2424a9b84160ed12a5def47f66d5a88ce5e6032be7e0e91b912d92e1b64f97b1d13a5096eec097470dee7764'
);
CALL sign_up_user(
'1993-02-03',
'username8@domain.com',
'Mike',
'F',
'Doe',
'BB',
'username8',
'219aab6b2cf738d9f370e197ce0151be42ae6095e0d72fa49592865c9d2dde5d2fa72e908ac374cba55426e6d0ed39324fd6de1d5da2641cc7f4491f5edd931f'
);
CALL sign_up_user(
'1995-01-05',
'username9@domain.com',
'John',
'M',
'Garcia',
'NYC',
'username9',
'26e261e3003a175c800a2c48f96972793676e8ab464d0e73da50b1c8d359ed4bac5ee660bfe3ee9a9362ad42ca3c9aa793ab4f707b163dfea4d89b64fae0a0b9'
);
CALL sign_up_user(
'1996-01-07',
'username10@domain.com',
'John',
'M',
'Doe',
'NYC',
'username10',
'2ce5f635d25b791d37a92c99f0af6df02a68fa695b74f90685e7d93ed3f5a61a715168541954b4c2feec9fd39fcc4df74fef1b9211e12ca96dc03efba2e6a31e'
);

CALL insert_problem(
'Problem 1 content',
'username5',
'Problem 1 description',
'504a9f056e73ae49c8b766f5a5c7fd403a',
TRUE
);
CALL insert_problem(
'Problem 2 content',
'username8',
'Problem 2 description',
'5052439a518b644f0aa6af649183ae8539',
TRUE
);
CALL insert_problem(
'Problem 3 content',
'username9',
'Problem 3 description',
'504180b6ea80eb4a39a425e0c195a21f67',
TRUE
);
CALL insert_problem(
'Problem 4 content',
'username3',
'Problem 4 description',
'50274419b222ac4ee787471f5492878f8b',
TRUE
);
CALL insert_problem(
'Problem 5 content',
'username8',
'Problem 5 description',
'508e6af3a869b14972aa0aa61a4e1f2f6f',
FALSE
);
CALL insert_problem(
'Problem 6 content',
'username4',
'Problem 6 description',
'509dd66ebaaf8745a6a5768ba840e747df',
FALSE
);
CALL insert_problem(
'Problem 7 content',
'username3',
'Problem 7 description',
'508a49960a74224b358d2ffd4e36ca02be',
TRUE
);
CALL insert_problem(
'Problem 8 content',
'username4',
'Problem 8 description',
'50cda5ad88d8534afd8f103fa4189f306d',
TRUE
);
CALL insert_problem(
'Problem 9 content',
'username2',
'Problem 9 description',
'50ab220729e0d84a2ca8a4ba2f40b6b9a4',
FALSE
);
CALL insert_problem(
'Problem 10 content',
'username9',
'Problem 10 description',
'50aa6363b8c4014adeb2359279e3709967',
FALSE
);
CALL insert_problem(
'Problem 11 content',
'username2',
'Problem 11 description',
'50548d212d18784055a36c99a206ca2620',
FALSE
);
CALL insert_problem(
'Problem 12 content',
'username5',
'Problem 12 description',
'5033a49a3224d6455ab4e40a19e240ca5e',
FALSE
);
CALL insert_problem(
'Problem 13 content',
'username3',
'Problem 13 description',
'505bd58abdcde540d5b31f8ef6218b85ef',
FALSE
);
CALL insert_problem(
'Problem 14 content',
'username8',
'Problem 14 description',
'507110cdfa5a214d6dbaa8f95cad57d821',
TRUE
);
CALL insert_problem(
'Problem 15 content',
'username10',
'Problem 15 description',
'505ab93b8576db46cf9a298d5dd2002030',
FALSE
);
CALL insert_problem(
'Problem 16 content',
'username5',
'Problem 16 description',
'50752d456d11a847b3b5e091bfd1811999',
FALSE
);
CALL insert_problem(
'Problem 17 content',
'username10',
'Problem 17 description',
'50dc1a3ec383ea4a29a24dcda1faf681db',
FALSE
);
CALL insert_problem(
'Problem 18 content',
'username6',
'Problem 18 description',
'500ddeedc2114141bbb9d8823a244a4c6b',
FALSE
);
CALL insert_problem(
'Problem 19 content',
'username1',
'Problem 19 description',
'5011a0f1cb7cc04af09e0fbe1f4dd2cbe8',
TRUE
);
CALL insert_problem(
'Problem 20 content',
'username2',
'Problem 20 description',
'502f5b07cca98247d0958c5f77dfca33e0',
FALSE
);
CALL insert_problem(
'Problem 21 content',
'username10',
'Problem 21 description',
'509aaf53b57a5240e092dedab799cb85d8',
FALSE
);
CALL insert_problem(
'Problem 22 content',
'username9',
'Problem 22 description',
'50d8a68ef1f2494719ba3c2a5cf6c8b68e',
TRUE
);
CALL insert_problem(
'Problem 23 content',
'username6',
'Problem 23 description',
'50061d05d1bebc4a7a962f0753967e4e2f',
FALSE
);
CALL insert_problem(
'Problem 24 content',
'username5',
'Problem 24 description',
'504e8ab7f4454e42739db174955f1338ff',
FALSE
);
CALL insert_problem(
'Problem 25 content',
'username1',
'Problem 25 description',
'50a4a5865afb984ecf8cd7371dfd6bdd81',
TRUE
);
CALL insert_problem(
'Problem 26 content',
'username1',
'Problem 26 description',
'503749390cf2a7441a9de3489d37729a0b',
FALSE
);
CALL insert_problem(
'Problem 27 content',
'username10',
'Problem 27 description',
'506bdea21672ab45159de84cef638966bc',
TRUE
);
CALL insert_problem(
'Problem 28 content',
'username3',
'Problem 28 description',
'508173a2b3e65f4969b9f2dc14ea376b24',
FALSE
);
CALL insert_problem(
'Problem 29 content',
'username3',
'Problem 29 description',
'501fa070b449e4494496d7b457539e0fae',
TRUE
);
CALL insert_problem(
'Problem 30 content',
'username8',
'Problem 30 description',
'509b694d324349482b9313a7cd60b25262',
FALSE
);

CALL insert_solution(
'5033a49a3224d6455ab4e40a19e240ca5e',
'Solution 1 content',
'username2',
'Solution 1 description',
'539ce2703632ae40c99cc24350142f6cfd',
FALSE
);
CALL insert_solution(
'504a9f056e73ae49c8b766f5a5c7fd403a',
'Solution 2 content',
'username6',
'Solution 2 description',
'538cebc0ee01014593976f63ab127030f0',
TRUE
);
CALL insert_solution(
'508173a2b3e65f4969b9f2dc14ea376b24',
'Solution 3 content',
'username8',
'Solution 3 description',
'535a4177eb26d0402895ef17464d55eed7',
TRUE
);
CALL insert_solution(
'504a9f056e73ae49c8b766f5a5c7fd403a',
'Solution 4 content',
'username7',
'Solution 4 description',
'5318e18aa33d184138ab0c5e21fd76923d',
TRUE
);
CALL insert_solution(
'500ddeedc2114141bbb9d8823a244a4c6b',
'Solution 5 content',
'username5',
'Solution 5 description',
'530e3c8ca48e714a769c9ba63e658b53ab',
TRUE
);
CALL insert_solution(
'50752d456d11a847b3b5e091bfd1811999',
'Solution 6 content',
'username9',
'Solution 6 description',
'53a393f2bf049244ec9031947321c19527',
TRUE
);
CALL insert_solution(
'50dc1a3ec383ea4a29a24dcda1faf681db',
'Solution 7 content',
'username1',
'Solution 7 description',
'531d384d9284cd4958bf5e35bd76436fcb',
TRUE
);
CALL insert_solution(
'508a49960a74224b358d2ffd4e36ca02be',
'Solution 8 content',
'username5',
'Solution 8 description',
'5328fc99d6de834ddca0340dea50388a9a',
TRUE
);
CALL insert_solution(
'504180b6ea80eb4a39a425e0c195a21f67',
'Solution 9 content',
'username9',
'Solution 9 description',
'5369e142baa6854e5092f75097aec6272d',
FALSE
);
CALL insert_solution(
'508a49960a74224b358d2ffd4e36ca02be',
'Solution 10 content',
'username1',
'Solution 10 description',
'5360233801a4684d41b9b288d9c00d96e2',
FALSE
);
CALL insert_solution(
'50548d212d18784055a36c99a206ca2620',
'Solution 11 content',
'username2',
'Solution 11 description',
'53b2983617577643038dab9c5b831657d3',
TRUE
);
CALL insert_solution(
'5033a49a3224d6455ab4e40a19e240ca5e',
'Solution 12 content',
'username4',
'Solution 12 description',
'53242d13c30586461081ca3f539c6522ed',
FALSE
);
CALL insert_solution(
'50cda5ad88d8534afd8f103fa4189f306d',
'Solution 13 content',
'username3',
'Solution 13 description',
'53c7ed106340b74a7ea7e754b064de2092',
TRUE
);
CALL insert_solution(
'50a4a5865afb984ecf8cd7371dfd6bdd81',
'Solution 14 content',
'username6',
'Solution 14 description',
'53c909164471e34b0b8ce8571a0dca5c18',
TRUE
);
CALL insert_solution(
'509aaf53b57a5240e092dedab799cb85d8',
'Solution 15 content',
'username3',
'Solution 15 description',
'534f3f3aa96114471c94038879a973dcab',
FALSE
);
CALL insert_solution(
'509aaf53b57a5240e092dedab799cb85d8',
'Solution 16 content',
'username10',
'Solution 16 description',
'534f013261b3294355af4ed102a3fad314',
FALSE
);
CALL insert_solution(
'505ab93b8576db46cf9a298d5dd2002030',
'Solution 17 content',
'username6',
'Solution 17 description',
'53707c01816a75436f84525f9302397394',
FALSE
);
CALL insert_solution(
'509aaf53b57a5240e092dedab799cb85d8',
'Solution 18 content',
'username4',
'Solution 18 description',
'537a4950640d204549b0dae8f02cc35ee5',
FALSE
);
CALL insert_solution(
'501fa070b449e4494496d7b457539e0fae',
'Solution 19 content',
'username9',
'Solution 19 description',
'535e048d77c2d5458e86751da91347da46',
TRUE
);
CALL insert_solution(
'50548d212d18784055a36c99a206ca2620',
'Solution 20 content',
'username5',
'Solution 20 description',
'537b4f045a5aab499ebc64dd97f55cd1e7',
TRUE
);
CALL insert_solution(
'508173a2b3e65f4969b9f2dc14ea376b24',
'Solution 21 content',
'username7',
'Solution 21 description',
'53f2d8545fb0774ba59dea670a62e058ee',
TRUE
);
CALL insert_solution(
'502f5b07cca98247d0958c5f77dfca33e0',
'Solution 22 content',
'username8',
'Solution 22 description',
'53126e41c6127741d698ddb8a2fcd446eb',
FALSE
);
CALL insert_solution(
'502f5b07cca98247d0958c5f77dfca33e0',
'Solution 23 content',
'username8',
'Solution 23 description',
'53187bbe7cfd8847edac048faea9b6f52b',
TRUE
);
CALL insert_solution(
'509dd66ebaaf8745a6a5768ba840e747df',
'Solution 24 content',
'username4',
'Solution 24 description',
'53c616196295f3486bab3fd89a317b929d',
FALSE
);
CALL insert_solution(
'50ab220729e0d84a2ca8a4ba2f40b6b9a4',
'Solution 25 content',
'username4',
'Solution 25 description',
'53f444eaa91b724bb4aaef70a43b1bafb2',
FALSE
);
CALL insert_solution(
'50aa6363b8c4014adeb2359279e3709967',
'Solution 26 content',
'username4',
'Solution 26 description',
'53315c04c48aee489e8b9338d8d0b79f70',
FALSE
);
CALL insert_solution(
'5011a0f1cb7cc04af09e0fbe1f4dd2cbe8',
'Solution 27 content',
'username8',
'Solution 27 description',
'5334f791a55aa44463a2dc900bc5be39d9',
TRUE
);
CALL insert_solution(
'50d8a68ef1f2494719ba3c2a5cf6c8b68e',
'Solution 28 content',
'username10',
'Solution 28 description',
'53ee6b3ce15a814943b23b2190b693fff0',
TRUE
);
CALL insert_solution(
'502f5b07cca98247d0958c5f77dfca33e0',
'Solution 29 content',
'username9',
'Solution 29 description',
'533b46c2d002834071a7584fda7786af21',
TRUE
);
CALL insert_solution(
'509dd66ebaaf8745a6a5768ba840e747df',
'Solution 30 content',
'username9',
'Solution 30 description',
'53bcf1d410826b4737b405b54826025a6f',
TRUE
);
CALL insert_solution(
'504e8ab7f4454e42739db174955f1338ff',
'Solution 31 content',
'username8',
'Solution 31 description',
'53cad2843b1e8e4b2b8aa3aeb56400b217',
FALSE
);
CALL insert_solution(
'50274419b222ac4ee787471f5492878f8b',
'Solution 32 content',
'username9',
'Solution 32 description',
'53b85555437df041298a254bcaff6245ce',
TRUE
);
CALL insert_solution(
'502f5b07cca98247d0958c5f77dfca33e0',
'Solution 33 content',
'username8',
'Solution 33 description',
'53ba2a0881955243f3ba2b202916d42668',
FALSE
);
CALL insert_solution(
'509b694d324349482b9313a7cd60b25262',
'Solution 34 content',
'username4',
'Solution 34 description',
'5377aa5277d0dd4e0290ff47356a3063e2',
TRUE
);
CALL insert_solution(
'508e6af3a869b14972aa0aa61a4e1f2f6f',
'Solution 35 content',
'username4',
'Solution 35 description',
'5324bb63ba66ec4594a1ae2da683885b28',
FALSE
);
CALL insert_solution(
'50d8a68ef1f2494719ba3c2a5cf6c8b68e',
'Solution 36 content',
'username3',
'Solution 36 description',
'530ada5de135604da4abf58846838d508f',
TRUE
);
CALL insert_solution(
'509aaf53b57a5240e092dedab799cb85d8',
'Solution 37 content',
'username3',
'Solution 37 description',
'53106da2f07c4649c690b36c3485671069',
FALSE
);
CALL insert_solution(
'500ddeedc2114141bbb9d8823a244a4c6b',
'Solution 38 content',
'username6',
'Solution 38 description',
'53a5f3fcb96d644dbabb043cdce0eb55f8',
FALSE
);
CALL insert_solution(
'500ddeedc2114141bbb9d8823a244a4c6b',
'Solution 39 content',
'username5',
'Solution 39 description',
'53b159a7e85c884e8c83f24747c1ee44b7',
FALSE
);
CALL insert_solution(
'50cda5ad88d8534afd8f103fa4189f306d',
'Solution 40 content',
'username2',
'Solution 40 description',
'53bedcddf8c173447da3bd70d688aa6c69',
FALSE
);
CALL insert_solution(
'5052439a518b644f0aa6af649183ae8539',
'Solution 41 content',
'username8',
'Solution 41 description',
'5325a39ebcb38b49ce80c469baf4d19a35',
TRUE
);
CALL insert_solution(
'50a4a5865afb984ecf8cd7371dfd6bdd81',
'Solution 42 content',
'username1',
'Solution 42 description',
'53ea45294a171248d6a0672b6b7086bc86',
TRUE
);
CALL insert_solution(
'509dd66ebaaf8745a6a5768ba840e747df',
'Solution 43 content',
'username2',
'Solution 43 description',
'53c420f2fd12f5484b92bee75be2bea3b4',
TRUE
);
CALL insert_solution(
'50dc1a3ec383ea4a29a24dcda1faf681db',
'Solution 44 content',
'username3',
'Solution 44 description',
'53a2d90cf4d4774ec38feb83fb2fc2a49a',
FALSE
);
CALL insert_solution(
'50aa6363b8c4014adeb2359279e3709967',
'Solution 45 content',
'username7',
'Solution 45 description',
'538242e82eeede40a9b90a8d9e4333db6e',
TRUE
);
CALL insert_solution(
'50ab220729e0d84a2ca8a4ba2f40b6b9a4',
'Solution 46 content',
'username1',
'Solution 46 description',
'53696a08876275476f9e90f236ea8daa34',
TRUE
);
CALL insert_solution(
'50d8a68ef1f2494719ba3c2a5cf6c8b68e',
'Solution 47 content',
'username1',
'Solution 47 description',
'53c38673e6640d4448a7dd97168aeb6d0d',
TRUE
);
CALL insert_solution(
'50061d05d1bebc4a7a962f0753967e4e2f',
'Solution 48 content',
'username10',
'Solution 48 description',
'53322f3bb37fcd4ab6a66acf962b9f89df',
FALSE
);
CALL insert_solution(
'503749390cf2a7441a9de3489d37729a0b',
'Solution 49 content',
'username7',
'Solution 49 description',
'531961b5b5fa40447dbbc36b7128f6a321',
TRUE
);
CALL insert_solution(
'508a49960a74224b358d2ffd4e36ca02be',
'Solution 50 content',
'username4',
'Solution 50 description',
'534947b2939e214f3593293f87d6621a1d',
FALSE
);

CALL insert_clarification(
'5328fc99d6de834ddca0340dea50388a9a',
'username5',
'43713879e3467343989e21adb64c05bb12',
'Clarification 1 question'
);
CALL insert_clarification(
'53242d13c30586461081ca3f539c6522ed',
'username8',
'4359dfe4cbc77c40c7a81334385b699771',
'Clarification 2 question'
);
CALL insert_clarification(
'506bdea21672ab45159de84cef638966bc',
'username1',
'431077b5dd4cb74640bf0b99c5111ae206',
'Clarification 3 question'
);
CALL insert_clarification(
'509dd66ebaaf8745a6a5768ba840e747df',
'username4',
'436171bddb84c8431a867495882178c0b0',
'Clarification 4 question'
);
CALL insert_clarification(
'538242e82eeede40a9b90a8d9e4333db6e',
'username2',
'436307b91e32e443be9f72fad79e7ae87a',
'Clarification 5 question'
);
CALL insert_clarification(
'5324bb63ba66ec4594a1ae2da683885b28',
'username2',
'4304a954951a12445f86391cbdbe599991',
'Clarification 6 question'
);
CALL insert_clarification(
'53a393f2bf049244ec9031947321c19527',
'username5',
'431b6de89dc8fd45849280e72aad918c31',
'Clarification 7 question'
);
CALL insert_clarification(
'535e048d77c2d5458e86751da91347da46',
'username4',
'43f6c6ed15ca8248bf97300960edd23f34',
'Clarification 8 question'
);
CALL insert_clarification(
'50752d456d11a847b3b5e091bfd1811999',
'username3',
'434cfa146a09124640bf0bfa8d2a07e4bf',
'Clarification 9 question'
);
CALL insert_clarification(
'50061d05d1bebc4a7a962f0753967e4e2f',
'username8',
'43e71b6e12221c48f7820ec1e0c98619f9',
'Clarification 10 question'
);

