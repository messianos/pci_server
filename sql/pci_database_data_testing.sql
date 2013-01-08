USE pci_database;

DELETE IGNORE FROM problem_solutions;
DELETE IGNORE FROM Clarification;
DELETE IGNORE FROM Problem;
DELETE IGNORE FROM Solution;
DELETE IGNORE FROM User;

CALL sign_up(
'1995-07-09',
'username1@domain.com',
'John',
'M',
'Garcia',
'NYC',
'password1',
'2012-05-05',
'username1'
);
CALL sign_up(
'1994-05-06',
'username2@domain.com',
'Mike',
'F',
'Perez',
'MDQ',
'password2',
'2012-05-07',
'username2'
);
CALL sign_up(
'1996-08-08',
'username3@domain.com',
'John',
'F',
'Perez',
'NYC',
'password3',
'2012-08-07',
'username3'
);
CALL sign_up(
'1998-07-05',
'username4@domain.com',
'Jose',
'M',
'Smith',
'BB',
'password4',
'2012-07-03',
'username4'
);
CALL sign_up(
'1998-02-02',
'username5@domain.com',
'Jose',
'M',
'Garcia',
'MDQ',
'password5',
'2012-07-09',
'username5'
);
CALL sign_up(
'1998-04-06',
'username6@domain.com',
'Mike',
'F',
'Perez',
'CABA',
'password6',
'2012-07-05',
'username6'
);
CALL sign_up(
'1992-06-03',
'username7@domain.com',
'Jose',
'F',
'Smith',
'NYC',
'password7',
'2012-03-08',
'username7'
);
CALL sign_up(
'1996-01-07',
'username8@domain.com',
'John',
'M',
'Doe',
'NYC',
'password8',
'2012-09-03',
'username8'
);
CALL sign_up(
'1998-06-02',
'username9@domain.com',
'John',
'M',
'Perez',
'BB',
'password9',
'2012-02-08',
'username9'
);
CALL sign_up(
'1998-09-09',
'username10@domain.com',
'Juan',
'M',
'Doe',
'CABA',
'password10',
'2012-08-01',
'username10'
);

