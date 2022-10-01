def my_median(sample):
  n = len(sample)
  index = n // 2
  if n % 2:
    return sorted(sample)[index]
  return sum(sorted(sample)[index - 1:index + 1]) / 2
