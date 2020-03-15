fid = fopen('filterCoefficients.h','w');

%% Define filter lengths
fprintf(fid,['#define N_A %d' char([13 10])], length(lowPassNumerator));
fwrite(fid,char([13 10]),'uchar');

fprintf(fid,['#define N_B %d' char([13 10])], length(lowPassDenominator));
fwrite(fid,char([13 10]),'uchar');


%% LOW PASS FILTER
%% Numerator
fwrite(fid,'float a_lp[] = { ','uchar');
for ct = 1:length(lowPassNumerator)-1
    fprintf(fid,'%.7ff, ', single(lowPassNumerator(ct)));
end
fprintf(fid,'%.7ff', single(lowPassNumerator(end)));
fwrite(fid,[' };' char([13 10])],'uchar');
fwrite(fid,char([13 10]),'uchar');
%% Denominator
fwrite(fid,'float b_lp[] = { ','uchar');
for ct = 1:length(lowPassDenominator)-1
    fprintf(fid,'%.7ff, ', single(lowPassDenominator(ct)));
end
fprintf(fid,'%.7ff', single(lowPassDenominator(end)));
fwrite(fid,[' };' char([13 10])],'uchar');
fwrite(fid,char([13 10]),'uchar');


%% FIR FILTER
%% B
fwrite(fid,'float a_bp[] = { ','uchar');
for ct = 1:length(bandPassNumerator)-1
    fprintf(fid,'%.7ff, ', single(bandPassNumerator(ct)));
end
fprintf(fid,'%.7ff', single(bandPassNumerator(end)));
fwrite(fid,[' };' char([13 10])],'uchar');
fwrite(fid,char([13 10]),'uchar');
%% A
fwrite(fid,'float b_bp[] = { ','uchar');
for ct = 1:length(bandPassDenominator)-1
    fprintf(fid,'%.7ff, ', single(bandPassDenominator(ct)));
end
fprintf(fid,'%.7ff', single(bandPassDenominator(end)));
fwrite(fid,[' };' char([13 10])],'uchar');
fwrite(fid,char([13 10]),'uchar');


%% FIR FILTER
%% B
fwrite(fid,'float a_hp[] = { ','uchar');
for ct = 1:length(highPassNumerator)-1
    fprintf(fid,'%.7ff, ', single(highPassNumerator(ct)));
end
fprintf(fid,'%.7ff', single(highPassNumerator(end)));
fwrite(fid,[' };' char([13 10])],'uchar');
fwrite(fid,char([13 10]),'uchar');
%% A
fwrite(fid,'float b_hp[] = { ','uchar');
for ct = 1:length(highPassDenominator)-1
    fprintf(fid,'%.7ff, ', single(highPassDenominator(ct)));
end
fprintf(fid,'%.7ff', single(highPassDenominator(end)));
fwrite(fid,[' };' char([13 10])],'uchar');
fwrite(fid,char([13 10]),'uchar');


fclose(fid);
