/**
 * @param {string} columnTitle
 * @return {number}
 */
var titleToNumber = function(columnTitle) {
    let len = columnTitle.length;
    let ans = 0;

    for (const ch of columnTitle) {
        const charValue = Math.pow(26, --len) * (ch.charCodeAt(0) - 65 + 1);
        ans += charValue;
    }

    return ans;
};