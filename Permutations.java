import java.util.*;

public class Permutations {

  //A simple class to find all the permutations for 5 distinguishable elements
  //put into 3 indistinguishable boxes/bins/urns
  //
  //Output: number of permutations, followed by a list of the permutations
  public static void main(String[] args) {
    ArrayList<String> pos = new ArrayList<String>();
    ArrayList<String> def = new ArrayList<String>();
    char[] let = {'1', '2', '3', '4', '5', ',', ','};

    //set up all posibilities
    permutate(let, pos, "");

    //check for duplicates
    def.add(pos.get(0));
    for (int i = 1; i < pos.size(); i++) {
      String[] cur = pos.get(i).split(",", -1);
      boolean doesntExist = true;

      for (int j = 0; j < def.size(); j++) {
        String[] comp = def.get(j).split(",", -1);

        if (isTheSame(cur, comp) && isTheSame(comp,cur)) {
          doesntExist = false;
          break;
        }
      }

      if (doesntExist) {
        def.add(pos.get(i));
      }
    }

    System.out.println("Total answers: " + def.size());
    for (int i = 0; i < def.size(); i++) {
      System.out.println(def.get(i));
    }
  }

  /**
  *  Such a beautiful permutate method :)
  *
  */
  private static void permutate(char[] lets, ArrayList<String> poss, String cur) {
    if (lets.length == 0) {
      poss.add(cur);
      return;
    }

    for (int i = 0; i < lets.length; i++) {
      char[] temp = new char[lets.length - 1];
      for (int j = 0; j < temp.length; j++) {
        if (j >= i)
          temp[j] = lets[j+1]; //remove correct one and do after
        else
          temp[j] = lets[j]; //put before correct one
      }
      permutate(temp, poss, cur + lets[i]);
    }
  }

  /**
  *  Checks to see if the first string array is "the same" as the second
  *
  */
  private static boolean isTheSame(String[] one, String[] two) {
    for (int i = 0; i < one.length; i++) {
      boolean same = false;
      for (int j = 0; j < two.length; j++) {
        if (sort(one[i]).equals(sort(two[j]))) {
          same = true;
          break;
        }
      }
      if (!same)
        return false;
    }

    return true;
  }

  /**
  *  Sorts a string of numbers in ascending order
  *
  */
  private static String sort(String toSort) {
    char[] temp = toSort.toCharArray();
    Arrays.sort(temp);
    return new String(temp);
  }
}
