

### FileQueryʵ��˼·

��vector�����о���

�ù�ϣ���<����,set�������е��к�>
���Դ�ʱset->size()���ǵ��ʳ��ֵĴ��� -- ��ʱ�����⣺
	���һ������һ�г��ֶ�� -- �ᱻȥ��
	1.����ʹ��multiset
	�������ϵ�TestQuery����û��������� -- ��˿���ʹ��set
	����multiset�ڴ�ӡ�кŵ�ʱ�򲻷��� -- ��Ҫȥ��
	2.������һ��pair<set,size_t>
	set��������кż��ϣ�size_t������ų��ִ���

��һ�����ȶ��н��TopK����

��ӡ��������һ��ContextualResults�ദ��
	��װ�������Ϊ������ȡ�����ĵĹ��̸�������
	��ContextualResults���е���get_context��print�ӿ������н���Ĵ�ӡ
	get_context()�ӿ�������ȡÿһ����Ŀ�굥�ʵ�������
	print()�ӿ�������ӡ���

��ѯ����
	�ڹ�ϣ����O(1)��ѯ����ѯ���õ��ʵ��кż���
	���кż��ϵ�multiset����һ��set
	����ContextualResults��
	����print_every_sentence�ӿ�

Replace