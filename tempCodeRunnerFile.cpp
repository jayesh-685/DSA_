int editDistRec (string s1, string s2, int n, int m) {
//     if (s1[n-1] == s2[m-1])
//         return editDistRec(s1, s2, n-1, m-1);
//     else 
//         // considering all operations: insertion deletetion replacing
//         return 1 + min(editDistRec(s1, s2, n, m-1), editDistRec(s1, s2, n-1, m), editDistRec(s1, s2, n-1, m-1));
// }