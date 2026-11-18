	push {r4, lr}
	mov ip, r0
	ldrh r0, [r0, #0x1c]
	movs r2, #0x96
	lsls r2, r2, #1
	add r2, ip
	strh r0, [r2]
	mov r1, ip
	ldrh r0, [r1, #0x1e]
	movs r4, #0x97
	lsls r4, r4, #1
	add r4, ip
	strh r0, [r4]
	ldrh r0, [r1, #0x20]
	movs r3, #0x98
	lsls r3, r3, #1
	add r3, ip
	strh r0, [r3]
	movs r1, #0x9a
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r2]
	ldrh r1, [r1]
	subs r0, r0, r1
	movs r1, #0x9e
	lsls r1, r1, #1
	add r1, ip
	strh r0, [r1]
	movs r1, #0x9b
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r4]
	ldrh r1, [r1]
	subs r0, r0, r1
	movs r2, #0x9f
	lsls r2, r2, #1
	add r2, ip
	strh r0, [r2]
	movs r1, #0x9c
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r3]
	ldrh r1, [r1]
	subs r0, r0, r1
	movs r1, #0xa0
	lsls r1, r1, #1
	add r1, ip
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
