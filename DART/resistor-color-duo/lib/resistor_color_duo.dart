class ResistorColorDuo {
   List<String> colors = ['black','brown','red','orange','yellow','green','blue','violet','grey','white'];
   int value(List<String> values) 
      => int.parse("${colors.indexOf(values[0])}${colors.indexOf(values[1])}");
   
}
