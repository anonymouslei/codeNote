git branch <分支名>    创建分支
git checkout <分支名>    切换到分支
git merge <分支名>    将分支名merge到我当前的branch
	可以先将bugFix merge到master,此时我们还在master分支下，再切换到bugFix分支下，把master切换过去，最终就得到：master and bugFix在一起了，可以进行下一步操作了
git rebase
git check <哈希值>    将head指向这个版本
git log 查看提交记录的哈希值
^ 向上移动一个提交记录 ~<num>  向上移动多个提交记录
	git checkout master^    master的父节点
	git checkout master^^   master的第二个父节点
git branch -f master HEAD~3 移动master到head的第三个父节点
撤销变更：
git reset HEAD~1    把master分支移回到C1
git revert HEAD     为了撤销更改并分享给别人，我们需要使用git revert.在撤销的提交记录后面多了一个新提交，新提交刚好是用来撤销C2这个提交的。
git cherry-pick xx xx 把C2和C4复制到head

远程分支命名规则：
<remote name>/<branch name>, 远程仓库默认为origin
git fetch 将本地仓库中的远程分支更新成了远程仓库相应分支最新的状态,但是git fetch不会改变本地仓库的状态，不会更新master分支，也不会修改你磁盘上的文件

当别人更改了远程的分支的内容时，可以使用如下的语句
git pull --rebase
git push

有些情况下，你不能将你的分支提交到远程分支上，此时需要新建一个分支feature,推送到远程服务器，然后reset你的master分支和远程服务器保持一致.


