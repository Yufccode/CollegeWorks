function   [k,f1,f2,f3] = grad(f,x1,x2,s,start_point,thereshold) 
    k = 0;%����������ֵ��ʼ��
    grad_f = [diff(f,x1) diff(f,x2)]; %����f���ݶ� 
    delta = subs(grad_f,[x1,x2],[start_point(1),start_point(2)]);
    %���������ݶ�   
    step=1; %���ó�ʼ����Ϊ1
    current_point = start_point;%���ֵ������ǰ��
    %�����½�������ѭ�����ж�����Ϊ���ݶȵ�ģ����������ֵ���бȽ�
    while norm(delta) > thereshold          
        k = k + 1;%��������+1     
        %һά̽�� �����Ų�������ʱ������֪������sΪ������
        x_next = [current_point(1),current_point(2)] - s* delta/norm(delta);% ����x��k+1���㣬���в���sΪ���� 
        f_val = subs(f,[x1,x2],[x_next(1),x_next(2)]);% ��xֵ����Ŀ�꺯����
        step = abs(double(solve(diff(f_val,s)))); % ��s��һ�׵������Ӿ���ֵ���ţ��õ����Ų����ľ���ֵ
        step = step(1);%���²���    
        %����x��k+1����
        current_point = double([current_point(1),current_point(2)] - step * delta/norm(delta));
        %����x��k+1������ݶ�ֵ
        delta = subs(grad_f,[x1,x2],[current_point(1),current_point(2)]);
        %���㺯��ֵ
        f_value = double(subs(f,[x1,x2],[current_point(1),current_point(2)]));
        %��������������
        result_string=sprintf('k=%d, x1=%.6f, x2=%.6f, step=%.6f f(x1,x2)=%.6f',k,current_point(1),current_point(2),step,f_value);
        f1(k)=current_point(1);
        f2(k)=current_point(2);
        f3(k)=f_value;
        disp(result_string);
    end
end

