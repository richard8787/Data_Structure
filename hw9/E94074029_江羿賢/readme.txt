aoe.cpp

��Ʀs��:
AOE���|��J���ȧQ��before,after��weight�Ӧs���O�T�ӭȡA�ӧQ�ΥL�̪�
activity�@��index�ӴM���s���A�Ӧbtable�һݭn���ƾڤ��O��
ee,le,e,l,slack,critical,path�A���O���w�A��j�p���x�}�Ӧs�A
�Ө䤤�һݭn�`�N���O�A�]��le�ݭn�Ψ��p�A�ҥH����l�ƫܤj���ȵ��L
�b�ܼƤ��Q��be,af,w�ӧ@���Ȯɦs���J���ȡA����e��Ū�A�ëإߤ@��finish
�Ӧsfinish vertex�O�X��

��J:
�Q��time�Ӭݷ|��J�X���A�çQ��while(time--)�ӡA��Ū���۹������ƭ�
before,after,weight

�D�n�B�椺�e:
���p��ee��le����A�b�h����L���p��|��K�ܦh

ee:�q�Ĥ@�Ӷ}�lŪ����̫�@�ӡA���after��ee�ȸ�before��ee��
+weight�A�p�G��̤���j���ܴN�N�ƾڧ�s����̡C

le:le��ee�]�O�۪��[���A�u���L�ݭn�q�̫᭱�}�l��s�A�ӻݭn�`�N���O�A
le��finish vertex���ȷ|��ee��finish vertex���Ȥ@�ˡA�ҥH����s�o�ӭ�
������le��before��L��after����-weight�A�p�G�᭱���ȸ��p�N��s���ӭ�

e:���Fee����N��²��F�A�q�Ĥ@�Ӷ}�lŪ����̫�A�C��e���s�Lbefore��ee�ȧY�i

l:���Fle����]��²��A���M�i�H�q�Ĥ@��Ū�A�i�O�ڬO�q����Ū�^�Ӥ�����۹������Pı�A
�C��l�N�s�Lafter����-�L��weight�Y�i

slack:�q�Ĥ@�Ө�̫�@�ӡA��l���ȴ�he���ȧY�i�o��

critical:��slack�A�p�G�O0���ܴN�]��1�A��L�N�]��0

path:�Ӹ��|�������ݥL��critical�p�G�O1���ܴN�K�[�i�h

��X:
print�X�T�ӡAevent table,act. table,path�A�ݭn�`�N���O�Q��
cout<<left��setw�����O

event table:�qvetex 0Ū��vertex finish�Aprint�Xee��le

act. table:�q�Ĥ@��Ū��̫�Aprint�Xe,l,slack,critical

path:�q�Ĥ@��Ū��̫�Aprint�Xpath
