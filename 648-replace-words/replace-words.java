import java.util.HashSet;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

class Solution {
    public String replaceWords(List<String> dictionary, String sentence) {
        HashSet<String> rootSet = new HashSet<>(dictionary);
        List<String> words = Arrays.asList(sentence.split(" "));
        List<String> result = words.stream()
                .map(word -> {
                    String prefix = "";
                    for (int i = 1; i <= word.length(); i++) {
                        prefix = word.substring(0, i);
                        if (rootSet.contains(prefix)) {
                            break;
                        }
                    }
                    return prefix;
                })
                .collect(Collectors.toList());
        return String.join(" ", result);
    }
}

