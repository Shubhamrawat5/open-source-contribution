class ResistorColor {
      List<String> colors;

      ResistorColor() {
         colors = ['black','brown', 'red', 'orange','yellow','green','blue','violet','grey','white'];
      }
      int colorCode(String value) {
         return colors.indexOf(value.toLowerCase());
      }
}
