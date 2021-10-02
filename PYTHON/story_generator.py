import random


Sentence_starter = ['Once upon a time']
character = [' there lived a boy.',' there was a man named Pypy .', ' there lived a Fisherman.']
time = ['One Hot summer day', 'One day']
story_plot = [' he was playing in ',' he was going for a work to do in ']
place = [' the mountains', ' the river-side']
second_character = [' he saw a girl', ' he saw a young lion']
age = [' who seemed to be in late 20s', ' who seemed very old and feeble']
work = [' eating something.', ' sleeping peacefully.']



print(random.choice(Sentence_starter)+random.choice(character)+
      random.choice(time)+random.choice(story_plot) +
      random.choice(place)+random.choice(second_character)+
      random.choice(age)+random.choice(work))