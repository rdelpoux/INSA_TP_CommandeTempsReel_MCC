% Scipt DataVisu to be called or copy & past within the picgui script 
figure(50);

[A tUart] = padr(Rn,2,t_Rn);  % sample on last column data received (remove NaN numbers from the original matrix)

% Signed values
idx = find(A > 65535 / 2);
A(idx) = A(idx)-65536;

if ~isempty(A)
    t = [0:(length(A)-1)] * .01 + tUart(1); % Do not rely on UART data arrival timestamp. Recreate time vector
    subplot(3,1,1); plot(t,A(:,1)); axis tight; ylabel('Pot');    
    subplot(3,1,2); plot(t,A(:,3)*2^-5); axis tight; ylabel('Speed (rad/s)');    
    subplot(3,1,3); plot(t,A(:,2)*4.4/32768); axis tight; ylabel('Current (A)');     
end

