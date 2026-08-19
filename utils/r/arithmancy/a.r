# Function to calculate the numerology number
numerology_number <- function(num) {
  # Sum the digits
  digit_sum <- sum(as.numeric(unlist(strsplit(as.character(num), ""))))
  
  # Reduce to a single digit
  while (digit_sum > 9) {
    digit_sum <- sum(as.numeric(unlist(strsplit(as.character(digit_sum), ""))))
  }
  
  return(digit_sum)
}

args = commandArgs(trailingOnly=TRUE)

if (length(args) == 0) {
    stop("At least one argument must be supplied (input file).", call.=FALSE)
}

input_number = args[1]
# print(paste("Input is:", input_number))

# Example usage
result <- numerology_number(input_number)
# print(result)
cat(result)
