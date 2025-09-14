/**
 * @param {string} s
 * @return {string}
 */
var sortVowels = function(s) {
    const vowelSet = new Set(['A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u']);
    const vowelsInWord = [];

    for(const ch of s) {
        if(vowelSet.has(ch)) {
            vowelsInWord.push(ch);
        }
    };

    vowelsInWord.sort()

    let ans = "";
    let idx = 0;

    for(const ch of s) {
        if(vowelSet.has(ch)) {
            ans += vowelsInWord[idx++];
            continue;
        }

        ans += ch;
    }

    return ans;
};