CALL insert_problem(
'Problem 1 content',
'2013-03-08 06:06:06',
'username6',
'Problem 1 description',
'508b5dae790a1a46c186542562f1f387d3',
FALSE
);
CALL insert_problem(
'Problem 2 content',
'2013-03-04 05:03:04',
'username10',
'Problem 2 description',
'5010417a6575fc41229f42c3b18929a431',
FALSE
);
CALL insert_problem(
'Problem 3 content',
'2013-06-08 02:07:08',
'username10',
'Problem 3 description',
'50772300d9666248a7b795b50cc88299d3',
FALSE
);
CALL insert_problem(
'Problem 4 content',
'2013-03-09 04:08:06',
'username5',
'Problem 4 description',
'50d2f5961d5d4649f1a7c4ccf7d50dede1',
FALSE
);
CALL insert_problem(
'Problem 5 content',
'2013-07-07 03:04:02',
'username7',
'Problem 5 description',
'509e7c1200a5f1480994b44531234a7f54',
TRUE
);
CALL insert_problem(
'Problem 6 content',
'2013-01-01 04:01:09',
'username2',
'Problem 6 description',
'505c79feac087d48a6b11f870117cebe50',
FALSE
);
CALL insert_problem(
'Problem 7 content',
'2013-04-09 07:07:04',
'username8',
'Problem 7 description',
'50ff8a559e2a0843afa430c8b95ae68d1e',
TRUE
);
CALL insert_problem(
'Problem 8 content',
'2013-03-03 02:05:07',
'username9',
'Problem 8 description',
'5063150d12b6354441af99d9c721cd7598',
FALSE
);
CALL insert_problem(
'Problem 9 content',
'2013-07-05 05:06:06',
'username7',
'Problem 9 description',
'504c8899caf17040d3ba1b9417d8e72031',
TRUE
);
CALL insert_problem(
'Problem 10 content',
'2013-01-02 01:03:05',
'username1',
'Problem 10 description',
'504945fdf3b31f41d2b705f6a47b0e940c',
FALSE
);
CALL insert_problem(
'Problem 11 content',
'2013-02-03 04:07:02',
'username8',
'Problem 11 description',
'50375f542315434c26b77ecb5b31981808',
FALSE
);
CALL insert_problem(
'Problem 12 content',
'2013-06-08 07:02:03',
'username1',
'Problem 12 description',
'50e3214eeefd77448c8f55cd9fcc565601',
TRUE
);
CALL insert_problem(
'Problem 13 content',
'2013-09-01 08:06:07',
'username6',
'Problem 13 description',
'50b3b2c777c5694d29871b46a1507fad05',
FALSE
);
CALL insert_problem(
'Problem 14 content',
'2013-08-08 01:07:06',
'username7',
'Problem 14 description',
'50f1ab52931b104be38295329558bcfd05',
TRUE
);
CALL insert_problem(
'Problem 15 content',
'2013-08-07 01:03:08',
'username10',
'Problem 15 description',
'50fe507324c9074899bbca8300e13da0a4',
FALSE
);
CALL insert_problem(
'Problem 16 content',
'2013-09-01 09:08:07',
'username4',
'Problem 16 description',
'50eb289710cbb141d393830d16efc9c805',
FALSE
);
CALL insert_problem(
'Problem 17 content',
'2013-05-01 06:09:06',
'username8',
'Problem 17 description',
'50e18ebf847f404c9e8bec2ddf18666c3a',
TRUE
);
CALL insert_problem(
'Problem 18 content',
'2013-01-07 01:05:04',
'username10',
'Problem 18 description',
'50b969c9ad18364c5fb22106ece2187b13',
TRUE
);
CALL insert_problem(
'Problem 19 content',
'2013-03-04 04:03:08',
'username8',
'Problem 19 description',
'50d21ac1b8c14e4ac29bd1891fe8fc98d2',
FALSE
);
CALL insert_problem(
'Problem 20 content',
'2013-08-08 08:01:01',
'username10',
'Problem 20 description',
'500d5e3d83768249c19b3f57ec61a7bf51',
FALSE
);
CALL insert_problem(
'Problem 21 content',
'2013-05-02 02:08:08',
'username2',
'Problem 21 description',
'50c6b28ed034db437c9fb964e8a91a422d',
TRUE
);
CALL insert_problem(
'Problem 22 content',
'2013-03-08 09:09:07',
'username6',
'Problem 22 description',
'5038828b7c9bdc4ee0b272cc4e6ee2ba58',
FALSE
);
CALL insert_problem(
'Problem 23 content',
'2013-08-08 09:08:03',
'username2',
'Problem 23 description',
'5034f9720d4fc340678dc781e65a1e1abe',
FALSE
);
CALL insert_problem(
'Problem 24 content',
'2013-09-09 01:09:09',
'username6',
'Problem 24 description',
'500a7ce3408a784a16959f2da53b1e26cc',
FALSE
);
CALL insert_problem(
'Problem 25 content',
'2013-01-04 08:02:08',
'username7',
'Problem 25 description',
'5096f9467d57ed4b13840c955adeca2a4d',
TRUE
);
CALL insert_problem(
'Problem 26 content',
'2013-04-01 04:05:03',
'username3',
'Problem 26 description',
'50781b663a09c447948b3f63c191920339',
TRUE
);
CALL insert_problem(
'Problem 27 content',
'2013-04-06 02:07:04',
'username7',
'Problem 27 description',
'50fc4e6c4267d144eaa1ff2aaebf2faf6a',
FALSE
);
CALL insert_problem(
'Problem 28 content',
'2013-07-08 04:08:09',
'username2',
'Problem 28 description',
'50357a518b17d241f09796f4b928c1324d',
FALSE
);
CALL insert_problem(
'Problem 29 content',
'2013-03-01 08:03:05',
'username4',
'Problem 29 description',
'50ae469ac0671d467bade4f8a0cf621fda',
FALSE
);
CALL insert_problem(
'Problem 30 content',
'2013-08-03 06:04:03',
'username6',
'Problem 30 description',
'50bbcf087d910a4ad99f4344a38632fd47',
FALSE
);

