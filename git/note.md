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
