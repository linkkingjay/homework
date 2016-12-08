/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function(version1, version2) {
    var parts1 = version1.split('.').map(function (n) {
        return parseInt(n)
    })
    var parts2 = version2.split('.').map(function (n) {
        return parseInt(n)
    })
    
    var i, j;
    for (i = parts1.length - 1; i >= 0; i--) {
        if (parts1[i] !== 0) {
            break
        }
        parts1.pop()
    }
    for (j = parts2.length - 1; j >= 0; j--) {
        if (parts2[j] !== 0) {
            break
        }
        parts2.pop()
    }
    console.log(parts1, parts2)
    
    for (i = 0, j = 0; i < parts1.length && j < parts2.length; i++, j++) {
        if (parts1[i] !== parts2[j]) {
            return parts1[i] > parts2[j] ? 1 : -1
        }
    }
    if (i === parts1.length && j === parts2.length) {
        return 0
    }
    if (i < parts1.length) return 1
    if (j < parts2.length) return -1
};


console.log(compareVersion('1.0', '1.0'))