CALL insert_solution(
'5096f9467d57ed4b13840c955adeca2a4d',
'Solution 1 content',
'2013-01-09 04:02:05',
'username3',
'Solution 1 description',
'53504e3855605949f986ac38dc62ccafb8',
TRUE
);
CALL insert_solution(
'5034f9720d4fc340678dc781e65a1e1abe',
'Solution 2 content',
'2013-08-03 07:03:09',
'username4',
'Solution 2 description',
'532755302c10984d9c84788d283661e7f1',
TRUE
);
CALL insert_solution(
'50d2f5961d5d4649f1a7c4ccf7d50dede1',
'Solution 3 content',
'2013-09-07 03:07:09',
'username8',
'Solution 3 description',
'53765ef3deb4b74c898e1e13cc27e9ae9b',
TRUE
);
CALL insert_solution(
'505c79feac087d48a6b11f870117cebe50',
'Solution 4 content',
'2013-01-09 03:04:03',
'username8',
'Solution 4 description',
'5368eeb1ed8d6548298fec44b5f8a6531e',
TRUE
);
CALL insert_solution(
'505c79feac087d48a6b11f870117cebe50',
'Solution 5 content',
'2013-08-03 02:01:02',
'username9',
'Solution 5 description',
'5346df5cabc30b4f78a2d4849d78d7d046',
FALSE
);
CALL insert_solution(
'5010417a6575fc41229f42c3b18929a431',
'Solution 6 content',
'2013-03-01 08:01:03',
'username6',
'Solution 6 description',
'53f23c3e195a8f427197a6eadf4c90aa22',
TRUE
);
CALL insert_solution(
'504c8899caf17040d3ba1b9417d8e72031',
'Solution 7 content',
'2013-04-07 06:07:01',
'username6',
'Solution 7 description',
'537e0cc08788f84b09a8491e2daff08474',
FALSE
);
CALL insert_solution(
'50d2f5961d5d4649f1a7c4ccf7d50dede1',
'Solution 8 content',
'2013-07-05 03:05:07',
'username4',
'Solution 8 description',
'536e62a4ed369d4cc29bb41d9a700a1ff8',
FALSE
);
CALL insert_solution(
'50fc4e6c4267d144eaa1ff2aaebf2faf6a',
'Solution 9 content',
'2013-02-06 02:09:01',
'username7',
'Solution 9 description',
'539ea33969e6824aa7bd84aacba3254ff8',
FALSE
);
CALL insert_solution(
'50357a518b17d241f09796f4b928c1324d',
'Solution 10 content',
'2013-03-04 02:01:01',
'username6',
'Solution 10 description',
'53919d368d5e7f442ab4d4d4ef9b91e19d',
TRUE
);
CALL insert_solution(
'50d21ac1b8c14e4ac29bd1891fe8fc98d2',
'Solution 11 content',
'2013-08-02 06:07:01',
'username2',
'Solution 11 description',
'5313735df48bc1435fa35f10d880dd185c',
TRUE
);
CALL insert_solution(
'50fe507324c9074899bbca8300e13da0a4',
'Solution 12 content',
'2013-04-02 01:06:05',
'username3',
'Solution 12 description',
'539055382467714fe2b7cd5678e363ae7b',
TRUE
);
CALL insert_solution(
'50375f542315434c26b77ecb5b31981808',
'Solution 13 content',
'2013-02-04 07:09:03',
'username5',
'Solution 13 description',
'533cd599fb99ef4b04997733b4426e7b15',
FALSE
);
CALL insert_solution(
'50b3b2c777c5694d29871b46a1507fad05',
'Solution 14 content',
'2013-01-07 04:06:07',
'username5',
'Solution 14 description',
'5337fc198f5a7b48139eb3734967d0c87f',
TRUE
);
CALL insert_solution(
'50d2f5961d5d4649f1a7c4ccf7d50dede1',
'Solution 15 content',
'2013-02-05 03:04:06',
'username3',
'Solution 15 description',
'5300e36fb115c446dabff50fdc884a1d7a',
TRUE
);
CALL insert_solution(
'50d2f5961d5d4649f1a7c4ccf7d50dede1',
'Solution 16 content',
'2013-02-03 05:08:09',
'username3',
'Solution 16 description',
'53afbfe629e9c34aac927f18d3115709e6',
TRUE
);
CALL insert_solution(
'50eb289710cbb141d393830d16efc9c805',
'Solution 17 content',
'2013-08-01 07:09:01',
'username7',
'Solution 17 description',
'533d833e02101e4d37af4b6b41186a6a43',
FALSE
);
CALL insert_solution(
'50ae469ac0671d467bade4f8a0cf621fda',
'Solution 18 content',
'2013-03-06 02:02:06',
'username10',
'Solution 18 description',
'531ac5340b926247f0817d1977713cdf13',
TRUE
);
CALL insert_solution(
'50fc4e6c4267d144eaa1ff2aaebf2faf6a',
'Solution 19 content',
'2013-07-07 04:04:08',
'username9',
'Solution 19 description',
'5388995cf7ed294b398e0b68af7d4f3c93',
FALSE
);
CALL insert_solution(
'50ff8a559e2a0843afa430c8b95ae68d1e',
'Solution 20 content',
'2013-07-09 07:06:07',
'username10',
'Solution 20 description',
'53cacc5a1a2b88465bba81797f50581533',
TRUE
);
CALL insert_solution(
'508b5dae790a1a46c186542562f1f387d3',
'Solution 21 content',
'2013-07-04 05:08:08',
'username9',
'Solution 21 description',
'537ee776c68d2f4fb089e346cd8202b081',
FALSE
);
CALL insert_solution(
'50d2f5961d5d4649f1a7c4ccf7d50dede1',
'Solution 22 content',
'2013-01-09 04:05:06',
'username8',
'Solution 22 description',
'53c76f7d7ef0c14a26851ff5ac71b97f3a',
FALSE
);
CALL insert_solution(
'50f1ab52931b104be38295329558bcfd05',
'Solution 23 content',
'2013-08-09 06:09:02',
'username6',
'Solution 23 description',
'5384096c11d2f2448b8414be27681f0659',
TRUE
);
CALL insert_solution(
'500d5e3d83768249c19b3f57ec61a7bf51',
'Solution 24 content',
'2013-07-04 04:08:09',
'username8',
'Solution 24 description',
'5360097f7769844fc28eebb15d0e64d751',
TRUE
);
CALL insert_solution(
'50e3214eeefd77448c8f55cd9fcc565601',
'Solution 25 content',
'2013-09-09 06:04:05',
'username2',
'Solution 25 description',
'538ee4761538b7446aa4b388a195e88d43',
FALSE
);
CALL insert_solution(
'505c79feac087d48a6b11f870117cebe50',
'Solution 26 content',
'2013-02-05 02:04:05',
'username2',
'Solution 26 description',
'5313c85698fc5447e5809a342d2f93fc27',
FALSE
);
CALL insert_solution(
'5034f9720d4fc340678dc781e65a1e1abe',
'Solution 27 content',
'2013-08-02 08:04:04',
'username9',
'Solution 27 description',
'53f2424b62d8f842e197d8a852eafb9574',
FALSE
);
CALL insert_solution(
'500d5e3d83768249c19b3f57ec61a7bf51',
'Solution 28 content',
'2013-05-05 07:08:07',
'username8',
'Solution 28 description',
'532a633a02a2ce4505b08714ebc554bdd3',
FALSE
);
CALL insert_solution(
'50357a518b17d241f09796f4b928c1324d',
'Solution 29 content',
'2013-08-04 07:09:07',
'username1',
'Solution 29 description',
'53cf39509378d34dd8ba004b8e60242f7f',
TRUE
);
CALL insert_solution(
'5038828b7c9bdc4ee0b272cc4e6ee2ba58',
'Solution 30 content',
'2013-04-08 03:08:08',
'username4',
'Solution 30 description',
'536985633036114b24ac93f10aa1a024eb',
TRUE
);
CALL insert_solution(
'50e18ebf847f404c9e8bec2ddf18666c3a',
'Solution 31 content',
'2013-04-01 07:05:05',
'username10',
'Solution 31 description',
'53761add5364b94c26878c1fb7f23cd195',
FALSE
);
CALL insert_solution(
'508b5dae790a1a46c186542562f1f387d3',
'Solution 32 content',
'2013-06-03 03:01:09',
'username9',
'Solution 32 description',
'53ab8fc48dee7f4a4085d5fbba363fddad',
TRUE
);
CALL insert_solution(
'5038828b7c9bdc4ee0b272cc4e6ee2ba58',
'Solution 33 content',
'2013-06-03 05:02:07',
'username1',
'Solution 33 description',
'53372a055f387e4286aabfd86afa10b493',
FALSE
);
CALL insert_solution(
'500a7ce3408a784a16959f2da53b1e26cc',
'Solution 34 content',
'2013-07-08 01:06:07',
'username8',
'Solution 34 description',
'53ae84665bad0547bead32a55fb086e0eb',
FALSE
);
CALL insert_solution(
'50ff8a559e2a0843afa430c8b95ae68d1e',
'Solution 35 content',
'2013-09-01 01:08:09',
'username9',
'Solution 35 description',
'53cd162d5ed697411db73947a9743f0d3a',
FALSE
);
CALL insert_solution(
'504c8899caf17040d3ba1b9417d8e72031',
'Solution 36 content',
'2013-07-07 06:02:04',
'username7',
'Solution 36 description',
'53ed17fdbdfecb4eb4986a2ed6a8f931c9',
FALSE
);
CALL insert_solution(
'5034f9720d4fc340678dc781e65a1e1abe',
'Solution 37 content',
'2013-04-09 04:03:05',
'username7',
'Solution 37 description',
'53c0a6d244038c4322a34a03f81b557b72',
TRUE
);
CALL insert_solution(
'5063150d12b6354441af99d9c721cd7598',
'Solution 38 content',
'2013-06-06 07:02:09',
'username6',
'Solution 38 description',
'5362b692597141429b92dda9f09a38cd61',
TRUE
);
CALL insert_solution(
'505c79feac087d48a6b11f870117cebe50',
'Solution 39 content',
'2013-06-05 03:05:08',
'username4',
'Solution 39 description',
'53b65a7fe6a6f24f86a69d67d871c3ebf2',
TRUE
);
CALL insert_solution(
'50357a518b17d241f09796f4b928c1324d',
'Solution 40 content',
'2013-06-08 07:05:02',
'username6',
'Solution 40 description',
'537388566e2fdd44559f90aa0d5569416f',
FALSE
);
CALL insert_solution(
'50f1ab52931b104be38295329558bcfd05',
'Solution 41 content',
'2013-06-06 07:02:05',
'username5',
'Solution 41 description',
'53b1eefb6846064516a58035d521bb352f',
FALSE
);
CALL insert_solution(
'509e7c1200a5f1480994b44531234a7f54',
'Solution 42 content',
'2013-09-01 09:09:07',
'username2',
'Solution 42 description',
'53b2ac66d24afc4f61baa313a0fbae448d',
TRUE
);
CALL insert_solution(
'5034f9720d4fc340678dc781e65a1e1abe',
'Solution 43 content',
'2013-06-02 07:05:05',
'username3',
'Solution 43 description',
'5354fe0bf7dace431289c2973e68ba08fb',
FALSE
);
CALL insert_solution(
'50357a518b17d241f09796f4b928c1324d',
'Solution 44 content',
'2013-07-01 04:06:07',
'username5',
'Solution 44 description',
'532e30fb98ad604ff9b3d8e9059ec98aaf',
TRUE
);
CALL insert_solution(
'50f1ab52931b104be38295329558bcfd05',
'Solution 45 content',
'2013-03-06 06:06:02',
'username9',
'Solution 45 description',
'5343571df8057744f9af1f0513e9dd0456',
FALSE
);
CALL insert_solution(
'50c6b28ed034db437c9fb964e8a91a422d',
'Solution 46 content',
'2013-01-06 08:09:07',
'username3',
'Solution 46 description',
'5311d42c5b93e84511afb2165692d9aa5d',
FALSE
);
CALL insert_solution(
'5010417a6575fc41229f42c3b18929a431',
'Solution 47 content',
'2013-05-09 06:05:06',
'username3',
'Solution 47 description',
'5351f8a5eb3d4e4d18ba0681c75e8e38f1',
TRUE
);
CALL insert_solution(
'50fc4e6c4267d144eaa1ff2aaebf2faf6a',
'Solution 48 content',
'2013-08-04 01:07:07',
'username5',
'Solution 48 description',
'5322df2aad1efb45458ae5041d5e5f2987',
TRUE
);
CALL insert_solution(
'50eb289710cbb141d393830d16efc9c805',
'Solution 49 content',
'2013-06-06 03:08:04',
'username7',
'Solution 49 description',
'533de8830f39f34340bd586bd1d8675efc',
TRUE
);
CALL insert_solution(
'50fc4e6c4267d144eaa1ff2aaebf2faf6a',
'Solution 50 content',
'2013-09-08 06:01:08',
'username5',
'Solution 50 description',
'53885fd69f89f9485ab4b9eba06b5f375b',
TRUE
);

