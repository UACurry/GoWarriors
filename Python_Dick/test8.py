import random
reward = ("1等奖 笔记本一部","2等奖 苹果手机一部","3等奖 kindle一部","4等奖 迷你音响一个")
sno = random.randint(1,60)
reward_no = random.randint(0,3)
print("中奖号码：",sno,"号，奖品：",reward[reward_no])
