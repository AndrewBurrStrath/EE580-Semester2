################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
bsl_main.obj: ../bsl_main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv6/tools/compiler/c6000_7.4.16/bin/cl6x" -mv6740 --abi=eabi -g --include_path="C:/ti/ccsv6/tools/compiler/c6000_7.4.16/include" --include_path="C:/Users/rnb15131/Downloads/c6748/c6748/bsl/inc" --define=c6748 --diag_wrap=off --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="bsl_main.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