CALL insert_clarification(
'500a7ce3408a784a16959f2da53b1e26cc',
'username10',
'43d506645158cc47299d59d815bef00c58',
'Clarification 1 question'
);
CALL insert_clarification(
'53ed17fdbdfecb4eb4986a2ed6a8f931c9',
'username3',
'433812df1596db461ab89152d384e025d0',
'Clarification 2 question'
);
CALL insert_clarification(
'532e30fb98ad604ff9b3d8e9059ec98aaf',
'username1',
'4333af304e22654373939bba6651a7d8ff',
'Clarification 3 question'
);
CALL insert_clarification(
'53919d368d5e7f442ab4d4d4ef9b91e19d',
'username2',
'43c6335f3d6abd444aada099284c9121b1',
'Clarification 4 question'
);
CALL insert_clarification(
'5300e36fb115c446dabff50fdc884a1d7a',
'username6',
'435ec99ddda3874036aba74ea8d50f03fe',
'Clarification 5 question'
);
CALL insert_clarification(
'50eb289710cbb141d393830d16efc9c805',
'username8',
'433576fdc2e5564a60b75801d31e993f02',
'Clarification 6 question'
);
CALL insert_clarification(
'53ae84665bad0547bead32a55fb086e0eb',
'username9',
'43559bd448644c4a08b9458e3937dfd129',
'Clarification 7 question'
);
CALL insert_clarification(
'53f23c3e195a8f427197a6eadf4c90aa22',
'username6',
'430b6073c8375a4a60ba4d0ec1e98d192c',
'Clarification 8 question'
);
CALL insert_clarification(
'5388995cf7ed294b398e0b68af7d4f3c93',
'username7',
'439b6d67799a1840c7b7eab43585be3fdc',
'Clarification 9 question'
);
CALL insert_clarification(
'50d2f5961d5d4649f1a7c4ccf7d50dede1',
'username4',
'43c74faa5c41cc433e8fb2d1181bdeae9a',
'Clarification 10 question'
);

